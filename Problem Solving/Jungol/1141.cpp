// J 1141
#include <iostream>
using namespace std;
 
const int SIZE = 80000;
 
class queue {
public:
    int front = -1;
    int rear = -1;
    int arr[SIZE] = { 0, };
 
    bool is_full();
    bool is_empty();
    void enqueue(int val);
    int dequeue();
    int peek(); // arr[top] 반환
 
}cows;
 
bool queue::is_full() {
    if (rear >= SIZE - 1)
        return true;
    else
        return false;
}
bool queue::is_empty() {
    if (front == rear)
        return true;
    else
        return false;
}
 
void queue::enqueue(int val) {
    if (is_full())
        cout << "Queue Overflow \n";
    else
        arr[++rear] = val;
}
 
int queue::dequeue() {
    if (is_empty())
        cout << "Queue Underflow \n";
    else {
        int ret = arr[++front];
        return ret;
    }
}
 
int queue::peek() {
    if (is_empty())
        cout << "Queue Underflow \n";
    else
        return arr[front];
}
 
int calculate(queue q, int hi) {
    int ci = 0;
    while (!q.is_empty()) {
        if (hi > q.dequeue()) ci++;
        else break;
    }
 
    return ci;
}
 
int main() {
    int N = 0;
    cin >> N;
    int a[SIZE] = { 0, };
    for (int i = 0; i < N; i++) {
        //int height = 0; // 소의 키
        cin >> a[i];
        //cin >> height;
        //a[i] = height;
        //cows.enqueue(height);
    }
 
 
    int ans = 0; // c1 + ... + cn
    for (int i = 0; i < N; i++) {
        //int hi = cows.dequeue();
        int hi = a[i];
        for (int j = i+1; j < N; j++) {
            if (hi > a[j])
                ans++;
            else
                break;
        }
    }
 
    cout << ans << endl;
}
