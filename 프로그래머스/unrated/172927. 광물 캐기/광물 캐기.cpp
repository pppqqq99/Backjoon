#include <string>
#include <vector>
#include <queue>
#include <iostream>
// 13:40 - 
using namespace std;

typedef struct st{
    int dia;
    int iron;
    int stone;
    int tired=0;
    int minIn=0;
}st;

queue <st> q;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0, minV = 50*25;
    q.push({0,0,0,0,0});
    
    while(!q.empty()){
        st f = q.front();
        //cout<<"d : "<< f.dia<<", i : "<<f.iron<<", s : "<<f.stone<<" tired : "<<f.tired<<", mineralsIndex : "<<f.minIn<<endl;
        q.pop();
        if(f.dia == picks[0] && f.iron == picks[1] && f.stone == picks[2]){
            minV = min(minV, f.tired);
            continue;
        }else if(f.minIn == minerals.size()){
            minV = min(minV, f.tired);
            continue;
        }
        
        st tmp;
        if(f.dia < picks[0]){
            tmp = f;
            tmp.dia++; // dia + 1
            // 미네랄 탐색하며 피로도 증가
            for(int i=f.minIn; i<f.minIn+5; i++){
                // 미네랄 끝에 다다를시 종료
                if(i == minerals.size()){
                    tmp.minIn = i;
                    break;
                }
                tmp.tired++;
                tmp.minIn++;
            }
            
            q.push(tmp);
        }
        if(f.iron < picks[1]){
            tmp = f;
            tmp.iron++; // dia + 1
            // 미네랄 탐색하며 피로도 증가
            for(int i=f.minIn; i<f.minIn+5; i++){
                // 미네랄 끝에 다다를시 종료
                if(i == minerals.size()){
                    tmp.minIn = i;
                    break;
                }
                if(minerals[i] == "diamond"){
                    tmp.tired += 5;
                }else{
                    tmp.tired++;
                }
                tmp.minIn++;
            }
            q.push(tmp);
        }
        if(f.stone < picks[2]){
            tmp = f;
            tmp.stone++; // stone + 1
            // 미네랄 탐색하며 피로도 증가
            for(int i=f.minIn; i<f.minIn+5; i++){
                // 미네랄 끝에 다다를시 종료
                if(i == minerals.size()){
                    tmp.minIn = i;
                    break;
                }
                if(minerals[i] == "diamond"){
                    tmp.tired += 25;
                }else if(minerals[i] == "iron"){
                    tmp.tired += 5;
                }else{
                    tmp.tired++;
                }
                tmp.minIn++;
            }
            q.push(tmp);
        }
    }    
    answer = minV;
    return answer;
}