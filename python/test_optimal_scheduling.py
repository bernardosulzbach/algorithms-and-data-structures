from unittest import TestCase
import interval_scheduling_maximization


class TestOptimalScheduling(TestCase):
    def test_optimal_scheduling_should_work_with_empty_iterables(self):
        self.assertEqual(interval_scheduling_maximization.optimal_scheduling([]), [])

    def test_optimal_scheduling_should_work_with_single_tasks(self):
        self.assertEqual(interval_scheduling_maximization.optimal_scheduling([(2, 3)]), [(2, 3)])

    def test_optimal_scheduling_should_work_with_two_tasks_in_the_correct_order(self):
        self.assertEqual(interval_scheduling_maximization.optimal_scheduling([(2, 3), (3, 4)]), [(2, 3), (3, 4)])

    def test_optimal_scheduling_should_work_with_two_tasks_that_overlap(self):
        self.assertEqual(interval_scheduling_maximization.optimal_scheduling([(2, 4), (3, 5)]), [(2, 4)])
