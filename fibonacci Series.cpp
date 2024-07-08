#include <stdio.h>

int main() {
    int n, i;
    long long t1 = 0, t2 = 1, nextTerm;

    // Prompt the user to enter the number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Display the first two terms
    printf("Fibonacci Series: %lld, %lld", t1, t2);

    // Generate the Fibonacci series
    for (i = 3; i <= n; ++i) {
        nextTerm = t1 + t2;
        printf(", %lld", nextTerm);
        t1 = t2;
        t2 = nextTerm;
    }

    printf("\n");
    return 0;
}

