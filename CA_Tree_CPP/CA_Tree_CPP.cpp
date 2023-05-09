#include <iostream>

using namespace std;

//binarni strom, jehož nody ukladaji číslo
struct Node{
	int data;
	Node* leftChild;
	Node* rightChild;
};

//funkce vytvoří novy node a vrátí referenci na něho
Node* createNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->leftChild = newNode->rightChild = nullptr;
	return newNode;
}

int main()
{
	Node* root = createNode(1);

	root->leftChild = createNode(2);
	root->rightChild = createNode(3);

	root->leftChild->leftChild = createNode(4);
}