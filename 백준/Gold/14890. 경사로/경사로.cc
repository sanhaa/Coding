// BOJ 14890 경사로
// 구현
// i위치 조절 -> cur 위치 조절
#include <iostream>

using namespace std;

const int MAXN = 110;
int map[MAXN][MAXN] = { 0, };
int N = 0, L = 0;

struct POS {
    int r = 0;
    int c = 0;
    POS() {}
    POS(int _r, int _c) {
        r = _r; c = _c;
    }
};

bool is_road(int r, int c, int dr, int dc) {
    bool placed[MAXN] = { 0, }; // 경사로 설치 판단, 일차원 매칭 
    //cout << r << ", " << c << endl;
    for (int i = 1; i < N; i++) {
        POS cur = POS(r + dr * i, c + dc * i);
        POS prev = POS(cur.r - dr, cur.c - dc);
        //cout<<"diff btw: " << prev.r << " " << prev.c << " ~ " << cur.r << " " << cur.c << endl;
        int diff = map[prev.r][prev.c] - map[cur.r][cur.c];
        if (diff == 0) {
            continue;
        }
        else if (diff == 1) { // \ 방향 경사로
            /////// placed 검사???
            // 낮은 곳이 L길이만큼 연속인지 판단 (cur부터 앞으로 가며 검사)
            POS next = POS(cur.r + dr, cur.c + dc);
            int l = 1;

            while (next.r >= 0 && next.c >= 0 && next.r < N && next.c < N) {
                if (l >= L) break;
                if (map[cur.r][cur.c] == map[next.r][next.c]) {
                    l++;
                    next.r += dr; next.c += dc;
                }
                else break;
            }
            if (l < L) {
                //cout << "L limit\n";
                return false;
            }
            else {
                // placed cur(i) ~ next(i+l) 까지 설치
                for (l = 0; l < L; l++) {
                    //cout << "placed in " << i + l << endl;
                    placed[i+l] = true;
                }
                // prev = next;
                i += L-1; // cur 위치 조절
            }
        }
        else if (diff == -1) { // / 방향 경사로
            ////// placed 검사: prev(i-1) ~ prev-l
            int l = 0;
            for (l = 0; l < L; l++) {
                if ((i - 1 - l >= 0) && placed[i - 1 - l]) {
                    //cout << "already placed \n" << endl;
                    return false;
                }
            }
            // 낮은 곳이 L 길이만큼 연속인지 판단 (prev부터 뒤로 가며 검사)
            POS next = POS(prev.r - dr, prev.c - dc);
            l = 1;
            while (next.r >= 0 && next.c >= 0 && next.r < N && next.c < N) {
                   if (l >= L) break;
                if (map[prev.r][prev.c] == map[next.r][next.c]) {
                    l++;
                    next.r -= dr; next.c -= dc;
                }
                else break;
            }
            if (l < L) {
                //cout << "L limit\n";
                return false;
            }
            else {
                for (l = 0; l < L; l++) { 
                    //cout << "placed in "<<i-1-l<<endl;
                    // placed next(i-1-l) ~ prev(i-1)까지 설치 
                    placed[i - 1 - l] = true;
                }
                //prev = cur;
            }
        }
        else {
           // cout << prev.r << " " << prev.c << " | " << cur.r << " " << cur.c << endl;
            //cout << "height diff >= 2\n";
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> map[i][j];
    }

    int ans = 0;
    for (int r = 0; r < N; r++) {
        int ret = is_road(r, 0, 0, 1);
        if (ret) {
            //cout << "true in r: " << r <<endl<< endl;
            ans++;
        }
    }

    for (int c = 0; c < N; c++) {
        int ret = is_road(0, c, 1, 0);
        if (ret) {
            //cout << "true in c: " << c << endl << endl;
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}