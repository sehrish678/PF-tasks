#include <iostream>
#include <windows.h>
#include <iomanip> //libraries
#include <conio.h>
#include <sstream>
#include <fstream>

using namespace std;
// Header
void topHeader();
void adminHeader();
void signInHeader();
void signUpHeader();
// clearscreen
void clearScreen();
// loginPage
int loginMenu();
string signIn(string name, string password, string users[], string passwords[], string roles[], int &usersCount);
bool signUp(string name, string password, string role, string users[], string passwords[], string roles[], int &usersCount, int userArrSize);
// adminmenu
int adminPage();
void adminInterface(string products[], string brands[], int quantity[], float prices[], int &productsCount, int &del, string feedbackCount[], int &feedbackiteration, int &adminPassword, string file1);
// adminFeatures
void addProduct(string products[], string brands[], int quantity[], float prices[], int &productsCount);
void viewShopProducts(string products[], string brands[], int quantity[], float prices[], int &productsCount, int &del);
void deleteOldItem(string products[], string brands[], int quantity[], float prices[], int &productsCount);
void updateProduct(string products[], string brands[], int quantity[], float prices[], int &productsCount);
void viewRevenue(float prices[], int quantity[], int &productsCount);
void viewTopSellingProducts(string products[], int quantity[], int &productsCount);
void viewFeedback(string feedbackCount[], int &feedbackiteration);
void changePassword(int &adminPassword);
// usermenu
int userPage();
void userInterface(string file1,string products[], string brands[], int quantity[], float prices[], int &productsCount, int &del, string feedbackCount[], int &feedbackiteration, string passwords[], int usersCount);
// userFeatures
void addProductToCart(string products[], string brands[], float prices[], int quantity[], int productsCount, int cartQuantities[], int &cartCount, string cartProducts[], float cartPrices[], int maxCartSize);
void viewCart(string file1,string products[], string brands[], int quantity[], float prices[], int &cartCount, string cartProducts[], float cartPrices[], int cartQuantities[]);
void removeProductFromCart(int &cartCount, string cartProducts[], float cartPrices[], int cartQuantities[], string products[], float prices[]);
void generateBill(string products[], float cartPrices[], int cartQuantities[], int &cartCount, string cartProducts[]);
string feedback();
void changePasswordOfUser(string passwords[], int usersCount);

void storeSignIn(string users[], string passwords[], string roles[], int &usersCount, string fileName);
void loadSignIn(string users[], string passwords[], string roles[], int &usersCount, string fileName);
string getfield(string record, int field);
void loadProducts(string products[], string brands[],  int quantity[], float prices[] ,int &productsCount, string file1);
void storeProducts(string products[], string brands[],  int quantity[], float prices[] ,int &productsCount, string file1);

