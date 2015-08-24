from shash import shash, shash_roll


def find(text, substr):
    """
    Attempts to find a substring in a string of text.
    :param text: the string of text
    :param substr: the substring
    :return: the index of the first character of the first appearance of the substring in the string or -1
    """
    text_size = len(text)
    substr_size = len(substr)
    if text_size < substr_size:
        return -1
    last_hash = shash(text[0:substr_size])
    substr_hash = shash(substr)
    if substr_hash == last_hash:
        if text[0:substr_size] == substr:
            return 0
    for i in range(1, text_size - substr_size + 1):
        last_hash = shash_roll(last_hash, substr_size, text[i - 1], text[substr_size + i - 1])
        if substr_hash == last_hash:
            if text[i:substr_size + i] == substr:
                return i
    return -1


def count(text, substr):
    counter = 0
    while True:
        index = find(text, substr)
        if index != -1:
            counter += 1
            if index + 1 < len(text):
                text = text[index + 1:]
            else:
                break
        else:
            break
    return counter
