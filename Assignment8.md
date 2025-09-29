# Quick Sort and Divide & Conquer on Student Marks

**Name:** Sahil Ashok Khaire  
**Roll No:** 13 
**Title:** Sorting Student Marks using Quick Sort and Finding Min/Max using Divide & Conquer


## Theory

In this program:
- Marks of `n` students are input.
- **Quick Sort Algorithm** is used to sort marks in ascending order.
- Sorting is analyzed **pass by pass**.
- **Divide and Conquer Technique** is applied recursively to find **minimum and maximum marks**.

### Concepts Used
1. **Dynamic Memory Allocation**  
   - Memory for marks array is allocated at runtime using `malloc`.
2. **Quick Sort**  
   - Pivot element divides array into two halves.
   - Each half is sorted recursively.
   - Efficient: O(n log n) average time.
3. **Pass by Pass Analysis**  
   - After each partition, array is printed to show sorting progress.
4. **Divide and Conquer (Recursion)**  
   - Array is split into halves recursively.
   - Min and Max of each half are compared to find global Min/Max.

---

## Algorithm

### Quick Sort
1. Choose pivot (last element).
2. Partition array:
   - Elements smaller than pivot on left.
   - Elements greater than pivot on right.
3. Recursively apply Quick Sort on left and right sub-arrays.
4. Print array after each partition (to show passes).

### Divide & Conquer for Min/Max
1. If only one element → both min and max = element.
2. If two elements → compare and assign min/max.
3. If more than two elements:
   - Split array into two halves.
   - Recursively find min/max of each half.
   - Combine results.


## Input
- Number of students `n`.
- Marks of `n` students.

---

## Output

### Example
