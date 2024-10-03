template<typename NODETYPE>
Tree<NODETYPE>::~Tree() {
	while (root != NULL)
		deleteNode(root->data);
} // end destructor

template<typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNodePtr & curr, const NODETYPE & value) {
	// If the subtree is empty, then we have found our new nesting place.
	// This is the base case, so let's create the new node.
	if (curr == NULL) {
		curr = new TreeNode<NODETYPE>(value);
		return;
	}
	if (value <= curr->data)
		insertNodeHelper(curr->left, value);
	else
		insertNodeHelper(curr->right, value);
	recolor(search(value));
} // end insertNodeHelper

template<typename NODETYPE>
TreeNode<NODETYPE> * Tree<NODETYPE>::deleteNodeHelper(TreeNodePtr & curr, const NODETYPE & value) {
	// If the subtree is empty, quit
	if (curr == NULL)
		return curr;
	else if (value < curr->data)
		curr->left = deleteNodeHelper(curr->left, value);
	else if (value > curr->data)
		curr->right = deleteNodeHelper(curr->right, value);
	else {
		// We know that curr->data == value, so we're ready to delete

		// Let's call the "node to be deleted" . . . . doomed
		// Case 1: (doomed has no children)
		if ((curr->left == NULL) && (curr->right == NULL)) {
			delete curr;
			curr = NULL;
		} // end case 1 if

		// Case 2: (doomed has one child)
		else if (curr->left == NULL) {
			TreeNodePtr temp = curr;
			curr = curr->right;
			delete temp;
		} // end case 2a if
		else if (curr->right == NULL) {
			TreeNodePtr temp = curr;
			curr = curr->left;
			delete temp;
		} // end case 2b if

		// Case 3: (doomed has two children)
		else {
			// Find the smallest element on the right side of the tree.
			TreeNodePtr smallestRight = curr->right;
			while (smallestRight->left != NULL)
				smallestRight = smallestRight->left;

            // Notice that you actually only ever delete a node with 0 or 1 child from the tree.
            // Nodes with two children are too big to fail.
			curr->data = smallestRight->data;
			curr->right = deleteNodeHelper(curr->right, smallestRight->data);
		} // end case 3
	} // end outside else

	return curr;
} // end deleteNodeHelper

template<typename NODETYPE>
void Tree<NODETYPE>::preOrderHelper(TreeNodePtr curr) const {
	if (curr == NULL)
		return;
	cout << curr->data << ' ';		// process the node
	preOrderHelper(curr->left);		// traverse the left subtree
	preOrderHelper(curr->right);	// traverse the right subtree
} // end preOrderHelper

template<typename NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNodePtr curr) const {
	if (curr == NULL)
		return;
	inOrderHelper(curr->left);		// traverse the left subtree
	cout << curr->data << ' ';		// process the node
	inOrderHelper(curr->right);		// traverse the right subtree
} // end inOrderHelper

template<typename NODETYPE>
void Tree<NODETYPE>::postOrderHelper(TreeNodePtr curr) const {
	if (curr == NULL)
		return;
	postOrderHelper(curr->left);	// traverse the left subtree
	postOrderHelper(curr->right);	// traverse the right subtree
	cout << curr->data << ' ';		// process the node
} // end postOrderHelper

template<typename NODETYPE>
void Tree<NODETYPE>::leftRotate(TreeNodePtr x) {
	TreeNodePtr y = x->right;
	x->right = y->left;
	if(y->left != NULL)
		y->left->parent = x;
	y->parent = x->parent;
	if(x->parent == NULL)
		this->root = y;
	else if(x->parent->left == x)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
} // end leftRotate

template<typename NODETYPE>
void Tree<NODETYPE>::rightRotate(TreeNodePtr x) {
	TreeNodePtr y = x->left;
	x->left = y->right;
	if(y->right != NULL)
		y->right->parent = x;
	y->parent = x->parent;
	if(x->parent == NULL)
		this->root = y;
	else if(x->parent->right == x)
		x->parent->right = y;
	else
		x->parent->left = y;
	y->right = x;
	x->parent = y;
} // end rightRotate

template<typename NODETYPE>
void Tree<NODETYPE>::recolor(TreeNodePtr x) {
	while(x->parent->col == RED)
	{
		if(x->parent == x->parent->parent->right){
			TreeNodePtr u = x->parent->parent->left;
			if(u->col == RED){
				u->col = BLACK;
				x->parent->col = BLACK;
				x->parent->parent->col = RED;
				x = x->parent->parent;
			}
			else{
				if(x==x->parent->left){
					x=x->parent;
					rightRotate(x);
				}
				x->parent->col = BLACK;
				x->parent->parent->col = RED;
				leftRotate(x->parent->parent);
			}
		}
		else{
			TreeNodePtr u = x->parent->parent->right;
			if(u->col == RED){
				u->col = BLACK;
				x->parent->col = BLACK;
				x->parent->parent->col = RED;
				x = x->parent->parent;
			}
			else{
				if(x==x->parent->left){
					x=x->parent;
					rightRotate(x);
				}
				x->parent->col = BLACK;
				x->parent->parent->col = RED;
				leftRotate(x->parent->parent);
			}
		}
	}
	root->col = BLACK;
} //end recolor

template<typename NODETYPE>
TreeNode<NODETYPE> * Tree<NODETYPE>::search(const NODETYPE & value)
{
	return searchHelper(root, value);
} //end search

template<typename NODETYPE>
TreeNode<NODETYPE> * Tree<NODETYPE>::searchHelper(TreeNodePtr curr, const NODETYPE & value) const
{
	if(curr == NULL)
		return curr;
	else if(value < curr->data)
		return searchHelper(curr->left, value);
	else if(value > curr->data)
		return searchHelper(curr->right, value);
	
	return curr;
} //end searchHelper