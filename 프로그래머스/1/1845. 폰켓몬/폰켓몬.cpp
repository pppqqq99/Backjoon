#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<int, int> hash1;

// n - n/2 
// 
int solution(vector<int> nums)
{
    int answer = 0;
    for(int i=0;i<nums.size();i++){
        auto it = hash1.find(nums[i]);
        if(it == hash1.end()){
            hash1.insert({nums[i], 1});
        }else{
            hash1[nums[i]]++;
        }
    }
    
    // n/2마리를 뽑을 때 -> hash의 수 구하기
    
    
    if(hash1.size() >= nums.size()/2) answer = nums.size()/2;
    else answer = hash1.size();
    
    return answer;
}