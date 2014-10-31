def dfs(i, removed, visited):
  visited.add(i)
  for j in range(len(prefer[i])):
    if prefer[i][j] == 'Y':
      if j not in visited and j not in removed:
        dfs(j, removed, visited)


def valid(partial):
  B = partial[0]
  for i in partial:
    if prefer[i][B] == 'Y':
      B = i

  removed = set(partial)
  removed.remove(B)

  # Trivial case.
  if A in removed: return False

  # Case (i)
  if A == B:
    for i in range(N):
      if i != A and i not in removed:
        if prefer[A][i] != 'Y':
          return False
    return True

  # Case (ii)
  visited = set([B])
  dfs(A, removed, visited)
  for i in range(len(prefer[B])):
    if prefer[B][i] == 'Y':
      visited.add(i)
  return len(visited.union(removed)) == N


def solve():
  visited = set()
  dfs(A, set(), visited)
  if len(visited) != N: return "IMPOSSIBLE"

  partial = []
  for i in range(N):
    for j in range(N):
      if j not in partial and valid(partial + [j]):
        partial = partial + [j]
        break
  return ' '.join(map(str, partial))


for tc in range(int(input())):
  [N, A] = map(int, input().split())
  prefer = []
  for i in range(N):
    prefer.append(input())
  print("Case #%d: %s" % (tc + 1, solve()))

