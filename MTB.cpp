#include <iostream>
#include <iomanip>  //use to manipulate output
#include <fstream>
#include <string>
#include <math.h>

using namespace std;


class Movie
{
private:
    string movieCode;
    string movieName;
    string movieGenre;
    int movieYear;
    string movieRating;
    double moviePrice;

public:
    int y, x, seat_icon3 = 254;
    char seat[4][15];
    int total_seat_select = 0;
    int total_to_pay;
    void welcome();
    void login_menu();
    void login();
    void mainMenu();
    void edit();
    void add();
    void view();
    void rem();
    void book();
    void seat_display(int &y, int &x, char seat[4][15]);
    void seat_select(int &y, int &x, char seat[4][15]);
    void seat_select_agn(int &y, int &x, char seat[4][15]);
    void check_class(int &y, int &x, char seat[4][15]);
    void ticket_calculation(string movCode, int &total_seat_select);
    void ticket_print(string movCode, char seat[4][15], int &total_seat_select);
    void finish_seat(int &y, int &x, char seat[4][15]);
    void sale_report(string movCode, int &y, int &x, char seat[4][15]);
};


void Movie::welcome()
{
    for (int w = 1; w <= 76; w++)
    {
        cout << (char)205;
    }
    std::cout << R"(
                     #     #
                     ##   ##  #  #####     ##         #
                     # # # #  #  #    #   #  #        #
                     #  #  #  #  #    #  #    #       #
                     #     #  #  #####   ######       #
                     #     #  #  #   #   #    #  #    #
                     #     #  #  #    #  #    #   ####

             #####
            #     #  #  #    #  ######  #    #    ##     ####
            #        #  ##   #  #       ##  ##   #  #   #
            #        #  # #  #  #####   # ## #  #    #   ####
            #        #  #  # #  #       #    #  ######       #
            #     #  #  #   ##  #       #    #  #    #  #    #
             #####   #  #    #  ######  #    #  #    #   ####
    )"
              << "\n";
    for (int w = 1; w <= 76; w++)
    {
        cout << (char)205;
    }
    cout << "\n\n\n";
    system("pause");
}


void Movie::login_menu()
{
loop:
    system("cls");
    std::cout << R"(
                    ================================
                        WELCOME TO MIRAJ CINEMAS
                    ================================

                     ********* LOGIN MENU *********
                     ______________________________
                    |                              |
                    |____ 1) Login ________________|
                    |                              |
                    |____ 2) Exit _________________|
                    |                              |
                    |______________________________|
    )";
    int choice;
    cout << "\n\n\t\t\t Your choice: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
            login();
            break;

        case 2:
            exit(0);

        default:
            cout << "\n\n\t\t\tWrong Choice! Try Again.\n\n\n";
            system("pause");
            cin.clear();
            fflush(stdin);
            break;
    }
    goto loop;
}


void Movie::mainMenu()
{
    system("cls");
    std::cout << R"(
                     ********** MAIN MENU **********
                     _______________________________
                    |                               |
                    |____ 1) Edit Movies List ______|
                    |                               |
                    |____ 2) Book Tickets __________|
                    |                               |
                    |____ 3) Exit __________________|
                    |                               |
                    |_______________________________|
    )";
    int choice;
    cout << "\n\n\t\t\t Your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        edit();
        break;

    case 2:
    {
        book();
        break;
    }

    case 3:
        login_menu();

    default:
        cout << "\n\n\t\t\tWrong Choice! Try Again.\n\n\n";
        system("pause");
        cin.clear();
        fflush(stdin);
        mainMenu();
        break;
    }
}


