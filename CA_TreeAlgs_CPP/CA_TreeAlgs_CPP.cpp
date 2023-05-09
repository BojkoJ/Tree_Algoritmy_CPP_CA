#include <iostream>

using namespace std;

//jsou dva druhy algoritmu, pro procházení stromu:
//BFS a DFS (Breadth First Search) a (Depth First Search)
//aka do šířky a do hloubky

//v tomto mini-projektu se budeu soustředit na DFS

struct Node {
	int data;
	Node* leftChild;
	Node* rightChild;
};

Node* createNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->leftChild = newNode->rightChild = nullptr;
	return newNode;
}

//preorder
//rekurzivní funkce
void printTreePreorder(Node* root)
{
	if (root == nullptr) return;

	cout << root->data << " | "; //prvně se vypíšou data Nodu
	printTreePreorder(root->leftChild); //jde se do levého childu a zavolá se na něj funkce rekurzivně
	printTreePreorder(root->rightChild); //jde se do pravého childu a zavolá se na něj funkce rekurzivně
}

//inorder
//rekurzivní fuknce
void printTreeInorder(Node* root)
{
	if (root == nullptr) return;

	printTreeInorder(root->leftChild);
	cout << root->data << " | ";
	printTreeInorder(root->rightChild);
}

//postorder
//rekurzivní funkce
void printTreePostorder(Node* root)
{
	if (root == nullptr) return;

	printTreePostorder(root->leftChild);
	printTreePostorder(root->rightChild);
	cout << root->data << " | ";
}

int main()
{
	//vytvoření stromu pro procházení:
	//lvl 1
	Node* root = createNode(1);
	//lvl 2
	root->leftChild = createNode(2);
	root->rightChild = createNode(3);
	//lvl 3
	root->leftChild->leftChild = createNode(4);
	root->leftChild->rightChild = createNode(5);
	root->rightChild->leftChild = createNode(6);
	root->rightChild->rightChild = createNode(7);
	//lvl 4
	root->leftChild->rightChild->leftChild = createNode(9);
	root->rightChild->rightChild->leftChild = createNode(15);
	//---------------------------------------------------------

	//pro DFS existují 3 algoritmy:

	//preorder - prvně manipuluje s daty, pak jde do levého childu, zavolá se na něj a pak do pravého childu a zavolá se na něj
	//vypis preorder bude: 1,2,4,5,9,3,6,7,15

	cout << "preorder algorithm: ";
	printTreePreorder(root);
	cout << endl;

	//---------------------------------------------------------
	//inorder - prvně jde do levého childu, manipuluje data, pak jde do pravého childu
	//vypis inorder bude: 4,2,9,5,1,6,3,15,7

	cout << "inorder algorithm: ";
	printTreeInorder(root);
	cout << endl;

	//---------------------------------------------------------
	//postorder - left, right, data
	//vypis postorder bude: 4,9,5,2,6,15,7,3,1

	cout << "postorder algorithm: ";
	printTreePostorder(root);
	cout << endl;

}