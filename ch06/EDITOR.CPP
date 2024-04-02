#include <iostream>

class Node {
	int data;
	Node* link;
public:
	Node(int val) : data(val), link(nullptr) {}
	Node* getLink() { return link; }
	void setLink(Node* l) { link = l; }
	void display() {
		printf("%d", data);
	}
	// 노드의 데이터 값이 val인지 확인
	bool hasData(int val) {
		return data == val;
	}
	//// 자신 다음 새로운 노드를 삽입
	//void insertNext(Node* newNode) {
	//	if (newNode != nullptr) {
	//		newNode->link = link;
	//		link = newNode;
	//	}
	//	
	//}
	//// 자신 다음 노드를 리스트에서 삭제
	//Node* removeNext(){}
};

class test {
	Node headNode;
public:
	test() : headNode(0) {}
	// pos 위치에 새로운 newNode을 삽입
	void insert(int pos, Node* newNode) {
		// pos위치에 새로운 newNode를 삽입하려면 pos-1의 node의 주소를 알아야 하겠쥐 getEntry로 불러와
		Node* beforeNode = getEnty(pos - 1);
		// 근데 pos 5에 삽입하려고 하는디 리스트는 2개까지 밖에 없으면 어떡하지? 
		// 1번 노드 뒤에 삽입하면 됨, 그래서 getEntry()함수 for문에서 tmpNode== nullptr일때 break종료하고 현재 노드 반환한는 거 ㅇㅇ
		

		
		 
	}
	Node remove(int pos) {

	}

	// pos위치에 있는 노드를 반환
	Node* getEnty(int pos)
	{
		// 순회를 해야할 거 같아
		// headNode부터 탐색을 해야겠지
		Node* tmpNode = &headNode; // headNode의 주소값을 가진 임시 노드를 만들자
		// headNode다음 첫번째 리스트는 0번부터 시작
		for (int i = -1; i < pos; i++, tmpNode = tmpNode->getLink()) {
			// 중간에 pos를 찾기도 전에 임시 노드가 null값이면 탐색을 종료해야해
			if (tmpNode == nullptr) {
				break;
			}
		}
		return tmpNode;
	}
	bool isEmpty() {
		return headNode.getLink() == nullptr;
	}
	Node* find(int item);
	void replace(int pos, Node* node);
	int size();
	void display();
};

int main() {

}