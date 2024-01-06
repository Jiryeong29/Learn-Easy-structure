# Learn-Easy-structure
「C++로 쉽게 풀어쓴 자료구조」를 읽고 공부하는 리파지토리
| 목차 | 진행여부 | 요약 |
| --- | --- | --- |
| ch01 자료구조와 알고리즘 | O |  |
| ch02 배열 | O |  |
| ch03 스택 | △ | 구현, 괄호검사, 수식계산, 미로탐색문제와 stl 흑흑 시간이 없는 관계로 수식계산 중간까지만하고 넘어간다.... |
| ch04 큐 | X | 구현, 덱, 은행시뮬레이션, 미로탐색프로그램 |
| ch05 포인터와 연결리스트 | △ |  포인터, 동적메모리할당, 연결리스트, 연결리스트로 구현한 스택과 큐 |
| ch06 리스트 |  | 배열로 구현한 리스트, 연결리스트로 구현된 리스트, 다양한 형태의 연결리스트, 라인편집기 |
| ch07 순환 |  | 순환, 거듭제곱값계산, 피보자치수열계산, 하노이탑문제, 다중 순환 |
| ch08 트리 |  | 개념, 이진트리 구현, 순회, 연산, 응용, 스레드 이진트리 |
| ch09 이진탐색트리 |  |  |
| ch10 우선순위큐 |  | 구현, 힙, 힙정렬, 허프만코드 |
| ch11 그래프 |  | 그래프 탐색,연결성분, 신장트리, 위상정렬 |
| ch12 가중치 그래프 |  | 최소비용신장트리, 최단경로 |
| ch13 정렬 |  |  |
| ch14 탐색 |  |  |


- 자료구조란 무엇인가요?
    
    자료구조란 문제 해결에 필요한 데이터를 표현하고 저장하는 방식입니다. 자료구조는 다음과 같이 분류되어 있습니다.
    
    ![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/0104449c-0dac-4ae2-8999-739ab3004a7e/5e374247-3254-4107-83b9-ca397edc4d0a/Untitled.png)
    
- 알고리즘이란 무엇인가요?
    
    문제를 해결하는 절차를 뜻합니다.
    
    문제를 해결하는 절차를 뜻하기 때문에 프로그래밍 스타일이나 프로그래밍 언어와 무관하며 표현 방식으로는
    1. 영어나 한국어와 같은 자연어 
    2. 흐름도 
    3. 유사코드
    4. 특정한 프로그래밍 언어 
    등이 있습니다.
    
- 자료구조와 알고리즘의 차이는 무엇인가요?
    
    알고리즘은 프로그래밍 스타일이나 프로그래밍 언어와 무관하게 문제를 해결하는 절차이며 자료구조는 문제 해결에 필요한 데이터를 처리하고 저장하는 방식입니다.
    
    문제를 빠르고 정확하게 해결하기 위해서 보다 적합한 자료구조를 이용해 데이터를 효율적으로 처리해야하는 것이 중요합니다.  따라서 알고리즘과 자료구조는 밀접한 관계이며, 프로그램은 알고리즘과 자료구조로 구성 되어있다고 할 수 있습니다.
    
- 추상화란 무엇인가요?
    
    복잡한 자료, 모듈, 시스템 등으로부터 핵심적인 개념이나 기능을 간추려 내는 것을 말합니다. 즉, 시스템의 정말 핵심적인 구조나 동작에만 집중하는 것입니다. 좋은 추상화는 사용자에게 중요한 정보는 강조되는 반면 중요하지 않은 구현 세부 사항은 제거되는 것을 말합니다.
    
    이를 위하여 정보은닉기법이 사용되며 정보은닉기법은 추상자료형의 개념으로 발전되었습니다.
    
- 추상자료형(ADT: Abstract Data Type)이란 무엇인가요?
    
    추상자료형은 추상화한 자료형, 즉 추상적으로 정의한 자료형을 의미합니다. 쉽게 설명하면 기능의 구현 부분을 나타내지 않고 기능이 무엇이 있는지만 나열한 것이라고 할 수 있습니다. 예를 들어
    
    다항식프로그램의 추상 자료형을 정의해본다면 다음과 같습니다.
    
    ```cpp
    ADT of Polynomial
    Data
    - degree : int// 다항식의 최고 차수
    - coef : float[]// 각 항에 대한 계수
    
    Operation
    +void read();	// 다항식을 입력받는다.
    +void display(const char *str);	// 다항식을 화면에 출력한다.
    +bool isZero(); // 최고 차수가 0인지를 검사하여 0이면true를 반환
    +void negate(); // 모든 계수의 부호를 바꾼다.
    +void add(Polynomial p1, Polynomial p2);  // 다항식 p1과 p2를 더한다
    +void mult(Polynomial p1, Polynomial p2); // 다항식 p1과 p2를 곱한다.
    ```
    
    이런식으로 추상자료형을 표현할 때는 먼저 데이터를 정의하고 다음으로 연산들을 정의합니다. 데이터는 주로 집합의 개념을 사용하여 표현하고 연산의 정의에는 연산의 이름, 매개변수, 연산의 결과, 연산이 수행하는 기능들을 기술합니다. 
    
    > 추상자료형은 객체지향 언어의 개념과 일치합니다.
    > 
    > 
    > c++에서는 클래스를 사용하여 추상자료형을 구현합니다. 
    > 추상자료형에서의 `데이터` 는  클래스의 속성(멘버변수)로 구현되고 `연산` 은 클래스의 메소드(멤버함수)로 구현됩니다. 
    > private나 protected키워드를 사용하여 속성과 연산에 대한 접근을 제한하며 클래스는 계층 구조로 구성될 수 있습니다.
    > 
    
