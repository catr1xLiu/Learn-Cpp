

## 1. Task Overview

Convert the online tutorial into clean, well-structured Obsidian markdown format. You have full creative freedom to:
- Reorganize unclear structures
- Create logical sections
- Improve clarity while keeping content concise for review purposes

## 2. Obsidian Formatting Requirements

### 2.1 Outline

The document should have an h1 title, and should be divided into a few sections, each beginning with a callout that has a number and a sub-title.

```markdown
# 7. References and Pointers

> [!abstract] 7.1
> # Value Catagories


```

### 2.2 Callouts

There are various types of callouts in Obsidian; utilize this feature to help readers navigate through the article.

**Callout Types:**
- `[!abstract]` - Introduction
- `[!quote]` - Concept
- `[!fact]` - Fact
- `[!info]` - Important
- `[!warning]` Warning
- `[!hint]` - Best Practice
- `[!example]` - Examples

```markdown
> [!abstract] Introduction
> #### Subtitle
> Introductory parts in the note, such as the content describing the importance of a chapter or its real-life applications. (optional)

> [!quote] Concept
> #### Appropriate Subtitle
> Introduce new terminology or key concepts.

> [!fact] Fact
> #### Appropriate Subtitle
> State an important fact.

> [!info] Important
> #### Appropriate Subtitle
> An important fact or a useful computational trick is something that’s worth knowing.

> [!hint] Best Practice
> #### Appropriate Subtitle
> Post a best practice or regulate the code style. 

> [!example] Example
> #### Appropriate Subtitle
> Provide an example.
```

### 2.3 Examples with Collapsible Solutions

For examples that need solutions, solutions are hidden by default:

```markdown
> [!example] Example
> ## Finding Rank

Find the rank of the given matrix.

> [!success]- Solution (Click to expand)
> Step 1: Convert to REF
> Step 2: Count leading entries
> Answer: $\text{rank}(A) = 2$
```

### 2.4 Multi-Column Layouts

**AVOID** multi-column layouts in Obsidian. Use sequential structure with clear headings instead.

### 2.5 Graphs and Figures

For hand-drawn graphs:

```markdown
[Insert graph: description of what should be shown]
```

### 2.6 Important Terminology

Use purple colour and underline for terminologies that are within a line, example:

```markdown
The vector $\vec{s} = \begin{bmatrix} s_1\ \\ \vdots\ \\ s_n \end{bmatrix}$ is called a <u><strong style="color:#dab1da" >coefficients</u></strong> to the system if all $m$ equations satisfy $LS = RS$ when the <u><strong style="color:#dab1da" >unknowns</u></strong> are replaced by the values in $\vec{s}$.

The <u><strong style="color:#dab1da" >solution set</u></strong> is the set that contains all possible solutions to the system.
```

Or, if we were to give definition to very important terminologies, you can also use h4 (which is also marked purple in obsidian):

```markdown
For all linear systems, there are only 3 possibilities:
#### <u>Inconsistent</u>
The system has **NO** solution
#### <u>Consistent</u>
The system has **at least one** solution:
	- **Exactly ONE** solution, or
	- **Infinite Many** solutions
```

## 3. Content Guidelines

You will be given the content of a few (6-12) pages as plain text at a time, convert them into one document. This means that you need to shrink the content to about 1/4 the original size. Discard introduction part, unusual examples, outdated language features and only keep the best practices.

You will also be given a rough outline of the desired output note, so follow that structure.

### 3.1 What to Fix

- Computational errors
- Incomplete explanations
- Disorganized structure
- Unclear notation

### 3.2 Organization Tips

- Group related concepts
- Break complex theorems into parts
- Add "why" explanations between steps
- Use consistent terminology


## 4. Example

Input: (Original online tutorial with occasionally unclear structure and a lot of unrelated content)

Document 1
```text
Navigate  
  
12.2 — Value categories (lvalues and rvalues) Table of contents F.X — Chapter F summary and quiz  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.2 — Value categories (lvalues and rvalues) Table of contents F.X — Chapter F summary and quiz  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.1 — Introduction to compound data types  
  
Alex  
  
January 18, 2022, 10:01 am PST November 23, 2024  
  
In lesson 4.1 -- Introduction to fundamental data types, we introduced the fundamental data types, which are the basic data types that C++ provides as part of the core language. We’ve made much use of these fundamental types in our programs so far, especially the int data type. And while these fundamental types are extremely useful for straightforward uses, they don’t cover our full range of needs as we begin to do more complicated things. For example, imagine you were writing a math program to multiply two fractions. How would you represent a fraction in your program? You might use a pair of integers (one for the numerator, one for the denominator), like this: #include <iostream>  
  
int main() { // Our first fraction int num1 {}; int den1 {};  
  
// Our second fraction int num2 {}; int den2 {};  
  
// Used to eat (remove) the slash between the numerator and denominator char ignore {};  
  
std::cout << "Enter a fraction: "; std::cin >> num1 >> ignore >> den1;  
  
std::cout << "Enter a fraction: "; std::cin >> num2 >> ignore >> den2;  
  
std::cout << "The two fractions multiplied: " << num1 * num2 << '/' << den1 * den2 << '\n';  
  
return 0; } And a run of this program: Enter a fraction: 1/2 Enter a fraction: 3/4 The two fractions multiplied: 3/8  
  
While this program works, it introduces a couple of challenges for us to improve upon. First, each pair of integers is only loosely linked -- outside of comments and the context of how they are used in the code, there’s little to suggest that each numerator and denominator pair are related. Second, following the DRY (don’t repeat yourself) principle, we should create a function to handle the user inputting a fraction (along with some error handling). However, functions can only return a single value, so how would we return the numerator and denominator back to the caller?  
  
Now imagine another case where you’re writing a program that needs to keep a list of employee IDs. How might you do so? You might try something like this: int main() { int id1 { 42 }; int id2 { 57 }; int id3 { 162 }; // and so on } But what if you had 100 employees? First, you’d need to type in 100 variable names. And what if you needed to print them all? Or pass them to a function? We’d be in for a lot of typing. This simply doesn’t scale. Clearly fundamental types will only carry us so far. Compound data types Fortunately, C++ supports a second set of data types: compound data types (also sometimes called composite data types) are types that are defined in terms of other existing data types. Compound data types have additional properties and behaviors that make them useful for solving certain types of problems.  
  
Key insight Every data type is either a fundamental type or a compound type. The C++ language standard explicitly defines which category each type falls into.  
  
As we’ll show in this chapter and future chapters, we can use compound data types to elegantly solve all of the challenges we presented above.  
  
C++ supports the following compound types:  
  
Functions C-style Arrays Pointer types:  
  
Pointer to object Pointer to function  
  
Pointer to member types:  
  
Pointer to data member Pointer to member function  
  
Reference types:  
  
L-value references R-value references  
  
Enumerated types:  
  
Unscoped enumerations Scoped enumerations  
  
Class types:  
  
Structs Classes Unions  
  
You’ve already been using one compound type regularly: functions. For example, consider this function: void doSomething(int x, double y) { } The type of this function is void(int, double). Note that this type is composed of fundamental types, making it a compound type. Of course, functions also have their own special behaviors as well (e.g. being callable). Because there’s a lot of material to cover here, we’ll do it over multiple chapters. In this chapter, we’ll cover some of the more straightforward compound types, including l-value references, and pointers. Next chapter, we’ll cover unscoped enumerations, scoped enumerations, and our first class type: structs. Then, in the chapters beyond that, we’ll introduce classses and dig into some of the more useful array types. This includes std::string (introduced in lesson 5.7 -- Introduction to std::string), which is actually a class type!  
  
Nomenclature A class type is a type that is a struct, class, or union. We’ll use this term a lot in future lessons.  
  
Got your game face on? Let’s go!  
  
Next lesson  
  
12.2Value categories (lvalues and rvalues)  
  
Back to table of contents  
  
Previous lesson  
  
F.XChapter F summary and quiz  
  
Previous Post4.12 — Introduction to type conversion and static_cast  
  
Next Post12.2 — Value categories (lvalues and rvalues)  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
53 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move

```

Document 2
```text
Navigate  
  
12.3 — Lvalue references Table of contents 12.1 — Introduction to compound data types  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.3 — Lvalue references Table of contents 12.1 — Introduction to compound data types  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.2 — Value categories (lvalues and rvalues)  
  
Alex  
  
January 18, 2022, 10:04 am PST January 3, 2025  
  
Before we talk about our first compound type (lvalue references), we’re going to take a little detour and talk about what an lvalue is. In lesson 1.10 -- Introduction to expressions, we defined an expression as “a combination of literals, variables, operators, and function calls that can be executed to produce a singular value”. For example: #include <iostream>  
  
int main() { std::cout << 2 + 3 << '\n'; // The expression 2 + 3 produces the value 5  
  
return 0; } In the above program, the expression 2 + 3 is evaluated to produce the value 5, which is then printed to the console. In lesson 6.4 -- Increment/decrement operators, and side effects, we also noted that expressions can produce side effects that outlive the expression: #include <iostream>  
  
int main() { int x { 5 }; ++x; // This expression statement has the side-effect of incrementing x std::cout << x << '\n'; // prints 6  
  
return 0; } In the above program, the expression ++x increments the value of x, and that value remains changed even after the expression has finished evaluating.  
  
Besides producing values and side effects, expressions can do one more thing: they can evaluate to objects or functions. We’ll explore this point further in just a moment. The properties of an expression To help determine how expressions should evaluate and where they can be used, all expressions in C++ have two properties: a type and a value category. The type of an expression The type of an expression is equivalent to the type of the value, object, or function that results from the evaluated expression. For example:  
  
int main() { auto v1 { 12 / 4 }; // int / int => int auto v2 { 12.0 / 4 }; // double / int => double  
  
return 0; } For v1, the compiler will determine (at compile time) that a division with two int operands will produce an int result, so int is the type of this expression. Via type inference, int will then be used as the type of v1. For v2, the compiler will determine (at compile time) that a division with a double operand and an int operand will produce a double result. Remember that arithmetic operators must have operands of matching types, so in this case, the int operand gets converted to a double, and a floating point division is performed. So double is the type of this expression. The compiler can use the type of an expression to determine whether an expression is valid in a given context. For example: #include <iostream>  
  
void print(int x) { std::cout << x << '\n'; }  
  
int main() { print("foo"); // error: print() was expecting an int argument, we tried to pass in a string literal  
  
return 0; } In the above program, the print(int) function is expecting an int parameter. However, the type of the expression we’re passing in (the string literal "foo") does not match, and no conversion can be found. So a compile error results. Note that the type of an expression must be determinable at compile time (otherwise type checking and type deduction wouldn’t work) -- however, the value of an expression may be determined at either compile time (if the expression is constexpr) or runtime (if the expression is not constexpr).  
  
The value category of an expression Now consider the following program: int main() { int x{};  
  
x = 5; // valid: we can assign 5 to x 5 = x; // error: can not assign value of x to literal value 5  
  
return 0; } One of these assignment statements is valid (assigning value 5 to variable x) and one is not (what would it mean to assign the value of x to the literal value 5?). So how does the compiler know which expressions can legally appear on either side of an assignment statement? The answer lies in the second property of expressions: the value category. The value category of an expression (or subexpression) indicates whether an expression resolves to a value, a function, or an object of some kind. Prior to C++11, there were only two possible value categories: lvalue and rvalue.  
  
In C++11, three additional value categories (glvalue, prvalue, and xvalue) were added to support a new feature called move semantics.  
  
Author’s note In this lesson, we’ll stick to the pre-C++11 view of value categories, as this makes for a gentler introduction to value categories (and is all that we need for the moment). We’ll cover move semantics (and the additional three value categories) in a future chapter.  
  
Lvalue and rvalue expressions An lvalue (pronounced “ell-value”, short for “left value” or “locator value”, and sometimes written as “l-value”) is an expression that evaluates to an identifiable object or function (or bit-field). The term “identity” is used by the C++ standard, but is not well-defined. An entity (such as an object or function) that has an identity can be differentiated from other similar entities (typically by comparing the addresses of the entity). Entities with identities can be accessed via an identifier, reference, or pointer, and typically have a lifetime longer than a single expression or statement. int main() { int x { 5 }; int y { x }; // x is an lvalue expression  
  
return 0; } In the above program, the expression x is an lvalue expression as it evaluates to variable x (which has an identifier).  
  
Since the introduction of constants into the language, lvalues come in two subtypes: a modifiable lvalue is an lvalue whose value can be modified. A non-modifiable lvalue is an lvalue whose value can’t be modified (because the lvalue is const or constexpr). int main() { int x{}; const double d{};  
  
int y { x }; // x is a modifiable lvalue expression const double e { d }; // d is a non-modifiable lvalue expression  
  
return 0; } An rvalue (pronounced “arr-value”, short for “right value”, and sometimes written as r-value) is an expression that is not an lvalue. Rvalue expressions evaluate to a value. Commonly seen rvalues include literals (except C-style string literals, which are lvalues) and the return value of functions and operators that return by value. Rvalues aren’t identifiable (meaning they have to be used immediately), and only exist within the scope of the expression in which they are used. int return5() { return 5; }  
  
int main() { int x{ 5 }; // 5 is an rvalue expression const double d{ 1.2 }; // 1.2 is an rvalue expression  
  
int y { x }; // x is a modifiable lvalue expression const double e { d }; // d is a non-modifiable lvalue expression int z { return5() }; // return5() is an rvalue expression (since the result is returned by value)  
  
int w { x + 1 }; // x + 1 is an rvalue expression int q { static_cast<int>(d) }; // the result of static casting d to an int is an rvalue expression  
  
return 0; } You may be wondering why return5(), x + 1, and static_cast<int>(d) are rvalues: the answer is because these expressions produce temporary values that are not identifiable objects.  
  
Key insight Lvalue expressions evaluate to an identifiable object. Rvalue expressions evaluate to a value.  
  
Value categories and operators Unless otherwise specified, operators expect their operands to be rvalues. For example, binary operator+ expects its operands to be rvalues: #include <iostream>  
  
int main() { std::cout << 1 + 2; // 1 and 2 are rvalues, operator+ returns an rvalue  
  
return 0; } The literals 1 and 2 are both rvalue expressions. operator+ will happily use these to return the rvalue expression 3.  
  
Now we can answer the question about why x = 5 is valid but 5 = x is not: an assignment operation requires its left operand to be a modifiable lvalue expression. The latter assignment (5 = x) fails because the left operand expression 5 is an rvalue, not a modifiable lvalue. int main() { int x{};  
  
// Assignment requires the left operand to be a modifiable lvalue expression and the right operand to be an rvalue expression x = 5; // valid: x is a modifiable lvalue expression and 5 is an rvalue expression 5 = x; // error: 5 is an rvalue expression and x is a modifiable lvalue expression  
  
return 0; } Lvalue-to-rvalue conversion Since assignment operations expect the right operand to be an rvalue expression, you might be wondering why the following works: int main() { int x{ 1 }; int y{ 2 };  
  
x = y; // y is not an rvalue, but this is legal  
  
return 0; } In cases where an rvalue is expected but an lvalue is provided, the lvalue will undergo an lvalue-to-rvalue conversion so that it can be used in such contexts. This basically means the lvalue is evaluated to produce its value, which is an rvalue. In the above example, the lvalue expression y undergoes an lvalue-to-rvalue conversion, which evaluates y to produce an rvalue (2), which is then assigned to x.  
  
Key insight An lvalue will implicitly convert to an rvalue. This means an lvalue can be used anywhere an rvalue is expected. An rvalue, on the other hand, will not implicitly convert to an lvalue.  
  
Now consider this example: int main() { int x { 2 };  
  
x = x + 1;  
  
return 0; } In this statement, the variable x is being used in two different contexts. On the left side of the assignment operator (where an lvalue expression is required), x is an lvalue expression that evaluates to variable x. On the right side of the assignment operator, x undergoes an lvalue-to-rvalue conversion and is then evaluated so that its (2) can be used as the left operand of operator+. operator+ returns the rvalue expression 3, which is then used as the right operand for the assignment.  
  
How to differentiate lvalues and rvalues You may still be confused about what kind of expressions qualify as an lvalue vs an rvalue. For example, is the result of operator++ an lvalue or an rvalue? We’ll cover various methods you can use to determine which is which here.  
  
Tip A rule of thumb to identify lvalue and rvalue expressions:  
  
Lvalue expressions are those that evaluate to functions or identifiable objects (including variables) that persist beyond the end of the expression.  
  
Rvalue expressions are those that evaluate to values, including literals and temporary objects that do not persist beyond the end of the expression.  
  
For a more complete list of lvalue and rvalue expressions, you can consult technical documentation.  
  
Tip A full list of lvalue and rvalue expressions can be found here. In C++11, rvalues are broken into two subtypes: prvalues and xvalues, so the rvalues we’re talking about here are the sum of both of those categories.  
  
Finally, we can write a program and have the compiler tell us what kind of expression something is. The following code demonstrates a method that determines whether an expression is an lvalue or an rvalue: #include <iostream> #include <string>  
  
// T& is an lvalue reference, so this overload will be preferred for lvalues template <typename T> constexpr bool is_lvalue(T&) { return true; }  
  
// T&& is an rvalue reference, so this overload will be preferred for rvalues template <typename T> constexpr bool is_lvalue(T&&) { return false; }  
  
// A helper macro (#expr prints whatever is passed in for expr as text) #define PRINTVCAT(expr) { std::cout << #expr << " is an " << (is_lvalue(expr) ? "lvalue\n" : "rvalue\n"); }  
  
int getint() { return 5; }  
  
int main() { PRINTVCAT(5); // rvalue PRINTVCAT(getint()); // rvalue int x { 5 }; PRINTVCAT(x); // lvalue PRINTVCAT(std::string {"Hello"}); // rvalue PRINTVCAT("Hello"); // lvalue PRINTVCAT(++x); // lvalue PRINTVCAT(x++); // rvalue } This prints: 5 is an rvalue getint() is an rvalue x is an lvalue std::string {"Hello"} is an rvalue "Hello" is an lvalue ++x is an lvalue x++ is an rvalue  
  
This method relies on two overloaded functions: one with an lvalue refrence parameter and one with an rvalue reference parameter. The lvalue reference version will be preferred for lvalue arguments, and the rvalue reference version will be preferred for rvalue arguments. Thus we can determine whether the argument is an lvalue or rvalue based on which function gets selected. So as you can see, whether operator++ results in an lvalue or an rvalue depends on whether it is used as a prefix operator (which returns an lvalue) or a postfix operator (which returns an rvalue)!  
  
For advanced readers Unlike the other literals (which are rvalues), a C-style string literal is an lvalue because C-style strings (which are C-style arrays) decay to a pointer. The decay process only works if the array is an lvalue (and thus has an address that can be stored in the pointer). C++ inherited this for backwards compatibility. We cover array decay in lesson 17.8 -- C-style array decay.  
  
Now that we’ve covered lvalues, we can get to our first compound type: the lvalue reference.  
  
Next lesson  
  
12.3 Lvalue references  
  
Back to table of contents  
  
Previous lesson  
  
12.1Introduction to compound data types  
  
Previous Post12.1 — Introduction to compound data types  
  
Next Post12.11 — Pass by address (part 2)  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
146 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```

