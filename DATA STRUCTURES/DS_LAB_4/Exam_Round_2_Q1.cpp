#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int maxArea(vector<int>& height) {
    int max_area = 0;
    int left = 0, right = height.size() - 1;

    while (left < right) {
        int width = right - left;
        int current_height = min(height[left], height[right]);
        int area = width * current_height;
        max_area = max(max_area, area);

        // Move the pointer pointing to the shorter line
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return max_area;
}

int main() {
    vector<int> height;
    int h;
    string line;
    getline(cin, line);

    istringstream ss(line);
    while (ss >> h)
        height.push_back(h);

    cout << maxArea(height) << endl;

    return 0;
}
