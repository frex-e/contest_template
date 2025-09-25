a = "KANGAROO"
b = "KIWIBIRD"

s = input().upper()

x = 0
y = 0
for c in s:
  x += a.count(c)
  y += b.count(c)

if (x > y):
  print("Kangaroos")
elif (y > x):
  print("Kiwis")
else:
  print("Feud continues")