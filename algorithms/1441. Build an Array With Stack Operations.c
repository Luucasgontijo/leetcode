// 1441. Build an Array With Stack Operations
// https://leetcode.com/problems/build-an-array-with-stack-operations/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char** arr = (char**)malloc(2 * n * sizeof(char*));

    int index = 0, targetIndex = 0;

    for (int i = 1; i <= n; i++){
        arr[index] = (char*)malloc(5 * sizeof(char));
        strcpy(arr[index++], "Push");

        if (i != target[targetIndex]){
            arr[index] = (char*)malloc(5 * sizeof(char));
            strcpy(arr[index++], "Pop");
        } else {
            targetIndex++;
        }
        
        if (targetIndex == targetSize) {
            break;
        }
    }
    *returnSize = index;
    return arr;
}


