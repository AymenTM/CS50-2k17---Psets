
import os

os.chdir('/Volumes/DISK 1/MacBook Pro/Personal/iTunes/Quran - Sudais')

for f in os.listdir():
    names = (f.strip()[6:-4]).split('-')
    if len(names) > 1:
        names[1] = names[1].capitalize()
    print(names)

# os.rename(f, names)
