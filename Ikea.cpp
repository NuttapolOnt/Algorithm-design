#include<iostream>
#include<vector>

typedef std::vector<std::vector<int>> vv;
typedef std::vector<std::vector<bool>> vb;

int n,e;

void print(std::vector<bool> v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << "\n--------------\n";
}

bool check(vv &g, std::vector<int> &v){
    std::vector<bool> done(n);
    for(int i = 0; i < n; i++){
        //print(done);
        std::vector<int> x = g[v[i]];
        bool state = false;
        if(x.size() == 0){
            done[v[i]] = true;
            state = true;
        }
        for(int &y : x){
            if(done[y]){
                done[v[i]] = true;
                state = true;
                break;
            }
        }
        if(!state){
            return false;
        }
    }
    return true;
}

int main(){
    std::cin >> n >> e;
    vv g(n);
    for(int i = 0; i < e; i++){
        int a,b;
        std::cin >> a >> b;
        g[b-1].push_back(a-1);
    }
    for(int i = 0; i < 5; i++){
        std::vector<int> v(n);
        for(int i = 0; i < n; i++){
            int a;
            std::cin >> a;
            a -= 1;
            v[i] = a;
        }
        if(check(g,v)){
            std::cout << "SUCCESS\n"; 
        }
        else{
            std::cout << "FAIL\n";
        }
    }
    return 0;
}