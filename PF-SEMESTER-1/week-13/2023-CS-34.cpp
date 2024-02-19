#include <conio.h>
#include <iomanip>
#include <iostream>
#include <windows.h>

using namespace std;

string menu(string num);
void printheader();
void adminPageHeader();
void signUpPageHeader();
void signInPageHeader();
void CostumerPage();
void checkFeedbacks(int &count, string feedbackArray[]);
void costumerPageHeader();
string feedback();
int applyDiscount(string allMedicines[], int allProductsPrice[],
                  int medicineCount, int Quantity[]);
int choiceOfAdminPage(int Quantity[], int &size, int option,
                      string allMedicines[], string added, int &medicineCount,
                      int allProductPrice[], string product, int newPrice,
                      int count, string feedbackArray[], string Password[],
                      string password);
string signInPage(string username, string password, string role,
                  string Username[], string Password[], string Role[],
                  int count);
bool signUpCredentials(string username, string password, string role,
                       string Username[], string Password[], string Role[],
                       int &count, int arrSize);
int choiceOfCostumer(string Password[], int &maxFeedbacks, int count,
                     int option, int BillCount, string allMedicines[],
                     int allProductsPrice[], int medicineCount, int &size,
                     string feedbackArray[], int Quantity[],
                     string productToBuy);
void AlterPrice(string allMedicines[], int medicineCount,
                int allProductsPrice[], int newPrice, string product,
                int Quantity[]);
int BuyProduct(int medicineCount, string allMedicines[], int allProductsPrice[],
               string productToBuy);
int applyTaxes(string allMedicines[], int allProductsPrice[], int medicineCount,
               int Quantity[]);
void adminpage();
int PriceAdjustments(string allMedicines[], int allProductsPrice[], int &count,
                     int &medicineCount, int newPrice, string product,
                     int Quantity[]);
string products(string allMedicines[], int &medicineCount, int Quantity[],
                int allProductPrice[]);
string deleteProducts(string allMedicines[], int &medicineCount,
                      int allProductPrice[], int Quantity[]);
void changePassword(string Password[], int count);
void ViewList(string allMedicines[], int allProductsPrice[], int medicineCount,
              int Quantity[]);
string setcolor(unsigned short color);
bool ValidOrNot(int num);

