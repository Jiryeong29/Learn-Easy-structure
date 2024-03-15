#include<iostream>
template <typename T>
class Node {
	T data;
	Node* link;
public:
	Node(): data(0), link(nullptr){}
	void setLink(Node* l) { link = l; }
	void setData(T dt) { data = dt; }
	T getData() { return data; }
	Node* getLink() { return link; }
};
template <typename T>
class Stack {
	Node* top;

public:
	Stack() : top(nullptr) {}
	void push(T element){
		Node* newNode = new Node(element, top);
		top = newNode;

	}
	void pop(){
		Node* tmp = top;
		T poppedData = tmp->data;

		top = top->next;
		delete tmp;
	}

};

template <typename T>
class queue {
	Node front;
	Node rear;
	int queueSize = 0;
public:
	queue() : front(nullptr), rear(nullptr) {}
	void push(T dt) {
		Node newNode = new Node(dt, rear);
		queueSize++;
	}
	void pop() {
		queueSize--;
	}
	void isEmpty() {

	}
};
int main() {
	

}