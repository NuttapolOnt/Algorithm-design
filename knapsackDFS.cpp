#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<iomanip>

typedef std::vector<std::pair<double,std::pair<double,double>>> vp;

vp r;
double k;
int n;
double max = -1;

void print(vp &v){
    for(auto &x : v){
        std::cout << x.first << " ";
    }
    std::cout << "\n";
}

double best(double value, double weight, int pos){
    double wref = weight;
    double vref = value;
    for(int i = pos; i < n; i++){
        double w = r[i].second.second;
        double v = r[i].second.first;
        if(w + wref < k){
            wref += w;
            vref += v;
        }
        else{
            vref += (((k-wref)/w) * v);
            wref = k;
            break;
        }
    }
    return vref;
}

void choose(double value, double weight, int pos){
    if(weight > k) {
        return;
    }
    if(pos == n){
        if(value > max) max = value;
        return;
    }
    if(best(value,weight,pos) < max) {
        return;
    }
    else{
        choose(value + r[pos].second.first, weight + r[pos].second.second, pos+1);
        choose(value, weight, pos+1);
    }
}

int main(){
    std::cin >> k >> n;
    std::vector<double> v(n);
    std::vector<double> w(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    for(int i = 0 ; i < n; i++){
        std::cin >> w[i];
    }
    for(int i = 0; i < n; i++){
        r.push_back(std::make_pair(v[i]/w[i],std::make_pair(v[i],w[i])));
    }
    std::sort(r.begin(),r.end(),std::greater<std::pair<double,std::pair<double,double>>>());
    choose(0,0,0);
    std::cout << std::fixed <<  std::setprecision(4) << max << "\n";
}







// std::cout << std::fixed <<  std::setprecision(4) << max;