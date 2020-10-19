# Graph Theory

## Index
* [Types of graphs](#types-of-graphs)

## Types of graphs
1. **Complete Graph**
    * *Definition:* A graph in which every pair of vertices is joined by exactly one edge
    * *Number of vertices:* `n * (n - 1) / 2`
2. **Regular Graph**
    * *Definition:* A Regular graph is a graph in which degree of all the vertices is same. If the degree of all the vertices is k, then it is called k-regular graph.
    * *Tips:* A complete graph must be a regular graph.
3. **Bipartite Graph**
    * *Definition:* A bipartite graph is a graph in which the vertex set can be partitioned into two sets such that edges only go between sets, not within them.
4. **Complete Bipartite Graph**
    * *Definition:* A complete bipartite graph is a bipartite graph in which each vertex in the first set is joined to each vertex in the second set by exactly one edge.
5. **Star Graph**
    * *Definition:* A star graph is a complete bipartite graph in which `n-1` vertices have degree `1` and a single vertex have degree `(n -1)`.
6. **Planar Graph**
    * *Definition:* A planar graph is a graph that we can draw in a plane in such a way that no two edges of it cross each other except at a vertex to which they are incident.
