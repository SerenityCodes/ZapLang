# ⚡ ZapLang — The ECS Programming Language for Games

## Introduction

**ZapLang** is a modern, statically typed programming language built *from the ground up* for **game development** and **game engine development**.

It can compile to **LLVM IR** for native code support, or **Zap Bytecode** for fast iteration during development. This gives you unmatched flexibility, predictable control over memory, and a clean syntax optimized for **entity-component systems**, **real-time simulation**, and **high-performance gameplay code**.

## Motivation

ZapLang was born from the frustration of building a 3D renderer in C++ and wanting to have a better experience when it came to developing games and game servers. Writing ECS (Entity-Component-System) code felt unintuitive and clunky. While Flecs has their own scripting language, I wanted to take it a step further and create a programming language that could stand on its own while being purpose-built for game development. ZapLang is built from the frustration of keeping Jai closed source for so long. I also just wanted to create a programming language.

#### Components Are First-Class Citizens
Zap has *language-level support for ECS*, with intuitive ways to creating components and systems.

```zap
component Health {
    value: u8;
}
```

#### Attributes for Systems, Events, and Tooling
Declarative annotations let the engine or runtime identify key behavior:

```zap
@[system(Update)]
func update_health(entity: u32, health: ref Health) -> void {
    if (health.value > 0) {
        health.value = health.value - 1;
    }
}
```

## Features

🧱 **Components**
- Declared with the `component` keyword
- Native ECS-style storage expected in runtime
- Copy/Reference semantics using `ref` and `readonly` instead of pointers

⚙️ **Attributes**
- Declared with `@[name(args...), attr2(args...), ...]`
- Used to annotate systems, networking, serialization, UI hooks
- Customizable and introspectable

🔁 **Systems**
- Any func with component parameters and an attribute like `@[system(Update)]`
- Support for @[system(...), dependsOn(otherSystem)], to allow for 
- ECS runtime compiles and schedules the functions accordingly.

📦 **Modules**
- External code is sorted by directories. No `import` statements, no `using` statements. If the code is in your project, then it can be called accordingly.
- Functions can be given a `private` attribute, giving a compile error if used elsewhere in the project.

⚡ **Multiple Compilation Targets**
- Compiles to LLVM IR for native machine code performance on any platform supporting Vulkan.
- Can bind to C functions (automatic bindings can be generated).
- Optimizable at the IR level.

🧩 **Arena Memory Model**
- The arena memory model is vastly overlooked when considering options for memory management. Full garbage collection, or malloc are not the only options, and come with their own host of problems. In a game scenario, arenas make sense, and are cache efficient.
- Arena memory model is a more data oriented pattern, thus support is native.
- Sizes of arenas can be calculated during the profile build phase.
- Other methods of memory management may be added later if arenas aren't all they seem to be.

### 🧪 Example Program

```zap
// Define a component with entity data
component Health {
    value: u8;
}

readonly component Name {
    bytes: u8[64];
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

// System with readonly parameters
@[system(Update)]
func update_health(entity: u32, health: readonly Health) -> void {
    if (health.value > 0) {
        log("Health: {}", health.value);
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
    // Runs at the end
    defer log("Game shutting down...");
    
    // ECS Query Handle
    let query: Query<Health> = query(Health);
     
    log("Spawn points: {}", get_spawn_points());
    
    // job is a module here, not a class with a method
    let job_id: u32 = jobs.spawn(load_assets);
}
```

### Design Philosophies
- **Predictable**: Like C, things are explicit, and there are no hidden allocations, as you need to pass in an arena to anything that needs to allocate.
- **Simple**: Familiar syntax makes the language easy to understand.
- **Focused**: Game development comes first. Server side ECS support will come first before the Vulkan library.
- **Toolable**: The language will have as many built in tools as possible. Once the compiler is installed, the lsp, formatter, linter, etc. will be built in. No third party installs or confusing build systems to learn. Every Zap project builds the same.
- **Composable**: ECS-first architecture is data oriented, leading to immense performance gains when taken advantage of properly.


## Roadmap

🚧 **Project Status**

ZapLang is currently in development. Major components:
- ✅ Lexer & Parser (ANTLR4)
- ✅ Component & Attribute Parsing
- 🚧 AST & Type System (Arrays are still being worked out)
- 🚧 Zap IR Generation
- 🚧 LLVM IR code generation
- 🚧 Type inference
- ⏳ Game runtime (ECS runtime (most likely flecs), Vulkan/SDL libraries for games, UI library, ...)
- ⏳ Tooling (formatter, LSP, build system)

### Build Instructions

```bash
git clone https://github.com/SerenityCodes/ZapLang
cd ZapLang
mkdir build && cd build
cmake ..
make
./zapc your_file.zap
```

## Language Specification

Language specification can be found in the language.md or Wiki section of the Github. Comprehensive documentation will come as the language matures from a toy compiler to a real compiler.

---

📜 **License**

- GPL v3 License — free to use, modify, and distribute the language under GPL terms.
- MIT License - for any games built with Zap, only attribution is required. All commercial rights for your games are yours, and you owe nothing to ZapLang for the projects you build with it. Libraries used for the runtime will respect this license and not the GPL license.

---
