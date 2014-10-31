#!/usr/bin/python3
def nCk(n, k):
  if k > n: return 0
  res = 1
  for i in range(1, min(n - k, k) + 1):
    res = res * (n - i + 1) // i
  return res

def max_foods(D, A, B):
  cnt = 0
  for L in range(min(51, D // B + 1)):
    K_min = (D - L * B - B) // A + 1
    K_max = (D - L * B) // A
    cnt += nCk(K_max + L + 1, L + 1) - nCk(K_min + L, L + 1)
  return cnt

def min_days(N, A, B):
  lo = 0
  hi = int(1e15)
  while lo < hi:
    D = (lo + hi) // 2
    if max_foods(D, A, B) >= N:
      hi = D
    else:
      lo = D + 1
  return lo

for tc in range(int(input())):
  print("Case #%d: %d" % (tc+1, \
    min_days(*map(int, input().split()))))

