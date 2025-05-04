import copy
import sys
def remove_a(state, anis):
    for j in range(len(anis) - 1, -1, -1):
        for k in range(len(state)-1, 0, -1):
            if anis[j] == state[k]:
                del state[k]
                break
def min_cost(to_visits, i):
    global min_fee
    if i >= N:
        return
    for si in range(len(to_visits)-1, -1, -1):
        if len(to_visits[si]) == 1:
            if to_visits[si][0] < min_fee:
                min_fee = to_visits[si][0]
            del to_visits[si]
        else:
            cp = copy.deepcopy(to_visits[si])
            remove_a(cp, zoo[i])
            cp[0] += cost[i]
            to_visits.append(copy.deepcopy(cp))

            remove_a(cp, zoo[i])
            cp[0] += cost[i]
            to_visits.append(copy.deepcopy(cp))
    min_cost(to_visits, i + 1)

min_fee = 10**100
N, M = map(int, sys.stdin.readline().split())

cost = list(map(int, sys.stdin.readline().split()))
zoo = [[] for _ in range(N)]
for i in range(1, M+1):
    sAni = sys.stdin.readline().split()
    for j in range(1, len(sAni)):
        z = int(sAni[j])
        zoo[z-1].append(i)

to_visit =[0]

for i in range(1, M+1):
    to_visit.append(i)
    to_visit.append(i)

to_visits = [copy.deepcopy(to_visit)]

min_cost(to_visits, 0)

for si in range(len(to_visits) - 1, -1, -1):
    if len(to_visits[si]) == 1:
        if to_visits[si][0] < min_fee:
            min_fee = to_visits[si][0]
print(min_fee)