void Movie::edit()
{
loop:
    system("cls");
    std::cout << R"(
                        *** EDIT MOVIES LIST ***
                         _______________________
                        |                       |
                        |____ 1) Add ___________|
                        |                       |
                        |____ 2) View __________|
                        |                       |
                        |____ 3) Remove ________|
                        |                       |
                        |____ 4) Main Menu _____|
                        |                       |
                        |_______________________|
    )";

    int choice;
    cout << "\n\n\t\t\t Select any option: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        cout << "\n\n";
        system("pause");
        break;

    case 3:
        rem();
        break;

    case 4:
        mainMenu();
        break;

    default:
        cout << "\n\n\t\t\tWrong Choice! Try Again.\n\n\n";
        system("pause");
        cin.clear();
        fflush(stdin);
        break;
    }
    goto loop;
}


void Movie::add()
{
    char choice;
    do
    {
    loop:
        system("cls");
        cout << "\n\t\t *** Add Movie Details ***\n";
        fstream data;
        data.open("movieDatabase.txt", ios::in);
        int token = 0;

        if (!data)
        {
            data.open("movieDatabase.txt", ios::app | ios::out);
            cout << "\n\t\t Enter Movie Code: ";
            cin >> movieCode;
            fflush(stdin);
            cout << "\n\t\t Enter Movie Name: ";
            getline(cin, movieName);
            cout << "\n\t\t Enter Movie Genre: ";
            cin >> movieGenre;
            cout << "\n\t\t Enter Movie Year: ";
            cin >> movieYear;
            cout << "\n\t\t Enter Movie Rating: ";
            cin >> movieRating;
            fflush(stdin);
            cout << "\n\t\t Enter Movie Price: ";
            cin >> moviePrice;
            data << movieCode << "," << movieName << "," << movieGenre << "," << movieYear << "," << movieRating << "," << moviePrice << "\n";
            data.close();
        }
        else
        {
            cout << "\n\t\t Enter Movie Code: ";
            cin >> movieCode;

            string line;

            while (getline(data, line))
            {
                stringstream ss(line);
                string record;
                while (getline(ss, record, ','))
                {
                    if (record == movieCode)
                    {
                        cout << "\n\t\t Duplicate Entry!! Please Try Again.\n\n";
                        system("pause");
                        token++;
                    }
                }
            }
            data.close();
            if (token == 1)
            {
                goto loop;
            }
            else
            {
                data.open("movieDatabase.txt", ios::app | ios::out);
                fflush(stdin);
                cout << "\n\t\t Enter Movie Name: ";
                getline(cin, movieName);
                cout << "\n\t\t Enter Movie Genre: ";
                cin >> movieGenre;
                cout << "\n\t\t Enter Movie Year: ";
                cin >> movieYear;
                cout << "\n\t\t Enter Movie Rating: ";
                cin >> movieRating;
                fflush(stdin);
                cout << "\n\t\t Enter Movie Price: ";
                cin >> moviePrice;
                data << movieCode << "," << movieName << "," << movieGenre << "," << movieYear << "," << movieRating << "," << moviePrice << "\n";
                data.close();
            }
        }
        cout << "\n\t\t " << char(16) << " Movie Details Added!!";
        cout << "\n\nDo you want to add another?\n";
        cout << "[Y] YES\n[N] NO\n";
        cin >> choice;
        choice = toupper(choice);
    } while (choice == 'Y' || choice != 'N');
}


void Movie::view()
{
    system("cls");
    for (int w = 1; w <= 107; w++)
    {
        cout << (char)205;
    }
    cout << "\n";
    cout << setw(6) << left << "Code" << setw(47) << "Name" << setw(30) << "Genre" << setw(9) << "Year" << setw(9) << "Rating" << setw(8) << "Price"
         << "\n";
    for (int w = 1; w <= 107; w++)
    {
        cout << (char)205;
    }
    cout << "\n";
    ifstream myFileStream("movieDatabase.txt");
    if (!myFileStream.is_open())
    {
        cout << "File failed to open" << endl;
    }
    string movCode, movName, movGenre, movRating;
    int movYear;
    double movPrice;

    string myString, price;
    string line;

    while (getline(myFileStream, line))
    {
        stringstream ss(line);
        getline(ss, movCode, ',');
        getline(ss, movName, ',');
        getline(ss, movGenre, ',');
        getline(ss, myString, ',');
        movYear = stoi(myString);
        getline(ss, movRating, ',');
        getline(ss, price, ',');
        movPrice = stod(price);

        cout << setw(6) << left << movCode << setw(47) << movName << setw(30) << movGenre << setw(9) << movYear << setw(9) << movRating << setw(8) << movPrice << "\n";
    }
    myFileStream.close();
}


