// programmers BFS/DFS 문제 1
// DFS: 재귀, stack
#include <string>
#include <vector>
using namespace std;

int ans = 0; 
void calculate(vector<int> numbers, int target, int res){
	if (numbers.empty()){ 
		if (res == target){
			ans += 1;
		}
		return;
	}
	// numbers[0]
	int cur = numbers[0];
	numbers.erase(numbers.begin());
	
	calculate(numbers, target, res+cur);
	calculate(numbers, target, res-cur);
}

int solution(vector<int> numbers, int target) {
    calculate(numbers, target, 0);
    
    return ans;
}
