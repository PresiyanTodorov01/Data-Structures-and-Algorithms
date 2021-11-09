#include <iostream>
#include <string>


int check_letter_occurence(std::string& word, char letter){
    int occurences = 0;
    for(size_t i = 0; i < word.size(); i++){
        if(letter == word[i])
            occurences++;
    }

    return occurences;
}

void Mimi(std::string& word, int letters_to_write, char letter_searched){
    int occurences = check_letter_occurence(word, letter_searched);

    if(occurences == 0){
        std::cout << 0 << std::endl;
        return;
    }

    int times_letter_writen = (letters_to_write / int(word.size())) * occurences;

    for(int i = 0; i < letters_to_write % int(word.size()); i++){
        if(word[i] == letter_searched){
            times_letter_writen ++;
        }
    }

    std::cout << times_letter_writen << std::endl;



}

int main(){
    std::string word;
    std::cin >> word;

    int letters_to_write;
    std::cin >> letters_to_write;

    char letter_searched;
    std::cin >> letter_searched;

    Mimi(word, letters_to_write, letter_searched);

    return 0;


}
