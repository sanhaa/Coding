# # BOJ 1874 스택 수열

def main():
    n = int(input())
    arr, st = [], []
    ans = []

    for i in range(n):
        a = int(input())
        arr.append(a)

    num = 1
    flag = True
    for a in arr:
        if flag==False: 
            break

        if len(st) == 0: #empty
            st.append(num); num+=1 
            ans.append('+') # push

        while st[-1] < a:
            st.append(num); num+=1
            ans.append('+') # push
            if num > n:
                break # IMPOSSIBLE
                
        if st[-1] == a:
            st.pop()
            ans.append('-') # pop
        else:
            flag=False; break

    if flag == False:
        print("NO")
    else:
        for a in ans:
            print(a)


if __name__ == '__main__':
    main()

