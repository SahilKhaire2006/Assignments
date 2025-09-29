# Student Management System

**Name:** Sahil Ashok Khaire  
**Roll No:** 13

## Title  
Program to store, display, and search student information using structures and dynamic memory allocation in C.  

## Theory  
This program demonstrates:  

- **Structures** → used to group related student information.  
- **Dynamic Memory Allocation (`malloc`)** → memory is allocated at runtime depending on how many students the user wants to store.  
- **Random Data Assignment** → names, cities, branches, etc. are assigned using `rand()`.  
- **String Handling** → `strcpy` to copy strings and `strcmp` to compare strings.  
- **Menu-driven approach** → provides options to search students by roll number, search by name, or display all student records.  

This program is useful for understanding how to manage and organize real-life student databases.  

## Algorithm  

1. Start  
2. Define a `Student` structure with fields: roll number, name, city, class, branch, division, and age.  
3. Ask the user how many student records are required.  
4. Dynamically allocate memory for that many students using `malloc()`.  
5. Generate random student data (names, cities, branches, etc.).  
6. Display all student data.  
7. Show a menu with options:  
   - Search by Roll Number  
   - Search by Name  
   - Print all data  
   - Exit  
8. If search by roll number:  
   - Input roll number  
   - Traverse student array  
   - If match found → print data, else show "Not Found".  
9. If search by name:  
   - Input name  
   - Traverse student array  
   - If match found → print data, else show "Not Found".  
10. If "Print all data" → print details of all students.  
11. Repeat until user selects Exit.  
12. Free allocated memory.  
13. Stop.  


## Input  

- Number of student records (`n`)  
- Menu choices (roll number, name, all data, exit)  


## Output  

- Displays all student records  
- Displays specific record when searched by roll number or name  

