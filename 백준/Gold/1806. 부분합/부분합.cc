#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, s;

vector <int> v;

int main(){
    cin>>n>>s;

    for(int i=0; i<n; i++){
        int tmp;
        scanf("%d", &tmp);  
        v.push_back(tmp);
    }

    int sp=0, ep=0, minD = n+1;
    long long sum=v[0];
    while(ep < v.size()){
        if(sum < s){
            ep++;
            sum += v[ep];
        }else{
            if(ep < sp){
                minD = 1;
                break;
            }
            if(minD > ep-sp+1){
                minD = ep-sp+1;
                //cout<<sp<<", "<<ep<<endl;
            }
            sum -= v[sp];
            sp++;
            

        }
    }

    if(minD == n+1) cout<<0<<endl;
    else cout<<minD<<endl;
}
