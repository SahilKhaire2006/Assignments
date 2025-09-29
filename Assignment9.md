# Bubble Sort – Assigning Roll Numbers Based on Marks

**Name:** Sahil Ashok Khaire  
**Roll No:** 13 

## Aim
To write a program using **Bubble Sort algorithm** to assign roll numbers to students of a class according to their marks in the previous year.  
The topper should get Roll No. 1.


## Theory
- **Bubble Sort** is a comparison-based algorithm.  
- In each pass, adjacent elements are compared and swapped if they are in the wrong order.  
- Here, we sort **in descending order of marks** so that the highest marks come first.  
- After sorting, roll numbers are assigned sequentially (1 to n).

## Algorithm
1. Start  
2. Input number of students `n`.  
3. Generate random marks and assign names.  
4. Apply **Bubble Sort**:  
   - Repeat for `n-1` passes.  
   - In each pass, compare adjacent marks.  
   - Swap if the earlier mark is less than the next one (for descending order).  
   - Print list after each pass.  
5. Assign roll numbers: first student → Roll 1, second → Roll 2, …  
6. Display the final roll list.  
7. Stop  


## Input 

### Output
