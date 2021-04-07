#include <stdio.h>
#include <iostream>
#include "../headers/metaclasses.hpp"
#include "../headers/Dictionary.hpp"

using namespace std;

int main(int argc, char **argv) {

    // Initialize a dictionary
    Dictionary<string> Capitals;

    // Appending some capitals to the dictionary
    Capitals.Append("Russia", "Moscow");
    Capitals.Append("Great Britain", "London");
    Capitals.Append("Switzerland", "Bern");
    Capitals.Append("Finland", "Helsinki");
    Capitals.Append("Poland", "Warsaw");
    Capitals.Append("Sweden", "Stockholm");

    // Basic examples of using the dictionary
    cout << "The capital of Sweden is: " << Capitals["Sweden"] << endl;
    cout << "The capital of Russia is: " << Capitals["Russia"] << endl;
    cout << "There are " << Capitals.Length() << " capitals currently in the dictionary" << endl;

    cout << "Listing all of the capitals present in the dictionary:" << endl;
    for (auto i = 0; i < Capitals.Length(); i++)
        cout << Capitals[i] << endl;

    return 0;
}