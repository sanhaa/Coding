## 문제 풀 때 했던 고민 적는 곳

#### 입력 관련
  1. scanf로 문자 입력 받을 때 줄바꿈은 무시할 수 있도록 

-----

#### 자료구조 관련
  1. `struct{static int a}`, `global int a` 시간적인 성능은 거의 같다
  2. 0 ~ M 숫자를 2차원 좌표 x, y로 나타낼 때 보통 `x = (num-1)/3 + 1; y = (num-1)%3 + 1` 등으로 연산하는데, M의 수가 적을 경우
      ```
      pair<int, int> xy = { {0, 0}, {0, 1}, {0, 2} ... };
      pair<int, int> a = xy[m];
      ```  
      
      위와 같이 나타낼 수 있다. (단, 인덱스를 주의 할 것)

--- 

#### 그래프 관련  
  1. DFS, BFS 등 탐색 할 때 visit 체크 해주는 것을 잊지 말자!
  2. visit 체크는 거의 무조건 해야 한다고 생각하셈 체크 하면 안되는 경우 visit 배열 복사본 만들기
  3. DFS, BFS 레벨이 중요할 때 (특히 BFS) 구조체에 레벨 변수 넣고 돌리는 게 제일 편함

--- 
#### DP 관련
  1. DP 는 수학적 귀납법 기반 (base case + 점화식)
  2. DP 테이블 정의 + 점화식 정의 만 하면 된다. (말은 쉽지ㅠㅠㅠㅠㅠㅠㅠ)
  3. DP 테이블 정의: 바뀌는게 뭔지를 잘 판단하자, 바뀌는 것(변수)가 DP 테이블의 인덱스(차원)가 된다. (보통 1차원 or 2차원)
  4. DP 점화식: ~지금 생각으로는~ base case부터 말고 적당히 큰 n부터 계산하는게 나을 듯

----

#### Binary Search 관련
  1. `mid = (high + low) >> 1` 연산할 때 overflow 의식하고 `long long int` 사용하기 
  2. 이미 배열 속에 있는 값 찾을 때는 종료 조건이 쉽지만,  
     `if(arr[mid] == target) break;` 
  3. 조건을 만족하는 최소값 혹은 최대값을 찾을 때는  
      - 문제 예시: [백준 2805.나무자르기](https://www.acmicpc.net/problem/2805)
      - 풀이 예시: [백준/Silver/2805. 나무 자르기/나무 자르기.cc](https://github.com/Sanhaa/Coding/blob/master/%EB%B0%B1%EC%A4%80/Silver/2805.%E2%80%85%EB%82%98%EB%AC%B4%E2%80%85%EC%9E%90%EB%A5%B4%EA%B8%B0/%EB%82%98%EB%AC%B4%E2%80%85%EC%9E%90%EB%A5%B4%EA%B8%B0.cc)
     ```
     while(low <= high) {
       // .....
     }
     answer = high
     ```
  4. `high = mid`or `low = mid`는 무한 루프 => `high = mid+1` `low = mid-1`
  5. `low=2`와 `high=3`상태일 때 (차이가 1일 때), 이 둘 중에 하나가 정답
      1. 이때 `mid` 구하면 .5는 반올림 되니까 무조건 `high` 값과 같음
      2. `high`가 찾고자 하는 답이라면 (답이 3)   
          - `low = mid+1`로 범위가 잡히고 `low > high`로 범위가 엇갈리면서 while문 탈출
      4. `low`가 찾고자 하는 답이라면 (답이 2)  
          - `high = mid-1`로 범위가 잡히고 `low==high`인 상태로 while문 한 번 더 들어감
          - `mid = (low+high)/2`에서 연산 결과값이 `low`와 같으니까
          - `low = mid + 1`로 범위가 잡히고 low, high 범위가 엇갈리면서 while문 탈출
      5. 둘 다 high 값이 정답 (3과 2)
