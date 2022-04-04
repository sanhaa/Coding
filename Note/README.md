## Algorithm 
#### **다익스트라 알고리즘에서 음수 간선이 존재하면 안되는 이유**
` 가장 큰 이유는 음수 간선이 있으면 다익스트라 알고리즘 자체가 작동하지 않는다는 것`
<details>
<summary> 자세히 보기 </summary>
<div>       

#### 1. (가중치의 합이 음수인)음수 사이클의 발생 가능성
  + 더 최소인 거리 값을 계속해서 구하다 보면 사이클을 돌면 돌수록 거리가 최소가 되므로 음의 무한대로 발산하게 된다.

#### 2. Edge Relaxation 계산의 오류 가능성 (min update가 안된다.)
  + `min + min = min` 의 그리디 원리가 다익스트라의 기본이기 때문에
  + 음수 간선이 존재하면 `min + min = min` 으로 구한 값이 이전 min 보다 작아 질 수 있다.(만약 이게 답이면 이전 차례에서 구하지 못한다.) 
  + 다익스트라의 원리가 제대로 작동하지 않는다.

#### 3. 회피시의 시간복잡도
  + 회피 : 코드를 변형하여 PQ를 계속 업데이트 하는 방법
  + 위의 방법은 지수 시간 복잡도가 나오므로 느리다.

#### 4. 결론
  + 웬만하면 다른 알고리즘을 사용하자
  + 벨만 포드 등

(참고 자료 : https://hy38.github.io/why-dijkstra-fail-on-a-negative-weighted-edge)

</div>
</details>

#### **최단경로 VS. 최소신장트리(MST) VS. 모든쌍최단경로**
`그래프에서 최소 가중치(경로)를 찾는 문제이지만 목적의 차이`
<details>
<summary> 자세히 보기 </summary>
<div>       

#### 1. 공통점
  + 가중치가 있는 그래프에서 사용한다.
  + 가중치(또는 경로)가 제일 작은 값을 구한다.

#### 2. 목적의 차이
  + 최단 경로 : 그래프에서 두 정점 사이의 최단 경로 구하기 ( 모든 정점을 체크해야 하지만 모든 정점을 방문할 필요는 없다. )
  + 최소신장트리 : 그래프에서 모든 정점을 연결할 때 최소 가중치 구하기 ( 모든 정점을 체크해야하고 모든 정점을 방문해야 한다. )
  + 모든 쌍 최단 경로 : 모든 두 정점 사이의 최단 경로 구하기 ( 모든 정점을 여러번 체크해야 하고 모든 정점을 여러번 방문해야 한다. ) 


#### 3. 방법(알고리즘)의 차이
  + 최단 경로 : `BFS`, `Dijkstra`, `Bellman-Ford`
  + 최소신장트리 : `Prim`, `Kruskal`
  + 모든 쌍 최단 경로 : `Floyd-Warshall Algorithm(DP)`, `Dijkstra(출발정점 바꿔가며 반복)`

#### 4. 최단 경로 유형
  + single source and single destination shortest path problem `A*`
  + single source shortest path problem `Dijkstra`
  + All pairs shortest path problem `Floyd`
  + 최소 신장 트리는 최단 경로 문제가 아니다

</div>
</details>

#### **DFS VS. BFS VS. Backtracking**
`그래프를 탐색하는 알고리즘, 목적의 차이`
<details>
<summary> 자세히 보기 </summary>
<div>       

#### 1. 공통점
  + 그래프(트리)를 탐색할 때 사용한다.

#### 2. 목적의 차이
  + DFS / BFS : 말그대로 탐색 알고리즘으로 모든 노드를 방문해야 한다.
  + Backtracking: 문제 조건에 부합하는 답을 찾는 알고리즘으로 유망한 노드만 방문하면 된다. (답이 아니면 되돌아 온다)

#### 3. 구현
  + DFS: 깊이우선탐색, `stack` 이용, or `재귀`
  + BFS: 너비우선탐색, `queue` 이용 or `반복문`
  + Backtracking: `재귀 + 가지치기(prunning)` or `stack`

</div>
</details>


----  


## Optimization


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
 
----  
    
## Etc.
1. Overloading vs. Overriding
  - `overloading`: **골라쓰기**, 매개변수, 리턴 값에 따라서
  - `overrding`: **재정의**, 상속받은 class의 객체가 사용할 함수

