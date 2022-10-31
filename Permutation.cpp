#include<iostream>
#include<vector>
#include<unordered_map>

typedef std::vector<int> vectorint;
typedef std::vector<std::pair<int,int>> vectorpair;
typedef std::vector<bool> vectorbool;
typedef std::unordered_map<int,int> unmap;

void print(vectorint &v){
    for(int &x: v){
        std::cout << x << " ";
    }
    std::cout << "\n";
}

void permu(vectorint &v, unmap &con, vectorbool used, int pos, int n){
    if(pos == n){
        print(v);
        return;
    }
    for(int i = 0; i < n; i++){
        if(con.find(i) != con.end()){
            if(used[con[i]] && !used[i]){
                v[pos] = i;
                used[i] = true;
                permu(v,con,used,pos+1,n);
                used[i] = false;
            }
        }
        else{
            if(!used[i]){
                v[pos] = i;
                used[i] = true;
                permu(v,con,used,pos+1,n);
                used[i] = false;
            } 
        }
    }
}

int main(){
    int n,m;
    std::cin  >> n >>m;
    vectorint v(n);
    unmap con;
    vectorbool used(n);
    for(int i = 0; i < n; i++){
        v[i] = i;
    }
    for(int i = 0; i < m; i++){
        int a,b;
        std::cin >> a >> b;
        con[b] = a;
    }
    permu(v,con,used,0,n);
}