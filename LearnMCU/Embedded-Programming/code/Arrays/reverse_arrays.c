/**
 * You are given an array of integers and its length. Write a function to reverse the array in-place,
 *  without using another array.
 * 
 */

 #include <stdio.h>

void reverse_array(int arr[], int n) {
    int i = 0, j = n - 1;

    // Swap elements from front and back until the middle is reached
    while (i < j) {
        // Temporarily hold one element
        int temp = arr[i];

        // Swap front and back
        arr[i] = arr[j];
        arr[j] = temp;

        // Move indices towards the center
        i++;
        j--;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];

    // Read n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Reverse the array in-place
    reverse_array(arr, n);

    // Print the reversed array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n-1){
        	printf(" ");
        }
    }
    
    return 0;
}