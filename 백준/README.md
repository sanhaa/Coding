### 문제 정리 (최신순) 👀 🕛  ✔️ 

- [x] [BOJ 23291: 어항 정리](https://www.acmicpc.net/problem/23291)
  <details>
  <summary> 🕛=3h ✔️ 🕛=2h 10m ✔️ 긴 구현과 시뮬레이션</summary>
   
   - 👀 90도로 회전할 때 `이전 높이 -> 다음 target`은 맞는데 다음 90도 회전 여부 판단할 때는 `이번 높이`와 `size()-다음 target` 비교해야 함
   - 👀 반복문마다 **바뀌는 것**과 **종료 조건** 꼭 확인하기
   - 문제 과정이 길었지만 구현은 일반적인 편
   - 2차원 배열이 필요했지만 높이가 각각 달라 vector 사용
   - 90도, 180도 회전하고 쌓는 부분에서 역순으로 `vector.push_back()`: 인덱스 설계하는 것이 핵심

  </details>

- [x] [BOJ 15686: 치킨배달](https://www.acmicpc.net/problem/15686)
  <details>
  <summary>🕛=2h ✔️ 재귀로 조합구하기: 오름차순만 생각</summary>
  
   - 👀 비트마스킹은 생각 안해도 될 듯
   - 👀 재귀로 조합 구하기 = 오름차순만 생각: for 인덱스 조절
   - 치킨이 싫어질 뻔 했다. 시간초과 때문에 고생했다.
   - 재귀 (백트래킹)으로 BF 구현 
   - 조합을 재귀로 구현하면 이거랑 비슷한데, 아................
      ```C++
      // s: 이번에 선택한 인덱스
      // selected: 지금까지 선택한 것들
      void recurse(int s, vector<int> selected){
         /// .....
         for(int i = s+1; i<size; i++){ // i를 0부터 돌리는 게 아니라 방금 선택한 것의 다음꺼부터 푸는 게 핵심
            selected.push_back(i);
            recurse(i, selected);
            selected.pop_back(); // 포함 안한 조합도 세야 하므로 까먹지 말 것
         }
      }
      ```
   - selected 배열에 직접 안넣고 방문 체크만 해도 됨 + `비트마스킹` -> 근데 돌려보니까 시간은 비슷한 듯 
  
  </details>

- [X] [BOJ 15684: 사다리 조작](https://www.acmicpc.net/problem/15684)
  <details>
  <summary> 🕛=1.1h ✔️ 백트래킹할 때 중복 최소인지</summary>
   
    - 👀 어떤 정보가 board 한 칸을 차지 하지 않고 사이값을 나타낼 때 인덱스 주의  
    - 정답률보고 식겁했지만, INT_MAX 때문에 컴파일 에러난 거 빼고는 한 번에 맞춤 (사실 이전에 한 번 풀었던 거지만..)
    - `백트래킹`: 모든 경우의 수 구하기 (BF) + 가지치기 (사다리 개수 <= 3)
    - `백트래킹`: 모든 경우의 수를 구하고 있는지, 중복을 최소화하고 있는지. (현재 사다리 verti 이상의 사다리 추가)  

  </details>

- [x] [BOJ 15683: 감시](https://www.acmicpc.net/problem/15683)
  <details>
  <summary>🕛=2h ✔️ 구현, BF, 시뮬레이션</summary>  

  - 👀 잘 짠 것 같은데, 시간이 오래걸렸네...
  - 재귀를 이용한 Brute Force 구현
  - 재귀 함수 인자로 배열을 복사해서 넘겨주려면 vector 사용해야 한다
  - 테스트케이스: 최대, **최소** 값 넣기
  - 상하좌우 인덱스로 방향 나타낼 때 제대로 노트에 적어서 확인하고 코드 짜기

  </details>

- [x] [BOJ 14891: 톱니바퀴](https://www.acmicpc.net/problem/14891)
  <details>
  <summary>🕛=1h ✔️ 구현, 시뮬레이션</summary>

  - 👀 바뀌는 타이밍: 동시 or 순차 생각 잘하기
  - que 쓴거는 잘 생각했는데 동시에 돌아야 돼서 12시방향을 가르키는 인덱스가 마지막에 한 번에 바뀌어야 함.
  - 톱니가 시계방향으로 돌면 인덱스는 반대 방향으로 돌아야 함 
  - index 시계/반시계 방향 돌리기 팁:   
     ```C++
     // N: 배열 길이
     // idx: 현재 idx
     // dir: 돌리고 싶은 방향, 1 or -1
     idx = (N + idx + dir)%N
     // 이렇게 하면 idx>N, idx<0 범위 둘 다 커버 가능
     ```

 </details>
 
- [x] [BOJ 14890: 경사로](https://www.acmicpc.net/problem/14890)
   <details>
   <summary>🕛=1h 40m ✔️ ✔️ 구현, 이중 반복문 인덱스</summary>
   <div>
   
   - 👀 for 문 안의 index가 for 내부에서 변경될 때는 `while(idx<범위)` 사용하기
      ```
      왜냐면 for 돌면서 +1씩 되는 것까지 생각하면서 인덱스 변경하려면 복잡함
      ```
   - 👀 다 짜고 print로 틀린 부분 보려면 어려우니까 main test case 하나 잡고 구현하면서 print 찍기 
   - 높이 차이를 구하려고 cur, prev 위치를 비교, 경사면 설치할 때는 next 변수 사용하면서 뒤로 설치 vs. 앞으로 설치 구현
   - `placed[]`: 일차원 배열에 설치 여부 체크 했는데 일차원이라 대응시키는 게 헷갈린 거 같기도 하고
   - 맨날 이중 반복문으로 검사하고 나서 인덱스 바꿔주는 데서 시간이 너무 오래걸림 --> inner for문에서 사용하는 변수는 복사해서 사용하고, `+=l` or `+=i`와 같이 일관성 있게 해야할 듯
   - row 탐색, col 탐색에 공통적으로 적용할 수 있는 코드 구현
   - ~C++ 연산자 overloading 활용하기~
   
   </div>
   </details>
   
- [x] [BOJ 14503: 로봇청소기](https://www.acmicpc.net/problem/14503) 
   <details>
   <summary>🕛=30m ✔️✔️</summary>
   <div>     
      
   - **DFS + 방향 전환**
   - 네 방향 모두 청소할 수 없을 때 후진하거나 정지 -> `while()`로 네 방향 탐색하고 나와서 `if(네 방향 불가)` 조건을 한 번 더 해줘야 했음
   - 네 방향 탐색 후 갈 곳 없으면 ~~ -> `while` 말고 `for`문으로 4번이라는 거 명확히 해주기
   
   </div>
  </details>
   
- [x] [BOJ 14500: 테트로미노](https://www.acmicpc.net/problem/14500) ✔️✔️
   <details>
   <summary> 구현, BF </summary>
   <div>  
      
   - 이차원 배열 안에서 특정 모양 BF로 찾을 때, board를 90도씩 회전하는 방법 떠올리기
   - 90도 회전 코드 짤 때, `N*M` 이면 `vector<vector<int>>` 쓰는 게 나은 듯함. 
   - row, col 잘 바꿔주기
     ```C++
      // board -> new_board: 90도 회전
      for (int c = 0; c < COL; c++) { // COL = board col 사이즈
         for (int r = 0; r < ROW; r++) { // ROW = board row 사이즈
            new_board[c][ROW - 1 - r] = board[r][c];
         }
      }
     ```
      
   </div>
   </details>
- [x] [BOJ 3190: 뱀](https://www.acmicpc.net/problem/3190) ✔️✔️
   <details> 
   <summary>구현, 자료구조, 시뮬레이션, 덱, 큐 </summary>  
   <div>  
      
   - snake 몸통과 부딪히는지 검사할 때 `body[]` 배열을 for문으로 돌지 않고 `board`에 아예 표시함
   - body 배열이 필요한 건 똑같지만 반복문으로 검사하지 않아서 시간 단축
   - `endf` 플래그로 종료하는 로직도 간단해짐
   - L, D로 왼쪽 오른쪽 방향 전환할 때 dir 바꿔주는 배열은 잘 짠듯
      ```C++
      int L_ni[4] = { 2, 3, 1, 0 }; // Left rotate, next idx(dir)
      int R_ni[4] = { 3, 2, 0 ,1 }; // new dir idx(Right rotate) = R_ni[dir]
      ```
      
   </div>  
   </details>
- [x] [BOJ 13460: 구슬탈출2](https://www.acmicpc.net/problem/13460) ✔️✔️
   <details> 
   <summary>BF, backtracking </summary>  
   <div>  
      
   - 옛날에 어렵게 풀었던 것 치고는 별 게 없다...?  
   - 확실히 dr, dc 배열 만들어서 하는 게 편하다.  
   - RED, BLUE 동시에 들어갈 때, 구슬 위치가 변하지 않았을 때 -> 재귀 return 하기  
   - 굴려서 같은 위치가 되면 -> 뒤에 있던 구슬 한 칸 밀기  
      
   </div>  
   </details>
   
- [x] [BOJ 14889: 스타트와 링크](https://www.acmicpc.net/problem/14889) 🕛=1h ✔️
   <details>
   <summary>BF, backtracking</summary>
   <div>
      
   - 조합 문제인데 순열 구하듯이 하면, 중복이 너무 많음 ex. {1, 2, 3}, {1, 3, 2}, {2, 1, 3} ...
   - 재귀 후 for문 돌 때 현재 위치부터 탐색해서 항상 오름차순 순열만 구하도록 하기
   - 두 팀을 구분해서 중복 찾기는 어떻게 고칠까..?
   ```text
   // 현재는 둘 다 검사
   start = {1, 2, 3}, link = {4, 5, 6}
   start = {4, 5, 6}, link = {1, 2, 3}
   ```
      
   </div>
   </details>
   
- [x] [BOJ 14888: 연산자끼워넣기](https://www.acmicpc.net/problem/14888) 🕛=0.5h
   - `BF`, `backtracking`
   - 재귀로 순열 구하듯이 풀었고, 음수 양수 min max 값 잘 생각하기
   
- [x] [BOJ 14501: 퇴사](https://www.acmicpc.net/problem/14501) +
   - 🕛=0.5h
   - `BF`, `DP`
   - 재귀로 BF 하는데 뭔가 애매하다? 싶으면 main에서 처음 재귀 함수 호출하는 부분을 잘 조절할 것 
- [x] [BOJ 21611: 마법사 상어와 블리자드](https://www.acmicpc.net/problem/21611)
   - 🕛=2.5h
   - `구현`, `시뮬레이션`
   - 아예 처음부터 2차원 map -> 1차원 vector로 변환하고 얼음 파편으로 구슬 파괴할 때 index 규칙 구해서 처리
      - [ ] 달팽이 순회 복습 
- [x] [BOJ 23288: 주사위 굴리기2](https://www.acmicpc.net/problem/23288)
   - 🕛=1h
   - `구현`, `그래프 탐색`, `BFS`, `DFS`, `시뮬레이션`
   - enum 쓸 때 순서 유의 (동 - 남 - 서 - 북)
   - `dice[]` 배열 안의 값 바꿀 때 밀고 당기는 거 헷갈려서 `new_dice[]` 복사해서 사용함 -> 헷갈릴 때는 쉬운 방법으로
   - 이어져 있는 같은 숫자 탐색이라 DFS, BFS 둘 다 사용해도 된다.
- [x] [BOJ 23289: 온풍기 안녕!](https://www.acmicpc.net/problem/23289)
   - 🕛=3h
   - `구현`, `시뮬레이션`
   - 벽 정보를 저장하고 벽인지 검사하는 로직을 생각하는 데 시간이 오래걸림   
      - `bool walls_hori[]` `bool walls_verti[]` 이차원 배열 만들어서 따로 검사
      - 인접한 두 칸이 수직 인접 or 수평 인접인지 판단
      - 인접한 두 칸의 대소 관계를 비교하여 기준 칸의 `walls` 배열의 true/false 체크
      - 수직 인접: walls_hori 검사, 아래 칸이 기준 칸이 됨
      - 수평 인접: walls_verti 검사, 왼쪽 칸이 기준 칸이 됨 
   - 이차원 배열 복사는 웬만하면 vector 쓰지 말 것, `copy_arr()` 함수 만들어서 value 정확히 복사해주기
   - 인접한 칸들의 update가 동시에 일어날 때 -> `visit` 배열 사용, visit 검사는 아래와 같이
      ```C++
      for(int i=0;i<R;i++){
         for(int j=0;j<C;j++){
            if(visit[i][j]) continue;
            visit[i][j] = true; // 현재 기준이 되는 칸만 방문 체크
            
            for(int d=0;d<4;d++) {
               // 인접 칸 검사
               // ....
               if(visit[nr][nc]) continue; // 인접 칸이 이미 기준 칸으로 사용되었다면 건너 뛰기
               // 현재 기준 칸과의 연산만 이루어진 것이므로 인접 칸은 따로 방문체크 하지 않음
               // ....
      // ....
      ```


 
- [x] [BOJ 23290: 마법사 상어와 복제](https://www.acmicpc.net/problem/23290) +
   - 🕛=4h -> 3h
   - 2차 후기
      ```
      와 진짜.. 한 번 풀었던 건데도 너무 헤맸다. 상어가 갔던 칸 다시 못간다고 왜 단정지었을까? (상,하,상) 가능인데 visit 검사 해버림
      메모리랑 시간은 단축시켰음: shark_move()할 때 전체 배열 복사하지 않고 해당 칸 vector만 복사
      ```
   - `구현`, `시뮬레이션`, `백트래킹`
   - 문제 자체가 어려웠던 건 아닌데
   - c++에서 vector와 배열이 함수 인자로 넘겨질 때 복사되는지 아닌지 헷갈려서 시간을 많이 썼음
   - 2차원 격자에 물고기 정보가 vector<int>로 들어가 있는 3차원 배열 `vector<int> map[5][5]` 사용
   - **vector는 함수 인자로 넘겨질 때 복사됨, 배열은 복사가 아니라 포인터 참조함**
   - `void func(vector<int> map[N][N])` 에서 map은 vector<int> 자료형의 이차원 배열이므로 복사되지 않고 포인터 참조함
   - [ ] TODO: shark_move() 로직 개선하기 (재귀함수 내에서 다 처리할 수는 없는지, 원본 배열 복사해서 )
   - [ ] DFS (백트래킹) 구현 복습하기
   - `shark_move()` 현재 로직: 제거되는 물고기가 최대가 되는 이동 루트 찾기 ex. (상, 상, 좌) (우, 우, 하) 등
      ```C++
      // 전역 변수
      int max_cnt = -1; // 제거된 물고기 최대 개수
      int route[3]; // 상어 루트
   
      void shark_move(map, r, depth){
         if(depth>=3){
            // max_cnt 업데이트
            // route 업데이트
            // 재귀 종료 
         }
         temp = map;
         // ...
         // for (4방향 dir 반복)
         map[nr][nc].clear(); // 물고기 제거
         shark_move(map);
         map[nr][nc] = temp[nr][nc];
      }
   
      // ......
      int main(){
         // ....
         shark_move();
         // 함수 종료 후 route 정보 가지고 
         // shark 좌표 움직이기
         // 물고기 제거하기
         // 물고기 냄새 남기기
      }
      ```

- [x] [BOJ 9372: 상근이의여행](https://www.acmicpc.net/problem/9372): BFS나 DFS를 쓰려고 했는데 그냥 노드가 N개 있을 때 모든 노드를 연결하려면 최소 N-1 개의 간선이 필요하다는 것만 알면된다.
   - 🕛=1h
  - 그럼에도 헤맸던 이유가 '비행기를 탄다'고 표현하니까 a->b 와 b->a 왔다 갔다하면 두 번 비행기를 타는 거 아닌가? 싶었는데 그냥 비행기의 종류를 구하는거라서 방향 상관없이 간선 개수만 구하면 된다.
  - 모든 도시가 연결되어 있음을 보장한다는 문제 조건이 있기 때문에 최소 신장 트리(MST)를 찾고 간선 개수를 구하면 된다.
  - MST를 직접 구할 필요 없이 간선 개수는 항상 N-1개이므로 `N-1`만 출력하면 된다.  
   
- [X] [BOJ 12100: 2048(Easy)](https://www.acmicpc.net/problem/12100): 
   - 🕛=3h
   - **`백트래킹`, `시뮬레이션`**
   - 문제 이해에도 시간이 조금 걸렸음
   - 구현할 때, 상하좌우 이동할 때 그 반대방향부터 탐색해서 합치기 + 밀기 과정 해주기
   - 이중 반복문으로 반대 방향으로 탐색하는 거 때문에 인덱스 바꾸는 거에 헤멨음
   - C언어에서 함수에 배열을 인자로 넘겨줄 때 무조건 주소값을 넘겨줌 -> vector 사용해서 복사해서 넘겨주게 함
   - 상하 / 좌우가 각각 row, col이 다르게 움직여야 해서 따로 구현했는데 잘 생각해보면 합치는 방법이 있지 않을까? --> TODO
   
- [x] [BOJ 1074: Z](https://www.acmicpc.net/problem/1074):
   - **1h**
   - `분할정복`, `재귀`
   - ~왜이렇게 어렵냐...~
   - 사분면을 나눠서 재귀로 하는거까지는 생각했는데 전역변수 ans 두고 속하지 않은 사분면은 탐색 완료했다고 치고 `ans += size x size` 핵심

- [x] [BOJ 1107: 리모컨](https://www.acmicpc.net/problem/1107)
   - **2h**
   - `BF`
   - 로직은 나름 잘 생각했는데, 구현이 부족한 건가
   - 재귀로 중복 조합하는 느낌
