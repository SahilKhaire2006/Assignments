# Sparse Matrix Representation and Simple Transpose

**Name:** Sahil Ashok Khaire  
**Roll No:** 13 
**Title:** Sparse Matrix Representation with Simple Transpose  

## Theory
A **sparse matrix** is a matrix in which most of the elements are zero.  
To save memory, only **non-zero elements** are stored along with their positions.

### Sparse Matrix Representation
- Represented using a structure with fields: **row, col, value**.
- The **first entry** (header) stores:
  - Total number of rows
  - Total number of columns
  - Total number of non-zero elements

## Transpose of Sparse Matrix

### Simple Transpose
- The transpose of a matrix is obtained by **interchanging rows and columns**.  
- In the sparse representation, this means swapping the row and column values.  
- The **simple transpose method** works by:
  1. For each column `c` in the original sparse matrix:
  2. Scan all elements, and if any element belongs to column `c`,  
     - Place it in the transpose by interchanging `(row, col)`.  

Limitation: Requires **repeated scanning**, making it less efficient for large matrices.

## Algorithm

### Sparse Matrix Creation
1. Input number of rows and columns.  
2. Read matrix elements.  
3. Count non-zero elements.  
4. Create sparse matrix in triplet form:  
   - First entry: `(rows, cols, non-zero count)`  
   - Next entries: `(row, col, value)` for each non-zero element.  


### Simple Transpose
1. Copy header of sparse matrix with swapped rows and columns.  
2. For each column index `c` from `0` to `cols-1`:  
   - For each element in sparse matrix:  
     - If element’s column = `c`,  
       - Place `(col, row, value)` into transpose.  
3. Print transpose sparse matrix.


## Input

