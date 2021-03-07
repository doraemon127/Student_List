/*
  Project Description: This is a program will make a list of students. The user can add, print, and delete students.
  Name: Aammya Sapra
  Date: March 6, 2021
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip> //for setprecision()

using namespace std;


//create Student struct
struct Student {
	char first_name[20];
	char last_name[20];
	int id;
	float gpa;
};


//function prototypes
void add_Student(vector<Student*>* ptrvec);
void print_Students(vector<Student*>* ptrvec);
void delete_Student(vector<Student*>* ptrvec);


vector<Student*> Student_pointers; //vector of Student pointers
vector<Student*>* Student_list = &Student_pointers; //vector pointer that points to vector of Student pointers

vector<Student*>::iterator iter; //iterator


//------------------------------------------------------MAIN FUNCTION----------------------------------------------------------

int main() {

	//print out instructions
	cout << '\n' << "To add a student type \'ADD\'." << endl;
	cout << "To print current students type \'PRINT\'." << endl;
	cout << "To delete a student type \'DELETE\'." << endl;
	cout << "To quit type \'QUIT\'." << endl << endl;

	bool inputting = true;
	char command[10];  //stores the command (ADD, PRINT, DELETE, QUIT) inputted by the user

	while (inputting) {
		cin >> command;
		if (strcmp(command, "ADD") == 0) {
			add_Student(Student_list);
		} else if (strcmp(command, "PRINT") == 0) {
			print_Students(Student_list);
		} else if (strcmp(command, "DELETE") == 0) {
			delete_Student(Student_list);
		} else if (strcmp(command, "QUIT") == 0) {
			inputting = false;
			break;
		} else { //prompt user to re-enter command if something invalid was entered
			cout << "Please enter either \'ADD\', \'PRINT\', \'DELETE\', or \'QUIT\'." << endl;
		}
	} 

	return 0;
} 


//--------------------------------------------------------FUNCTIONS------------------------------------------------------------

//function to create a new entry for a student
void add_Student(vector<Student*>* ptrvec) {

	//create new Student pointer
	Student *s = new Student; 

	//prompt for first name, last name, student id, and GPA and add inputted information to Student
	cout << "Enter student's first name" << endl;
	cin >> s->first_name;
	cout << "Enter student's last name" << endl;
	cin >> s->last_name;
	cout << "Enter student's id number" << endl;
	cin >> s->id;
	cout << "Enter student's GPA" << endl;
	cin >> s->gpa;

	//add Student pointer to vector
	ptrvec->push_back(s);
	cout << "Student has been added. Enter \'ADD\', \'PRINT\', \'DELETE\' to continue editing or \'QUIT\' to exit." << endl << endl;
	return;
}



//function to print out all the students currently stored
void print_Students(vector<Student*>* ptrvec) {
	cout << "Students will be printed in the following format: first_name last_name, student_id, GPA" << endl;
	int i = 0;
	for (iter = ptrvec->begin(); iter < ptrvec->end(); iter++) {
		//use setprecision(2) to show GPA to 2 decimal places
		cout << ptrvec->at(i)->first_name << ' ' << ptrvec->at(i)->last_name << ", " << ptrvec->at(i)->id << ", " << fixed << setprecision(2) << ptrvec->at(i)->gpa << endl;
		i++;
	}
	cout << "All stored students have been printed. Enter \'ADD\', \'PRINT\', \'DELETE\' to continue editing or \'QUIT\' to exit." << endl << endl;	
	return;
}



//function to delete a student 
void delete_Student(vector<Student*>* ptrvec) {
	int delete_id; //will hold id of student that user wants to delete
	cout << "Enter the ID number of the student you want to delete." << endl; //prompt user for id number of student to delete
	cin >> delete_id;

	int i = 0;
	for (iter = ptrvec->begin(); iter < ptrvec->end(); iter++) {
		if (ptrvec->at(i)->id == delete_id) {
			delete *iter; //delete Student
			ptrvec->erase(ptrvec->begin() + i); //remove from vector
			cout << "Student with id number " << delete_id << " has been deleted. Enter \'ADD\', \'PRINT\', \'DELETE\' to continue editing or \'QUIT\' to exit." << endl << endl;
			break;
		}
		i++;
	}
	return;
}