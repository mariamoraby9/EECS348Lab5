/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

void findCombinations(int score, int td, int fg, int safety) {
    if (score == 0) {
        printf("%d TD + %dpt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td, 2, fg, td, fg / 3, safety);
        return;
    }

    if (score >= 6) {
        findCombinations(score - 6, td + 1, fg, safety);
    }
    if (score >= 3) {
        findCombinations(score - 3, td, fg + 3, safety);
    }
    if (score >= 2) {
        findCombinations(score - 2, td, fg, safety + 1);
    }
}

int main() {
    int score;
    
    printf("Enter 0 or 1 to STOP\n");
    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        if (score <= 1)
            break;

        printf("possible combinations of scoring plays:\n");
        findCombinations(score, 0, 0, 0);
    }
    
    return 0;
}
