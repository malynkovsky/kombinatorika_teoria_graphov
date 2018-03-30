#include <iostream>
#include <string>
#include <fstream>
//#include <sstream>
#include <vector>
using namespace std;

struct DSU {
    vector <int> parent; /*rank;*/
    DSU() {}
    DSU(int size) {
        parent.resize(size, -1);
        //rank.assign(size, 0);// or ,1
    }
    /*int Rank(int v) {

    }*/
    void reset(int size) {
        parent.resize(size, -1);
        //rank.assign(size, 0);// ранги множеств(деревьев)
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
    string check(int i, int j) {
        if (find(i) == find(j)) {
            return "YES";
        }
        else {
            return "NO";
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
    DSU test(1);
    int i = 0, j = 0;
    int N = 0;
    string str;
    while (fin >> str) {
        if (str == "RESET") {
            /*int N;*/
            fin >> N;
            test.reset(N);
            fout << "RESET DONE" << endl;
        }
        if (str == "JOIN") {
            /*int i = 0, j = 0;*/
            fin >> i >> j;
            if (test.find(i) != test.find(j)) {
                test.join(i, j);
            }
            else {
                fout << "ALREADY" << " " << i << " " << j << endl;
            }
        }
        if (str == "CHECK") {
            /*int i = 0, j = 0;*/
            fin >> i >> j;
            fout << test.check(i, j) << endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}