#include <iostream>
// Include the string header
#include <string>
using namespace std;
// Include the limits header for std::numeric_limits
// We researched this header and found it to be helpful for the user to know what the max and min values of the integer data type are
#include <limits> 

int main() {

    //declaring prototypes
    string caesarCipherRecursive(string cipherMessage, int shiftValue);
    void asciiArt();

    char willPlayAgain;
    string characterOptions[5] = {"Witch", "Vampire", "Ghost", "Bat", "Werewolf"};

    do {
        asciiArt();
         // Choose a character by the user
        std::cout << "\nChoose your character to help send your secret message:" << endl;

        //print out the 5 options for characters
        for(int i=1; i<= 5; i++) {
            cout << i << ". " << characterOptions[i-1] << endl;
        }

        // Get user input for choice with validation
        std::cout << "Enter the number of your character choice:" << endl;
        int choice;
        do {
            cin >> choice;

            // Check if the choice user is wrong and ask then put the right one
            if (choice < 1 || choice > 5) {
                std::cout << "Invalid choice! Please choose a number between 1 and 5." << endl;
            }
        } while (choice < 1 || choice > 5);

        // Display the selected character
        std::cout << "You chose: " << characterOptions[choice-1] << endl;

        // Clear the input buffer before taking string input
        // Makes the output wait for the getline input we ask for below.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Get message from user
        std::cout << "Enter your spooky message:" << endl;
        string message;
        getline(std::cin, message); // Use getline to read the entire line

        // Get shift value from user
        int shift;
        std::cout << "Enter the shift value:" << endl;
        std::cin >> shift;

        // Encode the message
        string encodedMessage = caesarCipherRecursive(message, shift);

        // Display the encoded message
        std::cout << "\nYour secret Halloween message is: " << encodedMessage << " "
                << std::endl;

        // Ask if the user wants to play again
        std::cout << "\nWould you like to play again? (y/n):" << std::endl;
        std::cin >> willPlayAgain;
    } while (willPlayAgain == 'Y' || willPlayAgain == 'y');

    // Ending Exit Message
    std::cout << "Thank you for using the Halloween Secret Message Service! See "
                "you soon!"
                << std::endl;
    return 0;
}


// Function to encode a message using Caesar Cipher
string caesarCipherRecursive(std::string message, int shift) {
  std::string encodedMessage = "";
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
    std::cout
        << "                                          ,          ^'^       _"
        << std::endl;
    std::cout << "                                               (             "
                 " (_) ^'^                                          )"
              << std::endl;
    std::cout << "          _/\\_                    .---------. ((        ^'^"
              << std::endl;
    std::cout
        << "          (('>                    )`'`'`'`'`( ||                "
        << std::endl;
    std::cout
        << "    _     /^|                    /`'`'`'`'`'`\\||           ^'^"
        << std::endl;
    std::cout << "     =>--/__|m---               /`'`'`'`'`'`'`\\|"
              << std::endl;
    std::cout << "          ^^                   /`'`'`'`'`'`'`'`\\"
              << std::endl;
    std::cout << "                      ,,,,,,, /`'`'`'`'`'`'`'`'`\\      '"
              << std::endl;
    std::cout << "                     .-------,`|```````````````|`  .   )"
              << std::endl;
    std::cout << "                    / .^. .^. \\|   ,^^, ,^^,   |  / \\ (("
              << std::endl;
    std::cout << "                   /  |_| |_|  \\   |__| |__|   | /,-,\\||"
              << std::endl;
    std::cout << "        __        /_____________\\  |*)| |  |   |/ |_| \\|"
              << std::endl;
    std::cout << "       ('')        |  __   __  |   '==' '=='   /_______\\    __"
              << std::endl;
    std::cout << "      ('  ')       | /  \\ /  \\ |    _______    |,^, ,^,|   ('')"
              << std::endl;
    std::cout << "       \\   \\       | |--| |--| |   ((--.--))   ||_| |_||  ('  ')"
              << std::endl;
    std::cout << "     _  ^^^^ _     | |__| |('| |   ||  |  ||   |,-, ,-,|  /   /"
              << std::endl;
    std::cout << "   ,' ',   ,' ',   |           |   ||  |  ||   ||_| |_||  ^^^^  "
              << std::endl;
    std::cout << ".,,|RIP|,.,|RIP|,.,'==========='===''=='==''==='=======',,....,,,,.,"
              << std::endl;
}
