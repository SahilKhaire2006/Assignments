# Sparse Matrix Representation and Fast Transpose

**Name:** Sahil Ashok Khaire  
**Roll No:** 13 
**Title:** Sparse Matrix Representation with Fast Transpose .

## Theory
A **sparse matrix** is a matrix in which most of the elements are zero.  
Instead of storing all elements, we only store non-zero elements with their positions.

### Sparse Matrix Representation
- Represented using a structure with **row, column, value**.
- First element (header) stores: total rows, total columns, and count of non-zero elements.

### Transpose of Sparse Matrix
- **Simple Transpose:** Interchange row and column indices by scanning column-wise.  
- **Fast Transpose:** Optimized version using `rowterms` and `startpos` arrays to directly place elements without repeated scanning.

## Algorithm

### Sparse Matrix Creation
1. Read `rows` and `cols`.  
2. Input matrix elements and count non-zero values.  
3. Store matrix in triplet form `(row, col, value)`.  

###  Fast Transpose

1. Initialize arrays `rowterms[col] = 0` and `startpos[col]`.  
2. For each element `(row, col, value)` → increment `rowterms[col]`.  
3. Compute starting positions:  
   - `startpos[0] = 1`  
   - `startpos[i] = startpos[i-1] + rowterms[i-1]`  
4. For each element in sparse matrix:  
   - Place it directly at `startpos[col]` in transposed matrix.  
   - Increment `startpos[col]`.

## Input
