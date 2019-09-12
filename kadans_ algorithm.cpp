#include<bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    return(a<b);
}
void Max_sum_subarray(int arr[],int n)
{
    int current_sum,global_sum;
    int start_index;int end_index;int temp_index;
    current_sum=global_sum=arr[0];
    start_index=end_index=temp_index=0;
    for(int i=1;i<n;i++)
    {
        global_sum=std::max({arr[i],arr[i]+current_sum,global_sum},comp);
        current_sum=std::max(arr[i],arr[i]+current_sum);
        if(current_sum==arr[i])
        {
           // current_sum=arr[i]+current_sum;
           // temp_index=i;
            if(global_sum==current_sum)
            {  
               temp_index=start_index=i;
               end_index=i;
            }
           // end_index=i;
        }
        else if(current_sum>arr[i])
        {
          // 
            if(global_sum==current_sum)
               {
                   start_index=temp_index;
                   end_index=i;
               }
             
        }
       
    }
    cout<<"Max max_sum_subarray is "<<global_sum<<endl;
    cout<<"sub array is: [ ";
    for(int i=start_index;i<=end_index;i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<"]";
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    Max_sum_subarray(arr,n);
return 0;
}
