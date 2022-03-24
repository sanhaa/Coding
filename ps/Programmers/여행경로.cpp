#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool used[987654321] = {false, }; // 이미 사용한 항공권
vector<string> answer;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> st;
    st.push_back("ICN");

    while(!st.empty()){
        string cur = st.back();
        st.pop_back();
        answer.push_back(cur);
        
        vector<string> next;

        for(int i = 0; i<tickets.size(); i++){
            if (cur == tickets[i][0]){
                if(used[i]) continue;
                // 알파벳 순으로 st에 push
                // st.push_back(tickets[i][1]);
                used[i] = true;
                next.push_back(tickets[i][1]);
            }
        }
        sort(next.begin(), next.end(), greater<>());
        for(string n : next) {
            // cout<<n<<" > ";
            st.push_back(n);
        }
    }

    return answer;
}

int main(){
    vector<vector<string>> tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
    // vector<vector<string>> tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};

    vector<string> ans = solution(tickets);

    for (string s : ans){
        cout<<s<<" ";
    }
    cout<<endl;

    return 0;
}