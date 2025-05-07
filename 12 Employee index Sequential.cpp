#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const char* DATA_FILE = "employee_data.txt";
const char* INDEX_FILE = "index_data.txt";

struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};

struct IndexEntry {
    int id;
    int position;
};

void addEmployee() {
    Employee emp;
    fstream dataFile(DATA_FILE, ios::out | ios::app | ios::binary);
    fstream indexFile(INDEX_FILE, ios::out | ios::app | ios::binary);

    cout << "Enter Employee ID: ";
    cin >> emp.id;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(emp.name, 50);

    cout << "Enter Designation: ";
    cin.getline(emp.designation, 50);

    cout << "Enter Salary: ";
    cin >> emp.salary;

    int position = dataFile.tellp();
    dataFile.write((char*)&emp, sizeof(emp));

    IndexEntry entry;
    entry.id = emp.id;
    entry.position = position;
    indexFile.write((char*)&entry, sizeof(entry));

    cout << "Employee added successfully.\n";

    dataFile.close();
    indexFile.close();
}

void displayEmployee() {
    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;

    fstream indexFile(INDEX_FILE, ios::in | ios::binary);
    fstream dataFile(DATA_FILE, ios::in | ios::binary);

    IndexEntry entry;
    bool found = false;

    while (indexFile.read((char*)&entry, sizeof(entry))) {
        if (entry.id == id) {
            dataFile.seekg(entry.position);
            Employee emp;
            dataFile.read((char*)&emp, sizeof(emp));
            cout << "\nEmployee Details:\n";
            cout << "ID: " << emp.id << "\n";
            cout << "Name: " << emp.name << "\n";
            cout << "Designation: " << emp.designation << "\n";
            cout << "Salary: " << emp.salary << "\n";
            found = true;
         break;
        }
    }

    if (!found) {
        cout << "Employee not found.\n";
    }

    indexFile.close();
    dataFile.close();
}

void deleteEmployee() {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    fstream indexFile(INDEX_FILE, ios::in | ios::binary);
    fstream tempFile("temp_index.txt", ios::out | ios::binary);

    IndexEntry entry;
    bool deleted = false;

    while (indexFile.read((char*)&entry, sizeof(entry))) {
        if (entry.id != id) {
            tempFile.write((char*)&entry, sizeof(entry));
        } else {
            deleted = true;
        }
    }

    indexFile.close();
    tempFile.close();

    remove(INDEX_FILE);
    rename("temp_index.txt", INDEX_FILE);

    if (deleted) {
        cout << "Employee deleted (only index removed).\n";
    } else {
        cout << "Employee ID not found.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Employee Management ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employee\n";
        cout << "3. Delete Employee\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployee(); break;
            case 3: deleteEmployee(); break;
            case 4: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
