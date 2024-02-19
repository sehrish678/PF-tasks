#include <conio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <windows.h>

using namespace std;

// header
void printheader();

// login page
string menu(string num);
void signUpPageHeader();
void signInPageHeader();

string signInPage(string username, string password, string role,
                  string Username[], string Password[], string Role[],
                  int count, int &currentIndexUser);
bool signUpCredentials(string username, string password, string role,
                       string Username[], string Password[], string Role[],
                       int &count, int arrSize);

// admin features
void adminPageHeader();
int choiceOfAdminPage(int Quantity[], int &size, int option,
                      string allMedicines[], string added, int &medicineCount,
                      int allProductPrice[], string product, int newPrice,
                      int count, string feedbackArray[], string Password[],
                      string password, int &feedbackiteration, string[], string);
int applyDiscount(string allMedicines[], int allProductsPrice[],
                  int medicineCount, int Quantity[]);
int PriceAdjustments(string allMedicines[], int allProductsPrice[], int &count,
                     int &medicineCount, int newPrice, string product,
                     int Quantity[]);
void adminpage();
void ViewList(string allMedicines[], int allProductsPrice[], int medicineCount,
              int Quantity[]);
void changePassword(string Password[], int count);
string deleteProducts(string allMedicines[], int &medicineCount,
                      int allProductPrice[], int Quantity[]);
void AlterPrice(string allMedicines[], int medicineCount,
                int allProductsPrice[], int newPrice, string product,
                int Quantity[]);
int applyTaxes(string allMedicines[], int allProductsPrice[], int medicineCount,
               int Quantity[]);
string products(string allMedicines[], int &medicineCount, int Quantity[],
                int allProductPrice[]);
void checkFeedbacks(int &feedbackiteration, string feedbackArray[], int count,
                    string[]);

// customer features
void CostumerPage();
void costumerPageHeader();
int choiceOfCostumer(string Password[], int count, int option, int BillCount,
                     string allMedicines[], int allProductsPrice[],
                     int medicineCount, int &size, string feedbackArray[],
                     int Quantity[], string productToBuy,
                     int &feedbackiteration, int currentIndexUser, string File2);
int BuyProduct(string &productToBuy, int &quantity);
string feedback();
int BillCheck(string productToBuy, string allMedicines[],
              int allProductsPrice[], int Quantity[], int quantity,
              int medicineCount);

// set color
string setcolor(unsigned short color);
/// file handling functions
void loadSignIn(string Username[], string Password[], string Role[], int &count,
                string fileName);
void storeSignIn(string Username[], string Password[], string Role[],
                 int &count, string fileName);

void LoadProducts(string allMedicines[], int allProductsPrice[], int Quantity[],int &medicineCount,
                  string File2);
void StoreProducts(string allMedicines[], int allProductsPrice[], int Quantity[],int &medicineCount,
                   string File2);
string Parse(string line, int field1);    

