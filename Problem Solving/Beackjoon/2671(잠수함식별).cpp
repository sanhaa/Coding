#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool identify(string s){
    int len = s.length();
    // substr1 = 100~1~ = 10(part1), 0~(part2), 1~(part3)
    // substr2 = 01 = 01(part1)
    bool is_sub1 = s[0] - '0';
    int part = 1; int cont = 0; // 연속 숫자 개수

    for(int i = 0; i<len;i++){
        // cout<<is_sub1<<" "<<part<<" "<<i <<" " <<cont<<endl;
        if(is_sub1){ // substr1
            switch (part){
            case 1:
                if(i+1<len && s[i] == '1' && s[i+1] == '0') {
                    i+=1; part = 2;
                    continue;
                }
                return false;
            case 2:
                if(s[i] == '0') {
                    cont++; continue;
                }
                else {
                    if(cont==0) return false;
                    cont = 0; part = 3; i-=1;
                }
                break;
            case 3:
                if(s[i] == '1') {
                    cont++; continue;
                }
                else{ // 다음 sub str 판단
                    if(cont==0 || i+1>=len) return false;
                    
                    if(s[i+1] == '1') { // 01
                        is_sub1 = false; part = 1;
                        i-=1; cont = 0;
                    }
                    else if(cont>=2 && s[i+1] == '0'){ // (1) 00
                        is_sub1 = true; i-=2; part = 1; cont = 0;
                    }
                    else return false;
                }
                break;
            default:
                break;
            }
        }
        else{ // substr2
            if(i+1<len && s[i] == '0' && s[i+1] == '1') {
                if (i+2<len) is_sub1 = s[i+2] - '0';
                i+=1;
            }
            else return false;
        }
    }

    if(is_sub1 && (part != 3)) return false;
    return true;
}

int main(){
    string s = ""; cin>>s;
    bool ans = identify(s);

    cout<< (ans ? "SUBMARINE" : "NOISE" )<<endl;

    return 0;
}