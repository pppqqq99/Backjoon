// 13:47 -

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// DP 배열 2개
// DP[i][1] = max(DP[i-1][0] -1*sequence[i], -1*sequence[i])
// DP[i][0] = max(DP[i-1][1] + sequence[i], sequence[i]);

long long DP[500001][2] = {0,};

long long solution(vector<int> sequence) {
    long long answer = 0;
    DP[0][0] = sequence[0];
    DP[0][1] = -1 * sequence[0];
    answer = max(DP[0][0], DP[0][1]);
    
    for(int i=1; i<sequence.size(); i++){
        DP[i][1] = max(DP[i-1][0] + sequence[i]*-1, (long long)sequence[i]*-1);
        DP[i][0] = max(DP[i-1][1] + sequence[i], (long long)sequence[i]);
        answer = max(answer, max(DP[i][1], DP[i][0]));
    }
    return answer;
}