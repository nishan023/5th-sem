
#include <stdio.h>
#include <math.h>
int main()
{
    int q, alpha, Xa, Ya, Xb, Yb, k1, k2;
    printf("\t****NISHAN DHAKAL****\n      ****Diffie-Hellman****\n\n");
    printf("Enter prime number q: ");
    scanf("%d", &q);
    printf("Enter primitive root alpha: ");
    scanf("%d", &alpha);
    printf("\nAlice\n");
    printf("Enter Alice's private key Xa: ");
    scanf("%d", &Xa);

    printf("Xa: %d\n", Xa);
    printf("Ya: alpha^Xa mod q\n");
    printf("Ya:%d^%d mod %d  ", alpha, Xa, q);
    Ya = (int)pow(alpha, Xa) % q;
    printf("\nAlice's public key Ya: %d\n", Ya);

    printf("\nBob\n");
    printf("Enter Bob's private key Xb: ");
    scanf("%d", &Xb);
    Yb = (int)pow(alpha, Xb) % q;
    printf("Yb: alpha^Xb mod q\n");
    printf("Yb:%d^%d mod %d  ", alpha, Xb, q);
    printf("Xb: %d\n", Xb);
    printf("Bob's public key Yb: %d\n", Yb);

    k1 = (int)pow(Yb, Xa) % q;
    k2 = (int)pow(Ya, Xb) % q;

    printf("\nAlice's secret key k1: %d\n", k1);
    printf("Bob's secret key k2: %d\n", k2);

    if (k1 == k2)
        printf("Keys match! Secret key is: %d\n", k1);
    else
        printf("Keys do not match!\n");

    return 0;
}

/*

q is prime and alpha is a primitive root mod q
Alice
Xa=...
Ya=alpha^Xa mod q

secret key
k=Yb^Xa mod q


Bob
Xb=...
Yb=alpha^Yb mod q

secret key
k=Ya^Xb mod q


both k should be same



*/