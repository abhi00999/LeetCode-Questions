// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends

//get min operation is also in O(1)
void push(stack<int>& s, int a){
// Your code goes here
    if(s.empty()){
        s.push(a);
    }
    else{
        int x=s.top();
        if(x>=a){
            s.push(a);
        }
        else{
            s.pop();
            s.push(a);
            s.push(x);
        }
    }

}

bool isFull(stack<int>& s,int n){
// Your code goes here
    return s.size()==n;
}

bool isEmpty(stack<int>& s){
// Your code goes here
    return s.size()==0;
}

int pop(stack<int>& s){
// Your code goes here
    int x=s.top();
    s.pop();
    return x;
}

int getMin(stack<int>& s){
// Your code goes here
    int x=s.top();
    s.pop();
    return x;
    

}