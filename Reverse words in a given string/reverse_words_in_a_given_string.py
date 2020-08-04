# https://www.geeksforgeeks.org/reverse-words-in-a-given-string/

from math import floor

text = "How was your day today and did you water the plants?"
wordList = text.split()
print(*wordList)

i = 0
while i<floor(len(wordList)/2):
    wordList[i], wordList[-1-i] = wordList[-1-i], wordList[i]
    i += 1

print(*wordList)