#include <iostream>

using namespace std;

int N = 0;
const int MAX_SIZE = 10000;
int deque[MAX_SIZE*2+10] ={0, };
int head = MAX_SIZE, tail = MAX_SIZE+1;

int empty(){
    if(tail>head) return 1;
    else return 0;
}
int size(){
    if(empty()) return 0;
    else{
        return (head-tail)+1;
    }
}
void push_front(int x){
    deque[++head] = x; //
}
void push_back(int x){
    deque[--tail] = x;
}
void front(){
    if(empty()) cout<<"-1\n";
    else cout<<deque[head]<<"\n";
}
void back(){
    if(empty()) cout<<"-1\n";
    else cout<<deque[tail]<<"\n";
}
void pop_front(){
    if(empty()) cout<<"-1\n";
    else {
        cout<<deque[head]<<"\n";
        deque[head] = 0; head--;
    }
}
void pop_back(){
    if(empty()) cout<<"-1\n";
    else {
        cout<<deque[tail]<<"\n";
        deque[tail] = 0; tail++;
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    for(int i =0; i<N;i++){
        string op = "";
        cin>>op;
        if(op == "push_front"){
            int x = 0;cin>>x;
            push_front(x);
        }
        else if (op == "push_back"){
            int x = 0; cin>>x;
            push_back(x);
        }
        else if (op == "pop_front") pop_front();
        else if(op == "pop_back") pop_back();
        else if(op == "size") cout<<size()<<endl;
        else if (op == "empty") cout<<empty()<<endl;
        else if(op == "front") front();
        else if(op == "back") back();
    }

    return 0;
}