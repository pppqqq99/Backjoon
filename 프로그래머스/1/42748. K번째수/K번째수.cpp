#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    
    
    for(int i=0;i<commands.size();i++){
        
        int st = commands[i][0] - 1;
        int en = commands[i][1];
        int ta = commands[i][2] - 1;
        vector <int> temp;
        temp = array;
        
        //cout<<temp.size()<<endl;
        // cout<<st<<", "<<en<<", "<<ta<<" /"<<endl;
        sort(temp.begin() + st, temp.begin() + en);
        answer.push_back(temp[st+ta]);
    }
    return answer;
}