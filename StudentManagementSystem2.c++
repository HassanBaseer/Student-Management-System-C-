#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll_no;
    string course;
    double marks;
    char grade;
};

void input(Student*& students, int& total);
void display(const Student* students, int total);
void search(const Student* students, int total);
void insert(Student* students, int& total);
void deleteR(Student*& students, int& total);
void add(Student*& students, int& total);

int main() {
    cout << "***********************\n*                     *\n*  Choose Your Option *\n*                     *\n***********************\n";
    
    Student* students = nullptr;
    int total = 0;
    int value;
    
    while (true) {
        cout << "\n1 for Enter Information" << endl;
        cout << "2 for Display all Information" << endl;
        cout << "3 for Search Information" << endl;
        cout << "4 for Insert Information" << endl;
        cout << "5 for Delete Information" << endl;
        cout << "6 for Adding information" << endl;
        cout << "9 for to close Program" << endl;
        
        cin >> value;
        
        switch (value) {
            case 1:
                input(students, total);
                break;
            case 2:
                display(students, total);
                break;
            case 3:
                search(students, total);
                break;
            case 4:
                insert(students, total);
                break;
            case 5:
                deleteR(students, total);
                break;
            case 6:
                add(students, total);
                break;
            case 9:
                delete[] students; 
                exit(0);
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
    
    return 0;
}

void input(Student*& students, int& total) {
    cout << "Enter No of students: ";
    int curr_size;
    cin >> curr_size;
    
    Student* newStudents = new Student[total + curr_size];
    
    for (int i = 0; i < total; ++i) {
        newStudents[i] = students[i];
    }
    
    for (int i = total; i < total + curr_size; ++i) {
        cout << "\nEnter Information of student " << i + 1 << endl << endl;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, newStudents[i].name);
        cout << "Enter Roll no: ";
        cin >> newStudents[i].roll_no;
        cout << "Enter Course: ";
        cin.ignore();
        getline(cin, newStudents[i].course);
        cout << "Enter Marks: ";
        cin >> newStudents[i].marks;
        cout << "Enter Grade: ";
        cin >> newStudents[i].grade;
    }
    
    delete[] students; 
    students = newStudents; 
    total += curr_size; 
}

void display(const Student* students, int total) {
    if (total == 0) {
        cout << "No Information is Entered\nPlease Enter some Information First" << endl;
    } else {
        for (int i = 0; i < total; ++i) {
            cout << "\nInformation of Student " << i + 1 << endl << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Roll no: " << students[i].roll_no << endl;
            cout << "Course: " << students[i].course << endl;
            cout << "Marks: " << students[i].marks << endl;
            cout << "Grade: " << students[i].grade << endl;
        }
    }
}

void search(const Student* students, int total) {
    if (total == 0) {
        cout << "No Information is Entered\nPlease Enter some Information First" << endl;
    } else {
        int rollno;
        cout << "Enter the roll no of student: ";
        cin >> rollno;
        
        for (int i = 0; i < total; ++i) {
            if (rollno == students[i].roll_no) {
                cout << "Name: " << students[i].name << endl;
                cout << "Roll no: " << students[i].roll_no << endl;
                cout << "Course: " << students[i].course << endl;
                cout << "Marks: " << students[i].marks << endl;
                cout << "Grade: " << students[i].grade << endl;
            }
        }
    }
}

void insert(Student* students, int& total) {
    if (total == 0) {
        cout << "No Information is Entered\nPlease Enter some Information First" << endl;
    } else {
        int rollno;
        cout << "Enter the roll no of student which you want to Insert: ";
        cin >> rollno;
        
        for (int i = 0; i < total; ++i) {
            if (rollno == students[i].roll_no) {
                cout << "\nPrevious Information" << endl << endl;
                cout << "Information of Student " << i + 1 << endl;
                cout << "Name: " << students[i].name << endl;
                cout << "Roll no: " << students[i].roll_no << endl;
                cout << "Course: " << students[i].course << endl;
                cout << "Marks: " << students[i].marks << endl;
                cout << "Grade: " << students[i].grade << endl;
                cout << "\nEnter new Information" << endl << endl;
                
                cout << "Enter name: ";
                cin >> students[i].name;
                cout << "Enter Roll no: ";
                cin >> students[i].roll_no;
                cout << "Enter course: ";
                cin >> students[i].course;
                cout << "Enter Marks: ";
                cin >> students[i].marks;
                cout << "Enter Grade: ";
                cin >> students[i].grade;
            }
        }
    }
}

void deleteR(Student*& students, int& total) {
    if (total == 0) {
        cout << "No Information is Entered\nPlease Enter some Information First" << endl;
    } else {
        int a;
        cout <<"Choose Your Option\n";
        cout << "1 for delete all Information" << endl;
        cout << "2 for delete specific Information" << endl;
        cin >> a;
        
        if (a == 1) {
            delete[] students;
            students = nullptr; 
            total = 0; 
            cout << "All Information is deleted..!!" << endl;
        } else if (a == 2) {
            int rollno;
            cout << "Enter the roll no of student which you wanted to delete: ";
            cin >> rollno;
            
            Student* tempStudents = new Student[total];
            int count = 0;
            for (int i = 0; i < total; ++i) {
                if (rollno != students[i].roll_no) {
                    tempStudents[count++] = students[i];
                }
            }
            
            delete[] students; 
            students = tempStudents; 
            total = count; 
            
            cout << "Your required Information is deleted" << endl;
        } else {
            cout << "Invalid input";
        }
    }
}

void add(Student*& students, int& total) {
    Student newStudent;
    
    cout << "Enter the Information of student" << endl;
    cout << "\nEnter name: ";
    cin >> newStudent.name;
    cout << "Enter Roll no: ";
    cin >> newStudent.roll_no;
    cout << "Enter course: ";
    cin >> newStudent.course;
    cout << "Enter Marks: ";
    cin >> newStudent.marks;
    cout << "Enter Grade: ";
    cin >> newStudent.grade;
    
    Student* newStudents = new Student[total + 1];
    
    for (int i = 0; i < total; ++i) {
        newStudents[i] = students[i];
    }
    
    newStudents[total] = newStudent;
    
    delete[] students; 
    students = newStudents; 
    total += 1; 
}
