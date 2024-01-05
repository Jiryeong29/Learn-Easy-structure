# ch03 스택

> **학습목표
1.** 스택의 ****개념과 추상자료형을 이해한다.  
**2.** 스택의 동작의 원리를 이해한다.  
**3.** 배열을 이용한 스택의 구현 방법을 이해한다.  
**4.** 추상자료형을 C++클래스로 구현할 수 있는 능력을 배양한다.  
**5.** 괄호 검사, 수식의 계산 및 미로 탐색 등에 스택을 활용하여 문제를 해결할 수 있는 능력을 배양한다.  
**6.** STL의 스택을 사용할 수 있는 능력을 배양한다.
> 

- **스택에 대해서 설명해주세요**
    
    스택은 Last-in-first-out(후입선출)의 형태로 된 자료구조입니다.
    
    가장 먼저 입력된 데이터가 stack bottom(스택 하단)에 쌓이고 가장 최근에 입력된 데이터가  stack top(스택상단)에 쌓이는 구조를 가지고 있습니다.
    
- **스택의 ADT**
    
    ```cpp
    **데이터
    
    - 후입선출의 접근 방법을 유지하는 요소들의 모음
    
    연산
    
    - push(x) : 주어진 요소 x를 스택의 맨 위에 추가한다.
    - pop() : 스택이 비어있지 않으면 맨 위에 있는 요소를 삭제하고 반환한다.
    - isEmpty() : 스택이 비어있으면 true를 아니면 false를 반환한다.
    - peek() : 스택이 비어있지 않으면 맨 위에 있는 요소를 삭제하지 않고 반환한다.
    - isFull() : 스택이 가득 차 있으면 true를 아니면 false를 반환한다.
    - size() : 스택 내의 모든 요소들을 개수를 반환한다.
    - display() : 스택 내의 모든 요소들을 출력한다.**
    ```
    
- **스택은 어디에서 주로 쓰이나요?**
    
    주로 자료의 출력순서가 입력순서의 역순으로 이루어져야 할 때 사용 됩니다.
    
    - **되돌리기 기능** 
    수행된 멍령어들 중 가장 최근에 수행된 것부터 순서적으로 취소해하기 때문입니다.
    - **함수호출에서 복귀 주소를 기억**
    프로그램에서 함수가 호출될 때마다 스택에 현재 수행중인 문장의 주소와 그 함수에서 사용되고 있는 변수들의 값들이 스택에 저장됩니다. 하나의 함수가 끝나면 스택에서 가장 최근의 복귀 주소를 구해서 그곳으로 돌아갑니다. 이때 사용되는 스택은 운영체제가 사용하는 시스템 스택으로 사용자는 접근할 수 없습니다. 이 시스템에는 함수가 호출될 때마다 활성화 레코드가 만들어지며 여기에 현재 수해오디는 명령어 주소인 프로그램 카운터값이 기록됩니다. 이 값이 복귀 주소가 되고 활성화 레코드에는 함수 호출 시 파라미터와 함수 안에서 선언된 지역 변수들도 함께 저장됩니다.
        
        ![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/0104449c-0dac-4ae2-8999-739ab3004a7e/f319e680-3c54-4489-a267-476a1bfac32a/Untitled.png)
        
    - **소스코드나 문서에서 괄호닫기가 정상적으로 되었는지를 검사하는 프로그램**
    - **계산기 프로그램에서 입력된 수식을 계산하는 과정**
    - **미로에서 출구를 찾기**
    
- **스택 구현 방법**
    - **배열을 이용** 
    가장 간단함지만 배열의 특성에 따라 크기가 고정됨
    - **연결리스트를 이용**
    포인터를 이용, 복잡하지만 크기가 제한되지 않음
    

## 직접 구현해 본 코드

