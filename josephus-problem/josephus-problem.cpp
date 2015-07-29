// Step = 2
// People count = k
// First guy is at 1.
int josephus(int k) {
    if (k == 1) return 1;
    // If we have a pair number of dudes (1, 2, ..., 2n) after the first iteration we get
    // (1, 3, ..., 2n - 1). So just solve for (1, 2, ..., n) and do 2 * Solution - 1.
    if ((k & 1) == 0) return 2 * josephus(k / 2) - 1;
    // If we have an odd number of dudes (1, 2, ..., 2n + 1) after the first iteration we get
    // (3, 5, ..., 2n + 1). So just solve for (1, 2, ..., n) and do 2 * Solution + 1.
    else return 2 * josephus(k / 2) + 1;
}