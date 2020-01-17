/* Priyanshu kumar kharwar
   19HCS4041             */
#include<iostream>
#include<algorithm>
using namespace std;
bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
	int flag=0;
	if (startIndex<=lastIndex)
	{
		int middle=(startIndex+lastIndex)/2;
			if(element==array[middle])
			{
				return false;
			}
			else if(element<array[middle])
			{
				return binarySearchReacursive(array,startIndex,middle-1,element);
			}
			else
			{
				return binarySearchReacursive(array,middle+1,lastIndex,element);
			}	
	}
  return true;
}
bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
	int flag=0;
	while (startIndex<=lastIndex)
	{
		int middle=(startIndex+lastIndex)/2;
			if(element==array[middle])
			{
				return false;
			}
			else if(array[middle]>element)
			{
				lastIndex=middle-1;
			}
			else
			{
				startIndex=middle+1; 
			}
	}
	
  return true;
}

int main()
{
	int num;
	int nums;
	int numl;
	int n;
    cout<<"Enter the number of element in your array ";
    cin>>n;
    int *arr =new int[n];
    cout<<"Enter the element in the array ";
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
		sort(arr,arr+n);
	    cout<<"Elements in sorted form ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Enter the element to be searched in array ";
	cin>>num;
	nums=0;
	numl=n-1;
	if(binarySearchReacursive(arr,nums,numl,num))
	{
		cout<<"\nElement Not Found in array ";
	}
	else
	cout<<"\nElement Found in array ";
	cout<<endl;
	if(binarySearchIterative(arr,nums,numl,num))
	cout<<"\nElement Not Found in array ";
	else
	cout<<"\nElement Found in array ";
  return 0;
}
