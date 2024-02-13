#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

queue <int> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    string str;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>str;

        // str이 push라면
        if(str == "push"){
            cin>>x;
            q.push(x);
        }else if(str == "pop"){
            if(!q.empty()){
                cout<<q.front()<<endl;
                q.pop();
            }else{
                cout<<-1<<endl;
            }

        }else if(str == "size"){
            cout<<q.size()<<endl;
        }else if(str == "empty"){
            if(q.empty()){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }else if(str == "front"){
            if(q.empty()){
                cout<<-1<<endl;
            }else{
                cout<<q.front()<<endl;
            }
        }else if(str == "back"){
            if(q.empty()){
                cout<<-1<<endl;
            }else{
                cout<<q.back()<<endl;
            }
        }

    }
    // 1. push X : queue에 정수 X를 삽입 push

    // 2. pop : queue의 가장 앞에 있는 정수 빼고 출력, 없을 경우 -1 pop

    // 3. size : queue 사이즈 출력 size

    // 4. empty : queue가 비어있는지 여부 출력 1 or 0 empty

    // 5. queue의 가장 앞에 있는 정수 출력 front

    // 6. queue의 가장 뒤에 있는 정수 출력 rear

    return 0;
}