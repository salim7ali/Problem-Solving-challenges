import math


N, K = input().split()
N = int(N)
K = int(K)


arrList = list(map(int, input().split()))
# print(arrList)

for i in range(1, K+1):
     ind = arrList.index(max(arrList))
     arrList[ind] = math.floor(arrList[ind]/2)
     

# print(arrList)
print(sum(arrList))