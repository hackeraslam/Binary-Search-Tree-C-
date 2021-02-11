
#include<iostream>
using namespace std;
// Aslam Khan
class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node();

};

Node::Node()
{
	data = 0;
	left = NULL;
	right = NULL;
}

class Tree
{
public:
	Node* root;

	Tree();

	bool Isempty();
	void InsertNode(Node*);
	void Preoreder(Node*);
	void Postorder(Node*);
	void Inorder(Node*);
	bool Search(int);
	Node* Minimum_Value(Node*);
	Node* Delete(Node*, int);



};

int main()
{
	Tree T;
	int ch;
	int data;
	bool flag, found;
	int arr[] = { 46,15,70,45,35,54,19,12,68,59 };// to check the program
	for (int i = 0; i < 10; i++)// It will make 10 node manually and Assign values to it
	{
		Node* t = new Node();
		data = arr[i];
		t->data = data;
		T.InsertNode(t);
	}
	system("cls");
	while (true)
	{
		cout << "1 = Insert new node" << endl;
		cout << "2 = Search Node" << endl;
		cout << "3 = Print Pre-order" << endl;
		cout << "4 = Print In-order" << endl;
		cout << "5 = Print Post-order" << endl;
		cout << "6 = Delete Node" << endl;
		cout << "Enter Choice = ";
		Node* n = new Node();
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter Data for New Node = ";
			cin >> data;
			n->data = data;
			T.InsertNode(n);

			break;
		case 2:
			cout << "Enter Data to Search for = ";
			cin >> data;
			found = T.Search(data);
			if (found)
			{
				cout << "Value Found.." << endl;

			}
			else
			{
				cout << "Value Not Found..." << endl;
			}
			break;

		case 3:
			cout << "Pre-order" << endl;
			T.Preoreder(T.root);
			break;
		case 4:
			cout << "In-order" << endl;
			T.Inorder(T.root);
			break;
		case 5:
			cout << "Post-order" << endl;
			T.Postorder(T.root);
			break;
		case 6:
			cout << "Delete Node" << endl;
			cout << "Enter Value to Delete = ";
			cin >> data;
			flag = T.Search(data);
			if (flag)
			{
				T.Delete(T.root, data);
				cout << "Value Deleted..." << endl;
			}
			else
			{
				cout << "Value Not Found..." << endl;
			}

			break;

		default:
			cout << "Invalid option entered..." << endl;
			break;
		}
		cout << endl << endl;
		system("pause");
		system("cls");
	}




	system("pause");
}

Tree::Tree()
{
	root = NULL;
}

void Tree::Preoreder(Node* r)
{
	if (r == NULL)
	{
		return;
	}
	cout << r->data << ", ";
	Preoreder(r->left);
	Preoreder(r->right);

}

void Tree::Postorder(Node* r)
{
	if (r == NULL)
	{
		return;
	}
	Postorder(r->left);
	Postorder(r->right);
	cout << r->data << ", ";
}

void Tree::Inorder(Node* r)
{
	if (r == NULL)
	{
		return;
	}
	Inorder(r->left);
	cout << r->data << ", ";
	Inorder(r->right);
}
bool Tree::Isempty()
{
	if (root == NULL)
	{
		return true;

	}
	else
	{
		return false;
	}
}

void Tree::InsertNode(Node* n)
{
	if (Isempty())
	{
		root = n;
		cout << "Node Inserted..." << endl;

	}
	else
	{
		Node* temp = root;
		while (temp != NULL)
		{
			if (n->data == temp->data)
			{
				cout << "No Duplicate data..." << endl;
				break;
			}
			else if (n->data < temp->data && temp->left == NULL)
			{
				temp->left = n;
				cout << "Node Inserted..." << endl;
				break;

			}
			else if (n->data < temp->data)
			{
				temp = temp->left;
			}
			else if (n->data > temp->data && temp->right == NULL)
			{
				temp->right = n;
				cout << "Node Inserted.." << endl;
				break;
			}
			else
			{
				temp = temp->right;
			}
		}
	}
}

bool Tree::Search(int d)
{
	bool flag = false;
	Node* temp = root;
	if (root == NULL)
	{
		return false;

	}
	else
	{
		while (temp != NULL)
		{

			if (d == root->data)
			{
				flag = true;
				break;
			}
			else if (d < temp->data)
			{
				temp = temp->left;
			}
			else if (d == temp->data)
			{
				flag = true;
				break;
			}
			else if (d > temp->data)
			{
				temp = temp->right;
			}
			else if (d < temp->data && temp->left == NULL)
			{
				flag = false;
				break;
			}
			else
			{
				cout << "Value not found.." << endl;
				break;
			}

		}

	}
	return flag;
}

Node* Tree::Minimum_Value(Node* root)
{
	if (root->left == NULL)
	{
		return root;
	}
	else
	{
		Minimum_Value(root->left);
	}
}

Node* Tree::Delete(Node* root, int val)
{
	if (root == NULL)
	{
		return root;
	}
	else if (val < root->data)
	{
		root->left = Delete(root->left, val);
	}
	else if (val > root->data)
	{
		root->right = Delete(root->right, val);
	}
	else
	{
		Node* temp;
		if (root->left == NULL)
		{
			temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			delete root;
			return temp;
		}
		else
		{
			temp = Minimum_Value(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);

		}
	}
	return root;

}
