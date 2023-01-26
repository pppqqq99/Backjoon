#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

// vector <int> v;
//int v[10000] = {0,};

int main(){
    cin>>n>>m;
    // vector <int> v;
    int v[10000] = {0,};

    for(int i=0; i<n; i++){
        int tmp;
        scanf("%d", &tmp);
        // v.push_back(tmp);
        v[i] = tmp;
    }

    int left = 0, right = 0, cnt = 0;
    long long sum = 0;

    while(right <= n){
        
        if(sum == m){
            cnt++;
            sum -= v[left++];
        }else if(sum < m){
            if(right == n) break;
            sum += v[right++];
        }else{
            sum -= v[left++];
        }

    }

    cout<<cnt<<endl;
}