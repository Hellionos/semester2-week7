#include <stdio.h>
#include <stdlib.h>

long long factorial(int n)
{
    if (n<2){
        return n;
    }
    return n * factorial(n - 1);
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ./factorial <value>\n");
        return 1;
    }

    int value = atoi(argv[1]);
    if (value > 20){
        printf("The number is too high for this program\n");
        return 1;
    }

    long long result = factorial(value);

    printf("%d! = %lld\n", value, result);

    return 0;
}
