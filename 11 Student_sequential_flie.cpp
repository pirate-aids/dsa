#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Student {
    int rollNumber;
    char name[50];
    char division[10];
    char address[100];
};

vector<Student> students;

void addStudent() {
    Student newStudent;

    cout << "Enter Roll Number: ";
    cin >> newStudent.rollNumber;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(newStudent.name, 50);

    cout << "Enter Division: ";
    cin.getline(newStudent.division, 10);

    cout << "Enter Address: ";
    cin.getline(newStudent.address, 100);

    students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
}

void deleteStudent() {
    int rollNo;
    cout << "Enter Roll Number to delete: ";
    cin >> rollNo;

    bool found = false;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNumber == rollNo) {
            students.erase(it);
            found = true;
            cout << "Student record deleted successfully!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Record not found!" << endl;
    }
}

void displayStudent() {
    int rollNo;
    cout << "Enter Roll Number to display: ";
    cin >> rollNo;

    bool found = false;

    for (const auto& student : students) {
        if (student.rollNumber == rollNo) {
            cout << "\nStudent Details:\n";
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found!" << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Student Information System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayStudent();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}
