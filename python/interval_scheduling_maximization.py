def sort_by_last_value(tasks):
    """
    Sorts a list of tasks according to their last value.
    This algorithm uses an linearithmic sorting algorithm, so its complexity is O(n lg n).
    :param tasks: a list of tasks
    :return: the sorted list of tasks
    """
    # key specifies a function of one argument that is used to extract a comparison key from each list element.
    # Here we use a lambda function that extracts the last value of an iterable.
    return sorted(tasks, key=lambda task: task[-1])


def optimal_scheduling(tasks):
    """
    Calculates the optimal scheduling for a set of tasks. The tasks should be sorted by nondecreasing finishing time.

    A task should be represented by a tuple with two or more values.
    The first value will be taken as the starting time of the task.
    The last value will be considered as the finishing time of the task. All other values are not taken into account.

    This algorithm works with a single pass through the iterable, so its complexity is O(n).
    :param tasks: an iterable of tasks
    :return: a list of tasks
    """
    if len(tasks) == 0:
        return []
    schedule = [tasks[0]]
    minimum_starting_time = tasks[0][-1]  # When the first scheduled task finishes.
    for i in range(1, len(tasks)):
        # Found a task we could start. As the tasks are sorted, this will be the first to finish of those we can start.
        if tasks[i][0] >= minimum_starting_time:
            schedule.append(tasks[i])
            minimum_starting_time = tasks[i][-1]
    return schedule
