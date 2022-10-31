#include<iostream>
#include<vector>

typedef std::vector<std::vector<int>> vv;

int n,m;
vv v;

void print(std::vector<int> &v){
    for(int &x : v){
        std::cout << x << " ";
    }
    std::cout << "\n";
}

bool check(std::vector<int> &color,int k, int pos){
    for(int &x : v[pos]){
        if(color[x] == k) return false;
    }
    return true;
}

int count(std::vector<int> &color){
    int c = 0;
    std::vector<bool> vb(n,false);
    for(int i = 0; i < n; i++){
        if(color[i] != -1){
            vb[color[i]] = true;
        }
    }
    for(int i = 0; i < n; i++){
        if(vb[i]) c += 1;
    }
    return c;
}

int min = 0;

void coloring(std::vector<int> &color, int pos){
    if(pos == n){
        int c = count(color);
        if(c < min){
            min = c;
        }
        return;
    }
    if(count(color) > min) return;
    for(int i = 0; i < n; i++){
        if(check(color,i,pos)) {
            color[pos] = i;
            coloring(color, pos+1);
        }
    }
}

int main(){
    std::cin >> n >> m;
    min = n;
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