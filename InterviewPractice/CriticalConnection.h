#include <unordered_map>

using namespace std;
class CriticalConnection {

protected:
	
    std::unordered_map<int, vector<int>> adj;
	
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFS(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& bridge)
    {
        static int time = 0; // timestamp to know the ordering
        disc[u] = low[u] = time; // discovered and low values for nodes to find back edges
        time += 1;

        for (int v : adj[u])
        {
            if (disc[v] == -1) // if v is not visited
            {
                parent[v] = u;
                DFS(v, disc, low, parent, bridge);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u])
                    bridge.push_back({ u, v });
            }
            else if (v != parent[u]) // ignore child to parent edge
                low[u] = min(low[u], disc[v]);
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>> criticalConnections;

    	// create graph
        for (int i = 0; i < connections.size(); i++)
        {
            addEdge(connections[i][0], connections[i][1]);
        }

        vector<int> disc(n, -1), low(n, -1), parent(n, -1);

    	// for each edge
        for (int i = 0; i < n; i++)
        {
            if (disc[i] == -1) // perform dfs and see if there is only one component
                DFS(i, disc, low, parent, criticalConnections);
        }


        return criticalConnections;
    }

	void printCriticalConnections(int n, vector<vector<int>>& connections)
    {
        printf("N: %i\nConnections: [", n);
    	for (auto& conn : connections)
    	{
            printf("[");
    		for (auto& port : conn)
    		{
                printf("%i ", port);
    		}
            printf("] ");
    	}
        printf("]\n");

        auto result = criticalConnections(n, connections);

        printf("Result: [", n);
        for (auto& conn : result)
        {
            printf("[");
            for (auto& port : conn)
            {
                printf("%i ", port);
            }
            printf("] ");
        }
        printf("]\n\n");
    }
};
