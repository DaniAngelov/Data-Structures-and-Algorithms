// github.com/DaniAngelov

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;



vector<int> vec;

class disjointSet
{
private:
    unordered_map<long long, long long> parent;

    long long currLastTree = 0;
public:
    void add(long long child)
    {
        parent[child] = currLastTree;
        currLastTree++;
    }
    int find(long long child)
    {
        if (child == parent[child])
            return child;

        long long root = find(parent[child]);
        parent[child] = root;
        return root;
    }

    void unite(long long a, long long b)
    {
        int firstTree = find(a);
        int secondTree = find(b);

        parent[firstTree] = secondTree;
    }

    void init(long long size)
    {
        for (int i = 0; i < size; i++)
        {
            add(i);
        }
    }
};

struct Pair
{
    long long index;
    long long distance;
};

struct Node
{
    list<Pair> neighbours;

    bool hasNeighbour(long long index)
    {
        for (auto neigh : neighbours)
        {
            if (neigh.index == index)
            {
                return true;
            }
        }
        return false;
    }

    void addNeighbour(long long index, long long distance)
    {
        neighbours.push_back(Pair{ index,distance });
    }
};


struct Edge
{
    long long from;
    long long to;
    long long weight;

    bool operator<(const Edge& rhs)const
    {
        return weight < rhs.weight;
    }
};

class Graph
{
private:
    vector<Node> nodes;

public:

    Graph(int nodesCount = 0)
    {
        nodes.resize(nodesCount);
    }

    void connect(long long from, long long to, long long distance)
    {

        nodes[from].addNeighbour(to, distance);
        nodes[to].addNeighbour(from, distance);

    }

    vector<Edge> findAllEdges()
    {

        vector<Edge> edges;
        for (int from = 0; from < nodes.size(); from++)
        {
            for (auto neigh : nodes[from].neighbours)
            {
                long long to = neigh.index;
                long long dist = neigh.distance;

                if (from < to)
                {
                    edges.push_back(Edge{ from,to,dist });
                }
            }
        }
        return edges;
    }

    void kruskal()
    {
        vector<Edge> AllEdges = findAllEdges();
        sort(AllEdges.begin(), AllEdges.end());

        disjointSet elements;
        elements.init(nodes.size());


        for (auto edge : AllEdges)
        {
            if (elements.find(edge.to) != elements.find(edge.from))
            {
                elements.unite(edge.from, edge.to);
            }
        }

        int queries;
        cin >> queries;

        int type;
        int road1;
        int road2;

        for (int i = 0; i < queries; i++)
        {
            cin >> type;

            cin >> road1 >> road2;

            if (type == 1)
            {

                if (elements.find(road1) != elements.find(road2))
                {
                    vec.push_back(0);

                }
                else
                {
                    vec.push_back(1);
                }
            }


            else if (type == 2)
            {
                if (elements.find(road1) != elements.find(road2))
                {
                    elements.unite(road1, road2);
                }

            }
        }
    }


};

int main()
{
    long long N;
    cin >> N;

    Graph g(N + 1);


    long long M;
    cin >> M;

    long long from, to, weight;

    for (int i = 0; i < M; i++)
    {
        cin >> from >> to;
        weight = 0;
        g.connect(from, to, weight);
    }

    g.kruskal();


    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
    }



    int _;
    cin >> _;
    return 0;
}
