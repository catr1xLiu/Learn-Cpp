
## 1. Task Overview

Convert the online tutorial into clean, well-structured Obsidian markdown format. You have full creative freedom to:
- Reorganize unclear structures
- Create logical sections
- Improve clarity while keeping content concise for review purposes

## 2. Obsidian Formatting Requirements

### 2.1 Outline & Callout Usage

The document should have an h1 title, and should be divided into a few sections, each beginning with a callout with a h4 sub-title. 

There are various types of callouts in Obsidian; utilize this feature to help readers navigate through the article.

**Callout Types:**
- `[!abstract]` - Introduction
- `[!quote]` - Concept
- `[!fact]` - Important Information
- `[!info]` - Additional Information
- `[!warning]` Warning
- `[!hint]` - Best Practice
- `[!example]` - Examples

**IMPORTANT** only use callout for title, no callout for the content following it. (export for warning).

### 2.2 Important Terminology

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

### 2.3 Example Note

An example of the structure will be:
```markdown
> [!abstract] 1.1
> 
> # Variables

A <u><strong style="color:#dab1da">variable</strong></u> is a named object that stores a value in memory.

> [!quote] Concept
> 
> #### Memory

- <u><strong style="color:#dab1da">Bit</strong></u>: Smallest unit (0 or 1)
- <u><strong style="color:#dab1da">Byte</strong></u>: 8 bits with unique address
- n-bit object holds **2^n** unique values

int x;      // Define variable (reserves memory)

At runtime, memory is <u><strong style="color:#dab1da">allocated</strong></u> and the variable is <u><strong style="color:#dab1da">created</strong></u>.


> [!quote] Concept
> 
> #### Initialization & Assignment

<u><strong style="color:#dab1da">Initialization</strong></u>: Providing initial value at point of definition <u><strong style="color:#dab1da">Assignment</strong></u>: Changing value after definition

- `int x { 5 };` - Direct-list initialization ✓
- `int x {};` - Value initialization (0) ✓
- `int x = 5;` - Copy initialization (less preferred)
- `int x;` - Uninitialized (undefined behavior if used) ✗

int x { 5 };    // Direct-list initialization (preferred)
int y {};       // Value initialization (zero)
int z;          // Default initialization (dangerous - uninitialized!)

int a { 5 };
a = 10;         // Assignment (overwrites previous value)

> [!fact] Important
> 
> #### Identifier Rules

- Start with letter or underscore
- Letters, numbers, underscore only
- Can't be keywords


> [!hint] Best Practice
> 
> #### Naming Variables

- ✓ Always initialize variables
- ✓ Descriptive names: `playerScore` not `x`
- ✓ One variable per line
- ✗ Avoid starting with underscore
- ✗ Avoid abbreviations

**Conventions:**

int playerScore;     // camelCase (preferred)
int player_score;    // snake_case (also common)

> [!warning] Warning
> 
> #### Uninitialized Variables

Using uninitialized variables leads to <u><strong style="color:#dab1da">undefined behavior</strong></u> - the variable contains whatever garbage value was in that memory location. This can cause:

- Different results each run
- Crashes
- Inconsistent behavior
- Working code that suddenly breaks

**Always initialize your variables to avoid undefined behavior.**

```

## 3. Content Guidelines

You will be given the content of a few documents, each of length 4-5 pages as plain text at a time, convert them into one document of about 2 page size. This means that you need to shrink the content to about 1/4 the original size. Discard introduction part, unusual examples, outdated language features and only keep the best practices.

If you are given a desired outline, just follow that structure. Otherwise, provide a few structures with different structuring logic to choose from, and ask for the user to select one. 

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

