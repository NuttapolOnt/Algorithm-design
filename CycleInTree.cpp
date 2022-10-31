#include<iostream>
#include<vector>
#include<stack>
#include<queue>

typedef std::vector<std::vector<int>> vv;

int n;

void printv(std::vector<int> &v){
    for(int &x : v){
        std::cout << x << " ";
    }
    std::cout << "\n";
}

void print(std::stack<int> s){
    while(!s.empty()){
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n----------------\n";
}

int cycle(vv &g){
    std::stack<int> s;
    std::vector<int> r(n);
    std::vector<int> p(n);
    std::vector<bool> visited(n);
    s.push(0);
    visited[0] = true;
    r[0] = 0;
    p[0] = 0;
    while(!s.empty()){
        //print(s);
        int k = s.top();
        std::vector<int> v = g[k];
        bool state = true;
        for(int &x : v){
            if(!visited[x]){
                s.push(x);
                visited[x] = true;
                r[x] = r[k] + 1;
                p[x] = k;
                state = false;
                break;
            }
            else{
                if(p[k] != x && p[x] != k){
                    int ans = r[k] > r[x] ? r[k] - r[x] : r[x] - r[k];
                    return ans + 1;
                }
            }
        }
        if(state){
            s.pop();
        }
    }
    return 0;
}

int BFS(vv &g){
    std::vector<bool> visited(n);
    std::vector<int> parent(n,-1);
    std::vector<int> rank(n);
    std::queue<int> q;
    q.push(0);
    visited[0] = true;
    parent[0] = 0;
    rank[0] = 0;
    while(!q.empty()){
        int k = q.front();
        std::vector<int> v = g[k];
        for(int &x : v){
            if(!visited[x]){
                visited[x] = true;
                rank[x] = rank[k] + 1;
                parent[x] = k;
                q.push(x);
            }
            else{
                if(parent[x] != k && parent[x] != x){
                    std::cout << x << " " << k << "\n"; 
                    printv(rank);
                    return rank[x] + rank[k] + 1;
                }
            }
        }
        q.pop();
    }
    return 0;
}

int main(){
    std::cin >> n;
    vv g(n);
    for(int i = 0; i < n; i++){
        int a,b;
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    std::cout << BFS(g) << "\n";
    return 0;
}
/*9 0 1 0 2 1 3 1 4 2 5 2 6 2 7 4 5 5 8*/