#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map <string, int> umap;

// 참가자들을 해시로 저장한 후 completion이 hash에 존재하는 경우 값을 1로 변경 추후 hash를 순차적으로 탐색하며 값이 0인 참가자 이름을 리턴
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(int i=0;i<participant.size();i++){
        auto it = umap.find(participant[i]);
        if(it == umap.end()){
            umap[participant[i]] = 1;
        }else{
            umap[participant[i]]++;
        }
    }
    for(int i=0;i<completion.size();i++){
        umap[completion[i]]--;
    }
    for(int i=0;i<participant.size();i++){
        if(umap[participant[i]] > 0){
            answer = participant[i];
        }
    }
    return answer;
}