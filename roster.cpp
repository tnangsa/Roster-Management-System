#include <iostream>
#include "roster.h"

using namespace std;

//add a new student
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    

    Student* student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
   

    classRosterArray.push_back(student);

}


//remove student by studentID or display not found
void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i < classRosterArray.size(); i++) {
        if (classRosterArray[i]->get_studentID() == studentID) {
            found = true;
            delete classRosterArray[i];
            // Move last student pointer to this spot 
            classRosterArray.erase(classRosterArray.begin() + i);
            
       
            cout << "Student " << studentID << " was removed from the roster." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Student " << studentID << " was not found." << endl;
    }
}

//print all students
void Roster::printAll() {
    for (int i = 0; i < classRosterArray.size(); i++) {
        classRosterArray[i]->print();
    }
}

//print average days in course for one student by studentID
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < classRosterArray.size(); i++) {
        if (classRosterArray[i]->get_studentID() == studentID) {
            int* days = classRosterArray[i]->get_daysInCourse();
            double avg = (days[0] + days[1] + days[2]) / 3.0;
            cout << "Average number of days in course for this student " << studentID << ": " << avg << endl;
            return;
        }
    }
    cout << "Student " << studentID << " was not found." << endl;
}

//print invalid emails
void Roster::printInvalidEmails() {
    cout << "Invalid email addresses:" << endl;
    for (int i = 0; i < classRosterArray.size(); i++) {
        string email = classRosterArray[i]->get_emailAddress();
        if (email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos) {
            cout << email << endl;
        }
    }
}

//print students by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < classRosterArray.size(); i++) {
        if (classRosterArray[i]->get_degreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

//Destructor
Roster::~Roster() {
    for (int i = 0; i < classRosterArray.size(); i++) {
        delete classRosterArray[i];
    }
    classRosterArray.clear();
}
