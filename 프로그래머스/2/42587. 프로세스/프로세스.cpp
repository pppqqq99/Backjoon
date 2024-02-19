#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cursor = 0;
    int cycle = 1;
    int prior = 9;
    bool* flag = new bool[priorities.size()]{false};
    
    
    while(true){
        
        cursor = cursor % priorities.size();
        
        // 벡터를 한바퀴 순회하였을때 cycle을 다시 1부터, prior 1 감소
        if(cycle == priorities.size() + 1){ cycle = 1; prior--; } 
        
        
        // cursor를 하나씩 옮기며 prior와 같은 우선순위의 프로세스를 찾음
        if(priorities[cursor] == prior && !flag[cursor]){
            flag[cursor] = true;
            answer++;
            
            //cout<<cursor<<", "<<cycle<<endl;
            cycle = 0;
            if(cursor == location){
                break;
            }
        }
        
        cursor++;
        cycle++;
    }
    
    return answer;
}