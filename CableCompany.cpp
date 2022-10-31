#include<iostream>
#include<vector>
#include<queue>

typedef std::priority_queue<std::pair<int,std::pair<int,int>>, std::vector<std::pair<int,std::pair<int,int>>>, std::greater<std::pair<int,std::pair<int,int>>>> pq;


int main(){
    int n;
    std::cin >> n;
    pq q;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int a;
            std::cin >> a;
            q.push(std::make_pair(a,std::make_pair(i,j)));
        }
    }
    int count = 0;
    int ans = 0;
    std::vector<bool> visited(n);
    std::vector<int> parent(n);
    while(!q.empty()){
        int val = q.top().first;
        std::pair<int,int> p = q.top().second;
        int x = p.first;
        int y = p.second;
        if(!visited[x] && ! visited[y]){
            parent[x] = x;
            parent[y] = x;
            ans += val;
            count += 1;
            visited[x] = true;
            visited[y] = true;
        }
        else if(!visited[x]){
            parent[x] = parent[y];
            visited[x] = true;
            ans += val;
            count += 1;
        }
        else if(!visited[y]){
            parent[y] = parent[x];
            visited[y] = true;
            ans += val;
            count += 1;
        }
        else{
            if(parent[x] != parent[y]){
                int tmp = parent[y];
                for(int i = 0; i < n; i++) if(parent[i] == tmp) parent[i] = parent[x];
                ans += val;
                count += 1;
            }
        }
        q.pop();
    }
    std::cout << ans << std::endl;
    return 0;
}