a, b, c = input().split()
a = int(a)
b = int(b)
c = int(c)

if (a+b==c) or (a+c==b) or (b+c==a) or (a==b) or (a==c) or (b==c):
  print('S')
else:
  print('N')