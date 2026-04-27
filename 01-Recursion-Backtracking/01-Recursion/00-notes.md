Perfect timing for this—you’ve built the intuition, now we compress it into something you can *revise and instantly recall the whole picture*. I’ll make this like a mental cheat sheet, not boring notes.

# 🧠 RECURSION 

---

# 🔹 1. What is Recursion (Core Idea)

> A function calling itself to solve a **smaller version of the same problem**

### 🧠 Mental Model

* Don’t solve everything at once
* Solve **one step**
* Let recursion handle the rest

---

## 🔥 Golden Rule

Every recursive function has:

1. **Base Case → STOP condition**
2. **Recursive Case → Reduce problem**

If base case is missing → ❌ infinite recursion → crash

---

# 🔹 2. Recursion Flow (MOST IMPORTANT)

## 🔽 Going DOWN (calls)

* Function keeps calling itself
* Problem gets smaller

## 🔼 Coming UP (returns)

* Work gets executed (if after recursion)

---

## 🧠 Memory Rule

> “Before recursion = going down”
> “After recursion = coming up”

---

# 🔹 3. Boilerplate (Write this in your sleep)

```cpp
return_type func(parameters) {
    // 1. Base case
    if(condition) return value;

    // 2. Work (optional)

    // 3. Recursive call
    func(smaller_input);

    // 4. Remaining work (optional)
}
```

---

# 🔹 4. Two Core Patterns

---

## ✅ Pattern 1: Work BEFORE recursion

```cpp
void func(int n){
    if(n == 0) return;

    cout << n;
    func(n - 1);
}
```

👉 Output: `N → 1`

🧠 Happens while going DOWN

---

## ✅ Pattern 2: Work AFTER recursion

```cpp
void func(int n){
    if(n == 0) return;

    func(n - 1);
    cout << n;
}
```

👉 Output: `1 → N`

🧠 Happens while coming UP

---

## 🔥 Combined Pattern (VERY IMPORTANT)

```cpp
cout << n;
func(n - 1);
cout << n;
```

👉 Output example (n=3):
`3 2 1 1 2 3`

---

## 🧠 Final Rule (burn this)

| Position of work | Output direction |
| ---------------- | ---------------- |
| Before recursion | Descending       |
| After recursion  | Ascending        |
| Both sides       | Mirror           |

---

# 🔹 5. Classic Recursive Problems

---

## ✅ Factorial

```cpp
int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n - 1);
}
```

---

## ✅ Sum of N

```cpp
int sum(int n){
    if(n == 0) return 0;
    return n + sum(n - 1);
}
```

---

## ✅ Fibonacci (important pattern)

```cpp
int fib(int n){
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

🧠 Key idea:

* Multiple recursive calls
* Tree-like structure

---

# 🔹 6. Head vs Tail Recursion

---

## 🔹 Head Recursion

```cpp
func(n - 1);
cout << n;
```

* Work happens **after**
* Uses stack heavily
* Output: ascending

---

## 🔹 Tail Recursion

```cpp
cout << n;
func(n - 1);
```

* Work happens **before**
* Can be converted to loop
* Output: descending

---

## 🧠 Shortcut

> Tail recursion = loop
> Head recursion = stack-based thinking

---

# 🔹 7. When to Use Recursion (CRITICAL)

---

## ✅ Use recursion when:

### 1. Problem = smaller same problem

```text
f(n) = something with f(n-1)
```

Examples:

* factorial
* sum
* fibonacci

---

### 2. Structure is recursive

Examples:

* Trees 🌳
* Graphs
* Nested data

---

### 3. Choices / branching exists

Examples:

* subsets
* permutations
* maze solving

👉 Leads to **backtracking**

---

# 🔹 8. When NOT to Use Recursion

---

## ❌ Avoid recursion when:

### 1. Simple loop works

* printing numbers
* basic iteration

---

### 2. Input size is huge

```text
n = 10^5 or more → stack overflow risk
```

---

# 🔹 9. Common Mistakes (VERY IMPORTANT)

---

## ❌ Missing base case

→ infinite recursion

---

## ❌ Wrong base case

→ wrong output

---

## ❌ Not reducing problem

→ stuck recursion

---

## ❌ Stack overflow

→ too many calls

---

## ❌ Confusing flow

→ forgetting up vs down phase

---

# 🔹 10. The 3-Step Thinking Framework

Whenever you see a problem:

---

## 🧠 Step 1: Define in terms of itself

```text
Can I express this using smaller same problem?
```

---

## 🧠 Step 2: Find base case

```text
What is the smallest valid input?
```

---

## 🧠 Step 3: Decide work position

```text
Before recursion? → top-down
After recursion? → bottom-up
Both? → complex pattern
```

---




