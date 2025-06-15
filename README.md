# 🎮 ZapLang — The Game Programming Language

## Introduction

**ZapLang** is a modern, statically typed programming language built *from the ground up* for **game development** and **game engine architecture**.

It compiles directly to **LLVM IR**, giving you unmatched performance, predictable control over memory, and a clean syntax optimized for **entity-component systems**, **real-time simulation**, and **high-performance gameplay code**.

> Zap is not a general-purpose language that *can* be used for games — it's a language that exists *for games.*

## Motivation

🧩 **Components Are First-Class Citizens**  
Unlike C++, Rust, or C#, Zap has *language-level support for ECS*—components aren't structs with annotations. They're baked into the syntax and semantics.

```zap
component Health {
    value: u8;
}
```

⚡ **Attributes for Systems, Events, and Tooling**  
Declarative annotations let the engine or runtime identify key behavior:

```zap
@[system(Update)]
func update_health(entity: u32, health: ref Health) -> void {
    if (health.value > 0) {
        health.value = health.value - 1;
    }
}
```

🧠 **Direct-to-LLVM Compilation**  
Zap compiles to native code via LLVM, no bytecode or virtual machine. That means instant performance and seamless FFI with C/C++ libraries.

🛠 **Simplicity + Performance**  
Like Go, Zap has a simple syntax. Like Rust and C++, it offers raw performance. But unlike both, it doesn't fight you or over-abstract — what you write is what you get.

## Features

🧱 **Components**
- Declared with the `component` keyword
- Native ECS-style storage expected in runtime
- Read/write semantics using `ref`, `val`

⚙️ **Attributes**
- Declared with `@[name(args...)]`
- Used to annotate systems, networking, serialization, UI hooks
- Customizable and introspectable

🔁 **Systems**
- Any func with component parameters and an attribute like `@[system(Update)]`
- Runtime auto-discovers and schedules them
- Systems support `ref`, `val`, and `mut` semantics

📦 **Modules**
- Support for `module` declarations
- Encapsulation and hierarchy for game projects

⚡ **LLVM IR Output**
- Compiles directly to native machine code
- Supports native interop (C ABI)
- Optimizable at the IR level

🧩 **Memory Model**
- No garbage collection
- Deterministic lifetimes and ownership
- Component storage and memory layout designed for cache-friendliness

### 🧪 Example Program

```zap
// Define a component with entity data
component Health {
    value: u8;
}

readonly component Name {
    ascii_name: u8[];
}

// Define a struct for game settings
struct GameSettings {
    max_players: u16;
    gravity: f32;
}

// System to update health each frame
@[system(Update)]
func update_health(entity: u32, health: ref Health) -> void {
    if (health.value > 0) {
        health.value = health.value - 1;
    }
}

// Run once before the main loop starts
@[system(Init)]
func init_system() -> void {
    log("Initializing game systems...");
}

// Compile-time constant using aot block
func get_spawn_points() -> u32 {
    let points: u32 = aot {
        let result: u32 = 0;
        for (let i: u32 = 0; i < 10; i = i + 1) {
            result = result + 3;
        }
        yield result;
    };
    return points;
}

// Main entry point
func main() -> void {
    engine.initialize();
    
    log("Spawn points: ", get_spawn_points());
    
    let job_id: u32 = job.spawn(load_assets);
    
    defer log("Game shutting down...");
}
```

### 🎯 Game-Centric Design Goals

Zap isn't trying to replace every language. It's trying to be the best language for writing game logic, systems code, and engine internals.

| Feature | ZapLang | C++ | Rust | Go |
|---------|---------|-----|------|-----|
| First-class Components | ✅ | ❌ | ❌ | ❌ |
| ECS System Integration | ✅ | ❌ | ❌ | ❌ |
| Attributes / Metadata | ✅ `@[attr]` | ✅ | ✅ | ❌ |
| LLVM Native Compilation | ✅ | ✅ | ✅ | ❌ |
| Simple, Fast Builds | ✅ | ❌ | ❌ | ✅ |
| High Performance | ✅ | ✅ | ✅ | ⚠️ |
| Game Engine Focus | ✅ | ❌ | ❌ | ❌ |

## Roadmap

🚧 **Project Status**

ZapLang is currently in development. Major components:
- ✅ Lexer & Parser (ANTLR4)
- ✅ AST & Type System
- ✅ Component & Attribute parsing
- 🚧 LLVM IR code generation
- 🚧 Type inference
- ⏳ Game runtime (ECS scheduler, memory layout)
- ⏳ Module system
- ⏳ Tooling (formatter, LSP)

### ⚙️ Build Instructions

```bash
git clone https://github.com/SerenityCodes/ZapLang
cd ZapLang
mkdir build && cd build
cmake ..
make
./zapc your_file.zap
```

### 🧠 Philosophy
- **Predictable**: Performance is obvious and explicit.
- **Simple**: Readable syntax, no ceremony.
- **Focused**: Game dev comes first. Everything else is secondary.
- **Toolable**: Attributes and structure encourage great tools and editor support.
- **Composable**: ECS-first architecture encourages scalable, clean code.

## Language Specification

### Basic Syntax

**Variables and Types:**
```zap
let x: u32 = 10;
let y: f32 = 3.14;
let name: str = "Player";
```

**Functions:**
```zap
func add(a: u32, b: u32) -> u32 {
    return a + b;
}
```

**Structs:**
```zap
struct Player {
    name: str;
    level: u32;
    health: f32;
}
```

**Components:**
```zap
component Transform {
    x: f32;
    y: f32;
    z: f32;
}

readonly component Renderable {
    mesh_id: u32;
    texture_id: u32;
}
```

**Systems with Attributes:**
```zap
@[system(Update)]
func movement_system(entity: u32, transform: ref Transform) -> void {
    transform.x = transform.x + 1.0;
}
```

**Control Flow:**
```zap
// If statements
if (condition) {
    // code
} else {
    // code
}

// Loops
while (condition) {
    // code
}

for (let i: u32 = 0; i < 10; i = i + 1) {
    // code
}
```

**Modules:**
```zap
module Graphics {
    func render() -> void {
        // rendering code
    }
}
```

**Compile-time Evaluation:**
```zap
let computed_value: u32 = aot {
    let result: u32 = 0;
    for (let i: u32 = 0; i < 100; i = i + 1) {
        result = result + i;
    }
    yield result;
};
```

---

📜 **License**

GPL v3 License — free to use, modify, and distribute under GPL terms.

---

🚀 **Try It, Hack It, Build Games With It**

ZapLang is a bold attempt to build the ideal game language — by game developers, for game developers. Want to help shape the future of game programming?

👉 Star the repo, file issues, and come build with us.
