#include <iostream>
#include "student.h"

using namespace std;


//CONSTRUCTOR

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;

	this->degreeProgram = degreeProgram;

}

//ACCESSORS
string Student::get_studentID() const {
	return studentID;
}

string Student::get_firstName() const {
	return firstName;
}

string Student::get_lastName() const {
	return lastName;
}

string Student::get_emailAddress() const {
	return emailAddress;
}

int Student::get_age() const {
	return age;
}

int* Student::get_daysInCourse() {
	return daysInCourse;  
}

DegreeProgram Student::get_degreeProgram() const {
	return degreeProgram;
}


//MUTATORS

void Student::set_studentID(string studentID) {
	this->studentID = studentID;
}

void Student::set_firstName(string firstName) {
	this->firstName = firstName;
}

void Student::set_lastName(string lastName) {
	this->lastName = lastName;
}

void Student::set_emailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::set_age(int age) {
	this->age = age;
}

void Student::set_daysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
}

void Student::set_degreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}


//PRINT FUNCTION

void Student::print() const{
	cout << studentID << "\t"
		<< "First Name: " << firstName << "\t"
		<< "Last Name: " << lastName << "\t"
		<< "Email: " << emailAddress << "\t"
		<< "Age: " << age << "\t"
		<< "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "} "
		<< "Degree Program: ";

	switch (degreeProgram) {
		case SECURITY:
			cout << "Security";
			break;
		case NETWORK:
			cout << "Network";
			break;
		case SOFTWARE:
			cout << "Software";
			break;
	}

	cout << endl;
}

