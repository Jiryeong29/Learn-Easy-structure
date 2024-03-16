#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
class Node 
{
	int data;
	Node* before;
	Node* after;
public:

	// 생성자
	Node(int d):	data(d), before(nullptr), after(nullptr){}
	// get
	Node* getBefore() { return before; }
	Node* getAfter() { return after; }
	// set
	void setBefore(Node* link) { before = link; }
	void setAfter(Node* link) { after = link; }
	void setData(int element) { data = element; }
	
	void display() { printf("%d ", data); }
	void insertNext(Node* insertNode) {
		if (insertNode != nullptr) {
			insertNode->before = this;
			insertNode->after = after;
			if (after != nullptr) {
				after->before = insertNode;
			}
			after = insertNode;
		}
	}
	Node* remove() {
		if (before != nullptr) { before->after = after; }
		if (after != nullptr) { after->before = before; }
		return this;
	}
};

class dequeue {
	Node front;
	Node rear;
public:
	dequeue() : front(0), rear(0) {}
	Node* getFront() {
		return front.getAfter();
	}
	Node* getRear() {
		return rear.getBefore();
	}

	void push_front(int newData) {
		Node* newNode = new Node(newData);

		newNode->setBefore(&front);
		if (isEmpty()) {
			newNode->setAfter(&rear);
			rear.setAfter(newNode);
			front.setBefore(newNode);
			return;
		}
		newNode->setAfter(front.getAfter());
		getFront()->setBefore(newNode);
		front.setAfter(newNode);
		
	}
	
	
	bool isEmpty() {
		return front.getAfter() == nullptr
			&& rear.getBefore() == nullptr;
	}
	void display() {
		for (Node* p = getFront(); p != nullptr; p = p->getAfter()) {
			p->display();
		}
		printf("\n");
	}
};

int main() {
	dequeue dq;
	dq.push_front(10);
	dq.push_front(10);
	dq.push_front(10);
	dq.display();
}
