#include<iostream>
#include<vector>
#include<queue>

typedef std::vector<std::vector<int>> vv;
typedef std::vector<std::vector<bool>> vb;
typedef std::vector<std::pair<int,std::pair<int,int>>> vp;

void printvv(vv &v){
    for(auto &x : v){
        for(int &y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
}

void printvb(vb &v){
    for(auto &x : v){
        for(bool y : x){
            if(y) std::cout << "_ ";
            else std::cout << "o ";
        }
        std::cout << "\n";
    }
}

std::vector<std::pair<int,int>> get(int x, int y){
    std::vector<std::pair<int,int>> ans(4);
    ans[0] = std::make_pair(x,y+1);
    ans[1] = std::make_pair(x+1,y);
    ans[2] = std::make_pair(x,y-1);
    ans[3] = std::make_pair(x-1,y);
    return ans;
}

void ghost_walk(vb &map, vv &g, vp &ghost,int t, int row, int col){
    for(auto &x : ghost){
        int ti = x.first;
        int ri = x.second.first;
        int ci = x.second.second;
        std::queue<std::pair<int,int>> q;
        if((g[ri][ci] == -1 || ti < g[ri][ci]) && map[ri][ci]){
            q.push(x.second);
            g[ri][ci] = ti;
        }
        while(!q.empty()){
            std::pair<int,int> p = q.front();
            int rk = p.first;
            int ck = p.second;
            //std::cout << rk << " " << ck << "\n";
            if(g[rk][ck] >= t) break;
            std::vector<std::pair<int,int>> next = get(rk,ck);
            for(auto &y : next){
                int rn = y.first;
                int cn = y.second;
                if(rn >= 0 && rn < row && cn >= 0 && cn < col && map[rn][cn]){
                    if(g[rn][cn] == -1 || g[rk][ck] +1 < g[rn][cn]){
                        g[rn][cn] = g[rk][ck] +1;
                        q.push(y);
                    }
                }
            }
            q.pop();
        }
    }
}

bool check(vv &v, int t){
    for(auto &x : v){
        for(int &y : x){
            if(y >= t){
                return true;
            }
        }
    }
    return false;
}

vv pac_walk(vb &map, vv &g, vp &ghost,int t, int row, int col,int r ,int c){
    std::vector<int> tmppac(col,-1);
    vv pac(row,tmppac);
    std::queue<std::pair<int,int>> q;
    if(g[r][c] == -1 || 0 < g[r][c]){
        q.push(std::make_pair(r,c));
        pac[r][c] = 0;
    }
    while(!q.empty()){
        std::pair<int,int> p = q.front();
        int rk = p.first;
        int ck = p.second;
        //std::cout << rk << " " << ck << "\n";
        if(pac[rk][ck] >= t) break;
        std::vector<std::pair<int,int>> next = get(rk,ck);
        next.push_back(p);
        for(auto &y : next){
            int rn = y.first;
            int cn = y.second;
            if(rn >= 0 && rn < row && cn >= 0 && cn < col && map[rn][cn]){
                if(g[rn][cn] == -1 || (pac[rn][cn] == -1 && pac[rk][ck] +1 < g[rn][cn])){
                    //std::cout << pac[rk][ck] + 1 << " \n";
                    pac[rn][cn] = pac[rk][ck] +1;
                    q.push(y);
                }
            }
        }
        q.pop();
    }
    
    return pac;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int k;
    std::cin >> k;
    for(int i = 0; i < k; i++){
        int row,col,n,t,r,c;
        std::cin >> row >> col >> n >> t >> r >> c;
        vp ghost(n);
        for(int i = 0; i < n; i++){
            int ti,ri,ci;
            std::cin >> ti >> ri >> ci;
            ghost[i] = std::make_pair(ti,std::make_pair(ri,ci));
        }
        std::vector<bool> mtmp(col);
        vb map(row,mtmp);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                char a;
                std::cin >> a;
                if(a == '.')  map[i][j] = true;
            }
        }
        std::vector<int> gtmp(col,-1);
        vv g(row,gtmp);
        ghost_walk(map,g,ghost,t,row,col);
        //printvb(map);
        vv ans = pac_walk(map,g,ghost,t,row,col,r,c);
        //std::cout << "------------------\n";
        //printvv(ans);
        if(check(ans,t)) std::cout << "YES\n";
        else std::cout << "NO\n"; 
    }
    return 0;
}