// 프로그래머스 > 그리디 > 체육복
// reserve에 있는 학생이 lost에도 있을 때 다른 학생에게 빌려줄 수 없다.
// lost, reserve 배열이 순서대로 들어올지 아닐지 모름 -> 이것 때문에 시간 한참 버렸네...
// 학생 번호가 1~n인것도 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
   vector<int> student;
   for(int i=0;i<=n;i++) student.push_back(0); // 1~n
   for(int l : lost) student[l] -= 1;
   for(int r : reserve) student[r] += 1;
   
   int answer = n;

   for(int i=1;i<=n;i++){
      if(student[i] == -1){ // 체육복 없는 사람
         if(i-1 >= 1 && student[i-1] == 1) {
            student[i-1] = 0;
         }
         else if(i+1<=n && student[i+1] == 1) {
            student[i+1] = 0;
         }
          else
              answer--;
      }
   }

    return answer;
}

int main(){
   int n = 5;
   vector<int> lost = {4, 2};
   vector<int> reserve = {3};
   cout<<solution(n, lost, reserve)<<endl;

   return 0;
}