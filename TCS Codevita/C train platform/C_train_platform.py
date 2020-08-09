platforms = {}

def available(startT, endT,schedules):
    for index, entry in enumerate(schedules):
        if index<len(schedules)-1 and entry:
            


N = int(input("No of trains:"))

#first entry
startT = int(input())
endT = startT + int(input())
platforms[1] = [startT, endT]

# next entries
for i in range(2,N+1):
    startT = int(input())
    endT = startT + int(input())

    for num, schedules in platforms.items():
    if available(startT, endT, schedules):
        placeOnPlat()
        break