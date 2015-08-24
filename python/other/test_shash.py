from unittest import TestCase
from shash import shash
from statistics import mean, pstdev


class TestShash(TestCase):
    def test_shash(self):
        # How many buckets we will use.
        bucket_count = 100
        # The test fails if the population standard deviation of the buckets is bigger than the product of the tolerance
        # and the mean of the buckets.
        tolerance = 0.05
        buckets = [0 for n in range(bucket_count)]
        # Load a lot of words.
        with open('../words.txt', 'r') as words:
            for line in words.readlines():
                buckets[shash(line) % bucket_count] += 1
        self.failIf(pstdev(buckets) > tolerance * mean(buckets))