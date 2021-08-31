### About optimization

---

#### 일반적인 C++ 성능(속도) 향상 방법
<details>
<summary> 자세히 보기 </summary>
<div>       

#### 1. 함수 호출 줄이기
  + 백트래킹 알고리즘처럼 재귀 가지치기 하거나 함수를 인라인화 하여 호출을 줄인다.

#### 2. 알고리즘 자체의 성능 향상
  + 예를 들어 정렬이라면 `bubble`, `quick` 중에서 당연히 quick 구현이 좋다.
  + 입력의 개수에 따라 all pair 순회할 때 Dijstra vs. floyd 선택

#### 3. if 문에 두가지 이상 조건이 있을 때 계산 빠른 걸 앞쪽으로
  + if문이 많이 호출되는 곳에서는(재귀 함수 내부 등) 효과가 좋은 것 같다...!
  + `if(a==1 || arr[i] == arr2[j])` 에서 arr, arr2 배열을 참조하는 것보다 변수 a를 확인하는게 빠르므로 앞쪽에 조건적기

#### 4. 조건문 위치
  + 재귀, 반복문 등에서 조건문을 앞쪽에 배치하여 종료 등이 빨리 이루어 질 수 있게 한다.

</div>
</details>

---  

#### Bitmask를 활용한 속도 향상
<details>
<summary> 자세히 보기 </summary>
<div>       

#### 1. 그래프 탐색 문제에서 이미 방문했거나 방문 해야하는 정점을 기록할 때 사용
  + `bool visit[N]` 해도 되지만 `int visit = 1` bit 연산이 훨씬 빠르다
  + 보통 `DP[N][1<<N]` 으로 방문 정보를 DP 테이블에 함께 기록

#### 2. Bitmask 최대 크기
  + 그래프 정점 N이 크지 않을 때
  + `int visit` int 형으로 선언하면 4바이트의 자릿수인 32(bit) 개의 정점까지 기록 가능
  + ~근데 bitmask를 사용해야 하는 문제에서는 (ex. TSP) 보통 N < 20? 그 이상 넘어가면 시간이 엄청 오래걸려서~ 

#### 3. 기억해야 할 Bit 연산
  1) i'th bit on/off  
      - on: `n | (1<<i)`
      - of: `n & ~(1<<i)`
  3) all bit on  
      - `1<<n - 1`
  5) check if power of 2  
      - n == (n & -n)

</div>
</details>
