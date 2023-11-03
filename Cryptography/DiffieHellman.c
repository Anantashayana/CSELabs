#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(long long int n) {
    if (n <= 1)
        return 0;

    for (long long int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

long long int powerModulo(long long int base, long long int exponent, long long int modulus) {
    long long int result = 1;
    for (long long int i = 0; i < exponent; i++) {
        result = (result * base) % modulus;
    }
    //printf("%d",result);
    return result;
}

void main() {
    long long int p;
    printf("Enter a prime number: ");
    scanf("%lld", &p);

    if (!isPrime(p)) {
        printf("Invalid input. Please enter a prime number.\n");
        return;
    }

    printf("Prime number is %lld\n", p);

    long long int k = 2, k1, k2;
    long long int c = 0;
    long long int ar[p - 1];
    
    while (c == 0) {
        for (long long int i = 0; i < p - 1; i++)
            ar[i] = powerModulo(k, i + 1, p);

        c = 1;
        for (long long int i = 0; i < p - 2; i++) {
            if (ar[i] == 0) {
                c = 0;
                break;
            }
        }

        if (c == 0)
            k++;
    }

    printf("Prime number and primitive root are %lld %lld\n", p, k);

    printf("Enter public key 1: ");
    scanf("%lld", &k1);
    printf("Enter public key 2: ");
    scanf("%lld", &k2);

    long long int a = powerModulo(k, k1, p);
    long long int b = powerModulo(k, k2, p);

    printf("Private keys are %lld %lld\n", a, b);

    long long int A = powerModulo(b, k1, p);
    long long int B = powerModulo(a, k2, p);

    printf("Shared values are %lld %lld\n", A, B);
}
