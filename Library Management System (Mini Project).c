#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int available; // 1 = available, 0 = issued
};

struct Book books[100];
int count = 0;

void addBook() {
    printf("\n--- Add New Book ---\n");
    printf("Enter Book ID: ");
    scanf("%d", &books[count].id);
    printf("Enter Title: ");
    scanf(" %[^\n]s", books[count].title);
    printf("Enter Author: ");
    scanf(" %[^\n]s", books[count].author);
    books[count].available = 1;
    count++;
    printf("Book added successfully!\n");
}

void displayBooks() {
    if(count == 0) {
        printf("\nNo books found.\n");
        return;
    }
    printf("\n--- Book List ---\n");
    for(int i=0;i<count;i++) {
        printf("ID: %d | Title: %s | Author: %s | %s\n",
               books[i].id, books[i].title, books[i].author,
               books[i].available ? "Available" : "Issued");
    }
}

void searchBook() {
    int id;
    char title[50];
    int found = 0;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    for(int i=0;i<count;i++) {
        if(books[i].id == id) {
            printf("Book Found! Title: %s | Author: %s | %s\n",
                   books[i].title, books[i].author,
                   books[i].available ? "Available" : "Issued");
            found = 1;
            break;
        }
    }
    if(!found) printf("Book not found.\n");
}

void issueBook() {
    int id, found = 0;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    for(int i=0;i<count;i++) {
        if(books[i].id == id) {
            if(books[i].available) {
                books[i].available = 0;
                printf("Book issued successfully!\n");
            } else {
                printf("Book is already issued.\n");
            }
            found = 1;
            break;
        }
    }
    if(!found) printf("Book not found.\n");
}

void returnBook() {
    int id, found = 0;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    for(int i=0;i<count;i++) {
        if(books[i].id == id) {
            if(!books[i].available) {
                books[i].available = 1;
                printf("Book returned successfully!\n");
            } else {
                printf("Book was not issued.\n");
            }
            found = 1;
            break;
        }
    }
    if(!found) printf("Book not found.\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n=== Library Management System ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
