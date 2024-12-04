The purpose of the code in this repo is to verify the validity
of each part that will be used in our SFML GUI exe. The current
setup in main is meant to test whether Tarjan's algorithm and 
Union Find algorithm find the same source node for their cycles. 
I have concluded through testing that when the printed source 
nodes are different there is no actual cycle in the graph, 
thankfully this detail is taken care of in the SFML GUI though.

