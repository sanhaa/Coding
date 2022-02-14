// 1221, 1219, 11315
//#pragma warning (disable : 4996)
#include <iostream>
#include <string>
#include <unordered_map>
 
 
using namespace std;
 
#define MAX_LEN 10000
 
unordered_map<string, int> m = { {"ZRO", 0}, {"ONE", 1}, {"TWO", 2}, {"THR",3 }, {"FOR", 4}, {"FIV", 5}, {"SIX", 6},{"SVN", 7}, {"EGT", 8}, {"NIN", 9} };
 
string find_key(int v) {
    for (auto iter : m) {
        if (iter.second == v)
            return iter.first;
    }
    return "";
}
 
int main() {
    //freopen("GNS_test_input.txt", "r", stdin);
 
    int T = 0; //tc 개수
    cin >> T;
 
    for (int t = 1; t <= T; t++) {
        string tc;
        int N = 0;
        cin >> tc >> N;
 
        int count[10] = { 0, };
 
        int ans = 0;
        // 빈도수 세 counting sort
        for (int i = 0; i < N; i++) {
            string num_s;
            cin >> num_s;
            count[ (m.find(num_s))->second ]++; // key값으로 정수 찾아서 개수세기
        }
 
        cout << tc << endl;
 
        // 출력하기
        for (int i = 0; i < 10; i++) {
            string out = find_key(i);
 
            for (int j = 0; j < count[i]; j++) {
                cout << out << " ";
            }
        }
        cout << "\n";
    }
 
    return 0;
}
