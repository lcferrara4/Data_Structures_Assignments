Reading 11
==========

1. What problem is the Google File System trying to solve? GFS was created to solve 3 main problems: it needed to anticipate and deal with component failures, handle exceptionally large files, and optimize appending of data.

	* How does it solve the problem? It solves the problem of component failures, by using cheap hardware in anticipation that it will break anyway but keeping multiple copies of the data on different chunkservers for reliability. Optimization of appending data is done by using large chunk sizes and a system in which the client only needs to contact the master to request the chunk location information and then can read and write directly to the chunkserver. The problem of large files and the potentiality for hot spots due to this was fixed by storing executables with a higher replication factor and making the batch-queue system stagger application start times so that the same application can't be run on the same server by many clients at once.

	* Describe how data is stored in Google File System. A GFS cluster has a single master and multiple chunkservers accessed by multiple chunk clients. Files are divided into fixed-size chunks. Each chunk is given a 64 bit unique chunk handle assigned by the master. These are stored by chunkservers on local disks as Linux files. Each chunk is replicated on multiple chunkservers for back ups (3 replicas by default). The master contains all file system metadata, like access control info, mapping of files to chunks, etc.

	* Based on what you read, describe some data structures or algorithms that would be used in Google File System. GFS would need a hashmap to store for the master to keep a mapping of chunk handle to chunk index and filename. The master also needs to keep in memory which chunks each chunkserver has. For this, it may use a mapping of server to a linked list of chunks. The linked list would help with easy insertion and deletion of chunks. In addition the master gets information about operations from chunkservers in the form of a compact B-Tree like form to speed up recovery and availability of the data.

2. What problem is Map-Reduce trying to solve? It tries to simplify the complexity created by running fairly simple special-purpose computations on such large amounts of raw data that the computations need to be distributed across machines in order to finish in a reasonable amount of time.

	* How does it solve this problem? It standardizes these computations into an abstraction that consists of map and reduce steps, which are customized by the user, but that have the methods for parallelizing the compuations, distributing the data, and re-executing for fault tolerance built in.

	* Describe the three phases of a typical Map-Reduce workflow.

		1. Map = (written by user) Takes an input pair and produces a set of intermediate key/value pairs

		2. Combiner = Groups together all intermediate values with the same intermediate key I and passes to Reduce

		3. Reduce = (written by user) Accepts intermediate key I and a set of values for that key. It merges these value to form a possibly smaller set of values. 

	* Based on what you read, describe some data structures or algorithms that would be used in Map-Reduce. Map-Reduces needs hashmaps to keep track of the mappings of key/value pairs. It also needs set to store the hashsets (or mapping of key to list) made by the intermediate grouping phase. Some type of sorting and then grouping algorithm is needed to do the intermediate grouping step. Data structures are also used by the master to map the map and reduced task to its state and identity of the worker machine used.
