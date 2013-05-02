#include "smart-pointer.hpp"
#include "usingio.hpp"

int main(void)
{
	SmartPointer<int> sp1 = new int;
    SmartPointer<int> sp2 = sp1;
    *sp1 = 1;

    cout << *sp1 << endl;
    cout << *sp2 << endl;

	return 0;
}
