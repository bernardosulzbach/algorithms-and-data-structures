import random
import statistics

# Random sampling.

# Gathers a random sample of k elements from an iterator.
def random_sample(iterator, k):
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


if __name__ == '__main__':
    # All should be around 0.5
    for n in range(100):
        data = [(i + 1) / 1000 for i in range(1000)]
        assert 0.4 < statistics.mean(random_sample(data, 100)) < 0.6
        data = [random.random() for i in range(1000)]
        assert 0.4 < statistics.mean(random_sample(data, 100)) < 0.6
