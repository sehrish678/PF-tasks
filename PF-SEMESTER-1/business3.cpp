#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int menu();
void printheader();
void signUpPageHeader();
void signInPageHeader();
int choiceOfAdminPage(int option, string added);
string signInPage(string username, string password, string role, string Username[], string Password[], string Role[], int count);
bool signUpCredentials(string username, string password, string role, string Username[], string Password[], string Role[], int &count, int arrSize);
void adminpage();
string table();
string products(string allMedicines[], string added, int medicineCount);
string deleteProducts(string allMedicines[], int medicineCount);

int main()
{
    int num;
    int const arrSize = 100;
    string Username[arrSize];
    string Password[arrSize];
    string Role[arrSize];
    int count = 0;

    int medicineCount = 13;
    string allMedicines[medicineCount] = {"PANADOL", "CALPOL", "LEFLOX", "LORIN", "BRUFEN", "HYDRLIN", "ACEFYL", "GRAVINAT", "SANIPLAST", "BANDAGES", "MEDICAL TAPES", "MEDICAL SCISSORS"};
    int allProductsPrice[medicineCount] = {100, 200, 150, 100, 220, 300, 100, 400, 300, 200, 100, 200};

    int entered, option;
    string added, category;
    int option1;

    while (num != 3)
    {
        printheader();
        num = menu();
        if (num == 1) // for signing up..
        {

            system("cls");
            string username, password, role;

            printheader();
            signInPageHeader();

            cout << "ENTER THE USERNAME: ";
            cin >> username;
            cout << "ENTER YOUR PASSWORD: ";
            cin >> password;
            cout << "ENTER YOUR ROLE: ";
            cin >> role;

            bool isTrue = signUpCredentials(username, password, role, Username, Password, Role, count, arrSize);
            if (isTrue)
            {
                cout << "<<<SIGNED UP SUCCESSFULLY>>>" << endl;
            }
            else if (!isTrue)
            {
                cout << "<<<NOT SIGNED UP SUCCESSFULLY>>>";
            }
        }
        else if (num == 2) // for signing in..
        {
            string username;
            string password;
            string role;

            printheader();
            signUpPageHeader();

            cout << "ENTER THE USERNAME: ";
            cin >> username;
            cout << "ENTER YOUR PASSWORD: ";
            cin >> password;

            role = signInPage(username, password, role, Username, Password, Role, count);
            if (option1 == 0)
            {
                printheader();
                menu();
            }
            else if (option1 == 1)
            {

                if (role == "Admin" || role == "admin")
                {

                    choiceOfAdminPage(option, added);
                }
                else if (role == "Costumer" || role == "costumer")
                {
                    printheader();
                    table();
                }
                else if (role == "undefinead")
                {
                    cout << "You have entered wrong credentials." << endl;
                }
            }
        }

        cout << "Enter 0 to go back or 1 to continue : ";
        cin >> option1;
    }
    return 0;
}

void signInPageHeader()
{
    cout << "                               ##########################################                                        " << endl;
    cout << "                               #                                        #                                        " << endl;
    cout << "                               #                                        #                                        " << endl;
    cout << "                               #               SIGN IN PAGE             #                                        " << endl;
    cout << "                               #                                        #                                        " << endl;
    cout << "                               ##########################################                                        " << endl;
    cout << endl;
}

void signUpPageHeader()
{
    cout << "                               ##########################################                                        " << endl;
    cout << "                               #                                        #                                        " << endl;
    cout << "                               #                                        #                                        " << endl;
    cout << "                               #               SIGN UP PAGE             #                                        " << endl;
    cout << "                               #                                        #                                        " << endl;
    cout << "                               ##########################################                                        " << endl;
    cout << endl;
}

int menu()
{
    cout << "                                ##########################################                                     " << endl;
    cout << "                                #                                        #                                     " << endl;
    cout << "                                #                                        #                                     " << endl;
    cout << "                                #            1. SIGN UP.                 #                                     " << endl;
    cout << "                                #                                        #                                     " << endl;
    cout << "                                #                                        #                                     " << endl;
    cout << "                                #            2. SIGN IN.                 #                                     " << endl;
    cout << "                                #                                        #                                     " << endl;
    cout << "                                #                                        #                                     " << endl;
    cout << "                                #            3. EXIT.                    #                                     " << endl;
    cout << "                                #                                        #                                     " << endl;
    cout << "                                #                                        #                                     " << endl;
    cout << "                                ##########################################                                     " << endl;
    cout << "" << endl;
    int num;
    cout << "ENTER   YOUR   OPTION: ";
    cin >> num;
    return num;
}

