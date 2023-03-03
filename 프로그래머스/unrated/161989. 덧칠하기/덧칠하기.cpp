#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int start = section[0];
    answer++;
    
    // 벡터를 확인하며 시작점을 찾음 -> 시작점에서 m보다 작은 벡터가 발견될 시 넘어감
    for(int i=1; i<section.size(); i++){
        // v[i]가 페인트칠 한 구간에 포함되어 있다면 패스
        if(start + m - 1 >= section[i]){
            ;
        }else{
            answer++;
            start = section[i];
        }
    }
    return answer;
}

