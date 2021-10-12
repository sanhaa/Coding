### BOJ PS

*삼성SW역량테스트 기출 푸는중 [>>>>](https://www.acmicpc.net/workbook/view/1152)*

- [X] [3190 (뱀)](https://www.acmicpc.net/problem/3190) 
  - 알고리즘: ``` 구현, 큐 ```
  - 조건을 잘 읽기 - (방문 체크처럼) 이미 먹은 사과를 또 먹지 않도록
  - 최대값 설정할 때 구체적으로 생각하기 
    ```
    board가 N * N 일 때,
    칸의 개수 = N * N 개
    최대 시간 = N * N 초 
    ```
- [ ] [12100 (2048(easy))](https://www.acmicpc.net/problem/12100)
  - 알고리즘: ``` 구현, 백트래킹 ```
  - move, merge 두 동작으로 나눠서 구현하고 있는데, move -> merge -> move ... 계속 해야 되는지? ``` 알고리즘 수정 ```
  - backtracking 재귀 함수는 아무것도 반환하지 않음 
    ``` 
    int max = 0;
    void backtracking() {}
    ```
   - **이거 값 반환하고 비교하는 재귀함수 공부하기**

 - [X] [1018 (체스판 다시 칠하기)](https://www.acmicpc.net/problem/1018)
   - Brute Force
   - Not flip every time --> (i+j) even or odd decides 'B' or 'W'
   - **(Important) # of blocks when start with 'W' = 8x8(MAX_CNT) - starts with 'B'**
