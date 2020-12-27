def swap(ar,a,b):
    ar[a],ar[b] = ar[b],ar[a]
    return ar
f = open("evolution.in","r")
out = open("evolution.out","w")
lines = f.readlines()
c = lines.pop(0)
cs = []
for i in lines:
    i = i.replace("\n","")
    if len(i)>1:
        qqq = i.split(" ")
        qqq.pop(0)
        cs.append(qqq)
dic = {}
for i in cs:
    for j in i:
        if j in dic:
            dic[j] += 1
        else:
            dic[j] = 1
for i in cs:
    for zebra in range(len(i)):
        for j in range(len(i)-1):
            if dic[i[j+1]]>dic[i[j]]:
                swap(i,j,j+1)
dic = {}
cont = {}
for i in cs:
    i = ["start"] + i
    for k in range(len(i)):
        j = i[k]
        if j in dic:
           if len(i)>k+1:
                dic[j].append(i[k+1:])
        else:
            if len(i)>k+1:
                dic[j] = [i[k+1:]]
            else:
                dic[j] = []
        if j in cont:
           if k>=1:
                cont[j].append(i[0:k])
        else:
            if k>=1:
                cont[j] = [i[0:k]]
            else:
                cont[j] = []
b = True
for i in dic:
    for k in dic[i]:
        for j in k:
            for z in cont[j]:
                if i not in z:
                    b = False
if b == True:
    out.write("yes")
else:
    out.write("no")
f.close()
out.close()
