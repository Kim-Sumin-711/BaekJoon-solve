#include <iostream>
#include <vector>
#include <unordered_map>

using Graph = std::vector<std::unordered_map<int, int>>;

void set_bus_roads(Graph& map, int bus_cnt) {
    int start, end, time;
    while (bus_cnt--) {
        std::cin >> start >> end >> time;
        if (map[start].find(end) == map[start].end())
            map[start].insert({end, time});
        else if (map[start][end] > time)
            map[start][end] = time;
    }
}

bool check_negative_cycle(const Graph& map, std::vector<long>& dist, const int node_cnt) {
    for (int current_node = 1; current_node < node_cnt + 1; current_node++) {
        if(dist[current_node] == dist[0]) continue;
        for (const std::pair<int, int>& bus_info : map[current_node]) {
            int next_stop = bus_info.first;
            int cost = bus_info.second;
            if (dist[next_stop] > dist[current_node] + cost)
                return true;
        }
    }
    return false;
}

bool belman_ford(const Graph& map, std::vector<long>& dist, const int node_cnt) {
    for(int loop = 0 ; loop < node_cnt ; loop++) {
        for (int current_node = 1; current_node < node_cnt + 1; current_node++) {
            if(dist[current_node] == dist[0]) continue;
            for (const std::pair<int, int>& bus_info : map[current_node]) {
                int next_stop = bus_info.first;
                int cost = bus_info.second;
                if (dist[next_stop] > dist[current_node] + cost)
                    dist[next_stop] = dist[current_node] + cost;
            }
        }
    }

    bool negative_cycle = check_negative_cycle(map, dist, node_cnt);
    if (negative_cycle) return false;
    else return true;

}

void print_answer(const std::vector<long>& dist, const int node_cnt) {
    for (int node = 2; node < node_cnt + 1; node++) {
        if (dist[node] == 2100000000) std::cout << -1 << "\n";
        else std::cout << dist[node] << "\n";
    }
}

void sol(const int node_cnt, const int bus_cnt) {
    // index -> node_num except 0
    Graph map(node_cnt + 1);

    //set dist vec
    long INF = 2100000000;
    std::vector<long> dist(node_cnt + 1, INF);
    dist[1] = 0;

    set_bus_roads(map, bus_cnt);

    bool shortest_pathes_present = belman_ford(map, dist, node_cnt);
    if (shortest_pathes_present) print_answer(dist, node_cnt);
    else std::cout << "-1\n";

}

int main(void) {
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    int node_cnt, bus_cnt;
    std::cin >> node_cnt >> bus_cnt;
    sol(node_cnt, bus_cnt);
    return 0;
}