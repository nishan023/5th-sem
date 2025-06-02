#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Permute bits according to a given table
string permute(const string &input, const vector<int> &table)
{
    string output = "";
    for (int i : table)
    {
        output += input[i - 1]; // -1 for 0-based indexing
    }
    return output;
}

// Left shift (rotation) by specified bits
string leftShift(const string &half, int shifts)
{
    return half.substr(shifts) + half.substr(0, shifts);
}

// Generate multiple subkeys
void generateSubKeys(const string &key10, int numKeys)
{
    vector<int> P10 = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    vector<int> P8 = {6, 3, 7, 4, 8, 5, 10, 9};

    // Step 1: P10
    string permutedKey = permute(key10, P10);

    // Split into left and right halves
    string left = permutedKey.substr(0, 5);
    string right = permutedKey.substr(5, 5);

    // Generate keys
    int totalShift = 0;
    for (int i = 1; i <= numKeys; i++)
    {
        // Shift increases per round: 1, then 2 more, then 2 more, etc.
        int shift = (i == 1) ? 1 : 2;
        totalShift += shift;

        string lshifted = leftShift(left, totalShift % 5);  // rotate within 5 bits
        string rshifted = leftShift(right, totalShift % 5); // rotate within 5 bits

        string combined = lshifted + rshifted;
        string subkey = permute(combined, P8);

        cout << "Subkey K" << i << ": " << subkey << endl;
    }
}

int main()
{
    string key10;
    int numKeys;

    cout << ("\n--------------------------------------\n");
    cout << ("*****DES Key Generation*****\n");
    cout << ("    Compiled By: Deepesh\n");
    cout << ("--------------------------------------\n\n");

    cout << "Enter a 10-bit key (e.g. 1010000010): ";
    cin >> key10;

    if (key10.length() != 10 || key10.find_first_not_of("01") != string::npos || key10[0] != '1')
    {
        cout << "Invalid key. Key must be 10 bits, all 0s and 1s, and start with 1." << endl;
        return 1;
    }

    cout << "How many subkeys do you want to generate? ";
    cin >> numKeys;

    if (numKeys <= 0)
    {
        cout << "Please enter a valid number greater than 0." << endl;
        return 1;
    }

    generateSubKeys(key10, numKeys);

    return 0;
}