int main() {
  string num;
  int const arrSize = 100;
  string Username[arrSize];
  string Password[arrSize];
  string Role[arrSize];
  int count = 0;
  int BillCount;
  int maxFeedbacks = 100;

  int size = 100;
  string product;
  int newPrice;
  string productToBuy;

  int medicineCount = 12;
  string allMedicines[size] = {"PANADOL",  "CALPOL",        "LEFLOX",
                               "LORIN",    "BRUFEN",        "HYDRLIN",
                               "ACEFYL",   "GRAVINAT",      "SANIPLAST",
                               "BANDAGES", "MEDICAL TAPES", "MEDICAL SCISSORS"};
  int allProductsPrice[size] = {100, 200, 150, 100, 220, 300,
                                100, 400, 300, 200, 100, 200};
  int Quantity[size] = {20, 30, 40, 50, 60, 80, 90, 60, 80, 8, 45, 9};

  int entered, option;
  string added, category;
  int option1;

  while (num != "3") {
    printheader();
    num = menu(num);

    if (num == "1") // for signing up..
    {

      system("cls");
      string username, password, role;

      printheader();
      signUpPageHeader();
      setcolor(2);
      cout << "\t\t\t\t\t\t\t\t\tENTER THE USERNAME: ";
      cin >> username;
      cout << "\t\t\t\t\t\t\t\t\tENTER YOUR PASSWORD: ";
      cin >> password;
      cout << "\t\t\t\t\t\t\t\t\tENTER YOUR ROLE: ";
      cin >> role;

      bool isTrue = signUpCredentials(username, password, role, Username,
                                      Password, Role, count, arrSize);
      if (isTrue) {
        setcolor(2);
        cout << "\t\t\t\t\t\t\t\t\t<<<SIGNED UP SUCCESSFULLY>>>" << endl;
      } else if (!isTrue) {
        setcolor(4);
        cout << "\t\t\t\t\t\t\t\t\t<<<NOT SIGNED UP SUCCESSFULLY>>>" << endl;
      }
    } else if (num == "2") // for signing in..
    {
      string username;
      string password;
      string role;
      string product;
      int newPrice;
      string feedbackArray[count];

      printheader();
      signInPageHeader();
      setcolor(2);
      cout << "\t\t\t\t\t\t\t\t\t ENTER THE USERNAME: ";
      cin >> username;
      cout << "\t\t\t\t\t\t\t\t\t ENTER YOUR PASSWORD: ";
      cin >> password;

      role =
          signInPage(username, password, role, Username, Password, Role, count);
      if (option1 == 0) {
        printheader();
        menu(num);
      } else if (option1 == 1) {

        if ((role == "Admin" || role == "admin")) {
          system("cls");
          printheader();
          adminPageHeader();
          setcolor(2);
          cout << "\t\t\t\t\t\t\t\t\t    Access Gauranteed." << endl;
          Sleep(600);
          system("cls");
          printheader();
          adminPageHeader();
          choiceOfAdminPage(Quantity, size, option, allMedicines, added,
                            medicineCount, allProductsPrice, product, newPrice,
                            count, feedbackArray, Password, password);
        }

        else if (role == "Customer" || role == "customer") {
          cout << endl;
          system("cls");
          printheader();
          costumerPageHeader();
          setcolor(2);
          cout << "\t\t\t\t\t\t\t\t\t    Access Gauranteed." << endl;
          Sleep(600);
          system("cls");
          printheader();
          costumerPageHeader();
          CostumerPage();
          choiceOfCostumer(Password, maxFeedbacks, count, option, BillCount,
                           allMedicines, allProductsPrice, medicineCount, size,
                           feedbackArray, Quantity, productToBuy);
        } else if (role == "undefined") {
          setcolor(4);
          cout << "\t\t\t\t\t\t\t\t   You have entered wrong credentials.."
               << endl;
        }
      }

    }

    else {
      setcolor(4);
      cout << "\t\t\t\t\t\t\t\t  Invalid Input.Try again." << endl;
    }
    setcolor(14);
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t  Enter 0 to go back or 1 to continue : ";
    cin >> option1;
  }
  return 0;
}

void signInPageHeader() {
  setcolor(15);
  cout << "\t\t\t\t\t\t\t\t ##########################################" << endl;
  cout << "\t\t\t\t\t\t\t\t #                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t #                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t #               SIGN IN PAGE             #" << endl;
  cout << "\t\t\t\t\t\t\t\t #                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t ##########################################" << endl;
  cout << endl;
}

void signUpPageHeader() {
  setcolor(15);
  cout << "\t\t\t\t\t\t\t\t ##########################################" << endl;
  cout << "\t\t\t\t\t\t\t\t #                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t #                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t #               SIGN UP PAGE             #" << endl;
  cout << "\t\t\t\t\t\t\t\t #                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t ##########################################" << endl;
  cout << endl;
}

string menu(string num) {
  setcolor(15);
  cout << "\t\t\t\t\t\t\t\t##########################################" << endl;
  cout << "\t\t\t\t\t\t\t\t#                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t#                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t#            1. SIGN UP.                 #" << endl;
  cout << "\t\t\t\t\t\t\t\t#                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t#                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t#            2. SIGN IN.                 #" << endl;
  cout << "\t\t\t\t\t\t\t\t#                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t#                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t#            3. EXIT.                    #" << endl;
  cout << "\t\t\t\t\t\t\t\t#                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t#                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t##########################################" << endl;
  cout << "" << endl;
  setcolor(2);

  cout << "\t\t\t\t\t\t\t\t  ENTER   YOUR   OPTION: ";
  cin >> num;
  return num;
}

