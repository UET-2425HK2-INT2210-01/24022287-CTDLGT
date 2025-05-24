
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1001;

vector<int> adj[MAX_N]; // Danh sách kề
bool visited[MAX_N];    // Mảng đánh dấu đỉnh đã thăm

// Duyệt DFS từ đỉnh u
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Nhập số đỉnh và số cạnh

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Thêm cạnh (x, y)
        adj[y].push_back(x); // Vì đồ thị vô hướng
    }

    int components = 0; // Đếm thành phần liên thông

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);       // Bắt đầu DFS từ đỉnh i
            components++; // Phát hiện thành phần liên thông mới
        }
    }

    cout << components << endl;

    return 0;
}
