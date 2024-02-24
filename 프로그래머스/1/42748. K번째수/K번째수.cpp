#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    // 배열을 잘라서 정렬할 수 있는가?
    // commands 배열을 반복하며 i,j,k를 분리
    
    for(int i=0;i<commands.size();i++){
        int startIndex, endIndex, target;
        startIndex = commands[i][0] - 1;
        endIndex = commands[i][1];
        target = commands[i][2] - 1;
        
        vector <int> v;
        // 벡터 부분 복사
        copy(array.begin() + startIndex, array.begin() + endIndex, back_inserter(v));
        
        // 정렬
        sort(v.begin(), v.end());
        
        //cout<<v.size()<<endl;
        // // target을 answer에 저장
        answer.push_back(v[target]);
    }
    return answer;
}