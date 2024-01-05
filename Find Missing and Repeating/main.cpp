class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int repeatingNumber=-1;
        int missingNumber=-1;
        
        int i=0;
        while(i<n)
        {
            if(arr[i]!=arr[arr[i]-1])
            {
                swap(arr[i],arr[arr[i]-1]);
            }
            else
            {
                i++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=i+1)
            {
                repeatingNumber=arr[i];
                missingNumber=i+1;
            }
        }
        return {repeatingNumber,missingNumber};
    }
};
