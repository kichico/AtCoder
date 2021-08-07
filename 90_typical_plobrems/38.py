def gcd(a,b):
    if b==0: return a
    else: return gcd(b,a%b)

def lcm(a,b): return (a/gcd(a,b))*b

a,b=map(int,input().split())
v=lcm(a,b)
if(v>1e18):
    print("Large")
else:
    print(v)