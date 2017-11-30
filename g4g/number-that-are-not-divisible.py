class readfile:
    def __init__(self, flag=0):
        self.flag=flag

    def __iter__(self):
        if self.flag:
            f = open("input.txt")
            for line in f:
                for n in line.split():
                    #print type(n),n
                    yield int(n)
        else:
            line = raw_input()
            for n in line.split():
                #print type(n),n
                yield int(n)

def ugly(n):
    two,three,five=1,1,1
    ans = 1
    for i in range(n):
      
      if(2*two<=min(3*three,5*five)):
        ans=two*2
        two+=1
      if(3*three<=min(2*two,5*five)):
        ans=three*3
        three+=1
      if(5*five<=min(3*three,2*two)):
        ans=five*5
        five+=1

      print i+1,ans
    print (ans)

def main():
  f = iter(readfile())
  t = next(f)
  while t:
    t-=1
    n = next(f)
    ugly(n-1)
main()
