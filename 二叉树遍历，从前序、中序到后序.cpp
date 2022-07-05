#include <iostream>
#include <vector>
#include <string>
using namespace std;

string postorder = " ";
int index = 0;

void GetPost(string preorder, string inorder) {
	int len = preorder.length();
	if (len > 0) {
		char root = preorder[0];
		size_t pos = inorder.find(root);
		GetPost(preorder.substr(1, pos), inorder.substr(0, pos));
		GetPost(preorder.substr(pos + 1), inorder.substr(pos + 1));
		postorder[index++] = root;
	}
}

int main() {
	int len = 0;
	string preorder = " ", inorder = " ";
	vector<string> ans;
	
	while (cin >> len) {
		if (len == 0) break;
		cin >> preorder >> inorder;
		
		index = 0;
		postorder.clear();  postorder.resize(len);
		GetPost(preorder, inorder);
		ans.push_back(postorder);
	}	
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
