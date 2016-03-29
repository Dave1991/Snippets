int patition(vector<int>&nums,int left,int right){
	if(left==right)return left;
	else if(left+1==right){
		if(nums[left]<=nums[right])return left;
		else{
			swap(nums[left],nums[right]);
			return right;
		}
	}else{
		int i=left+1,j=right;
		while(i<j){
			while(i<j&&nums[i]<nums[left])i++;
			while(i<j&&nums[j]>=nums[left])j--;
			if(i<j)swap(nums[i],nums[j]);
		}
		if(nums[i]<nums[left]){
			swap(nums[i],nums[left]);
			return i;
		}
		else{
			swap(nums[i-1],nums[left]);
			return i-1;
		} 
	}
}
void qsort(vector<int>&nums,int left,int right){
	if(left==right)return;
	int mid=patition(nums,left,right);
	if(mid>left)
		qsort(nums,left,mid-1);
	if(mid<right)
		qsort(nums,mid+1,right);
}
void qsort(vector<int>&nums){
	qsort(nums,0,nums.size()-1);
}