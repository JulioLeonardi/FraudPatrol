#include <iostream>
#include <utility>
#include "TransactionGraph.h"

using namespace std;

int main() {
    TransactionGraph example(20, 100, 5, 5, 5); // node number, min edge number, additional cycles, min cycle length, max cycle length
    auto exampleGraph = example.getGraph();

    cout << "Node Count: " << exampleGraph.size() << endl;
    //cout << "Edges: " << endl;

    int edgecnt = 0;
    for (auto i: exampleGraph) {
        for (auto j: i.second) {
            //cout << i.first << " -> " << j <<endl;
            edgecnt++;
        }
    }

    cout << "Edge Count:" << edgecnt << endl;

    TrajanCycle exampleTrajan(exampleGraph);
    exampleTrajan.detectCycles();
    cout << "Trajan Cycles Found: " << exampleTrajan.getCycleNumber() << endl;

    UnionFindCycle exampleUnionFind(exampleGraph);
    exampleUnionFind.detectCycles();
    cout << "Union Find Cycles Found:" << exampleUnionFind.getCycleNumber() << endl;

    return 0;
}
