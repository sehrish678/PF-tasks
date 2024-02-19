#include <iostream>
#include <windows.h>
using namespace std;
void menu(int num);
void printheader();
int validcredentials(string username, string password, string role, string Username[], string Password[], string Role[], int count);
string AID(string added);
void adminpage();
string Syrup(string added);
string addproducts(string added, string category);
string medicines(string added);
string table();
main()
{
   int num;
   const int arrsize = 100;
   string Username[arrsize];
   string Password[arrsize];
   string Role[arrsize];
   int entered;
   int count = 0;
   string added, category;
   
  
   while (num!=3)
   {   printheader();
        menu(num);
      if (num == 1) // for signing up..
      {  
         string username;
         string password;
         string role;
         system("cls");
         printheader();
       
         cout << "                               ##########################################                                        " << endl;
         cout << "                               #                                        #                                        " << endl;
         cout << "                               #                                        #                                        " << endl;
         cout << "                               #               SIGN UP PAGE             #                                        " << endl;
         cout << "                               #                                        #                                        " << endl;
         cout << "                               ##########################################                                        " << endl;
         cout << endl;
         cout << "ENTER THE USERNAME: ";
         cin >> username;
         cout << "ENTER YOUR PASSWORD: ";
         cin >> password;
         cout << "ENTER YOUR ROLE: ";
         cin >> role;
         Username[count] = username;
         Password[count] = password;
         Role[count] = role;
         count++;
         if (Username[count] == Username[count - 1] && Password[count] == Password[count - 1])
         {
            cout << "INVALID CREDENTIALS.";
         }

         cout << "<<<SIGNED UP SUCCESSFULLY>>>" << endl;
         cout << endl;
      }

      else if (num == 2) // for signing in..
      {
         string username;
         string password;
         string role;
         system("cls");
         printheader();

         cout << "                               ##########################################                                        " << endl;
         cout << "                               #                                        #                                        " << endl;
         cout << "                               #                                        #                                        " << endl;
         cout << "                               #               SIGN IN PAGE             #                                        " << endl;
         cout << "                               #                                        #                                        " << endl;
         cout << "                               ##########################################                                        " << endl;
         cout << endl;
         cout << "ENTER THE USERNAME: ";
         cin >> username;
         cout << "ENTER YOUR PASSWORD: ";
         cin >> password;
         cout << "ENTER YOUR ROLE: ";
         cin >> role;
         bool istrue = validcredentials(username, password, role, Username, Password, Role, count);
         if (istrue == true)
         {
            cout << "<<<SIGNED IN SUCCESSFULLY>>>" << endl;
         }
         if (role == "Admin" || role == "admin")
         {
            system("cls");
            printheader();
            adminpage();
            int option;
            cout << "Enter any option: ";
            cin >> option;
            if (option == 1)
            {
               addproducts(added, category);
            }
         }
         else if (role == "Costumer" || role == "costumer")
         {
            system("cls");
            printheader();
            table();
         }
         else
         {
            cout << "You have entered wrong credentials." << endl;
         }
      }
      else if (num == 3) // to exit..
      {
         system("cls");
         printheader();
         menu(num);
      }
   }
}
void menu(int num)
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
   cout << "ENTER   YOUR   OPTION: ";
   cin >> num;
}
void printheader()
{
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

int validcredentials(string username, string password, string role, string Username[], string Password[], string Role[], int count)
{
   for (int i = 0; i < count; i++)
   {
      if (Username[i] == username && Password[i] == password)
      {
         cout << "                                  VALID CREDENTIALS.                                                         " << endl;
      }
      else
      {
         cout << "                                  INVALID CREDENTIALS.                                                        " << endl;
      }
   }
   return 0;
}

void adminpage()
{
   cout << " \t\t\t                      1. ADD PRODUCTS." << endl;
   cout << " \t\t\t                      2. DELETE PRODUCTS." << endl;
   cout << " \t\t\t                      3. PRICE ADJUSTMENTS." << endl;
   cout << " \t\t\t                      4. COSTUMER'S FEEDBACK." << endl;
   cout << " \t\t\t                      5. UPDATE PRODUCT INFORMATION." << endl;
}
string addproducts(string added, string category)
{
   Syrup(added);
   medicines(added);
   AID(added);

   cout << "Enter the product you want to add: " << endl;
   cin >> added;
   cout << "Enter the category of the product (FirstAid, Medicine, Syrup): " << endl;
   cin >> category;
   if (category == "FirstAid")
   {
      AID(added);
   }
   if (category == "Medicine")
   {
      medicines(added);
   }
   if (category == "Syrup")
   {
      Syrup(added);
   }
}
string medicines(string added)
{
   string medicines[4] = {"PANADOL", "CALPOL", "LEFLOX", "LORIN"};
   cout << added << endl;
   for (int i = 0; i < 4; i++)
   {
      cout << medicines[i] << endl;
   }
   cout << endl;
}
string Syrup(string added)
{
   string syrups[4] = {"BRUFEN", "HYDRLIN", "ACEFYL", "GRAVINAT"};
   cout << added << endl;
   for (int j = 0; j < 4; j++)
   {
      cout << syrups[j] << endl;
   }
   cout << endl;
}
string AID(string added)
{
   string firstaids[4] = {"SANIPLAST", "BANDAGES", "MEDICAL TAPES", "MEDICAL SCISSORS"};
   cout << added << endl;
   for (int k = 0; k < 4; k++)
   {
      cout << firstaids[k] << endl;
   }
}
string table()
{
   cout << "    (MEDICINES)           (SYRUPS)            (FIRST AIDS) " << endl;
   cout << "     PANADOL               BRUFEN              SANIPLAST " << endl;
   cout << "     CALPOL                HYDRLIN             BANDAGES  " << endl;
   cout << "     LEFLOX                ACEFYL              MEDICAL TAPE" << endl;
   cout << "     LORIN                 GRAVINAT            MEDICAL SCISSORS" << endl;
   cout << endl;
}
