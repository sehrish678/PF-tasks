#include <iostream>
#include <windows.h>
#include <conio.h>
#include<iomanip>


using namespace std;

int menu();
void printheader();
void signUpPageHeader();
void signInPageHeader();
void CostumerPage();
void checkFeedBacks(int &count,string feedbackArray[]);
void feedback(string feedbackArray[],int &count);
int applyDiscount(string allMedicines[],int allProductsPrice[],int medicineCount);
int choiceOfAdminPage(int option, string allMedicines[], string added, int &medicineCount, int allProductPrice[], string product, int newPrice,int count,string feedbackArray[]);
string signInPage(string username, string password, string role, string Username[], string Password[], string Role[], int count);
bool signUpCredentials(string username, string password, string role, string Username[], string Password[], string Role[], int &count, int arrSize);
int choiceOfCostumer(string allMedicines[],int allProductsPrice[],int medicineCount,int count,string feedbackArray[]);
void AlterPrice(string allMedicines[],int medicineCount,int allProductsPrice[],int newPrice,string product);
int BuyProduct(int medicineCount,string allMedicines[],int allProductsPrice[]);
int applyTaxes(string allMedicines[],int allProductsPrice[],int medicineCount);
void adminpage();
string table(string allMedicines[], int allProductsPrice[], int &medicineCount);
int PriceAdjustments(string allMedicines[], int allProductsPrice[],int &count, int &medicineCount,int newPrice,string product);
string products(string allMedicines[], int &medicineCount);
string deleteProducts(string allMedicines[], int &medicineCount);
void changePassword(string password,string Password[],int count);

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
     string product;
    int newPrice;

    int medicineCount = 12;
    string allMedicines[size] = {"PANADOL", "CALPOL", "LEFLOX", "LORIN", "BRUFEN", "HYDRLIN", "ACEFYL", "GRAVINAT", "SANIPLAST", "BANDAGES", "MEDICAL TAPES", "MEDICAL SCISSORS"};
    int allProductsPrice[size] = {100, 200, 150, 100, 220, 300, 100, 400, 300, 200, 100, 200};

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
            string feedbackArray[count];

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

                    choiceOfAdminPage(option, allMedicines, added, medicineCount, allProductsPrice, product, newPrice,count,feedbackArray);
                }
                else if (role == "Costumer" || role == "costumer")
                {   
                    cout<<endl;
                   
                    CostumerPage();
                    choiceOfCostumer(allMedicines,allProductsPrice,medicineCount,size,feedbackArray);
                   
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
    
    cout << "\t\t##########################################" << endl;
    cout << "\t\t#                                        #" << endl;
    cout << "\t\t#                                        #" << endl;
    cout << "\t\t#               SIGN IN PAGE             #" << endl;
    cout << "\t\t#                                        #" << endl;
    cout << "\t\t##########################################" << endl;
    cout << endl;
}

void signUpPageHeader()
{
    cout << "\t\t ##########################################" << endl;
    cout << "\t\t #                                        #" << endl;
    cout << "\t\t #                                        #" << endl;
    cout << "\t\t #               SIGN UP PAGE             #" << endl;
    cout << "\t\t #                                        #" << endl;
    cout << "\t\t ##########################################" << endl;
    cout << endl;
}

int menu()
{
   
    cout << "\t\t##########################################" << endl;
    cout << "\t\t#                                        #" << endl;
    cout << "\t\t#                                        #" << endl;
    cout << "\t\t#            1. SIGN UP.                 #" << endl;
    cout << "\t\t#                                        #" << endl;
    cout << "\t\t#                                        #" << endl;
    cout << "\t\t#            2. SIGN IN.                 #" << endl;
    cout << "\t\t#                                        #" << endl;
    cout << "\t\t#                                        #" << endl;
    cout << "\t\t#            3. EXIT.                    #" << endl;
    cout << "\t\t#                                        #" << endl;
    cout << "\t\t#                                        #" << endl;
    cout << "\t\t##########################################" << endl;
    cout << "" << endl;
    int num;
    cout << "ENTER   YOUR   OPTION: ";
    cin >> num;
    return num;
}

