#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// [큐] 선입선출 fifo : 가장 먼저 들어온 데이터가 가장 먼저 나감
// [스택] 후입선출 lifo : 가장 마지막에 들어온 데이터가 가장 먼저 나감
// 원형 연결리스트 구현하기


class Node {
	Node* link;
	int data;
public:
	Node(int val = 0) : data(val), link(nullptr){}
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }
	int getData() { return data; }
	void display() { printf("<%d> ", data); }
	bool hasData(int val) { return data == val; }


	// 자신 다음에 새로운 노드 n을 삽입하는 함수
	void insertNext(Node* n) {
		if (n != nullptr) {
			n->link = link;
			link = n;
		}
	}
	// 자신의 다음 노드를 리스트에서 삭제하는 함수
	Node* removeNext() {
		Node* removed = link;
		if (removed != nullptr) {
			link = removed->link;

		}
		return removed;

	}
};

class LinkedList {
	Node headNode;
public:
	LinkedList() : headNode(0) {}
	~LinkedList() { clear(); }

	void clear() {
		while (!isEmpty()) {
			delete remove(0);
		}
	}
	Node* getHead() {
		return headNode.getLink();
	}
	bool isEmpty() {
		return getHead() == nullptr;
	}

	Node* getEntry(int pos) {
		Node* n = &headNode;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == nullptr) break;
		return n;
	}
	// list.insert(0, new Node(30);
	void insert(int pos, Node* n) {
		Node* before = getEntry(pos - 1);
		if (before != nullptr) {
			before->insertNext(n);
		}
	}

	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}

	Node* find(int val) {
		for (Node* p = getHead(); p != nullptr; p = p->getLink()) {
			if (p->hasData(val)) return p;
		}
		return nullptr;
	}

	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != nullptr) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	int size() {
		int cnt = 0;
		for (Node* p = getHead(); p != nullptr; p = p->getLink()) {
			cnt++;
		}
		return cnt;
	}

	void display() {
		printf("[전체항목수 : %d ]", size());
		for (Node* p = getHead(); p != nullptr; p = p->getLink()) {
			p->display();
		}
		printf("\n");
	}
};

void main() {
	LinkedList list;
	list.insert(0, new Node(10));
	list.insert(0, new Node(20));
	list.insert(1, new Node(30));
	list.insert(list.size(), new Node(40));
	list.insert(2, new Node(50));
	list.display();
	list.remove(2);

	list.remove(list.size() - 1);
	list.remove(0);

	list.replace(1,new Node(90));
	list.display();
	list.clear();
	list.display();
}