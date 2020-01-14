#include <iostream>
#include <fstream>

using namespace std;
struct customer
{
    string firstname;
    string lastname;
    int numacc;
    float accountbalance;
};

int main()
{
    customer list[10];
    int numacc, numtran;
    ifstream accountinf;
    ifstream loginf;
    ofstream reportinf;
    accountinf.open("accounts.txt");
    loginf.open("log1.txt");
    reportinf.open("report.txt");
    accountinf >> numacc;
    for (int i = 0; i < numacc; i++)
    {
        accountinf >> list[i].firstname >> list[i].lastname >> list[i].numacc >> list[i].accountbalance;
    }
    int usedacc;
    string action;
    int amount, takeam;
    loginf >> numtran;
    for (int i = 0; i < numtran; i++)
    {
        loginf >> usedacc;
        loginf >> action;
        if (action == "Balance")
        {
            for (int i = 0; i < numacc; i++)
            {
                if (usedacc == list[i].numacc)
                {
                    reportinf << list[i].lastname << "," << list[i].firstname << endl
                              << "Account Balance:$" << list[i].accountbalance << endl;
                }
            }
        }
        else if (action == "Withdraw")
        {
            for (int i = 0; i < numacc; i++)
            {
                if (usedacc == list[i].numacc)
                {
                    loginf >> takeam;
                    list[i].accountbalance = list[i].accountbalance - takeam;
                    reportinf << list[i].lastname << "," << list[i].firstname << endl
                              << "Account Balance:$" << list[i].accountbalance << endl;
                }
            }
        }
        else if (action == "Deposit")
        {
            for (int i = 0; i < numacc; i++)
            {
                if (usedacc == list[i].numacc)
                {
                    loginf >> takeam;
                    list[i].accountbalance = list[i].accountbalance + takeam;
                    reportinf << list[i].lastname << "," << list[i].firstname << endl
                              << "Account Balance:$" << list[i].accountbalance << endl;
                }
            }
        }
    }
    return 0;
}