// Calculates the number of trailing zeros in a big factorial.
unsigned trailing_zeros_in_factorial_of(unsigned n) {
    // Logic
    // The number of trailing zeros depends on the frequency of the product 2 x 5.
    // There are more multiples of 2 than of 5, so we only count the multiples of 5.
    // Therefore, just add one for each time 5 appears in the factorization of n.
    // Add one for each factor that is a multiple of 5.
    // Add one for each factor that is a multiple of 25.
    // Add one for each factor that is a multiple of 125.
    // And so on.
    unsigned fives = 0;
    while (n /= 5) {
        fives += n;
    }
    return fives;
}