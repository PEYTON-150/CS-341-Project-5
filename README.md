Project Description:
This project involved the design and implementation of a Red-Black Tree (RBTree), a self-balancing binary search tree. Our team worked collaboratively to augment an existing binary search tree (BST) implementation, ensuring it met the properties of a Red-Black Tree, which maintains balanced search operations for efficient insertions and deletions. The key features of our project included memory management, correct balancing, and ensuring that no memory leaks occurred during tree operations.
Objectives:
Red-Black Tree Augmentation:
Our primary goal was to enhance an existing BST implementation by adding key Red-Black Tree characteristics such as node color and parent pointers. These modifications ensured that the tree maintained balance and met the defined color properties of a Red-Black Tree.

Phase-wise Development:

Phase 1: Adding Node Colors and Parent Pointers
We began by adding two new variables to each tree node: a parent pointer and a color (using an enum with values RED and BLACK). This step was critical to maintaining the Red-Black Tree's color-balancing properties.

Phase 2: Code Modification for Node Colors and Parents
In this phase, we updated all the necessary tree functions to account for the new variables while ensuring their proper initialization and maintenance throughout the program.

Phase 3: Custom Class Implementation (LicorIce Class)
We created a custom class, LicorIce, which represented entities with a shatter score and weapon power. The class was integrated with the RBTree, replacing int types to demonstrate the tree's flexibility. This phase required the creation of shatter score-based nodes and random weapon-fire functionalities, adding complexity to our tree structure.

Phase 4: Tree Rotations
We implemented the crucial left and right rotations, which ensured the tree maintained balance after insertions and deletions. This involved careful handling of pointers to maintain the tree structure.

Phase 5: Insertion with Recoloring
The insertion method was modified to ensure that after every new node was inserted, the tree properties were checked and maintained. This involved recoloring and rotating nodes based on specific Red-Black Tree properties.
Memory Management and Valgrind Testing:
To ensure memory efficiency, we rigorously tested the project using Valgrind, an essential tool for detecting memory leaks. Our code was checked after each phase to ensure it was memory-leak-free, with no dangling pointers or unresolved memory issues.

Bonus Phase – Deletion with Custom Logic:
As an additional challenge, we tackled the deletion operation in the Red-Black Tree, which involved complex memory management and balancing tasks. This phase also incorporated custom rules based on the LicorIce class, adding a unique element of randomness to the deletion process.

Tools and Technologies:
C++ for core programming
Valgrind for memory leak detection
GitHub for version control and collaboration
Custom Makefile for building the project
Text-based input/output files for testing insertions and deletions
