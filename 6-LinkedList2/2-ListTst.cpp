#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{
 List lst1;
 List* lst2 = new List;

 //This is example Test code
 cout << "Static Declaration" << endl;
 cout << "Test PutItemH and Print" << endl;
 cout << "Correct if output is 4, 3, 2, 1, 0 on subsequent lines" << endl;
 for (int i = 0; i < 5; i++)
   lst1.PutItemH(i);
 lst1.Print();

 cout << endl;
 cout << "Dynamic Declaration" << endl;
 cout << "Test PutItemT and Print" << endl;
 cout << "Correct if output is 4, 3, 2, 1, 0 on subsequent lines" << endl;
 for (int i = 0; i < 5; i++)
   lst2->PutItemT(i);
 lst2->Print();

//Destructor must be invoked for dynamically declared classes
 delete lst2;

 cout << "Testing copy constructor\n";
 cout << "Output should be 4, 3, 2, 1, 0 twice.\n";
 List copied(lst1);
 lst1.Print();
 copied.Print();

 cout << "Testing GetItemH and DeleteItemH\n";
 cout << "Output should be 4, then 3\n";
 cout << lst1.GetItemH() << '\n';
 lst1.DeleteItemH();
 cout << lst1.GetItemH() << '\n';


 cout << "Testing PutItemT, GetItemT, DeleteItemT\n";
 cout << "Output should be 0, 200, then 0\n";
 cout << lst1.GetItemT() << '\n';
 lst1.PutItemT(200);
 cout << lst1.GetItemT() << '\n';
 lst1.DeleteItemT();
 cout << lst1.GetItemT() << '\n';

 cout << "Testing IsEmpty and GetLength\n";
 cout << "Output should be 0, then 5\n";
 cout << lst1.IsEmpty() << " " << copied.GetLength() << '\n';

 cout << endl;
 return 0;
}
