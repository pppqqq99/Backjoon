#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n;
queue <long long> q;
bool checked[10];
int cnt=0;

int btk(int c, int t){

}

int main(){
    cin>>n;
    if(n==0) cout<<n<<endl;
    else if(n<=9) cout<<n<<endl;
    else if(n>=10) {
        for(int i=1;i<10;i++) { q.push(i); cnt++; }
        while(!q.empty()){
            long long a = q.front();
            q.pop();
            int r = a%10;
            for(int i=0;i<r;i++){
                long long result = a*10+i;
                q.push(result);
                cnt++;
                if(cnt == n){ cout<<result<<endl; exit(0); }
            }
        }
        cout<<-1<<endl;
        
    }
    
}