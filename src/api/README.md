# LoAT C++ API

This is a C++ interface for configuring and using LoAT (Loop Acceleration Tool) programmatically. It provides a structured way to define a transition system, select engines/SMT solvers, and analyze properties like **termination** or **safety**.

## ⚙️ Requirements

* C++17 or higher
* [Boost](https://www.boost.org/)
* [Faudes](https://sourceforge.net/projects/faudes/)  
* [Z3 SMT solver](https://github.com/Z3Prover/z3)  
* [Yices SMT solver](https://yices.csl.sri.com/)  
* [Poly](https://github.com/ths-poly/poly)  
* [PolyXX](https://github.com/ths-poly/polyxx)  
* [CUDD](https://github.com/ivmai/cudd)
* [Swine-Z3](https://github.com/ths-rwth/swine)  
* [CLN – Class Library for Numbers](https://www.ginac.de/CLN/)  
* [GMP – GNU Multiple Precision Arithmetic Library](https://gmplib.org/)


---

## 🧪 Template Repository

You can use our ready-to-go [LoAT API Template Repository](https://github.com/LoAT-developers/LoAT-API-Example) which includes:

- A complete **example project**
- The correct **Docker image** with all dependencies preinstalled
- A minimal `main.cpp` with a working LoAT analysis setup

This is the fastest way to get started and ensures all dependencies are resolved.

---

## 🚀 Quickstart

### ✅ Create a Configuration

#### 🔹 Initial Config only:

```cpp
#include "loatconfig.hpp"

LoatConfig::InitialConfig init(
    LoatConfig::InitialConfig::Engine::ADCL,               // Engine (TRL, ADCL, ABMC, ...)
    LoatConfig::InitialConfig::Mode::Termination,          // Analysis Mode (Termination, Safety)
    LoatConfig::InitialConfig::SmtSolver::Z3,              // SMT backend (Z3, Yices, ...)
    LoatConfig::InitialConfig::Direction::Forward,         // Direction (Forward)
    LoatConfig::InitialConfig::MbpKind::IntMbp,            // MBP variant
    false                                                  // Enable proof
);

LoatConfig config(init); // only initial config
```

#### 🔹 Add dynamic parameters (optional):

```cpp
LoatConfig::DynamicConfig dyn;
dyn.set(DynamicParameterKey::Log, true); // enable logging

LoatConfig config(init, dyn);
```

### ✅ Create a solver

```cpp
#include "loatsolver.hpp"
#include "loattransition.hpp"
#include "loatintexpr.hpp"

LoatSolver solver(config);
```

### ✅ Define a Transition System

#### 📍 Define locations and transitions

```cpp
LoatLocation q0("q0");
LoatLocation q1("q1");

solver.setStartLocation(q0);
solver.add(LoatTransition(q0, q1, LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));
```

> ❗ Only **one sink location** can be defined via `addSinkLocation(...)`.

---

### ✅ Run Analysis

```cpp
LoatResult result = solver.check();
```

You can expect:

* `LoatResult::SAT` → system is terminating (or bounded, etc.)
* `LoatResult::UNSAT` → system is non-terminating / unbounded / unsafe
* `LoatResult::UNKNOWN` → solver couldn't determine result

---

## 🔍 Supported Engines & Modes

| Engine | Supports Termination | Supports Safety |
| ------ | -------------------- | ---------------- |
| TRL    | ✅ Yes (Termination)               | ✅ Yes (Safety/Unsafety)             |
| ADCL   | ✅ Yes (Non Termination)               | ✅ Yes (Unsafety)           |
| ABMC   | ✅ Yes (Non Termination)         | ✅ Yes (Safety/Unsafety)             |
| ADCLSAT   | ❌ No                 | ✅ Yes (Safety)            |
| KIND   | ❌ No                 | ✅ Yes (Safety/Unsafety)            |
| BMC    | ❌ No                 | ✅ Yes (Unsafety)            |

---

## 🧠 Building Expressions

LoAT provides a symbolic API for building both integer (`LoatIntExprPtr`) and boolean (`LoatBoolExprPtr`) expressions using factory functions and overloaded operators.

### 🔢 Integer Expressions

You can construct integer expressions like constants, variables, arithmetic operations, and exponentiation:

```cpp
using namespace LoatIntExpression;

// Constants and variables
auto x = mkPreVar("x");         // pre-state variable x
auto y = mkPostVar("y");        // post-state variable y
auto c = mkConst(42);           // constant 42

// Arithmetic expressions
auto sum = x + c;               // x + 42
auto product = x * y;           // x * y
auto negation = -x;             // -x
auto modExpr = mkMod(x, c) ;          // x mod 42
auto expExpr = x ^ y;          // x^y
```

### 🔁 Variable Naming

Use `mkPreVar("x")` for pre-state variables and `mkPostVar("x")` for post-state.
Variable Pairs must have the same name. The programm will print them automatically with as `x` or `x'`, depending on their type 

---

### 🔘 Boolean Expressions

Boolean expressions can be built using logic combinators and comparisons between integer expressions.

```cpp
using namespace LoatBoolExpression;

// Logical operations
auto a = mkPreVar("a");     // boolean pre-variable
auto b = mkPostVar("b");    // boolean post-variable
auto logic = a && !b;       // a ∧ ¬b

// Comparisons
auto x = mkPreVar("x");
auto y = mkConst(10);
auto cond1 = x < y;         // x < 10
auto cond2 = x == y;        // x == 10

auto combined = cond1 || cond2; // (x < 10) ∨ (x == 10)
```

You can use the following overloaded operators:

#### 🔢 Integer Operators
- `+` – Addition  
- `*` – Multiplication  
- `-` – Subtraction / Negation  
- `^` – Exponentiation  
- `==`, `!=` – Equality / Inequality  
- `<`, `<=`, `>`, `>=` – Comparisons

#### 🔘 Boolean Logic Operators
- `&&` – Logical AND  
- `||` – Logical OR  
- `!` – Logical NOT

## 🧩 Solver Presets

You can directly create solvers for common use-cases without manual config:

```cpp
LoatSolver solver1 = LoatSolver::forTermination();
LoatSolver solver2 = LoatSolver::forNonTermination();
LoatSolver solver3 = LoatSolver::forSafety();
LoatSolver solver4 = LoatSolver::forUnsafety();
```
