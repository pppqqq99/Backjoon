#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector <pii> v;

bool compx1(pii a, pii b){
    return a.second < b.second;
}

bool compy1(pii a, pii b){
    return a.first < b.first;
}

bool compx2(pii a, pii b){
    return a.second > b.second;
}

bool compy2(pii a, pii b){
    return a.first > b.first;
}

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    for(int i=0; i<wallpaper.size(); i++){
        for(int j=0; j<wallpaper[i].length(); j++){
            if(wallpaper[i][j] == '#'){
                v.push_back({i, j});
            }
        }
    }
    sort(v.begin(), v.end(), compy1);
    answer.push_back(v[0].first);
    sort(v.begin(), v.end(), compx1);
    answer.push_back(v[0].second);
    sort(v.begin(), v.end(), compy2);
    answer.push_back(v[0].first+1);
    sort(v.begin(), v.end(), compx2);
    answer.push_back(v[0].second+1);
    
    return answer;
}

// #의 위치를 벡터에 저장
// sort - x좌표가 작은 순으로, y좌표가 작은 순으로, x좌표가 큰 순으로, y좌표가 큰 순으로
// (0,0)에서 시작해서 우, 하로 이동 