def kmp_table(p):
    """
    Generates a partial match table (as a Python list) for a pattern.
    """
    table = [0] * (len(p) + 1)
    i = 2  # The position of table we are computing.
    c = 0  # The index of the next character of the current candidate.
    while i < len(p):
        if p[i - 1] == p[c]:
            c += 1
            table[i] = c
            i += 1
        elif c > 0:
            c = table[c]  # Fall back to the previous candidate.
        else:
            table[i] = 0
            i += 1
        return table


def knuth_morris_pratt(t, p):
    """
    Finds the pattern p in the text t.
    """
    table = kmp_table(p)  # Make the table.
    q = 0  # Where in the text we are.
    i = 0  # Where in the pattern we are.
    while q + i < len(t):
        if p[i] == t[q + i]:
            i += 1
            if i == len(p):
                yield q
                q += i - table[i - 1]
                i = table[i - 1]
        elif i > 0:
            q += i - table[i]
            i = table[i]
        else:  # i == 0
            q += 1


if __name__ == '__main__':
    text = 'brian! abra? abracadabra'
    patt = 'bra'
    print(patt, 'in', "'" + text + "'")
    for match in knuth_morris_pratt(text, patt):
        print(match)
