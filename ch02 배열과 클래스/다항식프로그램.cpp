//#include <iostream>
//#include <algorithm>
#include <cstdio>
#define MAX_DEGREE 80

class Polynomial {

private:
	int degree;	// 다항식의 최고 차수
	float coef[MAX_DEGREE]; // 각 항에 대한 계수

public:

	Polynomial() { degree = 0; }

	void read();	// 다항식을 입력받는다.
	void display(const char *str);	// 다항식을 화면에 출력한다.


	bool isZero(); // 최고 차수가 0인지를 검사하여 0이면true를 반환

	void negate(); // 모든 계수의 부호를 바꾼다.
	void add(Polynomial p1, Polynomial p2);  // 다항식 p1과 p2를 더한다
	void mult(Polynomial p1, Polynomial p2); // 다항식 p1과 p2를 곱한다.

};

void Polynomial::read() {
	printf("다항식의 최고차수를 입력하시오 :");
	scanf_s("%d", &degree);
	printf("각 항의 계수를 입력하시오 (총 : %d개) : ", degree + 1);
	for (int i = 0; i <= degree; i++) {
		scanf_s("%f", coef + i);
	}
}

void Polynomial::display(const char* str) {//디폴트 매개변수 사용
	printf("\t%s", str);
	for (int i = 0; i < degree; i++) {
		printf("%5.1f x ^%d+ ", coef[i], degree - i);
	}
	printf("%4.1f\n", coef[degree]);
}
bool Polynomial::isZero() {
	//if (coef[degree] == 0) {
	//	return true;
	//}
	return degree == 0;
}

void Polynomial::negate() {
	for (int i = 0; i < degree; i++) {
		//coef[i] *= -1;
		coef[i] = -coef[i];
	}
}

void Polynomial::add(Polynomial p1, Polynomial p2) {

	if (p1.degree > p2.degree) {

		*this = p1; // p1다항식을 자기 객체에 복사
		for (int i = 0; i <= p2.degree; i++) {
			coef[i + (degree - p2.degree)] += p2.coef[i]; // 배열을 입력받을 때 최고차항순으로 입력받으므로 (degree - p2.degree)를 해주어야 함
		}
	}
	else
	{
		*this = p2; // p2다항식을 자기 객체에 복사
		for (int i = 0; i <= p1.degree; i++) {
			coef[i + (degree - p1.degree)] += p1.coef[i]; // 배열을 입력받을 때 최고차항순으로 입력받으므로  (degree - p1.degree)를 해주어야 함
		}
	}
}
int main() {
	// 테스트
	Polynomial a, b, c;
	a.read();
	b.read();
	c.add(a, b);
	a.display("A = ");
	b.display("B = ");
	c.display("A+B=");
}