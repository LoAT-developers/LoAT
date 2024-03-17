# LoAT -- the Loop Acceleration Tool

LoAT (**Lo**op **A**cceleration **T**ool) is a fully automated tool to analyze *transition systems* and linear *Constrained Horn Clauses (CHCs)* with integer variables.
For transition systems, it supports the inference of **lower bounds** on the worst-case runtime complexity and **non-termination proving**.
For CHCs, it can prove **unsatisfiability**.

For more information, please visit [LoAT's website](https://loat-developers.github.io/LoAT/).



# Dependencies
The following is an incomplete list of dependencies with links pointing to more information:
* cudd: https://github.com/ivmai/cudd
* cvc5: https://cvc5.github.io/
* z3: https://github.com/Z3Prover/z3
* libFAUDEs: https://github.com/FGDES/libFAUDES
* GINAC: https://www.ginac.de/
* NTL: https://libntl.org/
* yices: https://yices.csl.sri.com/
* poly: https://github.com/SRI-CSL/libpoly
* SWINE: https://github.com/ffrohn/swine-z3 https://github.com/ffrohn/swine
* PURRS solver for recurrence relations. Original solver can be found [here](https://www.cs.unipr.it/purrs/) but we recommend using the patched version that also includes a tutorial on installing found [here](https://github.com/aprove-developers/LoAT-purrs).