Document3
```text
Navigate  
  
12.4 — Lvalue references to const Table of contents 12.2 — Value categories (lvalues and rvalues)  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.4 — Lvalue references to const Table of contents 12.2 — Value categories (lvalues and rvalues)  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.3 — Lvalue references  
  
Alex  
  
July 16, 2007, 6:19 pm PDT November 11, 2024  
  
In C++, a reference is an alias for an existing object. Once a reference has been defined, any operation on the reference is applied to the object being referenced. This means we can use a reference to read or modify the object being referenced. Although references might seem silly, useless, or redundant at first, references are used everywhere in C++ (we’ll see examples of this in a few lessons).  
  
Key insight A reference is essentially identical to the object being referenced.  
  
You can also create references to functions, though this is done less often. Modern C++ contains two types of references: lvalue references, and rvalue references. In this chapter, we’ll discuss lvalue references.  
  
Related content Because we’ll be talking about lvalues and rvalues in this lesson, please review 12.2 -- Value categories (lvalues and rvalues) if you need a refresher on these terms before proceeding. Rvalue references are covered in the chapter on move semantics (chapter 22).  
  
Lvalue references types An lvalue reference (commonly just called a “reference” since prior to C++11 there was only one type of reference) acts as an alias for an existing lvalue (such as a variable).  
  
Just like the type of an object determines what kind of value it can hold, the type of a reference determines what type of object it can reference. Lvalue reference types can be identified by use of a single ampersand (&) in the type specifier: // regular types int // a normal int type (not an reference) int& // an lvalue reference to an int object double& // an lvalue reference to a double object const int& // an lvalue reference to a const int object For example, int& is the type of an lvalue reference to an int object, and const int& is the type of an lvalue reference to a const int object. A type that specifies a reference (e.g. int&) is called a reference type. The type that can be referenced (e.g. int) is called the referenced type.  
  
Nomenclature There are two kinds of lvalue references:  
  
An lvalue reference to a non-const is commonly just called an “lvalue reference”, but may also be referred to as an lvalue reference to non-const or a non-const lvalue reference (since it isn’t defined using the const keyword).  
  
An lvalue reference to a const is commonly called either an lvalue reference to const or a const lvalue reference.  
  
We’ll focus on non-const lvalue references in this lesson, and on const lvalue references in the next lesson (12.4 -- Lvalue references to const). Lvalue reference variables One of the things we can do with an lvalue reference type is create an lvalue reference variable. An lvalue reference variable is a variable that acts as a reference to an lvalue (usually another variable).  
  
To create an lvalue reference variable, we simply define a variable with an lvalue reference type: #include <iostream>  
  
int main() { int x { 5 }; // x is a normal integer variable int& ref { x }; // ref is an lvalue reference variable that can now be used as an alias for variable x  
  
std::cout << x << '\n'; // print the value of x (5) std::cout << ref << '\n'; // print the value of x via ref (5)  
  
return 0; } In the above example, the type int& defines ref as an lvalue reference to an int, which we then initialize with lvalue expression x. Thereafter, ref and x can be used synonymously. This program thus prints: 5 5  
  
From the compiler’s perspective, it doesn’t matter whether the ampersand is “attached” to the type name (int& ref) or the variable’s name (int &ref), and which you choose is a matter of style. Modern C++ programmers tend to prefer attaching the ampersand to the type, as it makes clearer that the reference is part of the type information, not the identifier.  
  
Best practice When defining a reference, place the ampersand next to the type (not the reference variable’s name).  
  
For advanced readers For those of you already familiar with pointers, the ampersand in this context does not mean “address of”, it means “lvalue reference to”.  
  
Modifying values through a non-const lvalue reference In the above example, we showed that we can use a reference to read the value of the object being referenced. We can also use a non-const reference to modify the value of the object being referenced:  
  
#include <iostream>  
  
int main() { int x { 5 }; // normal integer variable int& ref { x }; // ref is now an alias for variable x  
  
std::cout << x << ref << '\n'; // print 55  
  
x = 6; // x now has value 6  
  
std::cout << x << ref << '\n'; // prints 66  
  
ref = 7; // the object being referenced (x) now has value 7  
  
std::cout << x << ref << '\n'; // prints 77  
  
return 0; } This code prints: 55 66 77  
  
In the above example, ref is an alias for x, so we are able to change the value of x through either x or ref. Reference initialization Much like constants, all references must be initialized. References are initialized using a form of initialization called reference initialization. int main() { int& invalidRef; // error: references must be initialized  
  
int x { 5 }; int& ref { x }; // okay: reference to int is bound to int variable  
  
return 0; } When a reference is initialized with an object (or function), we say it is bound to that object (or function). The process by which such a reference is bound is called reference binding. The object (or function) being referenced is sometimes called the referent. Non-const lvalue references can only be bound to a modifiable lvalue. int main() { int x { 5 }; int& ref { x }; // okay: non-const lvalue reference bound to a modifiable lvalue  
  
const int y { 5 }; int& invalidRef { y }; // invalid: non-const lvalue reference can't bind to a non-modifiable lvalue int& invalidRef2 { 0 }; // invalid: non-const lvalue reference can't bind to an rvalue  
  
return 0; }  
  
Key insight If non-const lvalue references could be bound to non-modifiable (const) lvalues or rvalues, then you would be able to change those values through the reference, which would be a violation of their const-ness.  
  
Lvalue references to void are disallowed (what would be the point?).  
  
Even though the type of the reference (e.g. int&) doesn’t exactly match the type of the object being bound (e.g. int), no conversion is applied here (not even a trivial conversion) -- the difference in types is handled as part of the reference initialization process. A reference will (usually) only bind to an object matching its referenced type In most cases, a reference will only bind to an object whose type matches the referenced type, (there are some exceptions to this rule that we’ll discuss when we get into inheritance). If you try to bind a reference to an object that does not match its referenced type, the compiler will try to implicitly convert the object to the referenced type and then bind the reference to that.  
  
Key insight Since the result of a conversion is an rvalue, and a non-const lvalue reference can’t bind to an rvalue, trying to bind a non-const lvalue reference to an object that does not match its referenced type will result in a compilation error.  
  
int main() { int x { 5 }; int& ref { x }; // okay: referenced type (int) matches type of initializer  
  
double d { 6.0 }; int& invalidRef { d }; // invalid: conversion of double to int is narrowing conversion, disallowed by list initialization double& invalidRef2 { x }; // invalid: non-const lvalue reference can't bind to rvalue (result of converting x to double)  
  
return 0; } References can’t be reseated (changed to refer to another object)  
  
Once initialized, a reference in C++ cannot be reseated, meaning it cannot be changed to reference another object. New C++ programmers often try to reseat a reference by using assignment to provide the reference with another variable to reference. This will compile and run -- but not function as expected. Consider the following program: #include <iostream>  
  
int main() { int x { 5 }; int y { 6 };  
  
int& ref { x }; // ref is now an alias for x  
  
ref = y; // assigns 6 (the value of y) to x (the object being referenced by ref) // The above line does NOT change ref into a reference to variable y!  
  
std::cout << x << '\n'; // user is expecting this to print 5  
  
return 0; } Perhaps surprisingly, this prints: 6  
  
When a reference is evaluated in an expression, it resolves to the object it’s referencing. So ref = y doesn’t change ref to now reference y. Rather, because ref is an alias for x, the expression evaluates as if it was written x = y -- and since y evaluates to value 6, x is assigned the value 6. Reference scope and duration Reference variables follow the same scoping and duration rules that normal variables do: #include <iostream>  
  
int main() { int x { 5 }; // normal integer int& ref { x }; // reference to variable value  
  
return 0; } // x and ref die here References and referents have independent lifetimes  
  
With one exception (that we’ll cover next lesson), the lifetime of a reference and the lifetime of its referent are independent. In other words, both of the following are true:  
  
A reference can be destroyed before the object it is referencing.  
  
The object being referenced can be destroyed before the reference.  
  
When a reference is destroyed before the referent, the referent is not impacted. The following program demonstrates this: #include <iostream>  
  
int main() { int x { 5 };  
  
{ int& ref { x }; // ref is a reference to x std::cout << ref << '\n'; // prints value of ref (5) } // ref is destroyed here -- x is unaware of this  
  
std::cout << x << '\n'; // prints value of x (5)  
  
return 0; } // x destroyed here The above prints: 5 5  
  
When ref dies, variable x carries on as normal, blissfully unaware that a reference to it has been destroyed. Dangling references When an object being referenced is destroyed before a reference to it, the reference is left referencing an object that no longer exists. Such a reference is called a dangling reference. Accessing a dangling reference leads to undefined behavior. Dangling references are fairly easy to avoid, but we’ll show a case where this can happen in practice in lesson 12.12 -- Return by reference and return by address.  
  
References aren’t objects Perhaps surprisingly, references are not objects in C++. A reference is not required to exist or occupy storage. If possible, the compiler will optimize references away by replacing all occurrences of a reference with the referent. However, this isn’t always possible, and in such cases, references may require storage. This also means that the term “reference variable” is a bit of a misnomer, as variables are objects with a name, and references aren’t objects. Because references aren’t objects, they can’t be used anywhere an object is required (e.g. you can’t have a reference to a reference, since an lvalue reference must reference an identifiable object). In cases where you need a reference that is an object or a reference that can be reseated, std::reference_wrapper (which we cover in lesson 23.3 -- Aggregation) provides a solution.  
  
As an aside… Consider the following variables: int var{}; int& ref1{ var }; // an lvalue reference bound to var int& ref2{ ref1 }; // an lvalue reference bound to var Because ref2 (a reference) is initialized with ref1 (a reference), you might be tempted to conclude that ref2 is a reference to a reference. It is not. Because ref1 is a reference to var, when used in an expression (such as an initializer), ref1 evaluates to var. So ref2 is just a normal lvalue reference (as indicated by its type int&), bound to var. A reference to a reference (to an int) would have syntax int&& -- but since C++ doesn’t support references to references, this syntax was repurposed in C++11 to indicate an rvalue reference (which we cover in lesson 22.2 -- R-value references).  
  
Author’s note If references seem a bit useless at this point, don’t worry. References are used a lot, and we’ll cover one of the primary reasons why shortly, in lessons 12.5 -- Pass by lvalue reference and 12.6 -- Pass by const lvalue reference.  
  
Quiz time Question #1 Determine what values the following program prints by yourself (do not compile the program). #include <iostream>  
  
int main() { int x{ 1 }; int& ref{ x };  
  
std::cout << x << ref << '\n';  
  
int y{ 2 }; ref = y; y = 3;  
  
std::cout << x << ref << '\n';  
  
x = 4;  
  
std::cout << x << ref << '\n';  
  
return 0; } Show Solution  
  
11 22 44 Because ref is bound to x, x and ref are synonymous, so they will always print the same value. The line ref = y assigns the value of y (2) to ref -- it does not change ref to reference y. The subsequent line y = 3 only changes y.  
  
Next lesson  
  
12.4Lvalue references to const  
  
Back to table of contents  
  
Previous lesson  
  
12.2Value categories (lvalues and rvalues)  
  
Previous Post12.9 — Pointers and const  
  
Next Post13.12 — Member selection with pointers and references  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
361 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```

Document 4

```text
Navigate  
  
12.5 — Pass by lvalue reference Table of contents 12.3 — Lvalue references  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.5 — Pass by lvalue reference Table of contents 12.3 — Lvalue references  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.4 — Lvalue references to const  
  
Alex  
  
June 7, 2017, 3:30 pm PDT February 23, 2025  
  
In the previous lesson (12.3 -- Lvalue references), we discussed how an lvalue reference can only bind to a modifiable lvalue. This means the following is illegal: int main() { const int x { 5 }; // x is a non-modifiable (const) lvalue int& ref { x }; // error: ref can not bind to non-modifiable lvalue  
  
return 0; } This is disallowed because it would allow us to modify a const variable (x) through the non-const reference (ref). But what if we want to have a const variable we want to create a reference to? A normal lvalue reference (to a non-const value) won’t do. Lvalue reference to const By using the const keyword when declaring an lvalue reference, we tell an lvalue reference to treat the object it is referencing as const. Such a reference is called an lvalue reference to a const value (sometimes called a reference to const or a const reference). Lvalue references to const can bind to non-modifiable lvalues:  
  
int main() { const int x { 5 }; // x is a non-modifiable lvalue const int& ref { x }; // okay: ref is a an lvalue reference to a const value  
  
return 0; } Because lvalue references to const treat the object they are referencing as const, they can be used to access but not modify the value being referenced: #include <iostream>  
  
int main() { const int x { 5 }; // x is a non-modifiable lvalue const int& ref { x }; // okay: ref is a an lvalue reference to a const value  
  
std::cout << ref << '\n'; // okay: we can access the const object ref = 6; // error: we can not modify an object through a const reference  
  
return 0; } Initializing an lvalue reference to const with a modifiable lvalue Lvalue references to const can also bind to modifiable lvalues. In such a case, the object being referenced is treated as const when accessed through the reference (even though the underlying object is non-const): #include <iostream>  
  
int main() { int x { 5 }; // x is a modifiable lvalue const int& ref { x }; // okay: we can bind a const reference to a modifiable lvalue  
  
std::cout << ref << '\n'; // okay: we can access the object through our const reference ref = 7; // error: we can not modify an object through a const reference  
  
x = 6; // okay: x is a modifiable lvalue, we can still modify it through the original identifier  
  
return 0; } In the above program, we bind const reference ref to modifiable lvalue x. We can then use ref to access x, but because ref is const, we can not modify the value of x through ref. However, we still can modify the value of x directly (using the identifier x).  
  
Best practice Favor lvalue references to const over lvalue references to non-const unless you need to modify the object being referenced.  
  
Initializing an lvalue reference to const with an rvalue  
  
Perhaps surprisingly, lvalues references to const can also bind to rvalues: #include <iostream>  
  
int main() { const int& ref { 5 }; // okay: 5 is an rvalue  
  
std::cout << ref << '\n'; // prints 5  
  
return 0; } When this happens, a temporary object is created and initialized with the rvalue, and the reference to const is bound to that temporary object.  
  
Related content We covered temporary objects in lesson 2.5 -- Introduction to local scope.  
  
Initializing an lvalue reference to const with a value of a different type Lvalue references to const can even bind to values of a different type, so long as those values can be implicitly converted to the reference type: #include <iostream>  
  
int main() { // case 1 const double& r1 { 5 }; // temporary double initialized with value 5, r1 binds to temporary  
  
std::cout << r1 << '\n'; // prints 5  
  
// case 2 char c { 'a' }; const int& r2 { c }; // temporary int initialized with value 'a', r2 binds to temporary  
  
std::cout << r2 << '\n'; // prints 97 (since r2 is a reference to int)  
  
return 0; } In case 1, a temporary object of type double is created and initialized with int value 5. Then const double& r1 is bound to that temporary double object.  
  
In case 2, a temporary object of type int is created and initialized with char value a. Then const int& r2 is bound to that temporary int object. In both cases, the type of the reference and the type of the temporary match.  
  
Key insight If you try to bind a const lvalue reference to a value of a different type, the compiler will create a temporary object of the same type as the reference, initialize it using the value, and then bind the reference to the temporary.  
  
Also note that when we print r2 it prints as an int rather than a char. This is because r2 is a reference to an int object (the temporary int that was created), not to char c. Although it may seem strange to allow this, we’ll see examples where this is useful in lesson 12.6 -- Pass by const lvalue reference.  
  
Warning We normally assume that a reference is identical to the object it is bound to -- but this assumption is broken when a reference is bound to a temporary copy of the object or a temporary resulting from the conversion of the object instead. Any modifications subsequently made to the original object will not be seen by the reference (as it is referencing a different object), and vice-versa. Here’s a silly example showing this: #include <iostream>  
  
int main() { short bombs { 1 }; // I can has bomb! (note: type is short)  
  
const int& you { bombs }; // You can has bomb too (note: type is int&) --bombs; // Bomb all gone  
  
if (you) // You still has? { std::cout << "Bombs away! Goodbye, cruel world.\n"; // Para bailar la bomba }  
  
return 0; } In the above example, bombs is a short and you is a const int&. Because you can only bind to an int object, when you is initialized with bombs, the compiler will implicitly convert bombs to an int, which results in the creation of a temporary int object (with value 1). you ends up bound to this temporary object rather than bombs. When bombs is decremented, you is not affected because it is referencing a different object. So although we expect if (you) to evaluate to false, it actually evaluates to true. If you would stop blowing up the world, that would be great.  
  
Const references bound to temporary objects extend the lifetime of the temporary object  
  
Temporary objects are normally destroyed at the end of the expression in which they are created. Given the statement const int& ref { 5 };, consider what would happen instead if the temporary object created to hold rvalue 5 was destroyed at the end of the expression that initializes ref. Reference ref would be left dangling (referencing an object that had been destroyed), and we’d get undefined behavior when we tried to access ref. To avoid dangling references in such cases, C++ has a special rule: When a const lvalue reference is directly bound to a temporary object, the lifetime of the temporary object is extended to match the lifetime of the reference. #include <iostream>  
  
int main() { const int& ref { 5 }; // The temporary object holding value 5 has its lifetime extended to match ref  
  
std::cout << ref << '\n'; // Therefore, we can safely use it here  
  
return 0; } // Both ref and the temporary object die here In the above example, when ref is initialized with rvalue 5, a temporary object is created and ref is bound to that temporary object. The lifetime of the temporary object matches the lifetime of ref. Thus, we can safely print the value of ref in the next statement. Then both ref and the temporary object go out of scope and are destroyed at the end of the block.  
  
Key insight Lvalue references can only bind to modifiable lvalues. Lvalue references to const can bind to modifiable lvalues, non-modifiable lvalues, and rvalues. This makes them a much more flexible type of reference.  
  
For advanced readers Lifetime extension only works when a const reference is directly bound to a temporary. Temporaries returned from a function (even ones returned by const reference) are not eligible for lifetime extension. We show an example of this in lesson 12.12 -- Return by reference and return by address. For class type rvalues, binding a reference to a member will extend the lifetime of the entire object.  
  
So why does C++ allow a const reference to bind to an rvalue anyway? We’ll answer that question in the next lesson!  
  
Constexpr lvalue references Optional When applied to a reference, constexpr allows the reference to be used in a constant expression. Constexpr references have a particular limitation: they can only be bound to objects with static duration (either globals or static locals). This is because the compiler knows where static objects will be instantiated in memory, so it can treat that address as a compile-time constant. A constexpr reference cannot bind to a (non-static) local variable. This is because the address of local variables is not known until the function they are defined within is actually called. int g_x { 5 };  
  
int main() { [[maybe_unused]] constexpr int& ref1 { g_x }; // ok, can bind to global  
  
static int s_x { 6 }; [[maybe_unused]] constexpr int& ref2 { s_x }; // ok, can bind to static local  
  
int x { 6 }; [[maybe_unused]] constexpr int& ref3 { x }; // compile error: can't bind to non-static object  
  
return 0; } When defining a constexpr reference to a const variable, we need to apply both constexpr (which applies to the reference) and const (which applies to the type being referenced). int main() { static const int s_x { 6 }; // a const int [[maybe_unused]] constexpr const int& ref2 { s_x }; // needs both constexpr and const  
  
return 0; } Given these limitations, constexpr references typically don’t see much use.  
  
Next lesson  
  
12.5Pass by lvalue reference  
  
Back to table of contents  
  
Previous lesson  
  
12.3 Lvalue references  
  
Previous Post9.6 — Assert and static_assert  
  
Next Post24.8 — Hiding inherited functionality  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
214 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```

