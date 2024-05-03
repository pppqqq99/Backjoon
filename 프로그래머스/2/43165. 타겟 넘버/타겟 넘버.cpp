#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dfs(vector<int> numbers, int target, int depth, int sum){
    int ret = 0;
    
    if(depth == numbers.size()){
        if(sum == target) return 1;
        else return 0;
    }
    
    ret += dfs(numbers, target, depth+1, sum+numbers[depth]);
    ret += dfs(numbers, target, depth+1, sum-numbers[depth]);
    
    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = dfs(numbers, target, 0, 0);
    return answer;
}