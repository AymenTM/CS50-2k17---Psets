
import memory_profiler
import random
import time

names = ['John', 'Louis', 'Corey', 'John', 'Adam', 'Steve', 'Rick', 'Thomas', ]
majors = ['Math', 'Engineering', 'CompSci', 'Arts', 'Business']

print(f'Memory (Before): {memory_profiler.memory_usage()}Mb')


def people_list(num_people):
    result = []
    for i in range(num_people):
        person = {
            'id': i,
            'name': random.choice(names),
            'major': random.choice(majors)
        }
        result.append(person)
    return (result)


def people_generator(num_people):
    for i in range(num_people):
        person = {
            'id': i,
            'name': random.choice(names),
            'major': random.choice(majors)
        }
    yield person

# Testing Lists
# t1 = time.perf_counter()
# people = people_list(1000000)
# t2 = time.perf_counter()


# Testing Generators
t1 = time.perf_counter()
people = people_generator(1000000)
t2 = time.perf_counter()

print(f'Memory (Before): {memory_profiler.memory_usage()}Mb')
print(f'Took {t2-t1} Seconds')