void Movie::rem()
{
    system("cls");
    view();

    cout << "\n\nEnter Movie Code: ";
    cin >> movieCode;

    string line;
    ifstream ini_file{"movieDatabase.txt"};
    ofstream out_file{"movieDatabaseNew.txt"};

    if (ini_file && out_file)
    {
        while (getline(ini_file, line))
        {
            stringstream ss(line);
            string record;
            while (getline(ss, record, ','))
            {
                if (record == movieCode)
                {
                    getline(ini_file, line);
                }
                continue;
            }
            out_file << line << "\n";
        }
        cout << "\n"
             << (char)16 << " Removed Successfully \n\n";
        system("pause");
    }
    else
    {
        cout << "Cannot read File";
    }
    ini_file.close();
    out_file.close();
    remove("movieDatabase.txt");
    rename("movieDatabaseNew.txt", "movieDatabase.txt");

    ifstream in("movieDatabase.txt", ios::in);
    ofstream out("movieDatabaseNew.txt", ios::out);

    string readin;
    while (!in.eof())
    {
        getline(in, readin);
        if (readin != "")
        {
            out << readin << endl;
        }
    }
    in.close();
    out.close();
    remove("movieDatabase.txt");
    rename("movieDatabaseNew.txt", "movieDatabase.txt");
}


void Movie::book()
{
    system("cls");
    view();
    cout << "\n\nEnter Movie Code: ";
    cin >> movieCode;

    for (y = 0; y < 4; y++)
        for (x = 0; x < 15; x++)
            seat[y][x] = seat_icon3;

    string movCode, movName, movGenre, movRating;
    int movYear;
    double movPrice;

    string myString, price;
    string line;

    fstream data;
    data.open("movieDatabase.txt", ios::in);

    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        string line;

        while (getline(data, line))
        {
            stringstream ss(line);
            string record;
            while (getline(ss, record, ','))
            {
                if (record == movieCode)
                {

                    stringstream ss(line);
                    getline(ss, movCode, ',');
                    getline(ss, movName, ',');
                    getline(ss, movGenre, ',');
                    getline(ss, myString, ',');
                    movYear = stoi(myString);
                    getline(ss, movRating, ',');
                    getline(ss, price, ',');
                    movPrice = stod(price);

                    data.close();

                    char choice;
                loop:
                    do
                    {
                        system("cls");
                        seat_select_agn(y, x, seat);
                        check_class(y, x, seat);
                        ticket_calculation(movCode, total_seat_select);
                        ticket_print(movCode, seat, total_seat_select);
                        finish_seat(y, x, seat);

                        cout << "\nNext customer?\n[Y] YES\n[N] NO\n";
                        cin >> choice;
                        choice = toupper(choice);

                        if (choice == 'Y')
                        {
                            goto loop;
                        }
                        else
                        {
                        	sale_report(movCode, y, x, seat);
                            mainMenu();
                        }

                    } while (choice == 'Y' || choice != 'N');
                }
            }
        }
    }
    cout << "\nWrong Code!!\n\n";
    system("pause");
    mainMenu();
}


