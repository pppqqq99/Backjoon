#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector <int> v;
int arr[10] = {0,};
bool checked[10] = {false, };

// 재귀적으로 순열을 찾음
void backtracking(int depth){
    
    // 탈출 조건 조합의 개수가 m일 때
    if(depth == m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    // for 문을 통해 벡터 탐색하며 선택할 수 있는 수 선택 & checked 배열에 체크
    for(int i=0; i<n; i++){
        if(!checked[i]){
            checked[i] = true;
            arr[depth] = v[i];
            backtracking(depth+1);
            checked[i] = false;
        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 0. 입력
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    // 1. 정렬
    sort(v.begin(), v.end());

    // 2. 백트래킹으로 출력
    backtracking(0);
}
