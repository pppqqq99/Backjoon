#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자열에 부분 문자열이 속해있다면 리턴 false
// O(n^2) => 시간초과
// phone_book을 순차적으로 탐색하여 []에 저장
// 다시 순차적으로 탐색하며
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    for(int i=1;i<phone_book.size();i++){
        if(phone_book[i-1] == phone_book[i].substr(0, phone_book[i-1].size())){
            answer = false;
            break;
        }
    }
    return answer;
}