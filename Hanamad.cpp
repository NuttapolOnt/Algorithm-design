#include<iostream>
#include<vector>


void mat(int val, int x,int y, int len, std::vector<int> &v, std::vector<int> &ans, int n){
    if(len == n){
        return;
    }
    ans[y] += (val*v[x]);
    ans[y] += (val*v[x+len]);
    ans[y+len] += (val*v[x]);
    ans[y+len] += ((-1)*val*v[x+len]);
    mat(val,x,y,len*2,v,ans,n);
    mat(val,x+len,y,len*2,v,ans,n);
    mat(val,x,y+len,len*2,v,ans,n);
    mat(val*(-1),x+len,y+len,len*2,v,ans,n);
    return;
}



int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    std::vector<int> ans(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    mat(1,0,0,1,v,ans,n);
    for(int i = 0; i < n; i++){
        std::cout << ans[i] << " ";
    }
    return 0;
}