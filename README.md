# Nightly-CPP

Prompt ChatGPT to generate a small C++ exercise (like 5 to 15 mins of work) task for me when I feel like it, mostly near or at midnight.  
Thought I'd store / post the code here, mostly isn't something professional or stuff you should consider learning from. 

## Linear Function Table Generator
Project description:
```md
Here's a project idea that fits your level and constraints:

---

**Title:** *Linear Function Table Generator*

**Description:**
Create a C++ program that takes a linear function of the form `y = mx + b` (where `m` and `b` are user inputs) and generates a value table for `x` in a range (also user-defined). The output should be a nicely formatted table showing `x` and the corresponding `y` values.

**Requirements:**

* Ask the user to enter the slope `m` and y-intercept `b`.
* Ask the user for a start value, end value, and step size for `x`.
* Use a loop to calculate and display the `y` values for each `x`.
* Output should be aligned in a readable table format.

**Bonus:**

* Add input validation (e.g., step ≠ 0).
* Let the user choose between integer or decimal output.

---

Let me know if you want more project ideas in the same style or a different math topic.

```
My solution after `~15 minutes of work` can be found at `linear-function-table.cpp`.

## Fraction Calculator - Simplify and Add
Project description:
```md
Sure! Here's a simple C++ project idea that fits your level and can be done in about 20 minutes:

---

**📘 Project Title: "Fraction Calculator – Simplify and Add"**

**Goal:**
Write a program that takes two fractions as input (like `3/4` and `2/5`), simplifies them, and then adds them together, giving the simplified result.

**Requirements:**

* Input: two fractions as numerator and denominator (e.g., `3 4` for 3/4).
* Simplify each fraction (e.g., `6/8` → `3/4`).
* Add both fractions and simplify the result.
* Use only `iostream`, basic math (`+`, `*`, `%`, etc.), and functions.
* Optional: Print intermediate steps (e.g., "LCM of denominators", "Sum numerator").

**Example:**

---
Input:
Fraction 1: 3 4
Fraction 2: 2 5

Output:
3/4 + 2/5 = 23/20 = 1 3/20
---

Let me know if you want an extra challenge like subtracting or multiplying them too.
```
My solution after `~30min of work` can be found at `simple-fraction-addition.cpp`.

## Linear Equation Solver (DD/MM/YYYY : 19/06/2025)
Project description:
```md
Sure! Here's a project description that fits Algebra 1 level, is doable in about 20 minutes, and only uses standard C++ libraries:

---

**Project Title:** *Linear Equation Solver*

**Objective:**
Create a C++ program that solves simple linear equations of the form `ax + b = c`, where `a`, `b`, and `c` are real numbers entered by the user.

**Requirements:**

1. Prompt the user to input values for `a`, `b`, and `c`.
2. Calculate the value of `x` that solves the equation.
3. Display the solution in a clear and readable format.
4. Handle the following edge cases:

   * If `a == 0` and `b == c`, print "Infinite solutions."
   * If `a == 0` and `b != c`, print "No solution."
   * Otherwise, solve for `x` and display the result.

**Bonus (Optional):**

* Allow the user to enter another equation after solving the first.
* Display each step of the calculation for educational purposes.

---

Let me know if you want a version with a quadratic equation, or something involving plotting using ASCII!
```
My final solution after `~13 minutes of work` can be found at `linear-equation-solver.cpp`.

## Useless Bank (DD/MM/YYYY : 18/06/2025)
Project description:
```md
### 🧠 **Exercise: Bank Account Management System**

**Objective**: Practice classes, encapsulation, vectors, and basic I/O.

**Description**:
Create a simple bank account management system that allows users to:

1. Create new accounts.
2. Deposit money.
3. Withdraw money.
4. Display account details.
5. Exit the program.

**Requirements**:

* Use a `BankAccount` class with the following private members:

  * `int accountNumber`
  * `std::string ownerName`
  * `double balance`

* Include the following public methods:

  * Constructor to initialize a new account.
  * `void deposit(double amount)`
  * `bool withdraw(double amount)`
  * `void display() const`

* Store multiple accounts using a `std::vector<BankAccount>`.

* Use a simple console menu for user interaction.

---

**Bonus Challenges**:

* Ensure unique account numbers using a static counter.
* Validate inputs (no negative deposits/withdrawals, sufficient balance).
* Implement a search function to find accounts by account number.
```
My final solution after `~35 minutes of work` can be found at `useless-bank.cpp`.

## Primes In Range (DD/MM/YYYY : 17/06/2025)
Project description:
```md
### 🔍 **Task Description**

Write a C++ program that does the following:

1. **Asks the user to enter two integers `a` and `b`**, where `1 ≤ a < b ≤ 1000`.
2. **Finds all prime numbers between `a` and `b` (inclusive)**.
3. **Displays the following statistics**:

   * Total number of prime numbers
   * The smallest and largest prime
   * The average (mean) of all the found prime numbers (as a floating-point number)
   * The sum of all the digits of all prime numbers found

---

### 💡 **Hints**

* A number `n` is **prime** if it has no divisors other than `1` and `n`.
* Use `std::vector<int>` to store prime numbers.
* Use functions for modular design:

  * `bool isPrime(int n)`
  * `int sumOfDigits(int n)`

---

### 📥 **Sample Input**

Enter a: 10
Enter b: 30

### 📤 **Sample Output**

Prime numbers between 10 and 30: 11 13 17 19 23 29
Total primes found: 6
Smallest prime: 11
Largest prime: 29
Average of primes: 18.6667
Sum of all digits in primes: 66

---

### 🔧 **Requirements**

* Use only the standard C++ library: `<iostream>`, `<vector>`, `<cmath>`, etc.
* Do not use advanced libraries or third-party headers.
* Code should be split into at least two functions.
```
My final solution after `~15 minutes of work` can be found at `primes-in-range.cpp`.
