#include <iostream>

using namespace std;

int main(){
	int matrix[4][5] = {{1, 2, 3, 0, 4},
					    {2, 4, 3, 3, 4},
					    {2, 0, 1, 1, 3},
					    {1, 2, 0, 4, 5}};
										 
	for(int i = 0; i < 5; ++i){
		for (int j = 3; j >= 0; --j){
			cout << matrix[j][i] << " ";
		}
		cout << endl;
	}
										 
	return 0;
}