void Movie::seat_display(int &y, int &x, char seat[4][15])
{
    cout << "   ";
    for (int screen = 0; screen <= 25; screen++)
    {
        cout << (char)254;
    }
    cout << " SCREEN ";
    for (int screen = 0; screen <= 24; screen++)
    {
        cout << (char)254;
    }
    cout << endl;
    for (int y = 0; y < 4; y++)
    {
        cout << y << " " << (char)179 << " " << seat[y][0] << " " << (char)179 << " " << seat[y][1] << " " << (char)179 << " " << seat[y][2] << " " << (char)179 << " " << seat[y][3] << " " << (char)179 << " " << seat[y][4] << " " << (char)179 << " " << seat[y][5] << " " << (char)179 << " " << seat[y][6] << " " << (char)179 << " " << seat[y][7] << " " << (char)179 << " " << seat[y][8] << " " << (char)179 << " " << seat[y][9] << " " << (char)179 << " " << seat[y][10] << " " << (char)179 << " " << seat[y][11] << " " << (char)179 << " " << seat[y][12] << " " << (char)179 << " " << seat[y][13] << " " << (char)179 << " " << seat[y][14] << " " << (char)179 << " " << endl;
    }
    cout << " ";
    for (int z = 0; z < 10; z++)
    {
        cout << fixed << setw(4) << right << z;
    }
    cout << " ";
    for (int z = 10; z < 15; z++)
    {
        cout << fixed << setw(4) << z;
    }
    cout << endl;
    cout << "   ";
    for (int w = 1; w <= 59; w++)
    {
        cout << (char)205;
    }
    cout << endl
         << endl;
}


void Movie::seat_select(int &y, int &x, char seat[4][15])
{
    cout << "Select seat (ROW > COLUMN)\n* Example : 0 , 9 * \n";
    cout << "ROW    : ";
    cin >> y;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(132, '\n');
        cout << "Please only enter NUMBER!\n";
        cout << "ROW    : ";
        cin >> y;
    }

    while (y < 0 || y > 3)
    {
        cout << "Invalid input! Please enter a number of your seat.\n";
        cout << "ROW    : ";
        cin >> y;
    }

    cout << "COLUMN : ";
    cin >> x;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(132, '\n');
        cout << "Please only enter NUMBER!\n";
        cout << "COLUMN : ";
        cin >> x;
    }

    while (x < 0 || x > 14)
    {
        cout << "Invalid input! Please enter a number of your seat.\n";
        cout << "COLUMN : ";
        cin >> x;
    }

    if (seat[y][x] != '1' && seat[y][x] != 'X')
    {
        seat[y][x] = '1';
    }
    else
    {
        cout << "Seat taken\n";
        cout << endl;
    }

    seat_display(y, x, seat);
}


void Movie::seat_select_agn(int &y, int &x, char seat[4][15])
{
    char seat_agn;
    do
    {
        seat_display(y, x, seat);
        cout << "           \"1\" = Selected Seat\n           \"X\" = Seat Sold / Seat Unavaible Currently\n         ";
        for (int screen = 0; screen <= 45; screen++)
        {
            cout << (char)196;
        }
        cout << endl;
        seat_select(y, x, seat);
        cout << "Do you want to select another seat again?\n";
        cout << "[Y] YES\n[N] NO\n";
        cin >> seat_agn;
        seat_agn = toupper(seat_agn);
        if (seat_agn == 'Y')
        {
            system("cls");
            seat_select_agn(y, x, seat);
        }
        if (seat_agn != 'Y' && seat_agn != 'N')
        {
            cout << "Invalid! \nPlease keyin a correct Alphabet!\n";
        }
    } while (seat_agn != 'Y' && seat_agn != 'N');
}


void Movie::check_class(int &y, int &x, char seat[4][15])
{
    system("cls");
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x <= 14; x++)
        {
            if (seat[y][x] == '1' && seat[y][x] != 'X')
            {
                ++total_seat_select;
            }
        }
    }
    if (total_seat_select == 1)
    {
        cout << "\nYou have selected " << total_seat_select << " seat.\n\n";
    }
    else if (total_seat_select == 0)
    {
        cout << "\nYou have selected " << total_seat_select << " seat.\n\n";
    }
    else
    {
        cout << "\nYou have selected " << total_seat_select << " seats.\n\n";
    }
}


