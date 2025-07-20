//1948. Delete Duplicate Folders in System


class Solution {
    struct N { 
        unordered_map<string, N*> c; 
        bool del = false; 
    };
    unordered_map<string, vector<N*>> M;
    string s(N* u) {
        if (u->c.empty()) return "";
        vector<pair<string,string>> v;
        for (auto &p : u->c) v.emplace_back(p.first, s(p.second));
        sort(v.begin(), v.end());
        string r = "(";
        for (auto &pr : v) r += pr.first + pr.second;
        r += ")";
        M[r].push_back(u);
        return r;
    }
    void m(N* u) {
        u->del = true;
        for (auto &p : u->c) m(p.second);
    }
    vector<vector<string>> g(N* u, vector<string>& p) {
        vector<vector<string>> a;
        for (auto &pr : u->c) {
            if (pr.second->del) continue;
            p.push_back(pr.first);
            a.push_back(p);
            auto t = g(pr.second, p);
            a.insert(a.end(), t.begin(), t.end());
            p.pop_back();
        }
        return a;
    }
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& P) {
        N* r = new N();
        for (auto &pa : P) {
            N* u = r;
            for (auto &f : pa) {
                if (!u->c.count(f)) u->c[f] = new N();
                u = u->c[f];
            }
        }
        s(r);
        for (auto &pr : M) if (!pr.first.empty() && pr.second.size()>1)
            for (auto u : pr.second) m(u);
        vector<string> p;
        return g(r, p);
    }
};
