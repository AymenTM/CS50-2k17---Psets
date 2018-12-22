
import re

text = """
abcdefghijklmnopqrstuvwxyz
ABCDEFGHIJKLMNOPQRSTUVWXYZ
0123456789

Ha Haha

Meta Characters (that need to be escaped):
. ^ $ * + ? { } [ ] \ | ( )

ayk.com

321-555-4350
123.345.9824
123*345*9824
123+345+9824
123@345@9824

TypeError: expected string or bytes - like object

Mr.Schafer
mRs.Levki
Mr Smith
Ms Davis
ms Larry
Mrs. Robinson
Mr. T
"""
sentence = 'Start a sentence and then bring it to an end.'


urls = """
https://www.google.com
http://coreyms.com
https://youtube.com
https://www.nasa.gov
"""

teachers = """
Mr.Schafer
mRs.Levki
Mr Smith
Ms Davis
ms Larry
Mrs. Robinson
Mr. T
"""


# my_pattern = re.compile(r'(https?://)(www\.)?(\w+)(\.\w+)')

urls = """
		https://www.google.com
		http://coreyms.com
		https://youtube.com
		https://www.nasa.gov
		"""

my_pattern = re.compile(r'(https?://)(www\.)?(\w+)(\.\w+)')

match = my_pattern.search(urls)

#							OR

match = re.search(r'(https?://)(www\.)?(\w+)(\.\w+)', urls)

print(match)
