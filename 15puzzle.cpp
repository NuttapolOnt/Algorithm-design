#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

typedef std::priority_queue<std::pair<int,size_t>, std::vector<std::pair<int,size_t>>, std::greater<std::pair<int,size_t>>> pq;
typedef std::unordered_map<size_t,std::vector<int>> um;

bool up(std::vector<int> &v){
    int pos = v[16];
    if(pos - 4 >= 0) {
        std::swap(v[pos],v[pos-4]);
        v[16] = pos-4;
        v[17] = 1;
        return true;
    }
    return false;
}

bool down(std::vector<int> &v){
    int pos = v[16];
    if(pos + 4 < 16) {
        std::swap(v[pos],v[pos+4]);
        v[16] = pos + 4;
        v[17] = 2;
        return true;
    }
    return false;
}

bool left(std::vector<int> &v){
    int pos = v[16];
    if(pos%4 !=  0) {
        std::swap(v[pos],v[pos-1]);
        v[16] = pos-1;
        v[17] = 3;
        return true;
    }
    return false;
}

bool right(std::vector<int> &v){
    int pos = v[16];
    if(pos%4 !=  3) {
        std::swap(v[pos],v[pos+1]);
        v[16] = pos+1;
        v[17] = 4;
        return true;
    }
    return false;
}

const void printTable(const std::vector<int> &v){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int tmp = v[4*i+j] + 1;
            if(tmp == 16) tmp = 0;
            if(tmp < 10){
                std::cout << " " << tmp << " ";
            }
            else{
                std::cout << v[4*i+j]+1 << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "---------------\n";
}

void print(pq q){
    while(!q.empty()){
        std::cout << q.top().first << " ";
        q.pop();
    }
    std::cout << "\n";
}

int distance(std::vector<int> &v){
    int dis = 0;
    for(int i = 0; i < 16; i++){
        if(v[i] != 15){
            int tmp1 = std::abs((i%4)-(v[i]%4));
            int tmp2 = std::abs((i/4)-(v[i]/4));
            dis += (tmp1 + tmp2);
        }
    }
    return dis;
}

size_t hash(std::vector<int> &v){
    std::size_t seed = 16;
    for(int i = 0; i < 16; i++) {
        seed ^= v[i] + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}

pq q;
int min = -1;
um m;

void puzzle(){
    while(!q.empty()){
        while(!q.empty() && (q.top().first == 0 )){
            printTable(m[q.top().second]);
            if(m[q.top().second][18] < min || min == -1){
                min = m[q.top().second][18];
            }
            std::cout << min << "\n";
            q.pop();
        }
        if(q.empty()) break;
        std::vector<int> vref = m[q.top().second];
        int disref = q.top().first;
        q.pop();
        if(disref + vref[18] <  min || min == -1){
            if(up(vref)){
                size_t hashVector = hash(vref);
                if(m.find(hashVector) == m.end()){
                    vref[18] += 1;
                    m[hashVector] = vref;
                    q.push(std::make_pair(distance(vref), hashVector));
                    vref[18] -= 1;
                }
                down(vref);
            }
            if(down(vref)){
                size_t hashVector = hash(vref);
                if(m.find(hashVector) == m.end()){
                    vref[18] += 1;
                    m[hashVector] = vref;
                    q.push(std::make_pair(distance(vref), hashVector));
                    vref[18] -= 1;
                }
                up(vref);
            }
            if(left(vref)){
                size_t hashVector = hash(vref);
                if(m.find(hashVector) == m.end()){
                    vref[18] += 1;
                    m[hashVector] = vref;
                    q.push(std::make_pair(distance(vref), hashVector));
                    vref[18] -= 1;
                }
                right(vref);
            }
            if(right(vref)){
                size_t hashVector = hash(vref);
                if(m.find(hashVector) == m.end()){
                    vref[18] += 1;
                    m[hashVector] = vref;
                    q.push(std::make_pair(distance(vref), hashVector));
                    vref[18] -= 1;
                }
                left(vref);
            }
        }
    }
}


int main(){
    std::vector<int> v(19);
    v[16] = 0;
    v[17] = 0;
    v[18] = 0;
    int pos = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int tmp;
            std::cin >> tmp;
            if(tmp == 0){
                tmp = 16;
                v[16] = 4*i+j;
            }
            v[(4*i)+j] = tmp-1;
        }
    }
    m[hash(v)] = v;
    q.push(std::make_pair(distance(v),hash(v)));
    puzzle();
    std::cout << min << "\n";
}
/*1 2 3 4 5 6 7 8
9 10 11 0 13 14 15 12*/