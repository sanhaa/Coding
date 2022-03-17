#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    for (int i = 1; i<=k;i++){
        for(int j = 0; j<number.size();j++){
            if(j == number.size()-1) { 
                number.erase(number.end()-1); break;
            }
            if(number[j] >= number[j+1]) continue;
            else{
                number.erase(number.begin()+j); // k번째 최적해
                cout<<number<<endl;
                break;
            }
        }

    }
    return number;
}
int main(){
    string number = "654321";
    int k = 1;
    cout<<solution(number, k)<<endl;
    return 0;
}