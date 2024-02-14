#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int pointer=0;
    
    while(pointer < progresses.size()){
        
        // 포인터가 100일 경우 counter 증가 & answer에 저장
        int counter=0;
        while(progresses[pointer] >= 100 && pointer < progresses.size()){
            counter++;
            pointer++;
        }
        if(counter > 0){
            answer.push_back(counter);
        }
        
        // 매일 speed를 더함
        for(int i=pointer; i<progresses.size(); i++){
            progresses[i] += speeds[i];
        }
    }
    
    return answer;
}