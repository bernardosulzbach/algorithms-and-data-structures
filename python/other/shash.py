"""
Consider adding prime numbers to the hashing function.

Although there is no evidence whatsoever that using prime numbers increases bit entropy (or is there?), it seems that
this is a too widespread practice for an amateur such as myself not to follow.

There is no one-size-fits-all hashing methodology, what can be done is trial and error with extensive experimentation
and statistical analysis to find a good enough hashing algorithm.
"""
# A prime bigger than the alphabet (assumed to be composed of 256 characters).
alpha = 257


def shash(string):
    """
    Given a string of text, this function produces a nonnegative integer as a hash value.
    :param string: the string of text
    :return: a hash integer
    """
    global alpha
    # Each character lies between 0 and 255, inclusively.
    total = 0
    length = len(string)
    for i in range(length):
        total += ord(string[i]) * alpha ** (length - i - 1)
    return total


def shash_roll(h, size, old, new):
    """
    'Rolls' a hash forward.
    :param h: the old hash value
    :param size: the size of the string that generated the hash
    :param old: the old character (the first of the string that generated the hash)
    :param new: the new character (the last of the current string)
    :return: a new hash integer
    """
    global alpha
    h -= ord(old) * alpha ** (size - 1)
    h *= alpha
    h += ord(new)
    return h