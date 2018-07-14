# Institutional-Level-Seat-Allocation
This system allocates seat to the students based their preferences in various branches and their respective scores
ENGINEERING ADMISSION ROUNDS AND STREAM ALLOCATION

INTRODUCTION:
Following is the project that will assign streams to students based on their preferences for admission in a certain college. 
It simulates the institutional rounds and automates the entire process based on the input of the students.

WORKING:
1.	The program takes input of data of students including their name, cet score, application number and preferences for streams. This input is read from a .csv file that already stores all the information.
2.	The data file is linked with the program code and is read using File Handling. 
3.	The program then sorts all the students using Bubble Sort in a decreasing order on the basis of cet marks and correspondingly ranks them.
4.	The students are then assigned streams based on their respective first preferences. 
5.	The program then asks user for logging in as either a student or a college personnel.
6.	If the user is a student, then the program asks for the application number and displays the branch assigned to the student along with their application number and rank in a tabular form as the output. 
7.	If user selects college login, then the program asks the user to enter a password. If the entered password is correct, the program continues, else it terminates. 
8.	Once the user is authorised, application numbers of all students assigned to each branch and number of seats vacant in each branch are displayed. It also displays the application  numbers of students not assigned any branch.
9.	It then asks the user for the number of rounds to be conducted.
10.	In case number of rounds is more than 1, the program asks each student if he is willing to continue to go to the next round.
11.	If the branch the student is willing to pursue has availability, then the seat is assigned.
12.	Once the assigning process is completed, the program again asks for a student or college login and the process is repeated till the number of rounds are completed. 



MAIN CONCEPTS UTILIZED:

Array of structures
Bubble sorting of structure array
File handling: Taking Input from a Excel File 
        Converting the excel file to .csv format (comma separated values) and then use                 file handling.
Authentication of the user
String comparison using the standard library of string.h
C Program Constructs used: If-else condition, for loops, switch case, call to functions

CONCLUSION:

Using the above program we can successfully conduct the admission process of any college and assign students the right stream on the basis of their merit and preferences.
