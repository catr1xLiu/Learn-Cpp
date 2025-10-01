
> [!quote] 2.1
> # Arithmetic Operators

#### Unary Operators

```cpp
+x   // Returns value of x
-x   // Negation of x
```

#### Binary Operators

```cpp
x + y   // Addition
x - y   // Subtraction
x * y   // Multiplication
x / y   // Division
x % y   // Remainder (integers only)
```

#### Division Types

**Integer division** drops fractions: `7 / 4 = 1` **Floating-point division** keeps fractions: `7.0 / 4 = 1.75`

Force floating-point division:

```cpp
static_cast<double>(x) / y
```

> [!warning] Warning
> #### Division by Zero

**Division by zero causes undefined behavior (crash)**

```cpp
int x {1/0};
```
#### Arithmetic Assignment

```cpp
x += 4;   // x = x + 4
x -= 3;   // x = x - 3
x *= 2;   // x = x * 2
x /= 5;   // x = x / 5
x %= 3;   // x = x % 3
```

> [!quote] 2.2
> # Remainder and Exponentiation

---
#### Remainder (%)

Result takes sign of first operand:

```cpp
7 % 4    // = 3
-6 % 4   // = -2
6 % -4   // = 2
```

Compare remainder against 0 to handle negative numbers:
```cpp
bool isOdd(int x) { return (x % 2) != 0; }
```

#### Exponentiation

```cpp
#include <cmath>
std::pow(3.0, 4.0);  // 3^4 = 81 (floating-point only)
```

> [!fact] 2.3
> # Increment/Decrement and Side Effects

---
```cpp
++x   // Pre-increment: increment then return
x++   // Post-increment: copy, increment, return copy
--x   // Pre-decrement
x--   // Post-decrement
```

#### Side Effects

Operators that modify their operands: `=, +=, -=, ++, --`

> [!warning] Warning
> #### Side Effects
> **Never use a variable with side effects more than once per statement.**

```cpp
int y = x + ++x;  // UNDEFINED BEHAVIOR
```


> [!quote] 2.4
> # Relational Operators

---
```cpp
x > y    x < y    x >= y    x <= y
x == y   x != y
```

> [!hint] Best Practice
> **Don't compare booleans unnecessarily:**

 ```cpp
if (b1) ...        // Not: if (b1 == true)
if (!b1) ...       // Not: if (b1 == false)
```

#### Floating Point Comparison

> [!failure] 
> **Never use == or != with calculated floating-point values**

```cpp
double d1 = 100.0 - 99.99;  // Rounding errors!
double d2 = 10.0 - 9.99;
d1 == d2  // May be false despite both "should" equal 0.01
```

> [!hint] Best Practice
> **Safe comparisons:**

- Literal with variable initialized to same literal
- Use approximate equality function for calculations:

```cpp
bool approximatelyEqual(double a, double b, 
	double absEps = 1e-12, double relEps = 1e-8)
{
    if (std::abs(a - b) <= absEps) return true;
    return std::abs(a - b) <= std::max(std::abs(a), std::abs(b)) * relEps;
}
```


> [!quote] 2.5
> 
> # Logical Operators

---
```cpp
!x        // NOT
x && y    // AND (true if both true)
x || y    // OR (true if either true)
```

#### Short-Circuit Evaluation

**AND**: If left is false, right not evaluated **OR**: If left is true, right not evaluated

```cpp
if (ptr && ptr->value)  // Safe: ptr checked first
```

> [!warning] Warning
> **Avoid side effects in logical expressions:**

```cpp
if (x == 1 && ++y == 2)  // BAD: y may not increment
```

#### XOR

Use `!=` for bools:

```cpp
if (a != b) ...  // XOR
```

> [!quote] 3.6
> 
> # Operator Precedence and Associativity

---
<u><strong style="color:#dab1da">Precedence</strong></u> determines grouping (higher precedence groups first) <u><strong style="color:#dab1da">Associativity</strong></u> determines direction when operators have same precedence

```cpp
4 + 2 * 3    // = 4 + (2 * 3) = 10 (multiplication has higher precedence)
7 - 4 - 1    // = (7 - 4) - 1 = 2 (subtraction is left-to-right)
```

#### Key Precedence Levels (High to Low)

1. `++, --, !, ~` (unary)
2. `*, /, %`
3. `+, -`
4. `<, <=, >, >=`
5. `==, !=`
6. `&&`
7. `||`
8. `=, +=, -=, *=, /=, %=`

#### Effect of Brackets

Brackets force evaluation order:

```cpp
(4 + 2) * 3     // = 18 (addition first)
!(x > y)        // Negate the comparison result
(a || b) && c   // OR before AND
```

#### Logical Operator Associativity

Both AND and OR are **left-to-right**:

```cpp
a && b && c  // = (a && b) && c
a || b || c  // = (a || b) || c
```

> [!hint] Best Practices
> **Using Parenthesize to organize expressions**

- **Parenthesize** everything except `+, -, *, /`
- **Always parenthesize** mixed AND/OR expressions

```cpp
(a && b) || (c && d)  // Clear intent
```

> [!warning] Warning
>  **C++ doesn't specify the order operands are evaluated**
 
```cpp
foo(getValue(), getValue())  // Order undefined!
```

