# Student Sorting Program (Bubble Sort & Quick Sort)

**Name:** Sahil Ashok Khaire  
**Roll No:** 13  
**Title:** Sorting Student Records using Bubble Sort and Quick Sort

## Theory

In this program, we demonstrate **sorting techniques** applied to a structure (`Student_sak`) that stores:
- Roll Number
- Name
- Marks

### Concepts Used
1. **Structure in C**  
   - To group student data into one entity.
2. **Dynamic Memory Allocation (`malloc`)**  
   - Allocates memory at runtime based on the number of students.
3. **Bubble Sort**  
   - Simple comparison-based sorting algorithm.
   - Time Complexity: O(n²)
4. **Quick Sort**  
   - Divide and Conquer sorting algorithm.
   - Time Complexity: O(n log n) average, O(n²) worst case.
5. **Swapping Technique**  
   - Used to interchange structure elements.


## Algorithm

### Bubble Sort
1. Repeat (n-1) passes.
2. In each pass, compare adjacent elements.
3. If the first element is greater than the next, swap them.
4. Continue until sorted.

### Quick Sort
1. Select a **pivot element** (last element in this case).
2. Partition the array into two sub-arrays:
   - Left side → elements smaller than pivot.
   - Right side → elements larger than pivot.
3. Recursively apply Quick Sort to left and right sub-arrays.
4. Combine results.

## Input

- Number of students (entered by user).
- Student details generated randomly:
  - Roll No
  - Name
  - Marks
  
## Output

