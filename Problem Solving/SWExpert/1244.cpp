#include <iostream>
#include <algorithm>
#include <string>
 
using namespace std;
 
// global var
string numbers = ""; // 처음 input 정수로 저장
string nnn = "";
int chs = 0;
int len = 0; // 숫자판 개수
int max_price = 0;// 최대 상금
 
// 재귀  n^2
void recursion( int ch, int ii, int jj) {
 
    if (ch == 0) {
        int price = atoi(numbers.c_str()); // char array to int
 
        max_price = max(max_price, price);
        //printf("0 now max_price: %d, %d\n", price, max_price);
         
        // 이전 노드로 돌아갈 때 swap 반대로
        swap(numbers[ii], numbers[jj]);
        return;
    }
    else {
        // swap 후 재귀 함수 호출
        for (int i = 0; i < len; i++) {
            for (int j = jj; j < len; j++) {
                if (j < i || i == j) continue;
                if (ch%2==0 && (i == ii && j == jj)) continue;
 
                swap(numbers[i], numbers[j]);
                //printf("%d swaped(idx) : %d %d ",ch, i, j);
                recursion(ch - 1, i, j);
                if (ch == chs) {
                    numbers = nnn;
                    //cout << "here " << numbers << endl;
                }
            }
        }
    }
 
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 0;
    cin >> T;
 
    for (int t = 0; t < T; t++) {
 
        // 초기화
        chs = 0; // 교환 횟수
        max_price = 0;
        numbers = "";
         
        // input: 123 1
        cin >> numbers >> chs;
        len = numbers.size();
        nnn = numbers;
 
        // 재귀함수 호출
        recursion(chs, 0, 0);
 
        // output
        printf("#%d %d\n", t + 1, max_price);
    }
    return 0;
}
