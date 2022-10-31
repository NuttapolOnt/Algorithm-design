#include<iostream>
#include<vector>
#include<queue>

typedef std::vector<std::vector<std::pair<int,int>>> vv;
typedef std::priority_queue<std::pair<int,std::pair<int,int>>, std::vector<std::pair<int,std::pair<int,int>>>, std::greater<std::pair<int,std::pair<int,int>>>> pq;
 

int n;

int check(std::vector<int> &v){
    int max = 0;
    for(int &x : v){
        if(x == -1) return -1;
        if(x > max) max = x;
    }
    return max;
}

void print(pq q, std::vector<int> v){
    while(!q.empty()){
        std::cout << "(" <<q.top().first << " " << q.top().second.second << ")";
        q.pop();
    }
    std::cout << "\n";
    for(auto x : v){
        std::cout << x << " ";
    }
    std::cout << "\n--------------------\n";
}

int farthest(vv &g){
    pq q;
    std::vector<int> d(n,-1);
    d[0] = 0;
    for(auto &x : g[0]){
        q.push(std::make_pair(x.first,std::make_pair(0,x.second)));
    }
    while(!q.empty()){
        //print(q,d);
        std::pair<int,std::pair<int,int>> p = q.top();
        int k = p.second.first;
        int next = p.second.second;
        int dis = p.first;
        if(d[next] == -1){
            d[next] = dis;
            for(auto &x : g[next]){
                q.push(std::make_pair(d[next] + x.first,std::make_pair(next,x.second)));
            }
        }
        q.pop();
    }
    return check(d);
}

int main(){
    std::cin >> n;
    vv g(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a;
            std::cin >> a;
            if(a > 0) g[i].push_back(std::make_pair(a,j));
        }
    }
    std::cout << farthest(g) << "\n";
}
/*5
0 1 -1 -1 7
-1 0 2 3 5 
-1 -1 0 4-1 
-1 4 2 0 -1 
-1 -1 -1 4 0*/