#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int gcd(int m, int n) {
    int temp;
    while (n != 0) {
        temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}

void main() {
    int p, q;
    printf("Enter two prime numbers: ");
    scanf("%d%d", &p, &q);

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        e++;
    }

    int d = 2;
    while (d < phi) {
        if ((e * d) % phi == 1)
            break;
        d++;
    }

    int m;
    printf("Enter the message: ");
    scanf("%d", &m);

    int enc = fmod(pow(m, e), n);
    int dec = fmod(pow(enc, d), n);

    printf("Encryption: %d\n", enc);
    printf("Decryption: %d\n", dec);
}
