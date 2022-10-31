#include<iostream>
#include<vector>
#include<stack>

typedef std::vector<std::vector<int>> vv;

int n,e;

void print(std::stack<int> s){
    while(!s.empty()){
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n--------------------\n";
}

int check(std::vector<bool> &v){
    for(int i = 0; i < v.size(); i++){
        if(!v[i]) return i;
    }
    return -1;
}

int dfs(vv &g){
    int count = 0;
    std::vector<bool> visited(n);
    std::stack<int> s;
    s.push(0);
    visited[0] = true;
    bool c = true;
    std::vector<int> p(n);
    p[0] = 0;
    while(!s.empty()){
        //print(s);
        int k = s.top();
        std::vector<int> v = g[k];
        bool state = true;
        if(v.size() > 2) c = false ;
        for(int i = 0; i < v.size(); i++){
            if(!visited[v[i]]){
                s.push(v[i]);
                visited[v[i]] = true;
                state = false;
                p[v[i]] = k;
                break;
            }
            else{
                if(p[k] != v[i] && p[k] != k && p[v[i]] != k){
                    //std::cout << p[k] << v[i] <<" work\n";
                    c = false;
                }
            }
        }
        if(state){
            s.pop();
        }
        if(s.empty()){
            if(c){
                count += 1;
            }
            int next = check(visited);
            if(next != -1) {
                s.push(next);
                visited[next] = true;
                p[next] = next;
                c = true;
            }
        }
    }
    return count;
}

int main(){
    std::cin >> n >> e;
    vv g(n);
    for(int i = 0; i < e; i++){
        //std::cout << e << "\n";
        int a,b;
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    std::cout << dfs(g) << "\n";
    return 0;
}