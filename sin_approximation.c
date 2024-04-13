#include <stdio.h>
 
 
float pow(float n, int r)
{
    float result = 1;
    for (int i = 1; i <= r; i++)
    {
        result *= n;
    }
 
    return result;
}
 
float get_c(int n)
{
    if (n == 0) return 0;
    float result = 1;
 
    for (int i = 1; i <= n; i++)
    {
        result /= i;
    }
    if (n % 4 == 3) result *= -1;
    return result;
}
 
float sin_0_approx(float value, int repeat)
{
    //sin을 0에서 근사
    float result = 0;
 
    for (int i = 0; i < repeat; i++)
    {
        result += get_c(i * 2 + 1) * pow(value, i * 2 + 1);
        printf("%d번\t%0.10f\n",i+1, result);
    }
 
    return result;
}
 
 
int main(void)
{
    
    float value;
    int repeat;
 
    printf("sinx 에서 x의 값: ");
    scanf("%f", &value);
 
    printf("n 개의 항에서 n의 값: ");
    scanf("%d", &repeat);
 
    printf("sin을 0에서 태일러 급수로 근사했을때 \nsin%f = %.15f\n\n(-nan(ind)는 n번째 항이 너무 작아 데이터 타입의 범위를 초과하여 발생하는 오류)\n\n", value, sin_0_approx(value, repeat));
    return 0;
}