// BOJ 1920 수 찾기
// 정렬 후 이진 탐색
// 퀵소트
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

bool binary_search(int target, int low, int high){
    if(high < low) return 0; // not founded

    int mid = (low + high) >> 1;
    
    if(target < arr[mid]){
        return binary_search(target, low, mid-1);
    }
    else if(target > arr[mid]){
        return binary_search(target, mid+1, high);
    }
    else return 1; // target == mid
}

int main() {

	// INPUT
	int N = 0, M = 0; 
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a = 0; cin >> a;
		arr.push_back(a);
	}

	// SORT
    sort(arr.begin(), arr.end());

	cin >> M;
	for (int i = 0; i < N; i++) {
        int target = 0; cin >> target;
        // Find targets with binary search
        cout<<binary_search(target, 0, N-1)<<endl;
	}

    return 0;
}