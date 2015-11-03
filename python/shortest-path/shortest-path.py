# Three different algorithms that starting at the first point, visit all points in a set once and return the distance.

import random
import time
import functools


def timed(f):
    @functools.wraps(f)
    def wrapper(arg):
        start = time.time()
        value = f(arg)
        delta = round(1000 * (time.time() - start), 2)
        print(f.__name__, "took", delta, "ms.")
        return value

    return wrapper


def distance_between(a, b):
    return ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) ** .5


def find_index_of_nearest_point(point_list, lookup_limit=0):
    """
    Returns the index of the point that is nearest of the first point of the list. If a lookup limit is provided, only
    the first lookup_limit points will be tested.
    :param point_list: a list of points with at least one point
    :param lookup_limit: a lookup limit, 0 for no limit
    :return: an index
    """
    assert len(point_list) > 1, "point list should have at least two points"
    assert lookup_limit >= 0, "lookup limit cannot be negative"
    distance_to_nearest_point = -1
    index_of_nearest_point = -1
    for index in range(1, len(point_list) if lookup_limit == 0 else min(len(point_list), lookup_limit + 1)):
        distance = distance_between(point_list[0], point_list[index])
        if distance_to_nearest_point == -1 or distance < distance_to_nearest_point:
            distance_to_nearest_point = distance
            index_of_nearest_point = index
    return index_of_nearest_point


@timed
def len_simple(point_list):
    distance = 0
    for i in range(len(point_list) - 1):
        distance += distance_between(point_list[i], point_list[i + 1])
    return distance


@timed
def len_best_of_next_two(point_list):
    point_list = list(point_list)  # Copy the list.
    distance = 0
    while len(point_list) > 1:
        index_of_nearest_point = find_index_of_nearest_point(point_list, 2)
        distance += distance_between(point_list[0], point_list[index_of_nearest_point])
        point_list[0] = point_list[index_of_nearest_point]
        point_list.pop(index_of_nearest_point)
    return distance


@timed
def len_greediest(point_list):
    point_list = list(point_list)  # Copy the list.
    distance = 0
    while len(point_list) > 1:
        index_of_nearest_point = find_index_of_nearest_point(point_list)
        distance += distance_between(point_list[0], point_list[index_of_nearest_point])
        point_list[0] = point_list[index_of_nearest_point]
        point_list.pop(index_of_nearest_point)
    return distance


random_point = lambda: (random.random(), random.random())
random_point_list = lambda x=100: [random_point() for _ in range(x)]

if __name__ == '__main__':
    p_list = random_point_list()
    functions = (len_simple, len_best_of_next_two, len_greediest)
    for function in functions:
        print(function.__name__, round(function(p_list), 2))
