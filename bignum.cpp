string bigAdd(string num1, string num2) {
	int upper = 0;
	stack<char>resstack;
	int len1 = num1.length(), len2 = num2.length();
	int index1 = len1 - 1, index2 = len2 - 1;
	while (index1 >= 0 && index2 >= 0) {
		int tmp = num1[index1] - '0' + num2[index2] - '0' + upper;
		int cur = tmp % 10;
		upper = tmp / 10;
		index1--; index2--;
		resstack.push(cur + '0');
	}
	while (index1 >= 0) {
		int tmp = num1[index1] - '0' + upper;
		int cur = tmp % 10;
		upper = tmp / 10;
		index1--;
		resstack.push(cur + '0');
	}
	while (index2 >= 0) {
		int tmp = num2[index2] - '0' + upper;
		int cur = tmp % 10;
		upper = tmp / 10;
		index2--;
		resstack.push(cur + '0');
	}
	if (upper>0)
		resstack.push(upper + '0');
	ostringstream ostr;
	while (!resstack.empty()) {
		ostr << resstack.top();
		resstack.pop();
	}
	return ostr.str();
}
string multiply(string num, char c, int base) {
	int len = num.length();
	if (len == 0 || num == "0" || c == '0')return "0";
	int upper = 0;
	stack<char>resstack;
	for (int i = 0; i<base; i++)resstack.push('0');
	for (int i = len - 1; i >= 0; i--) {
		int tmp = (num[i] - '0')*(c - '0') + upper;
		resstack.push(tmp % 10+'0');
		upper = tmp / 10;
	}
	if (upper>0)resstack.push(upper+'0');
	ostringstream ostr;
	while (!resstack.empty()) {
		ostr << resstack.top();
		resstack.pop();
	}
	return ostr.str();
}
string bigMultiply(string num1, string num2) {
	vector<string>res;
	int len2 = num2.length();
	if (len2 == 0)return "";
	for (int i = len2 - 1; i >= 0; i--) {
		res.push_back(multiply(num1, num2[i], len2 - i - 1));
	}
	if (res.size() == 1)return res[0];
	else {
		string total = bigAdd(res[0], res[1]);
		for (int i = 2; i<res.size(); i++) {
			total = bigAdd(total, res[i]);
		}
		return total;
	}
}