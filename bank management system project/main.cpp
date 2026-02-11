#include <bits\stdc++.h>
#include<conio.h>
#include<Windows.h>

using namespace std;

 class bank{
 private:
    string pin;
    string id,pass,name,fname,address,phone;
    float balance;


 public:
     void menu();
     void bank_management();
     void atm_management();
     void new_user();
     void already_user();
     void deposit();
     void withdraw();
     void transfer();
     void payment();
     void search_user();
     void edit();
     void del();
     void show_records();
     void show_payments();
     void user_balance();
     void with_atm();
     void check_account();

 };
 void bank::menu()
 {

   p:
     system("cls");
     int choice;
     char ch;
     string pin,pass,email;
     cout<<"\n\n\t\t control panel"<<endl;
     cout<<"\n 1. Bank Management"<<endl;
     cout<<"\n 2. ATM Management"<<endl;
     cout<<"\n 3. Exit"<<endl;
     cout<<"enter your choice :";
     cin>>choice;

     switch(choice)
     {
     case 1:

             system("cls");
         cout<<"\n\n\t\t\tLogin Account";
         cout<<"\n\t E-mail: ";
         cin>>email;
         cout<<"\n\n\t Pin Code(enter 5-digit number) : ";
         for(int i=1;i<=5;i++)
         {
             ch=_getch();
             pin+=ch;
             cout<<"*";
         }

         if(email== "ashokpen2004@gmail.com"&&pin=="20449")
        {
         bank_management();
        }else
        {cout<<"\n\n\t\t\a==>entered details are wrong!<==\n\n\tpress any key to navigate to control panel";}
         break;
     case 2:
        atm_management();
        break;
     case 3:
        exit(0);
      default: cout<<"\n\nInvalid choice!!.....Please try again"<<endl;

     } _getch();
      goto p;
 }
 void bank::bank_management()
 {
     p:
            system("cls");
            int choice;
            cout<<"\n\n\n\t\t Bank MANAGEMENT STSTEM";
            cout<<"\n\n 1. New user";
            cout<<"\n\n 2. Already user";
            cout<<"\n\n 3. Deposit option";
            cout<<"\n\n 4. Withdraw option";
            cout<<"\n\n 5. Transfer option";
            cout<<"\n\n 6. Payment option";
            cout<<"\n\n 7. Search user ";
            cout<<"\n\n 8. Edit user ";
            cout<<"\n\n 9. Delete user ";
            cout<<"\n\n10. Show all records ";
            cout<<"\n\n11. Payment all records";
            cout<<"\n\n12. Go back";

            cout<<" \n enter your choice:";
            if (!(cin >> choice))
           {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
            cout << "\n\nInvalid input! Please enter numbers only.";
            _getch();
            goto p;
          }

            switch(choice)
            {
            case 1:
                new_user();
                break;
            case 2:
                already_user();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                transfer();
                break;
            case 6:
                payment();
                break;
            case 7:
                search_user();
                break;
            case 8:
                edit();
                break;
            case 9:
                del();
                break;
            case 10:
                show_records();
                break;
            case 11:
                show_payments();

                break;

            case 12:
                menu();
            default: cout<<"\n\nInvalid choice!!.....Please try again"<<endl;

            }
            _getch();
            goto p;

 }
 void bank::atm_management()
 {
         p:
            system("cls");
            int choice;
            cout<<"\n\n\n\t\t ATM MANAGEMENT STSTEM";
            cout<<"\n\n 1. User Login & Check balance";
            cout<<"\n\n 2. Withdraw amount";
            cout<<"\n\n 3. Account Details";
            cout<<"\n\n 4. Go Back";
            cout<<" \n enter your choice:";
            if (!(cin >> choice))
            {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
            cout << "\n\nInvalid input! Please enter numbers only.";
            _getch();
            goto p;
           }

            switch(choice)
            {
            case 1:
                user_balance();
                break;
            case 2:
                with_atm();
                break;
            case 3:
                check_account();
                break;
            case 4:
                menu();
            default: {
                cout<<"\n\nInvalid choice!!.....Press enter to try again"<<endl;
                cin.ignore();
                cin.get();
            }

}

            goto p;



 }
 void bank::new_user()
 {
  p:
     system("cls");
     fstream file;
     string p;
     float b;
     string n,f,pa,a,ph,i;
     cout << "add new user";

bool idExists;
int idChoice;

do
{
    idExists = false;

    cout << "\n\n User ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    file.open("bank.txt", ios::in);
    if (file)
    {
        file >> i >> n >> f >> a >> p >> pa >> ph >> b;
        while (!file.eof())
        {
            if (i == id)
            {
                idExists = true;
                break;
            }
            file >> i >> n >> f >> a >> p >> pa >> ph >> b;
        }
        file.close();
    }

   if (idExists)
{
    cout << "\n\n \a User ID already exists!";

    while (true)
    {
        cout << "\n Enter 1 to try again";
        cout << "\n Enter 0 to go back";
        cout << "\n Choice: ";
        cin >> idChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (idChoice == 1)
        {
            break;   // retry entering user ID
        }
        else if (idChoice == 0)
        {
            menu();
            return;
        }
        else

            cout << "\n  Invalid choice! Please enter 1 or 0.\n";
        }
    }
} while (idExists);




      cout<<"\n\n  name: ";
     getline(cin,name);
      cout<<"\n\n Father name: ";
     getline(cin,fname);
      cout<<"\n\n Address: ";
     getline(cin,address);
      int choice;
bool showError = true;

while (true)
{
    cout << "\n\n Pin code (5 digits): ";
    getline(cin, pin);

    cout << "\n\n Password (5 digits): ";
    getline(cin, pass);

    bool validPin  = (pin.length() == 5) &&
                     all_of(pin.begin(), pin.end(), ::isdigit);

    bool validPass = (pass.length() == 5) &&
                     all_of(pass.begin(), pass.end(), ::isdigit);

    if (validPin && validPass)
    {
        break;  // correct input → continue program
    }

    if (showError)
    {
        cout << "\n\n  Invalid input!";
        cout << "\n Password and PIN must be exactly 5 digits";
        cout << "\n and contain numbers only.\n";
        showError = false;
    }

    cout << "\n Enter 1 to try again";
    cout << "\n Enter 0 to go back";
    cout << "\n Choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 0)
    {
        menu();
        return;
    }
    // if choice == 1 → loop continues
}


    cout << "\n\n Phone No (10 digits): ";
    phone = "";
    char ch;

while (true)
{
    ch = _getch();

    // Accept digits
    if (ch >= '0' && ch <= '9' && phone.length() < 10)
    {
        phone += ch;
        cout << ch;
    }
    // Backspace handling
    else if (ch == 8 && !phone.empty())
    {
        phone.pop_back();
        cout << "\b \b";
    }
    // ENTER key → confirm only if exactly 10 digits
    else if (ch == 13)   // Enter key
    {
        if (phone.length() == 10)
            break;   // accept phone number
        else
        {
            // optional beep or message
            Beep(750, 100);
        }
    }
}

     cout<<"\n\n Current balance: ";
     cin>>balance;

     file.open("bank.txt",ios::in);
     if(!file)
     {
         file.open("bank.txt",ios::app|ios::out);
         file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
         file.close();
     }
     else
     {
         file>>i>>n>>f>>a>>p>>pa>>ph>>b;
         while(!file.eof())
         {
             if(i==id)
             {
                 cout<<"user id already exists...";
                 _getch();
                 goto p;
             }
             file>>i>>n>>f>>a>>p>>pa>>ph>>b;

         }
          file.close();
          file.open("bank.txt",ios::app|ios::out);
          file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
          file.close();

     }
      cout<<"new user account created successfully"<<endl;
 }
 void bank::already_user()
 {
     system("cls");
     fstream file;
     string t_id;
     int found=0;
     cout<<"\n\n\t\t\t already user account";
     file.open("bank.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n file opening error...";
     }
     else
     {
         cout<<"\n\n user id :";
         cin>>t_id;
         file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         while(!file.eof())
         {
             if(t_id==id)
             {
                 system("cls");
                 cout<<"\n\n\t\t already user account exist";
                 cout<<"\n\n user id: "<<id<<"   pin code: "<<pin<<"  password: "<<pass<<"   balance: "<<balance;
                 found++;
             }
             file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         }
         file.close();
         if(found==0)
         cout<<"user id can't found....";


     }
 }
 void bank::deposit()
 {
     fstream file,file1;
     string t_id;
     float dep;
     int found=0;
     system("cls");
     cout<<"\n\n\t\t\t Deposit amount option";
     file.open("bank.txt",ios::in);
     if(!file)
     {
         cout<<"\n\nfile opening error...";
     }
     else
     {
          cout<<"\n\n user id :";
         cin>>t_id;
         file1.open("bank1.txt",ios::app|ios::out);
         file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         while(!file.eof())
         {
             if(t_id==id)
             {
                 cout<<"\n\n\n Amount for deposit: ";
                 cin>>dep;
                 balance +=dep;
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";

                 found++;
                 cout<<"\n\n\n\t\t your amount "<<dep<<"successfully deposited";
             }
             else
             {
                  file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
             }
             file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         }
         file.close();
         file1.close();
         remove("bank.txt");
         rename("bank1.txt","bank.txt");

         if(found==0)
         cout<<"user id can't found....";

     }
 }


 void bank::withdraw()
 {
     fstream file,file1;
     string t_id;
     float with;
     int found=0;
     system("cls");
     cout<<"\n\n\t\t\t Withdraw amount option";
     file.open("bank.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n file opening error...";
     }
     else
     {
          cout<<"\n\n user id :";
         cin>>t_id;
         file1.open("bank1.txt",ios::app|ios::out);
         file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         while(!file.eof())
         {
             if(t_id==id)
             {
                 cout<<"\n\n\n Amount for withdraw: ";
                 cin>>with;
                 if(with<= balance)
                 {
                      balance -=with;
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                 cout<<"\n\n\n\t\t your amount "<<with<<" successfully withdraw...";

                 }
                 else
                 {    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                     cout<<"\n\n\t\t your current balance "<<balance<<"is less....";
                 }
                 found++;

             }
             else
             {
                  file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
             }
             file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         }
         file.close();
         file1.close();
         remove("bank.txt");
         rename("bank1.txt","bank.txt");

         if(found==0)
         cout<<"user id can't found....";

     }
 }

 void bank::transfer()
 {
     fstream file,file1;
     string s_id,r_id;
     float amount;
     int found=0;
     system("cls");
     cout<<"\n\n\t\t\t Payment transfer option";
     file.open("bank.txt",ios::in);
     if(!file)
     {
         cout<<"\n\nfile opening error...";
     }
     else
     {
         cout<<"\n\n enter sender user id for transaction: ";
         cin>>s_id;
          cout<<"\n\n enter reciever user id for transaction: ";
          cin>>r_id;
          cout<<"\n\n enter transaction amount: ";
          cin>>amount;
          file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
          while(!file.eof())
          {
              if(s_id==id&&amount<=balance)
                found++;
              else if(r_id==id)
                found++;
              file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
          }
          file.close();
          if(found==2)
          {
              file.open("bank.txt",ios::in);
              file1.open("bank1.txt",ios::app|ios::out);
          file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
          while(!file.eof())
          {
              if(s_id==id)
              {
                  balance-=amount;
                  file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";

              }
              else if(r_id==id)
              {
                  balance+=amount;
                   file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";

              }
              else
              {
                   file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
              }
              file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
          }
          file.close();
          file1.close();
          remove("bank.txt");
          rename("bank1.txt","bank.txt");
          cout<<"\n\n\n your transaction is successful";


          }
          else
          {
              cout<<"\n\n\t\t transaction id's & balance are invalid...";

          }

     }

 }

 void bank::payment()
 {
     system("cls");
     fstream file,file1;
     string t_id,b_name;
     SYSTEMTIME x;
     float amount;
     int found=0;
     cout<<"\n\n\t\t\t Bill payment option";
      file.open("bank.txt",ios::in);
     if(!file)
     {
         cout<<"\n\nfile opening error...";
     }
     else
     {
         cout<<"\n\n Enter user id: ";
         cin>>t_id;
         cin.ignore();
         cout<<"bill_name : ";
         getline(cin,b_name);
         cout<<"\n\n Bill amount: ";
         cin>>amount;
         file1.open("bank1.txt",ios::app|ios::out);
         file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         while(!file.eof())
          {
              if(t_id==id&&amount<=balance)
              {
                  balance-=amount;
                  file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                  found++;
              }
              else
              {
                  file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
              }

                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;

          }
          file.close();
          file1.close();
          remove("bank.txt");
          rename("bank1.txt","bank.txt");
          if(found==1)
          {
              GetSystemTime(&x);
              file.open("bill.txt",ios::app|ios::out);
              file<<t_id<<" "<<b_name<<" ,"<<amount<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<"\n";
              file.close();
              cout<<"\n\t"<<b_name<<"Bill payment successful";


          }
          else
          {
              cout<<"\n\n User Id or Amount invalid.....";
          }
     }

 }

 void bank::search_user()
 {
     system("cls");
     fstream file;
     string t_id;
     int found=0;
     cout<<"\n\n\n search user record";
      file.open("bank.txt",ios::in);
     if(!file)
     {
         cout<<"\n\nfile opening error...";
     }
     else
     {
         cout<<"\n\n enter user id: ";
         cin>>t_id;
         file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         while(!file.eof())
          {
              if(t_id==id)
              {
                  system("cls");
                  cout<<"\n\n\t\t user details are : ";
                  cout<<"\n\n id: "<<id<<"\n\n name:  "<<name<<"\n\n father name: "<<fname<<"\n\n address: "<<address<<"\n\n pin: "<<pin<<"\n\n pass: "<<pass<<"\n\n phone no: "<<phone<<"\n\n current balance: "<<balance<<"\n";
                  found++;
              }
              file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;

          }
          file.close();
          if(found==0)
          {
              cout<<"\n\n user id can't found....";
          }


     }
 }

  void bank::edit()
  {
      system("cls");
      fstream file,file1;
      string t_id,n,f,a,pi,pa,ph;

      int found=0;
      cout<<"\n\n\n edit user record";
       file.open("bank.txt",ios::in);
     if(!file)
     {
         cout<<"\n\nfile opening error...";
     }
     else
     {

         cout<<"\n\n enter user id: ";
         cin>>t_id;

         file1.open("bank1.txt",ios::app|ios::out);
         file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         while(!file.eof())
          {
              if(t_id==id)
              {
                   cout<<"\n\n  name: ";
                       cin.ignore();
                     getline(cin,n);
                      cout<<"\n\n Father name: ";
                     getline(cin,f);
                      cout<<"\n\n Address: ";
                     getline(cin,a);
                      cout<<"\n\n pin code(5 digit): ";
                     getline(cin,pi);
                     cout<<"\n\n password: ";
                     getline(cin,pa);
                      cout<<"\n\n phone no: ";
                     cin>>ph;

                       file1<<" "<<id<<" "<<n<<" "<<f<<" "<<a<<" "<<pi<<" "<<pa<<" "<<ph<<" "<<balance<<"\n";
                       cout<<"\n\n record edited successfully...";
                       found++;
              }
              else
              {
                  file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
              }
              file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;

          }
          file.close();
          file1.close();
          remove("bank.txt");
          rename("bank1.txt","bank.txt");
          if(found==0)
          {
              cout<<"\n\n user id can't found....";
          }
     }

}
void bank::del()
{
     system("cls");
      fstream file,file1;
      string t_id;

      int found=0;
      cout<<"\n\n\n delete user record";
       file.open("bank.txt",ios::in);
     if(!file)
     {
         cout<<"\n\nfile opening error...";
     }
     else
     {

         cout<<"\n\n enter user id: ";
         cin>>t_id;

         file1.open("bank1.txt",ios::app|ios::out);
         file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         while(!file.eof())
          {
              if(t_id==id)
              {
                       cout<<"\n\n record deleted successfully...";
                       found++;
              }
              else
              {
                  file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
              }
              file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;

          }
          file.close();
          file1.close();
          remove("bank.txt");
          rename("bank1.txt","bank.txt");
          if(found==0)
          {
              cout<<"\n\n user id can't found....";
          }
     }

}

