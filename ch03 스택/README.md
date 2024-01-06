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

	int pop() {
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
    - c++코드에서 대괄호 `[]`, 중괄호 `{}` , 소괄호 `()`등이 사용되는데, 일반적인 괄호의 검사 조건은 다음 3가지로 나눌 수 있다.
        - 조건 1 : 왼쪽 괄호의 개수와 오른쪽 괄호의 개수가 같아야 한다.
        - 조건 2 : 같은 타입의 괄호에서 왼쪽 괄호는 오른쪽 괄호보다 먼저 나와야 한다.
        - 조건 3 : 서로 다른 타입의 왼쪽 괄호와 오른쪽 괄호 쌍은 서로를 교차하면 안된다.
    - 괄호가 일치하지 않으면 잘못된 소스코드이기 때문에 컴파일러가 이것을 검사해야 한다. 이러한 괄호 사용의 오류를 검사하는데도 스택이 사용된다.
- 괄호 검사 알고리즘
    - 괄호를 차례대로 조사하면서 왼쪽 괄호를 만나면 스택에 삽입하고 오른쪽 괄호를 만나면 스택에서 맨 위의 괄호를 꺼낸 후 오른쪽 괄호와 짝이 맞는지를 검사합니다. 이때 스택이 비어있으면 `조건 1`이나 `조건 2`를 위배하게 되고 괄호의 짝이 맞지 않으면 `조건3` 에 위배됩니다. 마지막 괄호까지를 조사한 후에도 스택에 괄호가 남아있으면 `조건1`에 위배됩니다. 하나의 조건이라도 위배하면 오류이므로 `false`를 반환하고 그렇지 않으면 성공이므로 `true`를 반환합니다.
    - 유사 코드
        
        ```cpp
        checkMatching(expr)
        while(입력 expr의 끝이 아니면) do
        	ch <- expr의 다음글자;
        	switch(ch)
        		case '(' : case '[': case'{':
        			ch를 스택에 삽입
        			break;
        		case ')': case ']': case ']':
        			if( 스택이 비어 있으면)
        				then 오류;
        				else 스택에서 open_ch를 꺼냄
        					if (ch 와 open_ch가 같은 짝이 아니면)
        						then 오류 보고;
        			break;
        if( 스택이 비어 있지 않으면 ) 
        	then 오류보고;
        ```
        
    - c++을 이용하여 구현해보기!
    괄호 검사에서는 스택에 문자를 저장해야한다. ArrayStack을 이용하기. 이때 스택 요소들의 자료형을 char로 변경해도 되고  char형들은 필요시 int형으로 변환될 수 있으므로 코드를 그대로 상용해도 무방하다. 괄호 검사 알고리즘은 일반함수로 구현해도 되고 괄호 검사를 위한 클래스를 만들어 멤버함수로 구현해도 된다. 여기서는 일반 함수 checkMatching()으로 구현한다. checkMatching()은 파일 이름을 매개변수로 받아 이 파일을 읽어 괄호 검사를 하도록 구현하고, 테스트에는 구현한 소스파일을 사용하자.
        
        ```cpp
        #include <cstdio>
        #include <cstdlib>
        #define _CRT_SECURE_NO_WARNINGS 
        
        const int MAX_STACK_SIZE = 20; // 스택 최대 크기 설정
        
        inline void error(const char* message) {
        	printf("%s\n", message);
        	exit(1);
        }
        
        class arrayStack {
        
        	int top = -1; // 요소의 개수
        	char data[MAX_STACK_SIZE];
        
        public:
        	arrayStack() { top = -1; }
        	//~arrayStack();
        
        	bool isEmpty() { return top == -1; } // 스택이 비어있으면 true를 아니면 false를 반환한다.
        	bool isFull() { return top == MAX_STACK_SIZE - 1; }// 스택이 가득 차 있으면 true를 아니면 false를 반환한다.
        
        	void push(char e) {
        		if (isFull()) {
        			error("스택 포화 에러");
        		}
        		data[++top] = e;
        	}
        
        	char pop() {
        		if (isEmpty()) error("스택 공백 에러");
        		return data[top--];
        	}
        	char peek() {
        		if (isEmpty()) error("스택 공백 에러");
        		return data[top];
        	}
        
        	int size() {
        		if (isEmpty())  error("스택 공백 에러");
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
        
        bool checkMaching(const char* filename) {
        	FILE* fp;
        	fopen_s(&fp, filename, "r");
        	if (fp == NULL) {
        		error("Error: 파일이 존재하지 않습니다.");
        	}
        	int nLine = 1;
        	int nChar = 0;
        	arrayStack stack;
        	char ch;
        	while ((ch = getc(fp)) != EOF) {
        		printf("%c", ch);
        		if (ch == '\n') {
        			nLine++;
        		}
        		nChar++;
        		if (ch == '[' || ch == '(' || ch == '{')
        			stack.push(ch);
        		else if (ch == ']' || ch == ')' || ch == '}') {
        			int prev = stack.pop();
        			// 닫히는 괄호이면 스택에서 하나를 꺼내 비교한다. 
        			// 만일 맞지 않은 괄호이면 매칭 실패이므로 반복문을 빠져나간다.
        			if ((ch == ']' && prev != '[')
        				|| (ch == ')' && prev != '(')
        				|| (ch == '}' && prev != '{')) 
        				break;
        		}
        	}
        	fclose(fp); // 파일을 닫는다.
        	printf("[%s] 파일 검사결과 : \n", filename);
        	if (!stack.isEmpty())
        		printf("Error: 문제발견 ! (라인수 =%d, 문자수 = %d)\n\n", nLine, nChar);
        	else printf("OK : 괄호닫기 정상(라인수 =%d, 문자수  = %d)\n\n", nLine, nChar);
        	return stack.isEmpty();
        }
        
        int main() {
        	checkMaching("ArrayStack.h");
        }
        ```
        

## 스택의 응용 : 수식의 계산

### 수식의 계산과 스택

수식은 연산자와 피연산자를 이용해 나타낸다. 연산자의 위치에 따라 다음과 같이 나눌 수 있다.

- 전위(prefix)표기법 : 연산자를 피연산자 앞에 표기한다.
ex] +AB, +5*AB
- 중위(infix)표기법 : 연산자를 피연산자 사이에 표기한다.
ex] A+B, 5+A*B
- 후위(postfix)표기법 : 연산자를 피연산자 뒤에 표기한다.
ex] AB+, 5AB*+

