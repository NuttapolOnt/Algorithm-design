#include<iostream>
#include<vector>
#include<queue>

typedef std::vector<std::vector<int>> vv;

int row,col,t;

std::vector<std::pair<int,int>> getnext(std::pair<int,int> &x){
    int r = x.first;
    int c = x.second;
    std::vector<std::pair<int,int>> ans(4);
    ans[0] = std::make_pair(r,c+1);
    ans[1] = std::make_pair(r+1,c);
    ans[2] = std::make_pair(r-1,c);
    ans[3] = std::make_pair(r,c-1);
    return ans;
}

int check(vv &g){
    int count = 0;
    for(auto &x : g){
        for(int &y : x){
            if(y != -1 && y != 0){
                count += 1;
            }
        }
    }
    return count;
}

int spread(vv &g, std::queue<std::pair<int,int>> &q){
    int count = 1;
    while(!q.empty()){
        std::pair<int,int> p = q.front();
        int rk = p.first;
        int ck = p.second;
        if(g[rk][ck] > t) break;
        std::vector<std::pair<int,int>> v = getnext(p);
        for(auto &x : v){
            int r = x.first;
            int c = x.second;
            if(r >= 0 && r < row && c >= 0 && c < col && g[r][c] == 0){
                g[r][c] = g[rk][ck] + 1;
                q.push(x);
                count += 1;
            }
        }
        q.pop();
    }
    return count;
}

int main(){
    std::cin >> row >> col >> t;
    std::vector<int> v(col);
    vv g(row,v);
    std::queue<std::pair<int,int>> q;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int a;
            std::cin >> a;
            if(a == 2) a = -1;
            g[i][j] = a;
            if(g[i][j] == 1) q.push(std::make_pair(i,j));
        }
    }
    int ans = spread(g,q);
    std::cout << ans << "\n";
    return 0;
}
/*5 4 3 0 0 0 0 0 0 0 0 0 0 0 0 0 2 1 0 0 0 0 0*/