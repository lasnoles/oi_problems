# Problem Source
https://atcoder.jp/contests/abc401/tasks/abc404_d

# Thinking Process
The problem is trying to find the minimum cost of visiting the zoo so that I can see all animal from 1 to M minimum two times. 

There is a trick in this problem statement, the N is from 1 to 10, which could mean that we maybe able to use brutal force approach.

from the first look, for each zoo, we would vist it 0/1/2 times,

initially we have an array, with index 0 indicating the fee spend, and from index 1 onward, put all animals (two times) to visit with number ascending, 
````python
N, M = map(int, sys.stdin.readline().split())

cost = list(map(int, sys.stdin.readline().split()))
zoo = [[] for _ in range(N)]
for i in range(1, M+1):
    sAni = sys.stdin.readline().split()
    for j in range(1, len(sAni)):
        z = int(sAni[j])
        zoo[z-1].append(i)

to_visit =[0]  # store the fee spent

for i in range(1, M+1):
    to_visit.append(i)
    to_visit.append(i)

to_visits = [copy.deepcopy(to_visit)] #initialize the animal to visit
````

and we start to visit zoo, each time we visit, we will remove the seen animal from the array util there is only index 0 element, we found a solution. the cost should be index 0 element.

````python
min_fee = 10**100
def min_cost(to_visits, i):
    global min_fee
    if i >= N:
        return
    
    for si in range(len(to_visits)-1, -1, -1):
        if len(to_visits[si]) == 1:  #found solution
            if to_visits[si][0] < min_fee:
                min_fee = to_visits[si][0]
            del to_visits[si]
        else:
            cp = copy.deepcopy(to_visits[si])
            remove_a(cp, zoo[i])  #visit it once
            cp[0] += cost[i]
            to_visits.append(copy.deepcopy(cp))

            remove_a(cp, zoo[i])
            cp[0] += cost[i]  #visit it two times
            to_visits.append(copy.deepcopy(cp))
    min_cost(to_visits, i + 1)
````
