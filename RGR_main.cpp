#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std; 
// task 1
void task1();
string decimalToBinary(int decimal);
int binaryToDecimal(const std::string &binary);
// task 2
void task2();
string decimalToHex(int decimal);
int hexToDecimal(const std::string& hexStr);
string hexToBinary(const string& hexStr);
// task 3
void task3();
string DecTo7(int D);
// task 4
void task4();
string binaryAddition(const string &a, const string &b);
// menu
int main () { 
    cout << " " << endl;
    int task_num;  // diclaration
    do {
        cout << " Task number (0 - exit):  ";
        cin >> task_num;
        if (!cin) {
            cout << " Ups!" << endl; continue;
            // error notification
        }
        switch (task_num) {
            case 1 : task1(); break; // task 1
            case 2 : task2(); break; // task 2
            case 3 : task3(); break; // task 3
            case 4 : task4(); break; // task 4
            case 0 : cout << " The program is over!" << endl; break;
            default : cout << " Wrong task number!" << endl;
            // output for incorrect numbers
        }
    } while (task_num != 0); // end the program
    return 0;
}
// task 1
void task1(){
    cout << " ### Task 1 ### " << endl;
    int num1 = 125;
    int num2 = 2000;

    // converting decimal numbers to binary
    string binary1 = decimalToBinary(num1);
    string binary2 = decimalToBinary(num2);

    // output of conversion results
    cout << " Decimal number: " << num1 << " --> Binary number: " << binary1 << endl;
    cout << " Decimal number: " << num2 << " --> Binary number: " << binary2 << endl;

    // converting binary numbers back to decimal
    int reversedDecimal1 = binaryToDecimal(binary1);
    int reversedDecimal2 = binaryToDecimal(binary2);

    // outputting the results of the inverse conversion
    cout << " Binary number: " << binary1 << " --> Decimal number: " << reversedDecimal1 << endl;
    cout << " Binary number: " << binary2 << " --> Decimal number: " << reversedDecimal2 << endl;

    return;
}
// converting decimal numbers to binary
string decimalToBinary(int decimal) {
    string binary = "";
    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}
// converting binary numbers to decimal
int binaryToDecimal(const string &binary) {
    int num = 0;
    int length = binary.length();
    for (int i = 0; i < length; ++i) {
        if (binary[length - i - 1] == '1') {
            num += pow(2, i);
        }
    }
    return num;
}
// task 2
void task2(){
    cout << " ### Task 2 ### " << endl;
    int num1 = 125;
    int num2 = 2000;

    // converting decimal numbers to hexadecimal
    string hex1 = decimalToHex(num1);
    string hex2 = decimalToHex(num2);

    // output of results
    cout << " Decimal number: " << num1 << " --> Hexadecimal number: " << hex1 << endl;
    cout << " Decimal number: " << num2 << " --> Hexadecimal number: " << hex2 << endl;

    // converting hexadecimal numbers back to decimal
    int dec1 = hexToDecimal(hex1);
    int dec2 = hexToDecimal(hex2);

    // outputting the results of the inverse conversion
    cout << " Hexadecimal number: " << hex1 << " --> Decimal number: " << dec1 << endl;
    cout << " Hexadecimal number: " << hex2 << " --> Decimal number: " << dec2 << endl;

    // converting hexadecimal numbers to binary
    string hexBinary1 = hexToBinary(hex1);
    string hexBinary2 = hexToBinary(hex2);

    // outputting binary conversions
    cout << " Hexadecimal number: " << hex1 << " --> Binary number: " << hexBinary1 << endl;
    cout << " Hexadecimal number: " << hex2 << " --> Binary number: " << hexBinary2 << endl;

    return;
}

// converting decimal numbers to hexadecimal
string decimalToHex(int decimal) {
    stringstream ss;
    ss << hex << decimal;
    string hexStr = ss.str();
    for (char &c : hexStr) {
        if (c >= 'a' && c <= 'f') {
            c = toupper(c);
        }
    }
    return hexStr;
}
// converting hexadecimal numbers to decimal
int hexToDecimal(const std::string& hexStr) {
    int decimal;
    stringstream ss;
    ss << hex << hexStr;
    ss >> decimal;
    return decimal;
}

// converting hexadecimal numbers to binary
string hexToBinary(const string& hexStr) {
    int decimal = hexToDecimal(hexStr);
    return decimalToBinary(decimal);
}
// task 3
void task3(){
    cout << " Task 3 " << endl;
    int number;
    cout << " Decimal number: ";
    cin >> number;
    // converting decimal numbers to septal
    cout << " Septal number: " << DecTo7(number) << endl;

    return;
}
// converting decimal numbers to septal
string DecTo7(int D) {
    string result = "";
    if (D > 0) {
        int remainder = D % 7;
        result = to_string(remainder) + result;
        D /= 7;
    }
    else {
        cout << "number must be higher than 0! " << endl;
    }
    return result;
}
// task 4
void task4(){
    cout << " Task 4 " << endl;
    int num1 = 125;
    int num2 = 2000;
    // converting decimal numbers to binary
    string binaryNum1 = decimalToBinary(num1);
    string binaryNum2 = decimalToBinary(num2);
    // adding two double numbers
    string binarySum = binaryAddition(binaryNum1, binaryNum2);
    // translation of the result into a dozen system for verification
    int decimalSum = binaryToDecimal(binarySum);
    // output of results
    cout << "Перше число (у двійковій системі): " << binaryNum1 << endl;
    cout << "Друге число (у двійковій системі): " << binaryNum2 << endl;
    cout << "Результат додавання (у двійковій системі): " << binarySum << endl;
    cout << "Результат додавання (у десятковій системі): " << decimalSum << endl;

    return;
}
// sum calculation
string binaryAddition(const string &a, const string &b) {
    string result = "";
    int carry = 0;
    // equalize the length of the lines by adding leading zeros to the shorter line
    string bin1 = a.size() > b.size() ? a : string(b.size() - a.size(), '0') + a;
    string bin2 = b.size() > a.size() ? b : string(a.size() - b.size(), '0') + b;
    // add bit by bit from right to left
    for (int i = bin1.size() - 1; i >= 0; --i) {
        int sum = (bin1[i] - '0') + (bin2[i] - '0') + carry;
        result = to_string(sum % 2) + result;
        carry = sum / 2;
    }
    // if there is a carryover left, we add it
    if (carry) {
        result = "1" + result;
    }
    return result;
}
