#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int now = -1;
    
    // 1. arr 배열을 순차적으로 순회하며 now와 다를 경우 answer 배열에 추가
    for(int i=0; i<arr.size(); i++){
        if(arr[i] != now){
            answer.push_back(arr[i]);
            now = arr[i];
        }
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    return answer;
}