/*Author: Dev Patel
 *ID: 3040746
 *Date:3040746
 *Program Description: This will sort each possibilty vcmbination of getting a specific output of a football score
 */


#include <stdio.h>

#define plays_max 10

void plays_out(int plays[], int n_plays) {
    printf("%d TD + %d FG + %d 3pt FG + %d Safety\n", plays[0], plays[1], plays[2], plays[3]);
}

void combos_pos(int score, int plays[], int n_plays) {
    if (score == 0) {
        plays_out(plays, n_plays);
        return;
    }
    if (score < 0) {
        return;
    }
    int i;
    for (i = 0; i < 4; i++) {
        plays[i]++;
        combos_pos(score - (i == 0 ? 6 : (i == 1 ? 3 : (i == 2 ? 1 : 2))), plays, n_plays + 1);
        plays[i]--;
    }
}

int main() {
    int score;
    int plays[plays_max] = {0};
    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }
        printf("possible combinations of scoring plays:\n");
        combos_pos(score, plays, 0);
    }
    return 0;
}
