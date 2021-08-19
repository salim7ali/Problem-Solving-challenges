
def ReplaceX(s):
    # case 1
    if s == None:
        return -1
    
    first_half, second_half = s.split('+')
    second_half, third_half = second_half.split('=') 

    first_half = first_half.strip(' ')
    if first_half!='X':
        first_half = int(first_half.strip(' '))
    second_half = second_half.strip(' ')
    if second_half!='X':
        second_half = int(second_half.strip(' '))
    third_half = third_half.strip(' ')
    if third_half!='X':
        third_half = int(third_half.strip(' '))

    print(first_half, second_half, third_half)
    
    for index, singleChar in enumerate(s):
        if(singleChar!='X'):
            continue
        # case 2
        if index==0:
            return third_half-second_half
        # case 3
        elif s[index-2]=='+':
            return third_half-first_half
        # case 4
        else:
            return first_half+second_half
        break

if __name__ == "__main__":
    s = "2 + 15 = X"
    print(ReplaceX(s))

    s = "22 + X = 145"
    print(ReplaceX(s))