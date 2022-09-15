#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

vector <string> sub1;
vector <string> sub2;

bool isTrue(char ch){
    if(((ch-'a')>=0 && (ch-'a')<27) || ((ch-'A')>=0 && (ch-'A')<27)) return true;
    else return false;
}

vector <string> makeSub(string str){
    int now=0;
    vector <string> sub;
    while(now < str.size()){
        if(isTrue(str[now]) && isTrue(str[now+1])){
            string temp = str.substr(now,2);
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            sub.push_back(temp);
        }
        now++;
    }
    return sub;
}

bool isSame(string str1, string str2){
    
    cout<<str1<<", "<<str2<<endl;
    if(str1 == str2) return true;
    else return false;
}

int makeAnds(){
    int cnt1=0, cnt2=0, ret = 0;
    sort(sub1.begin(), sub1.end());
    sort(sub2.begin(), sub2.end());
    
    while(cnt1 < sub1.size() && cnt2 < sub2.size()){
        if(isSame(sub1[cnt1], sub2[cnt2])){
            ret++;
            cnt1++;
            cnt2++;
        }else if(sub1[cnt1].compare(sub2[cnt2]) > 0) {cout<<"cnt2++"<<endl; cnt2++;}
        else {cout<<"cnt1++"<<endl; cnt1++;}
    }
    return ret;
}

int makeAdds(){
    // 합집합 구하기
    int cnt1=0, cnt2=0, ret = 0;
    sort(sub1.begin(), sub1.end());
    sort(sub2.begin(), sub2.end());
    
    
    while(cnt1 < sub1.size() || cnt2 < sub2.size()){
        if(cnt1 == sub1.size()){
            cnt2++;
            ret++;
        }else if(cnt2 == sub2.size()){
            cnt1++;
            ret++;
        }else if(isSame(sub1[cnt1], sub2[cnt2])){
            ret++;
            cnt1++;
            cnt2++;
        }else if(sub1[cnt1].compare(sub2[cnt2]) > 0) { cout<<"cnt2++"<<endl; cnt2++; ret++; }
        else { cout<<"cnt1++"<<endl; cnt1++; ret++; }
    }
    
    return ret;
}


int solution(string str1, string str2) {
    int answer = 0;
    sub1 = makeSub(str1);
    sub2 = makeSub(str2);
    
    cout<<sub1.size()<<", "<<sub2.size()<<endl;
    for(int i=0;i<sub1.size(); i++) cout<<sub1[i]<<endl;
    for(int i=0;i<sub2.size(); i++) cout<<sub2[i]<<endl;
    
   
    int ands = makeAnds();
    int adds = makeAdds();
    cout<<ands << ", "<<adds<<endl;
    double ret = 0;
    if(adds == 0 && ands == 0) ret = 1;
    else ret = (double)ands/adds;
    answer = ret*65536;
    return answer;
}