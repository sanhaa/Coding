// BOJ 14500 테트로미노
#include <iostream>

using namespace std;
typedef pair<int, int> pii;

const int MAX_N = 600;
int max_sum = 0;
int board[MAX_N][MAX_N] = {0,};
int N = 0, M = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void DFS(int level, pii selected[4]){
    int sum = 0;

    if(level >= 3){
        for(int i = 0; i < 4; i++){
            sum += board[selected[i].first][selected[i].second];
        }
        if(max_sum < sum) max_sum = sum; // update maximum
        return;
    }
    // else
    for(int i = 0; i < 4; i++){
        int nr = selected[level].first + dr[i];
        int nc = selected[level].second + dc[i];
        if(nr < 0 || nr > N || nc < 0 || nc > M) continue;

        // visit check
        int is_visited = 0;
        for(int j = 0; j < level; j++){
            if(nr == selected[j].first && nc == selected[j].second) is_visited = 1;
        }
        if(is_visited) continue;

        selected[level+1] = make_pair(nr, nc); // 이번 블록 추가
        DFS(level+1, selected);
    }
}

int main(){

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }
    pii init[4];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            init[0] = make_pair(i, j); // start point
            DFS(0, init); 
        }
    }

    cout << max_sum << endl;

    return 0;
}