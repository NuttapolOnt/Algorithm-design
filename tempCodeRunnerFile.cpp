#include<iostream>
#include<vector>

typedef std::vector<std::vector<int>> vv;

int n,m;
vv v;

int count(std::vector<int> &color){
    int c = 0;
    std::vector<bool> check(n,false);
    for(int i = 0; i < n; i++){
        if(color[i] != -1){
            check[color[i]] = true;
        }
    }
    for(int i = 0; i < n; i++){
        if(check[i]) c += 1;
    }
    return c;
}

int min = -1;

void coloring(std::vector<int> &color, int pos){
    if(pos == n){
        int c = count(color);
        if(c < min || min == -1){
            min = c;
        }
        return;
    }
    if(count(color) > min && min != -1) return;
    for(int i = 0; i < n; i++){
        color[pos] = i;
        bool check = true;
        for(int &x : v[pos]){
            if(color[x] == color[pos]){
                check = false;
                break;
            }
        }
        if(check) coloring(color, pos+1);
    }
}

int main(){
    std::cin >> n >> m;
    for(int i = 0; i < n; i++){
        std::vector<int> tmp;
        v.push_back(tmp);
    }
    for(int i = 0; i < m; i++){
        int a,b;
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    std::vector<int> color(n,-1);
    coloring(color, 0);
    std::cout << min << "\n";
}
/*4 6 0 1 0 2 0 3 1 2 1 3 2 3*/