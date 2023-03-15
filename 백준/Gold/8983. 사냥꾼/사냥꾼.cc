#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
int n,m;
ll l;
vector <ll> hu;

// 동물과 사냥꾼 사이의 거리가 l보다 작거나 같아야 함
// 거리 비교를 brute force로 할 경우 n*m 시간초과
// 둘 중의 하나를 log 로 만들어줘야 함 -> 이분 탐색 가능성 존재
// 이분 탐색 가능하려면 일차원 배열 -> 사대를 이분 탐색
// 동물을 쏠 수 있는 사대를 이분 탐색으로 찾기

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int kill=0;

    cin>>m>>n>>l;
    for(int i=0; i<m; i++){
        ll t;
        cin>>t;
        hu.push_back(t);
    }
    sort(hu.begin(), hu.end());
    for(int i=0; i<n; i++){
        ll y, x;
        cin>>x>>y;
        
        int left=0, right=m-1, mid;
        // hu를 탐색하며 |x - hu[mid]| + y >= l이면 kill++;
        while(left <= right){
            mid = (left + right)/2;
            ll d = abs(x - hu[mid]) + y;
            if(d <= l){
                kill++;
                break;
            }else{
                if(hu[mid] > x) right = mid-1;
                else left = mid+1;
            }
        }
    }

    cout<<kill<<endl;

    
}