```cpp
#include <cstdio>
#define MAX_STACK_SIZE  80
class stack {

private:
	int data[MAX_STACK_SIZE];
	int data_size;
public:
	stack() {
		data_size = -1;
	}

	void push(int x); // 주어진 요소 x를 스택의 맨 위에 추가한다.
	void pop(); // 스택이 비어있지 않으면 맨 위에 있는 요소를 삭제하고 반환한다.
	bool isEmpty(); // 스택이 비어있으면 true를 아니면 false를 반환한다.
	int peek(); // 스택이 비어있지 않으면 맨 위에 있는 요소를 삭제하지 않고 반환한다.
	bool isFull(); // 스택이 가득 차 있으면 true를 아니면 false를 반환한다.
	int size();// 스택 내의 모든 요소들을 개수를 반환한다.
	void display(); // 스택 내의 모든 요소들을 출력한다.
};
void stack::push(int x) {
	++data_size;
	data[data_size] = x;
}

void stack::pop() {
	if (data_size <= -1) {
		return;
	}
	data[data_size] = NULL;
	data_size--;
}

bool stack::isEmpty() {
	if (data_size > -1)
	{
		printf("false\n");
		return false;
	}
	else {
		printf("true\n");
		return true;

	}
}
int stack::peek() {
	if (data_size > -1) {
		return data[data_size];
	}
}
bool stack::isFull() {
	if (data_size == MAX_STACK_SIZE - 1) {
		printf("true\n");
		return true;
	}
	else {
		printf("false\n");
		return false;
	}
}

int stack::size() {
	return data_size;
}
void stack::display() {
	printf("배열의 요소 출력 : ");
	for (int i = 0; i <=data_size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	
}

int main() {
	stack st;
	st.isEmpty();
	st.display();
	st.push(3);
	st.push(5);
	st.push(4);
	st.display();
	st.peek();
	st.pop();
	st.display();
	st.isEmpty();
}
```

## 교재 코드

```cpp
#include <cstdio>
#include <cstdlib>

const int MAX_STACK_SIZE = 20; // 스택 최대 크기 설정
inline void error(const char* message) {
	printf("%s\n", message);
	exit(1);
}

class arrayStack {

	int top; // 요소의 개수
	int data[MAX_STACK_SIZE];
public:
	arrayStack() { top = -1; }
	//~arrayStack();

	bool isEmpty() { return top == -1; } // 스택이 비어있으면 true를 아니면 false를 반환한다.
	bool isFull() { return top == MAX_STACK_SIZE - 1; }// 스택이 가득 차 있으면 true를 아니면 false를 반환한다.

	void push(int e) {
		if (isFull()) {
			error("스택 포화 에러");
		}
		data[++top] = e;
	}

	void pop() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top--];
	}
	int peek() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top];
	}

	int size() {
		if (isEmpty()); error("스택 공백 에러");
		return top;
	}

	void display() {
		printf("[스택 공백항목의 수 = %2d] ==> ", top + 1);
		for (int i = 0; i < top; i++) {
			printf("<%2d>", data[i]);
		}
		printf("\n");
	}
};

int main() {

	arrayStack stack;
	for (int i = 1; i < 10; i++) {
		stack.push(i);
	}
	stack.display();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.display();
}
```

- 오류 처리 함수. : 공백 상태에서 pop()이나 peek()연산을 하거나 포화상태에서 push()연산을 시도하면 정상적인 처리가 불가능하므로 오류상황이 됨 오류가 발생하면 오류 메시지를 출력하고 프로그램을 종요하는 것으로 간단히 처리함. 오래 상황이 발생해도 프로그램을 종료하고 싶지 않으면 그에 따른 처리를 해주어야 함. exit()함수를 사용하기 위해 <cstdlib>을 포함시킴.
- inline함수가 뭘까? 어떨 때 쓰일까?>?

### 복잡한 구조의 항목에 대한 스택의 구현

학생의 학번,이름, 학과 등의 정보를 저장하는 스택을 구현한다.

Stdudent클래스르 만들고 Student객체들을 관리하는 학생 스택을 만들어보자 

클래스 다이어그램은 다음과 같다.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/0104449c-0dac-4ae2-8999-739ab3004a7e/c053fe88-46a7-42f1-b2f4-e57e07aabda1/Untitled.png)

## 스택의 응용 : 괄호 검사

- 괄호 검사와 스택
    - c++코드에서 대괄호[], 중괄호 {} , 소괄호 ()등이 사용되는데, 일반적인 괄호의 검사 조건은 다음 3가지로 나눌 수 있다.
        - 조건 1 : 왼쪽 괄호의 개수와 오른쪽 괄호의 개수가 같아야 한다.
        - 조건 2 : 같은 타입의 괄호에서 왼쪽 괄호는 오른쪽 괄호보다 먼저 나와야 한다.
        - 조건 3 : 서로 다른 타입의 왼쪽 괄호와 오른쪽 괄호 쌍은 서로를 교차하면 안된다.
    - 괄호가 일치하지 않으면 잘못된 소스코드이기 때문에 컴파일러가 이것을 검사해야 한다. 이러한 괄호 사용의 오류를 검사하는데도 스택이 사용된다.