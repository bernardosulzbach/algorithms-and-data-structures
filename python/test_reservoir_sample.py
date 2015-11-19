from unittest import TestCase
import reservoir_sampling


class TestReservoirSample(TestCase):
    def test_reservoir_sample_should_work_with_empty_iterables(self):
        self.assertListEqual(reservoir_sampling.reservoir_sample([], 1), [])

    def test_reservoir_sample_should_get_all_elements_from_iterable_if_it_is_too_small(self):
        small_iterable = [1, 2, 3]
        self.assertListEqual(reservoir_sampling.reservoir_sample(small_iterable, 4), small_iterable)

    def test_reservoir_sample_should_get_some_elements_from_iterable_if_it_is_not_too_small(self):
        iterable = range(1, 10)
        for value in reservoir_sampling.reservoir_sample(iterable, 5):
            self.assertIn(value, iterable)
