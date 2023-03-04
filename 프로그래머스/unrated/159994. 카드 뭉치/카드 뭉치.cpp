#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int flag=0;
    int l=0, r=0;
    for(int i=0; i<goal.size(); i++){
        if(goal[i] == cards1[l]){
            l++;
        }else if(goal[i] == cards2[r]){
            r++;
        }else{
            flag=1;
            break;
        }
    }
    if(flag==0) answer = "Yes";
    else answer = "No";
    return answer;
}