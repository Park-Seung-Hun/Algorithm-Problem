#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int value;
	Node* leftN;
	Node* rightN;
};

Node* insert(Node* node, int value) {
	if (node == NULL) { // 노드가 초기화되지 않은 경우
		node = new Node();
		node->value = value;
		node->leftN = node->rightN = NULL;
	}
	else if (value >= node->value) { // 노드의 값보다 큰 값이 들어올 경우 (오른쪽 노드)
		node->rightN = insert(node->rightN, value);
	}
	else { // 노드의 값보다 작은 값이 들어올 경우 (왼쪽 노드)
		node->leftN = insert(node->leftN, value);
	}
	return node;
}

void postorder(Node* node) {
	if (node->leftN != NULL)
		postorder(node->leftN);
	if (node->rightN != NULL)
		postorder(node->rightN);
	cout << node->value << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Node를 만든다.
	Node* root = NULL;
	int val;
	// BST 초기화
	while (cin >> val) {
		if (val == EOF) break;
		root = insert(root, val);
	}
	postorder(root);

	return 0;
}