void bank::show_records()
{
    system("cls");
    fstream file;
    int found=0;
    cout<<"\n\n\t\tshow all users records: ";
    file.open("bank.txt",ios::in);
    if(!file)
     {
         cout<<"\n\nfile opening error...";
     }
     else
     {
       file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       while(!file.eof())
          {
               cout<<"\n\n id: "<<id<<"\n\n name:  "<<name<<"\n\n father name: "<<fname<<"\n\n address: "<<address<<"\n\n pin: "<<pin<<"\n\n pass: "<<pass<<"\n\n phone no: "<<phone<<"\n\n current balance: "<<balance<<"\n";
               cout<<"\n================================================================================";
              file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
              found++;
           }
          file.close();
          if(found==0)
            cout<<"\n\n data base is empty .....";

     }

}

void bank::show_payments()
{
     system("cls");
    fstream file;
    int found=0;
    string t_id,c_date,b_name;

    float amount;

    cout<<"\n\n\t\tshow all bill records: ";
    file.open("bill.txt",ios::in);
    if(!file)
     {
         cout<<"\n\n There are no bills to show here/a...";
     }
     else
     {
         file>>t_id;
       while(!file.eof())
          {
              cin.ignore();
              getline(file,b_name,',');
              file>>amount>>c_date;
               cout<<"\n\n id: "<<t_id<<"\n\n bill name:  "<<b_name<<"\n\n bill_amount: "<<amount<<"\n\n date: "<<c_date<<"\n";
               cout<<"\n================================================================================";
               file>>t_id;

              found++;
           }
          file.close();
          if(found==0)
            cout<<"\n\n data base is empty .....";
     }

}

