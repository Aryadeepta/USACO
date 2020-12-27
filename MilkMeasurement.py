def linSearch(arr,v):
    i=0
    while i<len(arr) and arr[i]<v:
        i+=1
    return(i)
f = open("measurement.in")
n,g=[int(i) for i in f.readline().split(" ")]
l=[]
for i in range(n):
    x = f.readline().split(" ")
    b=linSearch([j[0] for j in l],x[0])
    l=l[:b]+[x]+l[b:]
    print(l)
f.close()
mi=[g for i in l]
d=1
for i in l:
    m = max(mi)
    o=mi[int(i[1])-1]
    mi[int(i[1])-1]+=int(i[2])
    if (m!=max(mi) and ((o<m or m in mi))) or (m==max(mi) and o<m and mi[int(i[1])-1]>m):
        d+=1
    print(mi,max(mi))
f = open("measurement.out","w+")
f.write(str(d)+"\n")
f.close()
print(d)
