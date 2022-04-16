## Python 

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
    
### dictionary 
1. dictionary 선언
    ```python
    d = dict()
    d = {}
    ```
2. list -> dict
    ```python
    # 1) dictionary 컴프리헨션 사용
    # d = {key:value for key in list()}
    arr = ['A', 'B', 'C']
    d = {a: 0 for key in list()}
    ### {'A':0, 'B':0, 'C':0}
    
    # enumerate(튜플 반환): for 반복문에서 index, value 동시에 접근하면서 루프 돌릴 때 사용
    dd = {a: i for i, a enumerate(arr)} 
    ### {'A':0, 'B':1, 'C':2}
    
    # 2) dict.fromkeys(key, value)
    d = dict.fromkeys(arr, 0)
    ### {'A':0, 'B':0, 'C':0}
    
    # 3) zip
    brr = [10, 20, 30]
    d = dict(zip(arr, brr))
    ### {'A':10, 'B':20, 'C':30}
    ```
3. dictionary for
    ```python
    for value in d:
        print(value)
        
    for key, val in d.items(): # (key, value) tuple
        ### 
    for key in d.keys():
        ### 
    for val in d.values():
        ###
    ```
4. dictionary sort
    ```python
    # 1) key를 기준으로 정렬
    sorted_dict = sorted(d.items()) # 내림차순 파라미터: reverse=True
    
    # 2) value를 기준으로 정렬
    sorted_dict = sorted(d.items(), key=lambda x: x[1]) # 내림차순 파라미터: reverse=True
    ```
