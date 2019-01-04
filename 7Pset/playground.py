
# Image Manipulation using Pillow's Image Module

from PIL import Image
import os

os.mkdir('./1000/')
new_size = (1000, 1000)

for file in os.listdir(path='.'):

    if file.endswith('.jpeg'):

        fn, fx = os.path.splitext(file)

        img = Image.open(file)
        img.thumbnail(new_size)
        img.save(f'1000/{fn}_1000.png')
