#include<iostream>
#include<vector>
#include<queue>

typedef std::vector<std::vector<int>> vv;

void print(std::queue<int> q){
    while(!q.empty()){
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n-----------------\n";
}

int check(std::vector<bool> &v){
    for(int i = 0; i < v.size(); i++){
        if(!v[i]) return i;
    }
    return -1;
}

bool bfs(vv &g, std::vector<bool> &visited){
    // std::queue<int> q;
    // std::vector<bool> used(visited.size());
    // while(check(visited) != -1){
    //     int k = check(visited);
    //     q.push(k);
    //     visited[k] = true;
    //     while(!q.empty()){
    //         //print(q);
    //         std::vector<int> v = g[q.front()];
    //         for(int &x : v){
    //             if(!visited[x]){
    //                 q.push(x);
    //                 visited[x] = true;
    //             }
    //             else{
    //                 if(!used[x]){
    //                     return true;
    //                 }
    //             }
    //         }
    //         used[q.front()] = true;
    //         q.pop();
    //     }
    // }
    // return false;
    std::queue<int> q;
    std::vector<int> p(visited.size());
    q.push(0);
    visited[0] = true;
    p[0] = 0;
    while(!q.empty()){
        int k = q.front();
        std::vector<int> v = g[k];
        for(int &x : v){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                p[x] = k;
            }
            else{
                if(p[k] != x){
                    return true;
                }
            }
        }
        q.pop();
        if(q.empty()){
            int next = check(visited);
            if(next != -1){
                q.push(next);
                visited[next] = true;
                p[next] = next;
            }
            else{
                break;
            }
        }
    }
    return false;
}

int main(){
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n,e;
        std::cin >> n >> e;
        vv g(n);
        std::vector<bool> visited(n);
        for(int j = 0; j < e; j++){
            int a,b;
            std::cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bool state = bfs(g,visited);
        if(state){
            std::cout << "YES\n" ;
        }
        else{
            std::cout << "NO\n";
        }
    }
}
/*4 4 0 4 4 2 3 0 1 1 2 2 0 4 3 0 1 1 2 2 0 4 1 1 3*/