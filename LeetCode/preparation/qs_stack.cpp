class MyStack{
        vector <int> data;
    public:
        void push(int x){
            data.push_back(x);
        }

        bool isEmpty(){
            return data.empty();
        }

        int top(){
            return data.back();
        }

        bool pop(){
            if(isEmpty()) return false;
            data.pop_back();
            return true;
        }
}