<head>
    <title>LoAT</title>
    <style>
    p {text-align: justify;}
</head>

LoAT (**Lo**op **A**cceleration **T**ool) is a fully automated tool to analyze *Transition Systems* and linear *Constrained Horn Clauses (CHCs)* with integer variables.
For transition systems, it supports the inference of **lower bounds** on the worst-case runtime complexity and **non-termination proving**.
For CHCs, it can prove **unsatisfiability**.

LoAT is based on a [calculus for modular *loop acceleration*](https://doi.org/10.1007/978-3-030-45190-5_4).
Loop acceleration transforms certain simple relations into first-order formulas that describe their transitive closure.
To lift loop acceleration to more complex formalisms (like transition systems or CHCs), earlier versions of LoAT used the framework described in [this paper](https://doi.org/10.1145/3410331).
Current versions use a novel calculus called *ADCL* instead.
Details on ADCL will be available soon.

LoAT uses the recurrence solver [PURRS](http://www.cs.unipr.it/purrs/), the SMT solvers [Yices](https://yices.csl.sri.com/) and [Z3](https://github.com/Z3Prover/z3/), and the automata-library [libFAUDES](https://www.fgdes.tf.fau.de/faudes/index.html).

# Downloading LoAT

[Here](https://github.com/loat-developers/LoAT/releases) you can find the latests releases of LoAT.
Older releases can be found [here](https://github.com/aprove-developers/LoAT/releases).

# Input Formats

## Integer Transition Systems

LoAT supports the most common formats for *Integer Transition Systems*.

## SMTLIB

LoAT can parse the [SMTLIB-format](https://www.microsoft.com/en-us/research/wp-content/uploads/2016/02/SMTPushdownPrograms.pdf) used in the category *Termination of Integer Transition Systems* at the annual [*Termination and Complexity Competition*](http://termination-portal.org/wiki/Termination_Competition).

## KoAT

LoAT also supports an extended version of [KoAT's input format](http://aprove.informatik.rwth-aachen.de/eval/IntegerComplexity/), which is also used in the category *Complexity of Integer Transition Systems* at the annual *Termination and Complexity Competition*.

In this extension, rules can be annotated with polynomial costs:
```
l1(A,B) -{A^2,A^2+B}> Com_2(l2(A,B),l3(A,B)) :|: B >= 0
```
Here, `A^2` and `A^2+B` are lower and upper bounds on the cost of the rule.
The upper bound is ignored by LoAT.
The lower bound has to be non-negative for every model of the transition's guard.

## Constrained Horn Clauses

LoAT can parse the [SMTLIB-format](https://chc-comp.github.io/format.html) used at the annual [*CHC-COMP*](https://chc-comp.github.io/).

# Publications

The techniques implemented in LoAT are described in the following publications (in chronological order):

* [Lower Runtime Bounds for Integer Programs](http://aprove.informatik.rwth-aachen.de/eval/integerLower/compl-paper.pdf)\
  F. Frohn, M. Naaf, J. Hensel, M. Brockschmidt, and J. Giesl\
  IJCAR '16
* [Proving Non-Termination via Loop Acceleration](https://arxiv.org/abs/1905.11187)\
  F. Frohn and J. Giesl\
  FMCAD '19
* [Inferring Lower Runtime Bounds for Integer Programs](https://doi.org/10.1145/3410331)\
  F. Frohn, M. Naaf, M. Brockschmidt, and J. Giesl\
  ACM Transactions on Programming Languages and Systems, 42(3), 2020
* [A Calculus for Modular Loop Acceleration](https://doi.org/10.1007/978-3-030-45190-5_4)\
  F. Frohn\
  TACAS '20\
  Winner of the EASST Best Paper Award
* [A Calculus for Modular Loop Acceleration and Non-Termination Proofs](https://doi.org/10.1007/s10009-022-00670-2)\
  F. Frohn and C. Fuhs\
  International Journal on Software Tools for Technology Transfer, volume 24
* [Proving Non-Termination and Lower Runtime Bounds with LoAT (System Description)](https://doi.org/10.1007/978-3-031-10769-6_41)\
  F.Frohn and J. Giesl\
  IJCAR '22

# Citing LoAT

If you refer to LoAT in your paper, please cite our [IJCAR '22 system description](https://doi.org/10.1007/978-3-031-10769-6_41)

# Awards

In 2020, LoAT competed as standalone tool at the [*Termination and Complexity Competition*](http://termination-portal.org/wiki/Termination_Competition) for the first time.

* best tool for proving non-termination in the category *Termination of Integer Transition Systems* at the [*Termination and Complexity Competition 2020*](http://termination-portal.org/wiki/Termination_Competition_2020)
* 2nd place in the category *Termination of Integer Transition Systems* at the [*Termination and Complexity Competition 2020*](http://termination-portal.org/wiki/Termination_Competition_2020)
* best tool for proving non-termination in the category *Termination of Integer Transition Systems* at the [*Termination and Complexity Competition 2021*](http://termination-portal.org/wiki/Termination_Competition_2021)
* 2nd place in the category *Termination of Integer Transition Systems* at the [*Termination and Complexity Competition 2021*](http://termination-portal.org/wiki/Termination_Competition_2021)
* best tool for proving non-termination in the category *Termination of Integer Transition Systems* at the [*Termination and Complexity Competition 2022*](http://termination-portal.org/wiki/Termination_Competition_2022)
* 2nd place in the category *Termination of Integer Transition Systems* at the [*Termination and Complexity Competition 2022*](http://termination-portal.org/wiki/Termination_Competition_2022)

From 2016 until the last run of this category in 2019, [AProVE](http://aprove.informatik.rwth-aachen.de/) was using LoAT as backend to prove lower bounds on the runtime complexity of integer transition systems.
In this constellation, AProVE and LoAT won the following awards:

* 1st place in the category *Complexity of Integer Transition Systems* at the [*Termination and Complexity Competition 2016*](https://termcomp.imn.htwk-leipzig.de/competitions/Y2016)
* 1st place in the category *Complexity of Integer Transition Systems* at the [*Termination and Complexity Competition 2017*](https://termcomp.imn.htwk-leipzig.de/competitions/Y2017)
* 1st place in the category *Complexity of Integer Transition Systems* at the [*Termination and Complexity Competition 2018*](http://group-mmm.org/termination/competitions/Y2018/)
* 1st place in the category *Complexity of Integer Transition Systems* at the [*Termination and Complexity Competition 2019*](http://group-mmm.org/termination/competitions/Y2019/)

Since 2021, [AProVE](http://aprove.informatik.rwth-aachen.de/) is using LoAT in its backend to prove non-termination of C programs (besides [T2](http://mmjb.github.io/T2/)).
In this constellation AProVE, LoAT, and T2 won the following awards:

* 2nd place in the Category Termination at the [*Competition on Software Verification 2022*](https://sv-comp.sosy-lab.org/2022/results/results-verified/)
* 1st place in the Category *Termination of C programs* at the[*Termination and Complexity Competition 2022*](http://termination-portal.org/wiki/Termination_Competition_2022)
* 1st place in the Category *Termination of C Integer programs* at the[*Termination and Complexity Competition 2022*](http://termination-portal.org/wiki/Termination_Competition_2022)

# Build

Install docker and run ``./compile_static_binary``. Then the path to the binary is ``./build/static/release/loat-static``.

If you experience any problems, contact florian.frohn [at] cs.rwth-aachen.de.
