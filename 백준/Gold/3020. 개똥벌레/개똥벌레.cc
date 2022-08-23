#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,h;
int up[500001] = {0, };
int down[500001] = {0, };
int answer[500001] = {0, };

int main(){
    cin>>n>>h;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(i%2 == 0){
            down[a]++;
        }
        else{
            up[h-a+1]++;
        }
    }

    long long sum=0;
    for(int i=h;i>=1;i--){
        sum += down[i];
        answer[i] += sum;
    }

    sum = 0;
    for(int i=1;i<=h;i++){
        sum += up[i];
        answer[i] += sum;
    }

    int minV = 60000000;
    int res=0;
    for(int i=1;i<=h;i++){
        if(minV > answer[i]) {minV = answer[i]; res=1;}
        else if(minV == answer[i]) res++;
    }
    cout<<minV<<" "<<res<<endl;
}