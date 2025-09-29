# Practical File – String Operations in C

**Name:** Sahil Ashok Khaire  
**Roll No.:** 13 
**Title:** String Operations (Length, Concatenation, Reverse, Palindrome, Copy) without using `<string.h>`

## Theory

A **string** in C is a sequence of characters terminated by a **null character (`\0`)**.  
In this program, we perform basic string operations **manually** without using predefined library functions from `<string.h>`.

### Operations Implemented:
1. **Length of string** → counts number of characters until `\0`.  
2. **Concatenation** → joins two strings.  
3. **Reverse** → prints the string in reverse order.  
4. **Palindrome check** → compares string with its reverse.  
5. **Copy** → copies one string into another.

## Algorithm

### 1. Length of String
1. Initialize `counter = 0`.  
2. Traverse string until `\0`.  
3. Increment counter.  
4. Return counter.

### 2. Concatenation
1. Find length of `str1`.  
2. Append each character of `str2` at the end of `str1`.  
3. Add `\0` at the end.

### 3. Reverse
1. Find length of string.  
2. Print characters from last index to first index.

### 4. Palindrome
1. Copy string into reverse order in another array.  
2. Compare each character of original and reverse.  
3. If all match → Palindrome. Otherwise, not Palindrome.

### 5. Copy
1. Traverse original string.  
2. Copy each character into new string.  
3. Add `\0` at the end.


## Input

