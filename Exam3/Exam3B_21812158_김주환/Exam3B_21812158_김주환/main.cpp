/* main.cpp */
/* Description
* BST 구현 및 성능검사
* Programmed by J. H. Kim
* Last updated : 2021-11-20 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "T_BST.h"

using namespace std;
void main()
{
	int data_array[] =
	{ /* integer data */
	 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
	};
	int num_data = sizeof(data_array) / sizeof(int);
	T_BSTN<int>* pRoot, ** ppBST_int_root;
	T_BST<int> BST_int_noBalancing("BST_int_noBalancing");
	cout << "Testing Binary Search Tree with Rebalancing" << endl;
	ppBST_int_root = BST_int_noBalancing.getRootAddr();
	for (int i = 0; i < num_data; i++)
	{
		BST_int_noBalancing.insertInOrder(data_array[i]);
	}
	BST_int_noBalancing.print_with_Depth();
	cout << "Elements in " << BST_int_noBalancing.getName() << " (in order) : ";
	BST_int_noBalancing.print_inOrder();
	cout << endl;
	T_BST<int> BST_int_Balancing("BST_int_Balancing");
	cout << "\nTesting Binary Search Tree with Rebalancing" << endl;
	ppBST_int_root = BST_int_Balancing.getRootAddr();
	for (int i = 0; i < num_data; i++)
	{
		BST_int_Balancing.insertAndRebalance(data_array[i]);
	}
	BST_int_Balancing.print_with_Depth();
	cout << "Elements in " << BST_int_Balancing.getName() << " (in order) : ";
	BST_int_Balancing.print_inOrder();
	cout << endl;
}