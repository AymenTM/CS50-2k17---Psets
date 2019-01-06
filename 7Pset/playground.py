
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


# nums = myRangeGenerator(1, 10)

# for i in nums:
#     print(i)


# print(next(nums))
# print(next(nums))
# print(next(nums))
# print(next(nums))
# print(next(nums))
# print(next(nums))
# ...


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# Sentence Iterable & Iterator Coding Challenge


# we expect a string of words as argument
# when we loop over the sentence; we loop over the words in the sentence.


class Sentence:

    def __init__(self, str):
        self.str = str
        self.i = 0
        self.word_list = str.split(' ')
        self.len = len(self.word_list)

    def __iter__(self):
        return self

    def __len__(self):
        return self.len

    def __next__(self):
        if self.i >= self.len:
            raise StopIteration
        i = self.i
        self.i += 1
        return self.word_list[i]

    def __str__(self):
        return self.str


mystr = Sentence('this is the world of league')

# for word in mystr:
#     print(word)

# print(next(mystr))
# print(next(mystr))
# print(next(mystr))
# print(next(mystr))
# print(next(mystr))
# print(next(mystr))


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

# My Solution
def strWordGenerator(str):
    word_list = str.split(' ')
    for word in word_list:
        yield word_list[i]
        i += 1

# Corey's solution
def strWordGenerator(str):
    for word in str.split():
        yield word


str_gen = strWordGenerator('this is the world of league')

# for word in str_gen:
#     print(word)

print(next(str_gen))
print(next(str_gen))
print(next(str_gen))
print(next(str_gen))
print(next(str_gen))
print(next(str_gen))


# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
