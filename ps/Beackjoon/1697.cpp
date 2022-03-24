// BOJ 1697 숨바꼭질
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100000;

int main(){
    int N = 0,  K = 0;
    cin>>N>>K;
    vector<pair<int, int> > q;
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.erase(q.begin());
        if(cur.first == K){
            cout<<cur.second<<endl;
            break;
        }
        q.push_back(make_pair(cur.first+1, cur.second+1));
        q.push_back(make_pair(cur.first-1, cur.second+1));
        q.push_back(make_pair(cur.first*2, cur.second+1));
    }

    return 0;
}