# Variables, Datatypes and I/O


> [!quote] 1.1
> 
> ## Variables & Memory

A <u><strong style="color:#dab1da">variable</strong></u> is a named object that stores a value in memory.

**Memory organization:**

- <u><strong style="color:#dab1da">Bit</strong></u>: Smallest unit (0 or 1)
- <u><strong style="color:#dab1da">Byte</strong></u>: 8 bits with unique address
- n-bit object holds **2^n** unique values

```cpp
int x;      // Define variable (reserves memory)
```

At runtime, memory is <u><strong style="color:#dab1da">allocated</strong></u> and the variable is <u><strong style="color:#dab1da">created</strong></u>.

> [!quote] 1.2
> 
> ## Initialization & Assignment

<u><strong style="color:#dab1da">Initialization</strong></u>: Providing initial value at point of definition <u><strong style="color:#dab1da">Assignment</strong></u>: Changing value after definition

```cpp
int x { 5 };    // Direct-list initialization (preferred)
int y {};       // Value initialization (zero)
int z;          // Default initialization (dangerous - uninitialized!)

int a { 5 };
a = 10;         // Assignment (overwrites previous value)
```

**Key forms:**

- `int x { 5 };` - Direct-list initialization ✓
- `int x {};` - Value initialization (0) ✓
- `int x = 5;` - Copy initialization (less preferred)
- `int x;` - Uninitialized (undefined behavior if used) ✗

> [!hint] 1.3
> 
> ## Naming & Best Practices

**Identifier rules:**

- Start with letter or underscore
- Letters, numbers, underscore only
- Can't be keywords

**Conventions:**

```cpp
int playerScore;     // camelCase (preferred)
int player_score;    // snake_case (also common)
```

**Best practices:**

- ✓ Always initialize variables
- ✓ Descriptive names: `playerScore` not `x`
- ✓ One variable per line
- ✗ Avoid starting with underscore
- ✗ Avoid abbreviations

> [!quote] 1.4
> 
> ## std::cout Basics

```cpp
#include <iostream>

std::cout << "Hello";           // Output text
std::cout << 42;                // Output number
std::cout << x;                 // Output variable
std::cout << "Sum: " << x + y;  // Chain multiple outputs
```

**Newlines:**

```cpp
std::cout << "Line 1\n";        // Preferred: \n
std::cout << "Line 2" << '\n';  // Also preferred
std::cout << "Line 3" << std::endl;  // Slower (flushes buffer)
```

**Rule:** Prefer `\n` over `std::endl`

> [!quote] 1.5
> 
> ## std::cin & Input

```cpp
int x{};
std::cin >> x;           // Extract to variable

int a{}, b{};
std::cin >> a >> b;      // Multiple inputs (space-separated)
```

**Buffer behavior:**

- `>>` discards leading whitespace, stops at next whitespace
- Unextracted input remains in buffer for next extraction
- Enter key adds `\n` to buffer

**Mixing input types:**

```cpp
int choice{};
std::cin >> choice;      // Leaves \n in buffer

std::string name{};
std::getline(std::cin >> std::ws, name);  // std::ws removes leading whitespace
```

**Rule:** Always use `std::cin >> std::ws` before `std::getline()`

> [!quote] 1.6
> 
> ## Integer Types

|Type|Size|Range|
|---|---|---|
|`int`|4 bytes|±2 billion|
|`short`|2 bytes|±32,767|
|`long long`|8 bytes|±9 quintillion|
|`std::int32_t`|4 bytes|-2,147,483,648 to 2,147,483,647|

```cpp
int x { 5 };
std::int32_t y { 100 };  // Guaranteed size
```

**Integer division:** `8 / 5 = 1` (drops fractional part)

**Overflow:** Undefined behavior

```cpp
int max { 2'147'483'647 };
max = max + 1;  // UB: unpredictable result
```

**Unsigned:** Only use for bit manipulation, avoid for regular math

> [!quote] 1.7
> 
> ## Floating-Point Types

|Type|Size|Precision|
|---|---|---|
|`float`|4 bytes|~7 digits|
|`double`|8 bytes|~16 digits|

```cpp
double d { 3.14159 };
float f { 5.0f };        // f suffix for float
double sci { 5.97e24 };  // Scientific notation
```

**Rounding errors:**

```cpp
double x { 0.1 };  // Actually 0.10000000000000001
// 0.1 + 0.1 + ... (10 times) ≠ 1.0 exactly
```

**Rules:**

- ✓ Prefer `double` over `float`
- ✗ Never use `==` with floating-point
- ✗ Avoid for currency (use integer cents)
- ✓ Always include decimal: `1.0 / 2.0` not `1 / 2`

