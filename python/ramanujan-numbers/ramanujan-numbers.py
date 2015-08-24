import collections


def find_ramanujan_up_to(n):
    """
    Returns a list of all the numbers that can be written in two different ways
    as the sum of two cubes a^3 + b^3 == c^3 + d^3 such that a, b, c, d < n.
    """
    # Make a list of cubes of all values of i in the range [1, n - 1].
    # This runs in O(n) time.
    cubes = [i ** 3 for i in range(1, n)]
    counter = collections.Counter()
    # Add the different cubes together and store the frequency of these sums.
    # O(n^2) time.
    for i in range(len(cubes)):
        for j in range(i + 1, len(cubes)):
            counter[cubes[i] + cubes[j]] += 1
    ramanujan = []
    # Find all sums that happened two or more times.
    # There are O(n^2) values in counter, so this is also O(n^2).
    for number in counter:
        if counter[number] >= 2:
            ramanujan.append(number)
    return ramanujan


if __name__ == '__main__':
    for number in sorted(find_ramanujan_up_to(50)):
        print(number)
