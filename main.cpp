#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

class word_counter {
private:
    std::vector<unsigned char> splt_function(const std::string& word);
    std::vector<std::pair<unsigned char, unsigned int>> countr_function(const std::vector<unsigned char>& charList);
    
public:
    void print_function(const std::string& word);
};

// Splits the string into a vector of unsigned chars
std::vector<unsigned char> word_counter::splt_function(const std::string& word) {
    return std::vector<unsigned char>(word.begin(), word.end());
}

// Counts the frequency of each character
std::vector<std::pair<unsigned char, unsigned int>> word_counter::countr_function(const std::vector<unsigned char>& charList) {
    std::unordered_map<unsigned char, unsigned int> freqMap;

    for (auto ch : charList) {
        freqMap[ch]++;
    }

    std::vector<std::pair<unsigned char, unsigned int>> countList;
    for (const auto& pair : freqMap) {
        countList.push_back(pair);
    }

    return countList;
}

// Prints each character and its count
void word_counter::print_function(const std::string& word) {
    std::vector<unsigned char> c_char = splt_function(word);
    for (const auto& pair : countr_function(c_char)) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
}

// Entry point
int main() {
    std::string word;
    std::cin >> word;

    word_counter count;
    count.print_function(word);

    return 0;
}

