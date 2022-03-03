### Python 

```
파이썬이랑 절교 했는데 학원 알바 때문에 다시 친구 먹었다.
친해지는 중임
```


### list 입력 받기
1. 공백으로 분리
    ```python
    arr = [map(int, input().split())]
    ```


2. 줄바꿈
    ```python
    # 1) 기본 for 문
    arr = []
    for i in range(N):
        arr.append(int(input())
        
    # 2) sys.stdin
    nums = []
    for line in sys.stdin:
    nums.append(line)

    # 3) 리스트 컴프리헨션 + sys.stdin.readline()
    arr = [int(sys.stdin.readline()) for _ in range(n)]
    
    ```
