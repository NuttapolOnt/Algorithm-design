#include<iostream>
#include<vector>
#include<queue>

typedef std::vector<std::vector<int>> vv;

int n,e;

int check(std::vector<bool> &v){
    for(int i = 1; i < v.size(); i++){
        if(!v[i]) return i;
    }
    return -1;
}

int bfs(vv &g){
    std::queue<int> q;
    std::vector<bool> visited(n+1);
    q.push(1);
    visited[1] = true;
    int count = 0;
    while(!q.empty()){
        int k = q.front();
        std::vector<int> v = g[k];
        for(int &x : v){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
        q.pop();
        if(q.empty()){
            count += 1;
            int next = check(visited);
            if(next != -1){
                q.push(next);
                visited[next] = true;
            }
            else break;
        }
    }
    return count;
}

int main(){
    std::cin >> n >> e;
    vv g(n+1);
    for(int i = 0; i < e; i++){
        int a,b;
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    std::cout << bfs(g) << "\n";
    return 0;
}/*/**/