void printheader()
{
    system("cls");
    cout<<endl;
    cout << R"(
  ____   _   _  _       _____  _   _  ______    _____            _____   ______ 
 / __ \ | \ | || |     |_   _|| \ | ||  ____|  / ____|    /\    |  __ \ |  ____|
| |  | ||  \| || |       | |  |  \| || |__    | |        /  \   | |_) | |  |_   
| |  | || . ` || |       | |  | . ` ||  __|   | |       / /\ \  |  _  / |  __|  
| |_ | ||  |\ || |___    | |  | |\  || |____  | |____  / ____ \ | | \ \ | |____ 
 \____/ |_| \_||______||_____||_| \_||______|  \_____|/_/    \_\|_|  \_\|______|       )"
         << endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<endl;
cout<<endl;
}

// for admin to choose what to do after signing in..
void adminpage()
{
    cout << endl;
    cout << " 1. ADD PRODUCTS." << endl;
    cout << " 2. DELETE PRODUCTS." << endl;
    cout << " 3. PRICE ADJUSTMENTS." << endl;
    cout << " 4. COSTUMER'S FEEDBACK." << endl;
    cout<<  " 5. APPLY DISCOUNT."<<endl;
    cout<<  " 6. APPLY TAXES."<<endl;
    cout << " 7. LOG OUT." << endl;
}

// for admin to add products in the list...
string products(string allMedicines[], int &medicineCount)
{
    string added;
    cout << "Enter the product you want to add: ";
    cin >> added;
    allMedicines[medicineCount] = added;
    medicineCount++;
    int numOfProducts;
    cout<<"Enter the quantity of the product: ";
    cin>>numOfProducts;
    
    for (int j = 0; j < medicineCount; j++)
    {
        cout << allMedicines[j] << endl;
    }
    cout << endl;
    cout << "Press any key to continue..." ;
    getch();
}

