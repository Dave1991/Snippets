struct TrieNode {
	int count;
	vector<TrieNode*>children;
	TrieNode() :count(0) { children.resize(26); }
};
typedef void(*EnumFun)(vector<char>& word, int count);
class Trie {
private:
	TrieNode* root;
	void dfs(TrieNode* node, vector<char>& visited, EnumFun f) {
		for (int i = 0; i<node->children.size(); i++) {
			TrieNode* child = node->children[i];
			if (child != NULL) {
				visited.push_back(i + 'a');
				if (child->count>0) {
					f(visited, child->count);
				}
				dfs(child, visited, f);
				visited.pop_back();
			}
		}
	}
public:
	Trie() {
		root = new TrieNode();
	}
	void insert(string s) {
		int len = s.length();
		if (len>0) {
			TrieNode* node = root;
			for (int i = 0; i<len; i++) {
				if (node->children[s[i] - 'a'] == NULL) {
					node->children[s[i] - 'a'] = new TrieNode();
				}
				node = node->children[s[i] - 'a'];
			}
			node->count++;
		}
	}
	int search(string s) {
		int len = s.length();
		if (len>0) {
			TrieNode* node = root;
			for (int i = 0; i<len; i++) {
				if (node->children[s[i] - 'a'] == NULL) {
					return 0;
				}
				node = node->children[s[i] - 'a'];
			}
			return node->count;
		}
		return 0;
	}
	void traverse(EnumFun f) {
		vector<char>visited;
		dfs(root, visited, f);
	}
};