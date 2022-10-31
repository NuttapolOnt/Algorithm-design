#include<iostream>
#include<vector>

typedef std::vector<std::vector<int>> vv;

vv table;

int tri(vv &v, int x, int y, int n){
    if(y == n){
        table[y][x] = v[y][x];
        return v[y][x];
    }
    if(table[y][x] == -1){
        int lhs = tri(v,x,y+1,n);
        int rhs = tri(v,x+1,y+1,n);
        int ans = lhs>rhs ? lhs : rhs; 
        ans += v[y][x];
        table[y][x] = ans;
        return ans;
    }
    return table[y][x];
}

int main(){
    int n;
    std::cin >> n;
    vv v;
    for(int i = 1; i <= n; i++){
        std::vector<int> a(i);
        std::vector<int> b(i);
        for(int j = 0; j < i; j++){
            std::cin >> a[j];
            b[j] = -1;
        }
        v.push_back(a);
        table.push_back(b);
    }
    std::cout << tri(v,0,0,n-1);
}
