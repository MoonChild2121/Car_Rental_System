#include <iostream>
#include <fstream>
#include "CarRentalSystem.h"
#include <vector>
#include "unistd.h"
#include <string>
using namespace std;

void Cars :: displayinfo(long int k)
{
    fstream f2;
    f2.open("cars.txt", ios :: in);
    for (long int i = 0; i < k; i++)
    {
    	string a,b,c,d,e;
    	f2 >> a >> b >> c >> d >> e;
	}
	string f, g, h, i ,j;
	f2 >> f >> g >> h >> i >> j;
	name = f;
    model = g;
    num = h;
    price = prices[k];
    colour = j;
	cout << "\t\t ------------------------------------------------------------- \t\t\n";
    cout << "\t\t                                                               \t\t\n";
    cout << "\t\t       Name: " << name << endl;
    cout << "\t\t       Model: " << model << endl;
    cout << "\t\t       Car Number: " << num << endl;
    cout << "\t\t       Colour: " << colour << endl;
    cout << "\t\t       Time: " << num_of_days;
    if (days == true)
    {
        cout << " days" << endl;
        calcPrice(num_of_days, k);
    }
    else if(days == false)
    {
        cout << " hours" << endl;
        calcPrice(num_of_days, k);
    }
    cout << "\t\t                                                               \t\t\n";
    cout << "\t\t ------------------------------------------------------------- \t\t\n";
    f2.close();
}
// Store prices in vectors for calculations
void Cars :: setPrice()
{
	string a,b,c,d,e;
	fstream f;
	f.open("cars.txt", ios :: in);
	for (long int i = 0; !f.eof(); i++)
	{
		f >> a >> b >> c >> d >> e;
		long int y = stoi(d); // Converts string to long int
		prices.push_back(y);
	}
	f.close();
}
// Calculates price of booked car according to number of days/hours
void Cars :: calcPrice(long int a, long int b)
{
    if (days == true)
    {
        long int c;
        c = a*prices[b]*24;
        cout << "\t\t 		The price is Rs. " << c << endl;
        price = c; 
    }
    else if (days == false)
    {
        long int e;
        e = a*prices[b];
        cout << "\t\t 		The price is Rs. " << e << endl;
        price = e;
    }
    
}

