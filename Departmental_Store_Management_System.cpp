#include<bits/stdc++.h>

using namespace std;

void  logo()
{
    cout <<"              _________       "<<'\n';
    cout <<"        ___  |_________|    ___"<<'\n';
    cout <<"        | |  _   | |   _    | |"<<'\n';
    cout <<"        | | |_)  | |  /_\\   | |"<<'\n';
    cout <<"        | | |_)  | | /   \\  | |"<<'\n';
    cout <<"        | |______| |________| |"<<'\n';
    cout <<"        |________| |__________|"<<'\n';
    cout <<"              ___| |___       "<<'\n';
    cout <<"             |_________|     "<<'\n';
    cout <<"\n\n           Welcome to SHOPNO\n"<<'\n';
}


class product
{
    string name;
    string color;
    int amount;
    int prize;
public:
    static int total_product;
    void set_name(string str)
    {
        name=str;
    }
    void set_color(string str)
    {
        color=str;
    }
    void set_amount(string str)
    {
        int x=stoi(str);
        amount=x;
    }
    void set_prize(string str)
    {
        int x=stoi(str);
        prize=x;
    }
    void add_new_product()
    {
        cout << "Enter product name:\t";
        cin >> name;
        cout << "Enter product color:\t";
        cin >> color;
        cout << "Enter product amount:\t";
        cin >> amount;
        cout << "Enter product prize:\t";
        cin >> prize;
    }
    void view_all_product()
    {
        cout << "Product Name:\t\t" << name << '\n';
        cout << "Product Color:\t\t" << color << '\n';
        cout << "Remaining Amount:\t" << amount << '\n';
        cout << "Product Prize:\t\t" << prize << '\n';
    }
    bool check_available()
    {
        if(amount>0)
            return true;
        return false;
    }
    int make_bill()
    {
        amount--;
        return prize;
    }
    void save(ofstream &myfile)
    {
        myfile << name << '\n';
        myfile << color << '\n';
        myfile << amount << '\n';
        myfile << prize << '\n';
    }
} product_list[100];

int product::total_product=0;

int buy_product()
{
    product a;
    cout << "\n\n";
    for(int i=0; i<a.total_product; i++)
    {
        cout << "Product Number #" << i+1 << '\n';
        product_list[i].view_all_product();
        cout << "\n";
    }
    cout << "Which Product You Want to Bye?\n";
    int x;
    cin >> x;
    a=product_list[x-1];
    if(x>a.total_product || !a.check_available())
        return -1;
    int tmp=a.make_bill();
    product_list[x-1]=a;
    return tmp;
}

bool main_menu()
{
    logo();
    cout << "1.\tAdd Product\n";
    cout << "2.\tView all Product\n";
    cout << "3.\tBuy Product\n";
    cout << "4.\tClose Program (Press any other key)\n";
    int x;
    cin >> x;
    if(x==1)
    {
        product a;
        a.add_new_product();
        product_list[a.total_product++]=a;
    }
    else if(x==2)
    {
        product a;
        cout << "\n\n";
        for(int i=0; i<a.total_product; i++)
        {
            product_list[i].view_all_product();
            cout << "\n";
        }
    }
    else if(x==3)
    {
        int sum=0;
        while(1)
        {
            int tmp=buy_product();
            if(tmp==-1)
            {
                cout << "\n\nProduct Not Available.\nBuy Another Product?\n1.\tYes\n2.\tNo\n";
            }
            else
            {
                sum+=tmp;
                cout << "\n\nBuy Another Product?\n1.\tYes\n2.\tNo\n";
            }
            int x;
            cin >> x;
            if(x==2)
                break;
        }
        string name,mobile;
        cout << "Enter your name:\t";
        cin >> name;
        cout << "Enter your phone no:\t";
        cin >> mobile;
        cout << "Your Bill is:\t" << sum << " taka (only)\n";

        ofstream myfile;
        myfile.open ("customer.txt",ios_base::app);
        myfile << "Customer Name:\t" << name << '\n';
        myfile << "Customer Phone No:\t" << mobile << '\n';
        myfile << "Customer Bill:\t" << sum << "\n\n";
        myfile.close();

    }
    else
        return false;
    cout << "\n\nBack to Main Menu?\tPress Enter\n";
    fflush(stdin);
    getchar();
    return true;
}

int main()
{
    product a;
    int flag=0;
    string str;
    ifstream myfiles("product.txt");
    while(getline(myfiles,str))
    {
        flag%=4;
        if(flag==0)
            a.set_name(str);
        else if(flag==1)
            a.set_color(str);
        else if(flag==2)
            a.set_amount(str);
        else if(flag==3)
            a.set_prize(str);
        flag++;
        if(flag==4)
            product_list[a.total_product++]=a;
    }
    myfiles.close();

    string date;
    cout << "Enter Todays Date (dd-mm-yyyy):\t";
    cin >> date;

    ofstream myfile;
    myfile.open ("customer.txt",ios_base::app);
    myfile << date << "\n\n";
    myfile.close();

    while(main_menu())
    {
        system("cls");
    }
    myfile.open ("product.txt");
    for(int i=0; i<a.total_product; i++)
    {
        a=product_list[i];
        a.save(myfile);
    }
    myfile.close();
    return 0;
}