Document 5
```
Navigate  
  
12.6 — Pass by const lvalue reference Table of contents 12.4 — Lvalue references to const  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.6 — Pass by const lvalue reference Table of contents 12.4 — Lvalue references to const  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.5 — Pass by lvalue reference  
  
Alex  
  
July 24, 2007, 6:06 pm PDT December 6, 2024  
  
In the previous lessons, we introduced lvalue references (12.3 -- Lvalue references) and lvalue references to const (12.4 -- Lvalue references to const). In isolation, these may not have seemed very useful -- why create an alias to a variable when you can just use the variable itself? In this lesson, we’ll finally provide some insight into what makes references useful. And then starting later in this chapter, you’ll see references used regularly. First, some context. Back in lesson 2.4 -- Introduction to function parameters and arguments we discussed pass by value, where an argument passed to a function is copied into the function’s parameter: #include <iostream>  
  
void printValue(int y) { std::cout << y << '\n'; } // y is destroyed here  
  
int main() { int x { 2 };  
  
printValue(x); // x is passed by value (copied) into parameter y (inexpensive)  
  
return 0; } In the above program, when printValue(x) is called, the value of x (2) is copied into parameter y. Then, at the end of the function, object y is destroyed. This means that when we called the function, we made a copy of our argument’s value, only to use it briefly and then destroy it! Fortunately, because fundamental types are cheap to copy, this isn’t a problem.  
  
Some objects are expensive to copy Most of the types provided by the standard library (such as std::string) are class types. Class types are usually expensive to copy. Whenever possible, we want to avoid making unnecessary copies of objects that are expensive to copy, especially when we will destroy those copies almost immediately. Consider the following program illustrating this point: #include <iostream> #include <string>  
  
void printValue(std::string y) { std::cout << y << '\n'; } // y is destroyed here  
  
int main() { std::string x { "Hello, world!" }; // x is a std::string  
  
printValue(x); // x is passed by value (copied) into parameter y (expensive)  
  
return 0; } This prints Hello, world!  
  
While this program behaves like we expect, it’s also inefficient. Identically to the prior example, when printValue() is called, argument x is copied into printValue() parameter y. However, in this example, the argument is a std::string instead of an int, and std::string is a class type that is expensive to copy. And this expensive copy is made every time printValue() is called! We can do better. Pass by reference One way to avoid making an expensive copy of an argument when calling a function is to use pass by reference instead of pass by value. When using pass by reference, we declare a function parameter as a reference type (or const reference type) rather than as a normal type. When the function is called, each reference parameter is bound to the appropriate argument. Because the reference acts as an alias for the argument, no copy of the argument is made.  
  
Here’s the same example as above, using pass by reference instead of pass by value: #include <iostream> #include <string>  
  
void printValue(std::string& y) // type changed to std::string& { std::cout << y << '\n'; } // y is destroyed here  
  
int main() { std::string x { "Hello, world!" };  
  
printValue(x); // x is now passed by reference into reference parameter y (inexpensive)  
  
return 0; } This program is identical to the prior one, except the type of parameter y has been changed from std::string to std::string& (an lvalue reference). Now, when printValue(x) is called, lvalue reference parameter y is bound to argument x. Binding a reference is always inexpensive, and no copy of x needs to be made. Because a reference acts as an alias for the object being referenced, when printValue() uses reference y, it’s accessing the actual argument x (rather than a copy of x).  
  
Key insight Pass by reference allows us to pass arguments to a function without making copies of those arguments each time the function is called.  
  
The following program demonstrates that a value parameter is a separate object from the argument, while a reference parameter is treated as if it were the argument: #include <iostream>  
  
void printAddresses(int val, int& ref) { std::cout << "The address of the value parameter is: " << &val << '\n'; std::cout << "The address of the reference parameter is: " << &ref << '\n'; }  
  
int main() { int x { 5 }; std::cout << "The address of x is: " << &x << '\n'; printAddresses(x, x);  
  
return 0; } One run of this program produced the following output: The address of x is: 0x7ffd16574de0 The address of the value parameter is: 0x7ffd16574de4 The address of the reference parameter is: 0x7ffd16574de0  
  
We can see that the argument has a different address than the value parameter, meaning the value parameter is a different object. Since they have separate memory addresses, in order for the value parameter to have the same value as the argument, the argument’s value must be copied into memory held by the value parameter.  
  
On the other hand, we can see that taking the address of the reference parameter yields an address identical to that of the argument. This means that the reference parameter is being treated as if it were the same object as the argument. Pass by reference allows us to change the value of an argument When an object is passed by value, the function parameter receives a copy of the argument. This means that any changes to the value of the parameter are made to the copy of the argument, not the argument itself: #include <iostream>  
  
void addOne(int y) // y is a copy of x { ++y; // this modifies the copy of x, not the actual object x }  
  
int main() { int x { 5 };  
  
std::cout << "value = " << x << '\n';  
  
addOne(x);  
  
std::cout << "value = " << x << '\n'; // x has not been modified  
  
return 0; } In the above program, because value parameter y is a copy of x, when we increment y, this only affects y. This program outputs: value = 5 value = 5  
  
However, since a reference acts identically to the object being referenced, when using pass by reference, any changes made to the reference parameter will affect the argument:  
  
#include <iostream>  
  
void addOne(int& y) // y is bound to the actual object x { ++y; // this modifies the actual object x }  
  
int main() { int x { 5 };  
  
std::cout << "value = " << x << '\n';  
  
addOne(x);  
  
std::cout << "value = " << x << '\n'; // x has been modified  
  
return 0; } This program outputs: value = 5 value = 6  
  
In the above example, x initially has value 5. When addOne(x) is called, reference parameter y is bound to argument x. When the addOne() function increments reference y, it’s actually incrementing argument x from 5 to 6 (not a copy of x). This changed value persists even after addOne() has finished executing.  
  
Key insight Passing values by reference to non-const allows us to write functions that modify the value of arguments passed in.  
  
The ability for functions to modify the value of arguments passed in can be useful. Imagine you’ve written a function that determines whether a monster has successfully attacked the player. If so, the monster should do some amount of damage to the player’s health. If you pass your player object by reference, the function can directly modify the health of the actual player object that was passed in. If you pass the player object by value, you could only modify the health of a copy of the player object, which isn’t as useful. Pass by reference can only accept modifiable lvalue arguments Because a reference to a non-const value can only bind to a modifiable lvalue (essentially a non-const variable), this means that pass by reference only works with arguments that are modifiable lvalues. In practical terms, this significantly limits the usefulness of pass by reference to non-const, as it means we can not pass const variables or literals. For example: #include <iostream>  
  
void printValue(int& y) // y only accepts modifiable lvalues { std::cout << y << '\n'; }  
  
int main() { int x { 5 }; printValue(x); // ok: x is a modifiable lvalue  
  
const int z { 5 }; printValue(z); // error: z is a non-modifiable lvalue  
  
printValue(5); // error: 5 is an rvalue  
  
return 0; } Fortunately, there’s an easy way around this, which we will discuss next lesson. We’ll also take a look at when to pass by value vs. pass by reference.  
  
Next lesson  
  
12.6Pass by const lvalue reference  
  
Back to table of contents  
  
Previous lesson  
  
12.4Lvalue references to const  
  
Previous Postx.x — Passing arguments by value  
  
Next Post12.10 — Pass by address  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
362 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```

Document 6
```
Navigate  
  
12.7 — Introduction to pointers Table of contents 12.5 — Pass by lvalue reference  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.7 — Introduction to pointers Table of contents 12.5 — Pass by lvalue reference  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.6 — Pass by const lvalue reference  
  
Alex  
  
July 26, 2023, 4:26 pm PDT November 21, 2024  
  
Unlike a reference to non-const (which can only bind to modifiable lvalues), a reference to const can bind to modifiable lvalues, non-modifiable lvalues, and rvalues. Therefore, if we make a reference parameter const, then it will be able to bind to any type of argument: #include <iostream>  
  
void printRef(const int& y) // y is a const reference { std::cout << y << '\n'; }  
  
int main() { int x { 5 }; printRef(x); // ok: x is a modifiable lvalue, y binds to x  
  
const int z { 5 }; printRef(z); // ok: z is a non-modifiable lvalue, y binds to z  
  
printRef(5); // ok: 5 is rvalue literal, y binds to temporary int object  
  
return 0; } Passing by const reference offers the same primary benefit as pass by non-const reference (avoiding making a copy of the argument), while also guaranteeing that the function can not change the value being referenced. For example, the following is disallowed, because ref is const: void addOne(const int& ref) { ++ref; // not allowed: ref is const } In most cases, we don’t want our functions modifying the value of arguments.  
  
Best practice Favor passing by const reference over passing by non-const reference unless you have a specific reason to do otherwise (e.g. the function needs to change the value of an argument).  
  
Now we can understand the motivation for allowing const lvalue references to bind to rvalues: without that capability, there would be no way to pass literals (or other rvalues) to functions that used pass by reference!  
  
Passing arguments of a different type to a const lvalue reference parameter In lesson 12.4 -- Lvalue references to const, we noted that a const lvalue reference can bind to a value of a different type, as long as that value is convertible to the type of the reference. The conversion creates a temporary object that the reference parameter can then bind to. The primary motivation for allowing this is so that we can pass a value as an argument to either a value parameter or a const reference parameter in exactly the same way: #include <iostream>  
  
void printVal(double d) { std::cout << d << '\n'; }  
  
void printRef(const double& d) { std::cout << d << '\n'; }  
  
int main() { printVal(5); // 5 converted to temporary double, copied to parameter d printRef(5); // 5 converted to temporary double, bound to parameter d  
  
return 0; } With pass-by-value, we expect a copy to be made, so if a conversion occurs first (resulting in an additional copy) it’s rarely an issue (and the compiler will likely optimize one of the two copies away). However, we often use pass by reference when we don’t want a copy to be made. If a conversion occurs first, this will typically result in a (possibly expensive) copy being made, which can be suboptimal.  
  
Warning With pass by reference, ensure the type of the argument matches the type of the reference, or it will result in an unexpected (and possibly expensive) conversion.  
  
Mixing pass by value and pass by reference A function with multiple parameters can determine whether each parameter is passed by value or passed by reference individually. For example: #include <string>  
  
void foo(int a, int& b, const std::string& c) { }  
  
int main() { int x { 5 }; const std::string s { "Hello, world!" };  
  
foo(5, x, s);  
  
return 0; } In the above example, the first argument is passed by value, the second by reference, and the third by const reference. When to use pass by value vs pass by reference For most C++ beginners, the choice of whether to use pass by value or pass by reference isn’t very obvious. Fortunately, there’s a straightforward rule of thumb that will serve you well in the majority cases.  
  
Fundamental types and enumerated types are cheap to copy, so they are typically passed by value.  
  
Class types can be expensive to copy (sometimes significantly so), so they are typically passed by const reference.  
  
Best practice As a rule of thumb, pass fundamental types by value and class types by const reference. If you aren’t sure what to do, pass by const reference, as you’re less likely to encounter unexpected behavior.  
  
Tip Here’s a partial list of other interesting cases: The following are often passed by value (because it is more efficient):  
  
Enumerated types (unscoped and scoped enumerations).  
  
Views and spans (e.g. std::string_view, std::span).  
  
Types that mimic references or (non-owning) pointers (e.g. iterators, std::reference_wrapper).  
  
Cheap-to-copy class types that have value semantics (e.g. std::pair with elements of fundamental types, std::optional, std::expected).  
  
Pass by reference should be used for the following:  
  
Arguments that need to be modified by the function.  
  
Types that aren’t copyable (such as std::ostream).  
  
Types where copying has ownership implications that we want to avoid (e.g. std::unique_ptr, std::shared_ptr).  
  
Types that have virtual functions or are likely to be inherited from (due to object slicing concerns, covered in lesson 25.9 -- Object slicing).  
  
The cost of pass by value vs pass by reference Advanced Not all class types need to be passed by reference (such as std::string_view, which is normally passed by value). And you may be wondering why we don’t just pass everything by reference. In this section (which is optional reading), we discuss the cost of pass by value vs pass by reference, and refine our best practice as to when we should use each. First, we need to consider the cost of initializing the function parameter. With pass by value, initialization means making a copy. The cost of copying an object is generally proportional to two things:  
  
The size of the object. Objects that use more memory take more time to copy.  
  
Any additional setup costs. Some class types do additional setup when they are instantiated (e.g. such as opening a file or database, or allocating a certain amount of dynamic memory to hold an object of a variable size). These setup costs must be paid each time an object is copied.  
  
On the other hand, binding a reference to an object is always fast (about the same speed as copying a fundamental type). Second, we need to consider the cost of using the function parameter. When setting up a function call, the compiler may be able to optimize by placing a reference or copy of a passed-by-value argument (if it is small in size) into a CPU register (which is fast to access) rather than into RAM (which is slower to access).  
  
Each time a value parameter is used, the running program can directly access the storage location (CPU register or RAM) of the copied argument. However, when a reference parameter is used, there is usually an extra step. The running program must first directly access the storage location (CPU register or RAM) allocated to the reference, in order to determine which object is being referenced. Only then can it access the storage location of the referenced object (in RAM). Therefore, each use of a value parameter is a single CPU register or RAM access, whereas each use of a reference parameter is a single CPU register or RAM access plus a second RAM access. Third, the compiler can sometimes optimize code that uses pass by value more effectively than code that uses pass by reference. In particular, optimizers have to be conservative when there is any chance of aliasing (when two or more pointers or references can access the same object). Because pass by value results in the copy of argument values, there is no chance for aliasing to occur, allowing optimizers to be more aggressive. We can now answer these question of why we don’t pass everything by reference:  
  
For objects that are cheap to copy, the cost of copying is similar to the cost of binding, but accessing the objects is faster and the compiler is likely to be able to optimize better.  
  
For objects that are expensive to copy, the cost of the copy dominates other performance considerations.  
  
The last question then is, how do we define “cheap to copy”? There is no absolute answer here, as this varies by compiler, use case, and architecture. However, we can formulate a good rule of thumb: An object is cheap to copy if it uses 2 or fewer “words” of memory (where a “word” is approximated by the size of a memory address) and it has no setup costs.  
  
The following program defines a function-like macro that can be used to determine if a type (or object) is cheap to copy accordingly: #include <iostream>  
  
// Function-like macro that evaluates to true if the type (or object) is equal to or smaller than // the size of two memory addresses #define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))  
  
struct S { double a; double b; double c; };  
  
int main() { std::cout << std::boolalpha; // print true or false rather than 1 or 0 std::cout << isSmall(int) << '\n'; // true  
  
double d {}; std::cout << isSmall(d) << '\n'; // true std::cout << isSmall(S) << '\n'; // false  
  
return 0; }  
  
As an aside… We use a preprocessor function-like macro here so that we can provide either an object OR a type name as a parameter (as C++ functions disallow passing types as a parameter).  
  
However, it can be hard to know whether a class type object has setup costs or not. It’s best to assume that most standard library classes have setup costs, unless you know otherwise that they don’t.  
  
Tip An object of type T is cheap to copy if sizeof(T) <= 2 * sizeof(void*) and has no additional setup costs.  
  
For function parameters, prefer std::string_view over const std::string& in most cases One question that comes up often in modern C++: when writing a function that has a string parameter, should the type of the parameter be const std::string& or std::string_view? In most cases, std::string_view is the better choice, as it can handle a wider range of argument types efficiently. A std::string_view parameter also allows the caller to pass in a substring without having to copy that substring into its own string first.  
  
void doSomething(const std::string&); void doSomething(std::string_view); // prefer this in most cases There are a few cases where using a const std::string& parameter may be more appropriate:  
  
If you’re using C++14 or older, std::string_view isn’t available.  
  
If your function needs to call some other function that takes a C-style string or std::string parameter, then const std::string& may be a better choice, as std::string_view is not guaranteed to be null-terminated (something that C-style string functions expect) and does not efficiently convert back to a std::string.  
  
Best practice Prefer passing strings using std::string_view (by value) instead of const std::string&, unless your function calls other functions that require C-style strings or std::string parameters.  
  
Why std::string_view parameters are more efficient than const std::string& Advanced In C++, a string argument will typically be a std::string, a std::string_view, or a C-style string/string literal. As reminders:  
  
If the type of an argument does not match the type of the corresponding parameter, the compiler will try to implicitly convert the argument to match the type of the parameter.  
  
Converting a value creates a temporary object of the converted type.  
  
Creating (or copying) a std::string_view is inexpensive, as std::string_view does not make a copy of the string it is viewing.  
  
Creating (or copying) a std::string can be expensive, as each std::string object makes a copy of the string.  
  
Here’s a table showing what happens when we try to pass each type:  
  
Argument Type std::string_view parameter const std::string& parameter   
  
std::string Inexpensive conversion Inexpensive reference binding   
  
std::string_view Inexpensive copy Expensive explicit conversion to std::string   
  
C-style string / literal Inexpensive conversion Expensive conversion   
  
With a std::string_view value parameter:  
  
If we pass in a std::string argument, the compiler will convert the std::string to a std::string_view, which is inexpensive, so this is fine.  
  
If we pass in a std::string_view argument, the compiler will copy the argument into the parameter, which is inexpensive, so this is fine.  
  
If we pass in a C-style string or string literal, the compiler will convert these to a std::string_view, which is inexpensive, so this is fine.  
  
As you can see, std::string_view handles all three cases inexpensively. With a const std::string& reference parameter:  
  
If we pass in a std::string argument, the parameter will reference bind to the argument, which is inexpensive, so this is fine.  
  
If we pass in a std::string_view argument, the compiler will refuse to do an implicit conversion, and produce a compilation error. We can use static_cast to do an explicit conversion (to std::string), but this conversion is expensive (since std::string will make a copy of the string being viewed). Once the conversion is done, the parameter will reference bind to the result, which is inexpensive. But we’ve made an expensive copy to do the conversion, so this isn’t great.  
  
If we pass in a C-style string or string literal, the compiler will implicitly convert this to a std::string, which is expensive. So this isn’t great either.  
  
Thus, a const std::string& parameter only handles std::string arguments inexpensively. The same, in code form: #include <iostream> #include <string> #include <string_view>  
  
void printSV(std::string_view sv) { std::cout << sv << '\n'; }  
  
void printS(const std::string& s) { std::cout << s << '\n'; }  
  
int main() { std::string s{ "Hello, world" }; std::string_view sv { s };  
  
// Pass to `std::string_view` parameter printSV(s); // ok: inexpensive conversion from std::string to std::string_view printSV(sv); // ok: inexpensive copy of std::string_view printSV("Hello, world"); // ok: inexpensive conversion of C-style string literal to std::string_view  
  
// pass to `const std::string&` parameter printS(s); // ok: inexpensive bind to std::string argument printS(sv); // compile error: cannot implicit convert std::string_view to std::string printS(static_cast<std::string>(sv)); // bad: expensive creation of std::string temporary printS("Hello, world"); // bad: expensive creation of std::string temporary  
  
return 0; } Additionally, we need to consider the cost of accessing the parameter inside the function. Because a std::string_view parameter is a normal object, the string being viewed can be accessed directly. Accessing a std::string& parameter requires an additional step to get to the referenced object before the string can be accessed. Finally, if we want to pass in a substring of an existing string (of any type), it is comparatively cheap to create a std::string_view substring, which can then be cheaply passed to a std::string_view parameter. In comparison, passing a substring to a const std::string& is more expensive, as the substring must at some point be copied into the std::string that the reference parameter binds to.  
  
Next lesson  
  
12.7Introduction to pointers  
  
Back to table of contents  
  
Previous lesson  
  
12.5Pass by lvalue reference  
  
Previous Post13.11 — Struct miscellany  
  
Next Post12.13 — In and out parameters  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
46 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```

