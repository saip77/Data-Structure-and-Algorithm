
# 🧩 1. Basic Binary Search (sorted array)

### ✅ Template

```cpp
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;

        else if (arr[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }
    return -1;
}
```

### 🧠 Use when:

* Fully sorted array
* Direct search

---

# 🔄 2. Modified Binary Search (Rotated / Partial Sorted)

### ✅ Template (Rotated Sorted Array)

```cpp
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half sorted
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        // Right half sorted
        else {
            if (target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}
```

---

### 🧠 Template idea:

```cpp
if (left half is sorted) {
    check if target is inside
} else {
    right half is sorted
    check there
}
```

---

# 🎯 3. Binary Search on Answer (MOST IMPORTANT)

### ✅ Generic Template

```cpp
bool possible(int mid) {
    // return true if mid is a valid answer
}

int solve() {
    int left = MIN_ANSWER;
    int right = MAX_ANSWER;
    int ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (possible(mid)) {
            ans = mid;        // store answer
            right = mid - 1;  // try better (minimize)
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
```

---

### 🔁 For MAXIMUM answer problems:

```cpp
if (possible(mid)) {
    ans = mid;
    left = mid + 1;
} else {
    right = mid - 1;
}
```

---

### 🧠 Use when:

* “minimum possible…”
* “maximum possible…”
* optimization problems

---

# 🧱 4. Binary Search on 2D Matrix

---

## ✅ Method 1: Treat as 1D

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int left = 0;
    int right = row * col - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int value = matrix[mid / col][mid % col];

        if (value == target)
            return true;
        else if (value < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
```

---

## ✅ Method 2: Row-wise elimination

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int i = 0, j = col - 1;

    while (i < row && j >= 0) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}
```

---

# ⚡ MASTER TEMPLATE (covers almost everything)

```cpp
while (left <= right) {
    int mid = left + (right - left) / 2;

    if (condition satisfied)
        return / store answer;

    else if (go left)
        right = mid - 1;

    else
        left = mid + 1;
}
```

---



