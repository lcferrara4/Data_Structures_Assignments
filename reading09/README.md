Reading 09
==========

1. Graphs:

	A. Connected = Graph with a path from every vertex to every vertex 

	B. Acyclic = Graph with no cycles (path whose first and last vertices are the same)
 
	C. Directed = Finite set of vertices together with a finite set of edges
	
	D. Simple = Graphs that have no loops and no multiple edges
	
	E. Weighted = Graphs whose edges have weights

2. Adjacency:

A.
 
Graph 0 - Adjacency Matrix:
   A B C
A: 0 1 1
B: 0 0 0
C: 0 1 0

Graph 0 - Adjacency List:
A: B C
B:
C: B

Graph 1 - Adjacency Matrix:
   A B C D
A: 0 1 0 1
B: 1 0 0 0
C: 1 0 0 0
D: 0 1 1 1

Graph 1 - Adjacency List:
A: B D
B: A
C: A
D: B C D

Graph 2 - Adjacency Matrix:
   A B C D
A: 0 1 1 1
B: 1 0 1 1
C: 1 1 0 1
D: 1 1 1 0

Graph 2 - Adjacency List:
A: B C D
B: A C D
C: A B D
D: A B C

Graph 3 - Adjacency Matrix:
   A B C D
A: 0 0 0 0
B: 0 0 0 1
C: 0 0 0 1
D: 0 1 1 0

Graph 3 - Adjacency List:
A:
B: D
C: D
D: B C

B. An adjacncy matrix is easier to implement and easier to use than the list. They are efficient for adding/removing edges and for checking whether a particular edge is present.

C. Adjacency lists are better for iterating a loop that executes one time for each edge with a particular source vertex i.

3. Depth-first search:

A. 

void traversal(Graph &g, const string &s) {
    stack<string> q;
    set<string>   v;

    typedef std::map<std::string, std::set<string>>::iterator it_type;
    for(it_type iterator = m.begin(); iterator != m.end(); iterator++) {
	for( auto f : *it->second ){
		if( v.find(f) == v.end()){
			q.push(f);
			v.insert(f);
		}	
	}
    }

    while (!q.empty()) {
    	cout << q->first << endl;
	q.pop();
   }
}

B. The stack is used to process every node of the graph. Adding unmarked nodes to the stack and then doing something with them.

C. The set is used to check if the node of the graph has been seen already.

D. In a breadth first search, we'd have to change how we push elements onto the stack. Instead of going through the entire adjacency list, we would want to follow down until the end and then come back to the next element of the adjacency list.
