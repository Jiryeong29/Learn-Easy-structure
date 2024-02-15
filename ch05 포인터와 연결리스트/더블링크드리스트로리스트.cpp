#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// [큐] 선입선출 fifo : 가장 먼저 들어온 데이터가 가장 먼저 나감
// [스택] 후입선출 lifo : 가장 마지막에 들어온 데이터가 가장 먼저 나감
// 이중연결리스트로 리스트 


class Node {
	Node* prev;
	Node* next;
	int data;
public:
	Node(int val): prev(nullptr), next(nullptr), data(val){}
	Node* getPrev() { return prev; }
	Node* getNext() { return next; }
	void setPrev(Node* prevLink) { prev = prevLink; }
	void setNext(Node* nextLink) { next = nextLink; }
	void display() { printf("%d", data); }
	void setData(int element) { data = element; }
	bool hasData(int val) { return data == val; }
	void insertNext(Node* n){
		if (n != nullptr) {
			n->prev = this;
			n->next = next;
			// 후행노드가 null이 아닐때는 후행노드의 prev가 n을 가리켜야 하나 null이면 가리킬 수 없다.
			if (next != nullptr) {
				next->prev = n;
			}
			next = n;
		}
		
	}
	Node* remove(){
		if (prev != nullptr) { prev->next = next; }
		if (next != nullptr) { next->prev = prev; }
		return this;
	}

};

class LinkedList {
	Node head;
public:
	LinkedList() : head(0){}
	~LinkedList() { while (!isEmpty())delete remove(0); }
	Node* getHead() {
		return head.getNext();
	}
	bool isEmpty() { return getHead() == nullptr; }
	// pos에 해당하는 주소를 가져옴
	Node* getEntry(int pos){
		Node* n = &head;
		for (int i = -1; i < pos; i++, n = n->getNext()) {
			if (n == nullptr) break;
		}
		return n;


		/*int cnt = 0;
		for (Node* n = getHead(); n != nullptr; n = n->getNext()) {
			if (cnt == pos) {
				return n;
			}
			else if (cnt > pos) {
				return n;
			}
			cnt++;

		}*/
	}
	void insert(int pos, Node* n){
		Node* prev = getEntry(pos-1);
		if (prev != nullptr) {
			prev->insertNext(n);
		}
		// 잉 nullptr일때도 삽입을 해줘야 하는거 아닌가?

	}
	Node* remove(int pos){
		Node* n = getEntry(pos);
		return n->remove();
	}
	Node* find(int val){
		for (Node* p = getHead(); p != nullptr; p = p->getNext()) {
			if (p->hasData(val)) { return p; }
			return nullptr;
		}
	}
	void replace(int pos, Node* n){
		Node* prev = getEntry(pos - 1);
		if (prev != nullptr) {
			delete prev->getNext()->remove();
			prev->insertNext(n);
		}
	}
	int size() { 
		int cnt = 0;
		for (Node* p = getHead(); p != nullptr; p = p->getNext()) cnt++;
		return cnt;
	}
	void display(){
		for (Node* p = getHead(); p != nullptr; p = p->getNext()) {
			p->display();
		}
		printf("\n");

	}
	void clear() { while (!isEmpty())delete remove(0); }
	
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