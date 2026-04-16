#include <stdio.h>

int main() {

    // Detyra 1
    printf("=== Detyra 1 ===\n");
    int age = 16;
    char gradeChar = 'A';
    float height = 1.75;
    double weight = 68.5;
    short year = 2026;
    long population = 1800000;

    printf("Age: %d\n", age);
    printf("Grade: %c\n", gradeChar);
    printf("Height: %f\n", height);
    printf("Weight: %f\n", weight);
    printf("Year: %d\n", year);
    printf("Population: %ld\n\n", population);


    // Detyra 2
    printf("=== Detyra 2 ===\n");
    int number;
    printf("Shkruaj nje numer te plote: ");
    scanf("%d", &number);
    printf("Numri qe shkrove eshte: %d\n\n", number);


    // Detyra 3
    printf("=== Detyra 3 ===\n");
    char letter;
    printf("Shkruaj nje karakter: ");
    scanf(" %c", &letter);
    printf("Karakteri qe shkrove eshte: %c\n\n", letter);


    // Detyra 4
    printf("=== Detyra 4 ===\n");
    float num1;
    double num2;
    printf("Shkruaj nje numer float: ");
    scanf("%f", &num1);
    printf("Shkruaj nje numer double: ");
    scanf("%lf", &num2);
    printf("Numri float eshte: %f\n", num1);
    printf("Numri double eshte: %f\n\n", num2);


    // Detyra 5
    printf("=== Detyra 5 ===\n");
    int number2;
    printf("Shkruaj nje numer: ");
    scanf("%d", &number2);

    if (number2 > 0) {
        printf("Numri eshte pozitiv.\n\n");
    } else if (number2 < 0) {
        printf("Numri eshte negativ.\n\n");
    } else {
        printf("Numri eshte zero.\n\n");
    }


    // Detyra 6
    printf("=== Detyra 6 ===\n");
    int points;
    printf("Shkruaj piket e nxenesit: ");
    scanf("%d", &points);

    if (points >= 50) {
        printf("Nxenesi ka kaluar.\n\n");
    } else {
        printf("Nxenesi nuk ka kaluar.\n\n");
    }


    // Detyra 7
    printf("=== Detyra 7 ===\n");
    int a, b;
    printf("Shkruaj numrin e pare: ");
    scanf("%d", &a);
    printf("Shkruaj numrin e dyte: ");
    scanf("%d", &b);

    if (a > b) {
        printf("Numri me i madh eshte: %d\n\n", a);
    } else if (b > a) {
        printf("Numri me i madh eshte: %d\n\n", b);
    } else {
        printf("Te dy numrat jane te barabarte.\n\n");
    }


    // Detyra 8
    printf("=== Detyra 8 ===\n");
    int day;
    printf("Shkruaj nje numer nga 1 deri ne 7: ");
    scanf("%d", &day);

    switch (day) {
        case 1:
            printf("E Hene\n\n");
            break;
        case 2:
            printf("E Marte\n\n");
            break;
        case 3:
            printf("E Merkure\n\n");
            break;
        case 4:
            printf("E Enjte\n\n");
            break;
        case 5:
            printf("E Premte\n\n");
            break;
        case 6:
            printf("E Shtune\n\n");
            break;
        case 7:
            printf("E Diele\n\n");
            break;
        default:
            printf("Numer i pavlefshem.\n\n");
    }


    // Detyra 9
    printf("=== Detyra 9 ===\n");
    int numA, numB;
    char op;

    printf("Shkruaj numrin e pare: ");
    scanf("%d", &numA);

    printf("Shkruaj operatorin (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Shkruaj numrin e dyte: ");
    scanf("%d", &numB);

    switch (op) {
        case '+':
            printf("Rezultati: %d\n\n", numA + numB);
            break;
        case '-':
            printf("Rezultati: %d\n\n", numA - numB);
            break;
        case '*':
            printf("Rezultati: %d\n\n", numA * numB);
            break;
        case '/':
            if (numB != 0) {
                printf("Rezultati: %d\n\n", numA / numB);
            } else {
                printf("Pjestimi me zero nuk lejohet.\n\n");
            }
            break;
        default:
            printf("Operator i pavlefshem.\n\n");
    }


    // Detyra 10
    printf("=== Detyra 10 ===\n");
    int grade;
    printf("Shkruaj noten: ");
    scanf("%d", &grade);

    if (grade >= 1 && grade <= 5) {
        printf("Nota eshte e vlefshme.\n");
    } else {
        printf("Nota nuk eshte e vlefshme.\n");
    }

    return 0;
}
#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;
    short vitiShkollor;
    long numriTelefonit;

    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin e emrit: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj gjatesine: ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    printf("Shkruaj vitin shkollor: ");
    scanf("%hd", &vitiShkollor);

    printf("Shkruaj numrin e telefonit: ");
    scanf("%ld", &numriTelefonit);

    printf("\n===== PROFILI I PERDORUESIT =====\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Viti shkollor: %hd\n", vitiShkollor);
    printf("Numri i telefonit: %ld\n", numriTelefonit);

    return 0;
}

