#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<int> vec = {1, 3, 4, 5, 7, 9, 10, 11, 12, 13, 13, 13, 17, 19, 20};
    int key;
    int index;

    key = 12;
    auto it = lower_bound(vec.begin(), vec.end(), key);
    index = distance(vec.begin(), it);
    if (it != vec.end() && *it == key) {
        cout << key << " found at index: " << index << endl;
    } else {
        cout << key << " not found in the vector. It should be inserted at " << index << endl;
    }

    key = 13;
    it = lower_bound(vec.begin(), vec.end(), key);
    index = distance(vec.begin(), it);
    if (it != vec.end() && *it == key) {
        cout << key << " found at index: " << index << endl;
    } else {
        cout << key << " not found in the vector. It should be inserted at " << index << endl;
    }

    key = 15;
    it = lower_bound(vec.begin(), vec.end(), key);
    index = distance(vec.begin(), it);
    if (it != vec.end() && *it == key) {
        cout << key << " found at index: " << index << endl;
    } else {
        cout << key << " not found in the vector. It should be inserted at index: " << index << endl;
    }

    return 0;
}