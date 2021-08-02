 #include <stdlib.h>
 #include <stdio.h>
 #include <stdbool.h>

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

//  Simply print and indent the console with tabs
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

bool insertNumber(treeNode **rootPtr, int value) {
    treeNode *root = *rootPtr;
    if (root == NULL) {
        /* Tree EMPTY */
        (*rootPtr) = createNode(value);
        return true;
    }

    if (value == root -> value) {
        /* do NOTHING */
        return false;
    }

    if (value < root -> value) {
        /* Look on the left side, else right side */
        return insertNumber(&(root -> left), value);
    } else {
        return insertNumber(&(root -> right), value);
    }  
}

bool findNumber(treeNode *root, int value) {
    if (root == NULL) return false;
    if (root -> value == value) {
        return true;
    }
    if (value < root -> value) {
        return findNumber(root -> left, value);
    } else {
        return findNumber(root -> right, value);
    }    
}


int main(int argc, char const *argv[]) {

	//	Declare the root
    treeNode *root = NULL;

    //  Declare the nodes
    insertNumber(&root, 15);
    insertNumber(&root, 11);
    insertNumber(&root, 24);
    insertNumber(&root, 5);
    insertNumber(&root, 16);
    insertNumber(&root, 19);

	//	Calls the function to print the whole tree
    printTree(root);

    //  Sees if you find or not what you're looking for
    //  Returns 1 if found
    //          0 if not found
    printf("%d (%d)\n", 16,  findNumber(root, 16));
    printf("%d (%d)\n", 15,  findNumber(root, 15));
    printf("%d (%d)\n", 5,   findNumber(root, 6));
    printf("%d (%d)\n", 125, findNumber(root, 125));
    printf("%d (%d)\n", 6,   findNumber(root, 6));
    printf("%d (%d)\n", 7,   findNumber(root, 7));


	system("pause");
	return 0;
}