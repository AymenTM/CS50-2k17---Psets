# Harvard CS50 2017/2018 Weekly Overview 

My solutions to Harvard's 2017/2018 CS50 problem sets.
[Click here for the edX Course!](https://www.edx.org/course/introduction-computer-science-harvardx-cs50x#!)

## Overview of the Weeks

### Week 0: Scratch

We made a small 2D game.

### Week 1: C ; Water, Greedy, Mario & Credit !

**water.c** : a program that calculates your water consumption after having asked the user a couple of questions.

**greedy.c** : a program that counts the minimum amount of coins needed to give back the correct change (using the greedy algorithm).

**mario.c** : a program that prints out a double half-pyramid of a specified height.

```javascript
~/workspace/pset1/ (master) $ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

**credit.c** :
A program that determines whether a provided credit card number is valid according to Luhn’s algorithm.

```javascript
~/workspace/pset1/ (master) $ ./credit
Number: 6176292929
INVALID

~/workspace/pset1/ (master) $ ./credit
Number: 378282246310005
AMEX
```

### Week 2: Text Ciphering

**caesar.c** : a program that ciphers text per Caesar's cipher.
```javascript
~/workspace/pset2/ (master) $ ./caesar 13
Be sure to drink your Ovaltine!
Or fher gb qevax lbhe Binygvar!
```

**vigenere.c** : a program that ciphers text per Vigènere's cipher.
```javascript
~/workspace/pset2/ (master) $ ./vigenere bacon
Meet me at the park at eleven am
Negh zf av huf pcfx bt gzrwep oz
```

### Week 3: Search & Sorting Algorithms; Find, Game of Fifteen & Music

**find.c** : program that searches a niddle in a haystack (an integer in an array of integers).

**fifteen.c** : implementation of the game: Game of Fifteen
```javascript
~/workspace/pset3/ (master) $ ./fifteen 4

15 14 13 12

11 10  9  8

 7  6  5  4

 3  1  2  _
 
Tile to move:
```

**frequency.c** : function that turns musical notes to their corresponding frequency (in hertz).


### Week 4: Reading & Writing Files; Forensics, Resizing Images & Data Recovery
**whodunit.c** : a program that changes the pixel colors of an image to uncover a mystery.
```javascript
~/workspace/pset4/ (master) $ ./whodunit clue.bmp verdict.bmp
```

**resize.c** : a program that enlarges or shrinks an image to a given size (n).
```javascript
~/workspace/pset4/ (master) $ ./resize 4 small.bmp large.bmp
```

**recover.c** : a program that recovers Jpeg images from a camera's memory card (card.raw).
```javascript
~/workspace/pset4/ (master) $ ./recover card.raw
```


### Week 5: Data-Structures (Linked Lists, Stacks, Queues, BSTs, Tries ...) & a Spellchecker
Implementation of a program that spell-checks a file (implemented using a **trie** data-structure).

```javascript
~/workspace/pset5/ (master) $ ./speller dictionaries/large endi.txt

MISSPELLED WORDS

nme
veri
persan
yo
bro
USConstitution
http
usconstitution
const
html

WORDS MISSPELLED:     10
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        722
TIME IN load:         0.10
TIME IN check:        0.00
TIME IN size:         0.00
TIME IN unload:       0.06
TIME IN TOTAL:        0.16
```


## Week 7 and 8: Python
Requirements & Dependencies:
```javascript
cd ~/workspace/pset6/sentiments/
pip3 install --user -r requirements.txt
```

Convert some of week 1 & 2 .c programs to .py
```javascript
~/workspace/pset6/ (master) $ python mario.py
Height: 5
    ##
   ###
  ####
 #####
######
```

```javascript
~/workspace/pset6/ (master) $ python greedy.py
O hai! How much change is owed?
0.41
4
```

```javascript
~/workspace/pset6/ (master) $ python caesar.py 13
HELLO
URYYB
```

```javascript
~/workspace/pset6/ (master) $ python vigenere.py bacon
Meet me at the park at eleven am
Negh zf av huf pcfx bt gzrwep oz
```

Sentiments

smile.py : a program that categorizes a word as positive or negative

tweets.py categorizes a user’s recent 100 tweets as positive or negative (uses Twitter API)

Implement a website that generates a pie chart categorizing a user’s tweets

Usage: 
```javascript
~/workspace/pset6/sentiments/ (master) $ export API_KEY= <insert your API_KEY from Twitter here>
~/workspace/pset6/sentiments/ (master) $ export API_SECRET= <insert your API_SECRET from Twitter here>
~/workspace/pset6/sentiments/ (master) $ export FLASK_APP=application.py
~/workspace/pset6/sentiments/ (master) $ export FLASK_DEBUG=1
~/workspace/pset6/sentiments/ (master) $ flask run
```


## Week 9: Python & SQL

C$50 Finance
Implement a website via which users can "buy" and "sell" stocks, a la the below.

Requirements & Dependencies:
```javascript
cd ~/workspace/pset7/finance/
pip3 install --user -r requirements.txt
```
Usage: 
```javascript
~/workspace/pset7/finance/ (master) $ flask run
~/workspace/pset7/finance/ (master) $ phpliteadmin finance.db
```

## Week 10 & 11: Javascript
Implement a website that lets users search for articles atop a map (using Google's API)

Requirements & Dependencies:
```javascript
cd ~/workspace/pset8/mashup/
pip3 install --user -r requirements.txt
```
Usage: 
```javascript
~/workspace/pset8/mashup/ (master) $ export API_KEY=<API_KEY from Google Maps API>
~/workspace/pset8/mashup/ (master) $ flask run
~/workspace/pset8/mashup/ (master) $ phpliteadmin mashup.db
```



## Week 12-end: Final Project
https://github.com/endiliey/rengorum

## Disclaimer : I am aware that my materials might not be free of errors. I intend to correct them as I encounter it. I am still learning :)

----
_Note: prior to this I had strictly 0 coding/programming experience._