- 프로그램의 실행시간을 측정하는 코드
    
    ```cpp
    #include <cstdio>	// c 헤더파일 <stdio.h>을 포함하는 것과 동일
    #include <cstdlib> // c 헤더파일 <stdlib.h> 을 포함하는 것과 동일
    #include <ctime> // c헤더파일 <time.h>을 포함하는 것과 동일
    
    void main(void) {
    	clock_t start, finish;
    	double duration;
    
    	start = clock();
    	// 실행시간을 측정하고자 하는 코드
    	// 화면 출력문은 제외시켜야 함에 유의할 것
    	finish = clock();
    	duration = (double)(finish - start) / CLOCKS_PER_SEC;
    	printf("%f 초입니다.\n", duration);
    }
    ```
    

#### 이 책에서 사용하는 C++문법 분류
| 사용하는 문법 | 사용하지 않는 문법 |
| --- | --- |
| 클래스 | 연산자 오버로딩 |
| 멤버변수, 멤버함수 | 깊은 복사 |
| 생성자와 소멸자 | 복사 생성자 |
| 멤버 초기화 리스트 | 대입 연산자 오버로딩 |
| 함수 오버로딩 | 다중 상속 |
| 디폴트 매개변수 | 동적 바인딩 |
| 레퍼런스형 | 입출력 객체(cin, cout) |
| 클래스 상속 | 예외처리 |
| this 포인터 | 텝플릿 |

# ch 02 배열과 클래스
> **학습목표**
> 
> - 배열의 개념을 이해한다.
> - 함수호출에서의 배열의 전달 방법을 이해한다.
> - 클래스 개념을 이해한다.
> - 자주 사용되는 C++의 문법을 이해한다.
> - 배열을 사용한 클래스를 구현하는 능력을 배양한다.

### 문자열

자료형이 `char` 인 `str`라는 배열에 `game \0over`  문자열이 들어가면 `str` 을 출력하였을 때 `game over` 이 출력되는 것이 아니라 `game` 이 출력된다. 이는 문자열 끝을 나타내는 `\0` 이 문자열이 `over` 앞에 들어갔기 때문이다. 따라서 문자열 NULL 문자 이후의 내용은 문자열에 아무런 영향을 미치지 않는다.

> 문자열을 위해서 표준라이브러리에서 여러가지 함수들이 제공된다. 문자열을 비교하는 strcmp()와 문자열 복사를 위한strcpy()정도만 찾아서 공부해보아라.
> 

- 배열이란 무엇인가요?
    
    여러개의 동일한 자료형의 데이터를 연속된 공간에 저장하는 자료구조입니다.
    
- 배열의 특징은 무엇이 있나요
    - <인덱스, 요소> 쌍의 집합으로 구성되어있습니다.
    - 인덱스를 사용하여 **직접 접근**이 가능합니다.(순차접근 :  연결리스트)
    - 배열의 이름은 **포인터 역할**을 합니다. 배열의 이름을 매개변수로 전달하면 배열의 첫 번째 항목의 주소가 전달됩니다.
    - 삽입연산을 많이 수행하는 경우라면, 배열이나 벡터보다는 연결리스트를 사용하는 것이 좋습니다.
- 벡터란 무엇인가요?
    
    벡터는 c++의 표준 템플릿 라이브러리에서 배열에 여러가지 기능을 추가한 자료형입니다. 기존의 배열에서 불편했던 점들을 개선시켜 일반화 시킨것으로 특징은 다음과 같습니다.
    
    - 배열과 마찬가지로 인덱스로 항목을 접근할 수 있으며 인덱스의 범위는 0부터 원소의개수-1까지입니다.
    - 벡터는 일반 배열보다 자신에 관한 정보를 더 많이 가지고 있습니다. 특히 벡터의 크기나 잠정적으로 가질 수 있는 원소의 개수에 관한 정보를 얻을 수 있습니다.
    - 벡터의 크기는 동적으로 변할 수 있으며 새로운 원소를 벡터의 끝이나 중간에 삽입할 수 있습니다. 메모리 관리도 효율적이고 자동적으로 이루어집니다.
    - 그러나 삽입할 때에는 벡터도 배열처럼 효율적이지 않으므로 삽입연산을 많이 수행하는 경우 벡터보다는 연결리스트를 사용하는 것이 좋습니다.
