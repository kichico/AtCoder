N=int(input())

now=1
cnt=0
if(N==2):
    print(1)
    exit(0)
while(now*2<N):
    now*=2
    cnt+=1
    if(now*2==N):
        cnt+=1
        break

print(cnt)