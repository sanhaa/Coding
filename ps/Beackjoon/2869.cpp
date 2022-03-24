// BOJ 2869 달팽이는 올라가고 싶다
#include <iostream>

using namespace std;

int main(){
    int A = 0, B = 0, V = 0;
    cin>>A>>B>>V;

    // 하루: A-B
    int res = (V-A)/(A-B) + 1;

    if((V-A)%(A-B) != 0) res+=1;
    cout << res<<endl;

    return 0;
}