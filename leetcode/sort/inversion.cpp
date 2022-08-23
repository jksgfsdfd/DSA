//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    	int invcount(int *arr,int left,int right){
        	if(left>=right){
			return 0;
		}
		int mid=(left+right)/2;
        	int lcount=invcount(arr,left,mid);
        	int rcount=invcount(arr,mid+1,right);
        	int count=lcount+rcount;
        	int temp[right-left+1];
        	int i=left;
        	int j=mid+1;
        	int k=0;
        	while(i<=mid and j<=right){
            		if(arr[i]<=arr[j]){
                		temp[k++]=arr[i];
                		i++;
            		}else{
                		count+=mid-i+1;
                		temp[k++]=arr[j++];
            		}
        	}
        
        //if the remaining elements are that of left side,then count ++
        	while(i<=mid){
            		temp[k++]=arr[i++];
        	}
        
        	while(j<=right){
            		temp[k++]=arr[j++];
        	}
        	i=left;
        	for(k=0;k<(right-left+1);k++){
            		arr[i++]=temp[k];
        	}
        
        	return count;
    	}
    
    int inversionCount(int arr[], int N)
    {
        int start = 0;
        int *same=new int[N];
        for(int i=0;i<N;i++){
            same[i]=arr[i];
        }
        return invcount(same,start,N-1);
    }
    
    

};

//{ Driver Code Starts.

int main() {
    
        int N;
        cin >> N;
        
        int A[N];
        for(int i = 0;i<N;i++){
            cin >> A[i];
        }     
       
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    
    return 0;
}

// } Driver Code Ends
