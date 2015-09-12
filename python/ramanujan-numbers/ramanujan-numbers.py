def find_ramanujan_up_to(n):
    """
    Returns a dictionary of all the numbers that can be written in at least two
    different ways as the sum of two cubes a^3 + b^3 == c^3 + d^3 such that a,
    b, c, d < n.
    """
    # Make a list of cubes of all values of i in the range [1, n - 1].
    # O(n) time.
    cubes = [i ** 3 for i in range(1, n)]
    sums = {}
    # Add the different cubes together and record these sums.
    # O(n^2) time.
    for i in range(len(cubes)):
        for j in range(i + 1, len(cubes)):
            total = cubes[i] + cubes[j]
            value = sums.get(total, [])
            value.append((i + 1, j + 1))
            sums.update({total: value})
    ramanujan = {}
    # Find all sums that happened two or more times.
    # O(n^2) time.
    for key, value in sums.items():
        if len(value) >= 2:
            ramanujan.update({key: value})
    return ramanujan


def pretty_string_from_ramanujan_dict(dictionary):
    strings = []
    for number, values in sorted(dictionary.items()):
        strings.append(str(number))
        for value in values:
            strings.append(' = ')
            strings.append(str(value[0]))
            strings.append('^3 + ')
            strings.append(str(value[1]))
            strings.append('^3')
        strings.append('\n')
    return ''.join(strings)

if __name__ == '__main__':
    print(pretty_string_from_ramanujan_dict(find_ramanujan_up_to(100)))
