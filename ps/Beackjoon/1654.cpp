// BOJ 1654 랜선 자르기
// K개의 랜선 -> N개 이상의 같은 길이의 랜선
// 최대 랜선의 길이 구하기
////////////////////////////////////////////////
// 항상 K <= N 이니까, 랜선 최소값을 기준으로
// 절반 길이씩 나누면서 N개 이상이 나올 수 있는지 검토
// 현재 길이 값으로 N개 미만이 나온다 = 길이 더 작게
// 현재 길이 값으로 N개가 나온다 = 이진 탐색 그만
// 현재 길이 값으로 N개 이상이 나온다 = 최대 길이 찾기 위해 탐색
#include <iostream>

using namespace std;

const int MAX_K = 10010;
int arr[MAX_K] = {0,}; // K개의 랜선 길이
int K = 0, N = 0; // k<=1만, N<=100만

// 이진탐색, return 최대 길이
// low, high, target
// mid = low+high /2 
// mid_n = mid길이로 만들 수 있는 랜선 개수 
// mid_n == N: 탐색 종료
// mid_n < N: high = mid로 재귀 탐색
// mid_n > N: low = mid로 재귀 탐색 
// high - low <= 1: max(high_n, low_n)
int binary_search(int maxval){
    // long long int ??
    long long int low = 1;
    long long int high = maxval;

    while(low <= high){
        long long int mid = (low+high)/2;

        int n = 0;
        for(int i = 0; i<K;i++)
            n += (arr[i]/mid);

        if(n < N){
            high = mid-1;
        } 
        else{
            low = mid+1;
        }
    }

    // n == N 이 없을 때 ??
    int h = 0, l = 0;
    for(int i = 0; i<K;i++){
        h += (arr[i]/high);
        l += (arr[i]/low);
    }
    if(h >= l) return high;
    else return low;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    /* input */
    cin>>K>>N;
    int maxval = 1;
    for(int k = 0; k<K;k++){
        cin>>arr[k];
        if(arr[k] > maxval) maxval = arr[k];
    }

    int ans = binary_search(maxval);
    cout<<ans<<"\n"; 

    return 0;
}