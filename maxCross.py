f = open("maxcross.in","r")
out = open("maxcross.out","w")
(n,k,b)=(int(i) for i in f.readline().split(" "))
s=[]
for i in range(n):
    s.append(0)
for i in range(b):
    s[int(f.readline())-1]=1
print(s)
f.close()
m=sum(s[0:k])
c=m
i=k
while i<n:
    c=c+s[i]-s[i-k]
    m=min(m,c)
    i+=1
out.write(str(m)+"\n")
out.close()
