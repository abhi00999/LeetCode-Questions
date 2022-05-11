// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string str){
        // Code Here
    int i, j,MAX=26, n=str.size();
    // To store the first index of
    // every character of str
    int chk[MAX];
    for (i = 0; i < MAX; i++)
        chk[i] = -1;
  
    // Store the first occurring
    // index every character
    for (i = 0; i < n; i++) {
  
        // If current character is appearing
        // for the first time in str
        if (chk[str[i] - 'a'] == -1)
            chk[str[i] - 'a'] = i;
    }
  
    // Starting from the leftmost character
    for (i = 0; i < n; i++) {
  
        bool flag = false;
  
        // For every character smaller than str[i]
        for (j = 0; j < str[i] - 'a'; j++) {
  
            // If there is a character in str which is
            // smaller than str[i] and appears after it
            if (chk[j] > chk[str[i] - 'a']) {
                flag = true;
                break;
            }
        }
  
        // If the required character pair is found
        if (flag)
            break;
    }
  
    // If swapping is possible
    if (i < n) {
  
        // Characters to be swapped
        char ch1 = str[i];
        char ch2 = char(j + 'a');
  
        // For every character
        for (i = 0; i < n; i++) {
  
            // Replace every ch1 with ch2
            // and every ch2 with ch1
            if (str[i] == ch1)
                str[i] = ch2;
  
            else if (str[i] == ch2)
                str[i] = ch1;
        }
    }
  
    return str;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends