import random


def reservoir_sample(iterator, k):
    """
    Gathers a random sample of k elements or less from an iterator.
    :param iterator: an iterator that provides the elements
    :param k: the maximum amount of elements that should be sampled
    :return: a list with k elements if iterator has at least k elements; otherwise, all the elements of iterator
    """
    sample = []
    elements_so_far = 0
    for item in iterator:
        elements_so_far += 1
        if len(sample) < k:
            sample.append(item)
        else:
            index = int(random.random() * elements_so_far)
            if index < k:
                sample[index] = item
    return sample
