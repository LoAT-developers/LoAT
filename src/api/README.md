# API

## ⚙️ Requirements

- C++17 or higher
- [Boost](https://www.boost.org/) installed

> ✅ **TODO**: Add CMake usage and link further solver dependencies (e.g., Z3, etc)

---

## 🛠️ Usage

### 🔹 Creating a Config

You begin by defining an `InitialConfig`:

```cpp
#include "loatconfig.hpp"

#include "loatconfig.hpp"

LoatConfig::InitialConfig init(
    LoatConfig::InitialConfig::Engine::ADCL,
    LoatConfig::InitialConfig::Mode::Complexity,
    LoatConfig::InitialConfig::SmtSolver::Z3,
    LoatConfig::InitialConfig::Direction::Forward,
    LoatConfig::InitialConfig::MbpKind::IntMbp,
    false // proof enabled?
);
```

✅ Option 1: Only initial config (dynamic config uses defaults)

```cpp
LoatConfig config(init);
```

✅ Option 2: Provide initial + dynamic config
```cpp
LoatConfig::DynamicConfig dyn;
//You must use set(...) on DynamicConfig, since direct access to fields is not allowed.
dyn.set(DynamicParameterKey::Log, true);
dyn.set(DynamicParameterKey::TRP_RecurrentCycles, true);

LoatConfig config(init, dyn);
```
---

### 🔹 Using the Solver

```cpp
#include "loatsolver.hpp"

LoatSolver solver(config);
```

You can update parameters at runtime:

```cpp
solver.setParameter(DynamicParameterKey::LogAccel, true);
```

Then apply updated dynamic config globally
```cpp
solver.refreshConfig(); 
```

---