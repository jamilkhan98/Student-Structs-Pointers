//Jamil Khan
//CECS 282 - 05
//Oct 16, 2018

#include "myDate.h"
#include <iostream>
#include <string>
using namespace std;

//method which calculates Gregorian Calendar Date given Julian Date
void Julian2Greg(int JD, int & month, int  & day, int & year) {
	int I, J, K, L, N;
	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;
	year = I;
	month = J;
	day = K;
}

//method which calculates Julian Calendar Date from passed in month, day, and year values
int Greg2Julian(int month, int day, int year) {
	int I, J, K, JD;
	I = year;
	J = month;
	K = day;
	JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
	return JD;
}

//default constructor for myDate object
myDate::myDate() {
	month = 5;
	day = 11;
	year = 1959;
}

//overloaded constructor for myDate object passing in month, day, and year values
myDate::myDate(int M, int D, int Y) {
	int JD = Greg2Julian(M, D, Y);
	int m1, d1, y1;
	Julian2Greg(JD, m1, d1, y1);
	if (m1 == M && d1 == D && y1 == Y) {
		month = M; day = D; year = Y;
	}
	else {
		month = 5; day = 11; year = 1959;
	}
}

//display method for myDate objects
void myDate::display() {
	switch (month) {
	case 1:
		cout << "January " << day << ", " << year;
		break;
	case 2:
		cout << "February " << day << ", " << year;
		break;
	case 3:
		cout << "March " << day << ", " << year;
		break;
	case 4:
		cout << "April " << day << ", " << year;
		break;
	case 5:
		cout << "May " << day << ", " << year;
		break;
	case 6:
		cout << "June " << day << ", " << year;
		break;
	case 7:
		cout << "July " << day << ", " << year;
		break;
	case 8:
		cout << "August " << day << ", " << year;
		break;
	case 9:
		cout << "September " << day << ", " << year;
		break;
	case 10:
		cout << "October " << day << ", " << year;
		break;
	case 11:
		cout << "November " << day << ", " << year;
		break;
	case 12:
		cout << "December " << day << ", " << year;
		break;
	}
}

//method to increase value of myDate object
void myDate::increaseDate(int N) {
	int JD = Greg2Julian(month, day, year);
	JD += N;
	Julian2Greg(JD, month, day, year);
}

//method to decrease value of myDate object
void myDate::decreaseDate(int N) {
	int JD = Greg2Julian(month, day, year);
	JD -= N;
	Julian2Greg(JD, month, day, year);
}

//method which calculates difference in days between two myDate objects
int myDate::daysBetween(myDate D) {
	int JD = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());
	int JD2 = Greg2Julian(month, day, year);
	return (JD - JD2);
}

//getter method to return month value of myDate object
int myDate::getMonth() {
	return month;
}

//getter method to return day value of myDate object
int myDate::getDay() {
	return day;
}

//getter method to return year value of myDate object
int myDate::getYear() {
	return year;
}

//method to calculate day of year of myDate object
int myDate::dayOfYear() {
	int JD1 = Greg2Julian(month, day, year);
	int JD2 = Greg2Julian(1, 1, year);
	return (JD1 - JD2) + 1;
}

//method to display what day the myDate object corresponds to
string myDate::dayName() {
	int JD = Greg2Julian(month, day, year);
	int dayNumber = JD % 7;
	if (dayNumber == 0) {
		return "Monday";
	}
	else if (dayNumber == 1) {
		return "Tuesday";
	}
	else if (dayNumber == 2) {
		return "Wednesday";
	}
	else if (dayNumber == 3) {
		return "Thursday";
	}
	else if (dayNumber == 4) {
		return "Friday";
	}
	else if (dayNumber == 5) {
		return "Saturday";
	}
	else {
		return "Sunday";
	}
}

//toString method to print out complete date of myDate object
string myDate::printDate() {
	string Month;
	switch (month) {
	case 1:
		Month = "January ";
		break;
	case 2:
		Month = "February ";
		break;
	case 3:
		Month = "March ";
		break;
	case 4:
		Month = "April ";
		break;
	case 5:
		Month = "May ";
		break;
	case 6:
		Month = "June ";
		break;
	case 7:
		Month = "July ";
		break;
	case 8:
		Month = "August ";
		break;
	case 9:
		Month = "September ";
		break;
	case 10:
		Month = "October ";
		break;
	case 11:
		Month = "November ";
		break;
	case 12:
		Month = "December ";
		break;
	default:
		break;
	}

	return Month + to_string(day) + ", " + to_string(year);
}
