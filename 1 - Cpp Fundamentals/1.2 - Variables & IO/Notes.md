
# Variables and I/O

> [!quote] Concept
> 
> ## Data and Variables

#### <u>Data and Values</u>

<u><strong style="color:#dab1da">Data</strong></u> is any information a computer can process or store. A <u><strong style="color:#dab1da">value</strong></u> is a single piece of data (e.g., `5`, `'H'`, `"Hello"`).

**Value Types:**

- Numbers: `5`, `-6.7` (no quotes)
- Characters: `'H'`, `'$'` (single quotes, one symbol only)
- Text: `"Hello"`, `"H"` (double quotes, zero or more characters)

#### <u>Objects and Variables</u>

An <u><strong style="color:#dab1da">object</strong></u> is a region of storage (RAM or CPU register) that holds a value. A <u><strong style="color:#dab1da">variable</strong></u> is an object with a name (identifier).

```cpp
int x;  // x is a variable of type int
```

The <u><strong style="color:#dab1da">data type</strong></u> determines what kind of value the variable can store. The type must be known at compile-time and cannot change without recompiling.

> [!fact] Important
> 
> ## Initialization vs Assignment

#### <u>Initialization</u>

Providing an initial value when defining a variable:

```cpp
int width { 5 };     // direct-list-initialization (preferred)
int height {};       // value-initialization (initializes to 0)
int length = 7;      // copy-initialization
int depth ( 8 );     // direct-initialization
```

#### <u>Assignment</u>

Giving a value to an already-defined variable:

```cpp
int x;      // x is defined but uninitialized
x = 5;      // assignment
x = 7;      // reassignment (overwrites previous value)
```

> [!hint] Best Practice
> 
> ## Initialization Guidelines

**Always initialize variables upon creation** using direct-list-initialization or value-initialization:

```cpp
int x { 5 };    // Use when you have a specific initial value
int y {};       // Use when value is temporary and will be replaced
```

**Why list-initialization?**

- Works in most cases (most consistent)
- Disallows narrowing conversions
- Prevents data loss

```cpp
int w1 { 4.5 };  // Compile error: prevents losing .5
int w2 = 4.5;    // Compiles: silently drops .5 to become 4
```

> [!warning] Warning
> 
> ## Uninitialized Variables

Using uninitialized variables leads to <u><strong style="color:#dab1da">undefined behavior</strong></u> - the variable contains whatever garbage value was in that memory location. This can cause:

- Different results each run
- Crashes
- Inconsistent behavior
- Working code that suddenly breaks

**Always initialize your variables to avoid undefined behavior.**

> [!quote] Concept
> 
> ## Input/Output with iostream

#### <u>std::cout - Output</u>

Use `std::cout` with the insertion operator `<<` to print to console:

```cpp
#include <iostream>

int main()
{
    int x { 5 };
    std::cout << "x is: " << x << '\n';  // Prints: x is: 5
    return 0;
}
```

#### <u>std::cin - Input</u>

Use `std::cin` with the extraction operator `>>` to read keyboard input:

```cpp
int x {};
std::cin >> x;  // Waits for user input, then stores in x
```

> [!warning] Warning
> 
> ## Common Pitfalls
#### <u>Defining Multiple Variables</u>

Define one variable per line for clarity:

```cpp
// Avoid
int a, b = 5;     // Wrong! a is uninitialized
int x, y, z;      // Hard to read

// Prefer
int a { 5 };
int b { 5 };
```

#### <u>Unused Variables</u>

Use `[[maybe_unused]]` for intentionally unused variables:

```cpp
[[maybe_unused]] double pi { 3.14159 };
[[maybe_unused]] double gravity { 9.8 };

std::cout << pi << '\n';  // Only using pi, no warning about gravity
```

> [!hint] Best Practice
> 
> ## Naming Identifiers

**Rules:**
- Start with letter or underscore (not a digit)
- Use only letters, digits, underscores
- Cannot be a keyword
- Case-sensitive

**Conventions:**
- Variables/functions: start with lowercase (`myVariable`, `my_variable`)
- Types: start with uppercase (`MyClass`)
- Use descriptive names proportional to scope

```cpp
// Good
int customerCount {};
int minutesElapsed {};

// Avoid
int c {};           // Too vague
int data {};        // What kind of data?
int _count {};      // Don't start with underscore
```