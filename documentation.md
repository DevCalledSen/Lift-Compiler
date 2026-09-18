# Official Lift Language Documentation

> **Simple to learn. Powerful when you need it.**

---
**Compiler Version:** `v0.1.0`
---

## 1. Setup & Environment

### 1.1 Verifying Installation

Verify that the Lift compiler is properly installed on your system:

```bash
lift --version
```

### 1.2 Creating a Project

Initialize a new workspace in the terminal:

```bash
lift new "project-name"
```

### 1.3 Project Architecture

Newly generated projects follow a standardized directory layout:

```text
project-name/
├── libraries.liftl
├── settings.lifts
└── main.lift
```

### 1.4 Managing Dependencies (`libraries.liftl`)

Declared external libraries and version constraints are listed in `libraries.liftl`:

```liftl
use math[1.0.0];
use algorithm[1.0.0];
```

### 1.5 Compiler Settings (`settings.lifts`)

Configure compilation flags and performance optimizations in `settings.lifts`:

```lifts
warnings = false;
optimization = true;
```

### 1.6 Application Entry Point (`main.lift`)

The primary source file compiled during execution:

```lift
outputln("Hello, World!");
```

---

## 2. Beginner Syntax

### 2.1 Comments

Lift uses triple hyphens (`---`) for single-line and multi-line comments:

```lift
--- this is a comment ---

---
this is also a comment
---
```

### 2.2 Standard Output

Lift provides two standard print statements: `output()` for inline output and `outputln()` for printing with an automatic line break.

```lift
output("Hello, World!\n");
outputln("Hello, World!");

outputln("5 + 3 = ", 5 + 3);
```

### 2.3 Implicit Variables

Variables with dynamic type inference are declared using the `var` keyword:

```lift
var x = 5;
var name = "John";
```

### 2.4 The `repeat` Loop

For simple fixed iterations, use the `repeat` keyword:

```lift
repeat 5 {
    outputln("Hello, World!");
}
```

### 2.5 Basic Conditionals

Evaluate conditions using standard single-branch `if` statements:

```lift
var x = 6;
if x > 5 {
    outputln("x is greater than 5");
}
```

### 2.6 Standard Input

Capture input from the console using `input()`:

```lift
var name = "";
input(name);
outputln("Hello, ", name);
```

### 2.7 Operators

* **Arithmetic:** `+`, `-`, `*`, `/`, `//` (integer division)
* **Relational:** `==`, `!=`, `>`, `<`, `>=`, `<=`

---

## 3. Intermediate Syntax

### 3.1 Explicit Type Annotations

Explicit type binding is defined using generic syntax `var<type>`:

```lift
var<int> x = -5;
var<uint> count = 5;
var<float> pi = 3.14;
var<char> letter = 'B';
var<string> text = "Hello";
var<bool> active = false;
```

### 3.2 Functions

Functions require explicit parameter type annotations and a return type:

```lift
fn<int> add(var<int> x, var<int> y) {
    return x + y;
}

fn<void> main() {
    outputln(add(5, 3));
    outputln(add(13, 15));
    outputln(add(420, 69));
}
```

### 3.3 Function Signatures

Lift supports seven primary return type signatures:

```lift
fn<int> getInteger() {}
fn<uint> getUnsigned() {}
fn<float> getFloat() {}
fn<char> getChar() {}
fn<string> getString() {}
fn<bool> getStatus() {}
fn<void> executeTask() {}
```

### 3.4 Advanced Loops

Lift provides three fundamental iteration structures:

* **`for` loop:** C-style counter loop without parentheses around the conditions.
* **`while` loop:** Executes repeatedly while the condition evaluates to `true`.
* **`until` loop:** Executes repeatedly until the condition evaluates to `true` (executes while `false`).

```lift
--- Standard For loop ---
for var<int> i = 0; i < 10; i++ {
    outputln("Index: ", i);
}

--- Standard While loop ---
var<int> count = 0;
while count < 5 {
    outputln("Count: ", count);
    count++;
}

--- Standard Until loop ---
var<bool> ready = false;
until ready {
    outputln("Waiting for initialization...");
    ready = true;
}
```

### 3.5 Control Flow & Advanced Logic

Branching logic can be extended with `else if` and `else` clauses.

```lift
var<int> score = 85;

if score >= 90 {
    outputln("Grade: A");
} else if score >= 80 {
    outputln("Grade: B");
} else {
    outputln("Grade: C or below");
}
```

#### Logical Operators

| Operator | Keyword / Logic | Description |
|---|---|---|
| `&&` | AND | Returns `true` if both operands are `true` |
| `\|\|` | OR | Returns `true` if at least one operand is `true` |
| `^^` | XOR | Returns `true` if exactly one operand is `true` |
| `!` | NOT | Inverts the boolean value |
| `!&` | NAND | Returns `false` only if both operands are `true` |
| `!\|` | NOR | Returns `true` only if both operands are `false` |
| `!^` | XNOR | Returns `true` if both operands are equal |

