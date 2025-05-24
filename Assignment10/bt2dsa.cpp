
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1001;

vector<int> adj[MAX_N]; // Danh sách kề
bool visited[MAX_N];    // Mảng đánh dấu đỉnh đã thăm
int dist[MAX_N];        // dist[i] lưu số cạnh ngắn nhất từ X đến i

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    // Đọc đồ thị
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Đồ thị có hướng
    }

    // Mô phỏng hàng đợi bằng vector
    vector<int> q;
    int front = 0; // giống như chỉ số đầu hàng đợi

    q.push_back(X);
    visited[X] = true;
    dist[X] = 0;

    while (front < q.size()) {
        int u = q[front++]; // lấy phần tử đầu tiên

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push_back(v); // thêm vào cuối như queue
            }
        }
    }

    if (visited[Y]) {
        cout << dist[Y] << endl;
    } else {
        cout << -1 << endl; // không có đường đi từ X đến Y
    }

    return 0;
}
