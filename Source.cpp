#include<iostream>
#include<queue>
using namespace std;
int tab = 0;
struct node {
	int key;
	node* left;
	node* right;
	node() {
		this->key = 0;
		this->left = NULL;
		this->right = NULL;
	}
	node(int key) {
		this->key = key;
		this->left = NULL;
		this->right = NULL;
	}
	node(int key, node* left, node* right) {
		this->key = key;
		this->left = left;
		this->right = right;
	}
};
class BinarySearchTreň {
	node* root;
public:
	BinarySearchTreň() {
		this->root = NULL;
	}
	BinarySearchTreň(node* root) {
		this->root = root;
	}
	node* Add(int key);
	node* Delete_elem(int x);
	node* Search_min();
	node* Search_max();
	node* Search_next(node* x);
	node* Search_prev(node* x);
	node* Search(int key);
	void Print();
	void Preorder_traversal();
	void Inorder_traversal();
	void Postorder_traversal();
	void Width_traversal();
	node* get_Parent(node* x);
	void delete_tree() {
		Delete_elem(root->key);
	}
};
node* BinarySearchTreň::get_Parent(node* x) {
	if (x == this->root)
		return NULL;
	node* parent = this->root;
	if (parent->left != NULL && parent->right != NULL) {
		while (1)
			if (parent->left == x || parent->right == x)
				break;
			else {
				if (x->key < parent->key) {
					parent = parent->left;
				}
				else {
					parent = parent->right;
				}
			}
	}
	return parent;
}
node* BinarySearchTreň::Search_min() {
	node* min = this->root;
	while (min->left != NULL) {
		min = min->left;
	}
	return min;
}
node* BinarySearchTreň::Search_max() {
	node* max = this->root;
	while (max->right != NULL) {
		max = max->right;
	}
	return max;
}
node* BinarySearchTreň::Search_next(node* x) {
	BinarySearchTreň tmp;
	if (x->right != NULL) {
		tmp = BinarySearchTreň(x->right);
		return tmp.Search_min();
	}
	node* y = get_Parent(x);
	while (y != NULL && x == y->right) {
		x = y;
		y = get_Parent(y);
	}
}
node* BinarySearchTreň::Search_prev(node* x) {
	BinarySearchTreň tmp;
	if (x->left != NULL) {
		tmp = BinarySearchTreň(x->left);
		return tmp.Search_max();
	}
	node* y = get_Parent(x);
	while (y != NULL && x == y->left) {
		x = y;
		y = get_Parent(y);
	}
}
node* BinarySearchTreň::Search(int key) {
	BinarySearchTreň tmp;
	if (this->root == NULL || this->root->key == key) {
		return this->root;
	}
	else
		if (key < this->root->key) {
			tmp = BinarySearchTreň(this->root->left);
			return tmp.Search(key);
		}
		else {
			tmp = BinarySearchTreň(this->root->right);
			return tmp.Search(key);
		}
}
node* BinarySearchTreň::Add(int key) {
	BinarySearchTreň tmp;
	if (this->root == NULL) {
		this->root = new node(key);
	}
	else
		if (key < this->root->key) {
			tmp = BinarySearchTreň(this->root->left);
			this->root->left = tmp.Add(key);
		}
		else {
			tmp = BinarySearchTreň(this->root->right);
			this->root->right = tmp.Add(key);
		}
	return this->root;
}
void BinarySearchTreň::Preorder_traversal() {
	BinarySearchTreň tmp;
	if (this->root != NULL) {
		cout << this->root->key << ' ';
		tmp = BinarySearchTreň(this->root->left);
		tmp.Preorder_traversal();
		tmp = BinarySearchTreň(this->root->right);
		tmp.Preorder_traversal();
	}

 }
void BinarySearchTreň::Inorder_traversal() {
	BinarySearchTreň tmp;
	if (this->root != NULL) {
		tmp = BinarySearchTreň(this->root->left);
		tmp.Inorder_traversal();
		cout << this->root->key << ' ';
		tmp = BinarySearchTreň(this->root->right);
		tmp.Inorder_traversal();
	}
 }
void BinarySearchTreň::Postorder_traversal() {
	BinarySearchTreň tmp;
	if (this->root != NULL) {
		tmp = BinarySearchTreň(this->root->left);
		tmp.Postorder_traversal();
		tmp = BinarySearchTreň(this->root->right);
		tmp.Postorder_traversal();
		cout << this->root->key << ' ';
	}
 }
void BinarySearchTreň::Width_traversal() {
	deque<node> Width;
	Width.push_back(*this->root);
	while (!Width.empty()) {
		cout << Width.front().key << ' ';
		if (Width.front().left != NULL)
			Width.push_back(*Width.front().left);
		if (Width.front().right != NULL)
			Width.push_back(*Width.front().right);

		Width.pop_front();
	}
 }
node* BinarySearchTreň::Delete_elem(int x) {
	BinarySearchTreň tmp;
	if (this->root == NULL)
		return this->root;
	if (x < this->root->key) {
		tmp = BinarySearchTreň(this->root->left);
		this->root->left = tmp.Delete_elem(x);
	}
	else
		if (x > this->root->key) {
			tmp = BinarySearchTreň(this->root->right);
			this->root->right = tmp.Delete_elem(x);
		}
		else
			if (this->root->left != NULL && this->root->right != NULL) {
				tmp = BinarySearchTreň(this->root->right);
				this->root->key = tmp.Search_min()->key;
				this->root->right = tmp.Delete_elem(this->root->key);
			}
			else
				if (this->root->left != NULL)
					this->root = this->root->left;
				else if (this->root->right != NULL)
					this->root = this->root->right;
				else
					this->root = NULL;
	return root;
}
void BinarySearchTreň::Print()
{
	BinarySearchTreň tmp;
	if (!this->root)
		return;
	tab += 5;
	tmp = BinarySearchTreň(this->root->right);
	tmp.Print();
	for (int i = 0; i < tab; i++)
		cout << " ";
	cout << "->";
	cout << root->key << endl;
	tmp = BinarySearchTreň(this->root->left);
	tmp.Print();
	tab -= 5;
	return;
}
int main() {
	BinarySearchTreň tree, tmp;
	int key = 0;
	cout << "Put the tree" << endl;
	for (int i = 0; i < 16; i++) {
		cin >> key;
		tree.Add(key);
	}
	cout << "tree: " << endl;
	tree.Print();
	cout << "\nInorder travesal: " << endl;
	tree.Inorder_traversal();
	cout << "\nPreorder travesal: " << endl;
	tree.Preorder_traversal();
	cout << "\nPostorder travesal: " << endl;
	tree.Postorder_traversal();
	cout << "\nWidth travesal: " << endl;
	tree.Width_traversal();
	int el = 0;
	node* x;
	cout << "\nPut the element: " << endl;
	cin >> el;
	x = tree.Search(el);
	tmp = BinarySearchTreň(x);
	tmp.Print();
	tree.get_Parent(x);
	if (tree.Search_next(x) == NULL)
		cout << "\nNext element: NULL" << endl;
	else
		cout << "\nNext element: " << endl << tree.Search_next(x)->key << endl;
	if (tree.Search_prev(x) == NULL)
		cout << "\nPrev element: NULL" << endl;
	else
		cout << "\nPrev element: " << endl << tree.Search_prev(x)->key << endl;
	tree.Delete_elem(el);
	cout << "after deleted: " << endl;
	tree.Print();
	tree.Width_traversal();
	tree.delete_tree();
	return 0;
}