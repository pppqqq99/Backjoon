#include <string>
#include <vector>
#include <queue>

using namespace std;
bool checked[51] = {false,};
typedef pair<int, pair<int, string>> pis;
priority_queue <pis, vector<pis>, greater<pis>>q;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    // begin을 큐에 넣음
    q.push({0, {-1, begin}});
    
    int flag=0;
    while(!q.empty()){
        int ret = q.top().first;
        int idx = q.top().second.first;
        string str = q.top().second.second;
        q.pop();
        
        if(checked[idx]) continue;
        if(idx != -1) checked[idx] = true;
        
        for(int i=0; i<words.size(); i++){
            if(checked[i]) continue;
            int cnt=0;
            for(int j=0; j<words[i].length(); j++){
                if(words[i][j] != str[j]) cnt++;
            }
            if(cnt == 1){
                q.push({ret+1, {i, words[i]}});
                if(words[i] == target){
                    flag = 1;
                    answer = ret+1;
                    break;
                }
            }
        }
        // q에서 pop하여 words의 단어들과 비교
        // 같은 것이 있다면 cnt++, q.push
        // 같은 것이 target이라면 flag=1, break
        if(flag==1){
            break;
        }
    }
    
    if(flag==0) answer = 0;
    
    return answer;
}