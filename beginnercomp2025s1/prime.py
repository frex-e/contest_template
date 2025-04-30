x,y,k = (int(x) for x in input().split())

false = False
true = True

prime_sieve = [true for _ in range(y + 1)]

prime_sieve[0] = false
prime_sieve[1] = false

for i in range(2,len(prime_sieve)):
    if prime_sieve[i]:
        m = i * 2
        while m < len(prime_sieve):
            prime_sieve[m] = false
            m += i

prefix_sum = [0 for _ in range(len(prime_sieve))]

for i in range(2, len(prime_sieve)):
    prefix_sum[i] = prefix_sum[i - 1] + int(prime_sieve[i])

# print(prefix_sum)

l = x
r = x

ans = 0

while r <= y:
    # print(l,r)
    if (prefix_sum[r] - prefix_sum[l - 1] <=k):
        ans = max(ans, r - l + 1)
    if prefix_sum[r] - prefix_sum[l] < k:
        r += 1
    else:
        l += 1

# print(prefix_sum[y] - prefix_sum[x - 1])

# print(prime_sieve[x:y+1])

if prefix_sum[y] - prefix_sum[x - 1] < k:
    print(-1)
else:
    print(ans)