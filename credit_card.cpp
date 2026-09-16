
#include <iostream>

// Return this number if it is a single digit, otherwise, return the sum of the two digits
int getDigit(int number) {
    if (number < 10) {
        return number;
    }
}

// Return sum of odd place digits in number (1st, 3rd, 5th, ... from right to left)
int sumOfOddPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 100; // Skip the even place digit
    }
    return sum;
}

// Get the result from Step 2 (doubling every second digit from right to left)
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    number /= 10; // Move to the second digit from right (1st even-place digit)
    while (number > 0) {
        int digit = (number % 10) * 2;
        sum += getDigit(digit);
        number /= 100; // Skip the next odd place digit
    }
    return sum;
}

// Return the number of digits in d
int getSize(long long d) {
    int count = 0;
    while (d > 0) {
        count++;
        d /= 10;
    }
    return count;
}

// Return the first k number of digits from number. 
// If the number of digits in number is less than k, return number.
long long getPrefix(long long number, int k) {
    int size = getSize(number);
    if (size <= k) {
        return number;
    }
    
    for (int i = 0; i < size - k; i++) {
        number /= 10;
    }
    return number;
}

// Return true if the digit d is a prefix for number
bool prefixMatched(long long number, int d) {
    int prefixLength = getSize(d);
    return getPrefix(number, prefixLength) == d;
}

// Return true if the card number is valid
bool isValid(long long number) {
    int size = getSize(number);
    
    // Check digit length requirement (13 to 16 digits)
    if (size < 13 || size > 16) {
        return false;
    }
    
    // Check valid card prefix (4, 5, 37, 6)
    bool validPrefix = prefixMatched(number, 4) || 
                        prefixMatched(number, 5) || 
                        prefixMatched(number, 37) || 
                        prefixMatched(number, 6);
                        
    if (!validPrefix) {
        return false;
    }
    
    // Perform Luhn check (Steps 1-5)
    int totalSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return (totalSum % 10 == 0);
}

int main() {
    long long creditCardNumber;
    
    std::cout << "Enter a credit card number as a long integer: ";
    std::cin >> creditCardNumber;
    
    if (isValid(creditCardNumber)) {
        std::cout << creditCardNumber << " is valid" << std::endl;
    } else {
        std::cout << creditCardNumber << " is invalid" << std::endl;
    }

    return 0;
}