void printheader() {
  system("cls");
  cout << endl;
  setcolor(1);
  cout << R"(
                                              ____   _   _  _       _____  _   _  ______    _____            _____   ______ 
                                             / __ \ | \ | || |     |_   _|| \ | ||  ____|  / ____|    /\    |  __ \ |  ____|
                                            | |  | ||  \| || |       | |  |  \| || |__    | |        /  \   | |_) | |  |_   
                                            | |  | || . ` || |       | |  | . ` ||  __|   | |       / /\ \  |  _  / |  __|  
                                            | |_ | ||  |\ || |___    | |  | |\  || |____  | |____  / ____ \ | | \ \ | |____ 
                                             \____/ |_| \_||______||_____||_| \_||______|  \_____|/_/    \_\|_|  \_\|______|       )"
       << endl;
  cout << "\t\t\t\t\t    "
          "--------------------------------------------------------------------"
          "------------"
       << endl;
  cout << "\t\t\t\t\t    "
          "--------------------------------------------------------------------"
          "------------"
       << endl;
  cout << endl;
  cout << endl;
}

void adminPageHeader() {
  setcolor(15);
  cout << endl;
  cout << "\t\t\t\t\t\t\t\t ##########################################" << endl;
  cout << "\t\t\t\t\t\t\t\t #                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t #                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t #               ADMIN PAGE               #" << endl;
  cout << "\t\t\t\t\t\t\t\t #                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t ##########################################" << endl;
  cout << endl;
}

// for admin to choose what to do after signing in..
void adminpage() {
  setcolor(5);
  cout << "\t\t\t\t\t\t\t\t\t 1. ADD PRODUCTS." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 2. DELETE PRODUCTS." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 3. PRICE ADJUSTMENTS." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 4. COSTUMER'S FEEDBACK." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 5. APPLY DISCOUNT." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 6. APPLY TAXES." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 7. LOG OUT." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 8. CHANGE PASSWORD." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 9. VIEW LIST." << endl;
}

// for admin to add products in the list...
string products(string allMedicines[], int &medicineCount, int Quantity[],
                int allProductPrice[]) {
  setcolor(10);
  string added;
  cout << "\t\t\t\t\t\t\t\tEnter the product you want to add: ";
  cin >> added;
  allMedicines[medicineCount] = added;
  medicineCount++;

  cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "ALL PRODUCTS" << left
       << setw(20) << "PRICES" << left << setw(20) << "QUANTITY" << endl;
  for (int j = 0; j < medicineCount; j++) {

    cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << allMedicines[j] << left
         << setw(20) << allProductPrice[j] << left << setw(20) << Quantity[j]
         << endl;
  }

  cout << "\t\t\t\t\t\t\t\t\t Press any key to continue...";
  getch();
}

/// for admin to delete products from the list...
string deleteProducts(string allMedicines[], int &medicineCount,
                      int allProductPrice[], int Quantity[]) {
  setcolor(10);
  int numOfProducts;
  cout << "\t\t\t\t\t\t\t\tEnter the index of product you want to delete: ";
  cin >> numOfProducts;

  while ((numOfProducts != 0) && (numOfProducts >= 1) &&
         (numOfProducts <= medicineCount)) {
    for (int i = numOfProducts; i < medicineCount; i++) {
      allMedicines[i - 1] = allMedicines[i];
      allProductPrice[i - 1] = allProductPrice[i];
      Quantity[i - 1] = Quantity[i];
    }
    if (numOfProducts == 0) {
      system("cls");
      adminPageHeader();
      adminpage();
    }
    break;
  }
  medicineCount--;

  cout << "\t\t\t\t\t\t\t\tPress any key to continue...";
  getch();
}

// for signing in...
string signInPage(string username, string password, string role,
                  string Username[], string Password[], string Role[],
                  int count) {
  for (int i = 0; i < count; i++) {
    if (Username[i] == username && Password[i] == password) {
      return Role[i];
    }
  }
  return "undefined";
}

// to adjust the prices of products....
int PriceAdjustments(string allMedicines[], int allProductsPrice[], int &count,
                     int &medicineCount, int newPrice, string product,
                     int Quantity[]) {
  setcolor(10);
  AlterPrice(allMedicines, medicineCount, allProductsPrice, newPrice, product,
             Quantity);
  for (int i = 0; i < medicineCount; i++) {
    cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << allMedicines[i] << left
         << setw(20) << allProductsPrice[i] << left << setw(20) << Quantity[i]
         << endl;
  }

  cout << "\t\t\t\t\t\t\tPress any key to continue...";
  getch();
}

