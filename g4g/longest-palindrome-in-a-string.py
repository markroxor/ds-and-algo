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

def palin(st):
    dp = [[0 for i in range(len(st)+1)] for j in range(len(st)+1)]
    
    i1=0
    j1=0
    le = 0
    for ln in range(1,len(st)+1):
        for i in range(len(st)):
            j = i+ln-1
            if j>=len(st):
                break
            if ln==1:
                dp[i][j]=1
            elif ln==2 and st[i]==st[j]:
                dp[i][j]=1
            elif dp[i+1][j-1] and st[i]==st[j]:
                dp[i][j]=1
            if le<ln and dp[i][j]:
                i1=i
                j1=j
                le=ln
            #print (i,j,dp[i][j])

    print (st[i1:j1+1])
 
def main():
    t = int(input())
    for i in range(t):
        palin(input())

main()
