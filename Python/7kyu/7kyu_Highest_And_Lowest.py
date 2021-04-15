def high_and_low(numbers):
    # ...
    numbers = [int(x) for x in numbers.split()]
    return "{} {}".format(max(numbers), min(numbers))
