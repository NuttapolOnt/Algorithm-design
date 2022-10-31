#include<iostream>
#include<vector>
#include<queue>

typedef std::vector<std::vector<int>> vv;

int n,e,k;

int bfs(vv &g, std::vector<bool> visited, int start){
    // int count = 0;
    // std::queue<int> q;
    // q.push(start);
    // visited[start] = true;
    // std::vector<int> d(n);
    // d[start] = 0;
    // while(!q.empty()){
    //     int c = q.front();
    //     if(d[c] > k) break;
    //     std::vector<int> v = g[c];
    //     for(int &x : v){
    //         if(!visited[x]){
    //             q.push(x);
    //             visited[x] = true;
    //             d[x] = d[c] +1;
    //         }
    //     }
    //     count ++;
    //     q.pop();  
    // }
    // return count;
    std::queue<int> q;
    q.push(start);
    visited[start] = true;
    std::vector<int> rank(n);
    rank[start] = 0;
    int count = 1;
    while(!q.empty()){
        int x = q.front();
        if(rank[x] >= k) break;
        std::vector<int> v = g[x];
        for(int &y : v){
            if(!visited[y]){
                visited[y] = true;
                q.push(y);
                rank[y] = rank[x] + 1;
                count ++;
            }
        }
        q.pop();
    }
    return count;
}

int main(){
    std::cin >> n >> e >> k;
    vv g(n);
    std::vector<bool> visited(n);
    for(int i= 0; i < e; i++){
        int a,b;
        std::cin >> a >>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = -1;
    for(int i = 0; i < n; i++){
        int tmp = bfs(g,visited,i);
        if(tmp > ans) ans = tmp;
    }
    std::cout << ans << "\n";
    return 0;
}
/*7 8 2 0 6 1 6 1 5 1 4 2 3 3 4 4 5 5 6*/