// Menu for Users
void User :: display()
{
    cout << "\t\t\t=================================================\n";
    cout << "\t\t\t|                                               |\n";
    cout << "\t\t\t|        -----------------------------          |\n";
    cout << "\t\t\t|        |     CAR RENTAL SYSTEM     |          |\n";
    cout << "\t\t\t|        -----------------------------          |\n";
    cout << "\t\t\t|                                               |\n";
    cout << "\t\t\t|                                               |\n";
    cout << "\t\t\t=================================================\n\n";
    cout << "\t\t\t                   <<<USERS>>>                  \n\n\n";
}
// Menu for Admin
void Admin :: display()
{
    cout << "\t\t\t=================================================\n";
    cout << "\t\t\t|                                               |\n";
    cout << "\t\t\t|        -----------------------------          |\n";
    cout << "\t\t\t|        |     CAR RENTAL SYSTEM     |          |\n";
    cout << "\t\t\t|        -----------------------------          |\n";
    cout << "\t\t\t|                                               |\n";
    cout << "\t\t\t|                                               |\n";
    cout << "\t\t\t=================================================\n\n";
    cout << "\t\t\t                   <<<ADMIN>>>                  \n\n\n";
}
// Displays personal info of user
void User :: displayData()
{
    cout << "\t\t ------------------------------------------------------------------ \t\t\n";
    cout << "\t\t                                                                   \t\t\n";
    cout << "\t\t      Name -------------------------------- " << my_name << "       \t\t\n";
    cout << "\t\t      Phone Number ------------------------ +92 " << mobilenum << "    \t\t\n";
    cout << "\t\t      CNIC Number ------------------------- " << CNIC << "     \t\t\n";
    cout << "\t\t      Address ----------------------------- " << address << "      \t\t\n";
    cout << "\t\t                                                                   \t\t\n";
    cout << "\t\t ------------------------------------------------------------------ \t\t\n";
}
// Constructor which basically set prices and displays menu bar
User :: User()
{
    display();
    setPrice();
    cout << "\t\t\t             	<<<Welcome>>>                   \n";
    
}
// Function which includes all procedures of rental system
void User :: lessgo()
{
    bool cond = true;
    while (cond == true)
    {
        int a;
        cout << "Press 1 to rent a car and 2 to leave this page..." << endl;
        cin >> a;
        while (a < 0 || a > 2)
        {
            cout << "Invalid number... Please make a valid choice" << endl;
            cin >> a;
        }
        // Renting process
        if (a == 1)
        {
        	fstream f3;
        	f3.open("bookedcars.txt",ios :: app | ios :: out);
            cout << "Fill in the following information..." << endl;
            string b;
			string c;
            string d;
			string e;
			string f;
            cout << "Enter your first name: ";
            cin >> b;
            cout << "Enter your last name: ";
            cin >> c;
            my_name = b + " " + c;
            f3 << " " << b << " ";
            cout << "Enter your CNIC number (13 digit number with no space): ";
            cin >> d;
            while (d.size() != 13)
            {
            	cout << "Invalid CNIC... Please try again: ";
            	cin >> d;
			}
            CNIC = d;
            f3 << d << " ";
            cout << "Enter your phone number omitting 0: " << endl;
            cout << "+92 ";
            cin >> e;
            while (e.size() != 10)
            {
            	cout << "Invalid mobile number... Try again: " << endl;
            	cout << "+92 ";
            	cin >> e;
			}
            mobilenum = e;
            f3 << mobilenum << " ";
            cout << "Enter your address: ";
            cin >> f;
            address = f;
            f3 << address << " ";
            long int g;
            cout << "Select 1 for renting for days and 2 for renting for hours" << endl;
            cout << "1. " << "Days" << "\n" << "2. " << "Hours" << endl;
            cin >> g;
            while (g < 1 || g > 2)
            {
                cout << "Invalid selection... Make wise selection" << endl;
                cout << "1. " << "Days" << "\n" << "2. " << "Hours" << endl;
                cin >> g;
            }
            if (g == 1)
            {
                days = true;
                long int r;
                cout << "Enter number of days you want to rent the car: ";
                cin >> r;
                while (r <= 0)
                {
                    cout << "Enter valid number of hours: ";
                    cin >> r;
                }
                num_of_days = r;
            }
            else if (g == 2)
            {
                days = false;
                long int s;
                cout << "Enter number of hours you want to rent the car: ";
                cin >> s;
                while (s <= 0)
                {
                    cout << "Enter valid number of hours: ";
                    cin >> s;
                }
                num_of_days = s;
            }
            f3 << num_of_days;
            f3.close();
            long int h;
            cout << "Select from the following options, which car do you want to rent" << endl;
            fstream f1;
            f1.open("cars.txt", ios :: in);
            string u, v, w, x, y;
            long int i;
			for (i = 0; !f1.eof() ; i++)
            {
                cout << i + 1 << ". ";
                f1 >> u >> v >> w >> x >> y;
                cout << "Car: " << u << " | " << "Model: " << v << " | " << "Car Number: "<< w << " | " << "Price / hr: " << x << " | " << "Colour: " << y << endl;
            }
            f1.close();
            cin >> h;
            while (h < 0 || h > i + 1)
            {
                cout << "Invalid choice... Make a wise selection: ";
                cin >> h;
            }
            fstream f4, f5;
            f4.open("bookedcars.txt", ios :: app | ios :: out);
            f5.open("cars.txt", ios :: in);
            for (long int i = 0; i < h - 1; i++)
            {
            	string m, n, o, p, q;
            	f5 >> m >> n >> o >> p >> q;
			}
			
            string ss, t, uu, vv, ww;
            f5 >> ss >> t >> uu >> vv >> ww;
            bookname = ss;
            bookmodel = t;
            booknum = uu;
            bookcolour = ww;
           	f4 << " " << bookname << " " << bookmodel << " " << booknum << " " << bookcolour;
           	f5.close();
           	f4.close();
            displayData();
            displayinfo(h-1);
            int tt;
            cout << "Press 1 to exit and 2 to continue" << endl;
            cin >> tt;
            while (tt <= 0 || tt > 2)
            {
                cout << "Invalid selection... Make a wise choice: ";
                cin >> tt;
            }
            if (tt == 1) 
            {
                cond = false;
            }
            else if(tt == 2)
            {
                continue;
            }
        }
    }
}
// Password checking
bool Admin :: pwd()
{
    long int a = 373055;
    long int b;
    cout << "Enter 6 digit password if you are an admin: " << endl;
    try
    {
        cin >> b;
        while (b < 100000 && b > 999999)
        {
            cout << "Enter 6 digit password" << endl;
            cin >> b;
        }
        if (a == b)
        {
            cout << "Login Successful" << endl;
            return true;
        }
        else
        {
        	throw b;
		}
        
    }
    catch(long int b)
    {
        cout << "Invalid password" << endl;
        return false;
    }
}
// Constructor of Admin class: Set prices and displays menu bar of admin
Admin :: Admin()
{
    cout << "\t\t           		<<<Welcome>>>		               \t\t\n";
    setPrice();
    display();
}
// Includes all procedures for admin of rental system
void Admin :: lessgo()
{
	while (pwd() == true)
    {
        long int d;
        cout << "Press 1 to view booked cars and their details" << endl;
		cout << "Press 2 to add any car" << endl;
        cin >> d;
        while(d < 1 || d > 2)
        {
            cout << "Invalid Selection... Make a wise choice: ";
            cin >> d; 
        }
        // Shows booked cars
        if (d == 1)
        {
            fstream f;
            f.open("bookedcars.txt", ios :: in);
			cout << "The information is given below: " << endl;
            for (long int i = 0; !f.eof() ; i++)
            {
            	
				string a, b, c, d, e, f1, g, h, j;
            	f >> a >> b >> c >> d >> e >> f1 >> g >> h >> j;
            	cout << "\t\t\t	-------------------------------------------------- \t\t\n";
                cout << "\t\t\t 				<<< Car " << i + 1 << " >>> 				\t\t" << endl;
				cout << "\t\t\t 	Name ----------------------- " << a << endl;
				cout << "\t\t\t		CNIC Number ---------------- " << b << endl;
				cout << "\t\t\t		Mobile number -------------- +92 " << c << endl;
				cout << "\t\t\t		Address -------------------- " << d << endl;
				cout << "\t\t\t		Car Name ------------------- " << f1 << endl;
                cout << "\t\t\t		Car Model ------------------ " << g << endl;
                cout << "\t\t\t		Car Number ----------------- " << h << endl;
                cout << "\t\t\t		Car Colour ----------------- " << j << endl;
                cout << "\t\t\t		For time ------------------- " << e;
                if (days == true)
                {
                	cout << " days" << endl;
				}
				else
				{
					cout << " hours" << endl;
				}
				cout << "\t\t\t ------------------------------------------------- \t\t\n";
        	}
			f.close();
			
        }
        // Adds car in the system
        else if(d == 2)
        {
            cout << "Enter information for car to be added :-" << endl;
            string a, b, c;
            long int  i, j;
            cout << "Name: ";
            cin >> a;
            cout << "Model: ";
            cin >> i;
            cout << "Colour: ";
            cin >> b;
            cout << "Price per hour: ";
            cin >> j;
            cout << "Car Number: ";
            cin >> c;
            fstream f;
            f.open("cars.txt", ios :: app | ios :: out);
            f << "\t" << a << " " << i << " " << c << " " << j << " " << b;
            
			f.close();
			
        }
        
        long int f;
        cout << "If you want to continue, press 1 and if you want to exit press 2: ";
        cin >> f;
        while (f < 1 || f > 3)
        {
            cout << "Invalid selection.. Please make a wise choice: ";
            cin >> f;
        }
        if (f == 1)
        {
            continue;
        }
        else if(f == 2)
        {
            break;
        }
    }
}
