n#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int menu();
void printheader();
void signUpPageHeader();
void signInPageHeader();
void CostumerPage();

int choiceOfAdminPage(int option, string allMedicines[], string added, int &medicineCount, int allProductPrice[], string product, int newPrice,int size,string feedbackArray[]);
string signInPage(string username, string password, string role, string Username[], string Password[], string Role[], int count);
bool signUpCredentials(string username, string password, string role, string Username[], string Password[], string Role[], int &count, int arrSize);
int choiceOfCostumer(string allMedicines[],int allProductsPrice[],int medicineCount,int count,string feedbackArray[]);
int applyDiscount(string allMedicines[],int allProductsPrice[],int medicineCount);
int BuyProduct(int medicineCount,string allMedicines[],int allProductsPrice[]);
void adminpage();
void feedback(string feedbackArray[],int &count);
void checkFeedBacks(int &count,string feedbackArray[]);
string table(string allMedicines[], int allProductsPrice[], int &medicineCount);
int PriceAdjustments(string allMedicines[], int allProductsPrice[], int &medicineCount);
string products(string allMedicines[], int &medicineCount);
string deleteProducts(string allMedicines[], int medicineCount); 

int main()
{
    int num;
    int const arrSize = 100;
    string Username[arrSize];
    string Password[arrSize];
    string Role[arrSize];
    int count = 0;
    
    int size=100;
    char feedback[size];

    int medicineCount = 12;
    string allMedicines[medicineCount] = {"PANADOL", "CALPOL", "LEFLOX", "LORIN", "BRUFEN", "HYDRLIN", "ACEFYL", "GRAVINAT", "SANIPLAST", "BANDAGES", "MEDICAL TAPES", "MEDICAL SCISSORS"};
    int allProductsPrice[medicineCount] = {100, 200, 150, 100, 220, 300, 100, 400, 300, 200, 100, 200};
    string feedbackArray[count];
    int entered, option;
    string added, category;
    int option1;


    while (num != 3)
    {
        printheader();
        num = menu();
        if (num == 1) // for signing up...
        {

            system("cls");
            string username, password, role;

            printheader();
            signUpPageHeader();

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
                cout << "<<<NOT SIGNED UP SUCCESSFULLY>>>"<<endl;
            }
        }
        else if (num == 2) // for signing in..
        {
            string username;
            string password;
            string role;
            string product;
            int newPrice;

            printheader();
            signInPageHeader();

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

                    choiceOfAdminPage(option, allMedicines, added, medicineCount, allProductsPrice, product, newPrice,size,feedbackArray);
                }
                else if (role == "Costumer" || role == "costumer")
                {   CostumerPage();
                    choiceOfCostumer(allMedicines,allProductsPrice,medicineCount,count,feedbackArray);
                }
                else if (role == "undefined")
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
    cout << endl;
    cout << endl;
    cout << "##########################################                                        " << endl;
    cout << "#                                        #                                        " << endl;
    cout << "#                                        #                                        " << endl;
    cout << "#               SIGN IN PAGE             #                                        " << endl;
    cout << "#                                        #                                        " << endl;
    cout << "##########################################                                        " << endl;
    cout << endl;
}

void signUpPageHeader()
{
    cout << endl;
    cout << endl;
    cout << " ##########################################" << endl;
    cout << " #                                        #" << endl;
    cout << " #                                        #" << endl;
    cout << " #               SIGN UP PAGE             #" << endl;
    cout << " #                                        #" << endl;
    cout << " ##########################################" << endl;
    cout << endl;
}

int menu()
{
    cout << endl;
    cout << endl;
    cout << "##########################################                                     " << endl;
    cout << "#                                        #                                     " << endl;
    cout << "#                                        #                                     " << endl;
    cout << "#            1. SIGN UP.                 #                                     " << endl;
    cout << "#                                        #                                     " << endl;
    cout << "#                                        #                                     " << endl;
    cout << "#            2. SIGN IN.                 #                                     " << endl;
    cout << "#                                        #                                     " << endl;
    cout << "#                                        #                                     " << endl;
    cout << "#            3. EXIT.                    #                                     " << endl;
    cout << "#                                        #                                     " << endl;
    cout << "#                                        #                                     " << endl;
    cout << "##########################################                                     " << endl;
    cout << "" << endl;
    int num;
    cout << "ENTER   YOUR   OPTION: ";
    cin >> num;
    return num;
}

void printheader()
{
    system("cls");
    cout << R"(
      ____   _   _  _       _____  _   _  ______    _____            _____   ______ 
     / __ \ | \ | || |     |_   _|| \ | ||  ____|  / ____|    /\    |  __ \ |  ____|
    | |  | ||  \| || |       | |  |  \| || |__    | |        /  \   | |__) || |__   
    | |  | || . ` || |       | |  | . ` ||  __|   | |       / /\ \  |  _  / |  __|  
    | |__| || |\  || |____  _| |_ | |\  || |____  | |____  / ____ \ | | \ \ | |____ 
     \____/ |_| \_||______||_____||_| \_||______|  \_____|/_/    \_\|_|  \_\|______|         )"
         << endl;
}