Document 7
```
Navigate  
  
12.8 — Null pointers Table of contents 12.6 — Pass by const lvalue reference  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.8 — Null pointers Table of contents 12.6 — Pass by const lvalue reference  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.7 — Introduction to pointers  
  
Alex  
  
July 10, 2007, 6:52 pm PDT February 7, 2025  
  
Pointers are one of C++’s historical boogeymen, and a place where many aspiring C++ learners have gotten stuck. However, as you’ll see shortly, pointers are nothing to be scared of. In fact, pointers behave a lot like lvalue references. But before we explain that further, let’s do some setup.  
  
Related content If you’re rusty or not familiar with lvalue references, now would be a good time to review them. We cover lvalue references in lessons 12.3 -- Lvalue references, 12.4 -- Lvalue references to const, and 12.5 -- Pass by lvalue reference.  
  
Consider a normal variable, like this one: char x {}; // chars use 1 byte of memory Simplifying a bit, when the code generated for this definition is executed, a piece of memory from RAM will be assigned to this object. For the sake of example, let’s say that the variable x is assigned memory address 140. Whenever we use variable x in an expression or statement, the program will go to memory address 140 to access the value stored there. The nice thing about variables is that we don’t need to worry about what specific memory addresses are assigned, or how many bytes are required to store the object’s value. We just refer to the variable by its given identifier, and the compiler translates this name into the appropriately assigned memory address. The compiler takes care of all the addressing.  
  
This is also true with references: int main() { char x {}; // assume this is assigned memory address 140 char& ref { x }; // ref is an lvalue reference to x (when used with a type, & means lvalue reference)  
  
return 0; } Because ref acts as an alias for x, whenever we use ref, the program will go to memory address 140 to access the value. Again the compiler takes care of the addressing, so that we don’t have to think about it. The address-of operator (&) Although the memory addresses used by variables aren’t exposed to us by default, we do have access to this information. The address-of operator (&) returns the memory address of its operand. This is pretty straightforward: #include <iostream>  
  
int main() { int x{ 5 }; std::cout << x << '\n'; // print the value of variable x std::cout << &x << '\n'; // print the memory address of variable x  
  
return 0; } On the author’s machine, the above program printed: 5 0027FEA0  
  
In the above example, we use the address-of operator (&) to retrieve the address assigned to variable x and print that address to the console. Memory addresses are typically printed as hexadecimal values (we covered hex in lesson 5.3 -- Numeral systems (decimal, binary, hexadecimal, and octal)), often without the 0x prefix.  
  
For objects that use more than one byte of memory, address-of will return the memory address of the first byte used by the object.  
  
Tip The & symbol tends to cause confusion because it has different meanings depending on context:  
  
When following a type name, & denotes an lvalue reference: int& ref.  
  
When used in a unary context in an expression, & is the address-of operator: std::cout << &x.  
  
When used in a binary context in an expression, & is the Bitwise AND operator: std::cout << x & y.  
  
The dereference operator (*) Getting the address of a variable isn’t very useful by itself. The most useful thing we can do with an address is access the value stored at that address. The dereference operator (*) (also occasionally called the indirection operator) returns the value at a given memory address as an lvalue: #include <iostream>  
  
int main() { int x{ 5 }; std::cout << x << '\n'; // print the value of variable x std::cout << &x << '\n'; // print the memory address of variable x  
  
std::cout << *(&x) << '\n'; // print the value at the memory address of variable x (parentheses not required, but make it easier to read)  
  
return 0; } On the author’s machine, the above program printed: 5 0027FEA0 5  
  
This program is pretty simple. First we declare a variable x and print its value. Then we print the address of variable x. Finally, we use the dereference operator to get the value at the memory address of variable x (which is just the value of x), which we print to the console.  
  
Key insight Given a memory address, we can use the dereference operator (*) to get the value at that address (as an lvalue). The address-of operator (&) and dereference operator (*) work as opposites: address-of gets the address of an object, and dereference gets the object at an address.  
  
Tip Although the dereference operator looks just like the multiplication operator, you can distinguish them because the dereference operator is unary, whereas the multiplication operator is binary.  
  
Getting the memory address of a variable and then immediately dereferencing that address to get a value isn’t that useful either (after all, we can just use the variable to access the value). But now that we have the address-of operator (&) and dereference operator (*) added to our toolkits, we’re ready to talk about pointers. Pointers A pointer is an object that holds a memory address (typically of another variable) as its value. This allows us to store the address of some other object to use later.  
  
As an aside… In modern C++, the pointers we are talking about here are sometimes called “raw pointers” or “dumb pointers”, to help differentiate them from “smart pointers” that were introduced into the language more recently. We cover smart pointers in chapter 22.  
  
A type that specifies a pointer (e.g. int*) is called a pointer type. Much like reference types are declared using an ampersand (&) character, pointer types are declared using an asterisk (*): int; // a normal int int&; // an lvalue reference to an int value  
  
int*; // a pointer to an int value (holds the address of an integer value) To create a pointer variable, we simply define a variable with a pointer type:  
  
int main() { int x { 5 }; // normal variable int& ref { x }; // a reference to an integer (bound to x)  
  
int* ptr; // a pointer to an integer  
  
return 0; } Note that this asterisk is part of the declaration syntax for pointers, not a use of the dereference operator.  
  
Best practice When declaring a pointer type, place the asterisk next to the type name.  
  
Warning Although you generally should not declare multiple variables on a single line, if you do, the asterisk has to be included with each variable. int* ptr1, ptr2; // incorrect: ptr1 is a pointer to an int, but ptr2 is just a plain int! int* ptr3, * ptr4; // correct: ptr3 and ptr4 are both pointers to an int Although this is sometimes used as an argument to not place the asterisk with the type name (instead placing it next to the variable name), it’s a better argument for avoiding defining multiple variables in the same statement.  
  
Pointer initialization Like normal variables, pointers are not initialized by default. A pointer that has not been initialized is sometimes called a wild pointer. Wild pointers contain a garbage address, and dereferencing a wild pointer will result in undefined behavior. Because of this, you should always initialize your pointers to a known value.  
  
Best practice Always initialize your pointers.  
  
int main() { int x{ 5 };  
  
int* ptr; // an uninitialized pointer (holds a garbage address) int* ptr2{}; // a null pointer (we'll discuss these in the next lesson) int* ptr3{ &x }; // a pointer initialized with the address of variable x  
  
return 0; } Since pointers hold addresses, when we initialize or assign a value to a pointer, that value has to be an address. Typically, pointers are used to hold the address of another variable (which we can get using the address-of operator (&)). Once we have a pointer holding the address of another object, we can then use the dereference operator (*) to access the value at that address. For example: #include <iostream>  
  
int main() { int x{ 5 }; std::cout << x << '\n'; // print the value of variable x  
  
int* ptr{ &x }; // ptr holds the address of x std::cout << *ptr << '\n'; // use dereference operator to print the value at the address that ptr is holding (which is x's address)  
  
return 0; } This prints: 5 5  
  
Conceptually, you can think of the above snippet like this:  
  
This is where pointers get their name from -- ptr is holding the address of x, so we say that ptr is “pointing to” x.  
  
Author’s note A note on pointer nomenclature: “X pointer” (where X is some type) is a commonly used shorthand for “pointer to an X”. So when we say, “an integer pointer”, we really mean “a pointer to an integer”. This understanding will be valuable when we talk about const pointers.  
  
Much like the type of a reference has to match the type of object being referred to, the type of the pointer has to match the type of the object being pointed to: int main() { int i{ 5 }; double d{ 7.0 };  
  
int* iPtr{ &i }; // ok: a pointer to an int can point to an int object int* iPtr2 { &d }; // not okay: a pointer to an int can't point to a double object double* dPtr{ &d }; // ok: a pointer to a double can point to a double object double* dPtr2{ &i }; // not okay: a pointer to a double can't point to an int object  
  
return 0; } With one exception that we’ll discuss next lesson, initializing a pointer with a literal value is disallowed: int* ptr{ 5 }; // not okay int* ptr{ 0x0012FF7C }; // not okay, 0x0012FF7C is treated as an integer literal Pointers and assignment We can use assignment with pointers in two different ways:  
  
To change what the pointer is pointing at (by assigning the pointer a new address)  
  
To change the value being pointed at (by assigning the dereferenced pointer a new value)  
  
First, let’s look at a case where a pointer is changed to point at a different object:  
  
#include <iostream>  
  
int main() { int x{ 5 }; int* ptr{ &x }; // ptr initialized to point at x  
  
std::cout << *ptr << '\n'; // print the value at the address being pointed to (x's address)  
  
int y{ 6 }; ptr = &y; // // change ptr to point at y  
  
std::cout << *ptr << '\n'; // print the value at the address being pointed to (y's address)  
  
return 0; } The above prints: 5 6  
  
In the above example, we define pointer ptr, initialize it with the address of x, and dereference the pointer to print the value being pointed to (5). We then use the assignment operator to change the address that ptr is holding to the address of y. We then dereference the pointer again to print the value being pointed to (which is now 6). Now let’s look at how we can also use a pointer to change the value being pointed at: #include <iostream>  
  
int main() { int x{ 5 }; int* ptr{ &x }; // initialize ptr with address of variable x  
  
std::cout << x << '\n'; // print x's value std::cout << *ptr << '\n'; // print the value at the address that ptr is holding (x's address)  
  
*ptr = 6; // The object at the address held by ptr (x) assigned value 6 (note that ptr is dereferenced here)  
  
std::cout << x << '\n'; std::cout << *ptr << '\n'; // print the value at the address that ptr is holding (x's address)  
  
return 0; } This program prints: 5 5 6 6  
  
In this example, we define pointer ptr, initialize it with the address of x, and then print the value of both x and *ptr (5). Because *ptr returns an lvalue, we can use this on the left hand side of an assignment statement, which we do to change the value being pointed at by ptr to 6. We then print the value of both x and *ptr again to show that the value has been updated as expected.  
  
Key insight When we use a pointer without a dereference (ptr), we are accessing the address held by the pointer. Modifying this (ptr = &y) changes what the pointer is pointing at. When we dereference a pointer (*ptr), we are accessing the object being pointed at. Modifying this (*ptr = 6;) changes the value of the object being pointed at.  
  
Pointers behave much like lvalue references Pointers and lvalue references behave similarly. Consider the following program:  
  
#include <iostream>  
  
int main() { int x{ 5 }; int& ref { x }; // get a reference to x int* ptr { &x }; // get a pointer to x  
  
std::cout << x; std::cout << ref; // use the reference to print x's value (5) std::cout << *ptr << '\n'; // use the pointer to print x's value (5)  
  
ref = 6; // use the reference to change the value of x std::cout << x; std::cout << ref; // use the reference to print x's value (6) std::cout << *ptr << '\n'; // use the pointer to print x's value (6)  
  
*ptr = 7; // use the pointer to change the value of x std::cout << x; std::cout << ref; // use the reference to print x's value (7) std::cout << *ptr << '\n'; // use the pointer to print x's value (7)  
  
return 0; } This program prints: 555 666 777  
  
In the above program, we create a normal variable x with value 5, and then create an lvalue reference and a pointer to x. Next, we use the lvalue reference to change the value from 5 to 6, and show that we can access that updated value via all three methods. Finally, we use the dereferenced pointer to change the value from 6 to 7, and again show that we can access the updated value via all three methods. Thus, pointers and references both provide a way to indirectly access another object. The primary difference is that with pointers, we need to explicitly get the address to point at, and we have to explicitly dereference the pointer to get the value. With references, the address-of and dereference happens implicitly. There are some other differences between pointers and references worth mentioning:  
  
References must be initialized, pointers are not required to be initialized (but should be).  
  
References are not objects, pointers are.  
  
References can not be reseated (changed to reference something else), pointers can change what they are pointing at.  
  
References must always be bound to an object, pointers can point to nothing (we’ll see an example of this in the next lesson).  
  
References are “safe” (outside of dangling references), pointers are inherently dangerous (we’ll also discuss this in the next lesson).  
  
The address-of operator returns a pointer It’s worth noting that the address-of operator (&) doesn’t return the address of its operand as a literal (as C++ doesn’t support address literals). Instead, it returns a pointer to the operand (whose value is the address of the operand). In other words, given variable int x, &x returns an int* holding the address of x. We can see this in the following example: #include <iostream> #include <typeinfo>  
  
int main() { int x{ 4 }; std::cout << typeid(x).name() << '\n'; // print the type of x std::cout << typeid(&x).name() << '\n'; // print the type of &x  
  
return 0; } On Visual Studio, this printed: int int *  
  
With gcc, this printed i (int) and pi (pointer to int) instead. Because the result of typeid().name() is compiler-dependent, your compiler may print something different, but it will have the same meaning. The size of pointers The size of a pointer is dependent upon the architecture the executable is compiled for -- a 32-bit executable uses 32-bit memory addresses -- consequently, a pointer on a 32-bit machine is 32 bits (4 bytes). With a 64-bit executable, a pointer would be 64 bits (8 bytes). Note that this is true regardless of the size of the object being pointed to: #include <iostream>  
  
int main() // assume a 32-bit application { char* chPtr{}; // chars are 1 byte int* iPtr{}; // ints are usually 4 bytes long double* ldPtr{}; // long doubles are usually 8 or 12 bytes  
  
std::cout << sizeof(chPtr) << '\n'; // prints 4 std::cout << sizeof(iPtr) << '\n'; // prints 4 std::cout << sizeof(ldPtr) << '\n'; // prints 4  
  
return 0; } The size of the pointer is always the same. This is because a pointer is just a memory address, and the number of bits needed to access a memory address is constant. Dangling pointers Much like a dangling reference, a dangling pointer is a pointer that is holding the address of an object that is no longer valid (e.g. because it has been destroyed). Dereferencing a dangling pointer (e.g. in order to print the value being pointed at) will lead to undefined behavior, as you are trying to access an object that is no longer valid. Perhaps surprisingly, the standard says “Any other use of an invalid pointer value has implementation-defined behavior”. This means that you can assign an invalid pointer a new value, such as nullptr (because this doesn’t use the invalid pointer’s value). However, any other operations that use the invalid pointer’s value (such as copying or incrementing an invalid pointer) will yield implementation-defined behavior.  
  
Key insight Dereferencing an invalid pointer will lead to undefined behavior. Any other use of an invalid pointer value is implementation-defined.  
  
Here’s an example of creating a dangling pointer: #include <iostream>  
  
int main() { int x{ 5 }; int* ptr{ &x };  
  
std::cout << *ptr << '\n'; // valid  
  
{ int y{ 6 }; ptr = &y;  
  
std::cout << *ptr << '\n'; // valid } // y goes out of scope, and ptr is now dangling  
  
std::cout << *ptr << '\n'; // undefined behavior from dereferencing a dangling pointer  
  
return 0; } The above program will probably print: 5 6 6  
  
But it may not, as the object that ptr was pointing at went out of scope and was destroyed at the end of the inner block, leaving ptr dangling. Conclusion Pointers are variables that hold a memory address. They can be dereferenced using the dereference operator (*) to retrieve the value at the address they are holding. Dereferencing a wild or dangling (or null) pointer will result in undefined behavior and will probably crash your application. Pointers are both more flexible than references and more dangerous. We’ll continue to explore this in the upcoming lessons. Quiz time Question #1 What values does this program print? Assume a short is 2 bytes, and a 32-bit machine. #include <iostream>  
  
int main() { short value{ 7 }; // &value = 0012FF60 short otherValue{ 3 }; // &otherValue = 0012FF54  
  
short* ptr{ &value };  
  
std::cout << &value << '\n'; std::cout << value << '\n'; std::cout << ptr << '\n'; std::cout << *ptr << '\n'; std::cout << '\n';  
  
*ptr = 9;  
  
std::cout << &value << '\n'; std::cout << value << '\n'; std::cout << ptr << '\n'; std::cout << *ptr << '\n'; std::cout << '\n';  
  
ptr = &otherValue;  
  
std::cout << &otherValue << '\n'; std::cout << otherValue << '\n'; std::cout << ptr << '\n'; std::cout << *ptr << '\n'; std::cout << '\n';  
  
std::cout << sizeof(ptr) << '\n'; std::cout << sizeof(*ptr) << '\n';  
  
return 0; } Show Solution  
  
0012FF60 7 0012FF60 7  
  
0012FF60 9 0012FF60 9  
  
0012FF54 3 0012FF54 3  
  
4 2  
  
A brief explanation about the 4 and the 2. A 32-bit machine means that pointers will be 32 bits in length, but sizeof() always prints the size in bytes. 32 bits is 4 bytes. Thus the sizeof(ptr) is 4. Because ptr is a pointer to a short, *ptr is a short. The size of a short in this example is 2 bytes. Thus the sizeof(*ptr) is 2.  
  
Question #2 What’s wrong with this snippet of code? int v1{ 45 }; int* ptr{ &v1 }; // initialize ptr with address of v1  
  
int v2 { 78 }; *ptr = &v2; // assign ptr to address of v2 Show Solution  
  
The last line of the above snippet doesn’t compile. Let’s examine this program in more detail. The first and fourth lines contain standard variable definitions, along with an initialization value. Nothing special here. On the second line, the asterisk is part of the pointer declaration syntax (not a dereference). So this line says, “assign the address of v1 to ptr“. This is fine, since pointers hold addresses. On line five, the asterisk represents a dereference, which is used to get the value that a pointer is pointing to. So this line says, “assign the address of v2 to the value pointed to by ptr“. The value pointed to by ptr is an integer. So this assignment doesn’t make any sense -- you can’t assign an address to an integer! The fifth line should be: ptr = &v2; This correctly assigns the address of v2 to the pointer.  
  
Next lesson  
  
12.8Null pointers  
  
Back to table of contents  
  
Previous lesson  
  
12.6Pass by const lvalue reference  
  
Previous PostA PHP script to unzip files with file overwriting  
  
Next Post17.8 — C-style array decay  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
542 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```

