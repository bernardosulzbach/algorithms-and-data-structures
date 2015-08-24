class PriorityQueue():
    """
    A minimum-first priority queue.
    """

    def __init__(self, iterable=None):
        """
        Constructs an empty PriorityQueue or one from on the elements of an iterable.
        :param iterable: the iterable
        :return: a PriorityQueue
        """
        self.list = []
        if iterable is not None:
            for element in iterable:
                self.list.append(element)
            # If there are n complete levels, there are 2^n - 1 elements.
            # Start bubbling down from 2^floor(log2(length)) - 2.
            # Observation: -2 and not -1 as this is zero-indexed.
            if len(self) > 1:
                # first_index = 2 ** math.floor(math.log2(len(self))) - 2
                # This gets the leftmost set bit of the length.
                first_index = 2 ** len(self).bit_length() - 2
                for index in range(first_index, -1, -1):
                    self._bubble_down(index)

    def __contains__(self, element):
        if len(self.list) != 0 and element < self.list[0]:
            return False
        else:
            return element in self.list

    def __len__(self):
        return len(self.list)

    def __str__(self):
        return str(self.list)

    def _swap(self, a, b):
        """
        Swaps two elements, given their indices in the array.
        """
        self.list[a], self.list[b] = self.list[b], self.list[a]

    def _bubble_down(self, index):
        """
        Also known as heapify.
        """
        # Assume the element at the provided index is the smallest.
        index_of_smallest = index
        index_first_child = self._get_first_child(index_of_smallest)
        index_other_child = index_first_child + 1
        if len(self) > index_first_child:
            if self.list[index_first_child] < self.list[index_of_smallest]:
                index_of_smallest = index_first_child
        if len(self) > index_other_child:
            if self.list[index_other_child] < self.list[index_of_smallest]:
                index_of_smallest = index_other_child
        if index_of_smallest != index:
            self._swap(index, index_of_smallest)
            self._bubble_down(index_of_smallest)

    @staticmethod
    def _get_parent(index):
        return (index + 1) // 2 - 1

    @staticmethod
    def _get_first_child(index):
        return (index + 1) * 2 - 1

    def insert(self, element):
        self.list.append(element)
        if len(self) > 1:
            child = len(self) - 1
            index = self._get_parent(child)
            while self.list[index] > self.list[child]:
                self._swap(index, child)
                child = index
                index = self._get_parent(child)

    def get(self):
        if len(self) == 0:
            raise RuntimeError("Used get() with an empty PriorityQueue.")
        else:
            return_value = self.list[0]
            if len(self) > 1:
                self.list[0] = self.list.pop()
                self._bubble_down(0)
            else:
                self.list.clear()
        return return_value


def heap_sort(array):
    """
    Sorts an iterable using heapsort.
    :param array: the data
    :return: a sorted copy of the data
    """
    queue = PriorityQueue(array)
    sorted_array = [queue.get() for n in range(len(queue))]
    return sorted_array


if __name__ == '__main__':
    empty_list = []
    ten_to_one = range(10, 0, -1)
    assert sorted(empty_list) == heap_sort(empty_list)
    assert sorted(ten_to_one) == heap_sort(ten_to_one)