#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
// 수학 연산 관련 헤더파일 자연상수, 로그, 제곱, 루트 등을 사용하게 해줌
#include <math.h>

// 원하는 f(x)를 구현
double f(double x) {
	return 3 * x * x + exp(x); 
}


int main(void) {
	int sep = 0; // 구간을 나눌 개수
	double x1, x2; // 적분 구간
	double result_l = 0, result_r = 0; // 적분 값

	// 입력 받기
	printf("적분 구간을 입력하세요(x1 x2): ");
	scanf("%lf %lf", &x1, &x2);
	printf("\n적분 구간을 나눌 개수: ");
	scanf("%d", &sep);
	
	double dx = (x2 - x1) / sep; // 적분 막대기의 가로 폭


	// 0 ~ (n-1)
	for (int i = 0; i < sep; i++) {
		result_l += f(x1 + dx * i) * dx;
	}

	// 1 ~ n
	for (int i = 1; i <= sep; i++) {
		result_r += f(x1 + dx * i) * dx;
	}
	

	// 출력
	printf("\n\nf(x) 근사적분 결과(%.2f ~ %.2f 에서):\n\t적분 막대기의 왼쪽 값으로:\t%10.2f\n\t적분 막대기의 오른쪽 값으로:\t%10.2f", x1, x2, result_l, result_r);

	return 0; // 정상 종료
}