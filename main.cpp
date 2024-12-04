#include <iostream>
#include <utility>
#include "TransactionGraph.h"

using namespace std;

int main() {
    TransactionGraph example(10000, 500000); // node number, min edge number, additional cycles, min cycle length, max cycle length
    auto exampleGraph = example.getGraph();

    TarjanCycle exampleTarjan(exampleGraph);
    exampleTarjan.detectCycles();
    cout << "Tarjan Cycle Source: " << exampleTarjan.detectCycleSourceNode() << endl;

    UnionFindCycle exampleUnionFind(exampleGraph);
    exampleUnionFind.detectCycles();
    cout << "Union Cycle Source: " << exampleUnionFind.detectCycleSourceNode() << endl;

    return 0;
}
