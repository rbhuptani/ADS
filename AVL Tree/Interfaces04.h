/**
 * \file Interfaces04.h
 *
 * \brief define interfaces of CSE 674 HW04
 *
 * This file defines the interfaces which are necessary for students to implement.
 * Students are expected to create new classes to inherit from the structs here, and
 * to implement the pure virtual functions.
 *
 * \attention You shall not edit this file.
 *
 */

#pragma once

#include <vector>
#include <cstdlib>


/**
 * \struct IAVLTreeNode
 *
 * This interface defines a node used in an AVL Tree. It is utilized in IAVLTree.
 *
 */
struct IAVLTreeNode {
  /// Constructor
  IAVLTreeNode() { }

  /// Destructor
  virtual ~IAVLTreeNode() { }

  /**
   * Set the left child of an AVL Tree Node.
   *
   * \param left new left child of the node
   *
   */
  virtual void setLeft(IAVLTreeNode *left) = 0;

  /**
   * Set the right child of an AVL Tree Node.
   *
   * \param right new right child of the node
   *
   */
  virtual void setRight(IAVLTreeNode *right) = 0;

  /**
   * Set the key of an AVL Tree Node.
   *
   * \param key new key of the node
   *
   */
  virtual void setKey(int key) = 0;

  /**
   * Get the left child of an AVL Tree Node.
   *
   * \return the left child of a node
   *
   */
  virtual IAVLTreeNode * getLeft() = 0;

  /**
   * Get the right child of an AVL Tree Node.
   *
   * \return the right child of a node
   *
   */
  virtual IAVLTreeNode * getRight() = 0;

  /**
   * Get the key of an AVL Tree Node.
   *
   * \return the key of a node
   *
   */
  virtual int getKey() = 0;
};


/**
 * \struct IAVLTree
 *
 * This interface is corresponding to Workload 1, AVL Tree. Students are expected
 * to implement a class which inherits from the interface, and provides operations
 * of an AVL Tree.
 *
 */
struct IAVLTree {
  /// Constructor
  IAVLTree() { }

  /// Destructor
  virtual ~IAVLTree() { }

  /**
   * Insert a new node with a key into the AVL Tree.
   *
   * \param key key of the new node inserted
   *
   */
  virtual void insert(int key) = 0;

  /**
   * Remove a node with a key from the AVL Tree.
   *
   * \param key key of the node removed
   *
   */
  virtual void remove(int key) = 0;

  /**
   * Get the kth minimum key of the AVL Tree. Please notice that k starts from 0.
   * An example: \n
   * Insert 7, 3, 10 \n
   * kthMin(k = 0): 3 \n
   * kthMin(k = 1): 7 \n
   *
   * \param k the index of the minimum key needed
   * \return the kth minimum key in the tree
   *
   */
  virtual int kthMin(int k) = 0;

  /**
   * Get the root node of an AVL Tree Node.
   *
   * \return root node
   *
   */
  virtual IAVLTreeNode * getRoot() = 0;
};

/**
 * \struct IKdNode
 *
 * This interface defines a node used in an Kd Tree. It is utilized in IKdTree.
 *
 */
struct IKdNode {
  /// Constructor
  IKdNode() { }

  /// Destructor
  virtual ~IKdNode() { }

  /**
   * Set the point contained in a Kd Tree Node.
   *
   * \param point new point in the node
   *
   */
  virtual void setPoint(std::vector<int> point) = 0;

  /**
   * Get the point contained in an Kd Tree Node.
   *
   * \return the point in the node
   *
   */
  virtual std::vector<int> getPoint() = 0;

  /**
   * Set the left child of a Kd Tree Node.
   *
   * \param left new left child of a node
   *
   */
  virtual void setLeft(IKdNode *left) = 0;

  /**
   * Get the left child of an Kd Tree Node.
   *
   * \return left child of a node
   *
   */
  virtual IKdNode* getLeft() = 0;

  /**
   * Set the right child of a Kd Tree Node.
   *
   * \param right new right child of a node
   *
   */
  virtual void setRight(IKdNode *right) = 0;

  /**
   * Get the right child of an Kd Tree Node.
   *
   * \return right child of a node
   *
   */
  virtual IKdNode* getRight() = 0;
};

/**
 * \struct IKdTree
 *
 * This interface is corresponding to Workload 2, Kd Tree. Students are expected
 * to implement a class which inherits from the interface, and provides operations
 * of a Kd Tree.
 *
 * \attention The Kd Tree should start comparing the x coordinate at the root level.
 */
struct IKdTree {
  /// Constructor
  IKdTree() { }

  /// Destructor
  virtual ~IKdTree() { }

  /**
   * Set the root node of a Kd Tree.
   *
   * \param root new root node of the tree
   *
   */
  virtual void setRoot(IKdNode *root) = 0;

  /**
   * Get the root node of a Kd Tree.
   *
   * \return the root node of the tree
   *
   */
  virtual IKdNode* getRoot() = 0;

  /**
   * Set the dimension of a Kd Tree.
   *
   * \param dim the dimension, dim should >= 1
   *
   */
  virtual void setDim(int dim) = 0;

  /**
   * Get the dimension of a Kd Tree.
   *
   * \return dimension of the tree
   *
   */
  virtual int getDim() = 0;

  /**
   * Insert a new node which contains a point, into the tree.
   *
   * \param point the point contained in the new node, the vector size should
   *              be equal to the dimension of the tree
   *
   */
  virtual void insert(std::vector<int> point) = 0;

  /**
   * Search a point in the Kd Tree.
   *
   * \param point the target point
   * \return true, if there is a node contains the target point in the tree
   *         false, otherwise
   *
   */
  virtual bool search(std::vector<int> point) = 0;

  /**
   * Remove the node with a point from the Kd Tree.
   *
   * \param point target point
   * \return true, if a node contains the target point and it is removed successfully
   *         false, otherwise
   *
   */
  virtual bool remove(std::vector<int> point) = 0;

  /**
   * Get the nearest neighbour of a point.
   *
   * \param point target point
   * \return the nearest neighbour node in the tree, of the target point.
   *         NULL, if the vector size is not equal to the dimension of the tree.
   *
   */
  virtual IKdNode* nearestNeighbor(std::vector<int> point) = 0;
};


