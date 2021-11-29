#include <iostream>
using namespace std;
#include<unordered_map>
#include<unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include "math.h"
#include <stdlib.h>


int main() {
    vector<int> nums = {1,2,2,3,3,7};
    int ans = get_left(nums,7);
    cout<<ans<<endl;
    return 0;
}
