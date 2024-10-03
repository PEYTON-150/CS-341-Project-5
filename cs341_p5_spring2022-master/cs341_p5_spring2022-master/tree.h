#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;
#include "treenode.h"
#include "licorIce.h"
template<typename NODETYPE> class Tree {
	private:
		TreeNode<NODETYPE> * root;

		typedef TreeNode<NODETYPE> * TreeNodePtr;

		// Helper functions
		void insertNodeHelper(TreeNodePtr & curr, const NODETYPE & value);
		TreeNodePtr deleteNodeHelper(TreeNodePtr & curr, const NODETYPE & value);

		void preOrderHelper(TreeNodePtr curr) const;
		void inOrderHelper(TreeNodePtr curr) const;
		void postOrderHelper(TreeNodePtr curr) const;

        
        // Red/Black recoloring helper functions
        void leftRotate(TreeNodePtr x);
        void rightRotate(TreeNodePtr y);
        void recolor(TreeNodePtr k);
		/*
        **********
        void doubleBlack(TreeNodePtr x);
		**********
        */
		TreeNode<NODETYPE> * search(const NODETYPE & value);
		TreeNode<NODETYPE> * searchHelper(TreeNodePtr curr, const NODETYPE & value) const;

	public:
		// Class setup
		Tree() { root = NULL; }
		~Tree();

		// Core functionality
		void insertNode(const NODETYPE & value) { insertNodeHelper(root, value); }
		void deleteNode(const NODETYPE & value) { deleteNodeHelper(root, value); }
		void preOrder() const { preOrderHelper(root); }
		void inOrder() const { inOrderHelper(root); }
		void postOrder() const { postOrderHelper(root); }

}; // end class Tree

#include "tree.inl"

#endif