/// for admin to delete products from the list...
string deleteProducts(string allMedicines[], int &medicineCount)
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
{   cout<<"ALL PRODUCTS "<<"\t\t\t\t"<<"PRICE "<<endl;
    for (int i = 0; i < medicineCount; i++)
    {
        cout << i + 1 << "." << allMedicines[i] << "\t\t\t\t" << allProductsPrice[i] << endl;
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
int PriceAdjustments(string allMedicines[], int allProductsPrice[], int &count,int  &medicineCount,int newPrice,string product)
{
    AlterPrice(allMedicines,medicineCount,allProductsPrice,newPrice,product);
    for(int i=0; i<medicineCount; i++)
    {  
       cout<<allMedicines[i] <<"\t\t\t"<<allProductsPrice[i]<<endl;
    //     if(allMedicines[i]==product)
    //    {
    //     cout<<allMedicines[i]<<"\t\t\t" <<newPrice<<endl;
    //    }
    //    if(allMedicines[i]==product)
    //    continue;
    }

    cout<<"Press any key to continue...";
    getch();
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
        else if (option == 2) // for admin to delete products from the list...
        {
            deleteProducts(allMedicines, medicineCount);
        }
        else if (option == 3) // it is for admin to adjust the prices of the products...
        {
            PriceAdjustments(allMedicines, allProductsPrice,count, medicineCount,newPrice,product);
        }
        else if(option==4)
        {  
            checkFeedBacks(count,feedbackArray);
        }
        else if(option==5)
        {
            applyDiscount(allMedicines,allProductsPrice,medicineCount);
        }
        else if(option==6)
        {
           applyTaxes(allMedicines,allProductsPrice,medicineCount);
        }
        else if (option==7) // it is for admin to logout of his/her account..
            return 0;
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
    string Password[count];
    string password;
    int option; 
    cout<<"Enter your choice: ";
    cin>>option;
    
    if(option==1)
    {
       table(allMedicines,allProductsPrice,medicineCount); 
    }
    else if(option==2)
    {
       BuyProduct(medicineCount,allMedicines,allProductsPrice); 
    }
    else if(option==3)
    {
       feedback(feedbackArray,count);
       
    }
    else if(option==4)
    {   
        cout<<      R"(                   If you want more information about our website or you
                    want to check if its registered or not,you can contact 
                    on this number (000-111-777-0). 
                )"<<endl;
    }
    else if(option==5)
    {
       changePassword(password,Password,count); 
    }
    else if(option==6)
    {
        return 0;
    }

}
void CostumerPage()
{

cout<<"1. View products."<<endl; 
cout<<"2. Add to Cart."<<endl;
cout<<"3. Give Feedback."<<endl;
cout<<"4. Contact Information."<<endl;
cout<<"5. Change password."<<endl;
cout<<"6. Logout of account."<<endl;

}

int BuyProduct(int medicineCount,string allMedicines[],int allProductsPrice[])
{
    string productToBuy;
    cout << "Enter the product you want to buy: ";
    cin >> productToBuy;
    int quantity;
    cout<<"Enter the quantity of the product: ";
    cin>>quantity;

    for (int i = 0; i < medicineCount; i++)
    {
        if (allMedicines[i] == productToBuy)
        {   cout<<"The Price of " <<allMedicines[i]<<" is "<<allProductsPrice[i]*quantity<<endl;
            cout<<"Thanks for your purchase.";
            Sleep(1000);
            break;
        }
        
    }
    cout << "Press any key to continue..."<<endl;
    getch();
}

// for costumer to submit feedback..
void feedback(string feedbackArray[],int &count)
{
    string feedback="";
    
    cout << "Enter your Review: ";
    cin >> feedback;
    feedbackArray[count]=feedback;
    count++;
    cout<<"Please wait while your feedback is being submitted...."<<endl;
    Sleep(400);
    cout<<"Your feedback has been submitted."<<endl;
    Sleep(500);
    cout<<"Press any key to continue..."<<endl;
    getch();
}



///for admin to check the reviews by costumer...
void checkFeedBacks(int &count,string feedbackArray[])
{  
     

	for(int i=0;i<count;i++)
	{
        if(feedbackArray[i]!="")
		{
            cout<<i+1<<"\t\t\t"<< feedbackArray[i]<<endl;
        }
        else {
            cout<<"There is no review."<<endl;
        }
	}
cout<<"Press any key to continue..."<<endl;
    getch();
}


int applyDiscount(string allMedicines[],int allProductsPrice[],int medicineCount)
{       cout<<left<<setw(20)<<"ALL PRODUCTS "<<left<<setw(20)<<"PRICES"<<endl;
    for(int i=0;i<medicineCount;i++)
    {
        cout<<left<<setw(20)<<allMedicines[i]<<left<<setw(20)<<allProductsPrice[i]<<endl;
    }

    int discount;
    cout<<"Enter the percentage of discount: ";
    cin>>discount;

        cout<<left<<setw(20)<<"ALL PRODUCTS "<<left<<setw(20)<<"PRICES"<<endl;
    for(int i=0;i<medicineCount;i++)
    {
        
        cout<<left<<setw(20)<<allMedicines[i]<<left<<setw(20)<<(allProductsPrice[i]-((allProductsPrice[i])*discount/100))<<endl; 
    }
    cout<<"Press any key to continue..."<<endl;
    getch();
}

void AlterPrice(string allMedicines[],int medicineCount,int allProductsPrice[],int newPrice,string product)
{
    
    for(int i=0;i< medicineCount;i++)
    {
        cout<<left<<setw(20)<<allMedicines[i]<<left<<setw(20)<<allProductsPrice[i]<<endl;
    }
   
    
    cout<<"Enter the product name: "<<endl;
    cin>>product;
    int index = 0;
    for (int i = 0; i<medicineCount;i++)
    {
        if (product==allMedicines[i])
        {
            index = i;
            break;
        }

    }
    cout<<"Enter the new price of product : ";
    cin>>newPrice;


    allProductsPrice[index]=newPrice;
    // medicineCount++;
    
}

int applyTaxes(string allMedicines[],int allProductsPrice[],int medicineCount)
{
        cout<<left<<setw(20)<<"ALL PRODUCTS "<<left<<setw(20)<<"PRICES"<<endl;
    for(int i=0;i<medicineCount;i++)
    {
        cout<<left<<setw(20)<<allMedicines[i]<<left<<setw(20)<<allProductsPrice[i]<<endl;
    }

    int tax;
    cout<<"Enter the percentage of tax: ";
    cin>>tax;

        cout<<left<<setw(20)<<"ALL PRODUCTS "<<left<<setw(20)<<"PRICES"<<endl;
    for(int i=0;i<medicineCount;i++)
    {
        
        cout<<left<<setw(20)<<allMedicines[i]<<left<<setw(20)<<(allProductsPrice[i]+((allProductsPrice[i])+tax/100))<<endl; 
    }
    cout<<"Press any key to continue..."<<endl;
    getch();
}

void changePassword(string password,string Password[],int count)
{   
    cout<<"Enter the current password: ";
    cin>>password;
    string newPassword;
    cout<<"Enter the newPassword: ";
    cin>>newPassword;

    Password[count]=newPassword;
    count++;
    
    cout<<"Your password has been changed successfully!"<<endl;
    Sleep(1000);

    cout<<"Press any key to continue..."<<endl;
     getch();
}