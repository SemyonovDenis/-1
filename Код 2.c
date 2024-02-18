//Дабы избежать двойных факториалов, разложим их по формулам(2n-1)!!=(2n)!/(2^n)(n!) и (2n)!!=(2^n)(n!)
#include <stdio.h>

double power(double base, int exponent) {
    double powerResult = 1.0;
    for (int i = 0; i < exponent; i++) {
        powerResult *= base;
    }
    return powerResult;
}

unsigned long long factorial(int n) {
    unsigned long long factorialResult = 1;
    for (int i = 1; i <= n; i++) {
        factorialResult *= i;
    }
    return factorialResult;
}

double natural(double x, int terms) {
    double result = x;
    for (int n = 1; n < terms; n++) {
        result += power(-1, n) * (factorial(2*n) * power(x, 2*n+1)) / (factorial(n) * factorial(n) * power(4, n) * (2*n + 1));
    }
    return result;
}
//Эта модификация данной в варианте формуле полностью ей эквивалентна

int main() {
    double x;
    int terms;
    printf("x будет равен: ");
    scanf("%lf", &x);
    if (x < -1.0 || x > 1.0) {
        printf("x должен принимать значения только в отрезке [-1, 1]! \nНаша команда специально обученных счёту на абаке блох испытывает некоторые затруднения с введённым Вами значением.\n");
        return 1;
    }
    printf("Используемое количество членов (от этого зависит точность): ");
    scanf("%d", &terms);
    double result = natural(x, terms);
    printf("ln(%.3f+√(1+%.3f²)) = %.9f\n", x, x, result);
    return 0;
}
