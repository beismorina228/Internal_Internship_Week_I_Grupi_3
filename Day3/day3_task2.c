#include <stdio.h>

int main() {
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;
    int totalValues = 0;

    printf("Enter start of interval: ");
    scanf("%d", &start);

    printf("Enter end of interval: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid interval.\n");
        return 0;
    }

    for (int i = start; i <= end; i++) {
        totalValues++;

        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    printf("\nInterval: [%d - %d]\n", start, end);
    printf("Total values: %d\n", totalValues);
    printf("Even numbers: %d\n", evenCount);
    printf("Odd numbers: %d\n", oddCount);
    printf("Sum of even numbers: %d\n", evenSum);
    printf("Sum of odd numbers: %d\n", oddSum);

    if (evenCount > oddCount) {
        printf("Category with more numbers: Even\n");
    } else if (oddCount > evenCount) {
        printf("Category with more numbers: Odd\n");
    } else {
        printf("Category with more numbers: Equal\n");
    }

    return 0;
}