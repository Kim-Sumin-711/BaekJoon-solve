#include<iostream>
#include<vector>
#include<queue>
using Matrix = std::vector<std::vector<int>>;
using Vec_int = std::vector<int>;
using Queue_Vec_int = std::queue<Vec_int>;

void set_tomato_map(Matrix& map, Matrix& res, const int& row, const int& col) {
    for (int r = 0; r < row;r++) {
        for (int c = 0; c < col; c++) {
            std::cin >> map[r][c];
            if (map[r][c] == -1)
                res[r][c] = 0;
        }
    }
}

Matrix get_next_tomato_and_set_res(const Matrix& map, Matrix& res, const Vec_int& target, const int& r_size, const int& c_size, const int& day) {
    int tr = target[0], tc = target[1];
    Matrix next;
    //up
    if (tr - 1 >= 0 && res[tr-1][tc] != 0) {
        if (res[tr - 1][tc] > day || res[tr-1][tc] == -1) {
            next.push_back({ tr - 1,tc });
            res[tr - 1][tc] = day;
        }
    }
    //down
    if (tr + 1 < r_size && res[tr+1][tc] != 0) {
        if (res[tr + 1][tc] > day || res[tr + 1][tc] == -1) {
            next.push_back({ tr + 1,tc });
            res[tr + 1][tc] = day;
        }
    }
    //left
    if (tc - 1 >= 0 && res[tr][tc-1] != 0) {
        if (res[tr][tc - 1] > day || res[tr][tc - 1] == -1) {
            next.push_back({ tr,tc - 1 });
            res[tr][tc - 1] = day;
        }
        
    }
    //right
    if (tc + 1 < c_size && res[tr][tc+1] != 0) {
        if (res[tr][tc + 1] > day || res[tr][tc + 1] == -1) {
            next.push_back({ tr,tc + 1 });
            res[tr][tc + 1] = day;
        }
    }
    return next;
}

void ripe(const Matrix& map, Matrix& res, const Matrix& start_spots, const int& r_size, const int& c_size) {
    Queue_Vec_int tomato_queue;
    for (const Vec_int& start_spot : start_spots) {
        int tr = start_spot[0], tc = start_spot[1];
        res[tr][tc] = 0;
        tomato_queue.push(start_spot);
    }
    int day = 1;
    Matrix tmp;
    while (true) {
        while (tomato_queue.size() != 0) {
            Vec_int now_tomato = tomato_queue.front();
            tomato_queue.pop();
            tmp.push_back(now_tomato);
        }
        for (const Vec_int& target : tmp) {
            for (const Vec_int& next : get_next_tomato_and_set_res(map, res, target, r_size, c_size, day))
                tomato_queue.push(next);
        }
        day++;
        tmp.clear();
        if (tomato_queue.size() == 0)
            break;
    }
}

int find_max_val(const Matrix& map) {
    int max = 0;
    for (const Vec_int& vec : map) {
        for (const int& elem : vec) {
            if (elem == -1)
                return -1;
            else if (max < elem)
                max = elem;
        }
    }
    return max;
}

int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int row, col;
    std::cin >> col >> row;
    Matrix map(row, Vec_int(col)), res(row, Vec_int(col, -1)),ripen_tomato_matrix;
    set_tomato_map(map, res, row, col);
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (map[r][c] == 1) {
                ripen_tomato_matrix.push_back({ r,c });
            }
        }
    }
    ripe(map, res, ripen_tomato_matrix, row, col);
    std::cout << find_max_val(res);
    return 0;
}