class Solution {
public:
    
    struct info{
        int xi,yi,xj,yj,dist;
        
        info(int a, int b, int c, int d, int e) {
            xi = a;
            yi = b;
            xj = c;
            yj = d;
            dist = e;
        }
    };
    
    pair<int,int> findParent(pair<int,int> &p, map<pair<int,int>, pair<int,int>> &mp) {
        if(mp[p]==p) return p;
        
        return mp[p] = findParent(mp[p], mp);
    }
    
    void unio(pair<int,int> &p1, pair<int,int> &p2, map<pair<int,int>, pair<int,int>> &mp, map<pair<int,int>, int> &rnk) {
        p1 = findParent(p1, mp);
        p2 = findParent(p2, mp);
        
        if(rnk[p1] > rnk[p2]) {
            mp[p2] = p1;
        } else if(rnk[p2] > rnk[p1]) {
            mp[p1] = p2;
        } else {
            mp[p1] = p2;
            rnk[p2]++;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<info> v;
        int n = points.size();
        
        map<pair<int,int>, pair<int,int>> parent;
        map<pair<int,int>, int> rnk;
        
        for(int i = 0; i < n; i++) {
            parent[{points[i][0], points[i][1]}] = {points[i][0], points[i][1]};
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[j][1] - points[i][1]);
                info in(points[i][0], points[i][1], points[j][0], points[j][1], dist);
                v.push_back(in);
            }
        }
        
        sort(v.begin(), v.end(), [&](info &i1, info &i2) {
            return i1.dist < i2.dist;
        });
        
        int cost = 0;
        for(int i = 0; i < v.size(); i++) {
            info in = v[i];
            pair<int,int> p1 = {in.xi, in.yi};
            pair<int,int> p2 = {in.xj, in.yj};
            
            if(findParent(p1, parent) != findParent(p2, parent)) {
                cost += in.dist;
                unio(p1, p2, parent, rnk);
            }
        }
        
        return cost;
    }
};