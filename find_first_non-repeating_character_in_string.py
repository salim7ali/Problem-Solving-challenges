index = 99999999
mins = 99999999
myString = "1223a1k1a612absss15ams5"
count = {}


for ind, char in enumerate(myString):   
    if char in count.keys():
        count[char][0] += 1
    else:
        count[char] = [1, ind]

for key, value in count.items():
    if value[0] == 1 and value[1] < index:
        index = value[1]

print("First non repeating char is: ", myString[index])