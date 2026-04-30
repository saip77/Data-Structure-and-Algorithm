# Binary Search

### 1\. Definition

Binary Search is a divide-and-conquer algorithm that repeatedly divides a sorted array or search space in half to find a target value or optimal solution.

  * **Time Complexity:** O(log n).
  * **Space Complexity:** O(1) for the iterative version; O(log n) for the recursive version due to the call stack.

### 2\. C++ Implementation Templates

#### Classic Binary Search (Iterative)

``` cpp
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int left = 0, n = nums.size();
    int right = n - 1; //

    while (left <= right) { //
        int mid = left + (right - left) / 2; //

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1; //
        } else {
            right = mid - 1; //
        }
    }
    return -1;
}

```

#### Binary Search on Answer

``` cpp
int binarySearchOnAnswer(int minPossible, int maxPossible) {
    int left = minPossible, right = maxPossible; //
    
    while (left < right) { //
        int mid = left + (right - left) / 2; //
        
        if (can(mid)) { // Custom condition
            right = mid; // Try for a smaller optimal value
        } else {
            left = mid + 1; // Try larger value
        }
    }
    return left; //
}

```

### 3\. Application Contexts

Binary search is applicable in two major scenarios:

  * **Classic Arrays:** Finding a specific element or condition in a sorted array.
  * **Search Space:** Finding minimum/maximum values or optimal solutions in a monotonic numeric range.

### 4\. Identification and Benefits

| Feature      | Details                                                                                                            |
| :----------- | :----------------------------------------------------------------------------------------------------------------- |
| **Clues**    | Sorted arrays, finding first/last occurrences, or keywords like "minimum days" or "maximum capacity".              |
| **Examples** | Ship within D days, First bad version, Search in rotated array.                                                    |
| **Benefits** | Fast O(log n) time, acts as "smart brute-force," works on custom conditions, and saves memory by working in-place. |

### 5\. Common Problem Categories

| Category                 | Example Problems                                                         |
| :----------------------- | :----------------------------------------------------------------------- |
| **Sorted Array Search**  | Binary Search, Search in Rotated Array.                                  |
| **Position Finding**     | First Bad Version, Find Peak Element, Insert Position.                   |
| **Min/Max Optimization** | Capacity to Ship Packages, Koko Eating Bananas, Split Array Largest Sum. |
| **Custom Functions**     | Guess Number, H-index, Median of Two Sorted Arrays.                      |