- 벡터 vs 배열 [회고록]
    
    책에서도 벡터가 배열의 상위버전인것처럼 설명하는데 그럼에도 불구하고 배열을 사용하는 이유가 궁금해졌다.
    
    벡터가 무조건 좋으니 벡터만 사용하면 되는게 아닌가? 프로그램을 작성할때 배열보다 벡터를 다루는것이 익숙하여 항상 벡터를 사용해 왔었는데 두 가지 차이점을 확실히 구분하고 필요에 맞게 사용하면 좋을거 같다고 생각하였다. 잘 설명되어있는 몇 가지 글을 가져와 보았다.
    
    [](http://www.infopub.co.kr/info/ebook/pdf/8054-531.PDF)
    
    [[C/C++] 배열과 벡터 속도차이 비교 테스트](https://powerofsummary.tistory.com/47)
    
    [vector와 array의 처리 성능 높이는 방법 (실험)](https://remocon33.tistory.com/600)
    
    [Array 와 Vector의 속도차이](https://nicekon.tistory.com/113)
    
- 구조체란?
    
    배열이 같은 자료형 데이터의 모임이라면 구조체는 다양한 자료형을 데이터를 묶어주는 방법입니다.
    
- 클래스란?
    
    객체를 정의하는 특 또는 설계도를 말하며 멤버변수와 멤버함수로 구성되어있습니다.
    
- 멤버지정접근자란?
    - public 이란?
        
        어떤 클래스나 함수에서도 이 멤버에 접근할 수 있습니다.
        
    - private란?
        
        현재클래스의 멤버함수에만 접근이 가능합니다.
        
    - protected란?
        
        현재클래스와 이 클래스의 자식 클래스의 멤버함수에만 접근이 가능합니다.
        
- 생성된 객체의 멤버에 접근하는 방법은 무엇인가요?
    
    객체명 바로 뒤에 항목연산자 `.` 를 첨가하고 멤버이름을 적습니다.
    
- 생성자란?
    
    객체가 생성될 때 멤버변수에게 초깃값을 제공하고 필요한 초기화 절차를 실행하기 위한 특별한 멤버함수입니다.
    
- 소멸자란?
    
    객체가 파괴 될 때 뒷마무리를 담당하는 함수입니다.
    
- 멤버포기화 리스트란?
    
    데이터멤버를 초기화하는 방법으로 일반함수와 같이 생성자 함수 몸체에서 초기화를 하는 방법과 구분됩니다.
    
    - ex) 예시코드
        
        ```cpp
        car(int s, int g)
        	: speed(s), gear(g){
        
        }
        ```
        
    
- 함수의 오버로딩이란?
    
    함수 이름의 중복을 허용하는 것입니다. 클래스 , 멤버함수, 일반함수에서 모두 사용가능하고 매개변수가 다른 여러개의 함수를 동일한 이름으로 만들 수 있습니다.
    
- 디폴트 매개변수란?
    
    함수의 매개변수에 디폴트 값을 부여하는 것으로 이 함수를 호출하였을 때 인수를 넣으면 그 값이 매개변수로 복사되고 인수가 없으면 디폴트 값이 그 매개변수에 복사됩니다.
    
    - 예시 코드
        
        ```cpp
        void changeCar(int g =4);
        
        myCar.changeCar(2); // g에 2가 복사됨
        myCar.changeCar();  // g에 디폴트값인 4가 복사됨
        ```
        

> cin이나 cout을 사용하려는 이유는 입출력을 할 자료형을 신경 쓰지 않아 편리하다는 점이 있다. 그러나 프로그래밍에서 가장 중요한 것이 자료형이며 항상 자신이 처리하는 데이터의 자료형을 명확히 생각해야 한다. 따라서 printf()나 scanf()를 사용하여 익숙해지는 연습을 먼저 하는 것을 추천한다. 이 두 함수만 잘 활용하면 입출력외에도 파일입출력 fprintf(), fscanf()나 문자열 입출력 sprintf(), sscanf()등을 같은 방식으로 매우 편리하게 할 수 있다. 입출력객체를 잘 이해하고 c++프로그래밍에 익숙하다면 자신에게 편리한 방법을 사용하면 된다.
> 
- this 포인터란
    
    클래스 멤버함수에서 객체 자신의 주소가 필요한 경우 this를 사용합니다. this는 현재 객체의 메모리상의 주소를 반환합니다.
    
- 클래스 상속이란?
    
    기존 클래스의 필드와 메소드를 재사용하도록 부모클래스를 상속하여 자식 클래스를 만드는것
    
- 클래스를 상속하는 이유는 무엇인가요?
    1. 이미 검증된 소프트웨어를 재사용할 수 있으므로 신뢰성이 확보됩니다.
    2. 코드의 중복을 줄여주어 유지보수를 쉽게합니다.
- 오버라이딩이란?
    
    자식클래스에서 부모클래스의 멤버함수를 다시 재정의하는 것을 말합니다.
    
- 클래스의 객체를 배열로 생성할 수 있습니까?
    
    네, 생성할 수 있습니다.
    
- 레퍼런스란 무엇입니까?
    
    메모리 공간에 별명을 붙이는 것으로 대부분 함수의 매개변수에서 레퍼런스 형을 주로 사용합니다.
