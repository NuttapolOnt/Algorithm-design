#include<iostream>
#include<vector>
#include<queue>

typedef unsigned long int llint;
typedef std::priority_queue<std::pair<llint,std::pair<int,int>>> pq;

int n;

int main(){
    std::cin >> n;
    std::vector<llint> v(n);
    pq q;
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            llint x = v[i] ^ v[j];
            q.push(std::make_pair(x,std::make_pair(i,j)));
        }
    }
    llint ans = 0;
    int count = 0;
    std::vector<bool> visited(n);
    std::vector<int> parent(n);
    while(!q.empty()){
        llint val = q.top().first;
        std::pair<int,int> p = q.top().second;
        int x = p.first;
        int y = p.second;
        if(!visited[x] && !visited[y]){
            visited[x] = true;
            visited[y] = true;
            parent[x] = x;
            parent[y] = x;
            ans += val;
            count += 1;
        }
        else if(!visited[x]){
            visited[x] = true;
            parent[x] = parent[y];
            ans += val;
            count += 1;
        }
        else if(!visited[y]){
            visited[y] = true;
            parent[y] = parent[x];
            ans += val;
            count += 1;
        }
        else{
            if(parent[x] != parent[y]){
                int tmp = parent[y];
                for(int i = 0; i < n; i++){
                    if(parent[i] == tmp) parent[i] = parent[x];
                }
                count += 1;
                ans += val;
            }
        }
        q.pop();
        if(count >= n-1) break;
    }
    std::cout << ans << "\n";
    return 0;
}