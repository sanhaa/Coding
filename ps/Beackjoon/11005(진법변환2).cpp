// BOJ 11005 진법 변환 2
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N = 0; cin>>N;
    int B = 0; cin>>B;

    string answer = "";
    while(N>0){
        int rem = N%B;
        char c;
        if(rem>=10) c = rem + 55;
        else c = rem + '0';

        answer = c + answer;
        N /= B;
    }

    cout<<answer<<endl;

    return 0;
}