/// adminpage options...
int choiceOfAdminPage(int Quantity[], int &size, int option,
                      string allMedicines[], string added, int &medicineCount,
                      int allProductsPrice[], string product, int newPrice,
                      int count, string feedbackArray[], string Password[],
                      string password) 
                     
   {
  
  while (option != 8)
   {
    system("cls");
    printheader();
    adminPageHeader();
    adminpage();

    cout << "\t\t\t\t\t\t\t\t\tEnter any option: ";
    cin >> option;
    if (option == 1) // for admin to add products in the list...
    {
      system("cls");
      printheader();
      adminPageHeader();
      ViewList(allMedicines, allProductsPrice, medicineCount, Quantity);
      cout << endl;
      products(allMedicines, medicineCount, Quantity, allProductsPrice);
    } 
    else if (option == 2) // for admin to delete products from the list...
    {
      system("cls");
      printheader();
      adminPageHeader();
      ViewList(allMedicines, allProductsPrice, medicineCount, Quantity);
      cout << endl;
      deleteProducts(allMedicines, medicineCount, allProductsPrice, Quantity);
    } 
    else if (option == 3) // it is for admin to adjust the prices of the products...
    {
      system("cls");
      printheader();
      adminPageHeader();
      PriceAdjustments(allMedicines, allProductsPrice, count, medicineCount,
                       newPrice, product, Quantity);
    } 
    else if (option == 4) 
    {
      system("cls");
      printheader();
      adminPageHeader();
      checkFeedbacks(count, feedbackArray);
    }
     else if (option == 5) {
      system("cls");
      printheader();
      adminPageHeader();
      applyDiscount(allMedicines, allProductsPrice, medicineCount, Quantity);
    } 
    else if (option == 6) {
      system("cls");
      printheader();
      adminPageHeader();
      applyTaxes(allMedicines, allProductsPrice, medicineCount, Quantity);
    } 
    else if (option == 8) {
      system("cls");
      printheader();
      adminPageHeader();
      changePassword(Password, count);
    } 
    else if (option == 9) {
      system("cls");
      printheader();
      adminPageHeader();
      ViewList(allMedicines, allProductsPrice, medicineCount, Quantity);
    } 
    else if (option == 7) // it is for admin to logout of his/her account..
     { 
      return 0;
     }
  }
  cout << "\t\t\t\t\t\t\t\tPress any key to continue..." << endl;
  getch();
}

bool signUpCredentials(string username, string password, string role,
                       string Username[], string Password[], string Role[],
                       int &count, int arrSize) 
{

  bool isPresent = true;

  for (int i = 0; i < count; i++) {
    if (Username[i] == username && Password[i] == password) {
      isPresent = false;
      break;
    }
  }
  if (count < arrSize) {
    Username[count] = username;
    Password[count] = password;
    Role[count] = role;
    count++;
  }

  return isPresent;
}


///to view the list ...
string ViewList(string allMedicines[], string allProductsPrice[],
                int medicineCount)
{
  setcolor(10);
  cout << "\t\t\t\t\t\t\t\t"
       << "ALL PRODUCTS"
       << "\t\t\t"
       << "PRICES" << endl;
  for (int i = 0; i < medicineCount; i++) {
    cout << "\t\t\t\t\t\t\t\t" << allMedicines[i] << "\t\t\t"
         << allProductsPrice[i] << endl;
  }
  cout << "\t\t\t\t\t\t\t\tPress any key to continue..." << endl;
  getch();
}


///for customer to enter any choice...
int choiceOfCostumer(string Password[], int &maxFeedbacks, int count,
                     int option, int BillCount, string allMedicines[],
                     int allProductsPrice[], int medicineCount, int &size,
                     string feedbackArray[], int Quantity[],
                     string productToBuy) 

