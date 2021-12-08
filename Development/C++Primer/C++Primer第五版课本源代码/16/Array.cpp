/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/ 

#include <list>
using std::list;

#include <vector>
using std::vector; 

#include <iostream>
using std::cout; using std::endl; 

#include <string>
using std::string;

#include <cstddef>
using std::size_t;

#include "Blob.h"

int main()
{
    Blob<int> ia;                // empty Blob<int>
	int temp1[] = {0,1,2,3,4}; 
	// Blob<int> with five elements
	Blob<int> ia2(temp1, temp1 + sizeof(temp1)/sizeof(*temp1));
	vector<int> v1(10, 0); // ten elements initialized to 0
    Blob<int> ia3(v1.begin(), v1.end());  // copy elements from v1
    cout << ia << "\n" << ia2 << "\n" << ia3 << endl;

    // these definitions instantiate two distinct Blob types
    Blob<string> names; // Blob that holds strings
    Blob<double> prices;// different element type

    // instantiates Blob<string> class and the constructor
    //  that has two const string* parameters
	string temp2[] = {"a", "an", "the"}; // three elements
	Blob<string> articles(temp2, temp2 + sizeof(temp2)/sizeof(*temp2));

    // instantiates Blob<int> and the constructor
    // that has two const int* parameters
	int temp3[] = {0,1,2,3,4,5,6,7,8,9};
	Blob<int> squares(temp3, temp3 + sizeof(temp3)/sizeof(*temp3));

	// instantiates Blob<int>::size() const
    cout << squares << endl;
	for (size_t i = 0; i != squares.size(); ++i)  
		squares[i] = i*i; // instantiates Blob<int>::operator[](size_t)
    cout << squares << endl;

	long temp4[] = {0,1,2,3,4,5,6,7,8,9};
	vector<long> vl(temp4, temp4 + sizeof(temp4)/sizeof(*temp4));
	// instantiates the Blob<int> constructor that has
	// two vector<long>::iterator parameters
	Blob<int> a1(vl.begin(), vl.end());   // copy from a vector

	// instantiates the Blob<int> class 
	// and the Blob<int> constructor that has two int* parameters
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	Blob<int> a2(arr, arr + sizeof(arr)/sizeof(*arr));   // copy from an array

	list<int> li(10, 0); // 10 elements all zeros
	Blob<int> zeros(li.begin(), li.end());  // copy from a list

    cout << a1 << "\n" << zeros << endl;

	a1.swap(zeros);
    cout << a1 << "\n" << zeros << endl;

	const char* temp5[] = {"now", "is", "the", "time"};
	list<const char*> w(temp5, temp5 + sizeof(temp5)/sizeof(*temp5));

	// instantiates the Blob<string> class and the Blob<string> 
	// constructor that has two (list<const char*>::iterator parameters 
	Blob<string> a3(w.begin(), w.end());  // copy from a list

	return 0;
}
