#include <string>
#include <vector>

using namespace std;

int alpha[27] = {0,};

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    int i,j,k=0, flag=0;
    
    for(i='A'-'A'; i<='Z'-'A'; i++){
        flag=0;
        for(j=0; j<101; j++){
            if(flag == 1) break;
            for(k=0; k<keymap.size(); k++){
                if(keymap[k].length() < j+1) continue;
                if(keymap[k][j] == 'A' + i){
                    alpha[i] = j+1;
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0) alpha[i]=-1;
    }
    
    for(i=0; i<targets.size(); i++){
        int cnt=0, k;
        for(j=0; j<targets[i].length(); j++){
            if((k = alpha[targets[i][j] - 'A']) == -1){
                cnt = -1;
                break;
            }else{
                cnt += k;
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}