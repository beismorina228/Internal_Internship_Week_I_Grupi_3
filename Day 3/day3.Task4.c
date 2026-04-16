#include <stdio.h>

int main()
{
    int num;
    float decimal;

    int *pNum;
    float *pDecimal;

    int oldNum;

    printf("-Day 3 - Task 4-\n");

    printf("Enter an integer value: ");
    scanf("%d", &num);

    printf("Enter a decimal value: ");
    scanf("%f", &decimal);

    
    pNum = &num;
    pDecimal = &decimal;

    
    oldNum = *pNum;

    printf("\n-Before Change -\n");
    printf("Direct integer value: %d\n", num);
    printf("Integer address: %p\n", pNum);
    printf("Integer value through pointer: %d\n", *pNum);

    printf("Direct decimal value: %.2f\n", decimal);
    printf("Decimal address: %p\n", pDecimal);
    printf("Decimal value through pointer: %.2f\n", *pDecimal);

    
    *pNum = *pNum + 10;

    printf("\n--- After Change ---\n");
    printf("Updated integer value: %d\n", num);
    printf("Updated through pointer: %d\n", *pNum);

    
    printf("\n-Final Check -\n");

    if (*pNum > oldNum)
    {
        printf("The value has increased.\n");
    }
    else if (*pNum < oldNum)
    {
        printf("The value has decreased.\n");
    }
    else
    {
        printf("The value stayed the same.\n");
    }

    
    if (*pNum >= 0 && *pNum <= 100)
    {
        printf("The final value is within range 0 - 100.\n");
    }
    else
    {
        printf("The final value is outside range 0 - 100.\n");
    }

    return 0;
}