void printheader()
{
    system("cls");
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "|                          ****    **   **  **      ****     **   **   *******                                 |" << endl;
    cout << "|                         *    *   ** * **  **       **      ** * **   *                                       |" << endl;
    cout << "|                         *    *   **  ***  **       **      **  ***   *******                                 |" << endl;
    cout << "|                         *    *   **   **  **       **      **   **   *                                       |" << endl;
    cout << "|                          ****    **    *  ******  ****     **    *   *******                                 |" << endl;
    cout << "|                                                                                 _    _                       |" << endl;
    cout << "|                                 *****     **      ******     *******           (_)  (_)                      |" << endl;
    cout << "|                                 *       **  **    *    *     *                  \\   /                        |" << endl;
    cout << "|                                 *       ******    ****       *******             \\ /                         |" << endl;
    cout << "|                                 *       **  **    *   *      *                    |                          |" << endl;
    cout << "|                                 *****   **  **    *    *     *******              (_(.)                      |" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}

// for admin to choose what to do after signing in..
void adminpage()
{
    cout << " \t\t                      1. ADD PRODUCTS." << endl;
    cout << " \t\t                      2. DELETE PRODUCTS." << endl;
    cout << " \t\t                      3. PRICE ADJUSTMENTS." << endl;
    cout << " \t\t                      4. COSTUMER'S FEEDBACK." << endl;
    cout << " \t\t                      5. UPDATE PRODUCT INFORMATION." << endl;
}

// for admin to add products in the list...
string products(string allMedicines[], string added, int medicineCount)
{
    cout << "Enter the product you want to add: " << endl;
    cin >> added;
    allMedicines[medicineCount] = added;
    for (int j = 0; j < 12; j++)
    {
        cout << allMedicines[j] << endl;
    }
    cout << endl;
}


/// for admin to delete products from the list...
string deleteProducts(string allMedicines[], int medicineCount)
{
    string deletedProduct;
    cout << "Enter the product you want to delete: ";
    cin >> deletedProduct;

    for (int i = 0; i < 12; i++)
    {
        if (allMedicines[i] == deletedProduct)
        {
            continue;
        }
        cout << allMedicines[i] << endl;
    }
}


// table of products..to show the costumer the available products...
string table()
{
    cout << "     (MEDICINES)             (SYRUPS)               (FIRST AIDS) " << endl;
    cout << "    1. PANADOL              5. BRUFEN             9.  SANIPLAST " << endl;
    cout << "    2. CALPOL               6. HYDRLIN            10. BANDAGES  " << endl;
    cout << "    3. LEFLOX               7. ACEFYL             11. MEDICAL TAPE" << endl;
    cout << "    4. LORIN                8. GRAVINAT           12. MEDICAL SCISSORS" << endl;
    cout << endl;
}

string signInPage(string username, string password, string role, string Username[], string Password[], string Role[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (Username[i] == username && Password[i] == password)
        {
            return Role[i];
        }
    }
    return "undefined";
}

/// adminpage options...
int choiceOfAdminPage(int option, string allMedicines[], string added, int medicineCount)
{

    cout << "Enter any option: ";
    cin >> option;
    if (option == 1)
    {

        products(allMedicines, added, medicineCount);
    }
    if (option == 2)
    {
        deleteProducts(allMedicines, medicineCount);
    }
    if (option == 3)
    {
    }
}

bool signUpCredentials(string username, string password, string role, string Username[], string Password[], string Role[], int &count, int arrSize)
{

    bool isPresent = true;

    for (int i = 0; i < count; i++)
    {
        if (Username[i] == username && Password[i] == password)
        {
            isPresent = false;
            break;
        }
    }
    if (count < arrSize)
    {
        Username[count] = username;
        Password[count] = password;
        Role[count] = role;
        count++;
    }

    return isPresent;
    
}


// int PriceAdjustments()
// {

// }