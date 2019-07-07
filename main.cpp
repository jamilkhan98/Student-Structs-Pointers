//Jamil Khan
//Prog 3 - Structures and Pointers
//Oct 16, 2018

#define _CRT_SECURE_NO_WARNINGS
#include "myDate.h"
#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

struct Student
{
	char name[20];
	int ID;
	char grade;
	myDate bday;
	string hometown;
};

void populate(Student []);
void display(Student []);
void display(Student *[]);
void sortbyName(Student *[]);
void sortbyID(Student *[]);
void sortbyGrade(Student *[]);
void sortbyBday(Student *[]);
void sortbyHomeTown(Student *[]);

int main() {
	Student myclass[10];
	Student *names[10];
	Student *IDs[10];
	Student *Grades[10];
	Student *Bdays[10];
	Student *HomeTowns[10];

	populate(myclass);

	for (int i = 0; i < 10; i++) {
		names[i] = &myclass[i];
		IDs[i] = &myclass[i];
		Grades[i] = &myclass[i];
		Bdays[i] = &myclass[i];
		HomeTowns[i] = &myclass[i];
	}

	sortbyName(names);
	sortbyID(IDs);
	sortbyGrade(Grades);
	sortbyBday(Bdays);
	sortbyHomeTown(HomeTowns);

	int selection;
	bool going = true;

	while (going) {
		cout << "0) Display original list" << endl;
		cout << "1) Display list sorted by Name" << endl;
		cout << "2) Display list sorted by Student ID" << endl;
		cout << "3) Display list sorted by Grade" << endl;
		cout << "4) Display list sorted by Birthday" << endl;
		cout << "5) Display list sorted by Home Town" << endl;
		cout << "6) Exit" << endl;

		cin >> selection;

		switch (selection) {
		case 0:
			display(myclass);
			break;
		case 1:
			display(names);
			break;
		case 2:
			display(IDs);
			break;
		case 3:
			display(Grades);
			break;
		case 4:
			display(Bdays);
			break;
		case 5:
			display(HomeTowns);
			break;
		case 6:
			going = false;
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
		getchar();
	}
}

void populate(Student sa[]) {
	string names[10] = { "Jim", "Dwight", "Pam", "Michael", "Stanley", "Toby", "Red", "Donna", "Eric", "Kitty" };
	char grades[5] = { 'A', 'B', 'C', 'D', 'F' };
	string hometowns[10] = { "Westminster", "Fountain Valley", "Hollywood", "Los Alamitos", "Long Beach", "Los Angeles", "Rosemead", "Huntington Beach", "Seal Beach", "Rossmoor" };

	srand(time(0));

	for (int i = 0; i < 10; i++) {
		strcpy(sa[i].name, names[i].c_str());
		sa[i].ID = rand() % 9000 + 1000;
		sa[i].grade = grades[rand() % 5];
		sa[i].bday = myDate(1, 1, 1995);
		sa[i].bday.increaseDate(rand() % 2191);
		sa[i].hometown = hometowns[i];
	}
}

void display(Student sa[]) {
	cout << left;
	cout << setw(20) << "Name" << setw(15) << "Student ID" << setw(10) << "Grade" << setw(23) << "Birthday" << "Home Town" << endl;
	for (int i = 0; i < 10; i++) {
		cout << setw(20) << sa[i].name << setw(15) << sa[i].ID << setw(10) << sa[i].grade << setw(23) << sa[i].bday.printDate() << sa[i].hometown << endl;
	}
	cout << endl;
}

void display(Student *sp[]) {
	cout << left;
	cout << setw(20) << "Name" << setw(15) << "Student ID" << setw(10) << "Grade" << setw(23) << "Birthday" << "Home Town" << endl;
	for (int i = 0; i < 10; i++) {
		cout << setw(20) << sp[i]->name << setw(15) << sp[i]->ID << setw(10) << sp[i]->grade << setw(23) << sp[i]->bday.printDate() << sp[i]->hometown << endl;
	}
	cout << endl;
}

void sortbyName(Student *sp[]) {
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10 - i - 1; k++) {
			if (strcmp(sp[k]->name, sp[k + 1]->name) >= 1) {
				Student *temp;
				temp = sp[k];
				sp[k] = sp[k + 1];
				sp[k + 1] = temp;
			}
		}
	}
}

void sortbyID(Student *sp[]) {
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10 - i - 1; k++) {
			if (sp[k]->ID > sp[k + 1]->ID) {
				Student *temp;
				temp = sp[k];
				sp[k] = sp[k + 1];
				sp[k + 1] = temp;
			}
		}
	}
}

void sortbyGrade(Student *sp[]) {
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10 - i - 1; k++) {
			if (sp[k]->grade > sp[k + 1]->grade) {
				Student *temp;
				temp = sp[k];
				sp[k] = sp[k + 1];
				sp[k + 1] = temp;
			}
		}
	}
}

void sortbyBday(Student *sp[]) {
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10 - i - 1; k++) {
			if ((sp[k]->bday).daysBetween(sp[k + 1]->bday) < 0) {
				Student *temp;
				temp = sp[k];
				sp[k] = sp[k + 1];
				sp[k + 1] = temp;
			}
		}
	}
}

void sortbyHomeTown(Student *sp[]) {
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10 - i - 1; k++) {
			if ((sp[k]->hometown).compare(sp[k + 1]->hometown) >= 1) {
				Student *temp;
				temp = sp[k];
				sp[k] = sp[k + 1];
				sp[k + 1] = temp;
			}
		}
	}
}

