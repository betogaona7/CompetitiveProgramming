#include <iostream>
#include <string>

using namespace std;

int main() {
	string d, c;
	int sd, sc;
	while(getline(cin, d) && getline(cin, c)){
		string result = "$";
		sd = d.length();
		sc = c.length();
		for(int i = 0; i < sd; i++){
			if((sd - i) % 3 == 0 && i > 0){
				result += ",";
			}
			result += d[i];
		}
		result += ".";
		if(sc < 2){
			result += "0";
		}
		for (int i = 0; i < sc; i++){
			result += c[i];
		}
		cout << result << "\n";
	}
	return 0;
}