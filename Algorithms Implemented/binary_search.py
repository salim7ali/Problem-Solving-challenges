import math

numList = [2, 43,245, 248, 249, 300, 305] #sorted list

def binary_search(key, numList):
    L = 0
    R = len(numList)-1
    while L<=R :
        mid = math.floor(L + ((R-L)/2))
        if numList[mid] == key :
            return mid
        elif key < numList[mid] :
            R = mid-1
        
        else :
            L = mid+1
    return -1

print(binary_search(20, numList))