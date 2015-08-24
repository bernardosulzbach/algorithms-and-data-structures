from unittest import TestCase

from rabin_karp import find, count


class TestRabinKarp(TestCase):
    def test_find(self):
        string = "Abracadabra"
        self.assertTrue(find(string, 'A') == 0)
        self.assertTrue(find(string, 'b') == 1)
        self.assertTrue(find(string, 'r') == 2)
        self.assertTrue(find(string, 'a') == 3)
        self.assertTrue(find(string, 'k') == -1)
        self.assertTrue(find(string, ' ') == -1)
        self.assertTrue(find(string, 'abra') == 7)
        self.assertTrue(find(string, 'ABra') == -1)

    def test_count(self):
        string = "Abracadabra"
        self.assertTrue(count(string, 'A') == 1)
        self.assertTrue(count(string, 'b') == 2)
        self.assertTrue(count(string, 'r') == 2)
        self.assertTrue(count(string, 'a') == 4)
        self.assertTrue(count(string, 'c') == 1)
        self.assertTrue(count(string, 'd') == 1)