#include <stdio.h>
int main()
{
    int N;
    int a=0, b=1;
    int c;
    int i;

    // Read upper limit from input.txt
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error: Unable to open input.txt for reading.\n");
        return 1;
    }
    fscanf(inputFile, "%d", &N);
    fclose(inputFile);

    // Write Fibonacci sequence to output.txt
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error: Unable to open output.txt for writing.\n");
        return 1;
    }

    fprintf(outputFile, "%d\n", a);
    fprintf(outputFile, "%d\n", b);

    for (i=1; i<N; i++)
    {
        c = a+b;
        fprintf(outputFile, "%d\n", c);
        a = b;
        b = c;
    }

    fclose(outputFile);

    return 0;
}
