# BOJ 2606 바이러스
# BFS - queue
# list, deque

ans = 0 # 바이러스에 감염된 컴퓨터의 수 

n, m = int(input()), int(input()) # 컴퓨터 수, 연결 수

arr = [[False]*(n+1) for _ in range(n+1)] # edge 정보 저장

for i in range(m):
    c1, c2 = map(int, input().split())
    arr[c1][c2] = True # connected
    arr[c2][c1] = True

# BFS
que = []
visited = [False]*(n+1)
que.append(1) # start node = 1

while que:
    cur = que.pop(0)
    if not visited[cur]:
        ans+=1
        visited[cur] = True

    for i in range(1, n+1):
        if arr[cur][i] and not visited[i]:
            que.append(i)

print(ans-1)
        