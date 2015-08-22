#include "BinaryTree.h"
int main()
{
	char prelist[]={'A','B','D',NULL,'G',NULL,NULL,NULL,'C','E',NULL,NULL,'F','H'};
	BinaryTree<char> bitree(prelist,14);
	cout<<bitree;
	bitree.inOrder();
	bitree.postOrder();
	bitree.inOrderTraverse();
	bitree.levelOrder();
	cout<<bitree.depth()<<endl;
	cout<<bitree.countLeaf()<<endl;
#if 0
	bitree.insert('x');
	cout<<bitree;
#endif
#if 0
	bitree.insert(bitree.root->right,'X',false);
	cout<<bitree;
#endif
	bitree.remove(bitree.root->left,true);
	cout<<bitree;
	system("pause");
	return 0;
}