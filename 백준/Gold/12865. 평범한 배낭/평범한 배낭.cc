#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int DP[101][100001];
vector <pair<int, int>> v;
int n, k;

int main(){
    int maxV = 0, t = 0;

    // input
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int wi,vi;
        cin>>wi>>vi;
        v.push_back(make_pair(wi, vi));
    }
    v.push_back(make_pair(0,0));
    sort(v.begin(), v.end());

    // DP init
    for(int i=0; i<=k; i++)
        DP[0][i] = 0;
    for(int i=0; i<n; i++)
        DP[i][0] = 0;
    
    // DP table 채우기 - DP[i][j] -> i번째 아이템까지 사용가능할 때 무게 한도 j까지의 최대 이익
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j-v[i].first >= 0){
                DP[i][j] = max(DP[i-1][j-v[i].first] + v[i].second, DP[i-1][j]);
            }else{
                DP[i][j] = DP[i-1][j];
            }
        }
    }
    cout<<DP[n][k]<<endl;
}