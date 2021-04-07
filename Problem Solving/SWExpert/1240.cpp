#include <iostream>
#include <string>
 
using namespace std;
 
string decode_s[10] = { "0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011" };
int N, M;
 
// valid 하면 전체 수의 합을 반환 or 0 반환
// 홀수합*3 + 짝수합 + 검증코드 = 10의 배수
int is_valid(int num[8]) {
    int odd_sum = 0;
    int even_sum = 0;
    for (int i = 0; i < 7; i++) {
        if (i & 1 != 0) { // 홀수 index = 짝수
            even_sum += num[i];
        }
        else
            odd_sum += num[i];
    }
 
    int check_num = num[7];
    int cal = (odd_sum * 3 + even_sum) + check_num;
    // 계산이 10의 배수이면  10으로 나눈 나머지가 0
    if (cal % 10 == 0 )
        return odd_sum + even_sum + check_num;
    else
        return 0;
}
 
int main() {
 
    //freopen("input.txt", "r", stdin);
 
    int T = 0;
    cin >> T;
 
    for (int t = 1; t <= T; t++) {
        char arr[50][100] = { 0, };
 
        // input
        N = 0;
        M = 0;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> arr[i][j];
            }
        }
 
        /* code extraction */
        char code[57] = { 0, };
 
        int i, j;
        int f = 0;
        // 1의 시작점을 찾는 loop
        for (i = 0; i < 50; i++) {
            if (f == 1) break;
            for (j = 0; j < 100; j++) {
                if (arr[i][j] == '1') { // 1찾았으면 이중 포문 탈출
                    f = 1;
                    break;
                }
            }
        }
        int start = j;
 
        // start 기준으로 맨 뒤(start + 55)가 0이면, start-1 ~ 
        while(arr[i][start+55] == '0') start = start - 1;
 
        //  똑같이 56개를 저장하지만, 
        // 맨 뒤자리 1을 맞추기 위해서 start 지점을 조절함
        for (int k = 0; k < 56; k++) {
            code[k] = arr[i][start + k];
        }
        //cout << "code : " << endl;
        //for (int j = 0; j < 56; j++) {
        //  cout << code[j];
        //}
        //cout << endl;
 
        int num[8] = { 0, };
        int k = 0;
        int code_len = 56;
        for (int i = 0; i < code_len; i += 7) { // 8번 돌아야 7자리 + 검증코드
 
            char p_num[8]; // 7자리 이진수 
            sprintf(p_num, "%c%c%c%c%c%c%c", code[i], code[i + 1], code[i + 2], code[i + 3], code[i + 4], code[i + 5], code[i + 6]);
 
            for (int j = 0; j < 10; j++) {
                if (p_num == decode_s[j]) {
                    num[k++] = j;
                }
            }
        }
        //k = 8 to_num[7]은 검증 코드
        //for (int j = 0; j < k; j++) {
        //  cout << num[j] << " ";
        //}
        //cout << endl;
 
        printf("#%d %d\n", t, is_valid(num));
    }
    return 0;
 
}