// for admin to choose what to do after signing in..
void adminpage()
{
    cout << endl;
    cout << " 1. ADD PRODUCTS." << endl;
    cout << " 2. DELETE PRODUCTS." << endl;
    cout << " 3. PRICE ADJUSTMENTS." << endl;
    cout << " 4. COSTUMER'S FEEDBACK." << endl;
    cout << " 5. LOG OUT." << endl;
}

// for admin to add products in the list...
string products(string allMedicines[], int &medicineCount)
{
    string added;
    cout << "Enter the product you want to add: " << endl;
    cin >> added;
    allMedicines[medicineCount] = added;
    medicineCount++;

    for (int j = 0; j < medicineCount; j++)
    {
        cout << allMedicines[j] << endl;
    }
    cout << endl;
    cout << "Press any key to continue..." ;
    getch();
}

/// for admin to delete products from the list...
string deleteProducts(string allMedicines[], int medicineCount)
{
    string deletedProduct;
    cout << "Enter the product you want to delete: ";
    cin >> deletedProduct;

    for (int i = 0; i < medicineCount; i++)
    {
        if (allMedicines[i] == deletedProduct)
        {
            continue;
        }
        cout << allMedicines[i] << endl;
    }
    cout << "Press any key to continue...";
    getch();
}

// table of products..to show the costumer the available products...
string table(string allMedicines[], int allProductsPrice[], int &medicineCount)
{
    for (int i = 0; i < medicineCount; i++)
    {
        cout << i + 1 << "." << allMedicines[i] << "\t" << allProductsPrice[i] << endl;
    }

}


// for signing in...
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

// to adjust the prices of products....
int PriceAdjustments(string allMedicines[], int allProductsPrice[], int &medicineCount)
{

    for(int i=0;i< medicineCount;i++)
    {
        cout<<allMedicines[i]<<"\t"<<allProductsPrice[i]<<endl;
    }
    string product;
    int newPrice;
    cout<<"Enter the new price of product : ";
    cin>>newPrice;

    cout<<"Enter the product name: "<<endl;
    getline(cin,product);

    allProductsPrice[medicineCount]=newPrice;
    medicineCount++;

    allMedicines[medicineCount]=product;
    medicineCount++;
 


    for(int i=0; i<medicineCount; i++)
    {  
        if(allMedicines[i]==product)
       {
        cout<<allMedicines[i]<<"\t" <<newPrice<<endl;
       }
       if(allMedicines[i]==product)
       continue;
       cout<<allMedicines[i] <<"\t"<<allProductsPrice[i]<<endl;
    }

    
}


/// adminpage options...
int choiceOfAdminPage(int option, string allMedicines[], string added, int &medicineCount, int allProductsPrice[], string product, int newPrice,int count,string feedbackArray[])
{
    while (option != 5)
    {
        system("cls");
        printheader();
        adminpage();
        
        cout << "Enter any option: ";
        cin >> option;
        if (option == 1) // for admin to add products in the list...
        {
            products(allMedicines, medicineCount);
        }
        if (option == 2) // for admin to delete products from the list...
        {
            deleteProducts(allMedicines, medicineCount);
        }
        if (option == 3) // it is for admin to adjust the prices of the products...
        {
            PriceAdjustments(allMedicines, allProductsPrice, medicineCount);
        }
        if(option==4)
        {  
            feedback(feedbackArray,count);
        }

        if (option ==5 ) // it is for admin to logout of his/her account..
            return 0;
    }
    if(option==6)
    {
        applyDiscount(allMedicines,allProductsPrice,medicineCount);
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


string ViewList(string allMedicines[],string allProductsPrice[],int medicineCount)
{
    for(int i=0;i<medicineCount;i++)
    {
        cout<<allMedicines[i]<<"\t\t\t"<<allProductsPrice[i]<<endl;
    }
    return 0;
}

int choiceOfCostumer(string allMedicines[],int allProductsPrice[],int medicineCount,int count,string feedbackArray[])
{
    int option; 
    cout<<"Enter your choice: ";
    cin>>option;
    if(option==1)
    {
       table(allMedicines,allProductsPrice,medicineCount); 
    }
    if(option==2)
    {
       BuyProduct(medicineCount,allMedicines,allProductsPrice); 
    }
    if(option==3)
    {
       feedback(feedbackArray,count);
    }

}
void CostumerPage()
{
cout<<"1.View products."<<endl; 
cout<<"2.Add to Cart."<<endl;
cout<<"3.Give Feedback."<<endl;
cout<<"4.See Contact Information."<<endl;
cout<<"5.Logout of account."<<endl;

}

int BuyProduct(int medicineCount,string allMedicines[],int allProductsPrice[])
{
    string productToBuy;
    cout << "Enter the product you want to buy: ";
    cin >> productToBuy;

    for (int i = 0; i < medicineCount; i++)
    {
        if (allMedicines[i] == productToBuy)
        {   cout<<"The Price of " <<allMedicines[i]<<" is "<<allProductsPrice[i]<<endl;
            break;
        }
        
    }
    cout << "Press any key to continue...";
    getch();
}

