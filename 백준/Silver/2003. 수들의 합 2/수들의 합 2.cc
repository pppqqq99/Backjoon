#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

vector <int> v;

int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }

    // sort(v.begin(), v.end());

    int left = 0, right = 0, cnt = 0;
    long long sum = 0;
    while(right <= v.size()){
        
        //printf("left : %d, right : %d, sum : %lld\n", left, right, sum);
        if(sum == m){
            cnt++;
            sum -= v[left++];
        }else if(sum < m){
            sum += v[right++];
        }else{
            sum -= v[left++];
        }

    }
    
    cout<<cnt<<endl;
}