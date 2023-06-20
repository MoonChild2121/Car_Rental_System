#include <iostream>
#include <fstream>
#include "CarRentalSystem.h"
#include "CarRentalSystem.cpp"
#include "unistd.h"
#include <string>
using namespace std;


int main ()
{    
	Cars *s[2];
    bool cond1 = true; 
    while (cond1 == true)
    {
        cout << "\t\t\t -------------------------------------------------- \t\t\n";
        cout << "\t\t\t                                                    \t\t\n";
        cout << "\t\t\t           ----------------------------             \t\t\n";
        cout << "\t\t\t          |      Car Rental System     |            \t\t\n";
        cout << "\t\t\t           ----------------------------             \t\t\n";
        cout << "\t\t\t                                                    \t\t\n";
        cout << "\t\t\t -------------------------------------------------- \t\t\n";
        int y;
        cout << "If you want to exit, press 1, if you are admin, press 2, if you are user press 3" << endl;
        cin >> y;
        while (y < 1 || y > 3)
        {
            cout << "Invalid choice... Make one again: " << endl;
            cin >> y;
        }
        if (y == 1)
        {
            cout << "\t\t\t       <<<Thanks for visiting here>>>          \t\t\n";
            cond1 = false;
        }
        else if(y == 2)
        {
            Admin A;
            s[0] = &A;
            s[0]->lessgo();
        }
        else if(y == 3)
        {
            User U;
            s[1] = &U;
            s[1]->lessgo();
        }
    }
}