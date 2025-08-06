#include <stdio.h>
#include <ctype.h>

int main() {
    char names[5][11];
    int scores[5][13];
    double averages[5];

    // Läs in namn och poäng
    for (int i = 0; i < 5; i++) {
        scanf("%10s", names[i]);
        for (int j = 0; j < 13; j++) {
            scanf("%d", &scores[i][j]);
        }
        names[i][0] = toupper(names[i][0]);  // Gör första bokstaven versal
    }

    // Räkna ut snitt för varje elev
    double total = 0.0;
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 13; j++) {
            sum += scores[i][j];
        }
        averages[i] = sum / 13.0;
        total += averages[i];
    }

    // Gruppsnitt
    double group_average = total / 5.0;

    // Skriv ut endast de elever som ligger under gruppsnittet
    for (int i = 0; i < 5; i++) {
        if (averages[i] < group_average) {
            printf("%s\n", names[i]);
        }
    }

    return 0;
}
