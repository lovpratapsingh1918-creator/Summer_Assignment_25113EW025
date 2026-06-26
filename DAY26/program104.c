#include <stdio.h>

int main() {
    int score = 0;
    char answer;

    printf("Welcome to the Quiz Application!\n");
    printf("Answer each question with a, b, c, or d.\n\n");

    printf("1) What is the capital of France?\n");
    printf("a) London\n");
    printf("b) Paris\n");
    printf("c) Rome\n");
    printf("d) Berlin\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'b' || answer == 'B') {
        score++;
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is b) Paris.\n");
    }

    printf("\n2) Which planet is known as the Red Planet?\n");
    printf("a) Venus\n");
    printf("b) Jupiter\n");
    printf("c) Mars\n");
    printf("d) Saturn\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'c' || answer == 'C') {
        score++;
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is c) Mars.\n");
    }

    printf("\n3) How many days are there in a leap year?\n");
    printf("a) 364\n");
    printf("b) 365\n");
    printf("c) 366\n");
    printf("d) 367\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'c' || answer == 'C') {
        score++;
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is c) 366.\n");
    }

    printf("\n4) What is 2 + 2?\n");
    printf("a) 3\n");
    printf("b) 4\n");
    printf("c) 5\n");
    printf("d) 6\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'b' || answer == 'B') {
        score++;
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is b) 4.\n");
    }

    printf("\n5) Which language is used to create this program?\n");
    printf("a) Java\n");
    printf("b) Python\n");
    printf("c) C\n");
    printf("d) Ruby\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'c' || answer == 'C') {
        score++;
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is c) C.\n");
    }

    printf("\nYour score: %d/5\n", score);
    if (score == 5) {
        printf("Excellent! You got all answers right.\n");
    } else if (score >= 3) {
        printf("Good job! You did well.\n");
    } else {
        printf("Keep practicing!\n");
    }

    return 0;
}