```lift
var<bool> a = true;
var<bool> b = false;

if a && !b {
    outputln("Condition met");
}

if a ^^ b {
    outputln("Exactly one condition is true");
}
```

### 3.6 Lists

Lists store ordered sequences of a single data type. Elements are zero-indexed (`0` to `length - 1`).

```lift
--- List declaration ---
list<int> nums = [1, 2, 3];

--- Accessing and modifying elements via index ---
outputln("First element: ", nums[0]); --- Output: 1 ---
nums[1] = 20;                        --- Updates second element to 20 ---

--- Common List Methods ---
nums.append(4);                 --- Appends element to the end -> [1, 20, 3, 4] ---
nums.insert(0, 99);             --- Inserts element at specified index ---
nums.remove(2);                 --- Removes element at specified index ---
var<int> len = nums.length();   --- Returns list size ---
nums.clear();                   --- Removes all elements from list ---
```

### 3.7 Strings

Strings represent sequential character arrays and support indexing alongside built-in manipulation methods.

```lift
var<string> greeting = "Hello, Lift!";

--- String indexing ---
var<char> firstChar = greeting[0]; --- Returns 'H' ---

--- Common String Methods ---
var<int> len = greeting.length();                 --- Character count ---
var<string> sub = greeting.substring(0, 5);       --- Returns "Hello" ---
var<string> upper = greeting.toUpper();           --- Converts to uppercase ---
var<string> lower = greeting.toLower();           --- Converts to lowercase ---
var<bool> contains = greeting.contains("Lift");   --- Returns true ---
var<list<string>> parts = greeting.split(", ");   --- Returns ["Hello", "Lift!"] ---
```

---

## 4. Advanced Features

### 4.1 Custom Types / Structs

Structs allow user-defined grouping of data and behavior, partitioned into `public:` and `private:` access specifiers:

```lift
struct Player {
public:
    var<string> name;
    var<int> health = 100;

    fn<void> takeDamage(var<int> amount) {
        this.health -= amount;
        if this.health < 0 {
            this.health = 0;
        }
    }

    fn<int> getHealth() {
        return this.health;
    }

private:
    var<int> id;
}

--- Usage ---
var<Player> p1;
p1.name = "Hero";
p1.takeDamage(25);
outputln(p1.name, " HP: ", p1.getHealth());
```

### 4.2 Enums

Enums represent custom discrete sets of named constants. Lift supports standard un-scoped enums as well as scoped `enum class` declarations. Accessing members uses dot syntax (`.`) in both formats:

```lift
--- Standard C++-style enum ---
enum State {
    IDLE,
    RUNNING,
    PAUSED
}

--- Scoped enum class ---
enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
}

--- Usage ---
var<State> currentState = State.IDLE;
var<Direction> dir = Direction.NORTH;
```

### 4.3 Generics

Generics allow functions and data structures to operate on parametrized types:

```lift
--- Generic Struct ---
struct Container<T> {
public:
    var<T> item;

    fn<T> getItem() {
        return this.item;
    }
}

--- Generic Function ---
fn<T> identity<T>(var<T> val) {
    return val;
}

--- Usage ---
var<Container<int>> box;
box.item = 42;
outputln(identity<string>("Generic test"));
```

### 4.4 Advanced Collections

In addition to standard lists, Lift offers built-in key-value maps and unique sets:

```lift
--- Hash Map / Dictionary ---
map<string, int> scores;
scores.set("Alice", 100);
scores.set("Bob", 85);

if scores.has("Alice") {
    outputln("Alice's score: ", scores.get("Alice"));
}

--- Unique Set ---
set<int> uniqueIds;
uniqueIds.add(10);
uniqueIds.add(10); --- Ignored as duplicate ---
outputln("Unique count: ", uniqueIds.length());
```

### 4.5 Function Overloading

Functions with the same name can be overloaded provided their parameter signatures differ:

```lift
fn<int> calculate(var<int> a, var<int> b) {
    return a + b;
}

fn<float> calculate(var<float> a, var<float> b) {
    return a + b;
}

fn<int> calculate(var<int> a, var<int> b, var<int> c) {
    return a + b + c;
}
```

### 4.6 Function References / Callbacks

Functions can be passed as arguments or assigned to typed callback variables:

```lift
fn<int> multiplyByTwo(var<int> n) {
    return n * 2;
}

fn<void> processNumber(var<int> val, fn<int(int)> callback) {
    var<int> result = callback(val);
    outputln("Processed result: ", result);
}

fn<void> main() {
    processNumber(5, multiplyByTwo);
}
```

### 4.7 Modules & Namespaces

Namespaces encapsulate declarations to prevent symbol collisions across large projects. Accessing members uses dot syntax (`.`):

```lift
namespace Graphics {
    var<int> SCREEN_WIDTH = 1920;
    var<int> SCREEN_HEIGHT = 1080;

    fn<void> render() {
        outputln("Rendering frame...");
    }
}

--- Usage ---
Graphics.render();
outputln("Width: ", Graphics.SCREEN_WIDTH);
```

### 4.8 Error Handling

Lift uses structured `try / catch / throw` constructs for exceptional flow control:

