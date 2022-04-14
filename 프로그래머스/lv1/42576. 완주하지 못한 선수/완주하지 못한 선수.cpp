#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;

    for (string s : completion) {
        if (m.find(s) != m.end())
            m[s] += 1;
        else m.insert(make_pair(s, 1));
    }

    for (string s : participant) {
        map<string, int>::iterator iter = m.find(s);
        if (iter == m.end()) {
            // not founded 
            answer = s; break;
        }
        else if((*iter).second >= 2) {
            (*iter).second -= 1;
        }
        else {
            m.erase(iter);
        }
    }

    return answer;
}