void Movie::ticket_calculation(string movCode, int &total_seat_select)
{
    fstream data;
    data.open("movieDatabase.txt", ios::in);

    string movName, movGenre, movRating;
    int movYear;
    double movPrice;

    string myString, price;
    string line;

    while (getline(data, line))
    {
        stringstream ss(line);
        string record;
        while (getline(ss, record, ','))
        {
            if (record == movieCode)
            {
                stringstream ss(line);
                getline(ss, movCode, ',');
                getline(ss, movName, ',');
                getline(ss, movGenre, ',');
                getline(ss, myString, ',');
                movYear = stoi(myString);
                getline(ss, movRating, ',');
                getline(ss, price, ',');
                movPrice = stod(price);
            }
        }
    }
    data.close();

    double cash_payment, change_due;

    do
    {
        cout << "\n\t   *** BILL CALCULATION ***\n\n";

        //------calculation of total payment
        total_to_pay = total_seat_select * movPrice;
        cout << fixed << setw(20) << "Total to Pay  = " << fixed << setw(19) << "Rs. " << fixed << setprecision(2) << (double)total_to_pay;
        cout << endl;

        //------user input the cash amount

        cout << fixed << setw(20) << "Cash Payment  : " << fixed << setw(19) << "Rs. ";
        cin >> cash_payment;
        if (cash_payment < total_to_pay)
        {
            cout << "Your amount is not valid! Please enter a correct amount.\n";
            system("pause");
            cout << "\033[2J\033[1;1H";
        }
    } while (cash_payment < total_to_pay);

    //------calculation of change due
    change_due = (double)cash_payment - total_to_pay;
    cout << fixed << setw(20) << "Change Due    = " << fixed << setw(19) << "Rs. " << fixed << setprecision(2) << (double)change_due;
    cout << endl
         << endl;
    system("pause");
}


void Movie::ticket_print(string movCode, char seat[4][15], int &total_seat_select)
{
    fstream data;
    data.open("movieDatabase.txt", ios::in);

    string movName, movGenre, movRating;
    int movYear;
    double movPrice;

    string myString, price;
    string line;

    while (getline(data, line))
    {
        stringstream ss(line);
        string record;
        while (getline(ss, record, ','))
        {
            if (record == movieCode)
            {
                stringstream ss(line);
                getline(ss, movCode, ',');
                getline(ss, movName, ',');
                getline(ss, movGenre, ',');
                getline(ss, myString, ',');
                movYear = stoi(myString);
                getline(ss, movRating, ',');
                getline(ss, price, ',');
                movPrice = stod(price);
            }
        }
    }
    data.close();

    //---------------------------------- print ticket ----------------------------------//

    system("cls");

    for (int t = 1; t <= total_seat_select; t++)
    {
        for (int m = 0; m <= 65; m++)
        {
            cout << "=";
        }
        cout << "\n  MIRAJ CINEMAS";
        for (int s = 0; s <= 30; s++)
        {
            cout << " ";
        }
        cout << endl
             << endl;

        cout << "  Movie" << fixed << setw(10) << " = " << fixed << setw(5);

        cout << movName << "\n";

        cout << "  Date / Time " << fixed << setw(3) << " = " << fixed << setw(5) << "11 - 11 - 2022 ( 11.00 am )";

        cout << "\n  Seat No: \n";

        cout << "   ";
        for (int screen = 0; screen <= 25; screen++)
        {
            cout << (char)254;
        }
        cout << " SCREEN ";
        for (int screen = 0; screen <= 24; screen++)
        {
            cout << (char)254;
        }
        cout << endl;

        for (int y = 0; y < 4; y++)
        {
            cout << y << " " << (char)179 << " " << seat[y][0] << " " << (char)179 << " " << seat[y][1] << " " << (char)179 << " " << seat[y][2] << " " << (char)179 << " " << seat[y][3] << " " << (char)179 << " " << seat[y][4] << " " << (char)179 << " " << seat[y][5] << " " << (char)179 << " " << seat[y][6] << " " << (char)179 << " " << seat[y][7] << " " << (char)179 << " " << seat[y][8] << " " << (char)179 << " " << seat[y][9] << " " << (char)179 << " " << seat[y][10] << " " << (char)179 << " " << seat[y][11] << " " << (char)179 << " " << seat[y][12] << " " << (char)179 << " " << seat[y][13] << " " << (char)179 << " " << seat[y][14] << " " << (char)179 << " " << endl;
        }
        cout << " ";
        for (int z = 0; z < 10; z++)
        {
            cout << fixed << setw(4) << z;
        }
        cout << " ";
        for (int z = 10; z < 15; z++)
        {
            cout << fixed << setw(4) << z;
        }
        cout << endl;
        cout << "   ";
        for (int w = 1; w <= 59; w++)
        {
            cout << (char)205;
        }
        cout << endl;

        cout << setw(35) << right << fixed << setprecision(2) << "Price: Rs." << total_to_pay;

        cout << endl;
        for (int m = 0; m <= 65; m++)
        {
            cout << "=";
        }

        cout << endl;
    }
    cout << "\n\n";
    system("pause");
}


