#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    
    int idx = 0;
    while(true){
        if(citations[idx] < idx+1){ break; }
        idx++;
    }
    answer = idx;
    return answer;
}

// 6 5 4 1 0