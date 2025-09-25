import math

maxw = 100_000

best = (float("inf"), -1, -1,-1)

for i in range(2,150):
  for j in range(2,25000):
    l = i
    b = j
    target = maxw

    # Calculate k
    per_level = (target // l)
    k = (b + per_level - 1) // per_level

    if (k <= 1): continue

    # First
    lower = (l*b + k - 1)//k
    upper = min(l*(b - 1)//(k - 1) + l - 1, maxw)
    rng = upper - lower

    # second
    k += 1
    lower = (l*b + k - 1)//k
    upper = min(l*(b - 1)//(k - 1) + l - 1, maxw)
    rng = max(upper - lower, rng)

    queries = 2*(rng - 1) 
    # max_q = max(queries + b,b + l * ((l + 1)//2))
    left = queries + b
    right = b + (l)*(l-1)
    max_q = max(left ,right)
    best = min(best, (max_q, left, right,k,upper))

    if (max_q <= 25_000):
      print("SUCCESS")
      print(f"l: {l} b: {b}")
      print(f"{lower} <= x <= {upper}")
      print(f"K: {k}")
      print(f"Sucess case queries: {queries + b}")
      # print(f"Fail case queries: {b + l * ((l + 1)//2)}")
      print(f"Fail case queries: {b + l * (l - 1)}")

print(best)