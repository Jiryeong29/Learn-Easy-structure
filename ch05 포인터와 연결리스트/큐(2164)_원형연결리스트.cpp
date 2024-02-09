#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// [큐] 선입선출 fifo : 가장 먼저 들어온 데이터가 가장 먼저 나감
// [스택] 후입선출 lifo : 가장 마지막에 들어온 데이터가 가장 먼저 나감
// 단순연결리스트로 리스트 구현하기

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

class CircleQueue {
    Node* head;
    int NodeSize;
public:
    CircleQueue() : NodeSize(0), head(nullptr) {}

    void enqueue(int element) {
        if (isEmpty()) {
            head = new Node(element, nullptr);
            head->setLink(head);
        }
        else
        {
            Node* newNode = new Node(element, head->getLink());
            head->setLink(newNode);
            head = newNode;
        }
        NodeSize++;
    }
    void dequeue() {
        if (isEmpty()) {
            return;
        }
        
        Node* tmpNode = head->getLink();
        if (tmpNode == head) {
            delete head;
            head = nullptr;
            NodeSize--;
        }
        head->setLink(tmpNode->getLink());
        delete tmpNode;
        NodeSize--;
    }
    bool isEmpty() {
        return head == nullptr;

    }
    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return (head->getLink())->getData();
    }
    int size() {
        return NodeSize;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* current = head->getLink();
        do {
            cout << current->getData() << " ";
            current = current->getLink();
        } while (current != head->getLink());
        cout << endl;
    }
};
int Card2(int N){
    CircleQueue cq;
    for (int i = 1; i <= N; i++) {
        cq.enqueue(i);
    }
    while (cq.size() > 1) {
        cq.dequeue();
        cq.enqueue(cq.peek());
        cq.dequeue();
    }
    return cq.peek();
    
}
int main() {

    int N;
    scanf("%d", &N);

    printf("%d", Card2(N));


}