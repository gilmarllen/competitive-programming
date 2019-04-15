import math

def calcAngle_A(a, b):
  dx = (a[0] - b[0])
  dy = (a[1] - b[1])
  if dx==0:
    return math.pi/2
  angle = math.atan(dy/dx)
  if dx>0:
    angle += math.pi
  return angle

def calcAngle_B(a, b):
  dx = (a[0] - b[0])
  dy = (a[1] - b[1])
  if dx==0:
    return math.pi/2
  angle = math.atan(dy/dx)
  if dx>0:
    angle = abs(angle)
  else:
    angle = math.pi-angle
  return angle

n, xa, xb = input().split()
n = int(n)
xa = int(xa)
xb = int(xb)

a = (xa, 0)
b = (xb, 0)

points = []
for i in range(n):
  x, y = input().split()
  p = (int(x), int(y))
  points.append( (calcAngle_A(a, p), calcAngle_B(b, p)) )

# print(points)

globalResp = 0
for i,p1 in enumerate(points):
  localResp = 0
  for j,p2 in enumerate(points):
    if (i!=j) and (p2[0] <= p1[0]) and (p2[1] <= p1[1]):
      localResp+=1
  globalResp = max(globalResp, localResp)

print(globalResp+1)