int main()
{   

    string fileName = "file.txt";
    string file1 = "products.txt";

    //   feedback data
    string feedbackCount[100];
    int feedbackiteration = 0;

    int cartCount = 0;
    const int maxCartSize = 10;
    string cartProducts[maxCartSize];
    string cartBrands[maxCartSize]; // user page data
    int cartQuantities[maxCartSize];
    float cartPrices[maxCartSize];
    float totalAmount = 0.0;
    // login page data
    const int userArrSize = 10;
    string users[userArrSize];
    string passwords[userArrSize];
    string roles[userArrSize];

    int usersCount = 0;
    loadSignIn(users, passwords, roles, usersCount, fileName);
    // loadProducts(products, brands,  quantity, prices , productsCount, file1);
    

    ////////////////////////////////////////
    // products data
    // string products[], string bands[], int quantity[], float prices[], int &productsCount, int &del
    int del = 0;
    int productsCount = 10;
    string products[100] = {"A.C.", "Laptop", "HeadPhones", "SmartPhones", "Digitalcameras", "SmartWatch", "Tablets", "UPS", "LED", "Printers"};
    string brands[100] = {"Haier", "HP", "Sony", "Samsung", "Canon", "LG", "Apple", "Belkin", "MaxLite", "Dell"};
    int quantity[100] = {10, 14, 15, 17, 16, 11, 9, 8, 14, 7};
    float prices[100] = {200000, 100000, 45000, 100000, 50000, 35000, 80000, 150000, 120000, 60000};
    ////////////////////////////////////////3

  

    int adminPassword = 123;

    int loginOption = 0;
    while (loginOption != 4)
    {
        topHeader();
        loginOption = loginMenu();
        if (loginOption == 1)
        {
            adminHeader();
            int password;
            cout << endl;
            cout << endl;
            cout << "  \t\t\t\t\t\t\t\t\t Enter password: ";
            cin >> password;
            if (password == adminPassword)
            {
                clearScreen();
                adminInterface(products, brands, quantity, prices, productsCount, del, feedbackCount, feedbackiteration, adminPassword, file1);
            }
            else
            {
                cout << endl;
                cout << "  \t\t\t\t\t\t\t\t\t Wrong password! ";
                cout << endl;
            }
        }
        else if (loginOption == 2) // sign in page
        {
            system("cls");
            string name;
            string password;
            string role;
            topHeader();
            signInHeader();
            cout << endl;
            cout << endl;
            cout << "  \t\t\t\t\t\t\t\t\t Enter your Name: ";
            cin >> name;
            cout << "  \t\t\t\t\t\t\t\t\t Enter your Password: ";
            cin >> password;
            role = signIn(name, password, users, passwords, roles, usersCount);
            if (role == "User" || role == "user")
            {
                clearScreen();
                userInterface(file1,products, brands, quantity, prices, productsCount, del, feedbackCount, feedbackiteration, passwords, usersCount); // user interface
            }
            else if (role == "undefined")
            {
                cout << "  \t\t\t\t\t\t\t\t\t You Entered wrong Credentials" << endl;
            }
        }
        else if (loginOption == 3) // sign up page
        {
            system("cls");
            string name;
            string password;
            string role;
            topHeader();
            signUpHeader();
            cout << endl;
            cout << endl;
            cout << "  \t\t\t\t\t\t\t\t\t Enter your Name: ";
            cin >> name;
            cout << "  \t\t\t\t\t\t\t\t\t Enter your Password: ";
            cin >> password;
            cout << "  \t\t\t\t\t\t\t\t\t Enter your Role: ";
            cin >> role;
            bool isValid = signUp(name, password, role, users, passwords, roles, usersCount, userArrSize);
            if (isValid)
            {
                cout << "  \t\t\t\t\t\t\t\t\t Successfully signed up! " << endl;
               
            }
            if (!isValid)
            {
                cout << " \t\t\t\t\t\t\t\t\t\t Sign-up unsuccessful.!" << endl;
            }
            
        }
       
        clearScreen();
    }
      storeSignIn(users, passwords, roles, usersCount, fileName);
}
string signIn(string name, string password, string users[], string passwords[], string roles[], int &usersCount)
{
    for (int index = 0; index < usersCount; index++)
    {
        if (users[index] == name && passwords[index] == password) // check username ane password
        {
            return roles[index];
        }
    }
    return "undefined";
}
bool signUp(string name, string password, string role, string users[], string passwords[], string roles[], int &usersCount, int userArrSize)
{
    bool isPresent = false;

    for (int index = 0; index < usersCount; index++)
    {
        if (users[index] == name && passwords[index] == password)
        {
            isPresent = true;
            break;
        }
    }
    if (isPresent == true)
    {
        return 0;
    }
    else if (usersCount < userArrSize)
    {
        users[usersCount] = name;
        passwords[usersCount] = password;
        roles[usersCount] = role;
        usersCount++;
        return true;
    }
    else
    {
        return false;
    }
}

