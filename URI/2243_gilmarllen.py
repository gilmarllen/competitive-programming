def check_diagonal(h, column, alt):
  if (alt > column+1) or (alt > len(h)-column) :
    return False

  aux = alt
  for i in range(aux):
    if h[column+i]<alt-i or h[column-i]<alt-i:
      return False

  return True

n = int(input())
h = [int(x) for x in input().split()]

h_max = 0
for i, curr_h in enumerate(h):
  if check_diagonal(h, i, h_max+1):
    h_max+=1
  # print(str(i)+':'+str(h_max)+':'+str(h[i]))

print(h_max)