void Movie::finish_seat(int &y, int &x, char seat[4][15])
{
    if (total_seat_select != 0)
    {
        for (y = 0; y < 4; y++)
        {
            for (x = 0; x <= 14; x++)
            {
                if (seat[y][x] == '1' && seat[y][x] != 'X')
                {
                    seat[y][x] = 'X';
                }
            }
        }
    }
    total_seat_select = 0;
}

void Movie:: sale_report(string movCode, int &y, int &x, char seat[4][15]) 
{
    int total_seat=0;
    int empty_seat=0;
    int total_seat_sold = 0;
    system("cls");
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x <= 14; x++)
        {
            ++total_seat;
            if (seat[y][x] == 'X')
            {
                ++total_seat_sold;
            }
            else if(seat[y][x] != 'X')
            {
                ++empty_seat;
            }
        }
    }

    fstream data;
    data.open("movieDatabase.txt", ios::in);

    string movName, movGenre, movRating;
    int movYear;
    double movPrice;

    string myString, price;
    string line;

    while (getline(data, line))
    {
        stringstream ss(line);
        string record;
        while (getline(ss, record, ','))
        {
            if (record == movieCode)
            {
                stringstream ss(line);
                getline(ss, movCode, ',');
                getline(ss, movName, ',');
                getline(ss, movGenre, ',');
                getline(ss, myString, ',');
                movYear = stoi(myString);
                getline(ss, movRating, ',');
                getline(ss, price, ',');
                movPrice = stod(price);
            }
        }
    }
    data.close();
    
    cout << "\n\t\t\t    *** SALES REPORT ***             " << endl << endl;
    cout << "\t\t         Movie Name : " << movName << endl;
    cout << "\t\t        Total Seats : " << total_seat << endl;
    cout << "\t\t         Sold Seats : " << total_seat_sold << endl; 
    cout << "\t\t        Empty Seats : " << empty_seat << endl;
    cout << "\t\t       Ticket Price : " << movPrice << endl;
    cout << "\t\tTotal Amount Earned : " << total_seat_sold * movPrice << endl;
    
    cout << "\n\n";
	system("pause");
}

void Movie:: login()
{
    string pass, password = "urssanjaysingh";
    cout << "\n\n\t\t\tEnter the password to login: ";
    cin >> pass;

    if (pass == password)
        {
            Movie m;
            m.mainMenu();
        }
    else
        {
            printf("\n\n\t\t\tWrong password!!\n\n\n");
            system("pause");
        }
}


int main()
{
    Movie m;
    m.welcome();
    m.login_menu();

    return 0;
}
