

class List_Handler:
    def __init__(self, first, second):
        self.first = first
        self.second = second

    def ArrayChallenge(self):
        self.first = [itm for itm in self.first.split(',')]
        self.second = [itm for itm in self.second.split(',')]
        print(first, second, sep=" ")



if __name__ == "__main__":
    first = "[5, 2, 3]"
    second = "[2, 2, 3, 10, 6]"

    obj = List_Handler(first, second)
    obj.ArrayChallenge()
    