///validations
string isAlpha(string input); 
/// Program starts from here ...
int main() {

  string fileName = "abc.txt";
  string File2 = "xyz.txt";
  string feedbackArray[100];
  int feedbackiteration = 0; // not in use now

  // login data
 
  string num;
  int const arrSize = 100;
  string Username[arrSize];
  string Password[arrSize];
  string Role[arrSize];
  int count = 0;
  int BillCount;
  int currentIndexUser = 0;

  int size = 100;
  string product;
  int newPrice;
  string productToBuy;
  int quantity;

  int medicineCount = 0;
  string allMedicines[size];
  int allProductsPrice[size];
  int Quantity[size];

  int entered, option;
  string added, category;
  int option1;

  // loading sign in data from file
  loadSignIn(Username, Password, Role, count, fileName);
  // loading products from file
  LoadProducts(allMedicines, allProductsPrice, Quantity,medicineCount, File2);    
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
      username=isAlpha(username);
      cout << "\t\t\t\t\t\t\t\t\tENTER YOUR PASSWORD: ";
      password=isAlpha(password);
      cout << "\t\t\t\t\t\t\t\t\tENTER YOUR ROLE: ";
      role=isAlpha(role);

      bool isTrue = signUpCredentials(username, password, role, Username,
                                      Password, Role, count, arrSize);
      if (isTrue) {
        setcolor(2);
        cout << "\t\t\t\t\t\t\t\t\t<<<SIGNED UP SUCCESSFULLY>>>" << endl;
        storeSignIn(Username, Password, Role, count, fileName);
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

      printheader();
      signInPageHeader();
      setcolor(2);
      cout << "\t\t\t\t\t\t\t\t\t ENTER THE USERNAME: ";
      username=isAlpha(username);
      cout << "\t\t\t\t\t\t\t\t\t ENTER YOUR PASSWORD: ";
      password=isAlpha(password);

      role = signInPage(username, password, role, Username, Password, Role,
                        count, currentIndexUser);
     

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
                            count, feedbackArray, Password, password,
                            feedbackiteration, Username, File2);
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
          choiceOfCostumer(Password, count, option, BillCount, allMedicines,
                           allProductsPrice, medicineCount, size, feedbackArray,
                           Quantity, productToBuy, feedbackiteration,
                           currentIndexUser, File2);
        } else if (role == "undefined") {
          setcolor(4);
          cout << "\t\t\t\t\t\t\t\t   You have entered wrong credentials.."
               << endl;
        }
      

    } 
    else if (num == "3") /// to exit...
    {
      // return 0;
      exit(0);
    }

    else {
      setcolor(4);
      cout << "\t\t\t\t\t\t\t\t  Invalid Input.Try again."
           << endl; /// for another input except 1,2,3
    }
    setcolor(14);
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t  Enter 0 to go back or 1 to continue : ";
    cin >> option1;
  }
}
// for signing in...
string signInPage(string username, string password, string role,
                  string Username[], string Password[], string Role[],
                  int count, int &currentIndexUser) {
  for (int i = 0; i < count; i++) {
    if (Username[i] == username && Password[i] == password) {
      currentIndexUser = i;
      return Role[i];
    }
  }
  return "undefined";
}

/// this functions is for signing up...
bool signUpCredentials(string username, string password, string role,
                       string Username[], string Password[], string Role[],
                       int &count, int arrSize) {

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
// for admin to choose what to do after signing in..
void adminpage() {
  setcolor(5);
  cout << "\t\t\t\t\t\t\t\t\t 1. ADD PRODUCTS." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 2. DELETE PRODUCTS." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 3. PRICE ADJUSTMENTS." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 4. COSTUMER'S FEEDBACK." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 5. APPLY DISCOUNT." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 6. APPLY TAXES." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 7. CHANGE PASSWORD." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 8. VIEW LIST." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 9. LOG OUT." << endl;
}

/// adminpage options...
int choiceOfAdminPage(int Quantity[], int &size, int option,
                      string allMedicines[], string added, int &medicineCount,
                      int allProductsPrice[], string product, int newPrice,
                      int count, string feedbackArray[], string Password[],
                      string password, int &feedbackiteration,
                      string Username[], string File2) {

  // LoadProducts(allMedicines, allProductsPrice, Quantity,medicineCount, File2);
  while (option != 9) {
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
    } else if (option == 2) // for admin to delete products from the list...
    {
      system("cls");
      printheader();
      adminPageHeader();
      ViewList(allMedicines, allProductsPrice, medicineCount, Quantity);
      cout << endl;
      deleteProducts(allMedicines, medicineCount, allProductsPrice, Quantity);
    } else if (option ==
               3) // it is for admin to adjust the prices of the products...
    {
      system("cls");
      printheader();
      adminPageHeader(); /// for admin to adjust the price and quantity of
                         /// products...
      PriceAdjustments(allMedicines, allProductsPrice, count, medicineCount,
                       newPrice, product, Quantity);
    } else if (option == 4) {
      system("cls");
      printheader();
      adminPageHeader(); /// it is for adimin to check the feedbacks entered by
                         /// the customer...
      checkFeedbacks(feedbackiteration, feedbackArray, count, Username);
    } else if (option == 5) {
      system("cls");
      printheader();
      adminPageHeader(); /// for admin to apply discount on alll products..
      applyDiscount(allMedicines, allProductsPrice, medicineCount, Quantity);
    } else if (option == 6) {
      system("cls");
      printheader();
      adminPageHeader(); /// for admin to apply taxes on all products.
      applyTaxes(allMedicines, allProductsPrice, medicineCount, Quantity);
    } else if (option == 7) {
      system("cls");
      printheader();
      adminPageHeader(); /// for admin to cahnge password...
      changePassword(Password, count);
    } else if (option == 8) {
      system("cls");
      printheader();
      adminPageHeader(); /// to view list..
      ViewList(allMedicines, allProductsPrice, medicineCount, Quantity);
    }
    StoreProducts(allMedicines, allProductsPrice, Quantity,medicineCount, File2);
  }
  cout << "\t\t\t\t\t\t\t\tPress any key to continue..." << endl;
  getch();
}

