#include <stdio.h>
#include <stdlib.h>

int check_prime(int i, int num) {
    if (i * i > num) {
        return 0;
    }
    if (num % i == 0) {
        return 1;
    }
    return check_prime(i + 1, num);
}

int main() {
    int num;
    FILE *file;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fscanf(file, "%d", &num);
    fclose(file);

    if (check_prime(2, num) == 0) {
        printf("Its a prime number.\n");
    } else {
        printf("Not a prime number.\n");
    }

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    if (check_prime(2, num) == 0) {
        fprintf(file, "Its a prime number.\n");
    } else {
        fprintf(file, "Not a prime number.\n");
    }

    fclose(file);

    return 0;
}
