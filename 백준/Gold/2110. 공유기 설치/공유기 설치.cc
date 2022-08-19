#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
long long home[200002];

int decision(long long mid){

    long long spot = home[1];
    int num=1;
    for(int i=2;i<=n;i++){
        
        if(home[i]-spot >= mid){
            num++;
            spot = home[i];
        }
    }
    
    return num >= c;
}

int main(){
    // 구간은 가장 짧은 interval
    long long maxV=0, minV, ret, mid;
    
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin >> home[i]; 
    }
    sort(home+1, home+n+1);
    minV=1;
    maxV= home[n] - home[1];
    
    while(minV <= maxV){
        mid =(minV+maxV)/2;
        
        if(decision(mid)){
            minV = mid+1;
            ret = mid;
        }else{
            maxV = mid-1;
        }
    }
    
    cout<< ret;
    
    
}