#include<iostream>
#include<vector>
#include<queue>

typedef std::vector<std::vector<int>> vv;
typedef std::vector<std::vector<bool>> vb;

int n,r,c;
std::vector<bool> maptmp(1000,true);
vb map(1000,maptmp);
std::vector<int> gtmp(1000,-1);
vv g(1000,gtmp);

std::vector<std::pair<int,int>> get(std::pair<int,int> &x){
    std::vector<std::pair<int,int>> ans(4);
    ans[0] = std::make_pair(x.first,x.second+1);
    ans[1] = std::make_pair(x.first+1,x.second);
    ans[2] = std::make_pair(x.first,x.second-1);
    ans[3] = std::make_pair(x.first-1,x.second);
    return ans;
}

void tour(){
    std::queue<std::pair<int,int>> q;
    q.push(std::make_pair(r,c));
    g[r][c] = 0;
    while(!q.empty()){
        std::pair<int,int> p = q.front();
        int rk = p.first;
        int ck = p.second;
        std::vector<std::pair<int,int>> v = get(p);
        for(auto &x : v){
            int rn = x.first;
            int cn = x.second;
            if(rn >= 0 && rn < 1000 && cn >= 0 && cn < 1000){
                if(g[rn][cn] == -1){
                    q.push(x);
                    if(map[rn][cn]){
                        g[rn][cn] = g[rk][ck];
                    }
                    else{
                        g[rn][cn] = g[rk][ck] + 1;
                    }
                }
            }
        }
        q.pop();
    }
}

int check(){
    int min = 2000;
    for(int i = 0; i < 1000; i++){
        if(map[i][0] && g[i][0] < min) min = g[i][0];
        if(map[i][999] && g[i][999] < min) min = g[i][999];
        if(map[0][i] && g[0][i] < min) min = g[0][i];
        if(map[999][i] && g[999][i] < min) min = g[999][i];
    }
    return min;
}

int main(){
    int a,b;
    std::cin >> n >> a >> b;
    r = 1000 - b; c = 1000 - a;
    for(int i = 0; i < n; i++){
        int a,b;
        std::cin >> a >> b;
        map[1000-b][1000-a] = false;
    }
    tour();
    std::cout << check() << "\n";
    return 0;
}
