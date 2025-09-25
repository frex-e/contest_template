x = 10
y = 32

a = 1431655765
b = 715827882
m = 31

def f(p):
    return (p | x) + (p | y)

print("{:b}".format(f(a)))
print(f(b))
print(f(31))

# 2863311572
# 1431655764
# 94