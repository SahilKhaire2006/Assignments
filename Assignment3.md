# Matrix Multiplication (Row-Major & Column-Major)

**Name:** Sahil Ashok Khaire  
**Roll No:** 13  
**Title:** Implementation of Matrix Multiplication using Row-Major and Column-Major Representation  


## Theory
Matrix multiplication is a binary operation that produces a matrix from two matrices.  
If `A` is of order `(m × n)` and `B` is of order `(n × p)`, then their product `C = A × B` is of order `(m × p)`.

- **Row-Major Representation:**  
  Stores matrix elements row by row in contiguous memory locations.

- **Column-Major Representation:**  
  Stores matrix elements column by column in contiguous memory locations.

**Condition for multiplication:**  
Number of columns of first matrix = Number of rows of second matrix  


## Algorithm

1. Start  
2. Input row and column sizes of two matrices.  
3. Check if `c1 == r2`, else multiplication is not possible.  
4. Dynamically allocate memory for matrices.  
5. Input elements for both matrices.  

6. Perform multiplication:

   **Row-Major Multiplication:**  
   a. For each row `i` of first matrix:  
      - For each column `j` of second matrix:  
        - Initialize `C[i][j] = 0`  
        - For `k = 0` to `c1-1`:  
          - `C[i][j] += A[i][k] * B[k][j]`  
   b. Store the result in dynamically allocated 2D array.  

   **Column-Major Multiplication:**  
   a. Store both matrices as 1D arrays in **column-major order** using `IDX(i,j,rows)` formula:  
      - `IDX(i,j,rows) = j*rows + i`  
   b. For each row `i` and column `j`:  
      - Initialize `C[IDX(i,j,rows)] = 0`  
      - For `k = 0` to `c1-1`:  
        - `C[IDX(i,j,rows)] += A[IDX(i,k,rows)] * B[IDX(k,j,rows)]`  
   c. Store the result in dynamically allocated 1D array representing column-major matrix.  

7. Print the resulting matrices.  
8. Free all dynamically allocated memory.  
9. Stop  

