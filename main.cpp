#include "smart-pointer.hpp"
#include <iostream>
#include <string>
#include "usingio.hpp"


int main(void)
{
    /*
    // Référence cyclique: pose problème avec 
    // (seulement) un compteur de références.
    struct A {
        SmartPointer<struct B> s_spB;
    };

    struct B {
        SmartPointer<struct A> s_spA;
    };
    SmartPointer<struct A> spA = new struct A;

    spA->s_spB = new struct B;
    spA->s_spB-> s_spA = spA;
    */

    SmartPointer<int> tab = new int[2];
    tab[0] = 0;
    tab[1] = 1;

    cout << "tab[0]: " << tab[0] << endl;
    cout << "tab[1]: " << tab[1] << endl;
    cout << "*(tab + 1): " << *(tab + 1) << endl;
    cout << endl;

    struct Foo {
        SmartPointer<struct Foo> bar;
        SmartPointer<std::string> text;
    };

    struct Foo foo;
    foo.text = new std::string("foo");

    foo.bar = new Foo;
    foo.bar->text = new std::string("bar");

    cout << "foo: " << *(foo.text) << endl;
    cout << "bar: " << *(foo.bar->text) << endl;
    cout << endl;

    SmartPointer<int> sp1 = new int;
    SmartPointer<int> sp2 = sp1;
    SmartPointer<int> sp3 = sp2;
    *sp1 = 1;

    cout << *sp1 << endl;
    cout << *sp2 << endl;
    cout << *sp3 << endl;
    cout << endl;

    *sp3 = 2;

    cout << *sp1 << endl;
    cout << *sp2 << endl;
    cout << *sp3 << endl;
    cout << endl;

    sp3 = new int;
    *sp3 = 3;

    cout << *sp1 << endl;
    cout << *sp2 << endl;
    cout << *sp3 << endl;
    cout << endl;

	return EXIT_SUCCESS;
}
