#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
// 푸는중


// [큐] 선입선출 fifo : 가장 먼저 들어온 데이터가 가장 먼저 나감
// [스택] 후입선출 lifo : 가장 마지막에 들어온 데이터가 가장 먼저 나감
// 원형 연결리스트 구현하기
// 이중 연결리스트 구현하기
class Node {
    int data;
    Node* before;
    Node* after;
public:
    Node(int element, Node* prev, Node* next) :
        data(element), before(prev), after(next) {}
    Node* getBefore() { return before; }
    Node* getAfter() { return after; }
    int getData() { return data; }
    void SetBefore(Node* link) { before = link; }
    void SetAfter(Node* link) { after = link; }
    void setData(int element) { data = element; }
};

class DoubleLinkedList {
    Node* head;
    int dequeueSize;
public:
    DoubleLinkedList() : dequeueSize(0), head(nullptr) {}

     // 6 : 덱이 비어있으면 1, 아니면 0을 출력한다.
    bool empty() {
        return head == nullptr;
    }
    // 1 X: 정수 X를 덱의 앞에 넣는다. (1 ≤ X ≤ 100, 000)
    void push_front(int element){
        // 빈 덱에 첫 노드를 삽입할때

        if (empty()) {

            Node* newNode = new Node(element, , head);
            head = newNode;

        }
        // 빈덱에 노드를 삽입하는 게 아닐 때
        else {

        }

        dequeueSize++;
    }
    void push_back(){}
    void pop_front() {

    }
    void pop_front() {
    }
    int front(){}
    int back(){}
    void size(){}


};

int main() {

    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; ++i) {
        int cmd;
        scanf("%d", &cmd);

        switch (cmd)
        {
        // 1 X: 정수 X를 덱의 앞에 넣는다. (1 ≤ X ≤ 100, 000)
        case 1:
            break;
        // 2 X : 정수 X를 덱의 뒤에 넣는다. (1 ≤ X ≤ 100, 000)
        case 2:
            break;

        // 3 : 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다.없다면 - 1을 대신 출력한다.
        case 3:
            break;
         // 4 : 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다.없다면 - 1을 대신 출력한다.
        case 4:
            break;
         // 5  : 덱에 들어있는 정수의 개수를 출력한다.
        case 5:
            break;
        // 6 : 덱이 비어있으면 1, 아니면 0을 출력한다.
        case 6:
            break;
        // 7 : 덱에 정수가 있다면 맨 앞의 정수를 출력한다.없다면 - 1을 대신 출력한다.

        case 7:
            break;
        // 8 : 덱에 정수가 있다면 맨 뒤의 정수를 출력한다.없다면 - 1을 대신 출력한다.
        case 8:
            break;

        }

    }
    


}
//


