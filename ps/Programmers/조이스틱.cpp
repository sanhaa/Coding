#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mmin(int a, int b){
    return a<b?a:b;
}

int w[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 
12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int recurse(int cur, string changed, string name, int len){
    // cout<<"cur: "<<cur<<endl;
    int cnt = w[name[cur] - 'A'];
    changed[cur] = name[cur];
    if(changed == name) return cnt;
    
    int rmoves=1, lmoves=1;
    int rnext=0, lnext=0; 
    while(rmoves<=len){
        rnext = cur + rmoves;
        if(rnext >= len) rnext = rnext - len;
        if(name[rnext] != 'A' && name[rnext] != changed[rnext]) break;
        rmoves++;
    }
    while(lmoves<=len){
        lnext = cur - lmoves;
        if(lnext < 0) lnext = len+ lnext;
        if(name[lnext] != 'A' && name[lnext] != changed[lnext]) break;
        lmoves++;
    }
    
    return cnt + mmin(recurse(rnext, changed, name, len) + rmoves, 
    recurse(lnext, changed, name, len) + lmoves);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T = 0; cin>>T;
    while(T--){
        string name; cin>>name;
        string changed = "";
        for(int i=0;i<name.size();i++) changed+='A';

        cout<<recurse(0, changed, name, name.size())<<"\n";
    }

    return 0;
}