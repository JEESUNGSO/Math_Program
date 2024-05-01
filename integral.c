#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
// ���� ���� ���� ������� �ڿ����, �α�, ����, ��Ʈ ���� ����ϰ� ����
#include <math.h>

// ���ϴ� f(x)�� ����
double f(double x) {
	return 3 * x * x + exp(x); 
}


int main(void) {
	int sep = 0; // ������ ���� ����
	double x1, x2; // ���� ����
	double result_l = 0, result_r = 0; // ���� ��

	// �Է� �ޱ�
	printf("���� ������ �Է��ϼ���(x1 x2): ");
	scanf("%lf %lf", &x1, &x2);
	printf("\n���� ������ ���� ����: ");
	scanf("%d", &sep);
	
	double dx = (x2 - x1) / sep; // ���� ������� ���� ��


	// 0 ~ (n-1)
	for (int i = 0; i < sep; i++) {
		result_l += f(x1 + dx * i) * dx;
	}

	// 1 ~ n
	for (int i = 1; i <= sep; i++) {
		result_r += f(x1 + dx * i) * dx;
	}
	

	// ���
	printf("\n\nf(x) �ٻ����� ���(%.2f ~ %.2f ����):\n\t���� ������� ���� ������:\t%10.2f\n\t���� ������� ������ ������:\t%10.2f", x1, x2, result_l, result_r);

	return 0; // ���� ����
}