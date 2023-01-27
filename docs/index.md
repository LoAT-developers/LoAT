<head>
    <title>LoAT</title>
</head>

LoAT (**Lo**op **A**cceleration **T**ool, formerly known as **Lo**wer Bounds **A**nalysis **T**ool) is a fully automated tool to analyze programs operating on integers.
Currently, it supports the inference of **lower bounds** on the worst-case runtime complexity and **non-termination proving**.

LoAT uses a [calculus for modular loop acceleration](https://doi.org/10.1007/978-3-030-45190-5_4) and a variation of ranking functions to deduce lower bounds and to prove non-termination.

The tool is based on the recurrence solver [PURRS](http://www.cs.unipr.it/purrs/) and the SMT solvers [Yices](https://yices.csl.sri.com/) and [Z3](https://github.com/Z3Prover/z3/).

# Downloading LoAT

[Here](https://github.com/loat-developers/LoAT/releases) you can find the latests releases of LoAT.
Older releases can be found [here](https://github.com/aprove-developers/LoAT/releases).

# Input Formats

To analyze programs with LoAT, they need to be represented as *Integer Transition Systems*.
It supports the most common formats for such systems.

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

## T2

LoAT also comes with experimental support for the native input format of [T2](https://github.com/mmjb/T2).

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

# Awards

In 2020, LoAT competed as standalone tool at the [*Termination and Complexity Competition*](http://termination-portal.org/wiki/Termination_Competition) for the first time.

* best tool for proving non-termination in the category *Termination of Integer Transition Systems* at the [*Termination and Complexity Competition 2020*](http://termination-portal.org/wiki/Termination_Competition_2020)
* 2nd place in the category *Termination of Integer Transition Systems* at the [*Termination and Complexity Competition 2020*](http://termination-portal.org/wiki/Termination_Competition_2020)
* best tool for proving non-termination in the category *Termination of Integer Transition Systems* at the [*Termination and Complexity Competition 2021*](http://termination-portal.org/wiki/Termination_Competition_2021)
* 2nd place in the category *Termination of Integer Transition Systems* at the [*Termination and Complexity Competition 2021*](http://termination-portal.org/wiki/Termination_Competition_2021)

Since 2016, [AProVE](http://aprove.informatik.rwth-aachen.de/) is using LoAT as backend to prove lower bounds on the runtime complexity of integer transition systems.
In this constellation, AProVE and LoAT won the following awards:

* 1st place in the category *Complexity of Integer Transition Systems* at the [*Termination and Complexity Competition 2016*](https://termcomp.imn.htwk-leipzig.de/competitions/Y2016)
* 1st place in the category *Complexity of Integer Transition Systems* at the [*Termination and Complexity Competition 2017*](https://termcomp.imn.htwk-leipzig.de/competitions/Y2017)
* 1st place in the category *Complexity of Integer Transition Systems* at the [*Termination and Complexity Competition 2018*](http://group-mmm.org/termination/competitions/Y2018/)
* 1st place in the category *Complexity of Integer Transition Systems* at the [*Termination and Complexity Competition 2019*](http://group-mmm.org/termination/competitions/Y2019/)

Since 2021, [AProVE](http://aprove.informatik.rwth-aachen.de/) is using LoAT in its backend to prove non-termination of C programs (besides [T2](http://mmjb.github.io/T2/)).
In this constellation AProVE, LoAT, and T2 won the following awards:

* 2nd place in the Category Termination at the [*Competition on Software Verification 2022*](https://sv-comp.sosy-lab.org/2022/results/results-verified/)

# Build

Install docker and run ``./compile_static_binary``. Then the path to the binary is ``./build/static/release/loat-static``.

If you experience any problems, contact florian.frohn [at] cs.rwth-aachen.de.
