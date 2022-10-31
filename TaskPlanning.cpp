#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

typedef std::vector<std::vector<int>> vv;
typedef std::vector<std::pair<int,int>> vp;

int n;

void printp(vp &v){
    for(std::pair<int,int> &x : v){
        std::cout << "(" << x.first << "," << x.second << ")" << " ";
    }
    std::cout << "\n";
}

void print(vp &v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i].second << " ";
    }
    std::cout << "\n";
}

int check(std::vector<bool> &v){
    for(int i = 0; i < v.size(); i++){
        if(!v[i]) return i;
    }
    return -1;
}

vp planning(vv &g){
    vp ans;
    std::vector<bool> visited(n);
    std::stack<int> s;
    int count = 0;
    while(check(visited) != -1){
        //std::cout << "work\n";
        count += 1;
        int c = check(visited);
        s.push(c);
        visited[c] = true;
        while(!s.empty()){
            //std::cout << "work\n";
            bool state = true;
            int k = s.top();
            std::vector<int> v= g[k];
            for(int &x : v){
                if(!visited[x]){
                    count += 1;
                    s.push(x);
                    visited[x] = true;
                    state = false;
                    break;
                }
            }
            if(state){
                std::pair<int,int> p = std::make_pair(count ,k);
                ans.push_back(p);
                s.pop();
                count += 1;
            }
        }
    }
    return ans;
}

int main(){
    std::cin >> n;
    vv g(n);
    for(int i = 0; i < n; i++){
        int m;
        std::cin >> m;
        for(int j = 0; j < m; j++){
            int a;
            std::cin >> a;
            g[a].push_back(i);
        }
    }
    vp ans = planning(g);
    std::sort(ans.begin(), ans.end(), std::greater<std::pair<int,int>>());
    print(ans);
}/*4 1 1 2 3 2 0 0*/