void adminHeader()
{
    clearScreen();
    topHeader();
    cout << R"(                                                                  _           _          _                 _           )" << endl;
    cout << R"(                                                         /\      | |         (_)        | |               (_)           )" << endl;
    cout << R"(                                                        /  \   __| |_ __ ___  _ _ __    | |     ___   __ _ _ _ __        )" << endl;
    cout << R"(                                                       / /\ \ / _` | '_ ` _ \| | '_ \   | |    / _ \ / _` | | '_ \                 )" << endl;
    cout << R"(                                                      / ____ \ (_| | | | | | | | | | |  | |___| (_) | (_| | | | | |     )" << endl;
    cout << R"(                                                     /_/    \_\__,_|_| |_| |_|_|_| |_|  |______\___/ \__, |_|_| |_|      )" << endl;
    cout << R"(                                                                                                      __/ |              )" << endl;
    cout << R"(                                                                                                     |___/                )" << endl;
    cout << "                                                      ---------------------------------------------------------------" << endl;
}
void signInHeader()
{
    cout << R"(                                                                     _____ _                 _____             )" << endl;
    cout << R"(                                                                    / ____(_)               |_   _|            )" << endl;
    cout << R"(                                                                   | (___  _  __ _ _ __       | |  _ __        )" << endl;
    cout << R"(                                                                    \___ \| |/ _` | '_ \      | | | '_ \       )" << endl;
    cout << R"(                                                                    ____) | | (_| | | | |    _| |_| | | |      )" << endl;
    cout << R"(                                                                   |_____/|_|\__, |_| |_|   |_____|_| |_|      )" << endl;
    cout << R"(                                                                              __/ |                            )" << endl;
    cout << R"(                                                                             |___/                             )" << endl;
    cout << "                                                                    ----------------------------------------" << endl;
}
void signUpHeader()
{
    cout << R"(                                                                      _____ _                 _    _              )" << endl;
    cout << R"(                                                                     / ____(_)               | |  | |             )" << endl;
    cout << R"(                                                                    | (___  _  __ _ _ __     | |  | |_ __         )" << endl;
    cout << R"(                                                                     \___ \| |/ _` | '_ \    | |  | | '_ \        )" << endl;
    cout << R"(                                                                     ____) | | (_| | | | |   | |__| | |_) |       )" << endl;
    cout << R"(                                                                    |_____/|_|\__, |_| |_|    \____/| .__/        )" << endl;
    cout << R"(                                                                               __/ |                | |           )" << endl;
    cout << R"(                                                                              |___/                 |_|           )" << endl;
    cout << "                                                                      ---------------------------------------" << endl;
}
int loginMenu()
{
    system("cls");
    topHeader();
    int option;
    cout << "  \t\t\t\t\t\t\t\t\t ***************************" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *                         *" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *       1. Admin login    *" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *                         *" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *                         *" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *       2. Sign in.       *" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *                         *" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *                         *" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *       3. Sign up.       *" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *                         *" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *                         *" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *       4. Exit.          *" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *                         *" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t ***************************" << endl;
    cout << endl;
    cout << "  \t\t\t\t\t\t\t\t\t Enter the Option Number: ";
    cin >> option;
    return option;
}
void topHeader()
{
    cout << R"(           /$$$$$$$$ /$$                       /$$                                   /$$                            /$$$$$$  /$$                                 )" << endl;
    cout << R"(          | $$_____/| $$                      | $$                                  |__/                           /$$__  $$| $$                                 )" << endl;
    cout << R"(          | $$      | $$  /$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$  /$$$$$$$  /$$  /$$$$$$$  /$$$$$$$      | $$  \__/| $$$$$$$   /$$$$$$   /$$$$$$        )" << endl;
    cout << R"(          | $$$$$   | $$ /$$__  $$ /$$_____/|_  $$_/   /$$__  $$ /$$__  $$| $$__  $$| $$ /$$_____/ /$$_____/      |  $$$$$$ | $$__  $$ /$$__  $$ /$$__  $$       )" << endl;
    cout << R"(          | $$__/   | $$| $$$$$$$$| $$        | $$    | $$  \__/| $$  \ $$| $$  \ $$| $$| $$      |  $$$$$$        \____  $$| $$  \ $$| $$  \ $$| $$  \ $$       )" << endl;
    cout << R"(          | $$      | $$| $$_____/| $$        | $$ /$$| $$      | $$  | $$| $$  | $$| $$| $$       \____  $$       /$$  \ $$| $$  | $$| $$  | $$| $$  | $$       )" << endl;
    cout << R"(          | $$$$$$$$| $$|  $$$$$$$|  $$$$$$$  |  $$$$/| $$      |  $$$$$$/| $$  | $$| $$|  $$$$$$$ /$$$$$$$/      |  $$$$$$/| $$  | $$|  $$$$$$/| $$$$$$$/       )" << endl;
    cout << R"(          |________/|__/ \_______/ \_______/   \___/  |__/       \______/ |__/  |__/|__/ \_______/|_______/        \______/ |__/  |__/ \______/ | $$____/        )" << endl;
    cout << R"(                                                                                                                                                | $$             )" << endl;
    cout << R"(                                                                                                                                                | $$             )" << endl;
    cout << R"(                                                                                                                                                |__/             )" << endl;
    cout << "           $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$        " << endl;
    cout << endl;
    cout << endl;
}
void clearScreen()
{
    cout << endl;
    cout << " \t\t\t\t\t\t\t\t\t Press Any Key to Continue..";
    getch();
    system("cls");
}
int  adminPage()
{
    int adminChoice;
    cout << R"(                                                                         _           _         __  __                       )" << endl;
    cout << R"(                                                                /\      | |         (_)       |  \/  |                      )" << endl;
    cout << R"(                                                               /  \   __| |_ __ ___  _ _ __   | \  / | ___ _ __  _   _      )" << endl;
    cout << R"(                                                              / /\ \ / _` | '_ ` _ \| | '_ \  | |\/| |/ _ \ '_ \| | | |     )" << endl;
    cout << R"(                                                             / ____ \ (_| | | | | | | | | | | | |  | |  __/ | | | |_| |     )" << endl;
    cout << R"(                                                            /_/    \_\__,_|_| |_| |_|_|_| |_| |_|  |_|\___|_| |_|\__,_|     )" << endl;
    cout << endl;
    cout << "                                                              -----------------------------------------------------------" << endl;
    cout << endl;
    cout << "  \t\t\t\t\t\t\t\t\t Select one of the following options....                                                                    " << endl;
    cout << endl;
    cout << "  \t\t\t\t\t\t\t\t\t 1. View Shop Products.                   " << endl;
    cout << "  \t\t\t\t\t\t\t\t\t 2. Add a New Products in Shop.           " << endl;
    cout << "  \t\t\t\t\t\t\t\t\t 3. Delete a Products in Shop.            " << endl;
    cout << "  \t\t\t\t\t\t\t\t\t 4. Update products of Shop.              " << endl;
    cout << "  \t\t\t\t\t\t\t\t\t 5. View Revenue of Shop.                 " << endl;
    cout << "  \t\t\t\t\t\t\t\t\t 6. View Top Selling Products in Shop.    " << endl;
    cout << "  \t\t\t\t\t\t\t\t\t 7. View feedback.    " << endl;
    cout << "  \t\t\t\t\t\t\t\t\t 8. Change password.    " << endl;
    cout << "  \t\t\t\t\t\t\t\t\t 9. Log Out.                              " << endl;
    cout << "  \t\t\t\t\t\t\t\t\t Enter your choice: ";
    cin >> adminChoice;
    return adminChoice;
}
void adminInterface(string products[], string brands[], int quantity[], float prices[], int &productsCount, int &del, string feedbackCount[], int &feedbackiteration, int &adminPassword, string file1)
{
    int adminOption = 0;
     loadProducts(products, brands,  quantity, prices , productsCount, file1);
    while (adminOption != 9)
    {

        topHeader();

        adminOption = adminPage();
        if (adminOption == 1)
        {
            viewShopProducts(products, brands, quantity, prices, productsCount, del);
            clearScreen();
        }
        else if (adminOption == 2)
        {
            viewShopProducts(products, brands, quantity, prices, productsCount, del);
            addProduct(products, brands, quantity, prices, productsCount);
            clearScreen();
        }
        else if (adminOption == 3)
        {
            viewShopProducts(products, brands, quantity, prices, productsCount, del);
            deleteOldItem(products, brands, quantity, prices, productsCount);
            clearScreen();
        }
        else if (adminOption == 4)
        {
            viewShopProducts(products, brands, quantity, prices, productsCount, del);
            updateProduct(products, brands, quantity, prices, productsCount);
            clearScreen();
        }
        else if (adminOption == 5)
        {
            viewShopProducts(products, brands, quantity, prices, productsCount, del);
            viewRevenue(prices, quantity, productsCount);
            clearScreen();
        }
        else if (adminOption == 6)
        {
            viewTopSellingProducts(products, quantity, productsCount);
            clearScreen();
        }
        else if (adminOption == 7)
        {
            viewFeedback(feedbackCount, feedbackiteration);
            clearScreen();
        }
        else if (adminOption == 8)
        {
            changePassword(adminPassword);
            clearScreen();
        }
        storeProducts(products, brands, quantity, prices , productsCount, file1);
    }
}
void viewShopProducts(string products[], string brands[], int quantity[], float prices[], int &productsCount, int &del)
{
    system("cls");
    topHeader();
    cout << "                                                                              View Products    " << endl;
    cout << "                                                                             ***************   " << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t" << left << setw(5) << "No." << setw(20) << "Products Name" << setw(20) << "Brands" << setw(15) << "Quantity" << setw(15) << "Prices" << endl;
    cout << endl;

    for (int i = 0; i < productsCount; i++)
    {
        if (products[i] != "")
        {
            cout << "\t\t\t\t\t\t\t" << left << setw(5) << i + 1 << setw(20) << products[i] << setw(20) << brands[i] << setw(15) << quantity[i] << setw(15) << prices[i] << endl;
        }
    }
}
void addProduct(string products[], string brands[], int quantity[], float prices[], int &productsCount)
{
    cout << endl;
    cout << endl;
    cout << "  \t\t\t\t\t\t\t\t\t  Add a new product" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *******************" << endl;
    cout << endl;
    if (productsCount < 100)
    {
        string newProduct, newBrand;
        int newQuantity;
        float newPrice;
        cout << "  \t\t\t\t\t\t\t\t Enter the name of the new product: ";
        cin >> newProduct;
        cout << "  \t\t\t\t\t\t\t\t Enter the brand of the new product: ";
        cin >> newBrand;
        cout << "  \t\t\t\t\t\t\t\t Enter the quantity of the new product: ";
        cin >> newQuantity;
        cout << "  \t\t\t\t\t\t\t\t Enter the price of the new product: ";
        cin >> newPrice;
        products[productsCount] = newProduct;
        brands[productsCount] = newBrand;
        quantity[productsCount] = newQuantity;
        prices[productsCount] = newPrice;
        productsCount++;
    }
    else
    {
        cout << "  \t\t\t\t\t\t\t\t Product limit reached. Cannot add more products." << endl;
    }
}
void deleteOldItem(string products[], string brands[], int quantity[], float prices[], int &productsCount)
{
    cout << endl;
    cout << endl;
    cout << "  \t\t\t\t\t\t\t\t\t  Delete a  product" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t *******************" << endl;
    cout << endl;
    int productIndex;
    cout << "  \t\t\t\t\t\t\t\t Enter the product index you want to delete or 0 to finish: ";
    cin >> productIndex;
    while (productIndex != 0 && productIndex >= 1 && productIndex <= productsCount)
    {
        if (products[productIndex - 1] != "")
        {
            products[productIndex - 1] = "";
            brands[productIndex - 1] = "";
            quantity[productIndex - 1] = 0;
            prices[productIndex - 1] = 0.0;
            cout << "  \t\t\t\t\t\t\t\t Product deleted." << endl;
            cout << "  \t\t\t\t\t\t\t\t Enter the next product index you want to delete or 0 to finish: ";
            cin >> productIndex;
        }
        else
        {
            cout << "  \t\t\t\t\t\t\t\t Sorry, the product at index " << productIndex << " is not available." << endl;
            cout << "  \t\t\t\t\t\t\t\t Enter another product index or 0 to finish: ";
            cin >> productIndex;
        }
    }
}
void updateProduct(string products[], string brands[], int quantity[], float prices[], int &productsCount)
{
    cout << "  \t\t\t\t\t\t\t\t\t  Update Product" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t ***************" << endl;
    cout << endl;

    int productIndex;
    cout << "  \t\t\t\t\t\t\t\t Enter the product index you want to update or 0 to finish: ";
    cin >> productIndex;

    string attributeType;
    cout << "  \t\t\t\t\t\t\t\t Enter attribute type you want to update (Prices/Brands/Quantities): ";
    cin >> attributeType;

    while (productIndex != 0 && productIndex >= 1 && productIndex <= productsCount)
    {
        if (products[productIndex - 1] != "")
        {
            if (attributeType == "prices")
            {
                cout << "  \t\t\t\t\t\t\t\t Current " << attributeType << ": " << prices[productIndex - 1] << endl;
                cout << "  \t\t\t\t\t\t\t\t Enter new " << attributeType << ": ";
                cin >> prices[productIndex - 1];
            }
            else if (attributeType == "brands")
            {
                cout << "  \t\t\t\t\t\t\t\t Current " << attributeType << ": " << brands[productIndex - 1] << endl;
                cout << "  \t\t\t\t\t\t\t\t Enter new " << attributeType << ": ";
                cin >> brands[productIndex - 1];
            }
            else if (attributeType == "quantities")
            {
                cout << "  \t\t\t\t\t\t\t\t Current " << attributeType << ": " << quantity[productIndex - 1] << endl;
                cout << "  \t\t\t\t\t\t\t\t Enter new " << attributeType << ": ";
                cin >> quantity[productIndex - 1];
            }

            cout << "  \t\t\t\t\t\t\t\t Enter the next product index you want to update or 0 to finish: ";
            cin >> productIndex;
        }
        else
        {
            cout << "  \t\t\t\t\t\t\t\t Sorry, the product at index " << productIndex << " is not available." << endl;
            cout << "  \t\t\t\t\t\t\t\t Enter another product index or 0 to finish: ";
            cin >> productIndex;
        }
    }
}
void viewFeedback(string feedbackCount[], int &feedbackiteration)
{
    clearScreen();
    topHeader();

    int count = 0;
    for (int i = 0; i < feedbackiteration; i++)
    {
        cout << "  \t\t\t\t\t\t\t\t " << feedbackCount[i];
        count++;
    }
}
void viewRevenue(float prices[], int quantity[], int &productsCount)
{
    cout << endl;
    cout << endl;
    cout << "  \t\t\t\t\t\t\t\t\t     View Revenue" << endl;
    cout << "  \t\t\t\t\t\t\t\t\t    **************" << endl;
    cout << endl;
    float totalRevenue = 0.0;
    // Calculate total revenue
    for (int i = 0; i < productsCount; i++)
    {
        totalRevenue += prices[i] * quantity[i];
    }
    cout << fixed << setprecision(2);
    cout << "  \t\t\t\t\t\t\t\t\t    Total Revenue: $" << totalRevenue << endl;
}
void viewTopSellingProducts(string products[], int quantity[], int &productsCount)
{
    system("cls");
    topHeader();
    cout << "                                                                              View Top Selling Products" << endl;
    cout << "                                                                             ***************************   " << endl;
    cout << endl;
    // Sort products based on quantities
    for (int i = 0; i < productsCount - 1; i++)
    {
        for (int j = 0; j < productsCount - i - 1; j++)
        {
            if (quantity[j] < quantity[j + 1])
            {
                // Swap quantities
                int tempQuantity = quantity[j];
                quantity[j] = quantity[j + 1];
                quantity[j + 1] = tempQuantity;
                // Swap product names
                string tempProduct = products[j];
                products[j] = products[j + 1];
                products[j + 1] = tempProduct;
            }
        }
    }
    cout << "\t\t\t\t\t\t\tNo.  Products Name\tQuantity Sold" << endl;
    // Display the top-selling products
    for (int i = 0; i < productsCount; i++)
    {
        cout << "\t\t\t\t\t\t\t" << left << setw(5) << i + 1 << setw(20) << products[i] << setw(15) << quantity[i] << endl;
    }
}
void changePassword(int &adminPassword)
{
    int currentPassword;
    cout << "Current password: ";
    cin >> currentPassword;
    if (adminPassword == currentPassword)
    {
        int newpassword;
        cout << "enter new password: ";
        cin >> newpassword;
        adminPassword = newpassword;
    }
}

