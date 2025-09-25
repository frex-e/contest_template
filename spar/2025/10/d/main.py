n = int(input())

s = input()

penaltys = {
  "GDX": 5,
  "SNK": 15,
  'PRV': 25,
  "TWO": 20,
  'LNO' : 15,
  "LRB" : 10
}

orders = dict()
points = dict()
i = 0

names = []

while s != "END":
  name, code = s.split()
  if name not in orders:
    points[name] = 0
    orders[name] = i
    names.append(name)
    i += 1
  
  points[name] += penaltys[code]

  s = input()

parents = []
det = []
for name in names:
  if points[name] > 50:
    parents.append(name)
  elif points[name] > 30:
    det.append(name)

print(f"Week {n}")
print("Students for detention:")
if (len(det) == 0): 
  print("None")
else:
  print(*det)
print("Parental meeting for:")
if (len(parents) == 0): 
  print("None")
else:
  print(*parents)
