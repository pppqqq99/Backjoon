#include<string>
#include <iostream>
#include <stack>

using namespace std;

stack <char> st;

bool solution(string s)
{
    bool answer = true;
    
    // 1. 문자열 s를 순차적으로 탐색
    for(int i=0; i<s.size(); i++){
    
        
        if(s[i] == '('){    // 1-1. s[i] == '('이면 stack에 push
            st.push('(');
        }else{              // 1-2. s[i] == ')'이면 
            if(st.empty()){         // 1-2-1. stack이 empty이면 answer=false;
                answer = false;
                break;
            }else{                  // 1-2-2. stack서 pop
                st.pop();
            }
        }
        
    }
    
    // 2. s탐색 후 stack이 비어있지 않으면 answer=false;
    if(!st.empty()){ answer = false; }

    return answer;
}