> [!quote] 1.8
> 
> ## Boolean Type

```cpp
bool b1 { true };
bool b2 { false };
bool b3 { !true };   // Logical NOT: false

// Printing
std::cout << b1;                 // Prints 1
std::cout << std::boolalpha << b1;  // Prints "true"

// Input
std::cin >> std::boolalpha >> b1;   // Accept "true"/"false"
```

**Conversion:** `0` → `false`, non-zero → `true`

> [!quote] 1.9
> 
> ## Character Type

```cpp
char ch { 'a' };     // Single quotes for char
char tab { '\t' };
char newline { '\n' };

// I/O
std::cin >> ch;                    // First character only
std::cout << ch;                   // Prints as character
std::cout << static_cast<int>(ch); // Prints ASCII value (97)
```

**Common escapes:** `\n` `\t` `\'` `\"` `\\`

**Warning:** Use `\n` (backslash) not `/n` (forward slash)

> [!quote] 1.10
> 
> ## Type Conversion

**Implicit (automatic):**

```cpp
double d { 5 };      // int → double (safe)
int x = 5.5;         // double → int (loses 0.5, warning)
```

**Explicit (static_cast):**

```cpp
int x { static_cast<int>(5.5) };        // x = 5
char ch { 'A' };
std::cout << static_cast<int>(ch);      // Prints 65
```

**Syntax:** `static_cast<target_type>(expression)`

**Narrowing conversions:**

- `double` → `int`: Drops fractional part
- Larger → Smaller: May lose data
- Always use `static_cast` when intentional

> [!quote] 1.11
> 
> ## std::string Basics

```cpp
#include <string>

std::string name { "Alex" };
name = "John";                // Can reassign

std::cout << name;            // Output string

// Input
std::string s{};
std::getline(std::cin >> std::ws, s);  // Read full line (with spaces)
```

**Length:**

```cpp
name.length();                         // Returns unsigned
int len { static_cast<int>(name.length()) };  // Safe conversion
// C++20: std::ssize(name)
```

**Warning:** `std::cin >> s` stops at first whitespace. Use `std::getline()` for full input.

**Performance:** Don't pass `std::string` by value (makes expensive copy)

> [!quote] 1.12
> 
> ## Constants

#### <u>Runtime Constants</u>

Value cannot be changed after initialization, identified using `const`

```cpp
const double gravity { 9.8 };
gravity = 10.0;  // Error: cannot modify const

int x { 5 };
const int y { x };  // OK: initialize with non-const
```

**Rules:**
- Must be initialized
- Can't be reassigned
- Evaluated at runtime
- Helps prevent bugs

#### Constants Expressions

Constants initialized during compile time, usable only in other constant expressions, identified by `constexpr`

```cpp
constexpr double gravity { 9.8 };
constexpr int sum { 4 + 5 };
constexpr int x { sum };  // OK: sum is constexpr

int age{};
std::cin >> age;
constexpr int myAge { age };  // Error: age not known at compile-time
```

**Rules:**
- ✓ Literals: `5`, `3.14`, `'c'`
- ✓ constexpr variables
- ✓ const integral variables with constant initializer
- ✗ No non-const variables
- ✗ No const non-integral variables
- ✗ No runtime function returns

|Feature|const|constexpr|
|---|---|---|
|**Value known**|Runtime or compile-time|Compile-time only|
|**Initializer**|Any expression|Constant expression only|
|**Usage**|Runtime constant|Compile-time constant|
|**Type part?**|Yes|No (adds implicit const)|
|**All types?**|Yes|Most (not `std::string`)|

> [!hint] 1.13
> 
> ## Type Selection Summary

|Need|Use|
|---|---|
|Whole numbers (size flexible)|`int`|
|Whole numbers (specific size)|`std::int32_t`, `std::int64_t`|
|Decimals|`double`|
|True/false|`bool`|
|Single character|`char`|
|Text (mutable)|`std::string`|
|Compile-time constant|`constexpr`|
|Runtime constant|`const`|

**Key rules:**

- Always initialize variables
- Prefer `int` and `double` as defaults
- Use `\n` not `std::endl`
- Never `==` with floating-point
- Use `static_cast` for explicit conversions
- Don't pass `std::string` by value
- Use `constexpr` when possible, `const` otherwise
- Avoid unsigned except for bit operations

**Dangerous:**

- Uninitialized variables → UB
- Integer overflow → UB
- Narrowing conversions → Data loss
- `std::cin >>` with `std::string` → Stops at whitespace