#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> edge;
struct DSU {
    vector <int> parent;
    DSU() {}
    DSU(int size) {
        parent.resize(size, -1);
    }
    void join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j) {
            return;
        }
        else {
            parent[i] = j;
        }

    }
    bool check(int i, int j) {
        if (find(i) != find(j)) {
            return true;
        }
        else {
            return false;
        }
    }
    int find(int v) {
        int root = v;
        while (parent[root] != -1)
            root = parent[root];
        while (parent[v] != -1)
        {
            int tmp = v;
            v = parent[v];
            parent[tmp] = root;
        }
        return root;
    }
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    vector<edge> Edges;
    int p1 = 0, p2 = 0, w = 0;
    int min = 0;
    int N = 0, M = 0;
    string str;
    fin >> N >> M;
    for (int i(0); i < M; i += 1) {
        fin >> p1 >> p2 >> w;
        Edges.push_back(make_tuple(w, p1, p2));
    }
    fin.close();
    DSU test(N);
    sort(Edges.begin(), Edges.end());
    for (int i(0); i < M; i += 1) {
        if (test.check(get<1>(Edges[i]) - 1, get<2>(Edges[i]) - 1)) {
            test.join(get<1>(Edges[i]) - 1, get<2>(Edges[i]) - 1);
            min += get<0>(Edges[i]);
        }
    }
    fout << min << endl;
    fout.close();
    return 0;
}