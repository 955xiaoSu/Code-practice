#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e5;
 
int count;
int elem[MAX];
vector<pair<int,int> > edge[MAX + 10];
 
void dfs(int x, long long now, int pre){
    if (now> elem[x]) return;
    count++;
    
    int len = edge[x].size();
    for (int index = 0; index < len; index++){
        int y = edge[x][index].first;
        int w = edge[x][index].second;
        if (y == pre) continue;
        dfs(y, max(1LL * 0, now) + w, x);
    }
}
 
int main(){
    int totalNum = 0;  cin >> totalNum;
    for (int index = 1; index <= totalNum; index++) cin >> elem[index];
    
    int parent = 0, weight = 0;
    for (int index = 2; index <= totalNum; index++){
        cin >> parent >> weight;
        edge[index].push_back(make_pair(parent, weight));
        edge[parent].push_back(make_pair(index, weight));
    }
    dfs(1,0,-1);
    
    cout << totalNum - count;
    return 0;
}
