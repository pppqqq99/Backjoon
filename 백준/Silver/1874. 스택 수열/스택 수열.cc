#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector <int> v;
stack <int> st;
queue <char> q;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, cur=0;

    // 0. 입력
    cin>>n;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    // 1. 1~n 까지 탐색
    for(int i=1;i<=n;i++){
        st.push(i);
        q.push('+');
        
        // 1-1. 만약 벡터의 현재 커서 값과 스택의 top값이 같다면 '-' 삽입
        while(!st.empty() && st.top() == v[cur]){
            q.push('-');
            cur++;
            st.pop();
        }

    }

    // 2. 출력
    if(!st.empty()){
        cout<<"NO"<<endl;
    }else{
        while(!q.empty()){
            cout<<q.front()<<"\n";
            q.pop();
        }
    }

    return 0;

}
