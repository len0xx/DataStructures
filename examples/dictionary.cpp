#include <iostream>
#include "Dictionary.hpp"

using namespace std;

int main(int argc, char **argv) {
    // Initialize a dictionary
    Dictionary<string> Capitals;

    // Appending some capitals to the dictionary
    Capitals.append("Russia", "Moscow");
    Capitals.append("Great Britain", "London");
    Capitals.append("Switzerland", "Bern");
    Capitals.append("Finland", "Helsinki");
    Capitals.append("Poland", "Warsaw");
    Capitals.append("Sweden", "Stockholm");

    // Basic examples of using the dictionary
    cout << "The capital of Sweden is: " << Capitals["Sweden"] << endl;
    cout << "The capital of Russia is: " << Capitals["Russia"] << endl;
    cout << "There are " << Capitals.length() << " capitals currently in the dictionary" << endl;

    cout << "Listing all of the capitals present in the dictionary:" << endl;
    for (auto i = 0; i < Capitals.length(); i++)
        cout << Capitals[i] << endl;

    return 0;
}