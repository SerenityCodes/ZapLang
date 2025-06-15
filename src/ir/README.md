# Zap IR

Zap IR is the intermediate stage between the AST and whatever the target architecture is. Currently, the plan is to support a compilation target to C++, LLVM, and a bytecode VM for quick development. The IR can be summarized as a typed assembly language, with similarities to LLVM IR to make it easier to compile to LLVM. It is a simplfied SSA-based IR to make compiler optimizations easier and more effective.

---
## Core Elements

### Types
The IR supports basic, composite, and ECS-specific types.

**void**: Return value not expected.

### Primitive Types

- bool
- unsigned int (u8, u16, u32, u64)
- signed int (i8, i16, i32, i64)
- floating point numbers (f32, f64)

### Composite Types
- struct
```text
struct <name> (<name>: <type>, ...)
```
- ECS Types: Component (reference to ECS component data).
```
component <name> (<name>: <type>, ...)
```
---
### Values
Values represent operands for instructions. They include:
- **Immediate:** A constant value like 10, "Nice", 20.1000, 3.145, etc...
- **Register:** Virtual registers like `%1`, `%2`. Note that there is no limit placed on these, as register allocation is done from IR -> target.
- **Static:** Strings, constant arrays, and other constants will be stored in static memory (.bss) or on the stack when able.
---

## Opcode Instructions

### Arithmetic
Perform arithmetic operations on numeric types. If precision differs, highest precision is the resulting type (u32 + u16 = u32). The order of operations always goes from left to right. For example, %1 = div %0, %0 is %1 = %0 / %0.

#### Add
```text
// %2 = %0 + %1
%2 = add %0, %1     
```

#### Sub
```text
// %2 = %0 - %1
%2 = sub %0, %1      
```

#### Mul
```text
// %2 = %0 * %1
%2 = mul %0, %1
```

#### Div
```text
// %2 = %0 / %1
%2 = div %0, %1
```

#### Mod
```text
// %2 = %0 % %1
%2 = mod %0, %1
```

---

### Comparison
Compare values and return a boolean result.

#### Eq (Equal)
```text
%2 = eq %0, %1       ; %2 = (%0 == %1)
```

#### Ne (Not Equal)
```text
%2 = ne %0, %1        ; %2 = (%0 != %1)
```

#### Lt (Less Than)
```text
%2 = lt %0, %1        ; %2 = (%0 < %1)
```

#### Le (Less Than or Equal)
```text
%2 = le %0, %1       ; %2 = (%0 <= %1)
```

#### Gt (Greater Than)
```text
%2 = gt %0, %1        ; %2 = (%0 > %1)
```

#### Ge (Greater Than or Equal)
```text
%2 = ge %0, %1         ; %2 = (%0 >= %1)
```

---

### Logical
Perform logical operations.

#### And
```text
%2 = and %0, %1 ; %2 = (%0 && %1)
```

#### Or
```text
%2 = or %0, %1  ; %2 = (%0 || %1)
```

#### **Not**
```text
%1 = not %0        ; %1 = (!%0)
```

---

### Memory
Allocate and manage memory.

#### Alloca
```text
%ptr = alloca u32         ; Allocate stack space for u32
```

#### Load
```text
%value = load %ptr        ; Load value from stack
```

#### Store
```text
store %ptr, 42            ; Store 42 in memory
```

### Arena Memory Operations

#### ArenaAlloc

Allocate memory from an arena.

```text
%ptr = arena_alloc %arena, u32       ; Push a u32 onto the arena
%entity = arena_alloc %arena, Player ; Push a Player struct
```

#### ArenaClear

Clears the arena of all allocations done

```text
arena_clear %arena
```

#### ArenaDealloc

Deallocates all allocations done in this arena in the current stack frame

```text
arena_dealloc %arena
```

---

### Control Flow

#### Jump (Unconditional Branch)
```text
jmp %block1                
```

#### Branch (Conditional Branch)
```text
br %1, %block1, %block2 ; Jump to %block1 if %1 is true, else %block2
```

#### Ret

Return a value or exit the function.

```text
ret %1                   ; Return %1 from function
ret
```

---
### Function Calls

#### Call
```text
%result = call @func, %arg1 ; Call @func with %arg1
```
---

### Component Operations (ZapLang Specific)
Work with ECS component data.

#### Load Component
```text
%health = component_load %entity, Health.value
```

#### Store Component
```text
component_store %entity, Health.value, %new_health
```

#### Get Entity
```text
%transform = entity_get %id, Transform
```
---

### Struct Operations
Access and modify struct fields.

#### Get
```text
%name = struct_get %player, name ; Get the 'name' field from struct %player
```

#### StructSet
```text
struct_set %player, name, %new_name ; Set the 'name' field in struct %player to %new_name
```

---

### Type Operations
Handle type casting.

#### Cast
```text
%float_value = cast f32 %int_value
```

## Example IR Program

ZapLang code:
```zap
@[system(Update)]
func update_health(entity: u32, health: ref Health) -> void {
    if (health.value > 0) {
        health.value = health.value - 1;
    }
}
```

Generated Zap IR:
```text
function @update_health(entity: u32, health: component_ref Health) -> void
attributes: [system("Update")]
{
entry:
    %1 = component_load %entity, Health.value
    %2 = gt %1, 0
    br %2, then_block, end_block

then_block:
    %3 = sub %1, 1
    component_store %entity, Health.value, %3
    jmp end_block

end_block:
    ret
}
```

---
