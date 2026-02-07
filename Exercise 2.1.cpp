#include <iostream>
#include<cstring>
using namespace std;

struct Book {
    int isbn;
    char title[50];
    char author[50];
    int year;

    Book *prev;
    Book *next;
};

Book *start = NULL;
Book *temp, *current;
void insertBook() {
    temp = new Book;

    cout << "Enter ISBN: ";
    cin >> temp->isbn;

    cout << "Enter Title ";
    cin >> temp->title;

    cout << "Enter Author ";
    cin >> temp->author;

    cout << "Enter Year: ";
    cin >> temp->year;

    temp->next = NULL;
    temp->prev = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        current = start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
        temp->prev = current;
    }

    cout << "Book Added"<<endl;
}
void searchBook() {
    int choice;
    cout << "\n1. Search by ISBN\n2. Search by Title\nEnter choice: ";
    cin >> choice;

    current = start;

    if (choice == 1) {
        int isbn;
        cout << "Enter ISBN: ";
        cin >> isbn;

        while (current != NULL) {
            if (current->isbn == isbn) {
                cout << "\nBook Found!\n";
                cout << "ISBN: " << current->isbn << endl;
                cout << "Title: " << current->title << endl;
                cout << "Author: " << current->author << endl;
                cout << "Year: " << current->year << endl;
                return;
            }
            current = current->next;
        }
    }

    else if (choice == 2) {
        char t[50];
        cout << "Enter Title: ";
        cin >> t;

        while (current != NULL) {
            if (strcmp(current->title, t) == 0) {
                cout << "Book Found!"<<endl;
                cout << "ISBN: " << current->isbn << endl;
                cout << "Title: " << current->title << endl;
                cout << "Author: " << current->author << endl;
                cout << "Year: " << current->year << endl;
                return;
            }
            current = current->next;
        }
    }

    cout << "Book Not Found!"<<endl;
}
void modifyBook() {
    int isbn;
    cout << "Enter ISBN of book to modify: ";
    cin >> isbn;

    current = start;

    while (current != NULL) {
        if (current->isbn == isbn) {
            cout << "Enter New Title: ";
            cin >> current->title;

            cout << "Enter New Author: ";
            cin >> current->author;

            cout << "Enter New Year: ";
            cin >> current->year;

            cout << "Book Updated!"<<endl;
            return;
        }
        current = current->next;
    }

    cout << "Book Not Found!"<<endl;
}
void displayBooks() {
    current = start;
    int count = 0;

    if (current == NULL) {
        cout << "No Books"<<endl;
        return;
    }

    cout << " Book List"<<endl;

    while (current != NULL) {
        cout << "\nBook " << count + 1 << endl;
        cout << "ISBN: " << current->isbn << endl;
        cout << "Title: " << current->title << endl;
        cout << "Author: " << current->author << endl;
        cout << "Year: " << current->year << endl;

        count++;
        current = current->next;
    }

    cout << "\nTotal Books: " << count << endl;
}
int main() {
    int choice;

    do {
        cout << "1. Insert Book"<<endl;
        cout << "2. Search Book"<<endl;
        cout << "3. Modify Book"<<endl;
        cout << "4. Display Books"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertBook();
			 break;
            case 2: searchBook();
			 break;
            case 3: modifyBook();
			 break;
            case 4: displayBooks(); 
			break;
            case 5: cout << "Goodbye!"<<endl;
			 break;
            default: cout << "Invalid!"<<endl;
        }

    } while (choice != 5);

    return 0;
}