// user menu
int userPage()
{
    int userChoice;
    cout << R"(                                                             _    _                   __  __                       )" << endl;
    cout << R"(                                                            | |  | |                 |  \/  |                      )" << endl;
    cout << R"(                                                            | |  | |___  ___ _ __    | \  / | ___ _ __  _   _      )" << endl;
    cout << R"(                                                            | |  | / __|/ _ \ '__|   | |\/| |/ _ \ '_ \| | | |     )" << endl;
    cout << R"(                                                            | |__| \__ \  __/ |      | |  | |  __/ | | | |_| |     )" << endl;
    cout << R"(                                                             \____/|___/\___|_|      |_|  |_|\___|_| |_|\__,_|     )" << endl;
    cout << "                                                             ------------------------------------------------- " << endl;
    cout << endl;
    cout << "  \t\t\t\t\t\t\t\t Select one of the following options....                                                                    " << endl;
    cout << endl;
    cout << "  \t\t\t\t\t\t\t\t 1. View Products of Shop.                            " << endl;
    cout << "  \t\t\t\t\t\t\t\t 2. Add Products to Cart.                             " << endl;
    cout << "  \t\t\t\t\t\t\t\t 3. View Cart.                                        " << endl;
    cout << "  \t\t\t\t\t\t\t\t 4. Remove Products from Cart.                        " << endl;
    cout << "  \t\t\t\t\t\t\t\t 5. Display bill.                                     " << endl;
    cout << "  \t\t\t\t\t\t\t\t 6. Feedback.                                         " << endl;
    cout << "  \t\t\t\t\t\t\t\t 7. Change password                                   " << endl;
    cout << "  \t\t\t\t\t\t\t\t 8. Log out                                           " << endl;
    cout << "  \t\t\t\t\t\t\t\t Enter your choice: ";
    cin >> userChoice;
    return userChoice;
}
void userInterface(string file1,string products[], string brands[], int quantity[], float prices[], int &productsCount, int &del, string feedbackCount[], int &feedbackiteration, string passwords[], int usersCount)
{

    int cartCount = 0;
    const int maxCartSize = 10;
    string cartProducts[maxCartSize];
    string cartBrands[maxCartSize];
    int cartQuantities[maxCartSize];
    float cartPrices[maxCartSize];
    float totalAmount = 0.0;
    int userOption = 0;

     loadProducts(products, brands,  quantity, prices , productsCount, file1);
    while (userOption != 8)
    {
        topHeader();
        userOption = userPage();
        if (userOption == 1)
        {

            viewShopProducts(products, brands, quantity, prices, productsCount, del);
            clearScreen();
        }
        else if (userOption == 2)
        {
            viewShopProducts(products, brands, quantity, prices, productsCount, del);
            addProductToCart(products, brands, prices, quantity, productsCount, cartQuantities, cartCount, cartProducts, cartPrices, maxCartSize);
            clearScreen();
        }
        else if (userOption == 3)
        {
            viewCart(file1,products, brands, quantity, prices, cartCount, cartProducts, cartPrices, cartQuantities);
            clearScreen();
        }
        else if (userOption == 4)
        {
            viewCart(file1,products, brands, quantity, prices, cartCount, cartProducts, cartPrices, cartQuantities);
            removeProductFromCart(cartCount, cartProducts, cartPrices, cartQuantities, products, prices);
            clearScreen();
        }
        else if (userOption == 5)
        {
            viewCart(file1,products, brands, quantity, prices, cartCount, cartProducts, cartPrices, cartQuantities);
            generateBill(products, cartPrices, cartQuantities, cartCount, cartProducts);
            clearScreen();
        }
        else if (userOption == 6)
        {
            feedbackCount[feedbackiteration] = feedback();
            feedbackiteration++;
            clearScreen();
        }
        else if (userOption == 7)
        {
            changePasswordOfUser(passwords, usersCount);
            clearScreen();
        }
    }
    storeProducts( products,  brands,   quantity,  prices ,productsCount,  file1);
}
void viewCart(string file1,string products[], string brands[], int quantity[], float prices[], int &cartCount, string cartProducts[], float cartPrices[], int cartQuantities[])
{
    system("cls");
    topHeader();
    if (cartCount == 0)
    {
        cout << " \t\t\t\t\t\t\t Your cart is empty.";
    }
    else
    {
        cout << "  \t\t\t\t\t\t\t\t                     Your Cart:\n";
        cout << "  \t\t\t\t\t\t\t\t                    ***********\n";
        cout << endl;
        cout << "\t\t\t\t\t\t\t" << left << setw(5) << "No." << setw(20) << "Products Name" << setw(20) << "Brands" << setw(15) << "Quantities" << setw(15) << "Prices of Single Product" << endl;
        cout << endl;

        for (int i = 0; i < cartCount; i++)
        {
            // Convert product index from string to int using std::istringstream
            std::istringstream iss(cartProducts[i]);
            int productIndex;
            iss >> productIndex;
            cout << " \t\t\t\t\t\t\t" << left << setw(5) << i + 1 << setw(20) << products[productIndex - 1] << setw(20) << brands[productIndex - 1] << setw(15) << cartQuantities[i] << setw(15) << cartPrices[i] << endl;
        }
    }
}
void addProductToCart(string products[], string brands[], float prices[], int quantity[], int productsCount, int cartQuantities[], int &cartCount, string cartProducts[], float cartPrices[], int maxCartSize)
{
    int choice;
    int quantityChoice;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t\t     Add products                                   " << endl;
    cout << "\t\t\t\t\t\t\t\t\t    **************                                         " << endl;
    cout << endl;
    cout << "  \t\t\t\t\t\t\t Enter the product number you want to add to your cart or 0 to finish: ";
    cin >> choice;

    while (choice != 0 && cartCount < maxCartSize)
    {
        if (choice >= 1 && choice <= productsCount)
        {
            cout << "  \t\t\t\t\t\t\t Enter the quantity for this product: ";
            cin >> quantityChoice;

            if (quantityChoice > 0 && quantityChoice <= quantity[choice - 1])
            {
                // Convert product index from int to string using std::to_string
                cartProducts[cartCount] = to_string(choice);
                // Adjust the index to access arrays correctly (zero-indexed)
                int adjustedIndex = choice - 1;
                cartPrices[cartCount] = prices[adjustedIndex] * quantityChoice;
                cartQuantities[cartCount] = quantityChoice;
                cartCount++;
                cout << "  \t\t\t\t\t\t\t Product added to your cart." << endl;
                ;
            }
            else
            {
                cout << "  \t\t\t\t\t\t\t Invalid quantity choice. Please enter a valid quantity." << endl;
            }
        }
        else
        {
            cout << "  \t\t\t\t\t\t\t Invalid product choice.";
        }

        // Display the current cart and prompt for the next product
        cout << "  \t\t\t\t\t\t\t Enter the next product number you want to add to your cart or enter 0 to finish: ";
        cin >> choice;
    }

    if (cartCount >= maxCartSize)
    {
        cout << "  \t\t\t\t\t\t\t Your cart is full. Remove items before adding more.";
    }
}
void removeProductFromCart(int &cartCount, string cartProducts[], float cartPrices[], int cartQuantities[], string products[], float prices[])
{
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t\t     Remove products from cart                                   " << endl;
    cout << "\t\t\t\t\t\t\t\t\t    ***************************                                         " << endl;
    cout << endl;
    if (cartCount == 0)
    {
        cout << "  \t\t\t\t\t\t\t Your cart is already empty.";
    }
    else
    {
        int choice;
        cout << "  \t\t\t\t\t\t\t Enter the numbers of the products you want to remove from your cart or 0 to finish: ";

        while (true)
        {
            cin >> choice;

            if (choice == 0)
            {
                break; // Exit the loop
            }
            if (choice >= 1 && choice <= cartCount)
            {
                cout << "  \t\t\t\t\t\t\t You have " << cartQuantities[choice - 1] << " units of " << products[stoi(cartProducts[choice - 1]) - 1] << "in your cart." << endl;
                cout << "  \t\t\t\t\t\t\t How many units do you want to remove: ";
                int removeQuantity;
                cin >> removeQuantity;

                if (removeQuantity > 0 && removeQuantity <= cartQuantities[choice - 1])
                {
                    // Update the quantity and price in the cart
                    cartQuantities[choice - 1] -= removeQuantity;
                    cartPrices[choice - 1] = prices[stoi(cartProducts[choice - 1]) - 1] * cartQuantities[choice - 1];

                    // If the quantity becomes 0, remove the product from the cart
                    if (cartQuantities[choice - 1] == 0)
                    {
                        for (int i = choice - 1; i < cartCount - 1; i++)
                        {
                            cartProducts[i] = cartProducts[i + 1];
                            cartPrices[i] = cartPrices[i + 1];
                            cartQuantities[i] = cartQuantities[i + 1];
                        }
                        cartCount--;
                    }

                    cout << "  \t\t\t\t\t\t\t Units removed from your cart." << endl;
                }
                else
                {
                    cout << "  \t\t\t\t\t\t\t Invalid quantity. Please enter a valid quantity to remove.";
                }
            }
            else
            {
                cout << "  \t\t\t\t\t\t\t Invalid product choice.";
            }

            cout << "  \t\t\t\t\t\t\t Enter another product number to remove or 0 to finish: ";
        }
    }
}
void generateBill(string products[], float cartPrices[], int cartQuantities[], int &cartCount, string cartProducts[])
{
    system("cls");
    topHeader();
    if (cartCount == 0)
    {
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t\t Your cart is empty. No bill generated.";
    }
    else
    {
        cout << "\t\t\t\t\t\t\t ------------------- Your Cart Bill -------------------\n";
        cout << "\t\t\t\t\t\t\t" << setw(30) << left << " Product" << setw(15) << "Quantity" << setw(20) << "Total Price" << endl;
        cout << "\t\t\t\t\t\t\t --------------------------------------------------------\n";

        float totalAmount = 0.0;

        for (int i = 0; i < cartCount; i++)
        {
            int productIndex = stoi(cartProducts[i]) - 1;
            cout << "\t\t\t\t\t\t\t " << setw(30) << left << products[productIndex] << setw(15) << cartQuantities[i] << setw(20) << cartPrices[i] << endl;
            totalAmount += cartPrices[i];
        }
        cout << "\t\t\t\t\t\t\t --------------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t Total Amount: " << totalAmount << "\n";
        cout << "\t\t\t\t\t\t\t Thank you for shopping with us...!";
    }
}
string feedback()
{
    clearScreen();
    topHeader();
    string comment;
    cout << "  \t\t\t\t\t\t\t Enter your feedback about shop: " << endl;
    cin.ignore();
    getline(cin, comment);
    return comment;
}
void changePasswordOfUser(string passwords[], int usersCount)
{
    string currentpass;
    cout << "\t\t\t\t\t\t\t\t\t\tEnter the current password: ";
    cin >> currentpass;

    int index = 0;
    for (int i = 0; i < usersCount; i++)
    {
        if (currentpass == passwords[i])
        {
            index = i;
            break;
        }
    }
    string newpass;
    cout << "\t\t\t\t\t\t\t\tEnter the new password: ";
    cin >> newpass;
    passwords[index] = newpass;

    cout << "\t\\t\t\t\t\t\t\t\t\tYour password has been changed successfully!"
         << endl;
    Sleep(1000);
}

