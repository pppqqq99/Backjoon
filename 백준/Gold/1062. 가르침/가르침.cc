#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
bool checked[27] = {false};
vector <int> ans;
vector <string> input_str;

void counting(){
    int flag=0, cnt=0;

    for(int i=0; i<n; i++){
        flag=0;
        for(int j=0; j<input_str[i].length(); j++){
            if(!checked[input_str[i][j] - 'a']){
                flag = 1;
                break;
            }
        }
        if(flag == 0){ cnt++; }
    }
    
    ans.push_back(cnt);
}

void make_comb(int start, int rest){
    if(rest==0){
        counting();
        return ;
    }

    for(int i=start; i<27; i++){
        if(!checked[i]){
            checked[i] = true;
            make_comb(i+1, rest-1);
            checked[i] = false;
        }
    }
}

int antatica(){

    if(k<5) return 0;
    checked['a' - 'a'] = true;
    checked['n' - 'a'] = true;
    checked['t' - 'a'] = true;
    checked['i' - 'a'] = true;
    checked['c' - 'a'] = true;

    k-=5;
    // k개의 알파벳을 선택했을 때 읽을 수 있는 단어의 개수를 카운팅하여 ans 벡터에 저장
    make_comb(1, k);

    sort(ans.begin(), ans.end());
    return ans[ans.size()-1];

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;
    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        input_str.push_back(str);
    }
    
    cout<<antatica()<<endl;
}