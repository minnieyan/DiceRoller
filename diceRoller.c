#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int diceArray[] = {4, 6, 8, 10, 12, 20, 100}; //This array holds the types of dice that can be rolled.
    int diceCount[] = {0, 0, 0, 0, 0, 0, 0}; //This array will holds the amount of times each type of dice is going to be rolled as requested by the user.
    int i, finalSum = 0, diceSum = 0; //diceSum holds the sum of all dice rolls of a certain type. finalSum holds the final total of all dice rolled.

    for (i = 0; i < 7; i++) { //Requests amount of times each type of dice will be rolled. Stores in diceCount.
        printf("Amount of d%d rolls: ", diceArray[i]);
        scanf("%d", &diceCount[i]);
    }

    for (i = 0; i < 7; i++) { //Rolls the dice and prints the value. Keeps rolling until the dice roll count for that type is exhausted. Rolls the next type.
        for (;diceCount[i] > 0; diceCount[i] = diceCount[i] - 1) {
            int randValue = rand() % diceArray[i] + 1;
            printf("d%d Roll: %d\n", diceArray[i], randValue);
            diceSum = diceSum + randValue; //Calculates the diceSum on a rolling basis.
        }
        if (diceSum != 0) {
            printf("Sum of d%d Rolls: %d\n", diceArray[i], diceSum); //Prints the sum of all dice rolled for the given dice type.
        }
        finalSum = finalSum + diceSum; //Calculates the finalSum on a rolling basis.
        diceSum = 0; //Resets the value of diceSum before rolling the next dice type.
    }

    printf("Final Sum: %d\n", finalSum); //Prints the final sum fo all dice rolls.

    return 0;
}