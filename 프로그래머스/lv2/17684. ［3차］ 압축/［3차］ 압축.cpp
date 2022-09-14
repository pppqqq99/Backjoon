#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> lzw(string msg){
    vector<int> answer;
    vector<string> dic;
    
    dic.push_back("");
    for(int i=0;i<26;i++){
        char ch='A'+i;
        string str = "";
        str += ch;
        dic.push_back(str);
    }
    
    int now = 0; // 현재 커서
    
    // dic의 마지막 요소부터 비교
    // 비교할 때 dic의 길이만큼 비교
    while(now < msg.size()){
        for(int i=dic.size()-1; i>0; i--){
            string str = dic[i];
            int d_size = str.size();
            // 사전에 존재하는 문자와 일치할 시
            if(str == msg.substr(now, d_size)){
                // now를 수정
                int bef = now;
                now += d_size;
                dic.push_back(msg.substr(bef, d_size+1));
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}
vector<int> solution(string msg) {
    vector<int> answer = lzw(msg);
    return answer;
}