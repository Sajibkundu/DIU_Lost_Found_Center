DIU LOST & FOUND CENTER 
================================================================================

PROJECT INFORMATION:
-------------------
Project Name    : DIU Lost & Found Center Management System
Developer       : Sajib Kumar Kundu
GitHub Username : @Sajibkundu
Student ID      : 242-35-795
Program         : B.Sc in Software Engineering (SWE)
Department      : Department of Software Engineering
University      : Daffodil International University (DIU)
Course Teacher  : Rantu Das
Project Type    : Semester Short Project
Language        : C Programming
Development Date: 2025-08-16 16:57:52 UTC

================================================================================

PROJECT OVERVIEW:
----------------
A comprehensive console-based application designed to modernize the lost and found 
operations at Daffodil International University. The system replaces traditional 
paper-based tracking with digital management, providing efficient item reporting, 
searching, and administrative oversight.

Core Objectives:
- Streamline lost item reporting process
- Enable quick item search and retrieval
- Manage verification queues systematically
- Provide administrative control and monitoring
- Demonstrate practical data structure applications

================================================================================

DATA STRUCTURES IMPLEMENTATION:
------------------------------

1. LINKED LIST (Dynamic Storage)
   Location: struct LostItem with next pointer
   Global Variable: struct LostItem* head = NULL
   
   Key Functions:
   - reportLostItem(): Creates new node and inserts at head
   - searchByName(): Traverses list for item matching
   - deleteItem(): Removes node and updates links
   - freeMemory(): Deallocates all nodes before exit
   
   Advantages: Dynamic memory, unlimited items, efficient insertion

2. ARRAY (Static Storage)
   Implementation: 
   - categories[4][20]: {"Books", "Mobile", "Keys", "Others"}
   - categoryCount[4]: {0, 0, 0, 0} for counting items
   
   Key Functions:
   - getCategoryIndex(): Keyword-based categorization logic
   - displayCategories(): Shows category-wise statistics
   
   Benefits: Fast access, predefined categories, O(1) lookup

3. CIRCULAR QUEUE (FIFO Processing)
   Implementation: waitingQueue[50][50] with front/rear pointers
   Variables: queueFront = -1, queueRear = -1
   
   Key Functions:
   - enqueuePerson(): Adds person to verification line
   - dequeuePerson(): Processes next person in queue
   
   Features: Circular array prevents memory waste, handles 50 people

4. STACK (LIFO Activity Tracking)
   Implementation: activityLog[50][100] with top pointer
   Variable: stackTop = -1
   
   Key Functions:
   - pushActivity(): Logs new system activity
   - peekActivity(): Views most recent activity
   - viewAllActivities(): Displays complete activity history
   
   Purpose: Chronological tracking, system monitoring, audit trail

================================================================================

SYSTEM FEATURES & FUNCTIONALITY:
-------------------------------

USER INTERFACE:
- Menu-driven console interface
- Input validation and error handling
- Clear screen functionality for better UX
- Informative messages and confirmations

USER OPERATIONS:
1. Report Lost Item
   - Collects: Name, ID, Item Description, Phone
   - Auto-categorizes based on keywords
   - Adds to linked list and updates counters
   - Logs activity for tracking

2. Search Item by Name
   - Traverses entire linked list
   - Performs exact string matching
   - Displays all matching items with owner details
   - Shows search results count

3. Join Checking Line
   - Adds person to circular queue
   - Shows queue position
   - Logs joining activity
   - Handles queue overflow

4. Display Categories & Count
   - Shows all 4 categories with item counts
   - Real-time statistics
   - Array-based fast retrieval

ADMIN OPERATIONS:
1. Secure Login System
   - Username: "admin"
   - Password: "diu123" (defined constant)
   - Access control for sensitive operations

2. Delete Item
   - Search and remove from linked list
   - Update category counters
   - Log deletion activity
   - Proper memory deallocation

3. Process Queue
   - FIFO processing of waiting people
   - Queue status management
   - Activity logging for processed person

4. View All Activities
   - Complete system activity history
   - Stack-based chronological display
   - Administrative oversight capability

