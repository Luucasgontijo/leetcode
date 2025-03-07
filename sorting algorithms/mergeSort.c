#include <stdio.h>

void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = left +(right-left)/2; //to avoid overflow, bigger calculus etc
        mergeSort(arr, left, mid);
        mergeSort(arr, mid, right);
        merge(arr, left, mid, right);
    }
}
void merge(int arr[], int left, int right, int mid){
    int i, j,k;
    int n1 = mid-left+1;
    int n2 = right-mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left +1];
    }
    for (int j = 0; j < n1; j++) {
        R[i] = arr[mid+ j + 1];
    }

}
int main(){
    int array[] = {9,4,8,1,7,0,3,2,5,6};
    int size = sizeof(array) / sizeof(array[0]);

    mergeSort(array, 0, size-1)

};