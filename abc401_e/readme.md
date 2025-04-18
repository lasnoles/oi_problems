# Thinking Process
The problem is to figure out whether nodes are connected together after nodes are removed, and get the minimum number of nodes to remove.

### Step 1 Simplify the problem
#### how to figure out whether nodes are connected together? 
if nodes are reachable from the same root nodes, they can be considered connected together. 
Since the question wants the connection from node 1, 
we can consider the smallest number connectable to be the root.
now the problem is to find out the minimum number of the connected node.

#### how to find the least number of nodes to delete:
for any given u, from u+1 to N, if any nodes that have direct connection to (1,...k), it is the node we must delete.


### Step 2 Find the most applicable algorithm
The question needs to dynamically adjust root while adding edges. So the best algorithm is [Union Find](https://en.wikipedia.org/wiki/Disjoint-set_data_structure).
You may refer to the simplified explain below.

### Step 3 Optimisation
#### how to store the edges
since the question needs the output from 1 to N, for the given 1<=u<=N, we could gradually build up the Union Find Arrays. 
it is a good idea to have a data structure that naturally give me the adjacent nodes from index 1 to N.
So we choose vector<vector<int>> to store the input edges.

#### how to efficiently find out the count of the delete nodes:
while you are looping from 1 to k, 
- if any adjacent node of i is greater than k, and get introduced for the first time, your count++. 
- when you bring k+1 node edges into the Union Find, if this k+1 was counted before, you count--

### Step 4 generate the output out
With all those information, you can then achieve:
```
 int root = dsu.find(1);
 if (dsu.size[root] == u) {
        cout << nonZeros << '\n';
  } else {
        cout << "-1\n";
  }
```

# Union Find Simplified Explanation
- union find maintains two Arrays: 
   - array 1: if i is the root, it stores the value of i; if i is not the root, it stores the root index. 
   - array 2: if i is the root, it stores the number of nodes reachable from i.