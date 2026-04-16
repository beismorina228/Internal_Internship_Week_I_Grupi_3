#include <stdio.h>

int main() {
    int numriInt;
    double numriDouble;

    int paraInt, pasInt;
    double paraDouble, pasDouble;

    int *ptrInt;
    double *ptrDouble;

    printf("Shkruaj nje vlere int: ");
    scanf("%d", &numriInt);

    printf("Shkruaj nje vlere double: ");
    scanf("%lf", &numriDouble);

    // Ruajme vlerat para ndryshimit
    paraInt = numriInt;
    paraDouble = numriDouble;

    // Pointer-at marrin adresat e variablave
    ptrInt = &numriInt;
    ptrDouble = &numriDouble;

    printf("\n==============================\n");
    printf("VLERA DHE POINTER-AT FILLESTAR\n");
    printf("==============================\n");

    printf("Vlera direkte e numriInt: %d\n", numriInt);
    printf("Adresa e numriInt: %p\n", &numriInt);
    printf("Adresa e ruajtur ne ptrInt: %p\n", ptrInt);
    printf("Vlera e lexuar me *ptrInt: %d\n", *ptrInt);

    printf("\nVlera direkte e numriDouble: %.2lf\n", numriDouble);
    printf("Adresa e numriDouble: %p\n", &numriDouble);
    printf("Adresa e ruajtur ne ptrDouble: %p\n", ptrDouble);
    printf("Vlera e lexuar me *ptrDouble: %.2lf\n", *ptrDouble);

    // Ndryshimi i vlerave permes pointer-ave
    *ptrInt = *ptrInt + 10;
    *ptrDouble = *ptrDouble * 1.50;

    // Ruajme vlerat pas ndryshimit
    pasInt = numriInt;
    pasDouble = numriDouble;

    printf("\n==============================\n");
    printf("PAS NDRYSHIMIT PERMES POINTER-IT\n");
    printf("==============================\n");

    printf("numriInt para ndryshimit: %d\n", paraInt);
    printf("numriInt pas ndryshimit: %d\n", pasInt);

    printf("\nnumriDouble para ndryshimit: %.2lf\n", paraDouble);
    printf("numriDouble pas ndryshimit: %.2lf\n", pasDouble);

    printf("\n==============================\n");
    printf("ANALIZA ME IF / ELSE\n");
    printf("==============================\n");

    // Analiza per int
    if (pasInt > paraInt) {
        printf("numriInt eshte rritur.\n");
    } else if (pasInt < paraInt) {
        printf("numriInt eshte zvogeluar.\n");
    } else {
        printf("numriInt ka mbetur i njejte.\n");
    }

    if (pasInt >= 0 && pasInt <= 50) {
        printf("numriInt eshte brenda intervalit [0, 50].\n");
    } else {
        printf("numriInt nuk eshte brenda intervalit [0, 50].\n");
    }

    // Analiza per double
    if (pasDouble > paraDouble) {
        printf("numriDouble eshte rritur.\n");
    } else if (pasDouble < paraDouble) {
        printf("numriDouble eshte zvogeluar.\n");
    } else {
        printf("numriDouble ka mbetur i njejte.\n");
    }

    if (pasDouble >= 0.0 && pasDouble <= 100.0) {
        printf("numriDouble eshte brenda intervalit [0.00, 100.00].\n");
    } else {
        printf("numriDouble nuk eshte brenda intervalit [0.00, 100.00].\n");
    }

    return 0;
}