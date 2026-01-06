#pragma once


#include "student.h"
#include "degree.h"
#include <string>
#include <vector>


using namespace std;

//  ROSTER CLASS
class Roster {

private:
   
    vector<Student*> classRosterArray;
   

public:

    //constructor
    Roster() = default;   

    //adds a new student to roster
    void add(string studentID, string firstName, string lastName, string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
        DegreeProgram degreeProgram);

    //remove student by student ID
    void remove(string studentID);

    //print all students
    void printAll();

    //print average number of days in course
    void printAverageDaysInCourse(string studentID);

    //print invalid emails
    void printInvalidEmails();

    //print student by degree program
    void printByDegreeProgram(DegreeProgram degreeProgram);

    //Destructor
    ~Roster();

};

