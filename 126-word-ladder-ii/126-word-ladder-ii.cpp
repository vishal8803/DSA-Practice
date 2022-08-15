class Solution {
  int numNodes;
  int startNode;
  int endNode;
  int len;
  
  vector<vector<int>> edgeList;
  
  // Check that there is at most 1 mismatched character
  bool hasEdge(string& a, string& b) {
    int mismatched = 0;
    for (int i = 0; i < len; i++) {
      if (a[i] != b[i] && mismatched++) {
        return false;
      }
    }
    return true;
  }
  
  // Add edge (u, v) and (v, u) into graph
  void addEdge(int u, int v) {
    edgeList[u].push_back(v);
    edgeList[v].push_back(u);
  }
  
  // Backtrack to build up all paths from endNode to startNode
  void shortestPaths(vector<vector<int>>& paths, vector<int>& path, vector<int> parent[], int u) {
    if (u == startNode) {
      paths.push_back(path);
      return;
    }
    
    for (int v : parent[u]) { // all paths of equal length that go through node u
      path.push_back(v); 
      shortestPaths(paths, path, parent, v);
      path.pop_back();
    }
  }
  
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      int n = wordList.size();
      len = beginWord.size();
      startNode = n;
      auto it = find(begin(wordList), end(wordList), beginWord);
      bool hasStart = it != end(wordList);
      if (hasStart)
        startNode = it - begin(wordList);

      endNode = -1;
      numNodes = n + !hasStart;
      edgeList = vector<vector<int>>(numNodes, vector<int>());
      for (int i = 0; i < n; i++) {
        if (wordList[i] == endWord) {
          endNode = i;
        }
        if (!hasStart && hasEdge(beginWord, wordList[i])) {
          addEdge(startNode, i);
        }
        for (int j = i+1; j < n; j++) {
          if (hasEdge(wordList[i], wordList[j])) {
            addEdge(i, j);
          }
        }
      }

      if (endNode == -1) return {};
      
      vector<vector<string>> res;

      queue<int> q;
      q.push(startNode);
      vector<int> dist(numNodes, 1005); // Update distances from startNode
      vector<int> parent[numNodes]; // Track the parent(s) of a node ... -> u -> v -> ... implies parent[v] = u

      dist[startNode] = 0;
      while (!q.empty()) { // bfs through graph to find endNode
        int u = q.front(); q.pop();
        for (int v : edgeList[u]) {
          if (dist[v] > dist[u]+1) {
            dist[v] = dist[u] + 1;
            q.push(v);
            parent[v] = {u};
          } else if (dist[v] == dist[u] + 1) {
            parent[v].push_back(u);
          }
        }
      }
      
      vector<vector<int>> paths;
      vector<int> path = {endNode};
      shortestPaths(paths, path, parent, endNode); // backtrack to rebuild paths

      for (const vector<int>& p : paths) { // Paths are in reverse order, indexing wordList
        res.push_back({});
        vector<string>& t = res.back();
        t.push_back(beginWord);
        for (int i = p.size() - 2; i >= 0; i--) {
          t.push_back(wordList[p[i]]);
        }
      }
      
      return res;
    }
};