#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main(){
	unordered_map <char, set<char>> instructions;
	vector<char> tasks;
	string line;
	while(getline(cin, line)){
		instructions[line[36]].insert(line[5]);
		instructions.emplace(pair<char, set<char>>(line[5], {}));
	}
	
	priority_queue <char, vector<char>, greater<char>> ready;
	for(auto instruction : instructions){
		if(!instruction.second.size()) ready.push(instruction.first);
	}
	
	/* Part 1 */
	while(ready.size()){
		char task = ready.top();
		ready.pop();
		tasks.push_back(task);
		for(auto &it : instructions){
			if(it.second.find(task) != it.second.end()){
				if(it.second.size() == 1) ready.push(it.first);
				it.second.erase(task);
			}
		}
	}
	
	cout << string(tasks.begin(), tasks.end()) << endl;
	
	/* Part 2 */
	priority_queue< pair<int, char>, vector<pair<int, char>>, greater< pair<int, char>>> events;
	int workers = 5, t = 0;
	while(ready.size() || events.size()){
		if(ready.size() && workers){
			char picked_task = ready.top();
			ready.pop();
			events.push(pair<int, char>(t+60+picked_task-64, picked_task));
			workers -= 1;
		}else{
			char completed_task;
			tie(t, completed_task) = events.top();
			events.pop();
			workers += 1;
			for(auto &it : instructions){
				if(it.second.find(completed_task) != it.second.end()){
					if(it.second.size() == 1) ready.push(it.first);
					it.second.erase(completed_task);
				}
			}
		}
	}

	cout << t << endl;

	return 0;
}