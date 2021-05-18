from itertools import zip_longest

class List_Handler:
    def __init__(self, first, second):
        self.first = first
        self.second = second

    def ArrayChallenge(self):
        bad_characters = ['[', ']', ' ']
        for bad_char in bad_characters:
            self.first = self.first.replace(bad_char, '')
            self.second = self.second.replace(bad_char, '')

        self.first = self.first.split(',')
        self.first = [int(itm) for itm in self.first]
        self.second = self.second.split(',')
        self.second = [int(itm) for itm in self.second]
        print(self.first, self.second, sep=" ")

        zipped_list = zip_longest(self.first, self.second, fillvalue=0)
        result = '-'.join([str(f_num+s_num) for f_num, s_num in zipped_list])

        return result



if __name__ == "__main__":
    first = "[5, 2, 3]"
    second = "[2, 2, 3, 10, 6]"

    obj = List_Handler(first, second)
    print(obj.ArrayChallenge())
    
