#include <iostream>
#include <string>
using namespace std;

int countVokal(string sentence) {
    int count = 0;
    for (char c : sentence) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    int result = countVokal(sentence);
    std::cout << "Banyaknya huruf vokal : " << result << endl;
    return 0;
}