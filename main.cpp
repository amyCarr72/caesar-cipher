#include <iostream>
// Include the string header
#include <string>
// We wanted to create a delay and we searched about it in google and found that
// the header <thread> and <chrono> are needed to have the delay Include for
// sleep_for function
#include <thread>
// Include for defining time durations
#include <chrono> 
using namespace std;

int main() {

    //declaring prototypes
    string caesarCipherRecursive(string cipherMessage, int shiftValue);
    void asciiArt();

    char willPlayAgain;
    string characterOptions[5] = {"Witch", "Vampire", "Ghost", "Bat", "Werewolf"};


    do {
        // Display a halloween-themed welcome message
        cout << "Welcome to the Halloween Secret Message Service!"<< endl;

        // Introduce a delay of 3 seconds before showing the ASCII art
        this_thread::sleep_for(chrono::seconds(2));

        // Display with some Halloween-themed ASCII art
        asciiArt();

         // Choose a character by the user
        cout << "\nChoose your character to help send your secret message:" << endl;

        //print out the 5 options for characters
        for(int i=1; i<= 5; i++) {
            cout << i << ". " << characterOptions[i-1] << endl;
        }

        // Get user input for choice with validation
        cout << "Enter the number of your character choice:" << endl;
        int choice;
        while (!(cin >> choice) ||  choice < 1 || choice > 5 ) {
            cout << "Invalid choice! Please choose a number between 1 and 5." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Display the selected character
        cout << "You chose: " << characterOptions[choice-1] << endl;

       // Clear the input buffer before taking string input
        cin.ignore();

        // Get message from user
        cout << "Enter your spooky message:" << endl;
        string message;
        getline(cin, message); // Use getline to read the entire line

        // Get shift value from user
        cout << "Enter the shift number:" << endl;
        int shift;
        while (!(cin >> shift)) {
            cout << "Please enter a number for your cipher!" << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Encode the message
        string encodedMessage = caesarCipherRecursive(message, shift);

        // Display the encoded message
        cout << "\nYour secret Halloween message is: " << encodedMessage << " "
                << endl;

        // Ask if the user wants to play again
        cout << "\nWould you like to play again? (y/n):" << endl;
        cin >> willPlayAgain;

    } while (willPlayAgain == 'Y' || willPlayAgain == 'y');

    // Ending Exit Message
    cout << "Thank you for using the Halloween Secret Message Service! See "
                "you soon!"
                << endl;
    return 0;
}


// Function to encode a message using Caesar Cipher
string caesarCipherRecursive(string message, int shift) {
  string encodedMessage = "";
  if (message.length() == 0) {
    return encodedMessage;
  }
  // perform the cipher shift operation
  // Take the first character from the message
  char ch = message[0];
  // Check if the character is alphabetic
  if (isalpha(ch)) {
    char base = islower(ch) ? 'a' : 'A';
    // To check lower or upper case to get base ascii value and shift value
    ch = (ch - base + shift) % 26 + base;
  }
  encodedMessage += ch;
  // Code of the remaining characters except the first one
  return encodedMessage + caesarCipherRecursive(message.substr(1), shift);
}


// Display with some Halloween-themed ASCII art
void asciiArt() {
    cout
        << "                                          ,          ^'^       _"
        << endl;
    cout << "                                               (             "
                 " (_) ^'^                                          )"
              << endl;
    cout << "          _/\\_                    .---------. ((        ^'^"
              << endl;
    cout
        << "          (('>                    )`'`'`'`'`( ||                "
        << endl;
    cout
        << "    _     /^|                    /`'`'`'`'`'`\\||           ^'^"
        << endl;
    cout << "     =>--/__|m---               /`'`'`'`'`'`'`\\|"
              << endl;
    cout << "          ^^                   /`'`'`'`'`'`'`'`\\"
              << endl;
    cout << "                      ,,,,,,, /`'`'`'`'`'`'`'`'`\\      '"
              << endl;
    cout << "                     .-------,`|```````````````|`  .   )"
              << endl;
    cout << "                    / .^. .^. \\|   ,^^, ,^^,   |  / \\ (("
              << endl;
    cout << "                   /  |_| |_|  \\   |__| |__|   | /,-,\\||"
              << endl;
    cout << "        __        /_____________\\  |*)| |  |   |/ |_| \\|"
              << endl;
    cout << "       ('')        |  __   __  |   '==' '=='   /_______\\    __"
              << endl;
    cout << "      ('  ')       | /  \\ /  \\ |    _______    |,^, ,^,|   ('')"
              << endl;
    cout << "       \\   \\       | |--| |--| |   ((--.--))   ||_| |_||  ('  ')"
              << endl;
    cout << "     _  ^^^^ _     | |__| |('| |   ||  |  ||   |,-, ,-,|  /   /"
              << endl;
    cout << "   ,' ',   ,' ',   |           |   ||  |  ||   ||_| |_||  ^^^^  "
              << endl;
    cout << ".,,|RIP|,.,|RIP|,.,'==========='===''=='==''==='=======',,....,,,,.,"
              << endl;
}
