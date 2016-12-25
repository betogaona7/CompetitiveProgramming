#include <iostream>
using namespace std;

int main() {
	int sec, hours, minutes, seconds;
	cin >> sec; 
	
	hours = sec / 3600;
	minutes = (sec - (3600 * hours))/60;
	seconds = sec -((3600 * hours) + (60 * minutes));
	cout << hours <<":"<<minutes<<":"<<seconds<< endl;
	return 0;
}