def getScore(arr):
    return((sum(arr)-min(arr))/(len(arr)-1))
f = open("homework.in")
n=int(f.readline())
s=[int(i) for i in f.readline().split(" ")]
f.close()
r=""
h=0
if(max(s)==min(s)):
    for i in range(n-2):
        r+=str(i+1)+"\n"
else:
    while len(s)>1:
        x = getScore(s)
        if(h<x):
            r=str(n-len(s))+"\n"
            h=x
        elif(h==x):
            r+=str(n-len(s))+"\n"
        del s[0]
f = open("homework.out","w+")
f.write(r)
f.close()
