#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

stack<int> st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, push_num;
    string instr;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>instr;
        if(instr=="push"){
            cin>>push_num;
            // 스택에 push_num을 삽입
            st.push(push_num);
        }else if(instr=="pop"){
            // 스택의 top을 출력 후 스택에서 pop
            if(!st.size()){
                cout<<"-1"<<endl;
            }else{
                cout<<st.top()<<endl;
                st.pop();
            }

        }else if(instr=="size"){
                // 스택에 들어있는 정수 개수 출력
                cout<<st.size()<<endl;

        }else if(instr=="empty"){
                // 스택이 비어있으면 1, 아니면 0 출력
                cout<<st.empty()<<endl;

        }else if(instr=="top"){
                // 스택의 가장 위에 있는 정수 출력, 정수 없을 경우 -1 출력
                if(!st.size()){
                    cout<<"-1"<<endl;
                }else{
                    cout<<st.top()<<endl;
                }

        }
      
    }
}