Document 8
```
Navigate  
  
12.9 — Pointers and const Table of contents 12.7 — Introduction to pointers  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.9 — Pointers and const Table of contents 12.7 — Introduction to pointers  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.8 — Null pointers  
  
Alex  
  
August 12, 2015, 12:53 pm PDT February 5, 2025  
  
In the previous lesson (12.7 -- Introduction to pointers), we covered the basics of pointers, which are objects that hold the address of another object. This address can be dereferenced using the dereference operator (*) to get the object at that address: #include <iostream>  
  
int main() { int x{ 5 }; std::cout << x << '\n'; // print the value of variable x  
  
int* ptr{ &x }; // ptr holds the address of x std::cout << *ptr << '\n'; // use dereference operator to print the value of the object at the address that ptr is holding (which is x's address)  
  
return 0; } The above example prints: 5 5  
  
In the prior lesson, we also noted that pointers do not need to point to anything. In this lesson, we’ll explore such pointers (and the various implications of pointing to nothing) further. Null pointers Besides a memory address, there is one additional value that a pointer can hold: a null value. A null value (often shortened to null) is a special value that means something has no value. When a pointer is holding a null value, it means the pointer is not pointing at anything. Such a pointer is called a null pointer. The easiest way to create a null pointer is to use value initialization: int main() { int* ptr {}; // ptr is now a null pointer, and is not holding an address  
  
return 0; }  
  
Best practice Value initialize your pointers (to be null pointers) if you are not initializing them with the address of a valid object.  
  
Because we can use assignment to change what a pointer is pointing at, a pointer that is initially set to null can later be changed to point at a valid object:  
  
#include <iostream>  
  
int main() { int* ptr {}; // ptr is a null pointer, and is not holding an address  
  
int x { 5 }; ptr = &x; // ptr now pointing at object x (no longer a null pointer)  
  
std::cout << *ptr << '\n'; // print value of x through dereferenced ptr  
  
return 0; } The nullptr keyword Much like the keywords true and false represent Boolean literal values, the nullptr keyword represents a null pointer literal. We can use nullptr to explicitly initialize or assign a pointer a null value. int main() { int* ptr { nullptr }; // can use nullptr to initialize a pointer to be a null pointer  
  
int value { 5 }; int* ptr2 { &value }; // ptr2 is a valid pointer ptr2 = nullptr; // Can assign nullptr to make the pointer a null pointer  
  
someFunction(nullptr); // we can also pass nullptr to a function that has a pointer parameter  
  
return 0; } In the above example, we use assignment to set the value of ptr2 to nullptr, making ptr2 a null pointer.  
  
Best practice Use nullptr when you need a null pointer literal for initialization, assignment, or passing a null pointer to a function.  
  
Dereferencing a null pointer results in undefined behavior Much like dereferencing a dangling (or wild) pointer leads to undefined behavior, dereferencing a null pointer also leads to undefined behavior. In most cases, it will crash your application. The following program illustrates this, and will probably crash or terminate your application abnormally when you run it (go ahead, try it, you won’t harm your machine):  
  
#include <iostream>  
  
int main() { int* ptr {}; // Create a null pointer std::cout << *ptr << '\n'; // Dereference the null pointer  
  
return 0; } Conceptually, this makes sense. Dereferencing a pointer means “go to the address the pointer is pointing at and access the value there”. A null pointer holds a null value, which semantically means the pointer is not pointing at anything. So what value would it access? Accidentally dereferencing null and dangling pointers is one of the most common mistakes C++ programmers make, and is probably the most common reason that C++ programs crash in practice.  
  
Warning Whenever you are using pointers, you’ll need to be extra careful that your code isn’t dereferencing null or dangling pointers, as this will cause undefined behavior (probably an application crash).  
  
Checking for null pointers Much like we can use a conditional to test Boolean values for true or false, we can use a conditional to test whether a pointer has value nullptr or not: #include <iostream>  
  
int main() { int x { 5 }; int* ptr { &x };  
  
if (ptr == nullptr) // explicit test for equivalence std::cout << "ptr is null\n"; else std::cout << "ptr is non-null\n";  
  
int* nullPtr {}; std::cout << "nullPtr is " << (nullPtr==nullptr ? "null\n" : "non-null\n"); // explicit test for equivalence  
  
return 0; } The above program prints: ptr is non-null nullPtr is null  
  
In lesson 4.9 -- Boolean values, we noted that integral values will implicitly convert into Boolean values: an integral value of 0 converts to Boolean value false, and any other integral value converts to Boolean value true.  
  
Similarly, pointers will also implicitly convert to Boolean values: a null pointer converts to Boolean value false, and a non-null pointer converts to Boolean value true. This allows us to skip explicitly testing for nullptr and just use the implicit conversion to Boolean to test whether a pointer is a null pointer. The following program is equivalent to the prior one: #include <iostream>  
  
int main() { int x { 5 }; int* ptr { &x };  
  
// pointers convert to Boolean false if they are null, and Boolean true if they are non-null if (ptr) // implicit conversion to Boolean std::cout << "ptr is non-null\n"; else std::cout << "ptr is null\n";  
  
int* nullPtr {}; std::cout << "nullPtr is " << (nullPtr ? "non-null\n" : "null\n"); // implicit conversion to Boolean  
  
return 0; }  
  
Warning Conditionals can only be used to differentiate null pointers from non-null pointers. There is no convenient way to determine whether a non-null pointer is pointing to a valid object or dangling (pointing to an invalid object).  
  
Use nullptr to avoid dangling pointers Above, we mentioned that dereferencing a pointer that is either null or dangling will result in undefined behavior. Therefore, we need to ensure our code does not do either of these things. We can easily avoid dereferencing a null pointer by using a conditional to ensure a pointer is non-null before trying to dereference it: // Assume ptr is some pointer that may or may not be a null pointer if (ptr) // if ptr is not a null pointer std::cout << *ptr << '\n'; // okay to dereference else // do something else that doesn't involve dereferencing ptr (print an error message, do nothing at all, etc...) But what about dangling pointers? Because there is no way to detect whether a pointer is dangling, we need to avoid having any dangling pointers in our program in the first place. We do that by ensuring that any pointer that is not pointing at a valid object is set to nullptr.  
  
That way, before dereferencing a pointer, we only need to test whether it is null -- if it is non-null, we assume the pointer is not dangling.  
  
Best practice A pointer should either hold the address of a valid object, or be set to nullptr. That way we only need to test pointers for null, and can assume any non-null pointer is valid.  
  
Unfortunately, avoiding dangling pointers isn’t always easy: when an object is destroyed, any pointers to that object will be left dangling. Such pointers are not nulled automatically! It is the programmer’s responsibility to ensure that all pointers to an object that has just been destroyed are properly set to nullptr.  
  
Warning When an object is destroyed, any pointers to the destroyed object will be left dangling (they will not be automatically set to nullptr). It is your responsibility to detect these cases and ensure those pointers are subsequently set to nullptr.  
  
Legacy null pointer literals: 0 and NULL In older code, you may see two other literal values used instead of nullptr. The first is the literal 0. In the context of a pointer, the literal 0 is specially defined to mean a null value, and is the only time you can assign an integral literal to a pointer.  
  
int main() { float* ptr { 0 }; // ptr is now a null pointer (for example only, don't do this)  
  
float* ptr2; // ptr2 is uninitialized ptr2 = 0; // ptr2 is now a null pointer (for example only, don't do this)  
  
return 0; }  
  
As an aside… On modern architectures, the address 0 is typically used to represent a null pointer. However, this value is not guaranteed by the C++ standard, and some architectures use other values. The literal 0, when used in the context of a null pointer, will be translated into whatever address the architecture uses to represent a null pointer.  
  
Additionally, there is a preprocessor macro named NULL (defined in the <cstddef> header). This macro is inherited from C, where it is commonly used to indicate a null pointer. #include <cstddef> // for NULL  
  
int main() { double* ptr { NULL }; // ptr is a null pointer  
  
double* ptr2; // ptr2 is uninitialized ptr2 = NULL; // ptr2 is now a null pointer  
  
return 0; } Both 0 and NULL should be avoided in modern C++ (use nullptr instead). We discuss why in lesson 12.11 -- Pass by address (part 2). Favor references over pointers whenever possible Pointers and references both give us the ability to access some other object indirectly. Pointers have the additional abilities of being able to change what they are pointing at, and to be pointed at null. However, these pointer abilities are also inherently dangerous: A null pointer runs the risk of being dereferenced, and the ability to change what a pointer is pointing at can make creating dangling pointers easier:  
  
int main() { int* ptr { };  
  
{ int x{ 5 }; ptr = &x; // assign the pointer to an object that will be destroyed (not possible with a reference) } // ptr is now dangling and pointing to invalid object  
  
if (ptr) // condition evaluates to true because ptr is not nullptr std::cout << *ptr; // undefined behavior  
  
return 0; } Since references can’t be bound to null, we don’t have to worry about null references. And because references must be bound to a valid object upon creation and then can not be reseated, dangling references are harder to create. Because they are safer, references should be favored over pointers, unless the additional capabilities provided by pointers are required.  
  
Best practice Favor references over pointers unless the additional capabilities provided by pointers are needed.  
  
A joke Did you hear the joke about the null pointer? That’s okay, you wouldn’t get dereference. Quiz time Question #1 1a) Can we determine whether a pointer is a null pointer or not? If so, how?  
  
Show Solution  
  
Yes, we can use a conditional (if statement or conditional operator) on the pointer. A pointer will convert to Boolean false if it is a null pointer, and true otherwise.  
  
1b) Can we determine whether a non-null pointer is valid or dangling? If so, how? Show Solution  
  
There is no easy way to determine this.  
  
Question #2 For each subitem, answer whether the action described will result in behavior that is: predictable, undefined, or possibly undefined. If the answer is “possibly undefined”, clarify when. Assume that any objects mentioned are of a type that the pointer can point to. 2a) Assigning the address of an object to a non-const pointer Show Solution  
  
Predictable. This just copies the address into the pointer object.  
  
2b) Assigning nullptr to a pointer Show Solution  
  
Predictable.  
  
2c) Dereferencing a pointer to a valid object Show Solution  
  
Predictable.  
  
2d) Dereferencing a dangling pointer Show Solution  
  
Undefined.  
  
2e) Dereferencing a null pointer Show Solution  
  
Undefined.  
  
2f) Dereferencing a non-null pointer Show Solution  
  
Possibly undefined, if the pointer is dangling.  
  
Question #3 Why should we set pointers that aren’t pointing to a valid object to ‘nullptr’? Show Solution  
  
We can not determine whether a non-null pointer is valid or dangling, and accessing a dangling pointer will result in undefined behavior. Therefore, we need to ensure that we do not have any dangling pointers in our program. If we ensure all pointers are either pointing to valid objects or set to nullptr, then we can use a conditional to test for null to ensure we don’t dereference a null pointer, and assume all non-null pointers are pointing to valid objects.  
  
Next lesson  
  
12.9Pointers and const  
  
Back to table of contents  
  
Previous lesson  
  
12.7Introduction to pointers  
  
Previous Post2.6 — Why functions are useful, and how to use them effectively  
  
Next Post17.9 — Pointer arithmetic and subscripting  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
222 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```

Document 9
```text
Navigate  
  
12.10 — Pass by address Table of contents 12.8 — Null pointers  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.10 — Pass by address Table of contents 12.8 — Null pointers  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.9 — Pointers and const  
  
Alex  
  
July 16, 2007, 1:40 pm PDT February 12, 2025  
  
Consider the following code snippet: int main() { int x { 5 }; int* ptr { &x }; // ptr is a normal (non-const) pointer  
  
int y { 6 }; ptr = &y; // we can point at another value  
  
*ptr = 7; // we can change the value at the address being held  
  
return 0; } With normal (non-const) pointers, we can change both what the pointer is pointing at (by assigning the pointer a new address to hold) or change the value at the address being held (by assigning a new value to the dereferenced pointer). However, what happens if the value we want to point at is const? int main() { const int x { 5 }; // x is now const int* ptr { &x }; // compile error: cannot convert from const int* to int*  
  
return 0; } The above snippet won’t compile -- we can’t set a normal pointer to point at a const variable. This makes sense: a const variable is one whose value cannot be changed. Allowing the programmer to set a non-const pointer to a const value would allow the programmer to dereference the pointer and change the value. That would violate the const-ness of the variable. Pointer to const value A pointer to a const value (sometimes called a pointer to const for short) is a (non-const) pointer that points to a constant value.  
  
To declare a pointer to a const value, use the const keyword before the pointer’s data type: int main() { const int x{ 5 }; const int* ptr { &x }; // okay: ptr is pointing to a "const int"  
  
*ptr = 6; // not allowed: we can't change a const value  
  
return 0; } In the above example, ptr points to a const int. Because the data type being pointed to is const, the value being pointed to can’t be changed. However, because a pointer to const is not const itself (it just points to a const value), we can change what the pointer is pointing at by assigning the pointer a new address: int main() { const int x{ 5 }; const int* ptr { &x }; // ptr points to const int x  
  
const int y{ 6 }; ptr = &y; // okay: ptr now points at const int y  
  
return 0; } Just like a reference to const, a pointer to const can point to non-const variables too. A pointer to const treats the value being pointed to as constant, regardless of whether the object at that address was initially defined as const or not: int main() { int x{ 5 }; // non-const const int* ptr { &x }; // ptr points to a "const int"  
  
*ptr = 6; // not allowed: ptr points to a "const int" so we can't change the value through ptr x = 6; // allowed: the value is still non-const when accessed through non-const identifier x  
  
return 0; } Const pointers We can also make a pointer itself constant. A const pointer is a pointer whose address can not be changed after initialization.  
  
To declare a const pointer, use the const keyword after the asterisk in the pointer declaration: int main() { int x{ 5 }; int* const ptr { &x }; // const after the asterisk means this is a const pointer  
  
return 0; } In the above case, ptr is a const pointer to a (non-const) int value. Just like a normal const variable, a const pointer must be initialized upon definition, and this value can’t be changed via assignment: int main() { int x{ 5 }; int y{ 6 };  
  
int* const ptr { &x }; // okay: the const pointer is initialized to the address of x ptr = &y; // error: once initialized, a const pointer can not be changed.  
  
return 0; } However, because the value being pointed to is non-const, it is possible to change the value being pointed to via dereferencing the const pointer: int main() { int x{ 5 }; int* const ptr { &x }; // ptr will always point to x  
  
*ptr = 6; // okay: the value being pointed to is non-const  
  
return 0; } Const pointer to a const value  
  
Finally, it is possible to declare a const pointer to a const value by using the const keyword both before the type and after the asterisk: int main() { int value { 5 }; const int* const ptr { &value }; // a const pointer to a const value  
  
return 0; } A const pointer to a const value can not have its address changed, nor can the value it is pointing to be changed through the pointer. It can only be dereferenced to get the value it is pointing at. Pointer and const recap To summarize, you only need to remember 4 rules, and they are pretty logical:  
  
A non-const pointer (e.g. int* ptr) can be assigned another address to change what it is pointing at.  
  
A const pointer (e.g. int* const ptr) always points to the same address, and this address can not be changed.  
  
A pointer to a non-const value (e.g. int* ptr) can change the value it is pointing to. These can not point to a const value.  
  
A pointer to a const value (e.g. const int* ptr) treats the value as const when accessed through the pointer, and thus can not change the value it is pointing to. These can be pointed to const or non-const l-values (but not r-values, which don’t have an address).  
  
Keeping the declaration syntax straight can be a bit challenging:  
  
A const before the asterisk (e.g. const int* ptr) is associated with the type being pointed to. Therefore, this is a pointer to a const value, and the value cannot be modified through the pointer.  
  
A const after the asterisk (e.g. int* const ptr) is associated with the pointer itself. Therefore, this pointer cannot be assigned a new address.  
  
int main() { int v{ 5 };  
  
int* ptr0 { &v }; // points to an "int" but is not const itself. We can modify the value or the address. const int* ptr1 { &v }; // points to a "const int" but is not const itself. We can only modify the address. int* const ptr2 { &v }; // points to an "int" and is const itself. We can only modify the value. const int* const ptr3 { &v }; // points to a "const int" and is const itself. We can't modify the value nor the address.  
  
// if the const is on the left side of the *, the const belongs to the value // if the const is on the right side of the *, the const belongs to the pointer  
  
return 0; }  
  
Next lesson  
  
12.10Pass by address  
  
Back to table of contents  
  
Previous lesson  
  
12.8Null pointers  
  
Previous Post19.1 — Dynamic memory allocation with new and delete  
  
Next Post12.3 — Lvalue references  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
217 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```

Document 10
```text
Navigate  
  
12.11 — Pass by address (part 2) Table of contents 12.9 — Pointers and const  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.11 — Pass by address (part 2) Table of contents 12.9 — Pointers and const  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.10 — Pass by address  
  
Alex  
  
July 25, 2007, 4:14 pm PDT February 13, 2025  
  
In prior lessons, we’ve covered two different ways to pass an argument to a function: pass by value (2.4 -- Introduction to function parameters and arguments) and pass by reference (12.5 -- Pass by lvalue reference). Here’s a sample program that shows a std::string object being passed by value and by reference: #include <iostream> #include <string>  
  
void printByValue(std::string val) // The function parameter is a copy of str { std::cout << val << '\n'; // print the value via the copy }  
  
void printByReference(const std::string& ref) // The function parameter is a reference that binds to str { std::cout << ref << '\n'; // print the value via the reference }  
  
int main() { std::string str{ "Hello, world!" };  
  
printByValue(str); // pass str by value, makes a copy of str printByReference(str); // pass str by reference, does not make a copy of str  
  
return 0; } When we pass argument str by value, the function parameter val receives a copy of the argument. Because the parameter is a copy of the argument, any changes to the val are made to the copy, not the original argument. When we pass argument str by reference, the reference parameter ref is bound to the actual argument. This avoids making a copy of the argument. Because our reference parameter is const, we are not allowed to change ref. But if ref were non-const, any changes we made to ref would change str. In both cases, the caller is providing the actual object (str) to be passed as an argument to the function call.  
  
Pass by address C++ provides a third way to pass values to a function, called pass by address. With pass by address, instead of providing an object as an argument, the caller provides an object’s address (via a pointer). This pointer (holding the address of the object) is copied into a pointer parameter of the called function (which now also holds the address of the object). The function can then dereference that pointer to access the object whose address was passed. Here’s a version of the above program that adds a pass by address variant: #include <iostream> #include <string>  
  
void printByValue(std::string val) // The function parameter is a copy of str { std::cout << val << '\n'; // print the value via the copy }  
  
void printByReference(const std::string& ref) // The function parameter is a reference that binds to str { std::cout << ref << '\n'; // print the value via the reference }  
  
void printByAddress(const std::string* ptr) // The function parameter is a pointer that holds the address of str { std::cout << *ptr << '\n'; // print the value via the dereferenced pointer }  
  
int main() { std::string str{ "Hello, world!" };  
  
printByValue(str); // pass str by value, makes a copy of str printByReference(str); // pass str by reference, does not make a copy of str printByAddress(&str); // pass str by address, does not make a copy of str  
  
return 0; } Note how similar all three of these versions are. Let’s explore the pass by address version in more detail. First, because we want our printByAddress() function to use pass by address, we’ve made our function parameter a pointer named ptr. Since printByAddress() will use ptr in a read-only manner, ptr is a pointer to a const value. void printByAddress(const std::string* ptr) { std::cout << *ptr << '\n'; // print the value via the dereferenced pointer } Inside the printByAddress() function, we dereference ptr parameter to access the value of the object being pointed to.  
  
Second, when the function is called, we can’t just pass in the str object -- we need to pass in the address of str. The easiest way to do that is to use the address-of operator (&) to get a pointer holding the address of str: printByAddress(&str); // use address-of operator (&) to get pointer holding address of str When this call is executed, &str will create a pointer holding the address of str. This address is then copied into function parameter ptr as part of the function call. Because ptr now holds the address of str, when the function dereferences ptr, it will get the value of str, which the function prints to the console. That’s it. Although we use the address-of operator in the above example to get the address of str, if we already had a pointer variable holding the address of str, we could use that instead: int main() { std::string str{ "Hello, world!" };  
  
printByValue(str); // pass str by value, makes a copy of str printByReference(str); // pass str by reference, does not make a copy of str printByAddress(&str); // pass str by address, does not make a copy of str  
  
std::string* ptr { &str }; // define a pointer variable holding the address of str printByAddress(ptr); // pass str by address, does not make a copy of str   
  
return 0; }  
  
Nomenclature When we pass the address of a variable as an argument using operator&, we say the variable is passed by address. When we have a pointer variable holding the address of an object, and we pass the pointer as an argument to a parameter of the same type, we say the object is passed by address, and the pointer is passed by value.  
  
Pass by address does not make a copy of the object being pointed to Consider the following statements: std::string str{ "Hello, world!" }; printByAddress(&str); // use address-of operator (&) to get pointer holding address of str As we noted in 12.5 -- Pass by lvalue reference, copying a std::string is expensive, so that’s something we want to avoid. When we pass a std::string by address, we’re not copying the actual std::string object -- we’re just copying the pointer (holding the address of the object) from the caller to the called function. Since an address is typically only 4 or 8 bytes, a pointer is only 4 or 8 bytes, so copying a pointer is always fast.  
  
Thus, just like pass by reference, pass by address is fast, and avoids making a copy of the argument object. Pass by address allows the function to modify the argument’s value When we pass an object by address, the function receives the address of the passed object, which it can access via dereferencing. Because this is the address of the actual argument object being passed (not a copy of the object), if the function parameter is a pointer to non-const, the function can modify the argument via the pointer parameter: #include <iostream>  
  
void changeValue(int* ptr) // note: ptr is a pointer to non-const in this example { *ptr = 6; // change the value to 6 }  
  
int main() { int x{ 5 };  
  
std::cout << "x = " << x << '\n';  
  
changeValue(&x); // we're passing the address of x to the function  
  
std::cout << "x = " << x << '\n';  
  
return 0; } This prints: x = 5 x = 6  
  
As you can see, the argument is modified and this modification persists even after changeValue() has finished running. If a function is not supposed to modify the object being passed in, the function parameter should be made a pointer-to-const:  
  
void changeValue(const int* ptr) // note: ptr is now a pointer to a const { *ptr = 6; // error: can not change const value } For many of the same reasons we typically don’t const regular (non-pointer, non-reference) function parameters (discussed in 5.1 -- Constant variables (named constants)), we also typically don’t const pointer function parameters. Let’s make two assertions:  
  
A const keyword used to make a pointer function parameter a const pointer provides little value (since it has no impact on the caller, and mostly serves as documentation that the pointer won’t change).  
  
A const keyword used to differentiate a pointer-to-const from a pointer-to-non-const that can modify the object passed in is significant (as the caller needs to know if the function could change the value of the argument).  
  
If we only use non-const pointer function parameters, then all uses of const are significant. As soon as we start using const for const pointer function parameters, then it becomes more difficult to determine whether a given use of const is significant or not. More importantly, it also makes it harder to notice pointer-to-non-const parameters. For example: void foo(const char* source, char* dest, int count); // Using non-const pointers, all consts are significant. void foo(const char* const source, char* const dest, int count); // Using const pointers, `dest` being a pointer-to-non-const may go unnoticed amongst the sea of spurious consts. In the former case, it’s easy to see that source is a pointer-to-const and dest is a pointer-to-non-const. In the latter case, it’s much harder to see that dest is a const-pointer-to-non-const, whose pointed-to object can be modified by the function!  
  
Best practice Prefer pointer-to-const function parameters over pointer-to-non-const function parameters, unless the function needs to modify the object passed in. Do not make function parameters const pointers unless there is some specific reason to do so.  
  
Null checking Now consider this fairly innocent looking program: #include <iostream>  
  
void print(int* ptr) { std::cout << *ptr << '\n'; }  
  
int main() { int x{ 5 }; print(&x);  
  
int* myPtr {}; print(myPtr);  
  
return 0; } When this program is run, it will print the value 5 and then most likely crash.  
  
In the call to print(myPtr), myPtr is a null pointer, so function parameter ptr will also be a null pointer. When this null pointer is dereferenced in the body of the function, undefined behavior results. When passing a parameter by address, care should be taken to ensure the pointer is not a null pointer before you dereference the value. One way to do that is to use a conditional statement: #include <iostream>  
  
void print(int* ptr) { if (ptr) // if ptr is not a null pointer { std::cout << *ptr << '\n'; } }  
  
int main() { int x{ 5 };  
  
print(&x); print(nullptr);  
  
return 0; } In the above program, we’re testing ptr to ensure it is not null before we dereference it. While this is fine for such a simple function, in more complicated functions this can result in redundant logic (testing if ptr is not null multiple times) or nesting of the primary logic of the function (if contained in a block). In most cases, it is more effective to do the opposite: test whether the function parameter is null as a precondition (9.6 -- Assert and static_assert) and handle the negative case immediately: #include <iostream>  
  
void print(int* ptr) { if (!ptr) // if ptr is a null pointer, early return back to the caller return;  
  
// if we reached this point, we can assume ptr is valid // so no more testing or nesting required  
  
std::cout << *ptr << '\n'; }  
  
int main() { int x{ 5 };  
  
print(&x); print(nullptr);  
  
return 0; } If a null pointer should never be passed to the function, an assert (which we covered in lesson 9.6 -- Assert and static_assert) can be used instead (or also) (as asserts are intended to document things that should never happen):  
  
#include <iostream> #include <cassert>  
  
void print(const int* ptr) // now a pointer to a const int { assert(ptr); // fail the program in debug mode if a null pointer is passed (since this should never happen)  
  
// (optionally) handle this as an error case in production mode so we don't crash if it does happen if (!ptr) return;  
  
std::cout << *ptr << '\n'; }  
  
int main() { int x{ 5 };  
  
print(&x); print(nullptr);  
  
return 0; } Prefer pass by (const) reference Note that function print() in the example above doesn’t handle null values very well -- it effectively just aborts the function. Given this, why allow a user to pass in a null value at all? Pass by reference has the same benefits as pass by address without the risk of inadvertently dereferencing a null pointer. Pass by const reference has a few other advantages over pass by address. First, because an object being passed by address must have an address, only lvalues can be passed by address (as rvalues don’t have addresses). Pass by const reference is more flexible, as it can accept lvalues and rvalues: #include <iostream>  
  
void printByValue(int val) // The function parameter is a copy of the argument { std::cout << val << '\n'; // print the value via the copy }  
  
void printByReference(const int& ref) // The function parameter is a reference that binds to the argument { std::cout << ref << '\n'; // print the value via the reference }  
  
void printByAddress(const int* ptr) // The function parameter is a pointer that holds the address of the argument { std::cout << *ptr << '\n'; // print the value via the dereferenced pointer }  
  
int main() { printByValue(5); // valid (but makes a copy) printByReference(5); // valid (because the parameter is a const reference) printByAddress(&5); // error: can't take address of r-value  
  
return 0; } Second, the syntax for pass by reference is natural, as we can just pass in literals or objects. With pass by address, our code ends up littered with ampersands (&) and asterisks (*).  
  
In modern C++, most things that can be done with pass by address are better accomplished through other methods. Follow this common maxim: “Pass by reference when you can, pass by address when you must”.  
  
Best practice Prefer pass by reference to pass by address unless you have a specific reason to use pass by address.  
  
Next lesson  
  
12.11Pass by address (part 2)  
  
Back to table of contents  
  
Previous lesson  
  
12.9Pointers and const  
  
Previous Post12.5 — Pass by lvalue reference  
  
Next Post7.9 — Inline functions and variables  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
327 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```

