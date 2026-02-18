// Count Inversions



class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int>&arr, int s, int mid, int e){
        int l=s, r=mid+1, cnt=0, idx=0;
        vector<int>temp(e-s+1);
        while(l<= mid && r<= e){
            if(arr[l] > arr[r]){
                temp[idx] = arr[r];
                cnt += (mid-l+1);
                idx++;
                r++;
            }else{
                temp[idx] = arr[l];
                l++;
                idx++;
            }
        }
        while(l<=mid){
            temp[idx] = arr[l];
            idx++;
            l++;
        }while(r<=e){
            temp[idx] = arr[r];
            idx++;
            r++;
        }
        idx=0;
        while(s<=e){
            arr[s] = temp[idx];
            s++;
            idx++;
        }
        return cnt;
    }
    int mergeSort(vector<int>& arr, int s, int e){
        if(s>=e) return 0;
        int mid = s + (e - s)/2;
        int inv =0;
        inv += mergeSort(arr,s,mid);
        inv += mergeSort(arr,mid+1,e);
        inv +=merge(arr,s,mid,e);
        return inv;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        return mergeSort(arr,0,arr.size()-1);
    }
};
