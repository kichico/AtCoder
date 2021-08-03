x,y,a,b=map(int,input().split())

cnt=0
while x*a<y and x*a<=x+b:
    x*=a
    cnt+=1

print(int(cnt+((y-x-1)//b)))