Document 11
```text
Navigate  
  
12.12 — Return by reference and return by address Table of contents 12.10 — Pass by address  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.12 — Return by reference and return by address Table of contents 12.10 — Pass by address  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.11 — Pass by address (part 2)  
  
Alex  
  
January 18, 2022, 10:15 am PST April 25, 2024  
  
This lesson is a continuation of 12.10 -- Pass by address. Pass by address for “optional” arguments One of the more common uses for pass by address is to allow a function to accept an “optional” argument. This is easier to illustrate by example than to describe: #include <iostream>  
  
void printIDNumber(const int *id=nullptr) { if (id) std::cout << "Your ID number is " << *id << ".\n"; else std::cout << "Your ID number is not known.\n"; }  
  
int main() { printIDNumber(); // we don't know the user's ID yet  
  
int userid { 34 }; printIDNumber(&userid); // we know the user's ID now  
  
return 0; } This example prints: Your ID number is not known. Your ID number is 34.  
  
In this program, the printIDNumber() function has one parameter that is passed by address and defaulted to nullptr. Inside main(), we call this function twice. The first call, we don’t know the user’s ID, so we call printIDNumber() without an argument. The id parameter defaults to nullptr, and the function prints Your ID number is not known.. For the second call, we now have a valid id, so we call printIDNumber(&userid). The id parameter receives the address of userid, so the function prints Your ID number is 34.. However, in many cases, function overloading is a better alternative to achieve the same result:  
  
#include <iostream>  
  
void printIDNumber() { std::cout << "Your ID is not known\n"; }  
  
void printIDNumber(int id) { std::cout << "Your ID is " << id << "\n"; }  
  
int main() { printIDNumber(); // we don't know the user's ID yet  
  
int userid { 34 }; printIDNumber(userid); // we know the user is 34  
  
printIDNumber(62); // now also works with rvalue arguments  
  
return 0; } This has a number of advantages: we no longer have to worry about null dereferences, and we can pass in literals or other rvalues as an argument. Changing what a pointer parameter points at When we pass an address to a function, that address is copied from the argument into the pointer parameter (which is fine, because copying an address is fast). Now consider the following program: #include <iostream>  
  
// [[maybe_unused]] gets rid of compiler warnings about ptr2 being set but not used void nullify([[maybe_unused]] int* ptr2) { ptr2 = nullptr; // Make the function parameter a null pointer }  
  
int main() { int x{ 5 }; int* ptr{ &x }; // ptr points to x  
  
std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");  
  
nullify(ptr);  
  
std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n"); return 0; } This program prints: ptr is non-null ptr is non-null  
  
As you can see, changing the address held by the pointer parameter had no impact on the address held by the argument (ptr still points at x). When function nullify() is called, ptr2 receives a copy of the address passed in (in this case, the address held by ptr, which is the address of x). When the function changes what ptr2 points at, this only affects the copy held by ptr2. So what if we want to allow a function to change what a pointer argument points to?  
  
Pass by address… by reference? Yup, it’s a thing. Just like we can pass a normal variable by reference, we can also pass pointers by reference. Here’s the same program as above with ptr2 changed to be a reference to an address: #include <iostream>  
  
void nullify(int*& refptr) // refptr is now a reference to a pointer { refptr = nullptr; // Make the function parameter a null pointer }  
  
int main() { int x{ 5 }; int* ptr{ &x }; // ptr points to x  
  
std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");  
  
nullify(ptr);  
  
std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n"); return 0; } This program prints: ptr is non-null ptr is null  
  
Because refptr is now a reference to a pointer, when ptr is passed as an argument, refptr is bound to ptr. This means any changes to refptr are made to ptr.  
  
As an aside… Because references to pointers are fairly uncommon, it can be easy to mix up the syntax (is it int*& or int&*?). The good news is that if you do it backwards, the compiler will error because you can’t have a pointer to a reference (because pointers must hold the address of an object, and references aren’t objects). Then you can switch it around.  
  
Why using 0 or NULL is no longer preferred (optional) In this subsection, we’ll explain why using 0 or NULL is no longer preferred.  
  
The literal 0 can be interpreted as either an integer literal, or as a null pointer literal. In certain cases, it can be ambiguous which one we intend -- and in some of those cases, the compiler may assume we mean one when we mean the other -- with unintended consequences to the behavior of our program. The definition of preprocessor macro NULL is not defined by the language standard. It can be defined as 0, 0L, ((void*)0), or something else entirely. In lesson 11.1 -- Introduction to function overloading, we discussed that functions can be overloaded (multiple functions can have the same name, so long as they can be differentiated by the number or type of parameters). The compiler can figure out which overloaded function you desire by the arguments passed in as part of the function call. When using 0 or NULL, this can cause problems: #include <iostream> #include <cstddef> // for NULL  
  
void print(int x) // this function accepts an integer { std::cout << "print(int): " << x << '\n'; }  
  
void print(int* ptr) // this function accepts an integer pointer { std::cout << "print(int*): " << (ptr ? "non-null\n" : "null\n"); }  
  
int main() { int x{ 5 }; int* ptr{ &x };  
  
print(ptr); // always calls print(int*) because ptr has type int* (good) print(0); // always calls print(int) because 0 is an integer literal (hopefully this is what we expected)  
  
print(NULL); // this statement could do any of the following: // call print(int) (Visual Studio does this) // call print(int*) // result in an ambiguous function call compilation error (gcc and Clang do this)  
  
print(nullptr); // always calls print(int*)  
  
return 0; } On the author’s machine (using Visual Studio), this prints:  
  
print(int*): non-null print(int): 0 print(int): 0 print(int*): null  
  
When passing integer value 0 as a parameter, the compiler will prefer print(int) over print(int*). This can lead to unexpected results when we intended print(int*) to be called with a null pointer argument. In the case where NULL is defined as value 0, print(NULL) will also call print(int), not print(int*) like you might expect for a null pointer literal. In cases where NULL is not defined as 0, other behavior might result, like a call to print(int*) or a compilation error. Using nullptr removes this ambiguity (it will always call print(int*)), since nullptr will only match a pointer type. std::nullptr_t (optional) Since nullptr can be differentiated from integer values in function overloads, it must have a different type. So what type is nullptr? The answer is that nullptr has type std::nullptr_t (defined in header <cstddef>). std::nullptr_t can only hold one value: nullptr! While this may seem kind of silly, it’s useful in one situation. If we want to write a function that accepts only a nullptr literal argument, we can make the parameter a std::nullptr_t. #include <iostream> #include <cstddef> // for std::nullptr_t  
  
void print(std::nullptr_t) { std::cout << "in print(std::nullptr_t)\n"; }  
  
void print(int*) { std::cout << "in print(int*)\n"; }  
  
int main() { print(nullptr); // calls print(std::nullptr_t)  
  
int x { 5 }; int* ptr { &x };  
  
print(ptr); // calls print(int*)  
  
ptr = nullptr; print(ptr); // calls print(int*) (since ptr has type int*)  
  
return 0; } In the above example, the function call print(nullptr) resolves to the function print(std::nullptr_t) over print(int*) because it doesn’t require a conversion.  
  
The one case that might be a little confusing is when we call print(ptr) when ptr is holding the value nullptr. Remember that function overloading matches on types, not values, and ptr has type int*. Therefore, print(int*) will be matched. print(std::nullptr_t) isn’t even in consideration in this case, as pointer types will not implicitly convert to a std::nullptr_t. You probably won’t ever need to use this, but it’s good to know, just in case. There is only pass by value Now that you understand the basic differences between passing by reference, address, and value, let’s get reductionist for a moment. :) While the compiler can often optimize references away entirely, there are cases where this is not possible and a reference is actually needed. References are normally implemented by the compiler using pointers. This means that behind the scenes, pass by reference is essentially just a pass by address.  
  
And in the previous lesson, we mentioned that pass by address just copies an address from the caller to the called function -- which is just passing an address by value. Therefore, we can conclude that C++ really passes everything by value! The properties of pass by address (and reference) come solely from the fact that we can dereference the passed address to change the argument, which we can not do with a normal value parameter!  
  
Next lesson  
  
12.12Return by reference and return by address  
  
Back to table of contents  
  
Previous lesson  
  
12.10Pass by address  
  
Previous Post12.2 — Value categories (lvalues and rvalues)  
  
Next Post13.1 — Introduction to program-defined (user-defined) types  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
123 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```

Document 12
```
Navigate  
  
12.13 — In and out parameters Table of contents 12.11 — Pass by address (part 2)  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.13 — In and out parameters Table of contents 12.11 — Pass by address (part 2)  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.12 — Return by reference and return by address  
  
Alex  
  
February 25, 2008, 9:04 pm PST January 3, 2025  
  
In previous lessons, we discussed that when passing an argument by value, a copy of the argument is made into the function parameter. For fundamental types (which are cheap to copy), this is fine. But copying is typically expensive for class types (such as std::string). We can avoid making an expensive copy by utilizing passing by (const) reference (or pass by address) instead. We encounter a similar situation when returning by value: a copy of the return value is passed back to the caller. If the return type of the function is a class type, this can be expensive. std::string returnByValue(); // returns a copy of a std::string (expensive) Return by reference In cases where we’re passing a class type back to the caller, we may (or may not) want to return by reference instead. Return by reference returns a reference that is bound to the object being returned, which avoids making a copy of the return value. To return by reference, we simply define the return value of the function to be a reference type: std::string& returnByReference(); // returns a reference to an existing std::string (cheap) const std::string& returnByReferenceToConst(); // returns a const reference to an existing std::string (cheap) Here is an academic program to demonstrate the mechanics of return by reference: #include <iostream> #include <string>  
  
const std::string& getProgramName() // returns a const reference { static const std::string s_programName { "Calculator" }; // has static duration, destroyed at end of program  
  
return s_programName; }  
  
int main() { std::cout << "This program is named " << getProgramName();  
  
return 0; } This program prints: This program is named Calculator  
  
Because getProgramName() returns a const reference, when the line return s_programName is executed, getProgramName() will return a const reference to s_programName (thus avoiding making a copy). That const reference can then be used by the caller to access the value of s_programName, which is printed.  
  
The object being returned by reference must exist after the function returns Using return by reference has one major caveat: the programmer must be sure that the object being referenced outlives the function returning the reference. Otherwise, the reference being returned will be left dangling (referencing an object that has been destroyed), and use of that reference will result in undefined behavior. In the program above, because s_programName has static duration, s_programName will exist until the end of the program. When main() accesses the returned reference, it is actually accessing s_programName, which is fine, because s_programName won’t be destroyed until later. Now let’s modify the above program to show what happens in the case where our function returns a dangling reference: #include <iostream> #include <string>  
  
const std::string& getProgramName() { const std::string programName { "Calculator" }; // now a non-static local variable, destroyed when function ends  
  
return programName; }  
  
int main() { std::cout << "This program is named " << getProgramName(); // undefined behavior  
  
return 0; } The result of this program is undefined. When getProgramName() returns, a reference bound to local variable programName is returned. Then, because programName is a local variable with automatic duration, programName is destroyed at the end of the function. That means the returned reference is now dangling, and use of programName in the main() function results in undefined behavior.  
  
Modern compilers will produce a warning or error if you try to return a local variable by reference (so the above program may not even compile), but compilers sometimes have trouble detecting more complicated cases.  
  
Warning Objects returned by reference must live beyond the scope of the function returning the reference, or a dangling reference will result. Never return a (non-static) local variable or temporary by reference.  
  
Lifetime extension doesn’t work across function boundaries Let’s take a look at an example where we return a temporary by reference: #include <iostream>  
  
const int& returnByConstReference() { return 5; // returns const reference to temporary object }  
  
int main() { const int& ref { returnByConstReference() };  
  
std::cout << ref; // undefined behavior  
  
return 0; } In the above program, returnByConstReference() is returning an integer literal, but the return type of the function is const int&. This results in the creation and return of a temporary reference bound to a temporary object holding value 5. This returned reference is copied into a temporary reference in the scope of the caller. The temporary object then goes out of scope, leaving the temporary reference in the scope of the caller dangling. By the time the temporary reference in the scope of the caller is bound to const reference variable ref (in main()), it is too late to extend the lifetime of the temporary object -- as it has already been destroyed. Thus ref is a dangling reference, and use of the value of ref will result in undefined behavior.  
  
Here’s a less obvious example that similarly doesn’t work: #include <iostream>  
  
const int& returnByConstReference(const int& ref) { return ref; }  
  
int main() { // case 1: direct binding const int& ref1 { 5 }; // extends lifetime std::cout << ref1 << '\n'; // okay  
  
// case 2: indirect binding const int& ref2 { returnByConstReference(5) }; // binds to dangling reference std::cout << ref2 << '\n'; // undefined behavior  
  
return 0; } In case 2, a temporary object is created to hold value 5, which function parameter ref binds to. The function just returns this reference back to the caller, which then uses the reference to initialize ref2. Because this is not a direct binding to the temporary object (as the refrence was bounced through a function), lifetime extension doesn’t apply. This leaves ref2 dangling, and its subsequent use is undefined behavior.  
  
Warning Reference lifetime extension does not work across function boundaries.  
  
Don’t return non-const static local variables by reference In the original example above, we returned a const static local variable by reference to illustrate the mechanics of return by reference in a simple way. However, returning non-const static local variables by reference is fairly non-idiomatic, and should generally be avoided. Here’s a simplified example that illustrates one such problem that can occur: #include <iostream> #include <string>  
  
const int& getNextId() { static int s_x{ 0 }; // note: variable is non-const ++s_x; // generate the next id return s_x; // and return a reference to it }  
  
int main() { const int& id1 { getNextId() }; // id1 is a reference const int& id2 { getNextId() }; // id2 is a reference  
  
std::cout << id1 << id2 << '\n';  
  
return 0; } This program prints: 22  
  
This happens because id1 and id2 are referencing the same object (the static variable s_x), so when anything (e.g. getNextId()) modifies that value, all references are now accessing the modified value.  
  
This above example can be fixed by making id1 and id2 normal variables (rather than references) so they save a copy of the return value rather than a reference to s_x.  
  
For advanced readers Here’s another example with a less obvious version of the same problem: #include <iostream> #include <string> #include <string_view>  
  
std::string& getName() { static std::string s_name{}; std::cout << "Enter a name: "; std::cin >> s_name; return s_name; }  
  
void printFirstAlphabetical(const std::string& s1, const std::string& s2) { if (s1 < s2) std::cout << s1 << " comes before " << s2 << '\n'; else std::cout << s2 << " comes before " << s1 << '\n'; }  
  
int main() { printFirstAlphabetical(getName(), getName());  
  
return 0; } Here’s the result from one run of this program: Enter a name: Dave Enter a name: Stan Stan comes before Stan  
  
In this example, getName() returns a reference to static local s_name. Initializing a const std::string& with a reference to s_name causes that std::string& to bind to s_name (not make a copy of it). Thus, both s1 and s2 end up viewing s_name (which was assigned the last name we entered). Note that if we use std::string_view parameters instead, the first std::string_view parameter will be invalidated when the underlying std::string is changed.  
  
Another issue that commonly occurs with programs that return a non-const static local by reference is that there is no standardized way to reset s_x back to the default state. Such programs must either use a non-conventional solution (e.g. a reset function parameter), or can only be reset by quitting and restarting the program.  
  
Best practice Avoid returning references to non-const local static variables.  
  
Returning a const reference to a const local static variable is sometimes done if the local variable being returned by reference is expensive to create and/or initialize (so we don’t have to recreate the variable every function call). But this is rare. Returning a const reference to a const global variable is also sometimes done as a way to encapsulate access to a global variable. We discuss this in lesson 7.8 -- Why (non-const) global variables are evil. When used intentionally and carefully, this is also okay. Assigning/initializing a normal variable with a returned reference makes a copy  
  
If a function returns a reference, and that reference is used to initialize or assign to a non-reference variable, the return value will be copied (as if it had been returned by value). #include <iostream> #include <string>  
  
const int& getNextId() { static int s_x{ 0 }; ++s_x; return s_x; }  
  
int main() { const int id1 { getNextId() }; // id1 is a normal variable now and receives a copy of the value returned by reference from getNextId() const int id2 { getNextId() }; // id2 is a normal variable now and receives a copy of the value returned by reference from getNextId()  
  
std::cout << id1 << id2 << '\n';  
  
return 0; } In the above example, getNextId() is returning a reference, but id1 and id2 are non-reference variables. In such a case, the value of the returned reference is copied into the normal variable. Thus, this program prints: 12  
  
Also note that if a program returns a dangling reference, the reference is left dangling before the copy is made, which will lead to undefined behavior: #include <iostream> #include <string>  
  
const std::string& getProgramName() // will return a const reference { const std::string programName{ "Calculator" };  
  
return programName; }  
  
int main() { std::string name { getProgramName() }; // makes a copy of a dangling reference std::cout << "This program is named " << name << '\n'; // undefined behavior  
  
return 0; } It’s okay to return reference parameters by reference There are quite a few cases where returning objects by reference makes sense, and we’ll encounter many of those in future lessons. However, there is one useful example that we can show now.  
  
If a parameter is passed into a function by reference, it’s safe to return that parameter by reference. This makes sense: in order to pass an argument to a function, the argument must exist in the scope of the caller. When the called function returns, that object must still exist in the scope of the caller. Here is a simple example of such a function: #include <iostream> #include <string>  
  
// Takes two std::string objects, returns the one that comes first alphabetically const std::string& firstAlphabetical(const std::string& a, const std::string& b) { return (a < b) ? a : b; // We can use operator< on std::string to determine which comes first alphabetically }  
  
int main() { std::string hello { "Hello" }; std::string world { "World" };  
  
std::cout << firstAlphabetical(hello, world) << '\n';  
  
return 0; } This prints: Hello  
  
In the above function, the caller passes in two std::string objects by const reference, and whichever of these strings comes first alphabetically is passed back by const reference. If we had used pass by value and return by value, we would have made up to 3 copies of std::string (one for each parameter, one for the return value). By using pass by reference/return by reference, we can avoid those copies. It’s okay for an rvalue passed by const reference to be returned by const reference  
  
When an argument for a const reference parameter is an rvalue, it’s still okay to return that parameter by const reference. This is because rvalues are not destroyed until the end of the full expression in which they are created. First, let’s look at this example: #include <iostream> #include <string>  
  
std::string getHello() { return "Hello"; // implicit conversion to std::string }  
  
int main() { const std::string s{ getHello() };  
  
std::cout << s;  
  
return 0; } In this case, getHello() returns a std::string by value, which is an rvalue. This rvalue is then used to initialize s. After the initialization of s, the expression in which the rvalue was created has finished evaluating, and the rvalue is destroyed. Now let’s take a look at this similar example: #include <iostream> #include <string>  
  
const std::string& foo(const std::string& s) { return s; }  
  
std::string getHello() { return "Hello"; // implicit conversion to std::string }  
  
int main() { const std::string s{ foo(getHello()) };  
  
std::cout << s;  
  
return 0; } The only difference in this case is that the rvalue is passed by const reference to foo() and then returned by const reference back to the caller before it is used to initialize s. Everything else works identically. We discuss a similar case in lesson 14.6 -- Access functions. The caller can modify values through the reference When an argument is passed to a function by non-const reference, the function can use the reference to modify the value of the argument. Similarly, when a non-const reference is returned from a function, the caller can use the reference to modify the value being returned. Here’s an illustrative example: #include <iostream>  
  
// takes two integers by non-const reference, and returns the greater by reference int& max(int& x, int& y) { return (x > y) ? x : y; }  
  
int main() { int a{ 5 }; int b{ 6 };  
  
max(a, b) = 7; // sets the greater of a or b to 7  
  
std::cout << a << b << '\n';  
  
return 0; } In the above program, max(a, b) calls the max() function with a and b as arguments. Reference parameter x binds to argument a, and reference parameter y binds to argument b. The function then determines which of x (5) and y (6) is greater. In this case, that’s y, so the function returns y (which is still bound to b) back to the caller. The caller then assigns the value 7 to this returned reference. Therefore, the expression max(a, b) = 7 effectively resolves to b = 7. This prints: 57  
  
Return by address Return by address works almost identically to return by reference, except a pointer to an object is returned instead of a reference to an object. Return by address has the same primary caveat as return by reference -- the object being returned by address must outlive the scope of the function returning the address, otherwise the caller will receive a dangling pointer. The major advantage of return by address over return by reference is that we can have the function return nullptr if there is no valid object to return. For example, let’s say we have a list of students that we want to search. If we find the student we are looking for in the list, we can return a pointer to the object representing the matching student. If we don’t find any students matching, we can return nullptr to indicate a matching student object was not found. The major disadvantage of return by address is that the caller has to remember to do a nullptr check before dereferencing the return value, otherwise a null pointer dereference may occur and undefined behavior will result. Because of this danger, return by reference should be preferred over return by address unless the ability to return “no object” is needed.  
  
Best practice Prefer return by reference over return by address unless the ability to return “no object” (using nullptr) is important.  
  
Related content If you need the ability to return “no object” or a value (rather than an object) 12.15 -- std::optional describes a good alternative.  
  
Related content See 5.9 -- std::string_view (part 2) for a quick guide on when to return std::string_view vs const std::string& .  
  
Next lesson  
  
12.13In and out parameters  
  
Back to table of contents  
  
Previous lesson  
  
12.11Pass by address (part 2)  
  
Previous Post20.5 — Ellipsis (and why to avoid them)  
  
Next Post28.1 — Input and output (I/O) streams  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
598 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```

