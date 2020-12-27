fin = open("triangles.in","r")
out = open("triangles.out","w")
rl = fin.readlines()
sx = {}
sy = {}
x = {}
y = {}
ps=[]
s=0
n=int(rl.pop(0))
for i in range(n):
    (ix,iy)=(int(j) for j in rl.pop(0).split(" "))
    p=(ix,iy)
    ps.append(p)
    sx[p]=[]
    sy[p]=[]
    if ix in x.keys():
        for j in x[ix]:
            sx[j].append(p)
            sx[p].append(j)
        x[ix].append(p)
    else:
        x[ix]=[p]
    if iy in y.keys():
        for j in y[iy]:
            sy[j].append(p)
            sy[p].append(j)
        y[iy].append(p)
    else:
        y[iy]=[p]
for p in ps:
    for i in sx[p]:
        for j in sy[p]:
            s+=abs((i[1]-p[1])*(j[0]-p[0]))
out.write(str(s%1000000007)+"\n")
out.close()
fin.close()