void bank::user_balance()
{
    system("cls");
    fstream file;
    string t_id,t_pin,t_pass;
    char ch;
    int found=0;
    cout<<"\n\n\t\tUser login and check Balance";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\nerror in bank,please visit your bank!";
    }
    else
    {
        cout<<"\n\n enter user id: ";
        cin>>t_id;
        cout<<"\n\n\t enter pin code(5digits): ";
        for(int i=1;i<=5;i++)
        {
            ch=_getch();
            t_pin +=ch;
            cout<<"*";
        }
        cout<<"\n\n enter password: ";
        for(int i=1;i<=5;i++)
        {
            ch=_getch();
            t_pass+=ch;
            cout<<"*";
        }
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
            if(t_id==id&&t_pin==pin&&t_pass==pass)
            {
                cout<<"\n\n\t\t Your current balance is: "<<balance;
                found++;
                _getch();
            }

          file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;

        }
        file.close();
        if(found==0)
            cout<<"\n\n\t\t user details are invalid!...";

    }

}

void bank::with_atm()
{
    fstream file,file1;
     string t_id,t_pin,t_pass;
     char ch;
     float with;
     int found=0;
     system("cls");
     cout<<"\n\n\t\t\t Withdraw amount option";
     file.open("bank.txt",ios::in);
     if(!file)
     {
         cout<<"\n\nfile opening error...";
     }
     else
     {
          cout<<"\n\n user id :";
         cin>>t_id;
         cout<<"\n\n\t enter pin code: ";
        for(int i=1;i<=5;i++)
        {
            ch=_getch();
            t_pin +=ch;
            cout<<"*";
        }
        cout<<"\n\n enter password: ";
        for(int i=1;i<=5;i++)
        {
            ch=_getch();
            t_pass+=ch;
            cout<<"*";
        }

         file1.open("bank1.txt",ios::app|ios::out);
         file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         while(!file.eof())
         {
             if(t_id==id&&t_pin==pin&&t_pass==pass)
             {
                 cout<<"\n\n\n Amount for withdraw: ";
                 cin>>with;
                 if(with<= balance)
                 {
                      balance -=with;
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                 cout<<"\n\n\n\t\t your amount "<<with<<" successfully withdraw...";
                  cout<<"\n\n\t\t   your current balance "<<balance;
                  _getch();


                 }
                 else
                 {    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                     cout<<"\n\n\t\t your current balance "<<balance<<"is less....";
                     _getch();
                 }
                 found++;

             }
             else
             {
                  file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
             }
             file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         }
         file.close();
         file1.close();
         remove("bank.txt");
         rename("bank1.txt","bank.txt");

         if(found==0)
         cout<<"user id can't found....";

     }

}

