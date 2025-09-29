# Magic Square (Odd Order) Program

**Name:** Sahil Ashok Khaire  
**Roll No:** 13 

## Title  
Program to generate a Magic Square of odd order using dynamic memory allocation in C.  

## Theory  
- A **Magic Square** is an arrangement of numbers in a square grid where the sum of each row, column, and diagonal is the same.  
- This program uses the **Siamese method** (also known as De la Loubère’s method) to construct an odd-order magic square.  
- **Dynamic memory allocation (`malloc`)** is used to allocate memory for the square.  
- For an `n x n` square (where `n` is odd):  
  - Start at the middle of the first row.  
  - Place numbers sequentially from 1 to `n*n`.  
  - The next number goes **up one row and right one column** (with wrap-around).  
  - If the calculated cell is already filled, move **down one row** instead.  

## Algorithm  

### 1. Odd Order
1. Start  
2. Read size `n` of the square (must be odd).  
3. Allocate a 2D array (`magic[n][n]`) dynamically.  
4. Initialize all cells with 0.  
5. Place `1` at position `(0, n/2)`.  
6. For each number from `2` to `n*n`:  
   - Compute new position: `(i-1, j+1)` with wrap-around.  
   - If the new cell is already filled, move down `(i+1, j)` instead.  
   - Place the number in the new cell.  
7. Print the magic square.  
8. Free all dynamically allocated memory.  
9. Stop.  

### 2. Doubly Even Order (n % 4 == 0)  
1. Start  
2. Read size `n` (must be a multiple of 4).  
3. Allocate a 2D array (`magic[n][n]`) dynamically.  
4. Fill the matrix sequentially with numbers from 1 to n*n.  
5. For each 4x4 sub-square, invert numbers at positions forming the diagonals:  
   - Replace value with `(n*n + 1 - value)`  
6. Print the magic square.  
7. Free all dynamically allocated memory.  
8. Stop.  

### 3. Singly Even Order (n % 4 == 2)  
1. Start  
2. Read size `n` (even but not a multiple of 4).  
3. Divide the square into four sub-squares of size n/2 x n/2.  
4. Fill each sub-square using the **Odd Order (Siamese) method**.  
5. Swap specific columns between left and right sub-squares according to rules:  
   - Swap the first `k` columns in left quadrants  
   - Swap the last `k-1` columns in right quadrants (where k = n/4)  
6. Print the magic square.  
7. Free all dynamically allocated memory.  
8. Stop.  


## Input / Output

