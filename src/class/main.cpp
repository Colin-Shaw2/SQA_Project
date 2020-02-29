/*************************************
  * Main class is used to process the  *
  * inputs into their proper functions *
  * and passed into proper classes     *
  *************************************/

#include "Admin.cpp"
#include "FullStandard.cpp"
#include "BuyStandard.cpp"
#include "SellStandard.cpp"
#include "Item.cpp"
#include "TransactionCodeMaker.cpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

string line;
string itemFileName;
string userFileName;
string transactionFileName;


//global variables
const int usernameLength = 15;

enum inputState
{
  STATE_LOGGED_OUT,
  STATE_LOGGING_IN,
  STATE_WAITING,
  STATE_CREATE,
  STATE_DELETE,
  STATE_LOGOUT,
  STATE_ADD_CREDIT,
  STATE_REFUND,
  STATE_ADVERTISE,
  STATE_BID
};


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
  fstream userFile;

  userFile.open(userFileName);

  // read file line by line
  while (getline(userFile, inString))
  {
    if (inString.substr(0, usernameLength) == username)
    {
      userFile.close();
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

  userFile.close();
  return NULL;
};


/**
 * isValidUsername is called to validate string username inputs. isValidUsername
 * takes in a string parameter, checks if it's not empty and it's less than 15
 * characters. If all tests pass, it returns true, and if they fail
 * it returns false
 *
 * @param variable   user name to be checked
 * @return boolean
 */
bool isValidUsername(string variable)
{
  if (!variable.empty())
  {
    if (variable.length() <= usernameLength){
      if((variable == "\0") || (variable == "\\0") || (variable == "root")){
        cout << "That is an invalid username" << endl;
        return false;
      }
      if(NULL == getUser(variable)){
            cout << "We could not find that username" << endl;
            return false;
      }else{
            return true;
          }
        }
    else{
      cout << "That is an invalid username" << endl;
      return false;
    }
  }
  else
  {
    cout << "That is an invalid username" << endl;
    return false;
  }
}



/**
 * isValidNewUser is called to validate string username inputs for new users 
 * It takes in a string parameter, checks if it's not empty and it's less than 15
 * characters. Next, it checks if the user already exists.
 * If all tests pass, it returns true, and if they fail
 * it returns false with an explanation 
 *
 * @param variable   user name to be checked
 * @return boolean
 */
bool isValidNewUser(string variable)
{
  if (!variable.empty())
  {
    if (variable.length() <= usernameLength){
      if((variable == "\0") || (variable == "\\0") || (variable == "root")){
        cout << "That is an invalid username" << endl;
        return false;
      }
      if(NULL == getUser(variable)){
            return true;
      }else{
            cout << "User already exists" << endl;
            return false;
          }
        }
    else{
      cout << "That is an invalid username" << endl;
      return false;
    }
  }
  else
  {
    cout << "That is an invalid username" << endl;
    return false;
  }
}

/**
 * isValidItemName is called to validate string itemName inputs. isValidItemName
 * takes in a string parameter, checks if it's not empty and it's less than 25
 * characters. If all tests pass, it returns true, and if they fail
 * it returns false
 *
 * @param variable   item name to be checked
 * @return boolean
 */
bool isValidItemName(string variable)
{
  if (!variable.empty())
  {
    if (variable.length() < 25)
    {
      if((variable == "\0") || (variable == "\\0") || (variable == "root")){
        cout << "Invalid Name" << endl;
        return false;
      }
      fstream itemFile;
      itemFile.open(itemFileName);
      while(getline(itemFile, line)){
        if(line.find(variable)){
          return true;
        }
      }
      itemFile.close();
      cout << "We could not find that Item" << endl;
      return false;
    }
    cout << "Name too long" << endl;
    return false;
  }
  else
  {
    cout << "That is an invalid item name" << endl;
    return false;
  }
}

/**
 * isValidAmount is called to validate integer inputs. isValidAmount takes in
 * an int parameter, checks if it's between bigger than 0 and smaller than
 * 1000000. If the input satisfies the range, it returns true. Otherwise,
 * it returns false
 *
 * @param variable     amount input to be checked if it's between 0 and 1000000
 * @return boolean
 */
bool isValidAmount(int variable)
{
  if (variable < 1 || variable > 100000000)
  {
    cout << "Invalid amount" << endl;
    return false;
  }
  return true;
}


/**
 * isValidUserType is called to validate the user types inputted by checking
 * if it's one of the four possible choices. If it's one of the four, returns
 * true. Otherwise returns false
 *
 * @param variable     String to be checked if it's one of AA FS BS SS
 * @return boolean
 */
bool isValidUserType(string variable){
  if((variable == "AA") || (variable == "FS") || (variable == "BS") || ( variable == "SS")){
    return true;
  }
  cout << "Invalid type of user" << endl;
  return false;
}

/**
 * main uses a loop on cin to take in the inputs
 *
 */

int main(int argc, char const *argv[])
{
  //get the input and putput file names from command line
  if (argc < 4)
  {
    cout << "not enough command line arguments" << endl;
    exit(-1);
  }

  userFileName = argv[1];
  itemFileName = argv[2];
  transactionFileName = argv[3];

  inputState currentState = STATE_LOGGED_OUT;
  bool quit = false;
  bool loggedIn = false;
  string input = "";
  User *currentUser;
  //prevent infinite loops
  int maxTimesToLoop = 1000;
  int timesLooped = 0;

  while (!quit)
  {
    timesLooped++;
    if(timesLooped >= maxTimesToLoop){exit(0);}
    input = "";
    switch (currentState)
    {
    case STATE_LOGGED_OUT:
      //cout << "Please enter your username:" << endl;
      break;
    case STATE_WAITING:
      //cout << "Enter a command:" << endl;
      break;
    default:
      cout << "Please Enter an input (default)" << endl;
      break;
    }
    cin >> input;

    //commented code below is for debugging
    if (input == "q" || input == "thisLongStringExitsTheProgram")
    {
      quit = true;
      break;
    }

    if(!loggedIn){
      if (input == "login")
      {
        currentState =STATE_LOGGING_IN;
      }else{
        cout << "No user currently logged in: please login to complete the operation" << endl;
        currentState = STATE_LOGGED_OUT;
      }
    }

    //If waiting get next command
    if (currentState == STATE_WAITING)
    {
      if (input == "logout")
      {
        currentState = STATE_LOGOUT;
      }
      else if (input == "addcredit")
      {
        currentState = STATE_ADD_CREDIT;
      }
      else if (input == "login")
      {
        cout << "Already logged in." << endl;
      }
      else if (input == "advertise")
      {
        currentState = STATE_ADVERTISE;
      }
      else if (input == "bid")
      {
        currentState = STATE_BID;
      }
      else if (input == "create")
      {
        currentState = STATE_CREATE;
      }
      else if (input == "delete")
      {
        currentState = STATE_DELETE;
      }
      else if (input == "refund")
      {
        currentState = STATE_REFUND;
      }
    }

    switch (currentState)
    {
    //Not yet logged in
    //login
    case STATE_LOGGED_OUT:
    {
      break;
    }
    case STATE_LOGGING_IN:
    {
      cout << "Please enter your username:" << endl;
      cin >> input;
      if (isValidUsername(input))
      {
        currentUser = getUser(input);
        if (currentUser != NULL)
        {
          cout << "Login successful!" << endl;
          loggedIn = true;
          currentState = STATE_WAITING;
        }
      }
      else{
        currentState = STATE_LOGGED_OUT;
      }
      break;
    }
    //No valid command was given
    case STATE_WAITING:
    {
      break;
    }

    // case STATE_LOGGING_IN:
    // {
    //   currentState = STATE_LOGGED_OUT;
    //   break;
    // }

    case STATE_CREATE:
    {
      string username;
      string userType;
      int credit;

      cout << "Please Enter User Name:" << endl;
      cin >> username;

      if(!isValidNewUser(username)){
        currentState = STATE_WAITING;
        break;
      }

      cout << "Type of user?(Admin(AA)/BuyAndSell(FS)/Buy(BS)/Sell(SS))" << endl;
      cin >> userType;
      if(!isValidUserType(userType)){
        currentState = STATE_WAITING;
        break;
      }
      cout << "Starting Balance?" << endl;
      cin >> credit;
      if((credit < 0) || (credit > 100000000)){
        cout << "Invalid amount" << endl;
        currentState = STATE_WAITING;
        break;
      }

      currentUser->createNewUser(username,userType,credit);

      cout << "Created User \"" <<  username <<  "\" as " << currentUser->getType(userType) << " with $" << credit << endl;
      currentState = STATE_WAITING;
      break;
    }
    case STATE_DELETE:
    {
      if(currentUser->getUserType() != "AA"){
        cout << "Only admins can use that command" << endl;
        currentState = STATE_WAITING;
        break;
      }
      string username;
      
      cout << "Please enter a user name to be deleted" << endl;
      cin >> username;
      if(!isValidUsername(username)){
        currentState = STATE_WAITING;
        break;
      }
      for (int i = username.length(); i < usernameLength; i++)
      {
        username += " ";
      }
      if(currentUser->getName() == username){
        cout << "User cannot be deleted" << endl;
        currentState = STATE_WAITING;
        break;
      }

      currentUser->deleteUser(username, userFileName);

      cout << "User is deleted!" << endl;
      currentState = STATE_WAITING;
      break;
    }
    case STATE_LOGOUT:
    {
      currentUser->logout(transactionFileName);
      //cout << "Logout successful!" << endl;
      currentState = STATE_LOGGED_OUT;
      loggedIn = false;
      break;
    }
    case STATE_ADD_CREDIT:
    {
      string username;
      int amount;

      //Checks if admin, gives option for username if so

      if(currentUser->getUserType() == "AA"){
        cout << "Please enter a username:" << endl;
        cin >> username;
        if(!isValidUsername(username)){
          currentState = STATE_WAITING;
          break;
        }
        User *user = getUser(username);


        cout << "Current Balance $" << user->getBalance() << endl;
        cout << "How much would you like to add?" << endl;
        cin >> amount;
        if(!isValidAmount(amount)){
          currentState = STATE_WAITING;
          break;
        }
        int currentMaxCredit = 0;
        for (int i = 0; i < currentUser->accountsAddedTo.size(); i++)
        {
          if(user->getName() == currentUser->accountsAddedTo[i]){
            currentMaxCredit = currentUser->amountAdded[i];
            break;
          }
        }
        if(!(user->getBalance() + amount < 1000000)){
          cout << "Error Balance would be too high max value($999999.99)" << endl;
          currentState = STATE_WAITING;
          break;
        }
        else if((currentMaxCredit > 1000) || (currentMaxCredit + amount >1000)){
          cout << "Cannot add more than $1000 in one session" << endl;
          currentState = STATE_WAITING;
          break;
        }else{
          user->addCredit(amount);
          
          currentUser->accountsAddedTo.push_back(user->getName());
          currentUser->amountAdded.push_back(amount);

          currentUser->setTransactions(user->getTransactions());
        if (user->getName() == currentUser->getName()){
          //currentUser->setBalance(currentUser->getBalance() + amount);
          currentUser->setMaxCredit(currentUser->getMaxCredit() + amount);
        }
          cout << "Credit added, Balance is $" << user->getBalance() + amount << endl;
          
          currentState = STATE_WAITING;
          break;
        }
      }

      else{//Non admins
        cout << "Current Balance $" << currentUser->getBalance() << endl;
        cout << "How much would you like to add?" << endl;
        cin >> amount;
        if(!isValidAmount(amount)){
          currentState = STATE_WAITING;
          break;
        }

        if(!(currentUser->getBalance() + amount < 1000000)){
          cout << "Error Balance would be too high max value($999999.99)" << endl;
          currentState = STATE_WAITING;
          break;
        }
        else if((currentUser->getMaxCredit() > 1000) || (amount >1000)){
          cout << "Cannot add more than $1000 in one session" << endl;
          currentState = STATE_WAITING;
          break;
        }else{
          currentUser->addCredit(amount);

          currentUser->accountsAddedTo.push_back(currentUser->getName());
          currentUser->amountAdded.push_back(amount);

          cout << "Credit added, Balance is $" << currentUser->getBalance() + amount << endl;
          
          currentState = STATE_WAITING;
          break;
        }
      }
    }
    case STATE_REFUND:
    {
      string buyerUsername;
      string sellerUsername;
      int amount;

      if(!(currentUser->getUserType() == "AA")){
        cout << "Refund cannot be completed from a non admin account!" << endl;
        currentState = STATE_WAITING;
        break;
      }

      cout << "Please enter the buyer's username:" << endl;
      cin >> buyerUsername;
      if(!isValidUsername(buyerUsername)){
        currentState = STATE_WAITING;
        break;
      }
      cout << "Please enter the seller's username:" << endl;
      cin >> sellerUsername;
      if(!isValidUsername(sellerUsername)){
        currentState = STATE_WAITING;
        break;
      }
      cout << "Please enter the refund amount:" << endl;
      int amountInt;
      cin >> amountInt;
      
      if(cin.fail()){
        cin.clear();
        amount = -1;
      }else{
        amount = amountInt;
      }
      if(!isValidAmount(amount)){
        currentState = STATE_WAITING;
        break;
      }
      //Buyer has too many funds
      if(100000000 <= amount + getUser(buyerUsername)->getBalance()){
        cout << "Transaction reject buyer has too many funds" << endl;
        currentState = STATE_WAITING;
        break;
        }
      //check for sufficient funds
      if(amount > getUser(sellerUsername)->getBalance()){
        cout << "Seller does not have sufficient funds for a refund." << endl;
        currentState = STATE_WAITING;
        break;
        }
      currentUser->refund(buyerUsername, sellerUsername, amount, userFileName);

      cout << "Refund successful!" << endl;

      currentState = STATE_WAITING;
      break;
    }
    case STATE_ADVERTISE:
    {
      string itemName;
      int minimumBid;
      int daysToBid;
      float days;

      //Check for usertype BS
      if(currentUser->getUserType() == "BS"){
        cout << "You do not have permission to advertise" << endl;
        currentState = STATE_WAITING;
        break;
      }

      cout << "Name of product:" << endl;
      cin >> itemName;
      if(!isValidItemName(itemName)){
        currentState = STATE_WAITING;
        break;
      }

      cout << "Minimum Bid(CAD$ 00.01-999.99):" << endl;
      cin >> minimumBid;
      if(cin.fail()){
        cin.clear();
        minimumBid = -1;
      }
      if((!isValidAmount(minimumBid))){
        currentState = STATE_WAITING;
        break;
      }
      if(minimumBid >= 1000){
        cout << "Invalid amount" << endl;
        currentState = STATE_WAITING;
        break;
      }
      cout << "Number of days:" << endl;
      cin >> days;
      if(cin.fail()){
        cin.clear();
        daysToBid = -1;
        days = 0.5;
      }
      if(days ==ceilf(days)){
        daysToBid = days; 
      }else{
        daysToBid = -1;
      }
      
      if((0 >= daysToBid) || (daysToBid > 100)){
        cout << "Invalid number of days" << endl;
        currentState = STATE_WAITING;
        break;
      }
      currentUser->advertise(itemName, minimumBid, daysToBid);

      cout << "Item added successfully!" << endl;

      currentState = STATE_WAITING;
      break;
    }
    case STATE_BID:
    {
      string itemName;
      string username;
      int amount;

      if(currentUser->getUserType() == "SS"){
        cout << "You do not have permission to bid" << endl;
        currentState = STATE_WAITING;
        break;
      }

      cout << "Enter Product Name:" << endl;
      cin >> itemName;
      if(!isValidItemName(itemName)){
        currentState = STATE_WAITING;
        break;
      }
      Item *item = currentUser->getItem(itemName, itemFileName);
      
      cout << "Enter Username:" << endl;
      cin >> username;
      if(!isValidUsername(username)){
        currentState = STATE_WAITING;
        break;
      }

      cout << "Current Bid $" << item->getCurrentBid() << endl;
      cin >> amount;
      if(!isValidAmount(amount)){
        currentState = STATE_WAITING;
        break;
      }
      currentUser->bid(itemName, username, amount, item);

      cout << "Bid Successful!" << endl;

      currentState = STATE_WAITING;
      break;
    }
    default:
    {
      cout << "ERROR Do stuff switch is (default)" << endl;
      break;
    }
    }
  }

  return 0;
}
