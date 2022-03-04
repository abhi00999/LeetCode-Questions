// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	void merge(int ar1[], int ar2[], int n, int m) {
	    // code here
	    int gap = ceil((float)(n + m) / 2);
          while (gap > 0) {
            int i = 0;
            int j = gap;
            while (j < (n + m)) {
              if (j < n && ar1[i] > ar1[j]) {
                swap(ar1[i], ar1[j]);
              } else if (j >= n && i < n && ar1[i] > ar2[j - n]) {
                swap(ar1[i], ar2[j - n]);
              } else if (j >= n && i >= n && ar2[i - n] > ar2[j - n]) {
                swap(ar2[i - n], ar2[j - n]);
              }
              j++;
              i++;
            }
            if (gap == 1) {
              gap = 0;
            } else {
              gap = ceil((float) gap / 2);
            }
          }
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends