class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] != 0) {
        int temp = arr[i];
        arr[i] = arr[count];
        arr[count] = temp;
        count++;
      }
    }
    for (int i = count; i < n; i++) {
      arr[i] = 0;
    } 
	}
};