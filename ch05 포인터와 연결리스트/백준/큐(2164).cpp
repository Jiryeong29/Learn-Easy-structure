#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// [큐] 선입선출 fifo : 가장 먼저 들어온 데이터가 가장 먼저 나감
// [스택] 후입선출 lifo : 가장 마지막에 들어온 데이터가 가장 먼저 나감
class Node {
    int data;
    Node* link;
public:
    Node(int element, Node* inputlink)
        : data(element), link(inputlink) {}

    int getData() { return data; }
    void setData(int element) { data = element; }
    Node* getLink() { return link; }
    void setLink(Node* lk) { link = lk; }
};

class Queue {
    Node* front; // 가장 먼저 삽입된 노드
    Node* rear; // 가장 최근에 삽입된 노드
    int QueueSize = 0;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(int element) {

        Node* newNode = new Node(element, nullptr);
        if (isEmpty()) { // 처음 삽입할 때 front도 삽입한 노드를 가리켜야 하므로
            front = rear = newNode;
            QueueSize++;
            return;
        }
        rear->setLink(newNode);
        rear = newNode;
        QueueSize++;
    }
    void dequeue() {
        if (isEmpty()) {
            return;
        }

        Node* tmpNode = front;
        if (isOneElement()) {
            rear = nullptr;
        }
        front = front->getLink();
        delete tmpNode;
        QueueSize--;
    }
    bool isEmpty() {
        return ((front == nullptr) && (rear == nullptr));
    }
    bool isOneElement() {
        return front == rear;
    }
    void display() {
        Node* current = front; // 현재 노드를 가리키는 포인터를 front로 초기화합니다.
        while (current != nullptr) { // 현재 노드가 nullptr이 아닐 때까지 반복합니다.
            printf("%d ", current->getData()); // 현재 노드의 데이터를 출력합니다.
            current = current->getLink(); // 다음 노드로 이동합니다.
        }
        printf("\n");
    }
    int size() {
        return QueueSize;
    }
    int peek() {
        return front->getData();
    }
};

int Card2(int N) {
    Queue q;
    for (int i = 1; i <= N; i++) {
        q.enqueue(i);
    }


    while (q.size()>1) {
        q.dequeue();
        q.enqueue(q.peek());
        q.dequeue();
        
    }
    return q.peek();

}

int main() {
    int N;
    scanf("%d", &N);

    printf("%d", Card2(N));


}