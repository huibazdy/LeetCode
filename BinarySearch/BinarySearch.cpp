#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(int target,vector<int> vec)
{
	int low = 0;
	int high = vec.size();
	
	while(low <= high)
	{
		int mid = low + (high - low) / 2;   //Don't:(low + high) / 2
		if(target < vec[mid])
			high = mid - 1;
		else if(target > vec[mid])
			low = mid + 1;
		else
			return mid;
	}
	/*cannot find target in the vector*/
	return -1;
}
