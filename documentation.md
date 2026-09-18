# Official Lift Language Documentation

> **Simple to learn. Powerful when you need it.**

## **Compiler Version:** `v0.1.0`

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

## 2. Beginner Syntax

### 2.1 Comments

Lift uses triple hyphens (`---`) to wrap both single-line and multi-line comments:

```lift
--- This is a single-line comment ---

---
This is a multi-line comment.
It can span across multiple lines.
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
| --- | --- | --- |
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
--- Declaration ---
var<list<int>> nums = [1, 2, 3];

--- Accessing and modifying elements ---
outputln("First element: ", nums[0]); --- Output: 1 ---
nums[1] = 20;                        --- Updates second element to 20 ---

--- Common List Methods ---
nums.append(4);                 --- Appends element to the end -> [1, 20, 3, 4] ---
nums.insert(0, 99);             --- Inserts element at specific index ---
nums.remove(2);                 --- Removes element at specific index ---
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