// for admin to add products in the list...
string products(string allMedicines[], int &medicineCount, int Quantity[],
                int allProductPrice[]) {
  setcolor(10);
  string added;
  cout << "\t\t\t\t\t\t\t\tEnter the product you want to add: ";
  added=isAlpha(added);
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

// to adjust the prices and quantity of products....
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

/// this function is called in price adjustments function ...
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
  product=isAlpha(product);
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

/// this function is for admin to check the feedbacks...
void checkFeedbacks(int &feedbackiteration, string feedbackArray[],
                    int userCount, string UserName[]) {
                      setcolor(2);
  cout <<"\t\t\t\t\t\t\t\t "<<left<<setw(20)<< "Name \t\t Feedback" << endl;
  cout<<endl;
  for (int i = 0; i < userCount; i++) {
    if (feedbackArray[i] != "")
      cout <<"\t\t\t\t\t\t\t\t "<<left<<setw(20) <<UserName[i] << "\t\t " << feedbackArray[i] << endl;
  }
  cout << "\t\t\t\t\t\t\t\t Press any key to continue..." << endl;
  getch();
}

/// this is to apply discounts...(for admin)
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

/// to apply taxes by admin...
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

/// to change password and is for both..
void changePassword(string Password[], int count) {
  setcolor(10);
  string currentPassword;
  cout << "\t\t\t\t\t\t\t\tEnter the current password: ";
  currentPassword=isAlpha(currentPassword);

  int index = 0;
  for (int i = 0; i < count; i++) {
    if (currentPassword == Password[i]) {
      index = i;
      break;
    }
  }
  string newPassword;
  cout << "\t\t\t\t\t\t\t\tEnter the new password: ";
  newPassword=isAlpha(newPassword);
  Password[index] = newPassword;

  cout << "\t\t\t\t\t\t\t\tYour password has been changed successfully!"
       << endl;
  Sleep(1000);
}
/// just  to view list..
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

// customer data

/// choice of customer
void CostumerPage() {
  setcolor(5);
  cout << "\t\t\t\t\t\t\t\t\t 1. View products." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 2. Add to Cart." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 3. Give Feedback." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 4. Contact Information." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 5. Change password." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 6. Logout of account." << endl;
  cout << "\t\t\t\t\t\t\t\t\t 7. Check Bill." << endl;
}

int choiceOfCostumer(string Password[], int count, int option, int BillCount,
                     string allMedicines[], int allProductsPrice[],
                     int medicineCount, int &size, string feedbackArray[],
                     int Quantity[], string productToBuy,
                     int &feedbackiteration, int currentIndexUser, string File2) {
  int quantity = 0;
  // LoadProducts(allMedicines, allProductsPrice, Quantity,medicineCount, File2);
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
      BuyProduct(productToBuy, quantity);
    } else if (option == 3) {
      system("cls");
      printheader();
      costumerPageHeader();
      feedbackArray[currentIndexUser] = feedback();

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
    } else if (option == 7) {
      system("cls");
      printheader();
      costumerPageHeader();
      BillCheck(productToBuy, allMedicines, allProductsPrice, Quantity,
                quantity, medicineCount);
    }
    StoreProducts(allMedicines, allProductsPrice, Quantity,medicineCount, File2);
  }
  cout << "\t\t\t\t\t\t\t\tPress any key to continue..." << endl;
  getch();
}

/// for customer to buy products...
int BuyProduct(string &productToBuy, int &quantity) {
  setcolor(10);

  cout << "\t\t\t\t\t\t\t\tEnter the product you want to buy: ";
  productToBuy=isAlpha(productToBuy);

  cout << "\t\t\t\t\t\t\t\tEnter the quantity of the product: ";
  cin >> quantity;

  cout << "\t\t\t\t\t\t\t\tPress any key to continue..." << endl;
  getch();
  return 0;
}

/// to check bill of the customer...
int BillCheck(string productToBuy, string allMedicines[],
              int allProductsPrice[], int Quantity[], int quantity,
              int medicineCount) {
  setcolor(2);
  for (int i = 0; i < medicineCount; i++) {
    if (allMedicines[i] == productToBuy) {
      Quantity[i] = Quantity[i] - quantity;
      cout << "\t\t\t\t\t\t\t\t The Price of " << productToBuy << " is "
           << allProductsPrice[i] * quantity << endl;
      cout << "\t\t\t\t\t\t\t\t Thanks for your purchase." << endl;
      Sleep(1000);
      break;
    }
  }

  cout << "\t\t\t\t\t\t\t\t Press any key to continue..." << endl;
  getch();
}

