#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int kInverse(vector<int> nums, int k){

    //tạo graph
    unordered_map<int, unordered_map<int,int>> graph;
    int n = nums.size();

    for (int i = n-1; i>=0; i--){

        //tất cả mọi điểm đều có 1 cách để tiến 0 bước
        graph[i][0] = 1;

        for (int j = i+1; j<n; j++){
            if (nums[i] > nums[j]){
                for (auto p : graph[j]){
                    //cộng bước của những phần tử (j) nhỏ hơn (i)
                    graph[i][p.first + 1] += p.second;
                }
            }
        }
    }

    int total = 0;
    for (int i = 0; i<n; i++){
        //tìm những phần tử mà có số cách đi k-1 bước, rồi cộng số bước đấy vào total
        for (auto p : graph[i]){
            if (p.first == k-1){
                total += graph[i][p.first];
            }
        }

    }
    
    return total;

}

int main(){


    vector<int> nums = {5,2,8,11,5,1,3};
    int k = 3;
    std::cout << kInverse(nums, k);

    return 0;

}