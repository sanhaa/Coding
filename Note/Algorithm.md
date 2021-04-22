## MEMO 
---
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

---
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

---
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
  + Backtracking: `재귀 + 가지치기(pruning)` or `stack`

</div>
</details>

---
