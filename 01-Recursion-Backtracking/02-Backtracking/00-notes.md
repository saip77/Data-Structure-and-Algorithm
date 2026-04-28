# BACKTRACKING PATTERNS 

## 🧠 1. TAKE / SKIP (Subsets Pattern)

### ✅ When to use

* Subsets
* Include / Exclude
* Pick / Not pick

### 🧩 Template

```cpp
void solve(string &s, int index, string &path){
    if(index == s.size()){
        cout << path << endl;
        return;
    }

    // TAKE
    path.push_back(s[index]);
    solve(s, index + 1, path);
    path.pop_back(); // undo

    // SKIP
    solve(s, index + 1, path);
}
```

### 🧠 Trigger

```
Each element → 2 choices (take / skip)
```

---

## 🧠 2. BUILD STRING (Binary / Generate Pattern)

### ✅ When to use

* Generate strings
* Length = n
* Build step-by-step

### 🧩 Template

```cpp
void solve(int n, string path){
    if(path.size() == n){
        cout << path << endl;
        return;
    }

    solve(n, path + "0");
    solve(n, path + "1");
}
```

### 🧠 Trigger

```
Build path until size = n
```

---

## 🧠 3. CONSTRAINT BACKTRACKING

### ✅ When to use

* “Valid only if…”
* “No consecutive…”
* Any restriction

### 🧩 Template

```cpp
void solve(int n, string path){
    if(path.size() == n){
        cout << path << endl;
        return;
    }

    // always allowed
    solve(n, path + "0");

    // only if valid
    if(path.empty() || path.back() != '1'){
        solve(n, path + "1");
    }
}
```

### 🧠 Trigger

```
Only go deeper if valid
```

---

## 🧠 4. FIX POSITION (Permutations Pattern)

### ✅ When to use

* Permutations
* Arrangement problems
* Order matters

### 🧩 Template

```cpp
void solve(string &s, int index){
    if(index == s.size()){
        cout << s << endl;
        return;
    }

    for(int i = index; i < s.size(); i++){
        swap(s[index], s[i]);      // choose
        solve(s, index + 1);       // explore
        swap(s[index], s[i]);      // undo
    }
}
```

### 🧠 Trigger

```
Fix position → try all possible characters
```

---

## 🧠 5. CHOOSE FROM LIST (Combination Sum Pattern)

### ✅ When to use

* Array problems
* Target sum
* Choose elements

### 🧩 Template

```cpp
void solve(vector<int>& arr, int index, int target, vector<int>& path){
    if(target == 0){
        // print path
        return;
    }

    if(index == arr.size()) return;

    // TAKE
    if(arr[index] <= target){
        path.push_back(arr[index]);
        solve(arr, index, target - arr[index], path);
        path.pop_back(); // undo
    }

    // SKIP
    solve(arr, index + 1, target, path);
}
```

### 🧠 Trigger

```
Pick element OR skip it
```

---

## 🔥 MASTER TEMPLATE (Universal Backtracking)

```cpp
void solve(...){
    if(base case){
        save or print answer;
        return;
    }

    for(each choice){
        if(valid){
            choose
            solve(...)
            undo
        }
    }
}
```

---

## 🧠 FINAL PATTERN MAP

| Problem Type    | Pattern             |
| --------------- | ------------------- |
| Subsets         | Take / Skip         |
| Binary Strings  | Build String        |
| Constraints     | Condition + Pruning |
| Permutations    | Fix Position        |
| Combination Sum | Choose from List    |

---

#  Backtracking Pattern Flowchart 

```text
ALL POSSIBILITIES?
    |
    YES
    |
    ├── Order matters? → PERMUTATION
    |
    ├── Choosing elements?
    |       ├── Take/Skip → SUBSETS
    |       └── Target/Reuse → COMBINATION
    |
    ├── Building string? → BINARY / BUILD
    |
    └── Constraints? → ADD CONDITION
```

---

## 🧠 Quick Mental Shortcut

```text
Order matters? → Permutation  
Pick or not? → Subset  
Build length n? → Binary  
Target sum? → Combination  
Condition? → Add constraint  
```
