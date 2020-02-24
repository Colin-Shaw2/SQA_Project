#pragma once
#include "Admin.cpp"
#include "FullStandard.cpp"
#include "BuyStandard.cpp"
#include "SellStandard.cpp"
#include "Item.cpp"
#include "TransactionCodeMaker.cpp"
#include <string>
#include <iostream>
#include <fstream>

class FileIOHandler
{
private:
    int const usernameLength= 15;
    string itemFileName;
    string userFileName;
    string transactionFileName;
    /* data */
public:

/**
 * getUser searches file for a user and returns a new user object
 *
 * @param username the user trying to be found
 * @param userFile the filename where the users are stored
 * @return a pointer to a user object if the user is found or NULL if no user is found
 */
User *getUser(string username)
{
  //buffer username
  for (int i = username.length(); i < usernameLength; i++)
  {
    username += " ";
  }

  string inString;
  ifstream inFile;

  inFile.open(userFileName);
  if (!inFile)
  {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }

  // read file line by line
  while (getline(inFile, inString))
  {
    if (inString.substr(0, usernameLength) == username)
    {
      cout << "Login successful!" << endl;
      inFile.close();
      string userType = inString.substr(16, 2);
      if (userType == "AA")
      {
        return new Admin(username, stoi(inString.substr(19, 9)));
      }
      if (userType == "FS")
      {
        return new FullStandard(username, stoi(inString.substr(19, 9)));
      }
      if (userType == "BS")
      {
        return new BuyStandard(username, stoi(inString.substr(19, 9)));
      }
      if (userType == "SS")
      {
        return new SellStandard(username, stoi(inString.substr(19, 9)));
      }
    }
  }

  inFile.close();
  cout << "We could not find that username" << endl;
  return NULL;
};

    FileIOHandler(string itemFile, string userFile, string transactionFile) {
        itemFileName = itemFile;
        userFileName = userFile;
        transactionFileName = transactionFile;
    }
    ~FileIOHandler() {}
};