Document 13
```
Navigate  
  
12.14 — Type deduction with pointers, references, and const Table of contents 12.12 — Return by reference and return by address  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.14 — Type deduction with pointers, references, and const Table of contents 12.12 — Return by reference and return by address  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.13 — In and out parameters  
  
Alex  
  
July 31, 2023, 11:22 am PDT December 9, 2024  
  
A function and its caller communicate with each other via two mechanisms: parameters and return values. When a function is called, the caller provides arguments, which the function receives via its parameters. These arguments can be passed by value, reference, or address. Typically, we’ll pass arguments by value or by const reference. But there are times when we may need to do otherwise. In parameters In most cases, a function parameter is used only to receive an input from the caller. Parameters that are used only for receiving input from the caller are sometimes called in parameters. #include <iostream>  
  
void print(int x) // x is an in parameter { std::cout << x << '\n'; }  
  
void print(const std::string& s) // s is an in parameter { std::cout << s << '\n'; }  
  
int main() { print(5); std::string s { "Hello, world!" }; print(s);  
  
return 0; } In-parameters are typically passed by value or by const reference. Out parameters A function argument passed by non-const reference (or by pointer-to-non-const) allows the function to modify the value of an object passed as an argument. This provides a way for a function to return data back to the caller in cases where using a return value is not sufficient for some reason.  
  
A function parameter that is used only for the purpose of returning information back to the caller is called an out parameter. For example: #include <cmath> // for std::sin() and std::cos() #include <iostream>  
  
// sinOut and cosOut are out parameters void getSinCos(double degrees, double& sinOut, double& cosOut) { // sin() and cos() take radians, not degrees, so we need to convert constexpr double pi { 3.14159265358979323846 }; // the value of pi double radians = degrees * pi / 180.0; sinOut = std::sin(radians); cosOut = std::cos(radians); }  
  
int main() { double sin { 0.0 }; double cos { 0.0 };  
  
double degrees{}; std::cout << "Enter the number of degrees: "; std::cin >> degrees;  
  
// getSinCos will return the sin and cos in variables sin and cos getSinCos(degrees, sin, cos);  
  
std::cout << "The sin is " << sin << '\n'; std::cout << "The cos is " << cos << '\n';  
  
return 0; } This function has one parameter degrees (whose argument is passed by value) as input, and “returns” two parameters (by reference) as output. We’ve named these out parameters with the suffix “out” to denote that they’re out parameters. This helps remind the caller that the initial value passed to these parameters doesn’t matter, and that we should expect them to be overwritten. By convention, output parameters are typically the rightmost parameters. Let’s explore how this works in more detail. First, the main function creates local variables sin and cos. Those are passed into function getSinCos() by reference (rather than by value). This means function getSinCos() has access to the actual sin and cos variables in main(), not just copies. getSinCos() accordingly assigns new values to sin and cos (through references sinOut and cosOut respectively), which overwrites the old values in sin and cos. Function main() then prints these updated values. If sin and cos had been passed by value instead of reference, getSinCos() would have changed copies of sin and cos, leading to any changes being discarded at the end of the function. But because sin and cos were passed by reference, any changes made to sin or cos (through the references) are persisted beyond the function. We can therefore use this mechanism to return values back to the caller.  
  
As an aside… This answer on StackOverflow is an interesting read that explains why non-const lvalue references are not allowed to bind to rvalues/temporary objects (due to implicit type conversion producing unexpected behavior when combined with out-parameters).  
  
Out parameters have an unnatural usage syntax Out-parameters, while functional, have a few downsides. First, the caller must instantiate (and initialize) objects and pass them as arguments, even if it doesn’t intend to use them. These objects must be able to be assigned to, which means they can’t be made const. Second, because the caller must pass in objects, these values can’t be used as temporaries, or easily used in a single expression. The following example shows both of these downsides:  
  
#include <iostream>  
  
int getByValue() { return 5; }  
  
void getByReference(int& x) { x = 5; }  
  
int main() { // return by value [[maybe_unused]] int x{ getByValue() }; // can use to initialize object std::cout << getByValue() << '\n'; // can use temporary return value in expression  
  
// return by out parameter int y{}; // must first allocate an assignable object getByReference(y); // then pass to function to assign the desired value std::cout << y << '\n'; // and only then can we use that value  
  
return 0; } As you can see, the syntax for using out-parameters is a bit unnatural. Out-parameters by reference don’t make it obvious the arguments will be modified When we assign a function’s return value to an object, it is clear that the value of the object is being modified: x = getByValue(); // obvious that x is being modified This is good, as it makes it clear that we should expect the value of x to change. However, let’s take a look at the function call to getSinCos() in the example above again:  
  
getSinCos(degrees, sin, cos); It is not clear from this function call that degrees is an in parameter, but sin and cos are out-parameters. If the caller does not realize that sin and cos will be modified, a semantic error will likely result. Using pass by address instead of pass by reference can in some case help make out-parameters more obvious by requiring the caller to pass in the address of objects as arguments. Consider the following example: void foo1(int x); // pass by value void foo2(int& x); // pass by reference void foo3(int* x); // pass by address  
  
int main() { int i{};  
  
foo1(i); // can't modify i foo2(i); // can modify i (not obvious) foo3(&i); // can modify i  
  
int *ptr { &i }; foo3(ptr); // can modify i (not obvious)  
  
return 0; } Notice that in the call to foo3(&i), we have to pass in &i rather than i, which helps make it clearer that we should expect i to be modified. However, this is not fool-proof, as foo3(ptr) allows foo3() to modify i and does not require the caller to take the address-of ptr. The caller may also think they can pass in nullptr or a null pointer as a valid argument when this is disallowed. And the function is now required to do null pointer checking and handling, which adds more complexity. This need for added null pointer handling often causes more issues than just sticking with pass by reference.  
  
For all of these reasons, out-parameters should be avoided unless no other good options exist.  
  
Best practice Avoid out-parameters (except in the rare case where no better options exist). Prefer pass by reference for non-optional out-parameters.  
  
In/out parameters In rare cases, a function will actually use the value of an out-parameter before overwriting its value. Such a parameter is called an in-out parameter. In-out-parameters work identically to out-parameters and have all the same challenges. When to pass by non-const reference If you’re going to pass by reference in order to avoid making a copy of the argument, you should almost always pass by const reference.  
  
Author’s note In the following examples, we will use Foo to represent some type that we care about. For now, you can imagine Foo as a type alias for a type of your choice (e.g. std::string).  
  
However, there are two primary cases where pass by non-const reference may be the better choice.  
  
First, use pass by non-const reference when a parameter is an in-out-parameter. Since we’re already passing in the object we need back out, it’s often more straightforward and performant to just modify that object. void someFcn(Foo& inout) { // modify inout }  
  
int main() { Foo foo{}; someFcn(foo); // foo modified after this call, may not be obvious  
  
return 0; } Giving the function a good name can help: void modifyFoo(Foo& inout) { // modify inout }  
  
int main() { Foo foo{}; modifyFoo(foo); // foo modified after this call, slightly more obvious  
  
return 0; } The alternative is to pass the object by value or const reference instead (as per usual) and return a new object by value, which the caller can then assign back to the original object: Foo someFcn(const Foo& in) { Foo foo { in }; // copy here // modify foo return foo; }  
  
int main() { Foo foo{}; foo = someFcn(foo); // makes it obvious foo is modified, but another copy made here  
  
return 0; } This has the benefit of using a more conventional return syntax, but requires making 2 extra copies (sometimes the compiler can optimize one of these copies away). Second, use pass by non-const reference when a function would otherwise return an object by value to the caller, but making a copy of that object is extremely expensive. Especially if the function is called many times in a performance-critical section of code.  
  
void generateExpensiveFoo(Foo& out) { // modify out }  
  
int main() { Foo foo{}; generateExpensiveFoo(foo); // foo modified after this call  
  
return 0; }  
  
For advanced readers The most common example of the above is when a function needs to fill a large C-style array or std::array with data, and the array has an expensive-to-copy element type. We discuss arrays in a future chapter.  
  
That said, objects are rarely so expensive to copy that resorting to non-conventional methods of returning those objects is worthwhile.  
  
Next lesson  
  
12.14Type deduction with pointers, references, and const  
  
Back to table of contents  
  
Previous lesson  
  
12.12Return by reference and return by address  
  
Previous Post12.6 — Pass by const lvalue reference  
  
Next Post15.4 — Introduction to destructors  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
83 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```

Document 14
```
Navigate  
  
12.15 — std::optional Table of contents 12.13 — In and out parameters  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.15 — std::optional Table of contents 12.13 — In and out parameters  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.14 — Type deduction with pointers, references, and const  
  
Alex  
  
February 2, 2022, 2:56 pm PST January 21, 2025  
  
In lesson 10.8 -- Type deduction for objects using the auto keyword, we discussed how the auto keyword can be used to have the compiler deduce the type of a variable from the initializer: int main() { int a { 5 }; auto b { a }; // b deduced as an int  
  
return 0; } We also noted that by default, type deduction will drop const from types: int main() { const double a { 7.8 }; // a has type const double auto b { a }; // b has type double (const dropped)  
  
constexpr double c { 7.8 }; // c has type const double (constexpr implicitly applies const) auto d { c }; // d has type double (const dropped)  
  
return 0; } Const (or constexpr) can be reapplied by adding the const (or constexpr) qualifier to the definition of the deduced type: int main() { double a { 7.8 }; // a has type double const auto b { a }; // b has type const double (const applied)  
  
constexpr double c { 7.8 }; // c has type const double (constexpr implicitly applies const) const auto d { c }; // d is const double (const dropped, const reapplied) constexpr auto e { c }; // e is constexpr double (const dropped, constexpr reapplied)  
  
return 0; } Type deduction drops references In addition to dropping const, type deduction will also drop references: #include <string>  
  
std::string& getRef(); // some function that returns a reference  
  
int main() { auto ref { getRef() }; // type deduced as std::string (not std::string&)  
  
return 0; } In the above example, variable ref is using type deduction. Although function getRef() returns a std::string&, the reference qualifier is dropped, so the type of ref is deduced as std::string.  
  
Just like with dropped const, if you want the deduced type to be a reference, you can reapply the reference at the point of definition: #include <string>  
  
std::string& getRef(); // some function that returns a reference  
  
int main() { auto ref1 { getRef() }; // std::string (reference dropped) auto& ref2 { getRef() }; // std::string& (reference dropped, reference reapplied)  
  
return 0; } Top-level const and low-level const A top-level const is a const qualifier that applies to an object itself. For example: const int x; // this const applies to x, so it is top-level int* const ptr; // this const applies to ptr, so it is top-level // references don't have a top-level const syntax, as they are implicitly top-level const In contrast, a low-level const is a const qualifier that applies to the object being referenced or pointed to: const int& ref; // this const applies to the object being referenced, so it is low-level const int* ptr; // this const applies to the object being pointed to, so it is low-level A reference to a const value is always a low-level const. A pointer can have a top-level, low-level, or both kinds of const:  
  
const int* const ptr; // the left const is low-level, the right const is top-level When we say that type deduction drops const qualifiers, it only drops top-level consts. Low-level consts are not dropped. We’ll see examples of this in just a moment. Type deduction and const references If the initializer is a reference to const, the reference is dropped first (and then reapplied if applicable), and then any top-level const is dropped from the result. #include <string>  
  
const std::string& getConstRef(); // some function that returns a reference to const  
  
int main() { auto ref1{ getConstRef() }; // std::string (reference dropped, then top-level const dropped from result)  
  
return 0; } In the above example, since getConstRef() returns a const std::string&, the reference is dropped first, leaving us with a const std::string. This const is now a top-level const, so it is also dropped, leaving the deduced type as std::string.  
  
Key insight Dropping a reference may change a low-level const to a top-level const: const std::string& is a low-level const, but dropping the reference yields const std::string, which is a top-level const.  
  
We can reapply a reference and/or const:  
  
#include <string>  
  
const std::string& getConstRef(); // some function that returns a const reference  
  
int main() { auto ref1{ getConstRef() }; // std::string (reference and top-level const dropped) const auto ref2{ getConstRef() }; // const std::string (reference dropped, const dropped, const reapplied)  
  
auto& ref3{ getConstRef() }; // const std::string& (reference dropped and reapplied, low-level const not dropped) const auto& ref4{ getConstRef() }; // const std::string& (reference dropped and reapplied, low-level const not dropped)  
  
return 0; } We covered the case for ref1 in the prior example. For ref2, this is similar to the ref1 case, except we’re reapplying the const qualifier, so the deduced type is const std::string. Things get more interesting with ref3. Normally the reference would be dropped first, but since we’ve reapplied the reference, it is not dropped. That means the type is still const std::string&. And since this const is a low-level const, it is not dropped. Thus the deduced type is const std::string&. The ref4 case works similarly to ref3, except we’ve reapplied the const qualifier as well. Since the type is already deduced as a reference to const, us reapplying const here is redundant. That said, using const here makes it explicitly clear that our result will be const (whereas in the ref3 case, the constness of the result is implicit and not obvious).  
  
Best practice If you want a const reference, reapply the const qualifier even when it’s not strictly necessary, as it makes your intent clear and helps prevent mistakes.  
  
What about constexpr references? Constexpr is not part of an expression’s type, so it is not deduced by auto.  
  
A reminder When defining a const reference (e.g. const int&), the const applies to the object being referenced, not the reference itself. When defining a constexpr reference to a const variable (e.g. constexpr const int&), we need to apply both constexpr (which applies to the reference) and const (which applies to the type being referenced). This is covered in lesson 12.4 -- Lvalue references to const.  
  
#include <string_view> #include <iostream>  
  
constexpr std::string_view hello { "Hello" }; // implicitly const  
  
constexpr const std::string_view& getConstRef() // function is constexpr, returns a const std::string_view& { return hello; }  
  
int main() { auto ref1{ getConstRef() }; // std::string_view (reference dropped and top-level const dropped) constexpr auto ref2{ getConstRef() }; // constexpr const std::string_view (reference dropped and top-level const dropped, constexpr applied, implicitly const)  
  
auto& ref3{ getConstRef() }; // const std::string_view& (reference reapplied, low-level const not dropped) constexpr const auto& ref4{ getConstRef() }; // constexpr const std::string_view& (reference reapplied, low-level const not dropped, constexpr applied)  
  
return 0; } Type deduction and pointers Unlike references, type deduction does not drop pointers: #include <string>  
  
std::string* getPtr(); // some function that returns a pointer  
  
int main() { auto ptr1{ getPtr() }; // std::string*  
  
return 0; } We can also use an asterisk in conjunction with pointer type deduction (auto*) to make it clearer that the deduced type is a pointer: #include <string>  
  
std::string* getPtr(); // some function that returns a pointer  
  
int main() { auto ptr1{ getPtr() }; // std::string* auto* ptr2{ getPtr() }; // std::string*  
  
return 0; }  
  
Key insight The reason that references are dropped during type deduction but pointers are not dropped is because references and pointers have different semantics. When we evaluate a reference, we’re really evaluating the object being referenced. Therefore, when deducing a type, it makes sense that we should deduce the type of the thing being referenced, not the reference itself. Also, since we deduce a non-reference, it’s really easy to make it a reference by using auto&. If type deduction were to deduce a reference instead, the syntax for removing a reference if we didn’t want it is much more complicated. On the other hand, pointers hold the address of an object. When we evaluate a pointer, we are evaluating the pointer, not the object being pointed to (if we want that, we can dereference the pointer). Therefore, it makes sense that we should deduce the type of the pointer, not the thing being pointed to.  
  
The difference between auto and auto* Optional When we use auto with a pointer type initializer, the type deduced for auto includes the pointer. So for ptr1 above, the type substituted for auto is std::string*.  
  
When we use auto* with a pointer type initializer, the type deduced for auto does not include the pointer -- the pointer is reapplied afterward after the type is deduced. So for ptr2 above, the type substituted for auto is std::string, and then the pointer is reapplied. In most cases, the practical effect is the same (ptr1 and ptr2 both deduce to std::string* in the above example). However, there are a couple of difference between auto and auto* in practice. First, auto* must resolve to a pointer initializer, otherwise a compile error will result: #include <string>  
  
std::string* getPtr(); // some function that returns a pointer  
  
int main() { auto ptr3{ *getPtr() }; // std::string (because we dereferenced getPtr()) auto* ptr4{ *getPtr() }; // does not compile (initializer not a pointer)  
  
return 0; } This makes sense: in the ptr4 case, auto deduces to std::string, then the pointer is reapplied. Thus ptr4 has type std::string*, and we can’t initialize a std::string* with an initializer that is not a pointer. Second, there are differences in how auto and auto* behave when we introduce const into the equation. We’ll cover this below.  
  
Type deduction and const pointers Optional Since pointers aren’t dropped, we don’t have to worry about that. But with pointers, we have both the const pointer and the pointer to const cases to think about, and we also have auto vs auto*. Just like with references, only top-level const is dropped during pointer type deduction. Let’s start with a simple case: #include <string>  
  
std::string* getPtr(); // some function that returns a pointer  
  
int main() { const auto ptr1{ getPtr() }; // std::string* const auto const ptr2 { getPtr() }; // std::string* const  
  
const auto* ptr3{ getPtr() }; // const std::string* auto* const ptr4{ getPtr() }; // std::string* const  
  
return 0; } When we use either auto const or const auto, we’re saying, “make the deduced pointer a const pointer”. So in the case of ptr1 and ptr2, the deduced type is std::string*, and then const is applied, making the final type std::string* const. This is similar to how const int and int const mean the same thing. However, when we use auto*, the order of the const qualifier matters. A const on the left means “make the deduced pointer a pointer to const”, whereas a const on the right means “make the deduced pointer type a const pointer”. Thus ptr3 ends up as a pointer to const, and ptr4 ends up as a const pointer.  
  
Now let’s look at an example where the initializer is a const pointer to const. #include <string>  
  
int main() { std::string s{}; const std::string* const ptr { &s };  
  
auto ptr1{ ptr }; // const std::string* auto* ptr2{ ptr }; // const std::string*  
  
auto const ptr3{ ptr }; // const std::string* const const auto ptr4{ ptr }; // const std::string* const  
  
auto* const ptr5{ ptr }; // const std::string* const const auto* ptr6{ ptr }; // const std::string*  
  
const auto const ptr7{ ptr }; // error: const qualifer can not be applied twice const auto* const ptr8{ ptr }; // const std::string* const  
  
return 0; } The ptr1 and ptr2 cases are straightforward. The top-level const (the const on the pointer itself) is dropped. The low-level const on the object being pointed to is not dropped. So in both cases, the final type is const std::string*. The ptr3 and ptr4 cases are also straightforward. The top-level const is dropped, but we’re reapplying it. The low-level const on the object being pointed to is not dropped. So in both cases, the final type is const std::string* const. The ptr5 and ptr6 cases are analogous to the cases we showed in the prior example. In both cases, the top-level const is dropped. For ptr5, the auto* const reapplies the top-level const, so the final type is const std::string* const. For ptr6, the const auto* applies const to the type being pointed to (which in this case was already const), so the final type is const std::string*. In the ptr7 case, we’re applying the const qualifier twice, which is disallowed, and will cause a compile error. And finally, in the ptr8 case, we’re applying const on both sides of the pointer (which is allowed since auto* must be a pointer type), so the resulting types is const std::string* const.  
  
Best practice If you want a const pointer, pointer to const, or const pointer to const, reapply the const qualifier(s) even when it’s not strictly necessary, as it makes your intent clear and helps prevent mistakes.  
  
Tip Consider using auto* when deducing a pointer type. Using auto* in this case makes it clearer that we are deducing a pointer type, enlists the compiler’s help to ensure we don’t deduce a non-pointer type, and gives you more control over const.  
  
Summary Sorry to hear about your headache. Let’s recap the most important points quickly. Top-level vs low-level const:  
  
A top-level const applies to the object itself (e.g. const int x or int* const ptr).  
  
A low-level const applies to the object accessed through a reference or pointer (e.g. const int& ref, const int* ptr).  
  
What type deduction deduces:  
  
Type deduction first drops any references (unless the deduced type is defined as a reference). For a const reference, dropping the reference will cause the (low-level) const to become a top-level const.  
  
Type deduction then drops any top-level const (unless the deduced type is defined as const or constexpr).  
  
Constexpr is not part of the type system, so is never deduced. It must always be explicitly applied to the deduced type.  
  
Type deduction does not drop pointers.  
  
Always explicitly define the deduced type as a reference, const, or constexpr (as applicable), and even if these qualifiers are redundant because they would be deduced. This helps prevent errors and makes it clear what your intent is.  
  
Type deduction and pointers:  
  
When using auto, the deduced type will be a pointer only if the initializer is a pointer. When using auto*, the deduced type is always a pointer, even if the initializer is not a pointer.  
  
auto const and const auto both make the deduced pointer a const pointer. There is no way to explicitly specify a low-level const (pointer-to-const) using auto.  
  
auto* const also makes the deduced pointer a const pointer. const auto* makes the deduced pointer a pointer-to-const. If these are hard to remember, int* const is a const pointer (to int), so auto* const must be a const pointer. const int* is a pointer-to-const (int), so const auto* must be a pointer-to-const)  
  
Consider using auto* over auto when deducing a pointer type, as it allows you to explicitly reapply both the top-level and low-level const, and will error if a pointer type is not deduced.  
  
Next lesson  
  
12.15std::optional  
  
Back to table of contents  
  
Previous lesson  
  
12.13In and out parameters  
  
Previous Post13.10 — Passing and returning structs  
  
Next Post8.13 — Introduction to random number generation  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
194 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```

