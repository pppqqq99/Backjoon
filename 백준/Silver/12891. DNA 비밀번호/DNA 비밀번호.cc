#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, p, cnt=0;
    int a=0, c=0, g=0, t=0;
    string str;
    int a_v, c_v, g_v, t_v;


    // 0. 입력
    cin>>s>>p;
    cin>>str;
    cin>>a_v>>c_v>>g_v>>t_v;


    // 1. 부분 문자열 초기 세팅
    for(int i=0;i<p;i++){
        if(str[i] == 'A') a++;
        else if(str[i] == 'C') c++;
        else if(str[i] == 'G') g++;
        else if(str[i] == 'T') t++;
    }


    int start=0;
    // 2. 부분 문자열 하나씩 이동하며 체크
    for(int i=p;i<s+1;i++){
        if(a >= a_v && c >= c_v && g >= g_v && t >= t_v){
            cnt++;
        }

        if(i == s){
            // cout<<start<<", "<<i<<endl;
            break;
        }

        if(str[start] == 'A') a--;
        else if(str[start] == 'G') g--;
        else if(str[start] == 'C') c--;
        else if(str[start] == 'T') t--;
        else ;
        start++;

        if(str[i] == 'A') a++;
        else if(str[i] == 'G') g++;
        else if(str[i] == 'C') c++;
        else if(str[i] == 'T') t++;
    }
    
    cout<<cnt<<endl;
}