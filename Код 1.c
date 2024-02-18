#include <stdio.h>

void rearrangeDigits(int num) {
    int result = 0;

    int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0,
        count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;

    int isNegative = 0;
    if (num < 0) {
        isNegative = 1;
        num = -num; 
    }

    do {
        int digit = num % 10;

        if (digit == 0) count0++;
        else if (digit == 1) count1++;
        else if (digit == 2) count2++;
        else if (digit == 3) count3++;
        else if (digit == 4) count4++;
        else if (digit == 5) count5++;
        else if (digit == 6) count6++;
        else if (digit == 7) count7++;
        else if (digit == 8) count8++;
        else if (digit == 9) count9++;

        num /= 10;
    } while (num != 0);

    int i;
    if (isNegative) {
        for (i = 9; i >= 0; i--) {
            while (i == 0 && count0 > 0) { result = result * 10 + 0; count0--; }
            while (i == 1 && count1 > 0) { result = result * 10 + 1; count1--; }
            while (i == 2 && count2 > 0) { result = result * 10 + 2; count2--; }
            while (i == 3 && count3 > 0) { result = result * 10 + 3; count3--; }
            while (i == 4 && count4 > 0) { result = result * 10 + 4; count4--; }
            while (i == 5 && count5 > 0) { result = result * 10 + 5; count5--; }
            while (i == 6 && count6 > 0) { result = result * 10 + 6; count6--; }
            while (i == 7 && count7 > 0) { result = result * 10 + 7; count7--; }
            while (i == 8 && count8 > 0) { result = result * 10 + 8; count8--; }
            while (i == 9 && count9 > 0) { result = result * 10 + 9; count9--; }
        }
    } else {
        for (i = 0; i <= 9; i++) {
            while (i == 0 && count0 > 0) { result = result * 10 + 0; count0--; }
            while (i == 1 && count1 > 0) { result = result * 10 + 1; count1--; }
            while (i == 2 && count2 > 0) { result = result * 10 + 2; count2--; }
            while (i == 3 && count3 > 0) { result = result * 10 + 3; count3--; }
            while (i == 4 && count4 > 0) { result = result * 10 + 4; count4--; }
            while (i == 5 && count5 > 0) { result = result * 10 + 5; count5--; }
            while (i == 6 && count6 > 0) { result = result * 10 + 6; count6--; }
            while (i == 7 && count7 > 0) { result = result * 10 + 7; count7--; }
            while (i == 8 && count8 > 0) { result = result * 10 + 8; count8--; }
            while (i == 9 && count9 > 0) { result = result * 10 + 9; count9--; }
        }
    }

    if (isNegative)
        printf("Наименьшее: -%d\n", result);
    else
        printf("Наименьшее: %d\n", result);
}

int main() {
    int num;

    printf("Введите число: ");
    scanf("%d", &num);

    rearrangeDigits(num);

    return 0;
}
