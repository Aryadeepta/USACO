import sys
def between(a,b,c):
    return (c>=min(a,b) and c<=max(a,b))
def xor(a,b):
    return((a and not b) or (b and not a))
def intersect(a,b):
    if xor((between(a[0],a[2],b[0]) and between(a[1],a[3],b[1])),(between(a[0],a[2],b[2]) and between(a[1],a[3],b[3]))):
        return True
    if xor((between(b[0],b[2],a[0]) and between(b[1],b[3],a[1])),(between(b[0],b[2],a[2]) and between(b[1],b[3],a[3]))):
        return True
    return False
file = "cowjump"
f = open(file+".in","r")
out = open(file+".out","w")
lines = f.readlines()
n = int(lines.pop(0))
dic = {}
lm = []
for i in range(n):
    lm.append([])
    dic[i] = 0
    lines[i].replace("\n","")
    l = lines[i].split(" ")
    for j in l:
        lm[i].append(int(j))
for i in range(n):
    for j in range(i):
        if intersect(lm[i],lm[j]):
            dic[i]+=1
            dic[j]+=1
            if dic[i]>=2:
                out.write(str(i+1)+"\n")
                f.close()
                out.close()
                sys.exit()
            if dic[j]>=2:
                out.write(str(j+1)+"\n")
                f.close()
                out.close()
                sys.exit()
