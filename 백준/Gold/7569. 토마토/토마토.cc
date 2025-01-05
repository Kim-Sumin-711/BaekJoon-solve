#include<iostream>
#include<vector>
#include<queue>
using Third_Matrix = std::vector<std::vector<std::vector<int>>>;
using Matrix = std::vector<std::vector<int>>;
using Vec_int = std::vector<int>;
using Queue_Vec_int = std::queue<Vec_int>;

void set_tomato_map(Third_Matrix& map, Third_Matrix& res, const int& row, const int& col, const int& height) {
    for (int h = 0; h < height; h++) {
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                std::cin >> map[r][c][h];
                if (map[r][c][h] == -1)
                    res[r][c][h] = 0;
            }
        }
    }
    
}

bool good_index(const int& nr, const int& nc, const int& nh, const int& r_size, const int& c_size, const int& h_size) {
    if (nr >= 0 && nr < r_size) {
        if (nc >= 0 && nc < c_size) {
            if (nh >= 0 && nh < h_size) {
                return true;
            }
        }
    }
    return false;
}

Matrix get_next_tomato_and_set_res(const Third_Matrix& map, Third_Matrix& res, const Vec_int& target, const int& r_size, const int& c_size, const int& h_size, const int& day) {
    int tr = target[0], tc = target[1], th = target[2];
    Matrix next;
    //up,down,left,right,hup,hdown
    Vec_int dr = { -1,1,0,0,0,0 }, dc = { 0,0,-1,1,0,0 }, dh = { 0,0,0,0,1,-1 };

    for (int i = 0; i < 6; i++) {
        int nr = tr + dr[i], nc = tc + dc[i], nh = th + dh[i];
        if (good_index(nr, nc, nh, r_size, c_size, h_size)) {
            if (res[nr][nc][nh] != 0) {
                if (res[nr][nc][nh] > day || res[nr][nc][nh] == -1) {
                    next.push_back({ nr,nc,nh });
                    res[nr][nc][nh] = day;
                }
            }
        }
    }
    return next;
}

void ripe(const Third_Matrix& map, Third_Matrix& res, const Matrix& start_spots, const int& r_size, const int& c_size, const int& h_size) {
    Queue_Vec_int tomato_queue;
    for (const Vec_int& start_spot : start_spots) {
        int tr = start_spot[0], tc = start_spot[1], th = start_spot[2];
        res[tr][tc][th] = 0;
        tomato_queue.push(start_spot);
    }
    int day = 1;
    while (tomato_queue.size() != 0) {
        int size = tomato_queue.size();
        for (int i = 0; i < size; i++) {
            Vec_int now_tomato = tomato_queue.front();
            tomato_queue.pop();
            for (const Vec_int& next : get_next_tomato_and_set_res(map, res, now_tomato, r_size, c_size, h_size, day))
                tomato_queue.push(next);
        }
        day++;
    }
}

int find_max_val(const Third_Matrix& map) {
    int max = 0;
    for (const Matrix& matri : map) {
        for (const Vec_int& vec : matri) {
            for (const int& elem : vec) {
                if (elem == -1)
                    return -1;
                else if (max < elem)
                    max = elem;
            }
        }
    }
    return max;
}

int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int row, col,height;
    std::cin >> col >> row >> height;
    Third_Matrix map(row, Matrix(col,Vec_int(height))), res(row, Matrix(col, Vec_int(height,-1)));
    Matrix ripen_tomato_matrix;
    set_tomato_map(map, res, row, col,height);
    for (int h = 0; h < height; h++) {
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (map[r][c][h] == 1)
                    ripen_tomato_matrix.push_back({ r,c,h });
            }
        }
    }
    ripe(map, res, ripen_tomato_matrix, row, col,height);
    std::cout << find_max_val(res);
    return 0;
}