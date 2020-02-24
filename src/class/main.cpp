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
bool isValidUserName(string variable)
{
  if (!variable.empty())
  {
    if (variable.length() <= usernameLength){
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
    cout << "That is an invalid item name" << endl;
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
  if (variable < 1 || variable > 1000000)
  {
    cout << "Invalid amount!" << endl;
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
  if(variable == "AA" || "FS" || "BS" || "SS"){
    return true;
  }
  cout << "Invalid type of user" << endl;
  return false;
}


/**
 * checkAdvertise is called to validate inputs for advertise. The parameters
 * for checkAdvertise are string itemName, int minimumBid, and int daysToBid.
 * First, checkAdvertise calls isValidItemName, isValidUsername and isValidAmount
 * for the parameters.
 * Next it checks if userType is not BS as BuyStandard cannot advertise
 * itemName is the test on if it contains any special characters.
 * Next, it checks if daysToBid is less than 100 and minimumBid is
 * less than 1000.
 * If any test fails, it will output a message to the corresponding failure.
 * If all these tests pass, advertise is called.
 *
 *
 * @param itemName    name for the item to be posted
 * @param minimumBid  starting bid for the items
 * @param daysToBid   days left on the auction of the item
 * @return void
 */
void checkAdvertise(string itemName, int minimumBid, int daysToBid){};

/**
 * checkRefund is called to validate inputs for Refund. The parameters
 * for checkRefund are string buyerUsername, string sellerUsername, and
 * int amount
 * First checkRefund calls isValidUsername and isValidAmount for the parameters.
 * Next, it checks if the user has permission to apply a refund and if
 * the seller and buyer users exist.
 * If any test fails, it will output a message to the corresponding failure.
 * If all these tests pass, refund is called.
 *
 * @param buyerUsername   user refund is going to
 * @param sellerUsername  user refund is coming from
 * @param amount          amount of refund
 * @return void
 */
void checkRefund(string buyerUsername, string sellerUsername, int amount){};

/**
 * checkDeleteUser is called to validate inputs for DeleteUser. The parameter
 * for checkDeleteUser is string username.
 * isValidUsername is called to validate username.
 * If isValidUsername fails, it will output a message in regards to the input.
 * Otherwise, deleteUser is called.
 *
 * @param username  user to be deleted
 * @return void
 */
void checkDeleteUser(string username){};

/**
 * checkAddCredit is called to validate inputs for AddCredit. The parameter
 * for checkAddCredit is int amount.
 * isValidAmount is called to validate amount inputted.
 * If isValidAmount fails, it will output a message in regards to the input.
 * Otherwise, addCredit is called.
 *
 * @param amount  amount to be added to current user
 * @return void
 */
void checkAddCredit(int amount){};

/**
 * checkCreateNewUser is called to validate inputs for CreateNewUser. The parameter
 * for checkCreateNewUser are string username, string userType, and int credit
 * First isValidUsername and isValidAmount is called to validate the parameters
 * Next, it checks if the username already exists, and if userType fits the
 * four possibilities.
 * If any test fails, it will output a message to the corresponding failure.
 * Otherwise, createNewUser is called.
 *
 * @param username    name of the new user
 * @param userType    type of the new user
 * @param credit      starting credit on the user
 * @return void
 */
void checkCreateNewUser(string username, string userType, int credit){};

/**
 * checkBid is called to validate inputs for Bid. The parameter
 * for checkBid is string itemName, string username, and int amount
 * First isValidItemName, isValidUsername and isValidAmount is called to validate
 * the parameters
 * Next, it checks if the item exists, if the user exists, and if the item and
 * user match
 * If any test fails, it will output a message to the corresponding failure.
 * Otherwise, bid is called.
 *
 * @param itemName  name of the item to place the bid on
 * @param username  name of the user that placed the item
 * @param amount    amount of the new bid
 * @return void
 */
void checkBid(string itemName, string username, int amount){};


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
  string input = "";
  User *currentUser;

  while (!quit)
  {
    input = "";
    switch (currentState)
    {
    case STATE_LOGGED_OUT:
      cout << "Please enter your username:" << endl;
      break;
    case STATE_WAITING:
      cout << "Enter a command:" << endl;
      break;
    default:
      cout << "Please Enter an input (default)" << endl;
      break;
    }
    cin >> input;

    //commented code below is for debugging
    if (input == "q")
    {
      quit = true;
      break;
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
    case STATE_LOGGED_OUT:
    {
      if (isValidUserName(input))
      {
        currentUser = getUser(input);
        if (currentUser != NULL)
        {
          currentState = STATE_WAITING;
        }
      }
      break;
    }
    //No valid command was given
    case STATE_WAITING:
    {
      break;
    }

    case STATE_CREATE:
    {
      string username;
      string userType;
      int credit;

      cout << "Please Enter User Name:" << endl;
      cin >> username;

      if(isValidUserName(username)){
        cout << "User already exists" << endl;
        currentState = STATE_WAITING;
        break;
      }
      if((username.length() > usernameLength) || (username.empty())){
        cout << "Invalid User Name" << endl;
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
      if(!isValidAmount(credit)){
        currentState = STATE_WAITING;
        break;
      }

      currentUser->createNewUser(username,userType,credit);

      cout << "Created User \"" <<  username <<  "\" as " << userType << " with $" << credit << endl;
      currentState = STATE_WAITING;
      break;
    }
    case STATE_DELETE:
    {
      string username;

      cout << "Please enter a user name to be deleted" << endl;
      cin >> username;
      if(!isValidUserName(username)){
        currentState = STATE_WAITING;
        break;
      }

      currentUser->deleteUser(username);

      cout << "User is deleted!" << endl;
      currentState = STATE_WAITING;
      break;
    }
    case STATE_LOGOUT:
    {
      currentUser->logout(transactionFileName);
      //cout << "Logout successful!" << endl;
      currentState = STATE_LOGGED_OUT;
      break;
    }
    case STATE_ADD_CREDIT:
    {
      string username;
      int amount;


      cout << "Please enter a username:" << endl;
      cin >> username;
      if(!isValidUserName(username)){
        currentState = STATE_WAITING;
        break;
      }

      cout << "Current Balance $" << 100 /*place holder*/ << endl;
      cout << "How much would you like to add?" << endl;
      cin >> amount;
      if(!isValidAmount(amount)){
        currentState = STATE_WAITING;
        break;
      }
      currentUser->addCredit(username, amount);

      cout << "Created added, Balance is $" <</*placeHolder*/ currentUser->getBalance() << endl;

      currentState = STATE_WAITING;
      break;
    }
    case STATE_REFUND:
    {
      string buyerUsername;
      string sellerUsername;
      int amount;


      cout << "Please enter the buyer's username:" << endl;
      cin >> buyerUsername;
      if(!isValidUserName(buyerUsername)){
        currentState = STATE_WAITING;
        break;
      }
      cout << "Please enter the seller's username:" << endl;
      cin >> sellerUsername;
      if(!isValidUserName(sellerUsername)){
        currentState = STATE_WAITING;
        break;
      }
      cout << "Please enter the refund amount:" << endl;
      cin >> amount;
      if(!isValidAmount(amount)){
        currentState = STATE_WAITING;
        break;
      }
      currentUser->refund(buyerUsername, sellerUsername, amount);

      cout << "Refund successsful!" << endl;

      currentState = STATE_WAITING;
      break;
    }
    case STATE_ADVERTISE:
    {
      string itemName;
      int minimumBid;
      int daysToBid;


      cout << "Name of product:" << endl;
      cin >> itemName;
      if(!isValidItemName(itemName)){
        currentState = STATE_WAITING;
        break;
      }
      cout << "Minimum Bid(CAD$ 00.01-999.99):" << endl;
      cin >> minimumBid;
      if(!isValidAmount(minimumBid)){
        currentState = STATE_WAITING;
        break;
      }
      cout << "Number of days:" << endl;
      cin >> daysToBid;
      if((0 < daysToBid) || (daysToBid< 100)){
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


      cout << "Enter Product Name:" << endl;
      cin >> itemName;
      if(!isValidItemName(itemName)){
        currentState = STATE_WAITING;
        break;
      }
      cout << "Enter Username:" << endl;
      cin >> username;
      if(!isValidUserName(username)){
        currentState = STATE_WAITING;
        break;
      }
      cout << "Current Bid $" << 50 << endl;
      cin >> amount;
      if(!isValidAmount(amount)){
        currentState = STATE_WAITING;
        break;
      }
      currentUser->bid(itemName, username, amount);

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
