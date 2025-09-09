#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>

using Graph = std::vector<std::unordered_map<int, int>>;

void set_roads(Graph& city_map, int road_cnt) {
    int start, end, time;
    while (road_cnt--) {
        std::cin >> start >> end >> time;
        if (city_map[start].find(end) != city_map[start].end())
            city_map[start][end] = std::min(city_map[start][end], time);
        else city_map[start][end] = time;
        if (city_map[end].find(start) != city_map[end].end())
            city_map[end][start] = std::min(city_map[end][start], time);
        else city_map[end][start] = time;
    }
}

void set_wormholes(Graph& city_map, int wormhole_cnt) {
    int start, end, time;
    while (wormhole_cnt--) {
        std::cin >> start >> end >> time;
        city_map[start][end] = -1 * time;
    }
}

void set_city_map(Graph& city_map, int road_cnt, int wormhole_cnt) {
    set_roads(city_map, road_cnt);
    set_wormholes(city_map, wormhole_cnt);
}

void set_clustering_vec_and_max_clustering_num(std::vector<int>& clustering_vec, int& max_clustering_num,
                                               Graph& city_map, int node_cnt) {
    std::vector<bool> visit(node_cnt + 1);
    visit[0] = true;
    int clustering_num = 0;
    std::queue<int> next_nodes;
    for (int n = 1; n < node_cnt + 1; n++) {
        if (visit[n]) continue;
        clustering_vec[n] = ++clustering_num;
        next_nodes.push(n);

        while (!next_nodes.empty()) {
            int now = next_nodes.front();
            next_nodes.pop();
            visit[now] = true;
            for (const std::pair<int, int>& next : city_map[now]) {
                if (visit[next.first]) continue;
                visit[next.first] = true;
                clustering_vec[next.first] = clustering_num;
                next_nodes.push(next.first);
            }
        }
    }
    max_clustering_num = clustering_num;
}

bool check_negative_circle(const Graph& city_map, const std::vector<int>& clustering_vec, const int max_clustering_num, const int node_cnt) {
    int INF = 2100000000;
    for (int cluster_num = 1; cluster_num < max_clustering_num + 1; cluster_num++) {
        std::vector<int> nodes_in_a_cluster;
        for (int node = 1; node < node_cnt + 1; node++) {
            if (clustering_vec[node] == cluster_num) nodes_in_a_cluster.push_back(node);
        }

        std::unordered_map<int, int> dist;
        for (int node : nodes_in_a_cluster) {
            dist[node] = INF;
        }

        dist[nodes_in_a_cluster[0]] = 0;

        for (int loop = 0; loop < nodes_in_a_cluster.size(); loop++) {
            for (int node : nodes_in_a_cluster) {
                if (dist[node] == INF) continue;
                for (const std::pair<int, int>& road_or_wormhole : city_map[node]) {
                    int next_node = road_or_wormhole.first;
                    int cost = road_or_wormhole.second;
                    dist[next_node] = std::min(dist[node] + cost, dist[next_node]);
                }
            }
        }

        for (int node : nodes_in_a_cluster) {
            for (const std::pair<int, int>& road_or_wormhole : city_map[node]) {
                int next_node = road_or_wormhole.first;
                int cost = road_or_wormhole.second;
                if (dist[node] + cost < dist[next_node]) return true;
            }
        }
    }
    return false;
}

void sol() {
    int node_cnt, road_cnt, wormhole_cnt;
    std::cin >> node_cnt >> road_cnt >> wormhole_cnt;

    Graph city_map(node_cnt + 1);
    set_city_map(city_map, road_cnt, wormhole_cnt);

    std::vector<int> clustering_vec(node_cnt + 1);
    int max_clustering_num;
    set_clustering_vec_and_max_clustering_num(clustering_vec, max_clustering_num, city_map, node_cnt);

    bool negative_circle_detected = check_negative_circle(city_map, clustering_vec, max_clustering_num, node_cnt);

    if (negative_circle_detected) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main(void) {
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    int TC;
    std::cin >> TC;
    while (TC--) {
        sol();
    }
    return 0;
}
