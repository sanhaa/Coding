# BOJ 1436 영화감독 숌

def main():
    N = int(input())
    cnt, i = 0, 666

    while True:
        if "666" in str(i):
            cnt+=1
        if(cnt == N):
            print(i)
            break
        i+=1


if __name__ == '__main__':
    main()
