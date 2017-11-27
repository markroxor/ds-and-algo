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

def lis(l):
    n=len(l)
    dp = [x[0] for x in l]

    for i in range(n):
      for j in range(i):
        if l[i][1]>l[j][1] and l[i][2]>l[j][2]:
          dp[i]=max(dp[i],dp[j]+l[i][0])
    return max(dp)
    
def cmp_to_key(mycmp):
    'Convert a cmp= function into a key= function'
    class K:
        def __init__(self, obj, *args):
            self.obj = obj
        def __lt__(self, other):
            return mycmp(self.obj, other.obj) < 0
        def __gt__(self, other):
            return mycmp(self.obj, other.obj) > 0
        def __eq__(self, other):
            return mycmp(self.obj, other.obj) == 0
        def __le__(self, other):
            return mycmp(self.obj, other.obj) <= 0
        def __ge__(self, other):
            return mycmp(self.obj, other.obj) >= 0
        def __ne__(self, other):
            return mycmp(self.obj, other.obj) != 0
    return K
    
def compare(b1,b2):
  #print b1,b2
  return ((b1[2]*b1[1])-(b2[1]*b1[2]))

def maxHeight(height, width, length, n):
    box = []
    for i in range(n):
        box.append([height[i],min(width[i],length[i]),max(width[i],length[i])])
        box.append([width[i],min(height[i],length[i]),max(height[i],length[i])])
        box.append([length[i],min(width[i],height[i]),max(width[i],height[i])])
  #  print box
    box = sorted(box,key=cmp_to_key(compare))
   # print box
    return lis(box)

def main():
    r = iter(readfile())
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
        print (maxHeight(h,w,l,n))

main()

