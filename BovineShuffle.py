f=open("shuffle.in")
s=[int(i)-1 for i in f.readlines()[1][:-1].split(" ")]
f.close()
l=len(s)
print(s)
c=[1 for i in s]
pr=[1 for i in s]
prc=[]
while c!=prc:
    prc=c
    n=[0 for i in s]
    for i in range(l):
        if pr[i]>0:
            n[s[i]]=1
    pr=[i for i in n]
    c=[c[i]*n[i] for i in range(l)]
    print(c)
f=open("shuffle.out","w+")
f.write(str(sum(c))+"\n")
f.close()
