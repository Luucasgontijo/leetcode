// 11. Container With Most Water
//https://leetcode.com/problems/container-with-most-water/

int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int max_area = 0;
    while (left < right){
        int h = height[left] > height[right] ? height[right] : height[left];
        if ((right-left) * h > max_area) 
            max_area = (right-left) * h;
        
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max_area;
}