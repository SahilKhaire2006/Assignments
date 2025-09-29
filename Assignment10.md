# Sorting Employees by Average of Height and Weight

**Name:** Sahil Ashok Khaire  
**Roll No:** 13 

## Aim
To arrange a list of employees as per the average of their height and weight using **Selection Sort** and **Merge Sort** and analyze their time complexities.


## Theory
- **Selection Sort:**  
  - Finds the minimum element and swaps it with the first unsorted element.
  - Time complexity: O(n²)
- **Merge Sort:**  
  - Divides the list into halves, recursively sorts, and merges them.
  - Time complexity: O(n log n)

- **Average of Height and Weight:**  
  avg = (height + weight) / 2  


## Algorithm

### Selection Sort
1. Start
2. Input number of employees n.
3. Assign random height and weight for employees.
4. Compute avg = (height + weight)/2.
5. For i = 0 to n-1:
   - Find min avg in remaining array.
   - Swap with current position.
   - Print array after each pass.
6. Stop.

### Merge Sort
1. **Start**  
2. **Input** an array of employees (`Employee_sak`) with attributes including `avg_sak`.  
3. **Check** if the left index `<` right index:  
   - If yes, continue dividing;  
   - If no, stop (base case reached).  
4. **Find** the middle index:  
   - `mid_sak = left_sak + (right_sak - left_sak) / 2`  
5. **Recursively apply merge sort**:  
   - Call `mergeSort_sak(emp_sak, left_sak, mid_sak)` → Sort left half  
   - Call `mergeSort_sak(emp_sak, mid_sak+1, right_sak)` → Sort right half  
6. **Merge the two halves** using `merge_sak`:  
   - Create two temporary arrays: `L_sak[]` and `R_sak[]`  
   - Copy left half elements into `L_sak[]` and right half elements into `R_sak[]`  
   - Compare elements of `L_sak` and `R_sak` one by one:  
     - If `L_sak[i].avg_sak <= R_sak[j].avg_sak`, place `L_sak[i]` into original array  
     - Else, place `R_sak[j]` into original array  
   - Continue until one of the temporary arrays is exhausted  
   - Copy any remaining elements from `L_sak` or `R_sak` back to the original array  
7. **Free temporary arrays** (`L_sak` and `R_sak`) to release memory.  
8. **Repeat** until the whole array is sorted.  
9. **Stop**.  

## Input 

### Output
