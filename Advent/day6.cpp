#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	vector< pair<int, int> >  coordinates; 
	int x, y;
	string line;
	while(getline(cin, line)){
		sscanf(line.c_str(), "%d, %d", &x, &y);
		coordinates.push_back({x, y});
	}
	
	vector <int> population(coordinates.size());
	unordered_set <int> infinite;
	
	for(int x = 0; x <= 400; ++x){
		for(int y = 0; y<= 400;  ++y){
			int min_dist = 10000, closest =-1;
			for(int i = 0; i < coordinates.size(); ++i){
				int dist = abs(x-coordinates[i].first) + abs(y-coordinates[i].second);
				if(dist < min_dist){
					closest = i;
					min_dist = dist;
				}else if (dist == min_dist) closest = -1;
			}
			if (closest >= 0) population[closest] += 1;
			if(x==0 || x == 400 || y == 0 || y == 400) infinite.insert(closest);
		}
	}
	
	/* Part 1 */
	int largest_area = 0;
	for(int i = 0; i < population.size(); ++i){
		if(infinite.find(i) == infinite.end() && population[i] > largest_area){
			largest_area = population[i];
		}
	}
	
	cout << largest_area << endl;
	
	/* Part 2 */
	int region = 0, low = -10000, up = 10000;
    for(int x = low; x < up; ++x){
        for(int y = low; y < up; ++y){
            int dist = 0;
            for(int i = 0; i < coordinates.size(); ++i){
                dist += abs(x-coordinates[i].first) + abs(y-coordinates[i].second);
                if(dist > 10000) break;
            }
            if(dist < 10000) region += 1;
        }
    }
	cout << region << endl;
	
	return 0;
}