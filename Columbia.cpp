#include<iostream>
#include<vector>
#include<queue>

typedef std::vector<std::vector<int>> vv;
typedef std::priority_queue<std::pair<int,std::pair<int,int>>> pq;

int r,c;

void print(vv &m){
    for(std::vector<int> &x : m){
        for(int &y: x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
}


std::vector<std::pair<int,int>> get(std::pair<int,int> &x){
    std::vector<std::pair<int,int>> ans(4);
    ans[0] = std::make_pair(x.first+1,x.second);
    ans[1] = std::make_pair(x.first,x.second+1);
    ans[2] = std::make_pair(x.first-1,x.second);
    ans[3] = std::make_pair(x.first,x.second-1);
    return ans;
}

void dijkstra(vv &m){
    std::vector<bool> tmp(c);
    std::vector<std::vector<bool>> visited(r,tmp);
    pq q;
    std::pair<int,int> p = std::make_pair(0,0);
    q.push(std::make_pair(0,p));
    visited[0][0] = true;
    while(!q.empty()){
        std::pair<int,std::pair<int,int>> k = q.top();
        m[k.second.first][k.second.second] = -k.first;
        q.pop();
        std::pair<int,int> pos = k.second;
        std::vector<std::pair<int,int>> v = get(pos);
        for(std::pair<int,int> &x : v){
            if(x.first >= 0 && x.first < r && x.second >= 0 && x.second < c){
                if(!visited[x.first][x.second]){
                    q.push(std::make_pair(-m[x.first][x.second] + k.first, x));
                    visited[x.first][x.second] = true;
                }
            }
        }
    }
}

int main(){
    std::cin >> r >> c;
    vv m(r);
    for(int i = 0; i < r; i++){
        std::vector<int> tmp(c);
        for(int j = 0; j < c; j++){
            std::cin >> tmp[j];
        }
        m[i] = tmp;
    }
    dijkstra(m);
    print(m);
    return 0;
}
/*4 4
1 1 1 1
9 8 7 1
1 1 1 1
1 2 4 9*/