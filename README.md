**SafeDrive-Alert-System**
DATA STRUCTURE USED : Singly Linked list
Struct Definitions:

struct details: Contains information about a person and their vehicle, including name, blood group, mobile number, emergency contact number, and vehicle number.
struct node: Represents a node in a linked list. It contains a pointer to a struct details and a pointer to the next node.
Function Definitions:

Insert: Inserts a new node with the provided struct details into the linked list.
searching: Searches for a vehicle number in the linked list. If a match is found, it writes a message to the accident.txt file.
display: Displays the vehicle numbers stored in the linked list.
Main Function:

Reads data from the acc.csv file and populates an array of struct details (d).
Inserts each element of the array into a linked list using the Insert function.
Prompts the user to enter a vehicle number and searches for it using the searching function.
CSV File Processing:

Uses fgets and strtok to read and parse data from the CSV file.
The CSV file is expected to have columns in the order: name, blood group, mobile number, emergency contact number, and vehicle number.
File Operations:

It writes information about an accident to the accident.txt file if a matching vehicle number is found.
Important Note:

The code assumes that the CSV file and accident text file are present in the same directory as the executable.
