<head>
    <title>LoAT</title>
    <style>
        p {text-align: justify;}
    </style>
</head>

LoAT (**Lo**op **A**cceleration **T**ool) is a fully automated tool to analyze *transition systems* and linear *Constrained Horn Clauses (CHCs)* with integer variables.
For transition systems, it supports the inference of **lower bounds** on the worst-case runtime complexity and **non-termination proving**.
For CHCs, it can **prove and disprove satisfiability**.

LoAT is based on a variety of techniques:

* Most of LoAT's techniques use a [calculus for modular *loop acceleration*](https://doi.org/10.1007/978-3-030-45190-5_4).
  Loop acceleration transforms certain simple relations into first-order formulas that describe their transitive closure.
* To lift loop acceleration to more complex formalisms (like transition systems or CHCs), earlier versions of LoAT used the framework described in [this paper](https://doi.org/10.1145/3410331).
* Current versions use
  * [ADCL](https://arxiv.org/abs/2303.01827) (default for lower bounds and non-termination),
  * [ABMC](https://arxiv.org/abs/2401.09973) (only available for satisfiability and non-termination), and
  * [TRL](https://arxiv.org/abs/2502.04761) (only available, and the default for satisfiability).
* Apart from that, LoAT also implements
  * Bounded Model Checking and
  * k-Induction.

LoAT uses the recurrence solver [PURRS](http://www.cs.unipr.it/purrs/), the SMT solvers [SwInE](https://ffrohn.github.io/swine/), [Yices](https://yices.csl.sri.com/), and [Z3](https://github.com/Z3Prover/z3/), and the automata-library [libFAUDES](https://www.fgdes.tf.fau.de/faudes/index.html).

# Downloading LoAT

[Here](https://github.com/loat-developers/LoAT/releases) you can find the latests releases of LoAT, including nightly releases.
Older releases can be found [here](https://github.com/aprove-developers/LoAT/releases).

# Using LoAT

See `loat-static --help`.

## Input Format for Transition Systems

LoAT can parse the [ARI-format](https://termination-portal.org/wiki/Term_Rewriting#Integer_Transition_Systems) used at the annual [*Termination and Complexity Competition (TermComp)*](https://termination-portal.org/wiki/Termination_Competition).

For examples, we refer to the [TPDB benchmarks for termination](https://github.com/TermCOMP/TPDB-ARI/tree/master/Integer_Transition_Systems) and for [complexity analysis](https://github.com/TermCOMP/TPDB-ARI/tree/master/Complexity_ITS).

## Input Format for Constrained Horn Clauses

LoAT can parse the [SMTLIB-format](https://chc-comp.github.io/format.html) used at the annual [*CHC-COMP*](https://chc-comp.github.io/).

For examples, we refer to the [CHC-COMP benchmarks from 2024](https://github.com/chc-comp/chc-comp24-benchmarks/tree/main/LIA-Lin).

## Discontinued Features

Earlier versions of LoAT could analyze the complexity of non-tail-recursive transition systems, i.e., systems with transitions like `f(x) -> Com2(f(x-1), f(x-2)) :|: x>1`.
Such systems are no longer supported.
If you are interested in analyzing such systems, please use the release that was published with our [TOPLAS '20 paper](https://doi.org/10.1145/3410331).
A link to this release, as well as further information about using it, can be found [here](https://aprove-developers.github.io/its-lowerbounds-journal/).

Moreover, earlier versions of LoAT could parse the [SMTLIB-format](https://www.microsoft.com/en-us/research/wp-content/uploads/2016/02/SMTPushdownPrograms.pdf), the [KoAT format](http://aprove.informatik.rwth-aachen.de/eval/IntegerComplexity/), and the [C-Integer format](https://termination-portal.org/wiki/C_Integer_Programs) that had been used at TermComp.
Since all of these formats have been discontinued at TermComp, they are no longer supported.

# Publications

The techniques implemented in LoAT are described in the following publications (in reversed chronological order):

* [Infinite State Model Checking by Learning Transitive Relations](https://arxiv.org/abs/2502.04761)\
  F. Frohn and J. Giesl\
  CADE '25
* [Integrating Loop Acceleration into Bounded Model Checking](https://arxiv.org/abs/2401.09973)\
  F. Frohn and J. Giesl\
  FM '24
* [ADCL: Acceleration Driven Clause Learning for Constrained Horn Clauses](https://arxiv.org/abs/2303.01827)\
  F. Frohn and J. Giesl\
  SAS '23
* [Proving Non-Termination by Acceleration Driven Clause Learning](https://arxiv.org/abs/2304.10166)\
  F. Frohn and J. Giesl\
  CADE '23
* [Proving Non-Termination and Lower Runtime Bounds with LoAT (System Description)](https://doi.org/10.1007/978-3-031-10769-6_41)\
  F. Frohn and J. Giesl\
  IJCAR '22
* [A Calculus for Modular Loop Acceleration and Non-Termination Proofs](https://doi.org/10.1007/s10009-022-00670-2)\
  F. Frohn and C. Fuhs\
  International Journal on Software Tools for Technology Transfer, 24(5), 2022
* [A Calculus for Modular Loop Acceleration](https://doi.org/10.1007/978-3-030-45190-5_4)\
  F. Frohn\
  TACAS '20\
  Winner of the EASST Best Paper Award
* [Inferring Lower Runtime Bounds for Integer Programs](https://doi.org/10.1145/3410331)\
  F. Frohn, M. Naaf, M. Brockschmidt, and J. Giesl\
  ACM Transactions on Programming Languages and Systems, 42(3), 2020
* [Proving Non-Termination via Loop Acceleration](https://arxiv.org/abs/1905.11187)\
  F. Frohn and J. Giesl\
  FMCAD '19
* [Lower Runtime Bounds for Integer Programs](http://aprove.informatik.rwth-aachen.de/eval/integerLower/compl-paper.pdf)\
  F. Frohn, M. Naaf, J. Hensel, M. Brockschmidt, and J. Giesl\
  IJCAR '16

# Citing LoAT

If you refer to LoAT in your paper, please cite our [IJCAR '22 system description](https://doi.org/10.1007/978-3-031-10769-6_41)

# Awards

LoAT competes in several competitions.

## CHC-COMP

LoAT competes in the category *LIA-Lin* (linear clauses with linear integer arithmetic) of the [*CHC Competition*](https://chc-comp.github.io/) since 2023.

<details>

<summary>Click to see LoAT's CHC-COMP results</summary>

<h3><a href="https://chc-comp.github.io/">CHC-COMP 2025</a></h3>

<h4>LIA-Lin</h4>

<ul>
<li>3rd place</li>
<li>best tool (tied with <a href="https://github.com/usi-verification-and-security/golem">Golem</a>) for proving unsatisfiability</li>
</ul>

<h3><a href="https://chc-comp.github.io/2024">CHC-COMP 2024</a></h3>

<h4>LIA-Lin</h4>

<ul>
<li>3rd place</li>
</ul>

</details>

## TermComp

LoAT competes in several categories of the [*Termination and Complexity Competition*](http://termination-portal.org/wiki/Termination_Competition) since 2016.

From 2016 until 2019, [AProVE](http://aprove.informatik.rwth-aachen.de/) was using LoAT as backend to prove lower bounds on the runtime complexity of integer transition systems.
Nowadays, LoAT and [KoAT](https://koat.verify.rwth-aachen.de/) compete together in this category.

Since 2022, [AProVE](http://aprove.informatik.rwth-aachen.de/) is using LoAT in its backend to prove non-termination of C programs.

### [TermComp 2025](http://termination-portal.org/wiki/Termination_Competition_2025)

#### Termination of Integer Transition Systems

* best tool for proving non-termination

#### Complexity of Integer Transition Systems

* 1st place (with KoAT)

### [TermComp 2024](http://termination-portal.org/wiki/Termination_Competition_2024)

#### Termination of Integer Transition Systems

* best tool for proving non-termination

#### Termination of C Programs

* 1st place (with AProVE)

### [TermComp 2023](http://termination-portal.org/wiki/Termination_Competition_2023)

#### Termination of Integer Transition Systems

* best tool for proving non-termination

#### Termination of C Programs

* 1st place (with AProVE)

#### Termination of C Integer Programs

* 1st place (with AProVE)

### [TermComp 2022](http://termination-portal.org/wiki/Termination_Competition_2022)

#### Termination of Integer Transition Systems

* best tool for proving non-termination

#### Termination of C Programs

* 1st place (with AProVE)

#### Termination of C Integer Programs

* 1st place (with AProVE)

### [TermComp 2021](http://termination-portal.org/wiki/Termination_Competition_2021)

#### Termination of Integer Transition Systems

* 2nd place
* best tool for proving non-termination

### [TermComp 2020](http://termination-portal.org/wiki/Termination_Competition_2020)

#### Termination of Integer Transition Systems

* 2nd place
* best tool for proving non-termination

### [TermComp 2019](http://termination-portal.org/wiki/Termination_Competition_2019)

#### Complexity of Integer Transition Systems

* 1st place (with AProVE and KoAT)

### [TermComp 2018](http://termination-portal.org/wiki/Termination_Competition_2018)

#### Complexity of Integer Transition Systems

* 1st place (with AProVE and KoAT)

### [TermComp 2017](http://termination-portal.org/wiki/Termination_Competition_2017)

#### Complexity of Integer Transition Systems

* 1st place (with AProVE and KoAT)

### [TermComp 2016](http://termination-portal.org/wiki/Termination_Competition_2016)

#### Complexity of Integer Transition Systems

* 1st place (with AProVE and KoAT)

## SV-COMP

Together with AProVE, LoAT competes in the category *Termination* of the [*Competition on Software Verification*](https://sv-comp.sosy-lab.org)

### [SV-COMP 2026](https://sv-comp.sosy-lab.org/2026/results/results-verified/)

#### Termination

* 3rd place (with AProVE)

### [SV-COMP 2025](https://sv-comp.sosy-lab.org/2025/results/results-verified/)

#### Termination

* 3rd place (with AProVE)

### [SV-COMP 2022](https://sv-comp.sosy-lab.org/2022/results/results-verified/)

#### Termination

* 2nd place (with AProVE)

# Build

think about using one of our [releases](https://github.com/loat-developers/LoAT/releases) instead
1. install [Docker](https://www.docker.com/)
2. download the latest docker container with pre-installed dependencies via `docker pull loat/loat-base:$VERSION`
3. log in to the docker container via `docker run -it loat/loat-base:$VERSION bash`
4. `git clone https://github.com/LoAT-developers/LoAT.git`
5. `mkdir LoAT/build`
6. `cd LoAT/build`
7. `cmake -DCMAKE_BUILD_TYPE=$TYPE ..` where `$TYPE` is either `Release` or `Debug`,  depending on your use case
8. `make -j$(nproc)`
9. if everything worked, `./loat-static --help` should print a help message

