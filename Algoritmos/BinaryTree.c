 #include <stdlib.h>
 #include <stdio.h>

typedef struct treeNode {
	int value;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

treeNode *createNode(int value) {
	treeNode* result = malloc(sizeof(treeNode));
	if (result != NULL) {
		result -> left  = NULL;
		result -> right = NULL;
		result -> value = value;
	}
	return result;
}

void printTabs(int numTabs) {
	for (int i = 0; i < numTabs; i++) {
		printf("\t");
	}
}

void recursivePrintTree(treeNode *root, int level) {
	if (root == NULL) {
		printTabs(level);
		printf("<EMPTY>\n");
		return;
	}
	printTabs(level);
	printf("<Value = %d>\n", root -> value);
	printf("<Left>\n");
	recursivePrintTree(root -> left, level + 1);
	printTabs(level);
	printf("<Right>\n");
	recursivePrintTree(root -> right, level + 1);
	printTabs(level);
	printf("<Done>\n");
} 

void printTree(treeNode* root) {
	recursivePrintTree(root, 0);
}

int main(int argc, char const *argv[]) {
	//	Primary level of the tree
	int level = 0;

	//	Declare the nodes here
	treeNode *node1 = createNode(10);
	treeNode *node2 = createNode(66);
	treeNode *node3 = createNode(26);
	treeNode *node4 = createNode(13);
	treeNode *node5 = createNode(725);

	//	Afiliate the nodes with their branches
	//	As you will
	node1 -> left  = node2;
	node1 -> right = node3;
	node3 -> left  = node4;
	node3 -> right = node5;

	//	Calls the function to print the whole tree
	//	And climb the tree level 
	recursivePrintTree(node1 -> right, level + 1);

	//	Frees the nodes as you climb them
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);

	system("pause");
	return 0;
}