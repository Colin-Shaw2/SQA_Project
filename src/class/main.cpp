#include "User.cpp"
#include "Item.cpp"
#include "TransactionCodeMaker.cpp"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  bool quit = false;
  while (!quit)
  {
    string input = "";
    cout << "Please Enter an input" << endl;
    cin >> input;
    if (input == "q")
    {
      quit = true;
    }
  }

  return 0;
}

void isValidString(string variable)
{
}
void isValidInt(int variable)
{
}

void checkAdvertise(string itemName, int minimumBid, int daysToBid)
{
}
