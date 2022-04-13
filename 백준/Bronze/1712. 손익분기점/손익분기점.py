# BOJ 1712
# A 고정비용
# B * 노트북 개수
# C = 노트북 가격
# 총 수입 > 총 비용 -> 손익분기점

A, B, C = map(int, input().split())

diff = C-B 
if diff<=0:
    print(-1)
else:
    print(A//diff + 1)