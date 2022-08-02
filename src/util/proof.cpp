#include "proof.hpp"
#include "../its/export.hpp"

#include <iostream>
#include <string>

unsigned int Proof::defaultProofLevel = 1;
unsigned int Proof::maxProofLevel = 2;
unsigned int Proof::proofLevel = defaultProofLevel;

Proof::Proof(): level(1) {}

void Proof::print() const {
    for (const auto &l: proof) {
        if (std::holds_alternative<ProofStep>(l)) {
            ProofStep ps = std::get<ProofStep>(l);
            if (Config::Output::Colors) {
                switch (ps.first) {
                case None: std::cout << Config::Color::None;
                    break;
                case Result: std::cout << Config::Color::Result;
                    break;
                case Section: std::cout << Config::Color::Section;
                    break;
                case Headline: std::cout << Config::Color::Headline;
                    break;
                }
            }
            std::cout << ps.second << std::endl;
        } else {
            std::get<Proof>(l).print();
        }
    }
}

void Proof::append(const std::string &s) {
    append(Style::None, s);
}

void Proof::append(const std::ostream &s) {
    std::stringstream str;
    str << s.rdbuf();
    append(str.str());
}

void Proof::append(const Style &style, std::string s) {
    if (proofLevel >= level) {
        std::vector<std::string> lines;
        boost::split(lines, s, boost::is_any_of("\n"));
        for (const std::string &l: lines) {
            proof.push_back(ProofStep{style, l});
        }
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
    std::stringstream str;
    str << s.rdbuf();
    headline(str.str());
}

void Proof::section(const std::string &s) {
    newline();
    append(Section, s);
}

void Proof::section(const std::ostream &s) {
    std::stringstream str;
    str << s.rdbuf();
    section(str.str());
}

void Proof::result(const std::string &s) {
    append(Result, s);
}

void Proof::result(const std::ostream &s) {
    std::stringstream str;
    str << s.rdbuf();
    result(str.str());
}

void Proof::setProofLevel(unsigned int proofLevel) {
    Proof::proofLevel = proofLevel;
}

void Proof::concat(const Proof &that) {
    if (proofLevel >= level) {
        proof.insert(proof.end(), that.proof.begin(), that.proof.end());
    }
}

void Proof::ruleTransformationProof(const Rule &oldRule, const std::string &transformation, const Rule &newRule, const ITSProblem &its) {
    section("Applied " + transformation);
    std::stringstream s;
    s << "Original rule:\n";
    ITSExport::printRule(oldRule, its, s);
    s << "\nNew rule:\n";
    ITSExport::printRule(newRule, its, s);
    append(s);
}

void Proof::majorProofStep(const std::string &step, const ITSProblem &its) {
    headline(step);
    std::stringstream s;
    ITSExport::printForProof(its, s);
    append(s);
}

void Proof::minorProofStep(const std::string &step, const ITSProblem &its) {
    section(step);
    std::stringstream s;
    ITSExport::printForProof(its, s);
    append(s);
}

void Proof::deletionProof(const std::set<TransIdx> &rules) {
    if (!rules.empty()) {
        section("Applied deletion");
        std::stringstream s;
        s << "Removed the following rules:";
        for (TransIdx i: rules) {
            s << " " << i;
        }
        append(s);
    }
}

void Proof::chainingProof(const Rule &fst, const Rule &snd, const Rule &newRule, const ITSProblem &its) {
    section("Applied chaining");
    std::stringstream s;
    s << "First rule:\n";
    ITSExport::printRule(fst, its, s);
    s << "\nSecond rule:\n";
    ITSExport::printRule(snd, its, s);
    s << "\nNew rule:\n";
    ITSExport::printRule(newRule, its, s);
    append(s);
}

void Proof::storeSubProof(Proof subProof, const std::string &technique) {
    if (proofLevel > level) {
        append("Sub-proof via " + technique + ":");
        subProof.level = level + 1;
        proof.push_back(subProof);
    }
}

bool Proof::empty() const {
    return proof.empty();
}
