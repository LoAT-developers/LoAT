#include "proof.hpp"

#include <iostream>
#include <string>

unsigned int Proof::defaultProofLevel = 1;
unsigned int Proof::proofLevel = defaultProofLevel;
bool Proof::use_colors = true;

bool Proof::disabled() {
    return proofLevel <= 0;
}

const std::string HeadlineColor = "\033[1;4;33m"; // bold underlined yellow
const std::string WarningColor = "\033[1;31m"; // bold red
const std::string ResultColor = "\033[1;32m"; // bold green
const std::string NoColor = "\033[0m"; // reset color

void Proof::print(unsigned level) const {
    if (level <= proofLevel) {
        std::stringstream indentBuilder;
        for (unsigned i = 0; i < level - 1; ++i) {
            indentBuilder << "\t";
        }
        std::string indent = indentBuilder.str();
        // initialize with true to skip leading blank lines
        bool last_blank = true;
        for (const auto &l: proof) {
            if (std::holds_alternative<ProofStep>(l)) {
                ProofStep ps = std::get<ProofStep>(l);
                bool is_blank = ps.second.empty();
                if (is_blank && last_blank) {
                    continue;
                }
                if (!is_blank && !last_blank && ps.first != Proof::Style::None) {
                    // make sure that there is a blank line before headlines and results
                    std::cout << std::endl;
                }
                if (use_colors) {
                    switch (ps.first) {
                    case None: std::cout << NoColor;
                        break;
                    case Result: std::cout << ResultColor;
                        break;
                    case Headline: std::cout << HeadlineColor;
                        break;
                    }
                }
                std::cout << indent << ps.second << std::endl;
                // make sure that there is a blank line after headlines and results
                if (!is_blank && ps.first != Proof::Style::None) {
                    std::cout << std::endl;
                    last_blank = true;
                } else {
                    last_blank = is_blank;
                }
            } else {
                if (!last_blank) {
                    // make sure there is a blank line before the sub-proof
                    std::cout << std::endl;
                }
                std::get<Proof>(l).print(level + 1);
                // the sub-proof ends with a blank line
                last_blank = true;
            }
        }
        if (!last_blank) {
            // make sure the proof ends with a blank line
            std::cout << std::endl;
        }
    }
}

void Proof::append(const std::string &s) {
    append(Style::None, s);
}

void Proof::append(const std::ostream &s) {
    if (Proof::disabled()) {
        return;
    }
    std::stringstream str;
    str << s.rdbuf();
    append(str.str());
}

void Proof::append(const Style &style, std::string s) {
    if (Proof::disabled()) {
        return;
    }
    std::vector<std::string> lines;
    boost::split(lines, s, boost::is_any_of("\n"));
    for (const std::string &l: lines) {
        proof.emplace_back(ProofStep{style, l});
    }
}

void Proof::newline() {
    append(std::stringstream());
}

void Proof::headline(const std::string &s) {
    newline();
    append(Headline, s);
}

// print given string in headline style with spacing
void Proof::headline(const std::ostream &s) {
    if (Proof::disabled()) {
        return;
    }
    std::stringstream str;
    str << s.rdbuf();
    headline(str.str());
}

void Proof::result(const std::string &s) {
    append(Result, s);
}

void Proof::result(const std::ostream &s) {
    if (Proof::disabled()) {
        return;
    }
    std::stringstream str;
    str << s.rdbuf();
    result(str.str());
}

void Proof::setProofLevel(unsigned int proofLevel) {
    Proof::proofLevel = proofLevel;
}

void Proof::concat(const Proof &that) {
    if (Proof::disabled()) {
        return;
    }
    proof.insert(proof.end(), that.proof.begin(), that.proof.end());
}

void Proof::push() {
    pop_stack.push(proof.size());
}

void Proof::pop() {
    const unsigned current_size = proof.size();
    const unsigned new_size = pop_stack.top();
    pop_stack.pop();
    for (unsigned i = 0; i < current_size - new_size; ++i) {
        proof.pop_back();
    }
}

void Proof::storeSubProof(const Proof &subProof) {
    if (proofLevel > 1) {
        proof.push_back(subProof);
    }
}

bool Proof::empty() const {
    return proof.empty();
}
