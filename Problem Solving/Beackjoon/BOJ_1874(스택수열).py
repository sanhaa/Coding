# # BOJ 1874 스택 수열
import sys

def main():
    n = int(input())
    arr = [int(sys.stdin.readline()) for _ in range(n)]
    st, ans = [], []

    num = 1 # 오름차순으로 push 될 번호
    for a in arr:
        while num <= a:
            st.append(num); num+=1
            ans.append('+') # push
            if num > n:
                break
                
        if st[-1] != a:
            ans = ['NO']; break

        st.pop()
        ans.append('-') # pop

    # print answer
    for a in ans:
        print(a)


if __name__ == '__main__':
    main()

