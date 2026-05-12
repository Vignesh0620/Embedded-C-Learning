/*Left Rotate Array by K Positions
You are given an array of size n and an integer k. Rotate the array left by k positions, in-place (without using any extra array).

This means the elements that go beyond the first k positions should wrap around to the end.


Example-1

Input: n = 5, k = 2, arr = [1 2 3 4 5]
Output:[3  4  5  1  2]

Example-2

Input: n = 4, k = 1, arr = [10 20 30 40]
Output:[20  30  40  10]
 */

 #include <stdio.h>

void rotate_left(int arr[], int n, int k) {
    // Your logic here
    //if k is larger than n take it's modulo
    k = k % n;
    //reverse first k elements
    for(int i=0,j=k-1;i<j;i++,j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    //reverse n-k elements
    for(int i=k,j=n-1;i<j;i++,j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    //reverse whole array
    for(int i=0,j=n-1;i<j;i++,j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[100];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Rotate the array
    rotate_left(arr, n, k);

    // Print the rotated array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n-1){
        	printf(" ");
        }
    }

    return 0;
}