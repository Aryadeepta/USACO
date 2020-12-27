def count(a):
    c = 0
    for i in a:
        c += i.count("L")
    return c

def column(a,c):
    ar = []
    for b in a:
        ar.append(b[c])
    return ar
def flip(a):
    b = []
    for i in a:
        if i=="R":
            b.append("L")
        else:
            b.append("R")
    return b
file = "leftout"
f = open(file+".in","r")
lines = f.read().split("\n")
n = int(lines.pop(0))
lm = []
for i in range(len(lines)):
    lm.append([])
    for j in lines[i]:
        lm[i].append(j)
while count(lm)!=1:
    for i in range(n):
        if column(lm,i).count("R")<2:
            for r in range(n):
                if lm[r][i] == "R":
                    lm[r][i] = "L"
                else:
                    lm[r][i] = "R"
    if count(lm)==1:
        for i in range(n):
            for j in range(n):
                if lm[i][j] == "L":
                    out = open(file+".out","w")
                    out.write(str(i+1)+" "+str(j+1)+"\n")
                    out.close()
                    break
    for i in range(n):
        if lm[i].count("R")<2:
            lm[i] = flip(lm[i])
    if count(lm)==1:
        for i in range(n):
            for j in range(n):
                if lm[i][j] == "L":
                    out = open(file+".out","w")
                    out.write(str(i+1)+" "+str(j+1)+"\n")
                    out.close()
                    break
f.close()

