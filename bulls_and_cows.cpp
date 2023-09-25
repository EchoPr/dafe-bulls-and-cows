#include <iostream>
#include <vector>

int count(const std::vector<char> digits, char d){
    int x = 0;
    for (int i = 0; i < digits.size(); i++){
        if (digits[i] == d)
            x++;
    }

    return x;
}

void validate(const std::vector<char> number){
    for (int i = 0; i < number.size(); i++){
        if (number[i] < '0' || number[i] > '9')
            throw std::runtime_error("The number contains not digits");

        if (count(number, number[i]) != 1){
            throw std::runtime_error("Digits are not unique");
        }
    }
}

std::vector<char> user_guess(){
    std::vector<char> number(4);
    std::cout << "Guess the number: ";

    for (int i = 0; i < number.size(); i++){
        std::cin >> number[i];
    }

    if (!std::cin){
        throw std::runtime_error("Invalid input");
    }

    validate(number);
    return number;
}


int main(){
try{
    std::cout << "Bullst and Cows the game." << std::endl;

    std::vector<char> num{'1', '3', '7', '2'};

    int bulls, cows;

    do{
        bulls = cows = 0;
        std::vector<char> guess = user_guess();

        for (int i = 0; i < num.size(); i++){
            if (guess[i] == num[i])
                bulls++;
            else if (count(guess, guess[i]) == 1)
                cows++;

        }while(bulls != 4)

        std::cout << bulls << " bull(s) and " << cows << " cows" << endl;
    }
}

catch (std::exception& e){
    std::cerr << e.what() << std::endl;
    return 1;
}

catch (...){
    std::cerr << "Unknown error" << std::endl;
    return 1;
}
}