void storeSignIn(string users[], string passwords[], string roles[], int &usersCount, string fileName)
{
   
    fstream file;
    file.open(fileName, ios::out);
    for (int i = 0; i < usersCount; i++)
    {
        file << users[i] << "," << passwords[i] << "," << roles[i] << endl;
    }

    file.close();
}

void loadSignIn(string users[], string passwords[], string roles[], int &usersCount, string fileName)
{
    string line;
    fstream data;
    string record = "";
    data.open(fileName, ios::in);
  if (data.fail())
    return;           
  while (!(data.eof())) {
    getline(data, record);
    users[usersCount] = getfield(record, 1);
    passwords[usersCount] = getfield(record, 2);
    roles[usersCount] = getfield(record, 3);

    usersCount++;
    }
    data.close();

}
string getfield(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int i = 0; i < record.length(); i++)
    {
        if (record[i] == ',')
        {
            commaCount++;
        }
        else if (commaCount == field)
        {
            item = item + record[i];
        }
    }
    return item;
}

void storeProducts(string products[], string brands[],  int quantity[], float prices[] ,int &productsCount, string file1){


  fstream file;
  file.open("file1.txt", ios::out);
  for (int i = 0; i < productsCount; i++) {
    file << products[i] << "," << brands[i] << "," << quantity[i] << "," << prices[i];
    if (i != productsCount - 1)  // if not last iteration so store new line
      file << endl;
  }
  file.close();
}

void loadProducts(string products[], string brands[],  int quantity[], float prices[] ,int &productsCount, string file1){
  string line;
  fstream data;
  data.open("file1.txt", ios::in);
  
  if (data.fail())
    return;
  while (!(data.eof())) {
    getline(data, line);
    products[productsCount] = getfield(line, 1);
    brands[productsCount] = (getfield(line, 2));
    quantity[productsCount] = stoi(getfield(line, 3));
    prices[productsCount] = stoi(getfield(line, 4));

    productsCount++;
  }
}