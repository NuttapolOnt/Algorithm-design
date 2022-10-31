#include<iostream>
#include<vector>
#include<queue>

typedef std::vector<std::vector<int>> vv;

int n,e,t;

int bfs(vv &g){
    std::queue<int> q;
    std::vector<int> d(n+1);
    std::vector<bool> visited(n+1);
    q.push(0);
    visited[0] = true;
    int count = 0;
    while(!q.empty()){
        int k = q.front();
        std::vector<int> v = g[k];
        if(d[k] == t) count += 1;
        if(d[k] > t) break;
        for(int &x : v){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                d[x] = d[k] + 1;
            }
        }
        q.pop();
    }
    return count;
}


int main(){
    std::cin >> n >> e >> t;
    vv g(n+1);
    for(int i = 0; i < e; i++){
        int a,b;
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    std::cout << bfs(g) << "\n";
    return 0;
}
