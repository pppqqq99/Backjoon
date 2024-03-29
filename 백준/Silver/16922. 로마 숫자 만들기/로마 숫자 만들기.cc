#include <iostream>
#include <algorithm>

using namespace std;

bool checked[1001] = {0, };
int rome[4] = {1,5,10,50};
int cnt=0;

// n개의 로마 숫자를 사용하여 만들 수 있는 모든 수
// 현재까지의 합산
void combination(int depth, int n, int sum, int s){

    // n개의 숫자를 사용하여 만든 sum
    // sum이 처음 나오는 수라면
    if(depth == n){
        if(!checked[sum]){
            cnt++;
            //cout<<cnt<<", "<<sum<<endl;
            checked[sum] = true;
        }
        return ;

    }

    for(int i=s;i<4;i++){
        //cout<<cnt<<", "<<rome[i]<<endl;
        combination(depth+1, n, sum+rome[i], i);
        //cout<<cnt<<", "<<rome[i]<<" end"<<endl;
    }
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    combination(0, n, 0, 0);
    cout<<cnt<<endl;
}