#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <chrono>
#include <thread>
#include <vector>
 

 

using namespace std;
 

struct Student {
    string name;
    string surname;
    int vGrade;
    int wGrade; 
    double average; 
};
 

 
void schema();
void printStudent(const Student& student, ofstream& outputFile);
void bottom(ofstream& outputFile);
void bubbleSort(Student* students, int numberOfStudents);
void swapStudents(Student& a, Student& b);
 

string dashes = "---------------------------------------------------------------------------------------";
 

int main() {
    
 

//for progress bar
// using namespace std::this_thread;
// using namespace std::chrono; 
 

string nameOfStudent, surnameOfStudent;
    char wannaSearch;
 

//for input
int numberOfStudents;
    
    
//defensive programming
    
    
    
    //input mathites
    cout << "Posous mathites thes pia ? Lege: ";
    cin >> numberOfStudents;
    
 

    Student* students = new Student[numberOfStudents];
 

 
	
	 
	
	for (int i = 0; i < numberOfStudents; i++) {
		cout << endl << endl << "Name: ";
		cin >> students[i].name;
		 
		
		cout << "Surname: ";
		cin >> students[i].surname;
		 
		
		cout << "Vocal Grade: ";
		cin >> students[i].vGrade;
		 
		
		cout << "Written Grade: ";
		cin >> students[i].wGrade;
		   
		   
		students[i].average = (students[i].vGrade + students[i].wGrade) / 2.0;
	}
	

 

 

 

//progress bar
std::cout << "[";
 

for(int i = 0; i < 100; i++)
{
this_thread::sleep_for(chrono::milliseconds(5));
std::cout << "=";
}
 

std::cout << "] 100% \n\n\n";
 

 

 

//Sort it
    bubbleSort(students, numberOfStudents);
 

 

    //Output
    ofstream outputFile("output.txt");
        
		
		schema();
        for (int i = 0; i < numberOfStudents; i++) {
            printStudent(students[i], outputFile);
        }
        bottom(outputFile);
        outputFile.close();
        cout << "Output saved to output.txt." << endl;
 	

    
 

//Search Student
cout << endl << endl << "You wanna search? (y/n): ";
cin >> wannaSearch;
    if (wannaSearch == 'y'){
        
        system("CLS");
        cout << "Give me the info of the student:" << endl;
        
        cout << "Name: ";
        cin >> nameOfStudent;
        
        cout << "Surname: ";
        cin >> surnameOfStudent;
        
           // if(nameOfStudent == students[i].name){
           //     cout << students[i].name;
           // }else {
           //     cout << "There is no Student with that name.";
           // }
           
           
        for (int i = 0; i < numberOfStudents; i++) {
            if (nameOfStudent == students[i].name && surnameOfStudent == students[i].surname) {
                
                cout << endl << "Student found: " << endl << endl
                << "Name: " << students[i].name << endl 
                << "Surname: " << students[i].surname << endl
                << "V.Grade: " << students[i].vGrade << endl
                << "W.Grade: " << students[i].wGrade << endl
                << "Average: " << students[i].average << endl << endl;
                
                break;
            }
        }
        
    }else if (wannaSearch == 'n'){
        cout << "k ty bye";
    }else {
        cout << "Input 'y' or 'n' please";
    }
 

 

 

//save in file
 
	delete[] students; 
	
	
system("PAUSE");
return 0;
}
 

 

 

void schema() {
	 
	
	string spaces = "\t\t\t\t\t\t\t\t\t\t\t";
	 
	
	 
	
	 
	
	cout << " " << dashes << " " << endl;
	    cout << "|"<< spaces << "|" << endl;
	cout << "|"<< spaces << "|" << endl;    
	cout << "| DATABASE |" << endl;
	cout << "|"<< spaces << "|" << endl;  
	//    cout << "|"<< spaces << "|" << endl;
	    cout << "|"<< spaces << "|" << endl;
	    cout << " " << dashes << " " << endl;
	    cout << "|" << setw(18) << "Name " << setw(15) << "Surname " << setw(15) << "V.Grade " << setw(15) << "W.Grade " << setw(15) << "Average " << setw(10) << "|" << endl;
	    cout << "|"<< spaces << "|" << endl;
	//    cout << "|"<< spaces << "|" << endl;
	//    cout << "|"<< spaces << "|" << endl;
	    cout << " " << dashes << " " << endl;
}
 

 

//Withou Output 

//void printStudent(const Student& student) {
//    cout << "|" << " " << setw(14) << student.name << setw(15) << student.surname
//         << setw(15) << student.vGrade << setw(15) << student.wGrade
//         << setw(15) << student.average << "     \t|" << endl;
//}
//
// 
//
//void bottom() {
//    cout << "|"<< " " << setw(87) << "|" << endl;
//    // cout << "|"<< " " << setw(87) << "|" << endl;
//    // cout << "|"<< " " << setw(87) << "|" << endl;
//    // cout << "|"<< " " << setw(87) << "|" << endl;
//    cout << " " << dashes << " " << endl << endl << endl << endl;
//}
 

//With Output in .txt

void printStudent(const Student& student, ofstream& outputFile) {
    cout << "|" << " " << setw(14) << student.name << setw(15) << student.surname
         << setw(15) << student.vGrade << setw(15) << student.wGrade
         << setw(15) << student.average << "     \t|" << endl;

    outputFile << "|" << " " << setw(14) << student.name << setw(15) << student.surname
         << setw(15) << student.vGrade << setw(15) << student.wGrade
         << setw(15) << student.average << "     \t|" << endl;
}

void bottom(ofstream& outputFile) {
    cout << "|"<< " " << setw(87) << "|" << endl;
    outputFile << "|"<< " " << setw(87) << "|" << endl;
    cout << " " << dashes << " " << endl << endl << endl << endl;
    outputFile << " " << dashes << " " << endl << endl << endl << endl;
}






// Highest Average First
void bubbleSort(Student* students, int numberOfStudents) {
    for (int i = 0; i < numberOfStudents - 1; i++) {
        for (int j = 0; j < numberOfStudents - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                swapStudents(students[j], students[j + 1]);
            }
        }
    }
}
 

void swapStudents(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}
 

 

 

 

 

 

 

/*
Wishfull Output
 -----------------------------------------------------------------------
| |
| DATABASE |
| |
 -----------------------------------------------------------------------
| Name Surname V.Grade W.Grade Average |
| |
| John Doe 5 5 5 |
| |
| Mary Jane 6 4 5 |
| |
| |
| |
 -----------------------------------------------------------------------
 

*/