void bank::check_account()
{
     fstream file;
     string t_id,t_pin,t_pass;
     char ch;
     int found=0;
     system("cls");
     cout<<"\n\n\t\t\t check account details option";
     file.open("bank.txt",ios::in);
     if(!file)
     {
         cout<<"\n\nfile opening error...";
     }
     else
     {
          cout<<"\n\n user id :";
         cin>>t_id;
         cout<<"\n\n\t enter pin code: ";
        for(int i=1;i<=5;i++)
        {
            ch=_getch();
            t_pin +=ch;
            cout<<"*";
        }
        cout<<"\n\n enter password: ";
        for(int i=1;i<=5;i++)
        {
            ch=_getch();
            t_pass+=ch;
            cout<<"*";
        }
         file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         while(!file.eof())
         {
             if(t_id==id&&t_pin==pin&&t_pass==pass)
             {
                 system("cls");

                  cout<<"\n\n id: "<<id<<"\n\n name:  "<<name<<"\n\n father name: "<<fname<<"\n\n address: "<<address<<"\n\n pin: "<<pin<<"\n\n pass: "<<pass<<"\n\n phone no: "<<phone<<"\n\n current balance: "<<balance<<"\n";
                 found++;
                 _getch();

             }

            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         }

         }
         file.close();
         if(found==0)
         cout<<"user id can't found....";

}

 int main()
{
   bank obj;
   obj.menu();

    return 0;
}
