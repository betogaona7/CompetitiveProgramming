#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Record{
	char type;
	int year, month, day, hour, minute;
	int id;
	bool operator < (Record b) const{
		return (year < b.year) || 
			   (year == b.year && month < b.month) ||
			   (year == b.year && month == b.month && day < b.day) ||
			   (year == b.year && month == b.month && day == b.day && hour < b.hour) ||
			   (year == b.year && month == b.month && day == b.day && hour == b.hour && minute < b.minute);
	}
};

struct Guard{
	char state;
	int sleep, sleeping_since;
	int mins[60];
};

Guard *new_guard(){
	Guard *guard = new Guard;
	
	guard->state = 'w';
	guard->sleep = 0;
	guard->sleeping_since = -1;
	for(int i = 0; i < 60; ++i) guard->mins[i] = 0;
	
	return guard;
}


int main(){
	vector < Record > records;
	unordered_map <int, Guard*> guards;
	string line;
	
	while(getline(cin, line)){
		Record r;
		sscanf(line.c_str(), "[%d-%d-%d %d:%d]", &r.year, &r.month, &r.day, &r.hour, &r.minute);
		r.type = line[19];
		if(r.type == 'G') sscanf(line.c_str()+25, "#%d", &r.id);
		records.push_back(r);
	}
	
	sort(records.begin(), records.end());
	
	
	int id = 0;
	for(Record r: records){
		switch(r.type){
			case 'G':  
				id = r.id;
				if(guards.find(id) == guards.end()) guards[id] = new_guard();
				guards[id]->state = 'w';
				break;
			case 'f':
				if(guards[id]->state == 's') break;
				guards[id]->sleeping_since = r.minute;
				guards[id]->state = 's';
				break;
			case 'w':
				if(guards[id]->state == 'w') break;
				guards[id]->sleep += (r.minute - guards[id]->sleeping_since);
				for(int i = guards[id]->sleeping_since; i < r.minute; ++i){
					guards[id]->mins[i] += 1;
				}
				guards[id] -> state = 'w';
				guards[id] -> sleeping_since = -1;
				break;
		}
	}
	
	/* Part 1 */
	int max = 0, minute = 0, sleepyhead = 0;
	for(auto it : guards){
		if(it.second->sleep > max){
			max = it.second->sleep;
			sleepyhead = it.first;
		}
	}

	for(int i = 0; i < 60; ++i){
		if(guards[sleepyhead]->mins[i] > guards[sleepyhead]->mins[minute]) minute = i;
	}
	cout << sleepyhead * minute << endl;

	/* Part 2 */
	max = 0, minute = 0, sleepyhead = 0;
	for(auto it : guards){
		int m = 0;
		for(int i = 0; i < 60; ++i){
			if(it.second->mins[i] > it.second->mins[m]) m = i;
		}
		if(it.second->mins[m] > max){
			max = it.second->mins[m];
			minute = m;
			sleepyhead = it.first;
		}
	}
	cout << sleepyhead * minute << endl;
	
	return 0;
}