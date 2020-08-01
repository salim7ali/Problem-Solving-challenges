# https://www.geeksforgeeks.org/sort-array-wave-form-2/

import random 

numList = [random.randint(0,100) for i in range(8)]
print("Before waveform: ", numList)
numList.sort()
print("sorted : ", numList)

index = 0
while len(numList) - index != 1 and index<len(numList):
    numList[index], numList[index+1] = numList[index+1], numList[index]
    index +=2

print("After waveform: ", numList)