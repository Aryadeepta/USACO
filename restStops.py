##def rS(r):
##    if(len(r)==1):
##        return r
##    m=0
##    for i in range(len(r)):
##        if(r[i]>=r[m]):
##            m=i
##    if(m<len(r)-1):
##        t=rS(r[m+1:])
##        for i in range(len(t)):
##            t[i]+=m+1
##        return [m]+t
##    else:
##        return [m]
(l,n,f,b)=(int(i) for i in input("").split(" "))
r=[]
while len(r)<=l:
    r.append(0)
for i in range(n):
    (x,c)=(int(j) for j in input("").split(" "))
    r[x]=c
rs=[0]
for i in range(len(r)-1):
    j=rs[len(rs)-1]
    if(r[i]>=r[j]):
        while(r[i]>=r[j] and len(rs)>0):
            j=rs.pop()
        rs=rs+[i,i+1]
    print(rs)
c=0
g=0
for i in rs:
   g+=r[i]*(i-c)*(f-b)
   c=i
print(g)
