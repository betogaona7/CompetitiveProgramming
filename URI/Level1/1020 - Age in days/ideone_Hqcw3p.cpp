#include <iostream>
using namespace std;

int main() {
	int age, years, months, days;
	cin >> age;
	
	years = age/365;
	months = (age - (years*365))/30;
	days = age - ((months * 30) + (years*365));
	
	cout<< years << " ano(s)\n" << months << " mes(es)\n" << days << " dia(s)\n";
	return 0;
}