Hi Team,

I've just pushed my implementation of Tarjan's algorithm for detecting cycles into our TransactionGraph class. Here's a brief overview of what I've done:

Implemented detectCycles() Method:
The method uses Tarjan's algorithm to find strongly connected components (SCCs) in the graph, which helps us identify cycles indicative of potential money laundering patterns.
I converted the recursive strongConnect function into a member function to avoid using std::function and the <functional> header, as we wanted to minimize extra dependencies.

Class Member Variables:
Moved variables like index, indexes, lowlink, Nstack, onStack, and cycles to be member variables of the class.
This allows strongConnect to access them directly without needing to pass them around.
        
In terms of testing I just ran through debugger and did the best I could to really debug all of my syntax errors, but feel free to check.

What I would say our next steps are is to just review code, and to just test with syntetic data!

Let me know if there's anything else you'd like me to add or modify.
