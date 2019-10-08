n=int(input())
C=input().split()
A=int(C[0])
B=int(C[1])
ab = []
ans = 0
for i in range(0,n):
    C=input().split()
    C[0]=int(C[0])
    C[1]=int(C[1])
    ab.append((C[0],C[1]))
ab.sort(key=lambda k : k[0]*k[1])
for i in range(0,n):
    if(A//(ab[i])[1]>ans):
        ans=A//(ab[i])[1]
    A*=(ab[i])[0]
print(ans)
