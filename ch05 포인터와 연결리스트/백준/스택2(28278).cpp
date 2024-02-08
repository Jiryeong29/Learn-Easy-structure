#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data = -1, Node* next = nullptr) : data(data), next(next) {}
};

class Stack2 {
    Node* top;
    int stackSize;

public:
    Stack2() : top(nullptr), stackSize(0) {

        //std::cout << "[top]의 주소 : " << top << std::endl;

    }

    void push(int element) {

        Node* newNode = new Node(element, top);
        top = newNode;
       /* std::cout <<"[newNode]의 주소 : " << newNode << std::endl;
        std::cout <<"[newNode]의 Data : " << newNode->data << std::endl;
        std::cout <<"[newNode]의 Next : " << newNode->next << std::endl<<std::endl;
        std::cout << "[top]의 주소 : " << top << std::endl;
        std::cout << "[top]의 Data : " << top->data << std::endl;
        std::cout << "[top]의 Next : " << top->next << std::endl << std::endl;*/
        
        stackSize++;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }

        //cout << "[ pop! ]" << endl;
        //std::cout << "[top]의 주소 : " << top << std::endl;
        //std::cout << "[top]의 Data : " << top->data << std::endl;
        //std::cout << "[top]의 Next : " << top->next << std::endl << std::endl;
        Node* temp = top;
        int poppedData = temp->data;

        top = top->next;
        delete temp;
        stackSize--;

        return poppedData;
    }

    int getStackSize() {
        return stackSize;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int peek() {
        if (isEmpty()) {
            //cout << "공백상태!" << endl;
            return -1;
        }
        return top->data;
    }
};

int main() {
    int N;
    scanf("%d", &N);

    Stack2 st;
    for (int i = 0; i < N; i++) {
        int cmd;
        scanf("%d", &cmd);

        switch (cmd) {
        case 1: {
            int tmp;
            scanf("%d", &tmp);
            st.push(tmp);
            break;
        }
        case 2: {
            printf("%d\n", st.pop());
            break;
        }
        case 3: {

            printf("%d\n",st.getStackSize());
            break;
        }
        case 4: {

            printf("%d\n", st.isEmpty());
            break;
        }
        case 5: {

            printf("%d\n", st.peek());
            break;
        }
        }
    }
    return 0;
}
