/*
Johnny Utah owns a surf shop on the beach called “Point Break Surf Shop”. Johnny sells surfboards in 3 three sizes:
small (2 meters), medium (3 meters), and large (4 meters). The cost of one small surfboard is $175.00, one medium is
$190.00, and one large is $200.00.  Write a program that will make the surf shop operational.  Your program should
allow the user to do the following:

    1: Buy any surfboard in any size and in any quanity.
    2: At any time show the total number of surfboards of each size sold.
    3: At any time show the total money made.
*/

#include <iostream>
#include <string>
#include <iomanip>

// Name Spaces
using namespace std;

// Constant Variables
    // Prices
const double XXXS_COST = 99.99;
// Leters: used for checking user inputs 
const char LETTER_S_UP = 'S';
const char LETTER_S_LO = 's';

const char LETTER_P_UP = 'P';
const char LETTER_P_LO = 'p';

const char LETTER_C_UP = 'C';
const char LETTER_C_LO = 'c';

const char LETTER_T_UP = 'T';
const char LETTER_T_LO = 't';

const char LETTER_Q_UP = 'Q';
const char LETTER_Q_LO = 'q';

// Common Dialog
const string NO_PURCHASES = "No purchases made yet. ";
const string ENTER_SLECTON = "Please enter selection: ";
// Intro Dialog
const string WELCOME = " Welcome to my Johnny Utah's PointBreak Surf Shop ";
// Show Program Dialog
const string SHOW_LINE = "To show program usage 'S'";
const string PURCHASE_LINE = "To purchase a surfboard press 'P'";
const string CURRENT_LINE = "To display current purchases press 'C'";
const string TOTAL_LINE = "To display total amount due press 'T'";
const string QUIT_LINE = "To quit the program press 'Q'";
// Purchase Surfboard Dialog
const string PURCHASE_PROMPT = "Please enter the quantity of XXXS surfboard(s) for squirrel surfing you would like to purchase:";
// Display Current Dialog and Display Total Dialog
const string DISPLAY_XXXS_AMOUNT = "The total number of XXXS surfbaords is ";
const string TOTAL_AT = "at a total of ";
const string AMOUNT_DUE = "Amount due: ";
// Quit Dialog
const string ENDING = "Thank you";
// Symboles
const char ASTERISK_FILL = '*';
const char DOLLOR_SIGN = '$';
const char EMPTY_SPACE = ' ';
// Width Size
const int WIDTH = 60;

// Function Prototypes
void ShowUsage();
void MakePurchase(int& iTotalXXXS);
void DisplayPurchase(const int iTotalXXXS);
void DisplayTotal(const int iTotalXXXS);

int main()
{
    char userInput = ' ';

    // Total bought boards of each size
    int iTotalXXXS = 0;

    ShowUsage();

    while (userInput != LETTER_Q_UP)
    {
        //Getting user input
        cout << ENTER_SLECTON;
        cin >> userInput;

        switch (userInput)
        {
            // Show uasage
        case LETTER_S_LO:
        case LETTER_S_UP:
            ShowUsage();

            break;

            //Purchase a XXXS Surfboard
        case LETTER_P_LO:
        case LETTER_P_UP:
            MakePurchase(iTotalXXXS);
            cout << endl << endl;
            break;

            //Display Current XXXS Surfboard(s) Purchases
        case LETTER_C_LO:
        case LETTER_C_UP:
            DisplayPurchase(iTotalXXXS);
            cout << endl;
            break;

            //Display Total Amount
        case LETTER_T_LO:
        case LETTER_T_UP:
            DisplayTotal(iTotalXXXS);
            cout << endl << endl;
            break;

            //quit the program 
            // when the user input q it breaks out of the while loop then ends the program.
        case LETTER_Q_LO:
        case LETTER_Q_UP:
            userInput = LETTER_Q_UP;
            cout << ENDING << endl;
            break;
        default:
            break;
        }
    }

    // Program ending
    system("pause");
    return 0;
}

void ShowUsage()
{
    int welcomeLength = (WIDTH - WELCOME.length()) / 2;

    system("cls");

    // Header
    cout << left << setw(WIDTH) << setfill(ASTERISK_FILL) << ASTERISK_FILL << endl;
    cout << left << setw(welcomeLength) << setfill(ASTERISK_FILL) << ASTERISK_FILL;
    cout << WELCOME;
    cout << right << setw(welcomeLength) << setfill(ASTERISK_FILL) << ASTERISK_FILL;
    cout << endl;
    cout << left << setw(WIDTH) << setfill(ASTERISK_FILL) << ASTERISK_FILL << endl << endl;

    // Displaying user options
    cout << SHOW_LINE << endl;
    cout << PURCHASE_LINE << endl;
    cout << CURRENT_LINE << endl;
    cout << TOTAL_LINE << endl;
    cout << QUIT_LINE << endl;
    cout << endl;
}

// This function is used when the user picks the make purchase option in the console.
// This function uses Reference Parameters (int&) to change the original variables values when they are used in the Make Purchase function.
void MakePurchase(int& iTotalXXXS)
{
    // setting up varaibles for this function
    int numInput = 0;

    // Instuctes user on how to pick options 
    cout << PURCHASE_PROMPT;
    cin >> numInput;

    if (cin.good()) // checking if input is corretly inputed such as putting a number in an int.
    {
        iTotalXXXS = iTotalXXXS + numInput; 
    }
    else // program quits out if user did not corretly input a number into in num input.
    {
        cout << endl;
        exit(0);
    }
}

// Displays the ammout of surfboards are bought.
void DisplayPurchase(const int iTotalXXXS)
{
    
    if (iTotalXXXS > 0) // if there is somthing other than 0 in itotalSmall display dialog and amount
    {
        cout << DISPLAY_XXXS_AMOUNT << iTotalXXXS;
        cout << endl;
    }       
    else // If all parameters are at 0 display no purchases dialog
    {
        cout << NO_PURCHASES;
        cout << endl;
    }
}

// displays the amount is purchased and how much it will cost.
void DisplayTotal(const int iTotalXXXS)
{
    // setting up a variable to use to display total costs.
    double totalAmount = 0.0;
    double totalCostXXXS = 0.0;

    // converting iTotal from int to double for simplifying calculations.
    double dTotalXXXS = static_cast<double>(iTotalXXXS);

    // making all the total cost for each size. The
    totalCostXXXS = dTotalXXXS * XXXS_COST;


    // totaling the sum of all sized in a total amount add addtional if there were other sizes.
    totalAmount = totalCostXXXS;

    // checking if total amount has anything in it.
    if (totalAmount > 0)
    {
        // setting decmal point to show up to 2 decmials places
        cout << fixed << showpoint << setprecision(2);

        if (iTotalXXXS > 0) // display amount if iTotalXXXS is greater than a 0
        {
            cout << DISPLAY_XXXS_AMOUNT << iTotalXXXS << EMPTY_SPACE << TOTAL_AT << DOLLOR_SIGN << totalCostXXXS;
            cout << endl;
        }
        // display the total sum of all purchases.
        cout << AMOUNT_DUE << DOLLOR_SIGN << totalAmount;
    }
    else
    {
        cout << NO_PURCHASES;
    }
}

