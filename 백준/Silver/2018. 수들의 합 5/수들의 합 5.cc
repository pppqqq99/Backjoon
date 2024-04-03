#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int start=1, end=1, cnt=0;
    long long sum=1;

    cin>>n;
    
    // 반복
    while(start <= n){

        //  
        if(sum == n){
            cnt++;
            sum -= start;
            //cout<<start<<", "<<end<<endl;
            start++;
        }else if(sum > n){
            sum -= start;
            start++;
        }else{
            end++;
            sum += end;
        }
    }

    cout<<cnt<<endl;
}