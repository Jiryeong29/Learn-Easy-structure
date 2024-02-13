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
	Node(int element) : data(element), link(nullptr) {}
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }
	void display() {
		printf("%d", data);
	}
	bool hasData(int val) { return val == data; }
	void insertLink(Node* node) {
		// 만약에 선행노드가 존재하지 않는 위치에 노드를 삽입하여도 후행노드 바로 다음 주소로 링크를 연결 시키므로 따로 예외처리를 해주지 않아도 된다.
		node->link = link;
		link = node;
	}
	Node* removeLink() {
		Node* removed = link;
		if (removed != nullptr) {

			link = removed->link;
		}
		return removed;
	}
};

class LinkedList {
	Node head;
public:
	LinkedList():head(0) {}

	Node* getHead() {
		return head.getLink();
	}
	void insert(int pos, Node* node){
		//일단함수를중간에 삽입하려면 선행노드에 대한 정보를 알아 내야함 삽입하려는 위치의 선행 노드를 알아내기 위하여 선행노드값을 저장할 임시 노드를 선업함
		
		Node* prev = getEntry(pos - 1);// 선행노드
		prev->insertLink(node);
	}
	Node* remove(int pos){
		Node* prev = getEntry(pos - 1);
		return prev->removeLink();// 이건 왜 반환 해야하는걸까 쓸모없는 반환인거 같은데

	}
	// pos위치의 노드를 알아 내는 함수
	Node* getEntry(int pos){

		Node* h = &head; // 유의 할 것 h는 head.link의 값이 들어 있는게 아니라 head의 주소값이 들어있는 거임 따라서 pos값으로 -1이 입력되었을 떄 for문이 실행되지 않으므로 head의 주솟값이 리턴 됨
		for (int i = 0; i <= pos; i++)
		{
			if (h == nullptr) {
				break;
			}
			h = h->getLink();
		}
		return h;
	}
	bool isEmpty(){
		return head.getLink() == nullptr;
	}
	Node* find(int item){
		for(Node * p = head.getLink(); p != nullptr; p=p->getLink()){
			if (p->hasData(item)) {
				return p;
			}
		}
		return nullptr;
	}
	void replace(int pos, Node* node){
		Node* prev = getEntry(pos - 1);
		if (prev != nullptr) {
			delete prev->removeLink();
			prev->insertLink(node);
		}
	}
	int size(){
		int cnt = 0;
		for (Node* p = head.getLink(); p != nullptr; p = p->getLink()) {
			cnt++;
		}
		return cnt;
	}
	void display(){
		for (Node* p = head.getLink(); p != nullptr; p = p->getLink()) {
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
	//list.clear();
	list.display();
}