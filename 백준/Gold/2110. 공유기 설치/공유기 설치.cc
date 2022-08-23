#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,c;
vector <int> v;

// 가장 가까운 두 공유기 사이의 인접한 거리가 dis일 때 공유기를 c개 박을 수 있는지
int decision(int dis){
    int spot = v[0];
    int sum=1;

    for(int j=1; j<n; j++){
        if(v[j] - spot >= dis){
            spot = v[j];
            sum++;
        }
    }

    //cout<<dis<<", "<<sum<<endl;
    
    if(sum>=c) return true;
    else return false;


}

int main(){
    cin>>n>>c;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int minV = 1;
    int maxV = v[n-1] - v[0];
    int res=0;
    while(minV <= maxV){
        int mid = (minV + maxV)/2; // 가장 인접한 두 공유기 사이의 거리를 mid라고 하자
        // cout<<mid<<endl;


        // 가장 인접한 두 공유기 사이의 거리가 mid라고 가정할 때 공유기를 c개 설치할 수 있는 mid값의 최대 찾기

        // 공유기를 c개 이상 설치할 수 있다면 -> mid의 길이를 늘려서도 되는지 확인
        if(decision(mid)){
            minV = mid+1;
            res = mid;
        }else{ // 공유기를 c개 미만으로 설치할 수 있다면 -> mid의 길이를 줄여서 c개 이상 설치 가능한 지 확인
            maxV = mid-1;
        }
    }

    cout<<res<<endl;
}