================================================================================

TECHNICAL SPECIFICATIONS:
------------------------

Memory Management:
- Dynamic allocation using malloc() for lost items
- Proper deallocation with free() in cleanup
- Memory leak prevention with freeMemory() function
- NULL pointer checks for allocation failures

String Processing:
- Case-insensitive keyword matching for categorization
- Safe string operations using strncpy and bounds checking
- Pattern matching with strstr() for category detection
- Input sanitization with scanf format specifiers

Algorithm Complexity:
- Item insertion: O(1) - head insertion in linked list
- Item search: O(n) - linear traversal required
- Queue operations: O(1) - direct array access
- Stack operations: O(1) - direct array access

Error Handling:
- Memory allocation failure detection
- Queue overflow/underflow protection
- Stack overflow protection
- Input validation and bounds checking

================================================================================

COMPILATION AND EXECUTION:
-------------------------

Prerequisites:
- GCC Compiler (version 4.0 or higher)
- Standard C library support
- Console/Terminal environment
- Minimum 256 MB RAM

Compilation Command:
```bash
gcc -o DIU_Lost_Found DIU_Lost_Found.c
```

Execution Commands:
```bash
# Linux/Mac
./DIU_Lost_Found

# Windows
DIU_Lost_Found.exe
```

Testing Environment:
- Tested on Windows 10/11
- Verified on Ubuntu Linux
- Compatible with macOS terminal

================================================================================

SYSTEM ARCHITECTURE:
-------------------

Data Flow:
1. User Input → Input Validation → Function Routing
2. Data Processing → Structure Updates → Activity Logging
3. Result Display → Memory Management → Return to Menu

Memory Layout:
- Static: Arrays for categories, queue, stack
- Dynamic: Linked list nodes allocated as needed
- Global: Pointers and counters for system state

File Organization:
- Single source file for simplicity
- All functions logically grouped
- Clear separation between user and admin functions
- Modular design for easy maintenance

Constants and Limits:
```c
#define Max_categories 4        // Number of item categories
#define Max_name_len 50         // Maximum name/item length
#define Max_queue_size 50       // Queue capacity
#define Max_stack_size 50       // Activity log capacity
#define Admin_pass "diu123"     // Admin password
```

================================================================================

LEARNING OUTCOMES:
-----------------
- Practical implementation of fundamental data structures
- Understanding of memory management in C programming
- Application of algorithms for searching and sorting
- System design principles for real-world problems
- User interface design for console applications
- Administrative access control implementation
- Activity logging and system monitoring techniques

================================================================================

PROJECT STRUCTURE:
-----------------
Repository: Sajibkundu/DIU_Lost_Found_Center
Main File: DIU_Lost_Found.c (Complete implementation)
Documentation: README.md (This file)
Language: ANSI C (Compatible with all C compilers)

================================================================================

ACKNOWLEDGMENTS:
---------------
Academic Supervisor: Rantu Das
Institution: Daffodil International University
Department: Software Engineering
Course: Data Structures and Algorithms
Semester: Current Academic Session 2024-25

================================================================================

PROJECT STATUS:
--------------
Development Status: Completed and Tested
Version: 1.0 Release
Last Updated: 2025-08-16 16:57:52 UTC
Platform Support: Cross-platform (Windows/Linux/macOS)
Code Quality: Production-ready with error handling

Future Enhancements:
- File-based data persistence
- Advanced search filters
- GUI interface development
- Network connectivity features

================================================================================

DEVELOPER CONTACT:
-----------------
Name: Sajib Kumar Kundu
Student ID: 242-35-795
Email: kundu242-35-795@diu.edu.bd
GitHub: @Sajibkundu
Department: Software Engineering
University: Daffodil International University
Location: Dhaka, Bangladesh

================================================================================

COPYRIGHT & LICENSE:
-------------------
Copyright © 2025 Sajib Kumar Kundu
Academic Project - Educational Use Only
Submitted to Daffodil International University
Software Engineering Department

All rights reserved. This project is developed for academic purposes and 
evaluation. Unauthorized reproduction or commercial use is prohibited.

================================================================================
