#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map <string, int> umap;
vector <string> types;
int arr[31] = {0,};
bool checked[31] = {false, };


// 각 종류에 관한 개수를 hash 맵에 저장
// hash의 종류로 조합 계산
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    // hash 맵에 저장
    for(auto a_clothes : clothes){
        umap[a_clothes[1]]++;
    }
    
    for(auto p : umap){
        answer *= (p.second+1);
    }

    return answer-1;
}