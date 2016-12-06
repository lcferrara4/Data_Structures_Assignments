Reading 10
==========

1. 	Definitions:

	* Topological Sorting = Given a digraph, a topological sort puts the vertices in order such that all its directed edges point from a vertex earlier in the order to a vertex later in the order (or report thtat doing so is not possible).

	* Single-source Shortest Path = Given an edge-weighted digraph and a designated source vertex s, a single-source shortest path is the path to another vertex such that no other path has a lower weight.

	* Minimum Spanning Tree = Given an edge weighted graph, a minimum spanning tree (MST) is a spanning tree, which is a series of edges that connect every vertex in a graph, whose weight (sum of the weights of its edges) is no larger than the weight of any other spanning tree.
  
	Real world applications:

	* Topological Sorting: Anything where ordering is very important. Examples: course prerequisites, order in which to compile components of a large computer program, pipeline of computing job, class inheritance, deadlocking detection, etc.

	* Single-source Shortest Path: This has applications in computer networking/routing, Google maps shortest route, data retrieval over server network, etc.

	* Minimum Spanning Tree: MSTs are useful for minimizing costs in network design, for example in phone networks, electrical, cable, and road design. They can also be used to approximately solve some NP-hard problems, such as the traveling salesman problem.

2. Is it possible to have more than one:

	* Topological Sorting? Yes. Vertices can be ordered so that all directed edges point right in multiple ways. For example, if a graph has 3 nodes, A, B, and C, where A has an edge that points to B and an edge that points to C, but there are no other edges in the graph, A would have to be placed first in the topological sort but then the positioning of B and C doesn't matter.

	* Single-source Shortest Path? Yes. Shortest paths are not necessarily unique. There may be multiple paths of the lowest weight from one vertex to another. Choosing any one of them is acceptable.
	
	* Minimum Spanning Tree? Yes. If any of the edge weights are the same, it is possible that the minimum spanning tree is not unique.

3. Using algorithms on the graphs:

	* Kahn's Algorithm for Topological Sorting:

	Graph 0: A, C, B, E, D, F
	Graph 1: B, A, D, E, C
	Graph 2: A, C, B, D, E, F
	Graph 3: A, D, C, B, E

	* Dijkstra's Algorithm for Shorest Path from A to every other node:

	Graph 0:
	(A, C)
	(C, B)
	(C, E)
	(D, F)
	(E, D)

	Graph 1:
	(A, C)

	Graph 2:
	(A, B)
	(A, C)
	(B, D)
	(C, E)
	(D, F)
	
	Graph 3:
	(A, B)
	(A, C)
	(B, E)
	
	* Prim's Algorithm for Minimum Spanning Tree:

	Graph 0:
	(A, C)
	(B, C)
	(C, E)
	(D, E)
	(D, F)
	
	Graph 1:
	(A, B)
	(B, D)
	(D, E)
	(C, E)
	
	Graph 2:
	(A, B)
	(B, C)
	(C, D)
	(D, E)
	(D, F)

	Graph 3:
	(A, B)
	(B, C)
	(C, E)
	(D, E)
