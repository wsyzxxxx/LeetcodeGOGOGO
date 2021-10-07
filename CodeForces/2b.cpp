#include <bits/stdc++.h>

int n;
std::string nums;

bool solve() {
    int start = 0;
    int end = nums.size() - 1;
    
    long long leftSum = 0;
    long long rightSum = 0;
    int leftCount = 0;
    int rightCount = 0;

    while (start < end) {
        if (nums[start] == '?') {
            leftCount++;
        } else {
            leftSum += nums[start] - '0';
        }
        if (nums[end] == '?') {
            rightCount++;
        } else {
            rightSum += nums[end] - '0';
        }

        start++;
        end--;
    }

    if (leftCount == rightCount) {
        return leftSum == rightSum;
    } else {
        int temp = std::min(leftCount, rightCount);
        leftCount -= temp;
        rightCount -= temp;

        if (rightCount == 0) {
            return rightSum > leftSum && (rightSum - leftSum) % 9 == 0 && (rightSum - leftSum) / 9 == leftCount / 2;
        } else {
            return rightSum < leftSum && (leftSum - rightSum) % 9 == 0 && (leftSum - rightSum) / 9 == rightCount / 2;
        }
    }
}

int main() {
    std::cin >> n;
    std::cin >> nums;

    bool result = solve();
    if (result) {
        std::cout << "Bicarp" << std::endl;
    } else {
        std::cout << "Monocarp" << std::endl;
    }
    return EXIT_SUCCESS;
}