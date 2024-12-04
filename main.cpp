#include <iostream>
#include "TransactionGraph.h"

using namespace std;

int main() {
    TransactionGraph example(10, 0); // node number, edge number, additional cycles, min cycle length, max cycle length
    auto exampleGraph = example.getGraph();

    TarjanCycle exampleTarjan(exampleGraph);
    exampleTarjan.detectCycles();
    cout << "Tarjan Cycle Source: " << exampleTarjan.detectCycleSourceNode() << endl;

    UnionFindCycle exampleUnionFind(exampleGraph);
    bool found = exampleUnionFind.detectCycles();
    cout << "Union Cycle Source: " << exampleUnionFind.detectCycleSourceNode() << endl;
    cout << (found? "Yeah" : "Nah") << endl;

    return 0;
}
