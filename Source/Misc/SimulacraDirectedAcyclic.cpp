//
// Created by avsom on 3/6/2024.
//
#include <tuple>
#include <vector>

struct Node
{
    char                ID;
    std::vector<Node *> Dependencies;
    std::vector<Node *> Dependants;
};

void AddDependencies(Node &Dependant, Node &Dependency)
{
    Dependant.Dependencies.push_back(&Dependency);
    Dependency.Dependants.push_back(&Dependant);
}

void Test()
{
    std::vector<Node> NodeList;

    Node A{'a'};
    Node B{'b'};
    Node C{'c'};
    Node D{'d'};
    Node E{'e'};
    Node F{'f'};

    NodeList.push_back(A);
    NodeList.push_back(B);
    NodeList.push_back(C);

    

}


