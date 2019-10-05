#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
	int arr[1000][1000] = {0};
	unordered_map < int, vector<int> > data;
	int i, x, y, w, h;
	string line; 
	while(getline(cin, line)){
		sscanf(line.c_str(), "#%d @ %d,%d: %dx%d", &i, &y, &x, &w, &h);
		vector <int> d {y, x, w, h};
		data[i] = d;
		for(int i = x; i < (x+h) && i < 1000; ++i){
			for(int j = y; j < (y+w) && j < 1000; ++j){
				arr[i][j] += 1;
			}
		}
	}
	
	/* Part 1 */
	int total = 0;
	for(int i = 0; i < 1000; ++i){
		for(int j = 0; j < 1000; ++j){
			if(arr[i][j] > 1) total += 1;
		}
	}
	cout << total << endl;
	
	/* Part 2 */
	for(auto it = data.begin(); it != data.end(); ++it){
		int ones = 0;
		for(int i = it->second[1]; i < it->second[1]+it->second[3]; ++i){
			for(int j = it->second[0]; j < it->second[0]+it->second[2]; ++j){
				if (arr[i][j] == 1) ones += 1;
				else break;
			}
		}
		if(ones == (it->second[2]*it->second[3])){
			cout << it->first << endl;
			break;
		}
	}
	
	return 0;
}

/*
For some reason, code below doesn't work (part 1).
#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
	unordered_set <int> inches;
	unordered_set <int> over;
	
	int i, x, y, w, h;
	string line; 
	while(getline(cin, line)){
		sscanf(line.c_str(), "#%d @ %d,%d: %dx%d", &i, &y, &x, &w, &h);
		for(int i = x; i < (x+h) && i < 1000; ++i){
			for(int j = y; j < (y+w) && j < 1000; ++j){
				int inche = stoi(to_string(i) + to_string(j));
				auto it = inches.insert(inche);
				if(!it.second){
					over.insert(inche);
				}
			}
		}
	}
	
	cout << over.size() << endl;

	return 0;
}
*/