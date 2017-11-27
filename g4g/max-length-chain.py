
class readfile:
    def __init__(self, flag=0):
        self.flag=flag

    def __iter__(self):
        if self.flag:
            f = open("input.txt")
            for line in f:
                for n in line.split():
                    yield int(n)
        else:
            line = raw_input()
            for n in line.split():
                yield int(n)

def maxHeight(height, width, length, n):
    

def main():
    r = iter(readfile(1))
    #print next(r)
    #return
    t = next(r)
    while t:
        t-=1
        n = next(r)

        l = []
        w = []
        h = []
        for i in xrange(n):
            h.append(next(r))
            w.append(next(r))
            l.append(next(r))
        maxHeight(h,w,l,n)

main()
