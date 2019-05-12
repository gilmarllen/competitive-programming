
def isVogal(c):
  return (c=='a') or (c=='e') or (c=='i') or (c=='o') or (c=='u')

ent = input()

ent = ''.join([x for x in list(ent) if isVogal(x)])

if ent == ent[::-1]:
  print('S')
else:
  print('N')