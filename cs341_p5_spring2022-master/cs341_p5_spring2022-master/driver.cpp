#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;	// Ryan does not get a hi
#include "tree.h"

int main() {
	Tree<LicorIce> intTree;
	ifstream baby;
	LicorIce vanilla;
	int shatter1 = 1;
	int namCount = 0;


	baby.open("baby.txt");
		baby >> shatter1;
	while(shatter1 != 0){//runs a loop making the tree


	cout << shatter1 << endl;
	vanilla.makeBabies(shatter1);
	intTree.insertNode(vanilla);
	baby >> shatter1;
	}










	cout << "Preorder: ";
	intTree.preOrder();
	cout << endl;

	cout << "Inorder: ";
	intTree.inOrder();
	cout << endl;

	cout << "Postorder: ";
	intTree.postOrder();
	cout << endl;

	//intTree.leftRotate();
	//intTree.deleteNode(50);

	cout << "Preorder: ";
	intTree.preOrder();
	cout << endl;

	cout << "Inorder: ";
	intTree.inOrder();
	cout << endl;

	cout << "Postorder: ";
	intTree.postOrder();
	cout << endl;



	return 0;
}
