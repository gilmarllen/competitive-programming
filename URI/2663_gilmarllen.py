n = int(input())
k = int(input())

rank = []
for x in range(n):
  rank.append( int(input()) )

# print (rank)
rank = sorted(rank, reverse=True)
# print (rank)

resp = 0
limit = rank[k-1]
for x in rank:
  if x>=limit:
    resp+=1

print(resp)