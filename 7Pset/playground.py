
import random

deck = list(range(1, 53))

random.shuffle(deck)

hand = random.sample(deck, k=5)

print(hand)

# >>> '[11, 33, 8, 43, 38]'  # 1st Try
# >>> '[40, 22, 39, 27, 38]'  # 2nd Try
# >>> '[43, 22, 32, 50, 13]'  # 3rd Try
# >>> '[15, 46, 36, 43, 9]'  # 4th Try
