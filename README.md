# Lift

### Simple to learn. Powerful when you need it.

Lift is a general-purpose compiled programming language designed to be easy to understand by beginners while also offering control to advanced users.

> **Current version:** `v0.1.0`

---

## About

Lift aims to provide a programming language that can be approachable for someone learning programming while still giving experienced programmers access to lower-level features when they need them.

The project is currently under active development.

## Features

Lift is being designed with:

* Simple, beginner-friendly syntax
* Static variable types for additional control
* Functions
* `if`, `else if`, and `else` conditions
* `repeat`, `for`, `while`, and `until` loops
* Lists
* String manipulation
* Logical operators
* Built-in libraries
* Configurable compiler settings
* Low-level programming capabilities

More features will be added as development continues.

---

## Example

A simple Lift program:

```lift
outputln("Hello, World!");
```

Variables can be created without explicitly specifying a type:

```lift
var name = "Sen";
var age = 17;

outputln("Hello, ", name);
outputln("You are ", age, " years old.");
```

Types can also be specified when more control is desired:

```lift
var<int> x = 10;
var<string> message = "Hello!";
```

---

## Getting Started

### Check the compiler

```bash
./lift --version
```

### Create a project

```bash
./lift new "project-name"
```

This creates a new Lift project containing:

```text
project-name/
├── libraries.liftl
├── settings.lifts
└── main.lift
```

### Run a project

Inside the project directory:

```bash
./lift run
```

### Compile a project

```bash
./lift compile
```

---

## Documentation

The full Lift language documentation is available in [`documentation.md`](documentation.md).

It covers:

1. Lift setup
2. Beginner programming
3. Intermediate programming
4. Advanced programming
5. Low-level programming
6. Built-in libraries
7. Compiler settings
8. Creating libraries

---

## Project Status

Lift is currently in early development.

The current version is:

```text
v0.1.0
```

The compiler currently provides the initial project-management functionality, with the language compiler and additional features being developed progressively.

Expect the language and compiler to change significantly during development.

---

## Contributing

This project is currently being developed as an individual competition project.

**Pull requests are not being accepted at this time.**

Suggestions and discussion may be considered, but the project's implementation and direction are currently managed by the project author.

---

## License

Lift is released under the **MIT License**.

See [`LICENSE`](LICENSE) for the full license text.