{

  while (true) {
    system("cls");
    printheader();
    costumerPageHeader();
    CostumerPage();
    cout << "\t\t\t\t\t\t\t\t\t Enter your choice: ";
    cin >> option;
    if (option == 1) {
      system("cls");
      printheader();
      costumerPageHeader();
      ViewList(allMedicines, allProductsPrice, medicineCount, Quantity);
    } else if (option == 2) {
      system("cls");
      printheader();
      costumerPageHeader();
      ViewList(allMedicines, allProductsPrice, medicineCount, Quantity);
      BuyProduct(medicineCount, allMedicines, allProductsPrice, productToBuy);
    } else if (option == 3) {
      system("cls");
      printheader();
      costumerPageHeader();
      feedbackArray[count]=feedback();
      count++;
    } else if (option == 4) {
      system("cls");
      printheader();
      costumerPageHeader();
      setcolor(10);
      cout
          << R"(                                                                    If you want more information about our
                                                                    website or you want to check if its 
                                                                    registered or not,you can contact on
                                                                    this number (000-111-777-0).Thanks!. 
                                                                       )"
          << endl;
      cout << "\t\t\t\t\t\t\t\t      Press any key to continue..." << endl;
      getch();
    } else if (option == 5) {
      system("cls");
      printheader();
      costumerPageHeader();
      changePassword(Password, count);
    }

    else if (option == 6) {
      return 0;
    }
  }
  cout << "\t\t\t\t\t\t\t\tPress any key to continue..." << endl;
  getch();
}

///header of customer page..
void costumerPageHeader() {
  setcolor(15);
  cout << "\t\t\t\t\t\t\t\t ##########################################" << endl;
  cout << "\t\t\t\t\t\t\t\t #                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t #                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t #               CUSTOMER PAGE            #" << endl;
  cout << "\t\t\t\t\t\t\t\t #                                        #" << endl;
  cout << "\t\t\t\t\t\t\t\t ##########################################" << endl;
  cout << endl;
}


///choices of customer page..
void CostumerPage() {
  setcolor(5);
  cout << "\t\t\t\t\t\t\t\t\t 1. View products." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 2. Add to Cart." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 3. Give Feedback." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 4. Contact Information." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 5. Change password." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 6. Logout of account." << endl;
}


///this func. is to buy products...
int BuyProduct(int medicineCount, string allMedicines[], int allProductsPrice[],
               string productToBuy) {
  setcolor(10);

  cout << "\t\t\t\t\t\t\t\tEnter the product you want to buy: ";
  cin >> productToBuy;
  int quantity;
  cout << "\t\t\t\t\t\t\t\tEnter the quantity of the product: ";
  cin >> quantity;

  for (int i = 0; i < medicineCount; i++) {
    if (allMedicines[i] == productToBuy) {
      cout << "\t\t\t\t\t\t\t\tThe Price of " << allMedicines[i] << " is "
           << allProductsPrice[i] * quantity << endl;
      cout << "\t\t\t\t\t\t\t\tThanks for your purchase.";
      Sleep(1000);
      break;
    }
  }
  cout << "\t\t\t\t\t\t\t\tPress any key to continue..." << endl;
  getch();
}


///to change password and is for both admin and customer...
void changePassword(string Password[], int count) {
  setcolor(10);
  string currentPassword;
  cout << "\t\t\t\t\t\t\t\tEnter the current password: ";
  cin >> currentPassword;

  int index = 0;
  for (int i = 0; i < count; i++) {
    if (currentPassword == Password[i]) {
      index = i;
      break;
    }
  }
  string newPassword;
  cout << "\t\t\t\t\t\t\t\tEnter the new password: ";
  cin >> newPassword;
  Password[index] = newPassword;

  cout << "\t\t\t\t\t\t\t\tYour password has been changed successfully!"
       << endl;
  Sleep(1000);
}


