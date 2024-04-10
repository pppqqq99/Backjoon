#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n,m;


vector <long long> d;
vector <long long> arr;

// 이분 탐색을 통해 num이 data 배열에 존재하는지 확인하는 함수
int judge(int num){
    
    int start=0, end=d.size()-1;

    // data 배열의 인덱스를 탐색
    while(start<=end){

        // 해당 구간의 중간 인덱스 확인
        int mid = (start+end)/2;
        
        if(num == d[mid]){
            return 1;
        }else if(num < d[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    return 0;
    
}

// 시간 복잡도 O(n)*O(m) => 시간 초과
// 공간 복잡도 800,000
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        d.push_back(t);
    }

    cin>>m;
    for(int i=0; i<m; i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }

    sort(d.begin(), d.end());

    for(int i=0; i<m; i++){
        cout<<judge(arr[i])<<"\n";
    }
    

}