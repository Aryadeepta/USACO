
f = open("buckets.in","r")
out = open("buckets.out","w")
i = 0
j = 0
ar = f.readlines()
for i in range(len(ar)):
    for j in range(len(ar[i])):
        c = ar[i][j]
        if c == "B":
            b = (i,j)
        if c == "L":
            l = (i,j)
        if c == "R":
            r = (i,j)
if b[0]==r[0] and r[0]==l[0] and max(b[1],l[1])>r[1] and r[1]>min(b[1],l[1]):
    d = abs(l[1]-b[1])+1
elif b[1]==r[1] and r[1]==l[1] and max(b[0],l[0])>r[0] and r[0]>min(b[0],l[0]):
    d = abs(l[0]-b[0])+1
else:
    d = abs(l[0]-b[0])+abs(l[1]-b[1])-1
out.write(str(abs(d))+"\n")
f.close()
out.close()
