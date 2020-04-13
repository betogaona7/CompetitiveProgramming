#include <iostream> 
#include <vector>

class MyQueue{
        vector<int> data;
        int beggining;
    public:
        MyQueue(){beggining=0;}

        bool insert(int x){
            data.push_back(x);
            return true;
        }

        bool remove(){
            if(isEmpty()) return false;
            beginning++;
            return true;
        }

        int front(){
            return data[beginning];
        }

        bool isEmpty(){
            return beggining >= data.size();
        }
}