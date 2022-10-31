#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

typedef std::vector<std::vector<int>> vv;

void printstack(std::stack<int> s){
    while(!s.empty()){
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n------------------------\n";
}

int findmax(std::vector<bool> &visited, std::vector<int> &timing){
    int max = 0;
    int pos = 0;
    for(int i = 0; i < timing.size(); i++){
        if(timing[i] > max && !visited[i]){
            pos = i;
            max = timing[i];
        }
    }
    return pos;
}

int dfs(vv &g, std::vector<bool> &visited, int start){
    int count = 0;
    std::stack<int> s;
    s.push(start);
    visited[start] = true;
    while(!s.empty()){
        //printstack(s);
        std::vector<int> v = g[s.top()];
        int state = true;
        for(int &x :v){
            if(!visited[x]){
                s.push(x);
                visited[x] = true;
                state = false;
            }
        }
        if(state){
            s.pop();
            count++;
        }
    }
    return count;
}

void print(vv &g){
    for(std::vector<int> &v : g){
        for(int &x : v){
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}

vv tranpose(vv &g){
    vv ans(g.size());
    for(int i = 0; i < g.size(); i++){
        for(int j = 0; j < g[i].size(); j++){
            ans[g[i][j]].push_back(i);
        }
    }
    return ans;
}

int check(std::vector<bool> &v){
    for(int i = 0; i < v.size(); i++){
        if(!v[i]) return i; 
    }
    return -1;
}

std::vector<int> timing(vv &g, std::vector<bool> visited){
    std::stack<int> s;
    int count = 0;
    std::vector<int> time(g.size());
    while(check(visited) != -1){
        //std::cout << "work\n";
        int k = check(visited);
        visited[k] = true;
        s.push(k);
        count++;
        while(!s.empty()){
            //printstack(s);
            std::vector<int> v = g[s.top()];
            bool state = true;
            count ++;
            for(int i = 0; i < v.size(); i++){
                if(!visited[v[i]]){
                    s.push(v[i]);
                    visited[v[i]]= true;
                    state = false;
                    break;
                }
            }
            if(state){
                time[s.top()] = count;
                s.pop();
            }
        }
    }
    return time;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<bool> visited(n);
    vv g(n);
    for(int i = 0; i < n; i++){
        int m;
        std::cin >> m;
        std::vector<int> tmp(m);
        for(int j= 0; j < m; j++){
            std::cin >> tmp[j];
        }
        g[i] = tmp;
    }
    vv gt = tranpose(g);
    std::vector<int> time = timing(gt,visited);
    //print(gt);
    //std::cout << "----------------\n";
    // for(int i = 0; i < time.size(); i++){
    //     std::cout << time[i] << " ";
    // }
    // std::cout << "\n";
    std::vector<int> ans;
    while(check(visited) != -1){
        int pos = findmax(visited,time);
        ans.push_back(dfs(g,visited,pos));
    }
    std::sort(ans.begin(),ans.end());
    for(int & x : ans){
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}
/*5 2 1 2 2 0 3 1 3 1 2 0*/