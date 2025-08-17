#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_categories 4
#define Max_name_len 50
#define Max_id_len 15
#define Max_phone_len 15
#define Max_queue_size 50
#define Max_stack_size 50
#define Admin_pass "diu123"

//here i usee  Structure with info
struct LostItem {
    char itemName[Max_name_len];
    char ownerName[Max_name_len];
    char universityId[Max_id_len];
    char phone[Max_phone_len];
    char category[Max_name_len];
    struct LostItem* next;
};

// here i use circular queue for waiting line 
char waitingQueue[Max_queue_size][Max_name_len];
int queueFront = -1, queueRear = -1;

//here iuse stack for activity logging.
char activityLog[Max_stack_size][100];
int stackTop = -1;

// linked list of the lost items.,
struct LostItem* head = NULL;
int itemCount = 0;
char categories[Max_categories][20] = {"Books", "Mobile", "Keys", "Others"};
int categoryCount[Max_categories] = {0, 0, 0, 0};


void clearScreen() {
    system("cls");
}

 //to push new activity.
void pushActivity(const char* message) {
    if (stackTop >= Max_stack_size - 1) {
        printf("Activity log overflow. Unable to log new activities.\n");
        return;
    }
    stackTop++;
    strcpy(activityLog[stackTop], message);
}

//peek in stack
char* peekActivity() {
    if (stackTop == -1) {
        return "No recent activity.";
    }
    return activityLog[stackTop];
}
//enque
void enqueuePerson(const char* name) {
    if ((queueRear + 1) % Max_queue_size == queueFront) {
        printf("The waiting line is full. Please try again later.\n");
        return;
    }
    if (queueFront == -1) {
        queueFront = 0;
    }
    queueRear = (queueRear + 1) % Max_queue_size;
    strcpy(waitingQueue[queueRear], name);

    char logMessage[100];
    sprintf(logMessage, "%s joined the checking line.", name);
    pushActivity(logMessage);
    printf("Added to queue at position: %d\n", queueRear);
}



void dequeuePerson() {
    if (queueFront == -1) {
        printf("No one is currently in the queue.\n");
        return;
    }
    char personName[Max_name_len];
    strcpy(personName, waitingQueue[queueFront]);
    printf("Processing: %s\n", personName);

    if (queueFront == queueRear) {
        queueFront = -1;
        queueRear = -1;
    } else {
        queueFront = (queueFront + 1) % Max_queue_size;
    }

    char logMessage[100];
    sprintf(logMessage, "A person from the queue was processed.");
    pushActivity(logMessage);
}


void freeMemory() {
    struct LostItem* currentItem = head;
    while (currentItem != NULL) {
        struct LostItem* temp = currentItem;
        currentItem = currentItem->next;
        free(temp);
    }
    head = NULL;
}


int getCategoryIndex(const char* itemName) {
    if (strstr(itemName, "Book") != NULL || strstr(itemName, "book") != NULL) return 0;
    if (strstr(itemName, "Mobile") != NULL || strstr(itemName, "mobile") != NULL) return 1;
    if (strstr(itemName, "Key") != NULL || strstr(itemName, "key") != NULL) return 2;
    return 3;
}


