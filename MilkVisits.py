class node:
    def __init__(self,b):
        self.t=b
        self.c=[self]
    def addToPath(self,n):
        x = self.c
        self.c.append(n)
        for i in n.c:
            self.c.append(i)
        for i in x:
            i.c.append(n)
        return
fin = open("milkvisits.in","r")
(n,m) = (int(i) for i in fin.readline().split(" "))
s = fin.readline()
c=[]
for i in range(n):
    c.append(node((s[i]=="H")))
for i in range(n-1):
    (x,y)=(int(i)-1 for i in fin.readline().split(" "))
    if(c[x].t==c[y].t):
        c[x].addToPath(c[y])
        c[y].addToPath(c[x])
o=""
for i in range(m):
    (ix,iy,it) = (i for i in fin.readline().split(" "))
    x=c[int(ix)-1]
    y=c[int(iy)-1]
    t = (it=="H\n")
    if (y in x.c) and (t!=x.t):
        o+="0"
    else:
        o+="1"
fin.close()
fout = open("milkvisits.out","w+")
fout.write(o+"\n")
fout.close()
print(o)
