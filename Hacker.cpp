#include<iostream>
#include<vector>
#include<queue>

typedef std::vector<std::vector<int>> vv;
typedef std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;

int n,m,k;

int spread(vv &g, pq &q, std::vector<int> &time, std::vector<bool> &visited){
    while(!q.empty()){
        std::pair<int,int> p = q.top();
        int t = p.first;
        int pos = p.second;
        std::vector<int> v = g[pos];
        for(int &x : v){
            if(!visited[x]){
                visited[x] = true;
                q.push(std::make_pair(t + time[x], x));
            }
        }
        q.pop();
        if(q.empty()){
            return t;
        }
    }
}

int main(){
    std::cin >> n >> m >> k;
    pq q;
    std::vector<int> start(k);
    std::vector<int> time(n);
    std::vector<bool> visited(n);
    vv g(n);
    for(int i = 0; i < k; i++){
        std::cin >> start[i];
        visited[start[i]] = true;
    }
    for(int i = 0; i < n; i++){
        std::cin >> time[i];
    }
    for(int i = 0; i < k; i++){
        q.push(std::make_pair(time[start[i]],start[i]));
    }
    for(int i = 0; i < m; i++){
        int a,b; 
        std::cin >> a >> b ;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    std::cout << spread(g,q,time,visited) << "\n";
    return 0;
}
/*3 2 1 1 3 5 1 0 1 1 2*/