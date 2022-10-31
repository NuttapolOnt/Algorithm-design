#include<iostream>
#include<vector>
#include<queue>

typedef std::vector<std::vector<int>> vv;
int R,C;

void print(vv &v){
    for(auto &x: v){
        for(int &y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
    std::cout << "-------------------\n";
}
std::vector<std::pair<int,int>> next(int r, int c){
    std::vector<std::pair<int,int>> ans;
    if(r+1 < R)ans.push_back(std::make_pair(r+1,c));
    if(c+1 < C)ans.push_back(std::make_pair(r,c+1));
    if(r-1 >= 0)ans.push_back(std::make_pair(r-1,c));
    if(c-1 >= 0)ans.push_back(std::make_pair(r,c-1));
    return ans;
}

void DFS(vv &v){
    std::queue<std::pair<int,int>> q;
    q.push(std::make_pair(0,0));
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        std::vector<std::pair<int,int>> n = next(r,c);
        for(auto &x : n){
            if(v[x.first][x.second] == 0){
                q.push(x);
                v[x.first][x.second] = v[r][c] + 1;
            }
        }
        q.pop();
    }
}

int main(){
   std::cin >> R >> C;
   std::vector<int> vtmp(C,-1);
   vv v(R,vtmp);
   for(int i = 0; i < R; i++){
       for(int j = 0; j < C; j++){
           char tmp;
           std::cin >> tmp;
           if(tmp == '.'){
               v[i][j] = 0;
           }
           else if(tmp == '#'){
               v[i][j] = -1;
           }
       }
   }
   DFS(v);
   int ans = v[R-1][C-1] > 0 ? v[R-1][C-1] : -1;
   std::cout << ans << "\n";
   
   return 0;
}

/*5 5 ..... ...## ...#. ..##. .###.*/