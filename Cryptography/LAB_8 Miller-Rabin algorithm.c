#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to perform modular exponentiation: (base^exp) % mod
long long mod_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1) // If exp is odd
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Miller-Rabin Test based on your provided algorithm
const char *millerRabinTest(long long n)
{
    if (n <= 3)
        return (n == 2 || n == 3) ? "probably prime" : "composite";

    long long k = 0, q = n - 1;

    // Step 1: Find k and q such that n-1 = 2^k * q (with q odd)
    while (q % 2 == 0)
    {
        q /= 2;
        k++;
    }

    // Step 2: Select random a such that 1 < a < n-1
    srand(time(NULL));
    long long a = 2 + rand() % (n - 3); // a ∈ [2, n-2]

    // Step 3: If a^q mod n == 1, return inconclusive
    if (mod_exp(a, q, n) == 1)
        return "inconclusive";

    // Step 4: Loop j from 0 to k-1
    for (int j = 0; j < k; j++)
    {
        // Step 5: If a^(2^j * q) mod n == n-1, return inconclusive
        if (mod_exp(a, (1LL << j) * q, n) == n - 1)
            return "inconclusive";
    }

    // Step 6: If none of the above, return composite
    return "composite";
}

// Main function
int main()
{
    int number;
    printf("\t****NISHAN DHAKAL****\n ****Miller Rabin Algorithm****\n\n");
    printf("Enter an integer to test for primality: ");
    scanf("%d", &number);

    const char *result = millerRabinTest(number);
    printf("Result: %s\n", result);

    return 0;
}
