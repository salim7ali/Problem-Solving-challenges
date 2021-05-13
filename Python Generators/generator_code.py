class Gen:
    def __init__(self, number):
        self.number=number
        self.prev=0

    def __next__(self):
        return self.next()

    def next(self):
        if(self.prev == self.number):
            raise StopIteration()

        rv = self.prev**2
        self.prev += 1

        return rv


g = Gen(10000000000)

while True:
    try:
        print(g.__next__())
    except StopIteration:
        break
