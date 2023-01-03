#include <string>
#include <vector>

using namespace std;
bool checked[202] = {false, };
int ne[202] = {0, };

void fill_next(int j, vector<vector<int>> computers){
    
    // j번째 컴퓨터와 연결된 것 찾기
    for(int i=0;i<computers[j].size();i++){
        if(!checked[i] && computers[j][i]){
            checked[i] = true;
            ne[j] = i;
            fill_next(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    // next 표 채우기
    for(int i=0; i<computers.size(); i++){
        for(int j=0; j<computers[i].size();j++){
            if(!checked[j] && computers[i][j]){
                checked[j] = true;
                fill_next(j, computers);
                answer++;
            }
            
        }
    }
    return answer;
}