string feedback() {
  setcolor(10);

  string comment;
  cout << "\t\t\t\t\t\t\t\tEnter your Review: ";

  // Clear input buffer
  cin.ignore();

  // Use getline to handle feedback with spaces
  getline(cin, comment);
  return comment;
  setcolor(15);
  cout << "\t\t\t\t\t\t\t\tPlease wait while your feedback is being "
          "submitted...."
       << endl;
  Sleep(400);
  cout << "\t\t\t\t\t\t\t\tYour feedback has been submitted." << endl;

  cout << "\t\t\t\t\t\t\t\tPress any key to continue..." << endl;
  getch();
}

// set color
string setcolor(unsigned short color) {
  HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hcon, color);
  return "";
}

// header
void printheader() {
  system("cls");
  cout << endl;
  setcolor(1);
  cout << R"(
                                              ____   _   _  _       _____  _   _  ______    _____            _____   ______ 
                                             / __ \ | \ | || |     |_   _|| \ | ||  ____|  / ____|    /\    |  __ \ |  ____|
                                            | |  | ||  \| || |       | |  |  \| || |__    | |        /  \   | |) | |  |   
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

string ViewList(string allMedicines[], string allProductsPrice[],
                int medicineCount) {
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

/// it is used to store data...
void storeSignIn(string Username[], string Password[], string Role[],
                 int &count, string fileName) {
  fstream file;
  file.open("abc.txt", ios::out);
  for (int i = 0; i < count; i++) {
    file << Username[i] << "," << Password[i] << "," << Role[i];
    if (i != count - 1)
      file << endl;       // not last iteration so store new line
  }
  file.close();
}

/// it is used to read data..
void loadSignIn(string Username[], string Password[], string Role[], int &count,
                string fileName) {
  string record = "";
  fstream data;
  data.open("abc.txt", ios::in);
  // if (!data.is_open()) {
  //   data.open("abc.txt", ios::out);
  //   data.close();
  //   data.open("abc.txt", ios::in);
  // }
  if (data.fail())
    return;           // file not openning returning
  while (!(data.eof())) {
    getline(data, record);
    Username[count] = Parse(record, 1);
    Password[count] = Parse(record, 2);
    Role[count] = Parse(record, 3);

    count++;
  }
  data.close();
}
void StoreProducts(string allMedicines[], int allProductsPrice[], int Quantity[],int &medicineCount,
                   string File2) {
  fstream file;
  file.open("xyz.txt", ios::out);
  for (int i = 0; i < medicineCount; i++) {
    file << allMedicines[i] << "," << allProductsPrice[i] << "," << Quantity[i];
    if (i != medicineCount - 1)  // if not last iteration so store new line
      file << endl;
  }
  file.close();
}


///this function is for storing products in files 
void LoadProducts(string allMedicines[], int allProductsPrice[], int Quantity[],int &medicineCount,
                  string File2) {
  string line;
  fstream data;
  data.open("xyz.txt", ios::in);
  
  if (data.fail())
    return;
  while (!(data.eof())) {
    getline(data, line);
    allMedicines[medicineCount] = Parse(line, 1);
    allProductsPrice[medicineCount] = stoi(Parse(line, 2));
    Quantity[medicineCount] = stoi(Parse(line, 3));

    medicineCount++;
  }
}

string Parse(string line, int field1) {
  int commaCount = 1;
  string product = "";
  for (int x = 0; x < line.length(); x++) {
    if (line[x] == ',') 
    {
      commaCount = commaCount + 1;
    } else if (commaCount == field1)
    {
      product = product + line[x];
    }
  }
  return product;
}


string isAlpha(string input) // name validation
{

    cin.clear();
    cin.sync();
    getline(cin >> ws, input);
    int size;
    int check;
    bool flag;
    while (true)
    {
        size = input.length();
        for (int i = 0; i < size; i++)
        {
            check = int(input[i]);
            if (((check >= 65 && check <= 90) || (check >= 97 && check <= 122) || input[i] == ' ') && input[i] != ',')
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            return input;
        }
        else
        {
            cin.clear();
            cin.sync();
            cout << "\t\t\t\t\t\t\tWrong input..." << endl;
            cout << "\t\t\t\t\t\t\tEnter Again: ";
            getline(cin >> ws, input);
       }
     }
}