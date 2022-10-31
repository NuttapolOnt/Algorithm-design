#include<iostream>
#include<vector>
#include<queue>

typedef std::vector<std::vector<std::pair<int,int>>> vv;

int n,e,s;

void print(std::vector<int> &v){
    if(v.size() == 0){
        std::cout << -1 << "\n";
        return;
    }
    for(int &x : v){
        std::cout << x << " ";
    }
    std::cout << "\n";
}

std::vector<int> bellman(vv &g, int start){
    std::vector<int> ans(n,__INT16_MAX__);
    ans[start] = 0;
    int state = 0;
    for(int i = 0; i <= n; i++){
        std::vector<int> visited(n);
        std::queue<int> q;
        q.push(start);
        visited[start] = true;
        //print(ans);
        while(!q.empty()){
            int k = q.front();
            std::vector<std::pair<int,int>> v = g[k];
            for(std::pair<int,int> &x : v){
                if(x.second + ans[k] < ans[x.first]){
                    ans[x.first] = x.second + ans[k];
                    state = 1;
                }
                if(!visited[x.first]){
                    visited[x.first] = true;
                    q.push(x.first);
                }
            }
            q.pop();
        }
        if(state == 1){
            if(i == n){
                ans.resize(0);
                return ans;
            }
            else{
                state= 0;
            }
        }
        else{
            return ans;
        }
    }
}

int main(){
    std::cin >> n >> e >> s;
    vv g(n);
    for(int i = 0; i < e; i++){
        int a,b,c;
        std::cin >> a >>b >> c;
        g[a].push_back(std::make_pair(b,c));
    }
    std::vector<int> ans = bellman(g,s);
    print(ans);
    return 0;
}
/*4 3 0 0 1 -1 1 2 1 2 3 4
4 3 0 1 2 -1 2 3 -1 3 1 -1*/
