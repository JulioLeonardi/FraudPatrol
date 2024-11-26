//
// Created by jalg0 on 11/24/2024.
//

#ifndef TRANSACTIONGRAPH_H
#define TRANSACTIONGRAPH_H
#include <random>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class TransactionGraph {
    unordered_map<int, vector<int>> adjacencyList;
    int nodeNum;
    int cycleNum; // code will have at least cycleNum cycles, cycle generation may add more
    int edgeNum;
    int minCycleSize;
    int maxCycleSize;

public:
    TransactionGraph(int cn, int nm, int en, int mincs, int maccs) {
        cycleNum = cn;
        nodeNum = nm;
        edgeNum = en;
        minCycleSize = mincs;
        maxCycleSize = maccs;
        makeGraph();
    }

    // src for random generation: https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
    void makeGraph() {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<int> node(1, nodeNum);

        int edgesAdded = 0;
        while (edgesAdded < edgeNum) {
            int u = node(rng);
            int v = node(rng);

            if (u != v) {
                auto& neighbors = adjacencyList[u];
                if (find(neighbors.begin(), neighbors.end(), v) == neighbors.end()) {
                    adjacencyList[u].emplace_back(v);
                    edgesAdded++;
                }
            }
        }

        set<int> addedNodes;
        int cyclesAdded = 0;

        while (cyclesAdded < cycleNum) {
            int source;
            do {
                source = node(rng);
            } while (addedNodes.find(source) != addedNodes.end());

            addCycle(source);
            cyclesAdded++;

            set<int> cycleNodes;
            int curNode = source;
            do {
                cycleNodes.insert(curNode);
                curNode = adjacencyList[curNode].back();
            } while (curNode != source);

            addedNodes.insert(cycleNodes.begin(), cycleNodes.end());
        }
    }

    void addCycle(int source) {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<std::mt19937::result_type> cs(minCycleSize, maxCycleSize);

        int size = cs(rng);

        set<int> cycleNodes;
        cycleNodes.insert(source);

        int past = source;
        int cur;

        for (int i = 0; i < size-1; i++) {
            uniform_int_distribution<std::mt19937::result_type> node(1, nodeNum);
            cur = node(rng);

            while (cycleNodes.find(cur) != cycleNodes.end() || cur == past) {
                cur = node(rng);
            }

            adjacencyList[past].emplace_back(cur);
            cycleNodes.insert(cur);
            past = cur;
        }

        adjacencyList[past].emplace_back(source);
    }

    
    
    
    // Tarjan's Algorithm to detect cycles
    vector<vector<int>> detectCycles() {
        // Initialize variables
        index = 0;
        indexes.clear();
        lowlink.clear();
        onStack.clear();
        while (!Nstack.empty()) {
            Nstack.pop();
        }
        cycles.clear();

        // DFS for all unvisited nodes
        for (auto& nodepair : adjacencyList) {
            int node = nodepair.first;
            if (indexes.find(node) == indexes.end()) {
                strongConnect(node);
            }
        }

        // Checks for self-loops
        auto selfloop = [&](int node) {
            for (int neighbor : adjacencyList[node]) {
                if (neighbor == node) {
                    return true;
                }
            }
            return false;
        };

        // Filter SCCs to get cycles
        vector<vector<int>> cycleList;
        for (auto& SCC : cycles) {
            if (SCC.size() > 1 || selfloop(SCC[0])) {
                cycleList.push_back(SCC);
            }
        }
        return cycleList;
    }

    // Member function for Tarjan's strong connect
    void strongConnect(int node) {
        indexes[node] = index;
        lowlink[node] = index;
        index++;
        Nstack.push(node);
        onStack[node] = true;

        // Finding all successors of the node
        for (int neighbor : adjacencyList[node]) {
            // If neighbor is not yet indexed, then we need to recurse on it
            if (indexes.find(neighbor) == indexes.end()) {
                strongConnect(neighbor);
                lowlink[node] = min(lowlink[node], lowlink[neighbor]);
            } else if (onStack[neighbor]) {
                // Update the lowlink value if neighbor is in the stack
                lowlink[node] = min(lowlink[node], indexes[neighbor]);
            }
        }

        // If node is a root node, pop the stack and make a strongly connected component
        if (lowlink[node] == indexes[node]) {
            vector<int> component;
            int curNode;
            do {
                curNode = Nstack.top();
                Nstack.pop();
                onStack[curNode] = false;
                component.push_back(curNode);
            } while (curNode != node);
            cycles.push_back(component);
        }
    }






    unordered_map<int, vector<int>> getGraph() {
        return adjacencyList;
    }

};
#endif //TRANSACTIONGRAPH_H
