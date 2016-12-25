#include <iostream>
using namespace std;

int main() {
	float number, result;
	float values[] = {100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.25, 0.10, 0.05, 0.01};
	size_t size = (sizeof(values)/sizeof(values[0]));
	
	cin >> number;
	cout << "NOTAS:"<< endl;
	for(int i = 0; i < size; i++){
		result = int(number / values[i]);
		
		if(i <= 5){
			cout << result <<" nota(s) de R$"<<values[i]<< ".00"<< endl;
			if(i == 5){
				cout<<"MOEDAS:" << endl;
			}
		}else{
			cout << result <<" moeda(s) de R$"<<values[i]<< endl;
		}
		number = number - (result * values[i]);
	}
cout << number;
	return 0;
}