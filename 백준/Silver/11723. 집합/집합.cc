#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
int m;
set <int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>m;
    while(m--){
        string str;
        int num;
        cin>>str;
        if(str.substr(0, 3) == "all"){ // S를 {1, 2, ... , 20}으로 바꿈
            for(int i=1;i<=20;i++) s.insert(i);
        }else if(str.substr(0, 5) == "empty"){ // 공집합으로 바꿈
            s.clear();
        }else{
            cin>>num;
            if(str == "add"){ // 추가 insert(val)
                s.insert(num);
            }else if(str == "remove"){ // 삭제
                s.erase(num);
            }else if(str == "check"){ // x가 존재하는 확인 1, 0
                if(s.find(num) != s.end()){
                    cout<<1<<'\n';
                }else{
                    cout<<0<<'\n';
                }
            }else if(str == "toggle"){ // x가 존재하면 제거, 존재하지 않으면 추가
                if(s.find(num) != s.end()){
                    s.erase(s.find(num));
                }else{
                    s.insert(num);
                }
            }
        }
    }
}