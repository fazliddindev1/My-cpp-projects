#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string id;
    string name;
    double grade;

    Student() : id(""), grade(0.0) {}

    Student(string id, string name, double grade) : id(id), name(name), grade(grade) {}

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Grade: " << grade << endl;
     }
};

class StudentManager {
private:
    static const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int studentCount;

public:
    StudentManager() : studentCount(0) {}

    void addStudent() {
        if (studentCount >= MAX_STUDENTS) {
            cout << "Error: Maximum number of students reached." << endl;
            return;
        }

        string id;
        string name;
        double grade;

        cout << "Enter student ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter student grade: ";
        cin >> grade;
        cin.ignore();

        students[studentCount++] = Student(id, name, grade);
        cout << "Student added successfully!" << endl;
    }

    void deleteStudent() {
        string id;
        cout << "Enter student ID to delete: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < studentCount; ++i) {
            if (students[i].id == id) {
                found = true;
                for (int j = i; j < studentCount - 1; ++j) {
                    students[j] = students[j + 1];
                }
                studentCount--;
                cout << "Student deleted successfully!" << endl;
                break;
            }
        }

        if (!found) {
            cout << "Student ID not found!" << endl;
        }
    }

    void updateStudent() {
        string id;
        cout << "Enter student ID to update: ";
        cin >> id;
        cin.ignore();

        bool found = false;
        for (int i = 0; i < studentCount; ++i) {
            if (students[i].id == id) {
                found = true;
                cout << "Enter new name: ";
                getline(cin, students[i].name);

                cout << "Enter new grade: ";
                cin >> students[i].grade;
                cin.ignore();

                cout << "Student updated successfully!" << endl;
                break;
            }
        }

        if (!found) {
            cout << "Student ID not found!" << endl;
        }
    }

    void displayStudents() const {
        if (studentCount == 0) {
            cout << "No students to display." << endl;
            return;
        }

        cout << "Student Records:" << endl;
        for (int i = 0; i < studentCount; ++i) {
            students[i].display();
        }
    }
};

int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\nStudent Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Display Students" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.deleteStudent();
                break;
            case 3:
                manager.updateStudent();
                break;
            case 4:
                manager.displayStudents();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
