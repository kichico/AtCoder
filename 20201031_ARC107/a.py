all = list(map(int, input().split()))

a = all[0]
b = all[1]
c = all[2]
MOD = 998244353
sumA = a*(1+a)//2
sumB = b*(1+b)//2
sumC = c*(1+c)//2
sumALL = sumA*sumB*sumC
sumALL %= MOD
print(int(sumALL))
