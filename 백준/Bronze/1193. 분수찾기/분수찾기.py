# BOJ 1193 분수 찾기
x = int(input())
b = 0; n =1

while x>=n:
    b += 1
    n += b

parent, child = 0, 0

diff = x - (n-b)
if b%2!=0:
    parent = diff + 1
    child = b - diff
else:
    parent = b - diff
    child = diff + 1

print(f"{child}/{parent}")
