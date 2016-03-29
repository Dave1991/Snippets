template<typename T>
class Heap {
private:
	vector<T>nums;
public:
	Heap(vector<T>&_nums) :nums(_nums) {
		int size = nums.size();
		int mid = size / 2;
		for (int i = mid - 1; i >= 0; i--) {
			int j = i;
			while (true) {
				if (2 * j + 2<size) {
					if (nums[2 * j + 1] <= nums[2 * j + 2] && nums[j]>nums[2 * j + 1]) {
						swap(nums[j], nums[2 * j + 1]);
						j = 2 * j + 1;
					}
					else if (nums[2 * j + 2] <= nums[2 * j + 1] && nums[j]>nums[2 * j + 2]) {
						swap(nums[j], nums[2 * j + 2]);
						j = 2 * j + 2;
					}
					else
						break;
				}
				else if (2 * j + 1<size) {
					if (nums[2 * j + 1]<nums[j]) {
						swap(nums[2 * j + 1], nums[j]);
					}
					break;
				}
				else
					break;
			}
		}
	}
	void insert(T& num) {
		nums.push_back(num);
		int index = nums.size() - 1;
		while ((index - 1) / 2 >= 0) {
			if (nums[index]<nums[(index - 1) / 2]) {
				swap(nums[index], nums[(index - 1) / 2]);
				index = (index - 1) / 2;
			}
			else
				break;
		}
	}
	T top() {
		return nums[0];
	}
	void remove() {
		int size = nums.size();
		swap(nums[0], nums[size - 1]);
		nums.pop_back();
		int index = 0;
		size = nums.size();
		while (true) {
			if (2 * index + 2<size) {
				if (nums[2 * index + 1] <= nums[2 * index + 2] && nums[2 * index + 1]<nums[index]) {
					swap(nums[index], nums[2 * index + 1]);
					index = 2 * index + 1;
				}
				else if (nums[2 * index + 2] <= nums[2 * index + 1] && nums[2 * index + 2]<nums[index]) {
					swap(nums[index], nums[2 * index + 2]);
					index = 2 * index + 2;
				}
				else
					break;
			}
			else if (2 * index + 1<size) {
				if (nums[2 * index + 1]<nums[index]) {
					swap(nums[index], nums[2 * index + 1]);
				}
				break;
			}
			else
				break;
		}
	}
	bool empty() {
		return nums.empty();
	}
	int size() {
		return nums.size();
	}
};