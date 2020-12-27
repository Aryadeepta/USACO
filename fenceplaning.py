def minP(cs):
    x = [max(int(i[0]) for i in cs),min(int(i[0]) for i in cs)]
    y = [max(int(i[1]) for i in cs),min(int(i[1]) for i in cs)]
    return 2*((int(x[0])-int(x[1]))+(int(y[0])-int(y[1])))
file = "fenceplan"
f = open(file+".in","r")
out = open(file+".out","w")
lines = f.read().split("\n")
sn,sm = lines.pop(0).split(" ")
n,m = int(sn),int(sm)
d = {}
c={}
ml = []
nl = []
for i in range(n):
    nl.append([])
    nl[i] = lines.pop(0).split(" ")
for i in range(m):
    ml.append([])
    ml[i] = lines.pop(0).split(" ")
for i in range(n):
    d[i+1] = []
    c[i+1] = []
for i in range(n):
    for co in nl[i]:
        c[i+1].append(co)
for i in ml:
    d[int(i[0])].append(int(i[1]))
    d[int(i[1])].append(int(i[0]))
for zebra in range(n):
    for i in d:
        for j in d[i]:
            for k in d[j]:
                if k not in d[i]:
                    d[i]=d[i]+[k]
ps = {}
for i in d:
    ps[i] = []
    for j in d[i]:
        ps[i].append(c[j])
out.write(str(min(minP(ps[i]) for i in ps))+"\n")
f.close()
out.close()

    
    
