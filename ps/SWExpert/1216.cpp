// 1216 회문2
#include <iostream>
 
using namespace std;
 
char arr[100][100];
 
// 세로 i 가로 j부터 len의 길이의 문자가 palindrome인지 확인
bool is_palindrome(int n, int i, int start, int len) {
    if (n == 1) { // 가로
        for (int k = 0; k < len / 2; k++) {
            //printf("%c %c\n", arr[i][j + k], arr[i][j + len - k]);
            // 맞은편에 있는 문자와 같은지
            if (arr[i][start + k] != arr[i][start + len - k - 1]) return false;
        }
    }
    else { // 세로에서 i는 가로
        for (int k = 0; k < len / 2; k++) {
            // 맞은편에 있는 문자와 같은지
            if (arr[start +k][i] != arr[start + len - k - 1][i]) return false;
        }
    }
    return true;
}
 
int max(int a, int b) {
    return a > b ? a : b;
}
 
int main() {
 
    //freopen("1216_input.txt", "r", stdin);
 
    for (int t = 1; t <= 10; t++) {
        int tc;
        cin >> tc;
 
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> arr[i][j];
            }
        }
 
        int output = 0;
        // 어짜피 직선 구성만 가능하므로
        // 가로 탐색
        for (int i = 0; i < 100; i++) {
            int start = 0; // 가로 인덱스 시작 0~98
            while (start < 99) { 
                int end = 1; // 가로 인덱스 끝 1~99
                while (end < 100) {
                    // 현재 start 문자와 일치하는 end 찾기
                    while ((arr[i][start] != arr[i][end]) && (end<100)) end++;
                    //printf("%c(%d) = %c(%d)\n", arr[i][start], start, arr[i][end], end);
                    // 찾았다면 이번 start ~ end는 회문인지 검사
                    int len = end - start + 1;
                    if (is_palindrome(1, i, start, len)) { // 회문이 맞다면 최대 길이를 업데이트
                        output = max(output, len);
                    }
                    end++;
                }
                start++;
            }
        }
 
        // 세로 탐색
        for (int i = 0; i < 100; i++) {
            int start = 0; // 세로 인덱스 시작
            while (start < 99) {
                int end = 1; // 세로 인덱스 끝
                while (end < 100) {
                    // 현재 start 문자와 일치하는 end 찾기
                    while ((arr[start][i] != arr[end][i]) && (end < 100)) end++;
                    //printf("%c(%d) = %c(%d)\n", arr[i][start], start, arr[i][end], end);
                    // 찾았다면 이번 start ~ end는 회문인지 검사
                    int len = end - start + 1;
                    if (is_palindrome(0, i, start, len)) { // 회문이 맞다면 최대 길이를 업데이트
                        output = max(output, len);
 
                    }
                    end++;
                }
                start++;
            }
        }
 
        printf("#%d %d\n", t, output);
    }
 
 
    return 0;
}
