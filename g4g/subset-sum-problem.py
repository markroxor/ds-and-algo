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

def sum_set(arr):

  S = sum(arr)
  if S&1:
    return 0

  dp = [[1]*(S+1)]*(len(arr)+1)

  for i in range(len(arr)+1):
    for s in range(S/2+1):
      #print("s",s-arr[i-1],s,i,s>=arr[i-1], dp[0][i-1])
      if s==0:
    #    print ("a")
        dp[i][s]=1
      elif i==0:
   #     print ("b")
        dp[i][s]=0
      elif s>=arr[i-1] and dp[i-1][s-arr[i-1]]:
  #      print ("c")
        dp[i][s]=1
      else:
 #       print ("d")
        dp[i][s]=dp[i-1][s]
    
  #for s in range(S/2+1):
  #  print (s,dp[s])
  return dp[len(arr)][S/2]

def main():
    r = iter(readfile(1))

    t = next(r)
    while t:
        t-=1
        n = next(r)
        arr = []

        for i in range(n):
          arr.append(next(r))
        print (sum_set(arr))

main()