///it is to apply discount ...
int applyDiscount(string allMedicines[], int allProductsPrice[],
                  int medicineCount, int Quantity[]) {
  setcolor(10);
  cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "ALL PRODUCTS " << left
       << setw(20) << "PRICES" << left << setw(20) << "QUANTITY" << endl;
  for (int i = 0; i < medicineCount; i++) {
    cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << allMedicines[i] << left
         << setw(20) << allProductsPrice[i] << left << setw(20) << Quantity[i]
         << endl;
  }

  int discount;

  cout << "\t\t\t\t\t\t\t\tEnter the percentage of discount: ";
  cin >> discount;

  cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "ALL PRODUCTS " << left
       << setw(20) << "PRICES" << left << setw(20) << "QUANTITY" << endl;
  for (int i = 0; i < medicineCount; i++) {
    allProductsPrice[i] =
        (allProductsPrice[i] - (allProductsPrice[i]) * discount / 100);
    cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << allMedicines[i] << left
         << setw(20) << allProductsPrice[i] << left << setw(20) << Quantity[i]
         << endl;
  }
  cout << "\t\t\t\t\t\t\t\tPress any key to continue..." << endl;
  getch();
}

///this function is called in price adjustments function
void AlterPrice(string allMedicines[], int medicineCount,
                int allProductsPrice[], int newPrice, string product,
                int Quantity[]) {
  setcolor(10);
  cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "ALL PRODUCTS" << left
       << setw(20) << "PRICES" << left << setw(20) << "QUANTITY" << endl;
  for (int i = 0; i < medicineCount; i++) {
    cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << allMedicines[i] << left
         << setw(20) << allProductsPrice[i] << left << setw(20) << Quantity[i]
         << endl;
  }

  cout << "\t\t\t\t\t\t\t\tEnter the product name: ";
  cin>> product;
  int index = 0;
  for (int i = 0; i < medicineCount; i++) {
    if (product == allMedicines[i]) {
      index = i;
      break;
    }
  }
  cout << "\t\t\t\t\t\t\t\tEnter the new price of product : ";
  cin >> newPrice;
  allProductsPrice[index] = newPrice;

  int quantity;
  cout << "\t\t\t\t\t\t\t\tEnter the quantity of the product: ";
  cin >> quantity;
  Quantity[index] = quantity;
}


///this is to apply taxes for admin...
int applyTaxes(string allMedicines[], int allProductsPrice[], int medicineCount,
               int Quantity[]) {
  setcolor(10);
  cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "ALL PRODUCTS " << left
       << setw(20) << "PRICES" << left << setw(20) << "QUANTITY" << endl;
  for (int i = 0; i < medicineCount; i++) {
    cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << allMedicines[i] << left
         << setw(20) << allProductsPrice[i] << left << setw(20) << Quantity[i]
         << endl;
  }

  int tax;
  cout << "\t\t\t\t\t\t\t\tEnter the percentage of tax: ";
  cin >> tax;

  cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "ALL PRODUCTS " << left
       << setw(20) << "PRICES" << left << setw(20) << "QUANTITY" << endl;
  for (int i = 0; i < medicineCount; i++) {
    allProductsPrice[i] =
        (allProductsPrice[i] + ((allProductsPrice[i]) + tax / 100));

    cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << allMedicines[i] << left
         << setw(20) << allProductsPrice[i] << left << setw(20) << Quantity[i]
         << endl;
  }
  cout << "\t\t\t\t\t\t\t\tPress any key to continue..." << endl;
  getch();
}


void ViewList(string allMedicines[], int allProductsPrice[], int medicineCount,
              int Quantity[]) {
  setcolor(10);
  cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "ALL PRODUCTS" << left
       << setw(20) << "PRICES" << left << setw(20) << "QUANTITY" << endl;
  for (int i = 0; i < medicineCount; i++) {
    cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << allMedicines[i] << left
         << setw(20) << allProductsPrice[i] << left << setw(20) << Quantity[i]
         << endl;
  }
  cout << "\t\t\t\t\t\t\t\tPress any key to continue..." << endl;
  getch();
}


///to take feedback from the user...
string feedback() 
{
  setcolor(10);

    string review;
    cout << "\t\t\t\t\t\t\t\tEnter your Review: ";

    // Clear input buffer
    cin.ignore();

    // Use getline to handle feedback with spaces
    getline(cin, review);
    return review;
}



string setcolor(unsigned short color) {
  HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hcon, color);
  return "";
}


bool check(string option)
{
  for(int i=0;i<option.length();i++)
  {
    if(option[i]>=48 && option[i]<=57)
    {
      return true;
    }
    else{
      return false;
    }
  }
}