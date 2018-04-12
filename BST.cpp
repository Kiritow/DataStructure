struct bstnode
{
	bstnode* left;
	bstnode* right;
	int data;
};

bstnode* SearchBST(bstnode* root, int key)
{
	if (root == NULL) return NULL;
	if (key == root->data) return root;
	if (key < root->data) return SearchBST(root->left, key);
	else return SearchBST(root->right, key);
}

/// May change root if root is empty.
bstnode* InsertBST(bstnode*& root, int key)
{
	if (root == NULL)
	{
		bstnode* newNode = new bstnode;
		newNode->data = key;
		newNode->left = newNode->right = NULL;
		root = newNode;
		return root;
	}
	if (root->data == key) /// Have already the same value in tree. No insert operation.
	{
		return root;
	}
	if (key < root->data)
	{
		return InsertBST(root->left, key);
	}
	else
	{
		return InsertBST(root->right, key);
	}
}

bstnode*& GetMinValueBST(bstnode*& root)
{
	if (root->left == NULL && root->right == NULL)
	{
		return root;
	}
	else if(root->left==NULL)
	{
		bstnode*& rightMin = GetMinValueBST(root->right);
		if (rightMin->data < root->data)
		{
			return rightMin;
		}
		else
		{
			return root;
		}
	}
	else if (root->right == NULL)
	{
		bstnode*& leftMin = GetMinValueBST(root->left);
		if (leftMin->data < root->data)
		{
			return leftMin;
		}
		else
		{
			return root;
		}
	}
	else
	{
		bstnode*& leftMin = GetMinValueBST(root->left);
		bstnode*& rightMin = GetMinValueBST(root->right);
		if (leftMin->data < rightMin->data && leftMin->data < root->data)
		{
			return leftMin;
		}
		else if(rightMin->data < leftMin->data && rightMin->data < root->data)
		{
			return rightMin;
		}
		else
		{
			return root;
		}
	}
}

bool RemoveBST(bstnode*& root, int key)
{
	if (root == NULL) return false;
	if (root->data == key)
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if (root->left == NULL)
		{
			bstnode* thisNode = root;
			root = root->right;
			delete thisNode;
		}
		else if (root->right == NULL)
		{
			bstnode* thisNode = root;
			root = root->left;
			delete thisNode;
		}
		else
		{
			/// Find the min value in right sub tree.
			bstnode*& target = GetMinValueBST(root->right);
			root->data = target->data;
			RemoveBST(target, target->data);
		}

		return true;
	}
	else if(key < root->data)
	{
		return RemoveBST(root->left, key);
	}
	else
	{
		return RemoveBST(root->right, key);
	}
}
