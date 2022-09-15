#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

queue <string> q;


int isHit(string str){
    string hits;
    int qsize = q.size();
    int flag=0;
    for(int i=0;i<qsize;i++){
        string fr = q.front();
        if(fr == str){
            hits = fr;
            q.pop();
            flag =1;
        }else{
            q.pop();
            q.push(fr);
        }
    }
    if(flag == 1) {
        q.push(hits);
        for(int i=0;i<q.size();i++){
            string t = q.front();
            q.pop();
            q.push(t);
        }
        return true;
    }    
    else return false;
    
}

int calc(int cacheSize, vector<string> cities){
    if(cacheSize == 0) return 5*cities.size();
    
    int ret=0, cur=0;
    string ss;
    for(int i=0; i<cities.size();i++){
        ss = cities[i];
        transform(ss.begin(), ss.end(), ss.begin(), ::tolower);
    
        // hit일 때
        if(isHit(ss)){
            ret+=1;
        }else{ // hit이 아닐 때
            if(q.size() < cacheSize){ // q가 안찼을 때
                q.push(ss);
                ret+=5;
            }else{ // q가 가득 찼을 때
                q.pop();
                q.push(ss);
                ret+=5;
            }
        }
        
    }
    return ret;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    answer = calc(cacheSize, cities);
    return answer;
}