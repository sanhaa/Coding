# Algorithm & Problem Solving

2022.03 ~ 백준 문제풀이는 `/ps/Beackjoon`이 아니라 `/백준`에 업로드
(Auto git push extension for BOJ - https://github.com/BaekjoonHub/BaekjoonHub)

```bash
+-- 백준
    +-- Bronze
    +-- Gold
    +-- Silver
+-- algorithm
    +-- Combination&Permutation
    +-- DP
    +-- Graph
    +-- Sort
    +-- Stack&Queue
    +-- Tree
+-- note
+-- ps
    +-- Beackjoon
    +-- Extra
    +-- Jungol
    +-- Leetcode
    +-- Programmers
    +-- SWExpert
```

****

#### [C++] FOR 등을 활용한 반복 입출력에서 시간 줄이기 [참고](https://www.acmicpc.net/board/view/22716)
```
cin.tie(NULL);
ios_base::sync_with_stdio(false);
cout<<"\n"; // instead of 'endl'
```
1. ```cin.tie(NULL)``` cin과 cout의 묶음을 제거, cin으로 입력 받을 때 먼저 출력 버퍼를 비우는데, 온라인 저지에서는 그럴 필요 없다. 
2. ```ios_base::sync_with_stdio(false)```는 C와 C++의 버퍼를 분리, cin/cout과 stdin/stdout 싱크를 맞추지 않아서 속도가 빨라짐 (따라서 C/C++ 입출력 함수 혼용 불가)
3. ```endl```은 개행 문자 출력 + 출력 버퍼 비움 (버퍼를 비우는 작업은 굉장히 느리다.) 그냥 \n 쓰자

----
#### [C++] 자료형
- `int`: -21억 ~ +21억 =  2<sup>31</sup> -1 = `2147483647` > `2000000000` > 10<sup>9</sup> (4 bytes)
- `long long ing`: +- 9,223,372,036,854,775,807 = 2<sup>63</sup> -1 > 10<sup>18</sup> (8 bytes)


#### 도저히 틀린 이유를 모르겠을 때
  + 문제 다시 정독하면서 모든 조건에 대해 의심하기
  + 이해했다고 생각하는 것을 예시, 그림으로 다시 그려보기
  + 내 코드에서 사소한 것을 조절하면서 해보기  
    ``` int max = 0  ```  --> ``` int max = -1 ```
  + 만약 scanf로 문자를 입력받을 일이 있다면, 줄바꿈을 무시할 수 있도록 `scanf(" %c", ..)` 띄어쓰기를 하기


#### 유용한 사이트
- 알고리즘 시각화 : https://visualgo.net/ko
- 삼성SW역량평가 기출 모음 : https://cafe.naver.com/cozal


#### PS 
  1. [Beakjoon](https://www.acmicpc.net/)
  2. [SWexpert](https://swexpertacademy.com/main/main.do)
  3. [Jungol](http://jungol.co.kr/)



#### Algorithm Study
  - 1 BOJ a week
  - 1 problem review a week
  - Daily concept review and learning
