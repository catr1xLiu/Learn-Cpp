
# 7 - References, Pointers and Types

---

> [!quote] Concept
> 
> ## LValues and RValues

An <u><strong style="color:#dab1da">lvalue</strong></u> evaluates to an identifiable object that persists beyond the expression.

An <u><strong style="color:#dab1da">rvalue</strong></u> evaluates to a temporary value without persistent identity.

```cpp
int x = 5;    // x is lvalue
x = 10;       // Valid: lvalue on left
5 = x;        // Error: rvalue cannot be on left
```

**Lvalues implicitly convert to rvalues when needed by evaluating to their value.**

> [!quote] Concept
> 
> ## References

An <u><strong style="color:#dab1da">lvalue reference</strong></u> is an alias for an existing object, declared using `&`.

```cpp
int x { 5 };
int& ref { x };   // ref is now an alias for x
ref = 10;         // Changes x to 10
```

An <u><strong style="color:#dab1da">lvalue reference to const</strong></u> treats the referenced object as a **read-only** variable:

```cpp
int x { 5 };
const int& cref { x };  // Constant reference can point to non-constant variables
std::cout << cref << std::endl; // Can read value, but not write
```

**References:**
- Must be initialized
- Cannot be reseated
- No null references
- Cleaner syntax
- Safer

> [!quote] Concept
> 
> ## Pointers

A <u><strong style="color:#dab1da">pointer</strong></u> is an object that holds a memory address.

```cpp
int x { 5 };
int* ptr { &x };      // & gets address
std::cout << ptr;     // the value of ptr (or address of x)
std::cout << *ptr;    // dereferences ptr (prints the value of x)
(*ptr) ++;            // Change the value of x
ptr++;                // Change the address (dangerous)
```

**Pointers:**
- Can be uninitialized (dangerous)
- Can be reassigned
- Can be null
- Explicit dereferencing needed
- More flexible
### Null Pointers
```cpp
int* ptr {};          // Preferred: value initialization
int* ptr { nullptr }; // Explicit null
// Never dereference null pointers!
```
### Pointer Types
```cpp
const int* ptr1;      // Pointer to constant
int* const ptr2;      // Const pointer (can't change address)  
const int* const ptr3; // Both const
```


> [!hint] Best Practices
> 
> ## Passing Parameters

### By Value

```cpp
int func(int x)
{
	return 2 * x + 1;
}
```
**When to use**: When we only need to **read** the value of a **fundamental datatype**.

### By Constant Reference

```cpp
int countWords(const std::string& str)
{
	int result { 0 };
	for (char c:s) {
		if (c==' ') result++;
	}
	return result;
}
```
**When to use**: When we only need to **read** the value of a **class type**.
This is useful because we want to save the memory needed to copy the object
### By Reference

```cpp
void modify(int& x1, int& x2, int& x3);
```
**When to use**: When we only need to **modify** the value of parameters. 
This is useful because we can't return multiple values.
### By Pointer

```cpp
void modify(int* ptr) {
    if (ptr) {           // Always null-check!
        *ptr = 10;
    }
}

int x { 5 };
modify(&x);              // x becomes 10
modify(nullptr);         // Safe: null check prevents crash
```

**When to use**: Only for **optional parameters** where nullptr is a valid input.
Not recommended.

### Modern Preference: std::string_view

In modern c++ practices, it is preferred to use `std::string_view` over `const std::string&` for string parameters.


> [!hint] Best Practices
> 
> ## Returning Values

### Return by Address

```cpp
int* find(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) 
            return &arr[i];
    }
    return nullptr;  // "Not found"
}
```

**Choose reference** unless you need to return nullptr


### Return by Reference

```cpp
// SAFE: Static variable
const std::string& getName() {
    static std::string s_name { "Name" };
    return s_name;
}

// DANGEROUS: Local variable
const int& bad() {
    int local { 5 };
    return local;  // Dangling reference!
}
```

> [!example] Example
> 
> ## In & Out Parameters

```cpp
// Input parameters (by const ref for class types)
void process(const std::vector<int>& input);

// Output parameters (by reference)
bool getData(int& result) {
    if (/* success */) {
        result = 42;
        return true;
    }
    return false;
}

// In-out parameters (by reference)
void transform(std::string& data) {
    // Modify data in place
}
```

Best Practice 
 - Use return values for single outputs
 - Use out parameters for multiple outputs
 - Consider `std::tuple` or struct for multiple returns
 - Document parameter intent clearly

> [!hint] Best Practice
> 
> ## Type Deduction with auto

```cpp
int x { 5 };
int& ref { x };
const int& cref { x };

auto a = x;      // int (copies value)
auto b = ref;    // int (drops reference)
auto c = cref;   // int (drops const and reference)

auto& d = x;     // int& (keeps reference)
const auto& e = x; // const int& (adds const)
auto* f = &x;    // int* (pointer)
```

**Key**: `auto` drops references and cv-qualifiers unless explicitly specified


Replace nullable pointers with type-safe optional:

```cpp
#include <optional>

std::optional<int> divide(int a, int b) {
    if (b == 0) 
        return std::nullopt;  // or {}
    return a / b;
}

// Usage
if (auto result = divide(10, 2)) {
    std::cout << *result;     // or result.value()
}
```

> [!success]- Advantages (Click to expand)
> 
> - No dynamic allocation
> - Clear "no value" semantics
> - Stack-based efficiency
> - Works with value types
> - No null pointer risks

> [!hint] Best Practice
> 
> ## Safety Checklist

1. **Initialize all pointers** - No wild pointers
2. **Use nullptr, not NULL or 0** - Type safety
3. **Null-check before dereferencing** - Prevent crashes
4. **Prefer references over pointers** - Safer syntax
5. **Never return local addresses** - Avoid dangling
6. **Use smart pointers for dynamic memory** - RAII
7. **Consider std::optional** - Modern null alternative