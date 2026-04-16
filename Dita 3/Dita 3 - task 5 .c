#include <stdio.h>

enum Niveli {
    FILLESTAR = 1,
    MESATAR = 2,
    MIRE = 3,
    SHKELQYER = 4
};

int main() {
    int i;
    int zgjedhja;
    int valide = 0;
    int pavlefshme = 0;
    enum Niveli niveli;

    printf("Program me enum - Niveli i nxenesit\n");
    printf("1 = Fillestar\n");
    printf("2 = Mesatar\n");
    printf("3 = Mire\n");
    printf("4 = Shkelqyer\n\n");

    for (i = 1; i <= 3; i++) {
        printf("Shkruaj zgjedhjen per rastin %d: ", i);
        scanf("%d", &zgjedhja);

        if (zgjedhja >= 1 && zgjedhja <= 4) {
            niveli = (enum Niveli)zgjedhja;
            valide++;

            switch (niveli) {
                case FILLESTAR:
                    printf("Mesazh: Nxenesi eshte ne nivel fillestar dhe ka nevoje per me shume ushtrime.\n\n");
                    break;

                case MESATAR:
                    printf("Mesazh: Nxenesi eshte ne nivel mesatar dhe po perparon mire.\n\n");
                    break;

                case MIRE:
                    printf("Mesazh: Nxenesi eshte ne nivel te mire dhe mund te marre ushtrime me sfiduese.\n\n");
                    break;

                case SHKELQYER:
                    printf("Mesazh: Nxenesi eshte ne nivel shkelqyer dhe eshte gati per sfida me te medha.\n\n");
                    break;

                default:
                    printf("Gabim i papritur.\n\n");
            }
        } else {
            pavlefshme++;
            printf("Mesazh: Zgjedhje e pavlefshme. Ju lutem shkruani nje numer nga 1 deri ne 4.\n\n");
        }
    }

    printf("----- STATISTIKAT FINALE -----\n");
    printf("Zgjedhje valide: %d\n", valide);
    printf("Zgjedhje te pavlefshme: %d\n", pavlefshme);

    return 0;
}