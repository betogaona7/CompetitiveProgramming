class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack <int> scores;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] != "C" && ops[i] != "D" && ops[i] != "+"){
                scores.push(stoi(ops[i]));
            }else if(ops[i] == "C"){
                scores.pop();
            }else if(ops[i] == "D"){
                scores.push(scores.top()*2);
            }else{
                int last = scores.top();
                scores.pop();
                int lastlast = scores.top();
                
                scores.push(last);
                scores.push(last+lastlast);
            }
        }
        int total = 0;
        while(scores.empty() == false){
            total += scores.top();
            scores.pop();
        }
        return total;
    }
};