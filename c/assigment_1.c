#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function validates if a given number is valid for its specified base
int correct_numbers(char *number, int base) {   
    for (int i = 0; number[i]!='\0'; i++) {
        if (number[i] !='\n'){
            // the character must be either '0' or '1'
            if (base == 2 && (number[i] != '0' && number[i] != '1')) {
                return 0;
            } 
            // the character must be between '0' and '7'
            else if (base == 8 && (number[i] < '0' || number[i] > '7')) {
                return 0;
            }
            // the character must be between '0' and '9'
            else if (base == 10 && (number[i] < '0' || number[i] > '9')) {
                return 0;
            } 
            // the character must be between '0' and '9' or 'A' and 'F'
            else if (base == 16 && ((number[i] < '0' || number[i] > '9') && (number[i] < 'A' || number[i] > 'F'))) {
                return 0;
            }
        }
    }
    // it returns 1 to indicate a valid number
    return 1;
}
// function converts a number from its base to decimal
long convert_to_decimal(char *number, int base) {
    // it uses the strtol function from the standard library <stdlib.h> and returns the decimal value of the number
    return strtol(number, NULL, base);
}

int main() {
    // it opens the input and output files for reading
    FILE *inputf = fopen("input.txt", "r");
    FILE *outputf = fopen("output.txt", "w");
    // it reads the amount of numbers
    int N;
    fscanf(inputf, "%d\n", &N);
    // it checks if the amount of numbers is valid
    if (N < 1 || N > 40) {
        fprintf(outputf, "Invalid inputs\n");
        return 0;
    }

    // it reads the numbers 
    char S[1000];
    fgets(S, sizeof(S), inputf);

    // it reads the numbers' bases
    int A[40];
    for (int i = 0; i < N; i++) {
        fscanf(inputf, "%d", &A[i]);
        // it checks if the base is valid (all bases must be 2, 8, 10 or 16))
        if (A[i] != 2 && A[i] != 8 && A[i] != 10 && A[i] != 16) {
            fprintf(outputf, "Invalid inputs\n");
            return 0;
        }
    }

    // an array to store space-separated numbers
    char divided_numbers[40][7]; 
    // splits the string S into individual numbers using strtok
    char *p = strtok(S, " ");
    int amount = 0;
    long sum = 0;
    while (p != NULL && amount < N) {
        // it copies the number to the array divided_numbers
        strncpy(divided_numbers[amount], p, 6);
        divided_numbers[amount][6] = '\0';
        p = strtok(NULL, " ");
        amount++;
    }

    // it checks if the amount of numbers is valid
    if (amount != N) {
        fprintf(outputf, "Invalid inputs\n");
        return 0;
    }

    for (int i = 0; i < N; i++) {
        // it checks if the number is valid for its specified base
        if (!correct_numbers(divided_numbers[i], A[i])) {
            fprintf(outputf, "Invalid inputs\n");
            return 0;
        }
        // it converts the number to decimal and adds it to the sum
        sum += convert_to_decimal(divided_numbers[i], A[i]);
        // it subtracts 10 if the index is even
        if (i % 2 == 0) {
            sum -= 10;
        } 
        // it adds 10 if the index is odd
        else {
            sum += 10;
        }
    }    
    // it prints the sum to the output file
    fprintf(outputf, "%ld\n", sum);
    return 0;
}