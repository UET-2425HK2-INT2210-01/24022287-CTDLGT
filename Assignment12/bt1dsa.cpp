#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAX_N = 1001;
vector<int> adj[MAX_N];  // Danh sách kề
int indegree[MAX_N];     // Bậc vào của mỗi đỉnh

int main() {
    ifstream fin("jobs.txt");
    ofstream fout("jobs.out");

    int n, m;
    fin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    // Mô phỏng queue bằng vector + chỉ số đầu
    vector<int> q;
    int front = 0;

    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push_back(i);
        }
    }

    vector<int> result;

    while (front < q.size()) {
        int u = q[front++]; // lấy phần tử đầu
        result.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push_back(v);
            }
        }
    }

    // Nếu không đủ n đỉnh thì có chu trình
    if (result.size() != n) {
        fout << "IMPOSSIBLE";
    } else {
        for (int i = 0; i < result.size(); ++i) {
            fout << result[i];
            if (i != result.size() - 1) fout << " ";
        }
    }

    fin.close();
    fout.close();
    return 0;
}

