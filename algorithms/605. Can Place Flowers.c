// 605. Can Place Flowers
// https://leetcode.com/problems/can-place-flowers/description/

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (n == 0) return true;

    for (int i = 0; i < flowerbedSize; i++) {
        
        if (flowerbed[i] == 0) {
            int prev = (i == 0) ? 0 : flowerbed[i - 1];
            int next = (i == flowerbedSize - 1) ? 0 : flowerbed[i + 1];

            if (prev == 0 && next == 0) {
                flowerbed[i] = 1;
                n--;
                if (n == 0) return true;
            }
        }
    }

    return false;
}