#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

typedef std::vector<std::vector<int>> vv;

int n;

void printvv(vv &g){
    for(auto &x : g){
        for(auto &y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
    std::cout << "--------------\n";
}

void prints(std::stack<int> s){
    while(!s.empty()){
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n-------------------\n";
}

void print(std::vector<int> &v){
    for(int &x : v){
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int check(std::vector<bool> &v){
    for(int i = 0; i < v.size(); i++){
        if(!v[i]) return i;
    }
    return -1;
}

int findmax(std::vector<int> &time, std::vector<bool> &visited){
    int max = -1;
    int max_pos = -1;
    for(int i = 0; i < n; i++){
        if(!visited[i] && time[i] > max){
            max = time[i];
            max_pos = i;
        }
    }
    return max_pos;
}

int dfs(vv &g, std::vector<bool> &visited, int start){
    std::stack<int> s;
    s.push(start);
    visited[start] = true;
    int count = 1;
    while(!s.empty()){
        int k = s.top();
        std::vector<int> v = g[k];
        bool state = true;
        for(int &x : v){
            if(!visited[x]){
                visited[x] = true;
                s.push(x);
                count += 1;
                state= false;
            }
        }
        if(state){
            s.pop();
        }
    }
    return count;
}

std::vector<int> timing(vv &g){
    std::vector<bool> visited(n);
    std::vector<int> time(n);
    std::stack<int> s;
    s.push(0);
    visited[0] = true;
    int count = 1;
    while(!s.empty()){
        //prints(s);
        int k = s.top();
        std::vector<int> v = g[k];
        bool state = true;
        count += 1;
        for(int &x : v){
            if(!visited[x]){
                s.push(x);
                visited[x] = true;
                state = false;
                break;
            }
        }
        if(state){
            time[k] = count;
            s.pop();
        }
        if(s.empty()){
            int next = check(visited);
            if(next != -1){
                s.push(next);
                count += 1;
                visited[next] = true;
            }
        }
    }
    return time;
}

int main(){
    std::cin >> n;
    vv g(n);
    vv gt(n);
    for(int i = 0; i < n; i++){
        int m;
        std::cin >> m;
        for(int j = 0; j < m; j++){
            int a;
            std::cin >> a;
            g[i].push_back(a);
            gt[a].push_back(i);
        }
    }
    std::vector<int> time= timing(gt);
    std::vector<bool> visited(n);
    int max_pos = findmax(time,visited);
    std::vector<int> ans;
    while(max_pos != -1){
        ans.push_back(dfs(g,visited,max_pos));
        max_pos = findmax(time,visited);
    }
    std::sort(ans.begin(),ans.end());
    print(ans);
}