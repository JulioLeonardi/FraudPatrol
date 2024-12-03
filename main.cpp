#include <iostream>
#include <utility>
#include "TransactionGraph.h"

using namespace std;

int main() {
    TransactionGraph example(5, 100000, 200000, 1, 100); // additional cycles, node number, edge number, min cycle length, max cycle length
    auto exampleGraph = example.getGraph();

    for (auto i: exampleGraph) {
        for (auto j: i.second) {
            cout << i.first << " " << j <<endl;
        }
    }


    return 0;

}
