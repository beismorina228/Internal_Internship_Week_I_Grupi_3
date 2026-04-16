#include <stdio.h>

int main() {
    int start, end;

    int count3 = 0, sum3 = 0;
    int count5 = 0, sum5 = 0;

    printf("Enter start: ");
    scanf("%d", &start);

    printf("Enter end: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid interval\n");
        return 0;
    }

    for (int i = start; i <= end; i++) {
        if (i % 3 == 0) {
            count3++;
            sum3 += i;
        }
        else if (i % 5 == 0 && i % 3 != 0) {
            count5++;
            sum5 += i;
        }
    }

    printf("Divisible by 3: count = %d, sum = %d\n", count3, sum3);
    printf("Divisible by 5 (not 3): count = %d, sum = %d\n", count5, sum5);

    if (sum3 > sum5) {
        printf("Sum of numbers divisible by 3 is greater\n");
    }
    else if (sum5 > sum3) {
        printf("Sum of numbers divisible by 5 is greater\n");
    }
    else {
        printf("Sums are equal\n");
    }

    return 0;
}