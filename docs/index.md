<head>
    <title>LoAT</title>
    <style>
        p {text-align: justify;}
    </style>
</head>

LoAT (**Lo**op **A**cceleration **T**ool) is a fully automated tool to analyze *transition systems* and linear *Constrained Horn Clauses (CHCs)* with integer variables.
For transition systems, it supports the inference of **lower bounds** on the worst-case runtime complexity and **non-termination proving**.
For CHCs, it can prove **unsatisfiability**.

LoAT is based on a [calculus for modular *loop acceleration*](https://doi.org/10.1007/978-3-030-45190-5_4).
Loop acceleration transforms certain simple relations into first-order formulas that describe their transitive closure.
To lift loop acceleration to more complex formalisms (like transition systems or CHCs), earlier versions of LoAT used the framework described in [this paper](https://doi.org/10.1145/3410331).
Current versions use a novel calculus called [*ADCL*](https://arxiv.org/abs/2303.01827) instead.

LoAT uses the recurrence solver [PURRS](http://www.cs.unipr.it/purrs/), the SMT solvers [Yices](https://yices.csl.sri.com/) and [Z3](https://github.com/Z3Prover/z3/), and the automata-library [libFAUDES](https://www.fgdes.tf.fau.de/faudes/index.html).

# Downloading LoAT

[Here](https://github.com/loat-developers/LoAT/releases) you can find the latests releases of LoAT.
Older releases can be found [here](https://github.com/aprove-developers/LoAT/releases).

# Using LoAT

To choose the goal of your analysis, please use one of the following command-line option

* `--mode non_termination` for proving non-termination
* `--mode complexity` for proving lower bounds on the worst-case runtime complexity
* `--mode reachability` for proving reachability of error states, which corresponds to unsatisfiability of CHCs

Currently, reachability / unsatisfiability is supported for CHCs only, as LoAT's input formats for transition systems do not allow for specifying error states.

## Input Formats for Transition Systems

LoAT supports the most common formats for *Integer Transition Systems*.

### SMTLIB

LoAT can parse the [SMTLIB-format](https://www.microsoft.com/en-us/research/wp-content/uploads/2016/02/SMTPushdownPrograms.pdf) used in the category *Termination of Integer Transition Systems* at the annual [*Termination and Complexity Competition*](http://termination-portal.org/wiki/Termination_Competition).

To use this format, please use the command-line option `--format its`.

### C Integer Programs

LoAT can parse the [C Integer Programs](https://termination-portal.org/wiki/C_Integer_Programs) used in the category *Termination of C Integer Programs* at the annual [*Termination and Complexity Competition*](http://termination-portal.org/wiki/Termination_Competition).

To use this format, please use the command-line option `--format c`.

### KoAT

LoAT also supports an extended version of [KoAT's input format](http://aprove.informatik.rwth-aachen.de/eval/IntegerComplexity/), which is also used in the category *Complexity of Integer Transition Systems* at the annual *Termination and Complexity Competition*.

In this extension, rules can be annotated with polynomial costs:
```
l1(A,B) -{A^2,A^2+B}> l2(A,B) :|: B >= 0
```
Here, `A^2` and `A^2+B` are lower and upper bounds on the cost of the rule.
The upper bound is ignored by LoAT.
The lower bound has to be non-negative for every model of the transition's guard.

To use this format, please use the command-line option `--format koat`.

## Input Format for Constrained Horn Clauses

LoAT can parse the [SMTLIB-format](https://chc-comp.github.io/format.html) used at the annual [*CHC-COMP*](https://chc-comp.github.io/).

To use this format, please use the command-line option `--format horn`.

## Discontinued Features

Earlier versions of LoAT could analyze the complexity of non-tail-recursive transition systems, i.e., systems with transitions like `f(x) -> Com2(f(x-1), f(x-2)) :|: x>1`.
Such systems are no longer supported.
If you are interested in analyzing such systems, please use the release that was published with our [TOPLAS '20 paper](https://doi.org/10.1145/3410331).
A link to this release, as well as further information about using it, can be found [here](https://aprove-developers.github.io/its-lowerbounds-journal/).

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
  International Journal on Software Tools for Technology Transfer, 24(5), 2022
* [Proving Non-Termination and Lower Runtime Bounds with LoAT (System Description)](https://doi.org/10.1007/978-3-031-10769-6_41)\
  F.Frohn and J. Giesl\
  IJCAR '22
* [Proving Non-Termination by Acceleration Driven Clause Learning](https://arxiv.org/abs/2304.10166)\
  F.Frohn and J. Giesl\
  CADE '23
* [ADCL: Acceleration Driven Clause Learning for Constrained Horn Clauses](https://arxiv.org/abs/2303.01827)\
  F.Frohn and J. Giesl\
  SAS '23

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

* think about using one of our [releases](https://github.com/loat-developers/LoAT/releases) instead
* **Option A** using a pre-configured docker container -- recommended method if you do not plan major changes to the code
  1. install [Docker](https://www.docker.com/)
  3. download a docker container with pre-installed dependencies via `docker pull loat/loat-base`
  4. log in to the docker container via `docker run -it $CONTAINER_NAME bash`
  5. `git clone https://github.com/LoAT-developers/LoAT.git`
  6. `mkdir LoAT/build`
  7. `cd LoAT/build`
  8. `cmake -DCMAKE_BUILD_TYPE=$TYPE ..` where `$TYPE` is either `Release` or `Debug`,  depending on your use case
  9. `make -j$(nproc)`
  10. if everything worked, `./loat-static --help` should print a help message
* **Option B** using a devcontainer -- recommended method if you plan major changes to the code
  1. install and start Docker Desktop
  2. `git clone https://github.com/LoAT-developers/LoAT.git`
  3. `cd LoAT/scripts`
  4. execute each script `./extract_*.sh` to build each dependency in a docker container and copy it to `$PATH_TO_LOAT/docker/usr` on your machine
  5. `mkdir -p $PATH_TO_LOAT/build/debug`
  6. The configuration for the dev-container is in `$PATH_TO_LOAT/.devcontainer`, so in theory, you can use any IDE with support for dev-containers. For Visual Studio Code, open `$PATH_TO_LOAT` via `File -> Open Folder...`
  7. Make sure that the user `vscode` in the  devcontainer has read and write permissions, see https://docs.docker.com/desktop/faqs/linuxfaqs/#how-do-i-enable-file-sharing. My current solution is that all project files belong to group 100999, which has all required permissions.
  8. press `F1` and type `Dev Containers: Reopen in Container`
  9. click `Build` on the bottom to trigger the build

If you experience any problems, contact `florian.frohn [at] cs.rwth-aachen.de`.

