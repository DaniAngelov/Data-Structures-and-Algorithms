// github.com/DaniAngelov

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

long long sum = 0;

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
        
            nodes[from].addNeighbour(to,distance);
            nodes[to].addNeighbour(from,distance);
        
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

    list<Edge> kruskal()
    {
        vector<Edge> AllEdges = findAllEdges();
        sort(AllEdges.begin(), AllEdges.end());

        disjointSet elements;
        elements.init(nodes.size());

        list<Edge> tree;

        for (Edge edge : AllEdges)
        {
            if (elements.find(edge.from) != elements.find(edge.to))
            {
                tree.push_back(edge);
                elements.unite(edge.from, edge.to);
                
            }
        }

        return tree;
    }
};

int main()
{
    long long N;
    cin >> N;

    Graph g(N);


    long long M;
    cin >> M;

    long long from, to, weight;

    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> weight;

        g.connect(from, to, weight);
    }


    list<Edge> tree = g.kruskal();
    

    for (Edge edge : tree)
    {
        sum += edge.weight;
    }

    cout << sum << endl;


    int _;
    cin >> _;
    return 0;
