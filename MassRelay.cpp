#include<iostream>
#include<vector>
#include<algorithm>

typedef std::vector<std::pair<int,std::pair<int,int>>> vp;

int n,m,q;

void print(vp &v){
    for(auto &x : v){
        std::cout << "(" << x.second.first << "," << x.second.second << "=" << x.first << ") "; 
    }
    std::cout << "\n";
}

void printv(std::vector<int> &v){
    for(int &x : v){
        std::cout << x << " ";
    }
    std::cout << "\n";
}

std::vector<int> massrelay(vp &g){
    std::vector<int> ans(n-1,-1);
    std::vector<bool> visited(n);
    std::vector<int> p(n);
    int count = 0;
    for(auto &x : g){
        //printv(ans);
        int l = x.second.first;
        int r = x.second.second;
        if(visited[l] && visited[r]){
            if(p[l] != p[r]){
                ans[count] = x.first;
                int tmp = p[l];
                for(int i = 0; i < p.size(); i++){
                    if(p[i] == tmp) p[i] = p[r];
                }
                count += 1;
            }
        }
        else if(visited[l]){
            ans[count] = x.first;
            p[r] = p[l];
            visited[r] = true;
            count ++;
        }
        else if(visited[r]){
            ans[count] = x.first;
            p[l] = p[r];
            visited[l] = true;
            count ++;
        }
        else{
            ans[count] = x.first;
            visited[l] = true;
            visited[r] = true;
            p[l] = r;
            p[r] = r;
            count ++;
        }
        if(count >= n) break;
    }
    return ans;
}

int main(){
    std::cin >> n >> m >> q;
    vp g;
    for(int i = 0; i < m; i++){
        int a,b,c;
        std::cin >> a >> b >>c;
        g.push_back(std::make_pair(c,std::make_pair(a,b)));
    }
    std::sort(g.begin(), g.end());
    //print(g);
    std::vector<int> ans = massrelay(g);
    printv(ans);
    for(int i = 0; i < q; i++){
        int x;
        std::cin >> x;
        std::cout << ans[n-x-1] << "\n";
    }
    return 0;
}/*5 6 4 0 1 20 0 2 10 2 3 30 1 3 10 2 4 40 3 4 50*/