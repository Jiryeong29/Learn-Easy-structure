#include <iostream>
#include <string>
const int  MAX_CHAR_PER_LINE = 1000;
class Line {
	char data[MAX_CHAR_PER_LINE];
public:
	Line(const char* line) { strcpy(data, line); }
	void printf(FILE* fp = stdout) { fprintf(fp, "%s", data); }
	bool hasData(char* str) { return strcmp(str, data) == 0; }
};

class Node : public Line{
	Node* link;
public:
	Node(const char* str = "") : Line(str), link(nullptr) {};
	Node* getLink(){ return link; }
	void setLink(Node* p) { link = p; }
	void insertNext(Node* p) {
		if (p != nullptr) {
			p->link = link;
			link = p;
		}
	}
	Node* removeNext() {
		Node* removed = link;
		if (removed != nullptr) {
			link = removed->link;
		}
		return removed;
	}
};

class LinkedList {
	Node org;
public:
	LinkedList(): org(""){}
	~LinkedList() { clear(); }
	void clear() { while (!isEmpty()) delete remove(0); }
	Node* getHead() { return org.getLink(); }
	bool isEmpty() { return getHead() == nullptr; }
	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink()) {
			if (n == nullptr) break;
		}
		return n;
	}
	
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != nullptr) {
			prev->insertNext(n);
		}
	}
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}
	Node* find(char* str) {
		for (Node* p = getHead(); p != nullptr; p = p->getLink())
			if (p->hasData(str))
				return p;
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
		int count = 0;
		for (Node* p = getHead(); p != nullptr; p = p->getLink())
			count++;
		return count;
	}
};

class LineEditor :public LinkedList
{
public:
	void Display(FILE* fp = stdout) {
		int i = 0;
		for (Node* p = getHead(); p != nullptr; p = p->getLink(), i++) {
			fprintf(stderr, "%3d: ", i);
			p->printf(fp);
		}
	}
	void InsertLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		printf(" 입력행 번호 :");
		scanf("%d", &position);
		printf(" 입력행 내용: ");
		fflush(stdin);
		fgets(line, MAX_CHAR_PER_LINE, stdin);
		insert(position, new Node(line));
		
	}
	void DeleteLine() {
		printf(" 삭제행 번호 : ");
		int position;
		scanf("%d", &position);
		delete remove(position);
	}
	void ReplaceLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		printf(" 변경행 번호 : ");
		scanf("%d", &position);
		printf(" 변경행 내용: ");
		fflush(stdin);
		fgets(line, MAX_CHAR_PER_LINE, stdin);
		
		replace(position, new Node(line));
	}
	void LoadFile(const char* fname) {
		FILE* fp = fopen(fname, "r");
		if (fp != nullptr) {
			char line[MAX_CHAR_PER_LINE];
			while (fgets(line, MAX_CHAR_PER_LINE, fp))
				insert(size(), new Node(line));
			fclose(fp);
		}
	}
	void StoreFile(const char* fname) {
		FILE* fp = fopen(fname, "w");
		if (fp != nullptr) {
			Display(fp);
			fclose(fp);
		}
	}
};

void Usage() {
	printf("[메뉴선택] 1-입력,d-삭제,r-변경,p-출력,1-파일읽기,s-저장, q-종료=> ");
}

void main()
{
	char command;
	LineEditor editor;
	do {
		Usage();
		command = getchar();
		switch (command) {
			case 'd': editor.DeleteLine();			break;
			case 'i': editor.InsertLine();			break;
			case 'r': editor.ReplaceLine();			break;
			case 'I': editor.LoadFile("Test.txt");	break;
			case 's': editor.StoreFile("Test.txt"); break;
			case 'p': editor.Display();
			case 'q': break;
		}
		fflush(stdin);
	} while (command != 'q');
} 