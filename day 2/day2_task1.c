#include <stdio.h> 

  

int main() { 

    int mosha = 17; 

    char iniciali = 'B'; 

    float gjatesia = 1.95; 

    double mesatarja = 4.6; 

    short vlera1 = 10; 

    long vlera2 = 100000; 

  

   

    printf("Shkruaj moshen: "); 

    scanf("%d", &mosha); 

  

    printf("Shkruaj inicialin: "); 

    scanf(" %c", &iniciali); 

  

    printf("1.75: "); 

    scanf("%f", &gjatesia); 

  

    printf("Shkruaj mesataren: "); 

    scanf("%lf", &mesatarja); 

  

    

    printf("\n -PROFILI Im-\n"); 

    printf("Mosha: %d\n", mosha); 

    printf("Iniciali: %c\n", iniciali); 

    printf("Gjatesia: %.2f\n", gjatesia); 

    printf("Mesatarja: %.2lf\n", mesatarja); 

    printf("Vlera short: %d\n", vlera1); 

    printf("Vlera long: %ld\n", vlera2); 

  

    return 0; 
}