```lift
fn<float> divide(var<float> a, var<float> b) {
    if b == 0.0 {
        throw "DivisionByZeroError: Cannot divide by zero";
    }
    return a / b;
}

fn<void> main() {
    try {
        var<float> res = divide(10.0, 0.0);
    } catch (var<string> err) {
        outputln("An exception was caught: ", err);
    }
}
```

### 4.9 Compile-Time Features

Lift supports compile-time code evaluation and compile-time constant expressions via `const` and `comptime`:

```lift
--- Compile-time constant ---
const var<int> MAX_BUFFER_SIZE = 1024;

--- Code evaluated during compilation ---
comptime {
    outputln("Building Lift binaries for platform target...");
}
```

---

## 5. Low-Level Programming

### 5.1 Memory Architecture

Lift offers direct control over system memory for performance-critical systems. Memory addresses are represented as typed pointer locations or raw address offsets.

### 5.2 References

References create alias bindings to existing variable locations using the `&` modifier in type declarations:

```lift
fn<void> increment(var<int>& num) {
    num += 1;
}

fn<void> main() {
    var<int> val = 10;
    increment(val);
    outputln("Value after increment: ", val); --- Output: 11 ---
}
```

### 5.3 Pointers

Pointers store physical memory addresses using the `ptr<type>` notation.
* Initialize a null pointer using `NULL`.
* Use `ptr<void>` as a generic pointer type that can hold an address of any data type.

```lift
var<int> target = 42;
ptr<int> p = &target; --- Address-of operator ---

outputln("Value via pointer: ", *p); --- Dereference operator ---

*p = 100; --- Direct memory modification ---
outputln("Updated target: ", target); --- Output: 100 ---

--- Null pointer initialization ---
ptr<int> iptr = NULL;

--- Generic pointer to any type ---
ptr<void> genericPtr = p;
```

### 5.4 Pointer Arithmetic

Pointer arithmetic moves memory references by element size offsets:

```lift
ptr<int> buffer = getMemoryBuffer();

--- Move pointer forward by 2 element width offsets ---
ptr<int> offsetPtr = buffer + 2;

--- Calculate offset difference ---
var<int> count = offsetPtr - buffer;
```

### 5.5 Manual Memory Allocation

Heap memory can be explicitly reserved and released using `allocate<T>()` and `deallocate()`:

```lift
--- Allocate block for 5 integer elements on heap ---
ptr<int> heapArray = allocate<int>(5);

heapArray[0] = 10;
heapArray[1] = 20;

--- Always free manual dynamic allocations ---
deallocate(heapArray);
```

### 5.6 Raw Memory Access

Generic raw byte operations allow direct byte manipulation via `ptr<void>`:

```lift
ptr<void> rawChunk = allocateRaw(64); --- Reserve 64 raw bytes ---

--- Copy memory bytes from source to target ---
memcopy(destRaw, rawChunk, 64);

--- Fill memory region with zero bytes ---
memset(rawChunk, 0, 64);

freeRaw(rawChunk);
```

### 5.7 Stack and Heap

* **Stack Memory:** Fast, automatically managed, fixed-size frames for local variables and function scope lifetime.
* **Heap Memory:** Dynamically allocated memory that persists until explicitly released or cleared by manual/garbage-managed scope lifecycle.

```lift
fn<void> memoryDemo() {
    var<int> stackVar = 5; --- Stack allocation ---
    ptr<int> heapVar = allocate<int>(1); --- Heap allocation ---
    *heapVar = 50;

    deallocate(heapVar);
}
```

### 5.8 Bitwise Operations

Lift supports standard low-level bit manipulation operators:

| Operator | Operation | Description |
|---|---|---|
| `&` | Bitwise AND | Compares corresponding bits |
| `\|` | Bitwise OR | Sets bit if either bit is 1 |
| `^` | Bitwise XOR | Sets bit if exactly one bit is 1 |
| `~` | Bitwise NOT | Inverts all bits |
| `<<` | Left Shift | Shifts bits left (multiplies by $2^n$) |
| `>>` | Right Shift | Shifts bits right (divides by $2^n$) |

```lift
var<uint> flags = 0b00001100;
var<uint> mask  = 0b00000100;

var<uint> active = flags & mask;         --- Bitwise AND ---
var<uint> combined = flags | 0b00010000; --- Bitwise OR ---
var<uint> shifted = flags << 2;          --- Bitwise Left Shift ---
```

### 5.9 Inline Assembly

Low-level target platform instructions can be written directly using `asm` blocks:

```lift
fn<uint> readCycleCount() {
    var<uint> cycles = 0;
    asm {
        rdtsc
        mov cycles, eax
    }
    return cycles;
}
```

### 5.10 C / Native Interoperability

Foreign native functions compiled from C/C++ libraries can be declared using `extern "C"`:

```lift
--- Bind external C runtime functions ---
extern "C" {
    fn<int> puts(ptr<char> str);
    fn<int> abs(var<int> value);
}

fn<void> main() {
    abs(-15);
    puts("Calling C library directly from Lift!");
}
```
