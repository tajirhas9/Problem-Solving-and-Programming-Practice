/*
    Implementation of disjoint-set data structure
    Running time:
        O(⍺(n)) per operation, where ⍺(n) is the inverse of Ackermann function
    Usage:
        - Find (x) returns the set containing x
        - Union (x, y) joins two sets containing x and y, returns false if x and y are in the same set
    Input:
        - n, number of sets
*/

struct DisjointSet {
    int n;
    vector <int> rank, parent;

    DisjointSet (int n): n(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int Find (int x) {
        return parent[x] == x ? x : (parent[x] = Find(parent[x]));
    }

    bool Union (int x, int y) {
        x = Find(x), y = Find(y);
        if (x == y) {
            return false;
        } else if (rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            rank[x] = max(rank[x], rank[y] + 1);
        }
        return true;
    }
};