#include <iostream>
#include <algorithm>
#include <vector>

#define NANO 10000000

using namespace std;

int n,x;
vector <int> v;

void bs(){
    int left=0, right = n-1;
    int ans1=-1, ans2=-1;

    while(left<right){
        int sum = v[left] + v[right];
        if(x == sum){
            ans1 = left;
            ans2 = right;
            break;
        }
        else if(sum < x){
            left++;
        }else{
            right--;
        }
    }
    if(ans1 == -1 && ans2 == -1){
        cout<<"danger"<<endl;
    }else{
        cout<<"yes "<<v[ans1]<<" "<<v[ans2]<<endl;
    }
}

int main(){
    while(true){
        cin>>x;
        cin>>n;
        if(cin.eof())break;
        v = vector<int>();
        x *= NANO;

        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }

        sort(v.begin(), v.end());
        bs();
    }

}