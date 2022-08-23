#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector <long long> v;

long long minV = 3000000000;
int ans1, ans2;

void bs(){
    int left = 0, right = n-1;
    while(left<right){
        
        long long sum = v[left] + v[right];
        if(abs(sum) < abs(minV)){
            minV = sum;
            ans1 = left;
            ans2 = right;
        }
        if(sum == 0 ){ break;}
        else if(sum < 0){ //sum이 음수이면 0에 가까워지게 음수를 줄이기
            left++;
        }else{ // 양수면 0에 가까워지기 양수를 줄이기
            right--;
        }
    }
    cout<<v[ans1]<<" "<<v[ans2]<<endl;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    bs();
}