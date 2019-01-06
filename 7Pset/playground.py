
# Iterators  & Iterables

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —


class myRange:

    def __init__(self, start, end):
        self.value = start
        self.end = end

    def __iter__(self):
        return self

    def __next__(self):
        if self.value >= self.end:
            raise StopIteration
        current = self.value
        self.value += 1
        return current


# example of an object that is both an iterator and iterable
# 1) we can iterate through its values
# 2) it remembers where it left off in the iteration and can get the next value in the iterable
# nums = myRange(3, 10)

# for i in nums:
# print(i)


# print(next(nums))
# print(next(nums))
# print(next(nums))
# print(next(nums))
# print(next(nums))
# print(next(nums))
# ...


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

def myRangeGenerator(current, end):
    while current < end:
        yield current
        current += 1


nums = myRangeGenerator(1, 10)

for i in nums:
    print(i)


# print(next(nums))
# print(next(nums))
# print(next(nums))
# print(next(nums))
# print(next(nums))
# print(next(nums))
# ...


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
