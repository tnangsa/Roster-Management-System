#pragma once
#include <string>
#include "degree.h"

using namespace std;


//DECLARING STUDENT CLASS - holds info for one student
class Student {

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];     
	DegreeProgram degreeProgram;


public:
	//CONSTRUCTOR
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	
	//ACCESSORS
	string get_studentID() const;
	string get_firstName() const;
	string get_lastName() const;
	string get_emailAddress() const;
	int get_age() const;
	int* get_daysInCourse();
	DegreeProgram get_degreeProgram() const;

	//MUTATORS
	void set_studentID(string studentID);
	void set_firstName(string firstName);
	void set_lastName(string lastName);
	void set_emailAddress(string emailAddress);
	void set_age(int age);
	void set_daysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void set_degreeProgram(DegreeProgram degreeProgram);

	
	void print() const;
};