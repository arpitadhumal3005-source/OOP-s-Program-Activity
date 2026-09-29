#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

// Base Class
class Payment
{
protected:
    string id;
    float price;

public:
    Payment(string i, float p)
    {
        id = i;
        price = p;
    }

    virtual void makePayment() const = 0;

    virtual ~Payment()
    {
    }
};

// Credit Card Payment
class Card : public Payment
{
private:
    string cardNo;

public:
    Card(string i, float p, string c)
        : Payment(i, p), cardNo(c)
    {
    }

    void makePayment() const override
    {
        cout << "Payment through Credit Card" << endl;
        cout << "Transaction ID: " << id << endl;
        cout << "Amount: Rs. " << price << endl;
        cout << "Card Number: " << cardNo << endl;
        cout << "Status: Successful" << endl;
        cout << endl;
    }
};

// UPI Payment
class UPI : public Payment
{
private:
    string userId;

public:
    UPI(string i, float p, string u)
        : Payment(i, p), userId(u)
    {
    }

    void makePayment() const override
    {
        cout << "Payment through UPI" << endl;
        cout << "Transaction ID: " << id << endl;
        cout << "Amount: Rs. " << price << endl;
        cout << "UPI ID: " << userId << endl;
        cout << "Status: Successful" << endl;
        cout << endl;
    }
};

// Net Banking Payment
class NetBanking : public Payment
{
private:
    string bank;

public:
    NetBanking(string i, float p, string b)
        : Payment(i, p), bank(b)
    {
    }

    void makePayment() const override
    {
        cout << "Payment through Net Banking" << endl;
        cout << "Transaction ID: " << id << endl;
        cout << "Amount: Rs. " << price << endl;
        cout << "Bank Name: " << bank << endl;
        cout << "Status: Successful" << endl;
        cout << endl;
    }
};

// Main Function
int main()
{
    vector<unique_ptr<Payment>> paymentList;

    paymentList.push_back(
        make_unique<NetBanking>("N301", 45000, "ICICI Bank")
    );

    paymentList.push_back(
        make_unique<Card>("C402", 8750, "XXXX-5464")
    );

    paymentList.push_back(
        make_unique<UPI>("U403", 9400, "Rohan@upi")
    );

    cout << "===== PAYMENT SYSTEM =====" << endl;
    cout << endl;

    for (const auto& p : paymentList)
    {
        p->makePayment();
    }

    return 0;
}