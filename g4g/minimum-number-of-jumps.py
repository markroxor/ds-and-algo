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
            line = input()
            for n in line.split():
                #print type(n),n
                yield int(n)

def jumps(arr):
    dp = [100000000000000]*len(arr)

    dp[0]=0
    for i in range(len(arr)):
        for j in range(i):
            dis = i-j
            if arr[j]>=i-j:
                dp[i] = min(dp[i],dp[j]+1)

        #print (i,dp[i])

    print (dp[len(arr)-1])

def main():
    read = iter(readfile())
    t = next(read)

    for i in range(t):
        n = next(read)
        l = []

        for i in range(n):
            l.append(next(read))

        jumps(l)

main()
