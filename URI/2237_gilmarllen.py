import sys

def checkEnd(curr, goal):
  for r, row in enumerate(curr):
    for c, x in enumerate(row):
      if (r,c) not in goal[curr[r][c]]:
        return False
  return True

def rec(curr, goal, x, y):
  if (x>3) or (y>1):
    return sys.maxsize

  if checkEnd(curr, goal):
    return 0

  if (x,y) in goal[curr[y][x]]:
  

  return

ini = []
fin = []

ini.append([int(x) for x in input().split()])
ini.append([int(x) for x in input().split()])
fin.append([int(x) for x in input().split()])
fin.append([int(x) for x in input().split()])

pos = {}

for r, row in enumerate(fin):
  for c, x in enumerate(row):
    if x in pos:
      pos[x].append((r,c))
    else:
      pos[x] = [(r,c)]

print(rec(ini,pos, 0, 0))