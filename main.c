#include <stdio.h>
#include <ctype.h>

void calculate_averages(int scores[5][13], double averages[5]) {
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 13; j++) {
            sum += scores[i][j];
        }
        averages[i] = sum / 13.0;
        printf("Average score for student %d: %.2f\n", i + 1, averages[i]);
    }
}

void find_highest_average(double averages[5], char names[5][11]) {
    double highest = averages[0];
    int index = 0;
    for (int i = 1; i < 5; i++) {
        if (averages[i] > highest) {
            highest = averages[i];
            index = i;
        }
    }
    printf("Highest average score is %.2f for student %s\n", highest, names[index]);
}

void print_below_group_average(double averages[5], char names[5][11]) {
    // Step 2: Calculate group average
    double total = 0.0;
    for (int i = 0; i < 5; i++) {
        total += averages[i];
    }
    double group_average = total / 5.0;
    
    printf("\nAverage score below group average:\n");
    printf("Group average score: %.2f\n", group_average);
    
    for (int i = 0; i < 5; i++) {
        if (averages[i] < group_average) {
            printf("%s (%.2f)\n", names[i], averages[i]);
        }
    }
}

int main() {
    char names[5][11];       // 5 students, max 10 characters + null terminator
    int scores[5][13];       // 5 students, 13 test scores

    printf("Enter the name and 13 scores for each student (Name s1 s2 ... s13):\n");

    // Read names and scores
    for (int i = 0; i < 5; i++) {
        scanf("%10s", names[i]);
        for (int j = 0; j < 13; j++) {
            scanf("%d", &scores[i][j]);
        }
    }

    // Capitalize the first letter of each name
    for (int i = 0; i < 5; i++) {
        names[i][0] = toupper(names[i][0]);
    }
    for (int i = 0; i < 5; i++) {
        printf("%s\n", names[i]);
    }

    printf("\nAverage scores:\n");
    double averages[5];
    calculate_averages(scores, averages);

    find_highest_average(averages, names);

    // ➕ Step 2: Print students below group average
    print_below_group_average(averages, names);



    return 0;
}