Document 15
```
Navigate  
  
12.x — Chapter 12 summary and quiz Table of contents 12.14 — Type deduction with pointers, references, and const  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
Learn C++ Skill up with our free tutorials  
  
Skip to content   
  
Navigate  
  
12.x — Chapter 12 summary and quiz Table of contents 12.14 — Type deduction with pointers, references, and const  
  
Site Index Latest Changes  
  
About  
  
Leave feedback Report an issue Contact / Support Site FAQ Privacy Policy Donate  
  
   
  
Search  
  
Search for:  
  
Search  
  
12.15 — std::optional  
  
Alex  
  
March 19, 2024, 11:44 am PDT February 8, 2025  
  
In lesson 9.4 -- Detecting and handling errors, we discussed cases where a function encounters an error that it cannot reasonably handle itself. For example, consider a function that calculates and returns a value: int doIntDivision(int x, int y) { return x / y; } If the caller passes in a value that is semantically invalid (such as y = 0), this function cannot calculate a value to return (as division by 0 is mathematically undefined). What do we do in that case? Because functions that calculate results should have no side effects, this function cannot reasonably resolve the error itself. In such cases, the typical thing to do is have the function detect the error, but then pass the error back to the caller to deal with in some program-appropriate way. In the previously linked lesson, we covered two different ways to have a function return an error back to the caller:  
  
Have a void-returning function return a bool instead (indicating success or failure).  
  
Have a value-returning function return a sentinel value (a special value that does not occur in the set of possible values the function can otherwise return) to indicate an error.  
  
As an example of the latter, the reciprocal() function that follows returns value 0.0 (which can never otherwise occur) if the user passes in a semantically invalid argument for x: #include <iostream>  
  
// The reciprocal of x is 1/x, returns 0.0 if x=0 double reciprocal(double x) { if (x == 0.0) // if x is semantically invalid return 0.0; // return 0.0 as a sentinel to indicate an error occurred  
  
return 1.0 / x; }  
  
void testReciprocal(double d) { double result { reciprocal(d) }; std::cout << "The reciprocal of " << d << " is "; if (result != 0.0) std::cout << result << '\n'; else std::cout << "undefined\n"; }  
  
int main() { testReciprocal(5.0); testReciprocal(-4.0); testReciprocal(0.0);  
  
return 0; } While this is a fairly attractive solution, there are a number of potential downsides:  
  
The programmer must know which sentinel value the function is using to indicate an error (and this value may differ for each function returning an error using this method).  
  
A different version of the same function may use a different sentinel value.  
  
This method does not work for functions where all possible sentinel values are valid return values.  
  
Consider our doIntDivision() function above. What value could it return if the user passes in 0 for y? We can’t use 0, because 0 divided by anything yields 0 as a valid result. In fact, there are no values that we could return that cannot occur naturally. So what are we to do? First, we could pick some (hopefully) uncommon return value as our sentinel and use it to indicate an error: #include <limits> // for std::numeric_limits  
  
// returns std::numeric_limits<int>::lowest() on failure int doIntDivision(int x, int y) { if (y == 0) return std::numeric_limits<int>::lowest(); return x / y; } std::numeric_limits<T>::lowest() is a function that returns the most negative value for type T. It is the counterpart to the std::numeric_limits<T>::max() function (which returns the largest positive value for type T) that we introduced in lesson 9.5 -- std::cin and handling invalid input. In the example above, if doIntDivision() cannot proceed, we return std::numeric_limits<int>::lowest(), which returns the most negative int value back to the caller to indicate that the function failed.  
  
While this mostly works, it has two downsides:  
  
Every time we call this function, we need to test the return value for equality with std::numeric_limits<int>::lowest() to see if it failed. That’s verbose and ugly.  
  
It is an example of a semipredicate problem: if the user calls doIntDivision(std::numeric_limits<int>::lowest(), 1), the returned result std::numeric_limits<int>::lowest() will be ambiguous as to whether the function succeeded or failed. That may or may not be a problem depending on how the function is actually used, but it’s another thing we have to worry about and another potential way that errors can creep into our program.  
  
Second, we could abandon using return values to return errors and use some other mechanism (e.g. exceptions). However, exceptions have their own complications and performance costs, and may not be appropriate or desired. That’s probably overkill for something like this. Third, we could abandon returning a single value and return two values instead: one (of type bool) that indicates whether the function succeeded, and the other (of the desired return type) that holds the actual return value (if the function succeeded) or an indeterminate value (if the function failed). This is probably the best option of the bunch. Prior to C++17, choosing this latter option required you to implement it yourself. And while C++ provides multiple ways to do so, any roll-your-own approach will inevitably lead to inconsistencies and errors. Returning a std::optional C++17 introduces std::optional, which is a class template type that implements an optional value. That is, a std::optional<T> can either have a value of type T, or not. We can use this to implement the third option above:  
  
#include <iostream> #include <optional> // for std::optional (C++17)  
  
// Our function now optionally returns an int value std::optional<int> doIntDivision(int x, int y) { if (y == 0) return {}; // or return std::nullopt return x / y; }  
  
int main() { std::optional<int> result1 { doIntDivision(20, 5) }; if (result1) // if the function returned a value std::cout << "Result 1: " << *result1 << '\n'; // get the value else std::cout << "Result 1: failed\n";  
  
std::optional<int> result2 { doIntDivision(5, 0) };  
  
if (result2) std::cout << "Result 2: " << *result2 << '\n'; else std::cout << "Result 2: failed\n";  
  
return 0; } This prints: Result 1: 4 Result 2: failed  
  
Using std::optional is quite easy. We can construct a std::optional<T> either with or without a value: std::optional<int> o1 { 5 }; // initialize with a value std::optional<int> o2 {}; // initialize with no value std::optional<int> o3 { std::nullopt }; // initialize with no value To see if a std::optional has a value, we can choose one of the following: if (o1.has_value()) // call has_value() to check if o1 has a value if (o2) // use implicit conversion to bool to check if o2 has a value To get the value from a std::optional, we can choose one of the following: std::cout << *o1; // dereference to get value stored in o1 (undefined behavior if o1 does not have a value) std::cout << o2.value(); // call value() to get value stored in o2 (throws std::bad_optional_access exception if o2 does not have a value) std::cout << o3.value_or(42); // call value_or() to get value stored in o3 (or value `42` if o3 doesn't have a value) Note that std::optional has a usage syntax that is essentially identical to a pointer:  
  
Behavior Pointer std::optional   
  
Hold no value initialize/assign {} or std::nullptr initialize/assign {} or std::nullopt   
  
Hold a value initialize/assign an address initialize/assign a value   
  
Check if has value implicit conversion to bool implicit conversion to bool or has_value()   
  
Get value dereference dereference or value()   
  
However, semantically, a pointer and a std::optional are quite different.  
  
A pointer has reference semantics, meaning it references some other object, and assignment copies the pointer, not the object. If we return a pointer by address, the pointer is copied back to the caller, not the object being pointed to. This means we can’t return a local object by address, as we’ll copy that object’s address back to the caller, and then the object will be destroyed, leaving the returned pointer dangling.  
  
A std::optional has value semantics, meaning it actually contains its value, and assignment copies the value. If we return a std::optional by value, the std::optional (including the contained value) is copied back to the caller. This means we can return a value from the function back to the caller using std::optional.  
  
With this in mind, let’s look at how our example works. Our doIntDivision() now returns a std::optional<int> instead of an int. Inside the function body, if we detect an error, we return {}, which implicitly returns a std::optional containing no value. If we have a value, we return that value, which implicit returns a std::optional containing that value. Within main(), we use an implicit conversion to bool to check if our returned std::optional has a value or not. If it does, we dereference the std::optional object to get the value. If it doesn’t, then we execute our error condition. That’s it! Pros and cons of returning a std::optional Returning a std::optional is nice for a number of reasons:  
  
Using std::optional effectively documents that a function may return a value or not.  
  
We don’t have to remember which value is being returned as a sentinel.  
  
The syntax for using std::optional is convenient and intuitive.  
  
Returning a std::optional does come with a few downsides:  
  
We have to make sure the std::optional contains a value before getting the value. If we dereference a std::optional that does not contain a value, we get undefined behavior.  
  
std::optional does not provide a way to pass back information about why the function failed.  
  
Unless your function needs to return additional information about why it failed (either to better understand the failure, or to differentiate different kinds of failure), std::optional is an excellent choice for functions that may return a value or fail.  
  
Best practice Return a std::optional (instead of a sentinel value) for functions that may fail, unless your function needs to return additional information about why it failed.  
  
Related content std::expected (introduced in C++23) is designed to handle the case where a function can return either an expected value or an unexpected error code. See the std::expected reference for more information.  
  
Using std::optional as an optional function parameter In lesson 12.11 -- Pass by address (part 2), we discussed how pass by address can be used to allow a function to accept an “optional” argument (that is, the caller can either pass in nullptr to represent “no argument” or an object). However, one downside of this approach is that a non-nullptr argument must be an lvalue (so that its address can be passed to the function). Perhaps unsurprisingly (given the name), std::optional is an alternative way for a function to accept an optional argument (that is used as an in-parameter only). Instead of this: #include <iostream>  
  
void printIDNumber(const int *id=nullptr) { if (id) std::cout << "Your ID number is " << *id << ".\n"; else std::cout << "Your ID number is not known.\n"; }  
  
int main() { printIDNumber(); // we don't know the user's ID yet  
  
int userid { 34 }; printIDNumber(&userid); // we know the user's ID now  
  
return 0; } You can do this:  
  
#include <iostream> #include <optional>  
  
void printIDNumber(std::optional<const int> id = std::nullopt) { if (id) std::cout << "Your ID number is " << *id << ".\n"; else std::cout << "Your ID number is not known.\n"; }  
  
int main() { printIDNumber(); // we don't know the user's ID yet  
  
int userid { 34 }; printIDNumber(userid); // we know the user's ID now  
  
printIDNumber(62); // we can also pass an rvalue  
  
return 0; } There are two advantages to this approach:  
  
It effectively documents that the parameter is optional.  
  
We can pass in an rvalue (since std::optional will make a copy).  
  
However, because std::optional makes a copy of its argument, this becomes problematic when T is an expensive-to-copy type (like std::string). With normal function parameters, we worked around this by making the parameter a const lvalue reference, so that a copy would not be made. Unfortunately, as of C++23 std::optional does not support references. Therefore, we recommend using std::optional<T> as an optional parameter only when T would normally be passed by value. Otherwise, use const T*.  
  
For advanced readers Although std::optional doesn’t support references directly, you can use std::reference_wrapper (which we cover in lesson 17.5 -- Arrays of references via std::reference_wrapper) to mimic a reference. Let’s take a look at what the above program looks like using a std::string id and std::reference_wrapper: #include <functional> // for std::reference_wrapper #include <iostream> #include <optional> #include <string>  
  
struct Employee { std::string name{}; // expensive to copy int id; };  
  
void printEmployeeID(std::optional<std::reference_wrapper<Employee>> e=std::nullopt) { if (e) std::cout << "Your ID number is " << e->get().id << ".\n"; else std::cout << "Your ID number is not known.\n"; }  
  
int main() { printEmployeeID(); // we don't know the Employee yet  
  
Employee e { "James", 34 }; printEmployeeID(e); // we know the Employee's ID now  
  
return 0; } And for comparison, the pointer version: #include <iostream> #include <string>  
  
struct Employee { std::string name{}; // expensive to copy int id; };  
  
void printEmployeeID(const Employee* e=nullptr) { if (e) std::cout << "Your ID number is " << e->id << ".\n"; else std::cout << "Your ID number is not known.\n"; }  
  
int main() { printEmployeeID(); // we don't know the Employee yet  
  
Employee e { "James", 34 }; printEmployeeID(&e); // we know the Employee's ID now  
  
return 0; } These two programs are nearly identical. We’d argue the former isn’t more readable or maintainable than the latter, and isn’t worth introducing two additional types into your program for.  
  
In many cases, function overloading provides a superior solution: #include <iostream> #include <string>  
  
struct Employee { std::string name{}; // expensive to copy int id; };  
  
void printEmployeeID() { std::cout << "Your ID number is not known.\n"; }  
  
void printEmployeeID(const Employee& e) { std::cout << "Your ID number is " << e.id << ".\n"; }  
  
int main() { printEmployeeID(); // we don't know the Employee yet  
  
Employee e { "James", 34 }; printEmployeeID(e); // we know the Employee's ID now  
  
printEmployeeID( { "Dave", 62 } ); // we can even pass rvalues  
  
return 0; }  
  
Best practice Prefer std::optional for optional return types. Prefer function overloading for optional function parameters (when possible). Otherwise, use std::optional<T> for optional arguments when T would normally be passed by value. Favor const T* when T is expensive to copy.  
  
Next lesson  
  
12.xChapter 12 summary and quiz  
  
Back to table of contents  
  
Previous lesson  
  
12.14Type deduction with pointers, references, and const  
  
Previous PostB.5 — Introduction to C++23  
  
Next Post13.4 — Converting an enumeration to and from a string  
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
Notify me about replies:     
  
Label  
  
Name*  
  
Email*  
  
Your email address will not be displayed  
  
Find a mistake? Leave a comment above! Correction-related comments will be deleted after processing to help reduce clutter. Thanks for helping to make the site better for everyone!  
  
Avatars from https://gravatar.com/ are connected to your provided email address.   
  
33 Comments   
  
Newest  
  
Oldest Most Voted  
  
Inline Feedbacks View all comments  
  
Load More Comments   
  
©2024 Learn C++ Privacy Policy  
  
wpDiscuz  
  
Insert  
  
You are going to send email to Send  
  
Move Comment  
  
Move
```
Output: (Concise, well-organized note optimal for reviewing)

```

```
