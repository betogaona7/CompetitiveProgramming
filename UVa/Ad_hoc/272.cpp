#include <iostream>
#include <string>

using namespace std;

int main() {
	string line;
	bool first = true;
	
	while(getline(cin, line)){
		for(int i = 0; i < line.length(); i++){
			
			if(line[i] == '"'){
				if(first == true){
					
					line[i] = '@';
					first = false;
				}else{
					line[i] = '|';
					first = true;
				}
			}
		}	
		while (line.find("@") != string::npos){
			line.replace(line.find("@"), 1, "``");
		}
		while (line.find("|") != string::npos){
			line.replace(line.find("|"), 1, "''");
		}
		cout << line << endl;
	}
	return 0;
}