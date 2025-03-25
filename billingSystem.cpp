#include <bits/stdc++.h>
using namespace std;

map<string, pair<int, int>> mp;

void storeItems()
{
    int q, p;
    string i;
    cout << "Enter the item name, quantity, and price (or type 'exit' to stop):" << endl;
    while (true)
    {
        cin >> i;
        if (i == "exit")
            break;
        if (q < 0 || p < 0)
        {
            cout << "Invalid input! Quantity and price must be non-negative.\n";
            continue;
        }
        cin >> q >> p;

        mp[i] = {p, q};
    }
}
void displayBill(vector<pair<string, pair<int, int>>> &bill, int &amt)
{
    if (bill.empty())
    {
        cout << "No items in the bill!\n";
        return;
    }
    cout << "\n-------------------- BILL --------------------\n";
    cout << setw(15) << "Item" << setw(15) << "Quantity" << setw(15) << "Price" << setw(15) << "Total" << endl;
    cout << "-------------------------------------------------\n";
    for (const auto &item : bill)
    {
        cout << setw(15) << item.first << setw(15) << item.second.first << setw(15) << item.second.second
             << setw(15) << item.second.first * item.second.second << endl;
    }
    cout << "-------------------------------------------------\n";
    cout << "Total Amount to Pay: " << amt << endl;
    cout << "Thanks for Shopping!\n";
}
void calculateBill(vector<pair<string, pair<int, int>>> &bill, int &amt)
{
    int uQ;
    string uI;
    cout << "enter the item and quantity" << endl;
    cout << "Available items:\n";
    for (const auto &it : mp)
    {
        cout << setw(10) << left << it.first << setw(10) << "Stock: " << it.second.second << setw(10) << "Price: " << it.second.first << endl;
    }
    cin >> uI >> uQ;

    if (mp.find(uI) == mp.end())
    {
        cout << "Item is not available.\n";
    }
    else if (mp[uI].second < uQ)
    {
        cout << " Not enough stock available.\n";
    }
    else
    {

        pair<int, int> p = mp[uI];
        int quant = p.second;
        int price = p.first;
        quant -= uQ;
        amt += uQ * price;
        bill.push_back({uI, {uQ, price}});
        if (quant <= 0)
        {
            mp.erase(uI);
        }
        else
        {
            mp[uI] = {price, quant};
        }
        cout << " Item added to bill!\n";
    }
}
int main()
{
    int choice;

    vector<pair<string, pair<int, int>>> bill;
    int amt = 0;
    mp["Apple"] = {20, 50};
    mp["Milk"] = {10, 60};
    mp["Rice"] = {50, 80};
    mp["Bread"] = {25, 40};

    do
    {
        cout << "\n1. Store Items\n2. Calculate Bill\n3. Display Bill\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            storeItems();
            break;
        case 2:
            calculateBill(bill, amt);
            break;
        case 3:
            displayBill(bill, amt);
            break;
        case 4:
            cout << "Exiting... Thank you!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);
}