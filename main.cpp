#include <iostream>
#include "roster.h"
#include "degree.h"
#include <string>
#include <sstream>


using namespace std;


int main() {

    //print course, language, studentID, and name
    cout << "C867: Scripting and Programming - Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 011698877" << endl;
    cout << "Tenzin Nangsa" << endl;
    
    //add student data 
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson 1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",

        "A5,Tenzin,Nangsa,tnangsa@wgu.edu,26,7,20,24,SOFTWARE" };

    //calculate number of students
    int numStudents = sizeof(studentData) / sizeof(studentData[0]);

    //create an instsnce of roster class called classRoster
    Roster classRoster;
    
    //parse each student data string and then add it to the classRoster
    for (int i = 0; i < numStudents; i++) {
        stringstream ss(studentData[i]);

        string studentID, firstName, lastName, emailAddress, ageStr, days1Str, days2Str, days3Str, degreeStr;

        //extract criteria from string
        getline(ss, studentID, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, emailAddress, ',');
        getline(ss, ageStr, ',');
        getline(ss, days1Str, ',');
        getline(ss, days2Str, ',');
        getline(ss, days3Str, ',');
        getline(ss, degreeStr, ',');

        //convert from string to int
        int age = stoi(ageStr);
        int days1 = stoi(days1Str);
        int days2 = stoi(days2Str);
        int days3 = stoi(days3Str);

        DegreeProgram degreeProgram;
        if (degreeStr == "SECURITY") degreeProgram = SECURITY;
        else if (degreeStr == "NETWORK") degreeProgram = NETWORK;
        else degreeProgram = SOFTWARE;
        
        //add parsed student
        classRoster.add(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, degreeProgram);
    }

    //print all 
    classRoster.printAll();
    cout << endl;

    //print invalid emails
    classRoster.printInvalidEmails();
    cout << endl;

    //loop through students and print average 
    for (int i = 0; i < numStudents; i++) {
        string studentID = studentData[i].substr(0, 2);  
        classRoster.printAverageDaysInCourse(studentID);
    }
    cout << endl;

    //print students in SOFTWARE
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    //remove A3
    classRoster.remove("A3");
    cout << endl;

    //print All
    classRoster.printAll();
    cout << endl;

    //remove A3 again
    classRoster.remove("A3");


    return 0;
}
