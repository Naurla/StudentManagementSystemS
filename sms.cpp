#include <iostream>



using namespace std;

struct Students
{
    int StudentID;
    string firstName; 
    string lastName;
    string course;
    double gpa;
};

Students student[1000];
int studentCounter = 0;

void addStudents() {
    Students newStudents;
    bool found = false;
            cout << "Enter Student ID: ";
            cin >> newStudents.StudentID;
            cout << "Enter First Name: ";
            cin.ignore(); 
            getline(cin, newStudents.firstName);
            cout << "Enter Last Name: ";
            cin >> newStudents.lastName;
            cout << "Enter course: ";
            cin >> newStudents.course;
            cout << "Enter GPA: ";
            cin >> newStudents.gpa;

            
           while(true){
            found = false;
            for (int i = 0; i < studentCounter; i++) {
                if (student[i].StudentID == newStudents.StudentID) {
                    cout << "Student Id already exist";
                    cout << "\nEnter a unique one";
                    cout << "\nEnter a unqiue ID: ";
                    cin >> newStudents.StudentID;
                    found = true;
                    break;
                }
            }
          
            
            if(!found)
             break;
                
           
        }
       
        student[studentCounter++] = newStudents;
        cout << "The Student Has been added to the records"; 
    
}

void displayStudentsRecords(int studentid) {
    bool found = false;
    for (int i = 0; i < studentCounter; i++) {
        if (student[i].StudentID == studentid) {
            cout << "Student ID: " << student[i].StudentID;
            cout << "\nFirst Name: " << student[i].firstName;
            cout << "\nLast Name: " << student[i].lastName;
            cout << "\nCourse: " << student[i].course;
            cout << "\nGPA: " << student[i].gpa;
            cout << "\n===========================================";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No student Record found";
    }
}

void editStudents() {
    if (studentCounter == 0) {
        cout << "\nNo records";
        return;
    }

    int studentid;
        cout << "Enter Student ID to search: ";
        cin >> studentid;
        
        
        bool found = false;
        for (int i = 0; i < studentCounter; i++) {
            if (student[i].StudentID == studentid) {
                displayStudentsRecords(studentid);
                    cout << "\nEnter New ID: ";
                    cin >> student[i].StudentID;
                    cout << "Enter First Name: ";
                    cin.ignore();
                    getline(cin, student[i].firstName);
                    cout << "Enter Last Name: ";
                    cin >> student[i].lastName;
                    cout << "Enter New course: ";
                    cin >> student[i].course;
                    cout << "Enter GPA: ";
                    cin >> student[i].gpa;

                    while(true){
                     bool match = false;
                     for(int j = 0; j < studentCounter; j++){
                    if(student[j].StudentID == student[i].StudentID && j != i){
                     cout << "Student Id already exist";
                     cout << "\nEnter a unique one";
                     cout << "\nEnter a unqiue studentd ID: ";
                     cin >> student[i].StudentID;
                     match = true;
                    break;
                    
                }
            }
            if(!match)
            break;
          }        
                cout << "The Student ID has been Updated";           
                found = true;
                break;
                }
                
                
            }
                 if(!found){
                cout << "Student ID does not exist";
         
            }   
   
    

}

void deleteStudents() {
    char choice;
    if (studentCounter == 0) {
        cout << "No records";
        return;
    }

    int studentid;

    cout << "Enter Student ID to search: ";
    cin >> studentid;

    bool found = false;
    for (int i = 0; i < studentCounter; i++) {
        if (student[i].StudentID == studentid) {
            displayStudentsRecords(studentid);
            found = true;

            cout << "\nAre you sure you want to delete student from the records?(y/n): ";
            cin >> choice;
            if(choice == 'Y' || choice == 'y'){
            for (int j = i; j < studentCounter - 1; j++) {
                student[j] = student[j + 1];
            }
            studentCounter--;
            cout << "The Student has been deleted from the records";
        }
        else{
            cout << "Student was not deleted";
        }
    }
   
}
if (!found) {
    cout << "Student ID does not exist";
}
}

void viewStudents() {
    if (studentCounter == 0) {
        cout << "No records";
        return;
    }
    int option;

    while (true) {
        cout << "\nHow would you like to view Student Records: ";
        cout << "\n[1] View Alphabetically by lastNames: ";
        cout << "\n[2] View Gpa by Ascending order: ";
        cout << "\nEnter your choice: ";
        cin >> option;
        if (option == 1 || option == 2) {
            break;
        }
        cout << "INVALID OPTIONS, pick between (1 & 2)";
    }

    if (option == 1) {
        cout << "Student Record View in Alphabetically: ";
        for (int i = 0; i < studentCounter - 1; i++) {
            for (int j = 0; j < studentCounter - 1 - i; j++) {
                if (student[j].lastName > student[j + 1].lastName) {
                    Students temp = student[j];
                    student[j] = student[j + 1];
                    student[j + 1] = temp;
                }
            }
        }
    } else if (option == 2) {
        cout << "Student Record View by GPA: ";
        for (int i = 0; i < studentCounter - 1; i++) {
            for (int j = 0; j < studentCounter - 1 - i; j++) {
                if (student[j].gpa > student[j + 1].gpa) {
                    Students temp = student[j];
                    student[j] = student[j + 1];
                    student[j + 1] = temp;
                }
            }
        }
    }

    for (int i = 0; i < studentCounter; i++) {
        cout << "\nStudent ID: " << student[i].StudentID;
        cout << "\nFirst Name: " << student[i].firstName;
        cout << "\nLast Name: " << student[i].lastName;
        cout << "\nCourse: " << student[i].course;
        cout << "\nGPA: " << student[i].gpa;
        cout << "\n===========================================";
    }
}

int main() {
    int option;

    do {
        cout << "\n==========MENU============";
        cout << "\n [1] Add Students";
        cout << "\n [2] Edit Students";
        cout << "\n [3] Delete Students";
        cout << "\n [4] View Students";
        cout << "\n [5] Exit Program";
        cout << "\nEnter your choice: ";
        cin >> option;
        system("cls");

        switch (option) {
            case 1:
                addStudents();
                break;
            case 2:
                editStudents();
                break;
            case 3:
                deleteStudents();
                break;
            case 4:
                viewStudents();
                break;
            case 5:
                cout << "Thank you for using StudentManageMentSystem";
                break;
            default:
                cout << "INVALID OPTION, pick between (1-5)";
        }
    } while (option != 5);
}
