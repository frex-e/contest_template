def ints():
    return (int(x) for x in input().split())

c,z = ints()

cols = [[] for _ in range(z)]
removed = [-1 for _ in range(c)]

for i in range(c):
    x,y = ints()
    x -= 1

    cols[x].append((y,i))

for col in cols:
    col.sort(reverse=True)

last_time = -1

while True:
    failed = False

    max_height = 0
    for i in range(z):
        if len(cols[i]) == 0:
            failed = True
            break

        max_height = max(max_height, cols[i][-1][0])

    if failed:
        break
    
    ans = max(last_time + 1, max_height)
    last_time = ans
    for i in range(z):
        removed[cols[i][-1][1]] = ans
        del cols[i][-1]

q, = ints()

for _ in range(q):
    t,i = ints()

    i -= 1

    if removed[i] == -1:
        print("Never")
    elif removed[i] <= t:
        print("Yes")
    else:
        print("No")
