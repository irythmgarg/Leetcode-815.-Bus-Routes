class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // Map each stop to all bus routes that include it
        unordered_map<int, vector<int>> mp;

        // If source and target are the same, no buses are needed
        if (source == target) return 0;

        // Fill the map with stop -> list of bus routes
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i])
                mp[stop].push_back(i);
        }

        unordered_set<int> visited; // To keep track of visited bus routes
        queue<int> q; // BFS queue for bus routes

        // Initialize the queue with all bus routes passing through the source stop
        for (int bus : mp[source]) {
            q.push(bus);
            visited.insert(bus);
        }

        int buses = 1; // Count of buses taken

        // Perform BFS on the bus routes
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int bus = q.front(); q.pop();

                // Check all stops of the current bus route
                for (int stop : routes[bus]) {
                    // If we reach the target stop, return the number of buses taken
                    if (stop == target) return buses;
                }

                // Traverse all connecting bus routes via current bus stops
                for (int stop : routes[bus]) {
                    for (int nextBus : mp[stop]) {
                        if (!visited.count(nextBus)) {
                            visited.insert(nextBus);
                            q.push(nextBus);
                        }
                    }
                }
            }
            buses++; // Increment bus count at each BFS level
        }

        // If destination is unreachable
        return -1;
    }
};
