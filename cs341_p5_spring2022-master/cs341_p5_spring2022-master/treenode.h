#ifndef TREENODE_H
#define TREENODE_H

// forward declaration of a class Tree
template<typename NODETYPE> class Tree;

enum color {BLACK = 0, RED};

template<typename NODETYPE>

class TreeNode {
	friend class Tree<NODETYPE>;

	private:
		TreeNode<NODETYPE> * left;
		TreeNode<NODETYPE> * right;
		TreeNode<NODETYPE> * parent;
		NODETYPE data;
		color col;

	public:
		// Class setup
		TreeNode(const NODETYPE & d) : left(NULL), right(NULL), parent(NULL), data(d), col(RED) {}

		// Access function
		NODETYPE getData() const {return data;}
}; // end class TreeNode

#endif