void reportLostItem() {
    struct LostItem* newItem = (struct LostItem*)malloc(sizeof(struct LostItem));
    if (newItem == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    printf("Please enter your full name: ");
    scanf(" %[^\n]", newItem->ownerName);
    printf("Enter your university ID: ");
    scanf("%s", newItem->universityId);
    printf("Enter the item name you lost: ");
    scanf(" %[^\n]", newItem->itemName);
    printf("Enter your phone number: ");
    scanf("%s", newItem->phone);

    int categoryIndex = getCategoryIndex(newItem->itemName);
    strcpy(newItem->category, categories[categoryIndex]);
    categoryCount[categoryIndex]++;

    newItem->next = head;
    head = newItem;
    itemCount++;

    char logMessage[100];
    sprintf(logMessage, "%s reported a lost item: %s", newItem->ownerName, newItem->itemName);
    pushActivity(logMessage);

    printf("Item successfully reported! Thank you for helping us.\n");
}


void searchByName() {
    char searchName[Max_name_len];
    printf("Enter the item name you're looking for: ");
    scanf(" %[^\n]", searchName);

    struct LostItem* current = head;
    int foundCount = 0;

    printf("Searching for items named: %s\n", searchName);
    while (current != NULL) {
        if (strcmp(current->itemName, searchName) == 0) {
            printf("Found: %s\n", current->itemName);
            printf("  Owner: %s (ID: %s)\n", current->ownerName, current->universityId);
            printf("  Phone: %s\n", current->phone);
            foundCount++;
        }
        current = current->next;
    }

    if (foundCount == 0) {
        printf("No items found with that name. Please try again.\n");
    }
}

void displayCategories() {
    printf("\nItem Category Counts:\n");
    for (int i = 0; i < Max_categories; i++) {
        printf("%s: %d items\n", categories[i], categoryCount[i]);
    }
}

// this is admin functions
void deleteItem() {
    char itemToDelete[Max_name_len];
    printf("Enter the name of the item to delete: ");
    scanf(" %[^\n]", itemToDelete);

    struct LostItem* current = head;
    struct LostItem* prev = NULL;

    while (current != NULL && strcmp(current->itemName, itemToDelete) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Item not found.\n");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    int categoryIndex = getCategoryIndex(current->itemName);
    categoryCount[categoryIndex]--;

    printf("Item '%s' deleted successfully.\n", current->itemName);
    char logMessage[100];
    sprintf(logMessage, "Admin deleted item: %s", current->itemName);
    pushActivity(logMessage);
    free(current);
    itemCount--;
}

void viewAllActivities() {
    if (stackTop == -1) {
        printf("Activity log is empty.\n");
        return;
    }
    printf("\nActivity Log:\n");
    for (int i = stackTop; i >= 0; i--) {
        printf("- %s\n", activityLog[i]);
    }
}

void adminPanel() {
    int choice;
    do {
        printf("\n--- Admin Panel ---\n");
        printf("1. Delete Item\n");
        printf("2. Process Queue\n");
        printf("3. View All Activities\n");
        printf("0. Logout\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearScreen();
        switch (choice) {
            case 1:
                deleteItem();
                break;
            case 2:
                dequeuePerson();
                break;
            case 3:
                viewAllActivities();
                break;
            case 0:
                printf("Logged out of the admin panel.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);
}

void adminLogin() {
    char username[20], password[20];
    printf("Admin Username: ");
    scanf("%s", username);
    printf("Admin Password: ");
    scanf("%s", password);
    if (strcmp(username, "admin") == 0 && strcmp(password, Admin_pass) == 0) {
        printf("Login successful. Welcome, admin!\n");
        adminPanel();
    } else {
        printf("Invalid credentials. Access denied.\n");
    }
}

//this is the main function 

int main() {
    int choice;
    queueFront = -1;
    queueRear = -1;
    stackTop = -1;

    do {
        printf("\n=== Diu Lost & Found Center ===\n");
        printf("1. Report Lost Item\n");
        printf("2. Search Item by Name\n");
        printf("3. Join Checking Line\n");
        printf("4. Display Categories & Count\n");
        printf("5. Admin Login\n");
        printf("6. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);
        clearScreen();
        switch (choice) {
            case 1:
                reportLostItem();
                break;
            case 2:
                searchByName();
                break;
            case 3:
                {
                    char name[Max_name_len];
                    printf("Enter your name to join the line: ");
                    scanf(" %[^\n]", name);
                    enqueuePerson(name);
                }
                break;
            case 4:
                displayCategories();
                break;
            case 5:
                adminLogin();
                break;
            case 6:
                printf("Thank you for using Diu Lost & Found Center!\n");
                freeMemory();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
