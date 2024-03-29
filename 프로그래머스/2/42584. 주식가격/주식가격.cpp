#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int arr[100001] = {0, };

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack <pii> st;
    
    // 초기화
    for(int i=0; i<prices.size(); i++){ answer.push_back(0); }
    
    // stack에 첫번째 값 삽입
    st.push({prices[0], 0});
    
    for(int i=1; i<prices.size(); i++){
        // top.first보다 작을 경우
        
            while(!st.empty() && st.top().first > prices[i]){
            // top.first 빼버리기 & 배열에 값 채우기 i-top.second
            answer[st.top().second] = i - st.top().second;
            st.pop();
            }
        
        
        st.push({prices[i], i});
        
    }
    
    if(st.empty()) { return answer; }
    
    int top_sec = st.top().second;
    st.pop();
    while(!st.empty()){
        // cout<<top_sec<<" - "<<st.top().second<<endl;
        answer[st.top().second] = top_sec - st.top().second;
        st.pop();
    }

    return answer;
}