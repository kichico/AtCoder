N=int(input())
array=list(map(int, input().strip().split()))
ans=1
#print(array)
if 0 in array:
    print(0)
    exit()

for i in range(len(array)):
    ans=ans*array[i]
    if ans > 1e18:
        print(-1)
        exit()

print(ans)