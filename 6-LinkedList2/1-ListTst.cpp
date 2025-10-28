#include <iostream>
using namespace std;

#include "1-List.h"

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
 cout << "Test PutItemH and Print" << endl;
 cout << "Correct if output is 4, 3, 2, 1, 0 on subsequent lines" << endl;
 for (int i = 0; i < 5; i++)
   lst2->PutItemH(i);
 lst2->Print();

//Destructor must be invoked on dynamically declared lists
 delete lst2;

 cout << "Test DeleteItemH\n";
 cout << "Correct if output is 3, 2, 1, 0 on subsequent lines\n";
 lst1.DeleteItemH();
 lst1.Print();
 List l;
 cout << "Test IsEmpty and GetLength\n";
 cout << "Correct if false, then true, then 4\n";
 std::cout << lst1.IsEmpty() << " " << l.IsEmpty() << " " << lst1.GetLength() << '\n';

 cout << "Test Find\n";
 lst1.PutItemH(2);
 cout << "Correct if output is 2\n";
 std::cout << lst1.Find(2) << '\n';

 cout << "Test PutItemT and DeleteItemT\n";
 cout << "Correct if output is 2, 3, 2, 1, 0, 1, and then 2, 3, 2, 1, 0\n";
 lst1.PutItemT(1);
 lst1.Print();
 std::cout << '\n';
 lst1.DeleteItemT();
 lst1.Print();
 cout << endl;
 return 0;
}
