#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long x,y,z,t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>x>>y;
    z = y*100/x;
    if(z >= 99){
        cout<<-1<<endl;
        return 0;
    }

    long long l=0, r=1000000000;

    while(l+1 < r){
        t = (l+r)/2;
        long long zt = (y+t)*100/(x+t);
        //cout<<t<<" - "<<zt<<endl;

        if(zt <= z){
            l = t;
        }else{
            r = t;
        }
    }
    cout<<r<<endl;

}