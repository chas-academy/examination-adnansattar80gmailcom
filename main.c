#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
        names[i][0] = toupper(names[i][0]);  // Första bokstaven versal
    }

    // Beräkna genomsnitt
    double total = 0.0;
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 13; j++) {
            sum += scores[i][j];
        }
        averages[i] = sum / 13.0;
        total += averages[i];
    }

    // Hitta högst snitt
    double highest = averages[0];
    int index_highest = 0;
    for (int i = 1; i < 5; i++) {
        if (averages[i] > highest) {
            highest = averages[i];
            index_highest = i;
        }
    }

    // Skriv ut namn med högst snitt först
    printf("%s\n", names[index_highest]);

    // Räkna ut gruppsnitt
    double group_avg = total / 5.0;

    // Skriv ut de som ligger under gruppsnittet (i inmatningsordning)
    for (int i = 0; i < 5; i++) {
        if (i != index_highest && averages[i] < group_avg) {
            printf("%s\n", names[i]);
        }
    }

    return 0;
}
