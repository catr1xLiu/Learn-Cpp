
# C++ Basics: Program Structure & Comments

> [!quote] Concept
> 
> ## Statements & Functions
#### <u>Statement</u>
The smallest independent unit of computation that causes the program to perform an action. Most statements end with a semicolon (`;`).

```cpp
std::cout << "Hello world!";  // This is a statement
return 0;                      // This is also a statement
```

#### <u>Function</u>
A collection of statements executed sequentially.
```cpp
int function(int a)
{
	// do something
	return 0;
}
```



> [!fact] Important
> 
> ## The main() Function

Every C++ program **must** have a function named `main` (lowercase). When the program runs, statements inside `main` execute sequentially from top to bottom. The program terminates after the last statement in `main` executes.
```cpp
int main()
{
    std::cout << "Hello world!";
    return 0;
}
```


> [!example] Example
> 
> ## "Hello World"

```cpp
#include <iostream>

int main()
{
   std::cout << "Hello world!";
   return 0;
}
```

#### Line-by-Line Breakdown
- `#include <iostream>` - <u><strong style="color:#dab1da">Preprocessor directive</strong></u> that includes the iostream library for console I/O
- `int main()` - Declares the main function that returns an integer
- `{` and `}` - Define the <u><strong style="color:#dab1da">function body</strong></u>
- `std::cout << "Hello world!";` - Outputs text to console
- `return 0;` - Returns 0 to the OS indicating successful execution


> [!fact] Important
> 
> ## Syntax Errors
> 

A <u><strong style="color:#dab1da">syntax error</strong></u> occurs when code violates C++ grammar rules. The compiler will halt and point to the error location. Missing semicolons are the most common syntax errors.

**Key Insight**: If the compiler reports an error on a line but you can't find it, check the **previous line** - the error may actually be there.


> [!hint] Best Practice
> 
> ## Documenting Your Code
#### <u>Single-Line Comments</u>
Use `//` to comment from the symbol to the end of the line.

```cpp
// This entire line is a comment
std::cout << "Hello!";  // Comment after code
```

#### <u>Multi-Line Comments</u>
Use `/* */` to comment multiple lines.

```cpp
/* This comment spans
   multiple lines */
```

> [!warning] Warning
> 
> **Never nest multi-line comments** - they cannot be nested inside each other. However, wrapping single-line comments inside multi-line comments is acceptable.

Use comments for three purposes:

**1. What**: Describe what the library/program/function does (at the top)
```cpp
// This program calculates student's final grade based on test scores
```

**2. How**: Describe the approach or algorithm
```cpp
// To generate random items:
// 1) List all items of desired rarity
// 2) Calculate probability for each item
// 3) Choose random number and map to item
```

**3. Why**: Explain reasoning behind decisions at the statement level
```cpp
// Player drank blindness potion and cannot see
sight = 0;

// Multiply by 2 because items are bought in pairs
cost = quantity * 2 * storePrice;
```
