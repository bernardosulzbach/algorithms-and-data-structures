# This are my implementations of two algorithms that find a maximum subarray
# (a subarray whose sum is maximum).
#
# It is also possible to find the maximum subarray by testing C(n, 2) pairs.
# This is the brute-force approach and it is O(n^2). Don't use this.
#
# The first one finds the maximum subarray using D&C in O(n lg n).
#
# The second one can find the maximum subarray in O(n).
# It is known as Kadane's algorithm.


def find_maximum_crossing_subarray(array, start, end):
    """
    Finds the maximum middle-crossing subarray between start and end, inclusive.
    Returns a tuple of the form (left index, right index, sum).
    """
    mid = (start + end) // 2
    cur_l_sum = 0
    max_l_sum = None
    max_l_index = mid
    for i in range(mid, start - 1, -1):
        cur_l_sum += array[i]
        if max_l_sum is None or cur_l_sum > max_l_sum:
            max_l_sum = cur_l_sum
            max_l_index = i
    cur_r_sum = 0
    max_r_sum = 0
    max_r_index = mid
    # As the left sum includes the middle element, the right sum does not.
    for i in range(mid + 1, end + 1):
        cur_r_sum += array[i]
        if cur_r_sum > max_r_sum:
            max_r_sum = cur_r_sum
            max_r_index = i
    return (max_l_index, max_r_index, max_l_sum + max_r_sum)


def find_maximum_subarray(array, start, end):
    """
    Finds the maximum subarray between start and end (inclusive).
    Returns a tuple of the form (left index, right index, sum).
    """
    if start == end:
        return (start, end, array[start])
    else:
        mid = (start + end) // 2
        l = find_maximum_subarray(array, start, mid)
        m = find_maximum_crossing_subarray(array, start, end)
        r = find_maximum_subarray(array, mid + 1, end)
        if l[2] >= r[2] and l[2] >= m[2]:
            return l
        elif r[2] >= l[2] and r[2] >= m[2]:
            return r
        else:
            return m


def find_maximum_subarray_by_kadane(array, start, end):
    max_ending_here = array[start]
    max_ending_here_l = start
    max_so_far = array[start]
    max_so_far_l = start
    max_so_far_r = start
    for i in range(start + 1, end + 1):
        if array[i] > max_ending_here + array[i]:
            max_ending_here = array[i]
            max_ending_here_l = i
        else:
            max_ending_here += array[i]
        if max_ending_here > max_so_far:
            max_so_far = max_ending_here
            max_so_far_l = max_ending_here_l
            max_so_far_r = i
    return (max_so_far_l, max_so_far_r, max_so_far)


if __name__ == '__main__':
    array_a = [1]
    array_b = [-1]
    array_c = [10, -20]
    array_d = [-15, 20, 40, -10, 15]
    print(find_maximum_subarray(array_a, 0, len(array_a) - 1))
    print(find_maximum_subarray(array_b, 0, len(array_b) - 1))
    print(find_maximum_subarray(array_c, 0, len(array_c) - 1))
    print(find_maximum_subarray(array_d, 0, len(array_d) - 1))
    print(find_maximum_subarray_by_kadane(array_a, 0, len(array_a) - 1))
    print(find_maximum_subarray_by_kadane(array_b, 0, len(array_b) - 1))
    print(find_maximum_subarray_by_kadane(array_c, 0, len(array_c) - 1))
    print(find_maximum_subarray_by_kadane(array_d, 0, len(array_d) - 1))
