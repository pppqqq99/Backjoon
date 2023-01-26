#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector <long long> v;

int main(){
    cin>>n;

    for(int i=0; i<n; i++){
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int l = 0, r = 0, p = 0, good = 0;
    for(p=0; p<n; p++){
        l=0;
        r=n-1;
        while(l < r){
            long long sum = v[l] + v[r];
            if(p == l){
                l++;
            }else if(p == r){
                r--;
            }else if(sum == v[p]){
                good++;
                break;
            }else if(sum < v[p]){
                l++;
            }else if(sum > v[p]){
                r--;
            }

        }
    }
    

    cout<<good<<endl;
}