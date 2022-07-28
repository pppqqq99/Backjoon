#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <string>

using namespace std;

int n;
queue <pair<int, string>> sq;
char ch[4] = {'D', 'S', 'L', 'R'};
bool checked[10001];
int flag=0;

void dslr(int s1, string ans, int s2){

    string aa;
    char cc;
    for(int i=0;i<4;i++){
        aa = ans;
        cc = ch[i];
        int num1 = s1;
        if(cc == 'D'){
            num1 = (num1*2)%10000;
        }else if(cc == 'S'){
            if(num1 == 0)
                num1 = 9999;
            else num1 -= 1;
        }else if(cc == 'L'){
            int t = num1/1000;
            if(t == 0)  num1 *= 10;
            else{
                num1 -= t*1000;
                num1 *= 10;
                num1 += t;
            }
        }else{
            int t = num1%10;
            num1 /= 10;
            t *=1000;
            num1 += t;
        }
       
        if(!checked[num1]){
            aa += ch[i];
            sq.push({num1, aa});
            checked[num1] = true;
        }
        if(num1 == s2){
            cout<<aa<<endl;
            flag = 1;
            return ;
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n1, n2;
    cin>>n;

    for(int i=0;i<n;i++){
        sq = queue <pair<int, string>>();
        cin>>n1>>n2;
        memset(checked, 0, sizeof(checked));
        
        sq.push({n1, ""});
        flag = 0;
        checked[n1] = true;

        while(!sq.empty()){
            int s1 = sq.front().first;
            string ans = sq.front().second;
            // cout<< s1<<"->"<<str2<<", "<<ans<<endl;
            sq.pop();
            dslr(s1, ans, n2);
            if(flag==1) break;
        }
        
     }

}