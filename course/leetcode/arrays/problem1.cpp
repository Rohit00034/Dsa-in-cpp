/* 1920. Build Array from Permutation LEARNT ABOUT:-erase() method in vector to delete elements from one index to another*/
#include <bits/stdc++.h>
using namespace std;
// class Solution1 {
// public:
//     vector<int> buildArray(vector<int>& nums) {
//         vector<int> a;
//         for(int i=0;i<nums.size();i++){
//             a.push_back(nums[nums[i]]);
//         }
//         return a;
//     }
// };

// Follow-up: Can you solve it without using an extra space (i.e., O(1) memory)?
// the solution below uses O(n) as the vector is doubled in size so nothing changes here and we are using the var size too so this is useless
class Solution2 {
public:
    vector<int> buildArray(vector<int>& nums) {
     int size=nums.size();
    for(int i=0;i<size;i++){
            nums.push_back(nums[nums[i]]);
        }
        nums.erase(nums.begin(),nums.begin()+(nums.size()/2)-1); //we can delete elements in vector using this iterator with erase()
        for(int i:nums){
            cout<<i<<' ';
        }
        return nums;
    }
};

int main(){
    Solution2 s1;
    vector<int> vec={0,2,1,5,3,4};
    s1.buildArray(vec);
    return 0;
}

/*Correct solution for O(1) in space complxity 
SOLUTION:-
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();

        // Encode both old and new values
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] + n * (nums[nums[i]] % n);
        }

        // Decode to get the new values
        for (int i = 0; i < n; i++) {
            nums[i] /= n;
        }

        return nums;
    }
};

EXPLANATION:-
This is one of the cleverest tricks in array problems. The idea is to **store two numbers in one array element**.
IMPORTANT:- This works because every original element is guaranteed to be in the range **0 to n−1**, so `old < n`. That means `old` becomes the remainder (`% n`), while `new` is stored in the higher multiples of `n` and can be recovered with integer division (`/ n`).

Let's go through it step by step.

---

## Original array

```cpp
nums = [0, 2, 1, 5, 3, 4]
```

Here,

```text
n = 6
```

We need to build

```text
ans[i] = nums[nums[i]]
```

The expected answer is

```text
[0,1,2,4,5,3]
```

---

## The problem

Suppose we simply overwrite values.

For `i = 1`

```cpp
nums[1] = nums[nums[1]];
```

becomes

```cpp
nums[1] = nums[2];
```

so the array becomes

```text
[0,1,1,5,3,4]
```

Now when we later need the **original value** at index 1, it's already gone.

So we need a way to keep

* old value
* new value

inside the same integer.

---

# Step 1 : Encode both values

The formula is

```cpp
nums[i] = nums[i] + n * (nums[nums[i]] % n);
```

Notice

```cpp
nums[nums[i]] % n
```

Why `% n`?

Because some elements may already have been modified.

Suppose an element became

```text
31
```

The original value is still

```text
31 % 6 = 1
```

since every original number is between `0` and `5`.

---

## Let's do every iteration.

Initial

```text
Index : 0 1 2 3 4 5
Value : 0 2 1 5 3 4
```

---

### i = 0

Old value

```text
nums[0]=0
```

Need

```text
nums[nums[0]]
=
nums[0]
=
0
```

Store

```text
0 + 6×0 = 0
```

Array

```text
0 2 1 5 3 4
```

---

### i = 1

Old value

```text
nums[1]=2
```

Need

```text
nums[2]
```

Current value at index 2

```text
1
```

Store

```text
2 + 6×1 = 8
```

Array

```text
0 8 1 5 3 4
```

Notice

```text
8 = old(2) + 6×new(1)
```

Both values are inside 8.

---

### i = 2

Need

```text
nums[1]
```

But wait!

Index 1 already changed to

```text
8
```

If we directly use it,

```text
new value = 8
```

which is wrong.

So we do

```cpp
nums[1] % 6
```

which gives

```text
8 % 6 = 2
```

That's the original value.

Now

```text
1 + 6×2 = 13
```

Array

```text
0 8 13 5 3 4
```

---

### i = 3

Need

```text
nums[5]=4
```

Store

```text
5 + 6×4 = 29
```

Array

```text
0 8 13 29 3 4
```

---

### i = 4

Need

```text
nums[3]
```

Current value

```text
29
```

Original

```text
29 % 6 = 5
```

Store

```text
3 + 6×5 = 33
```

Array

```text
0 8 13 29 33 4
```

---

### i = 5

Need

```text
nums[4]
```

Current value

```text
33
```

Original

```text
33 % 6 = 3
```

Store

```text
4 + 6×3 = 22
```

Final encoded array

```text
0 8 13 29 33 22
```

---

# Step 2 : Decode

Now divide every element by `n`.

```cpp
for(int i=0;i<n;i++)
    nums[i]/=n;
```

Let's see.

| Encoded | Divide by 6 | Result |
| ------: | ----------: | -----: |
|       0 |           0 |      0 |
|       8 |           1 |      1 |
|      13 |           2 |      2 |
|      29 |           4 |      4 |
|      33 |           5 |      5 |
|      22 |           3 |      3 |

Result

```text
[0,1,2,4,5,3]
```

Exactly what we wanted.

---

# Why does this work?

Suppose

```text
old = 3
new = 5
n = 6
```

We store

```text
3 + 6×5 = 33
```

Now:

Original value:

```text
33 % 6 = 3
```

New value:

```text
33 / 6 = 5
```

So one integer contains both values:

```text
stored = old + n × new
```

```
stored = 33

33 % 6 = 3   ← old value
33 / 6 = 5   ← new value
```

*/
