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
bool isBigger(string& a, string& b) {
    int p1 = 0, p2 = 0;
    while (p1 < a.length() && a[p1++] == '0');
    while (p2 < b.length() && b[p2++] == '0');
    a = a.substr(p1 - 1, a.length() - p1 + 1);
    b = b.substr(p2 - 1, b.length() - p2 + 1);
    if (a.length() > b.length()) return true;
    else if (a.length() < b.length()) return false;
    else {
        int len = a.length();
        for (int i = 0; i < len; i++) {
            if (a[i] > b[i]) return true;
            else if (a[i] < b[i]) return false;
        }
        return true;
    }
}
string minus(string a, string b) {
    int len1 = a.length(), len2 = b.length();
    int p1 = len1 - 1, p2 = len2 - 1;
    stack<char> result;
    int downer = 0;
    while (p1 >= 0 && p2 >= 0) {
        if (a[p1] < b[p2]) {
            if (downer > 0) {
                result.push('0');
            } else {
                result.push('1');
            }
            downer = 1;
        } else if (a[p1] == b[p2]){
            if (downer > 0) {
                result.push('1');
            } else {
                result.push('0');
            }
        } else {
            if (downer > 0) {
                result.push('0');
                downer = 0;
            } else {
                result.push('1');
            }
        }
        p1--, p2--;
    }
    while (p1 >= 0) {
        if (downer > 0) {
            if (a[p1] == '0') {
                result.push('1');
            } else {
                result.push('0');
                downer = 0;
            }
        } else {
            result.push(a[p1]);
        }
        p1--;
    }
    string str = "";
    bool zeroFirst = true;
    while (!result.empty()) {
        if (result.top() != '0')
            zeroFirst = false;
        if (!zeroFirst)
            str.push_back(result.top());
        result.pop();
    }
    return str;
}
string divide(string a, string b) {
    int p1 = 0;
    string cur;
    string result;
    while (p1 < a.length()) {
        cur.push_back(a[p1]);
        if (isBigger(cur, b)) {
            result.push_back('1');
            cur = minus(cur, b);
        } else {
            result.push_back('0');
        }
        p1++;
    }
    return result;
}