보통 중위표기법에 익숙하나 컴파일러는 주로 후위 표기법을 사용한다.

### 컴파일러에서 후위표기법을 주로 사용하는 이유

```cpp
 		중위 표기 수식  : (A+B)*2
⇒  후위 표기 수식  :   AB+*2
```

- 괄호를 사용하지 않고도 계산해야 할 순서를 알 수 있다.
- 연산자의 우선순위를 생각할 필요가 없다. 식 자체에 우선순위가 이미 포함되어 있기 때문이다.
- 수식을 읽으면서 바로 계산할 수 있다. 중위표현식은 괄호와 연산자의 우선순위 때문에 수식을 끝까지 읽은 다음에야 계산이 가능하다.

**⇒ 컴파일러는 이러한 장점때문에 프로그램 개발자가 입력한 중위표기 수식을 후위표기수식으로 바꾸고 변환한 후위 표기수식을 계산하는 방법을 사용한다.** 

### 후위 표기 수식의 계산

중위표기수식을 후위표기법으로 변환하였다 가정하고 후위 표기식을 어떻게 계산할 수 있는지 알아보자

후위 표기 수식의 계산에 스택이 사용된다. 계산을 위해 전체 수식을 **왼쪽에서 오른쪽으로 스캔**하는데 스캔과정에서 **피연산자가 나오면 무조건 스택에 저장**한다.

**연산자가 나오면** **스택에서 피연산자 두 개를 꺼내 연산을 실행**하고 **그 결과를 다시 스택에 저장**한다. 이 과정은 수식이 모두 처리 될 때가지 **반복**되고 **마지막으로 스택에는 최종 계산 결과만** 하나 남는다.

```cpp
8 2 / 3 - 3 2 * + 를 계산해보자
```

### 후위 표기 수식 계산 PseudoCode

```cpp
calcPostfixExpr(expr)

스택 객체 s를 생성하고 초기화한다.
for 항목 in expr
	do if ( 항목이 피연산자이면 )
		s.push(item);
	if ( 항목이 연산자 op )이면
		then second <- s.pop();
			first <- s.pop();
			temp <- first op second;
			s.push(temp);
result <- s.pop();
```

### 후위 표기 수식 계산 코드

```cpp
#include <cstdio>
#include <cstdlib>

const int MAX_STACK_SIZE = 20; // 스택 최대 크기 설정

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1);
}

class OperandStack {
	double data[MAX_STACK_SIZE];
	int top;
public:
	OperandStack() { top = -1; }
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == MAX_STACK_SIZE - 1;
	}
	void push(double e) {
		if (isFull()) {
			error("스택 포화 에러");
		}
		data[++top] =e;
	}
	double pop() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top--];
	}
};

int calcPostfixExpr(FILE * fp = stdin) {

	OperandStack st;
	char ch;
	int temp;
	while ((ch = getc(fp)) != '\n') // '\n' 입력 전까지
	{

		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
		{
			double val2 = st.pop();
			double val1 = st.pop();
			switch (ch) 
			{
			case'+': st.push(val1 + val2); break;
			case '-': st.push(val1 - val2); break;
			case '*': st.push(val1 * val2); break;
			case '/': st.push(val1 / val2); break;
			}
		}
		else if (ch >= '0' && ch <= '9') // 피연산자(숫자)의 시작이면
		{
			ungetc(ch, fp); // 문자를 입력버퍼에 돌려주고
			double val;
			fscanf_s(fp, "%lf", &val); //더블로 다시 읽음
			st.push(val); // 읽은 값을 저장
		}
		
	}
	return (st.pop());
}

int main() {
	printf("수식 입력 (Postfix) = ");
	double res = calcPostfixExpr();
	printf("계산 결과 => %f", res);
}
```

처음에 입력값을 공백 없이 `82/3-32*+` 이런식으로 이력해주었더니 스택 공백에러가 떴다. 알고보니 후위 표기식을 입력할 때, 숫자와 연산자 사이에 공백이 필요하다고 한다.  `8 2 +` 같이 입력해야 하고 공백없이 `82/` 와 같이 입력할 경우 프로그램은 `34` 를 하나의 숫자로 인식하고 `+` 연산자에 대한 피연산자가 부족하다고 판단한다.

### 중위 표기 수식의 후위 표기 변환 알고리즘

컴퓨터는 후위표기 소식을 주로 사용하지만 인간은 중위 표기식에 익숙하므로 계산기를 구현하기 위해 사람이 기술하는 중위 표기식을 컴퓨터가 계산할 수 있는 후위 표기식으로 변환한는 과정이 필요하다

연산자의 출력순서는 연산자들의 우선순위 관계와 괄호에 의해 결정된다.