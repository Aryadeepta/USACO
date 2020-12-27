class cow:
    def __init__(self,x,y,p):
        self.x=x
        self.y=y
        self.p=p
        self.c=[]
def dist(a,b,c,d,r):
    return(((a-c)**2+(b-d)**2)<r**2)
def connect(a,b):
    if(dist(a.x,a.y,b.x,b.y,a.p):
       a.c+=b.c
    return
n=int(input(""))
ci=[list(int(j) for j in input("").split(" ")) for i in range(n)]
c=[cow(i[0],i[1],i[2]) for i in ci]
