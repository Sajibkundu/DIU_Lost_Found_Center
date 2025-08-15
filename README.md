DIU LOST & FOUND CENTER 
================================================================================

##  PROJECT INFORMATION
**Project Name:** DIU Lost & Found Center. 
**Developer:** Sajib Kumar Kundu  
**Student ID:** 242-35-795  
**Program:** B.Sc in Software Engineering (SWE)  
**University:** Daffodil International University (DIU)  
**Course Teacher:** Rantu Das  
**Language:** C Programming  
**Date:** August 2025  

================================================================================

##  PROJECT OVERVIEW
A comprehensive console-based application for managing lost and found items at DIU campus. The system enables students to report lost items, search for belongings, and efficiently manage the entire lost & found process through digital automation.

**Key Benefits:**
- Digitized lost & found operations
- Efficient queue management for item verification
- Activity tracking and administrative oversight
- Automated item categorization

================================================================================

##  DATA STRUCTURES IMPLEMENTED

| Structure | Implementation | Purpose |
|-----------|----------------|---------|
| **Linked List** | Dynamic item storage | Store lost items with flexible memory allocation |
| **Circular Queue** | Waiting line management | FIFO processing of verification requests |
| **Stack** | Activity logging | Track system operations and recent activities |
| **Array** | Category management | Fixed storage for item categories and counters |

================================================================================

## ✨ SYSTEM FEATURES

### 👤 **User Functions**
-  Report lost items with complete details
-  Search items by name
-  Join verification waiting line
- View categorized item statistics

### 🔒 **Admin Functions** (Login: admin/diu123)
-  Delete items from system
-  Process waiting queue
-  View complete activity log
- 🛡 Administrative oversight

### 🤖 **Smart Features**
- Auto-categorization (Books, Mobile, Keys, Others)
- Real-time activity logging
- Memory management optimization
- Input validation & error handling

================================================================================

## QUICK START

### Compilation:
```bash
gcc DIU_Lost_Found.c -o DIU_Lost_Found
```

### Execution:
```bash
./DIU_Lost_Found        # Linux/Mac
DIU_Lost_Found.exe      # Windows
```

### Requirements:
- GCC Compiler
- 256 MB RAM minimum
- Console/Terminal support

================================================================================

## SYSTEM ARCHITECTURE

```c
struct LostItem {
    char itemName[50];      // Item description
    char ownerName[50];     // Owner's name
    char universityId[15];  // DIU ID
    char phone[15];         // Contact number
    char category[50];      // Auto-assigned category
    struct LostItem* next;  // Linked list pointer
};
```

**Core Limits:**
- Categories: 4 types
- Queue Capacity: 50 people
- Activity Log: 50 entries
- Name Length: 50 characters

================================================================================

## LEARNING OUTCOMES
- Dynamic data structure implementation
- Memory management (malloc/free)
-  Pointer manipulation and linked operations
- Queue/Stack real-world applications
- String processing and categorization
- Administrative access control
- system design for practical problems

================================================================================

##  PROGRAM WORKFLOW

1. **Initialize** → Set up data structures and counters
2. **Main Menu** → Display options and route user requests
3. **Operations** → Process user/admin functions
4. **Logging** → Track all activities in stack
5. **Cleanup** → Free memory and exit gracefully


## ACKNOWLEDGMENTS
- **Rantu Das** - Course Teacher & Project Guide
- **Daffodil International University** - Academic Support
- **Software Engineering Department** - Resources & Curriculum

=

## 📞 CONTACT
**Sajib Kumar Kundu**  
📧 kundu242-35-795@diu.edu.bd  
🎓 Department of Software Engineering  
🏫 Daffodil International University  



## 📄 PROJECT STATUS
**Status:** Completed  
**Version:** 1.0  
**Updated:** August 15, 2025  
**Platform:** Cross-platform  

**Future Enhancements:** File persistence, GUI interface, Database integration



© 2025 Sajib Kumar Kundu | Academic Project | DIU Software Engineering

================================================================================
