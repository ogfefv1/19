//
//  main.cpp
//  19
//
//  Created by Егор Джемлиханов on 01.11.2024.
//

#include <iostream>
#include "MyString.hpp"

using namespace std;

int main() {
    MyString stringExample("пользователь1!!!");
    cout << "лен = " << stringExample.MyStrLen() << endl;
    stringExample.Print();

    stringExample.Input();
    stringExample.Print();

    MyString stringExample2("пользователь2!!!");

    stringExample += " привет, мир";
    stringExample.Print();

    MyString stringExample3;
    stringExample3 = "привет, " + stringExample2;
    stringExample3.Print();

    MyString::GetCountLiveObj();
    MyString::GetCountCreatedObj();

    return 0;
}
