#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visited[300] = {0,};

    for (int st = 0; st<n;st++){
		if (visited[st]) continue;
		//start_with(st, n, computers);
		vector<int> que;
		que.push_back(st);
		
		while(!que.empty()){
			int cur = que.back();
			que.pop_back();
			if (visited[cur]) continue;
			else visited[cur] = true;
			
			// cur과 연결된 컴퓨터
			for (int i = 0; i<n; i++){
				if(computers[cur][i]){
					que.push_back(i);
				}
			}	
		}
		answer++;
	}
    return answer;
}
