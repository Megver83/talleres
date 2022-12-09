#include "Month.h"

Month::Month(string month_name) {
    name = month_name;
    weight = calculateWeight(month_name);
}

void Month::lowerWeight() {
    weight -= 1;
}

int Month::calculateWeight(string month_name) {
            int size = 0;
            int index;
            for(char letter : month_name) {
                // La convierte en minúscula, por si acaso
                letter = tolower(letter);
                index = getIndexOfChar(letter);

                // Se ignoran caracteres que no estén en el abecedario inglés
                if(index >= 0)
                    size += index + 1;
            }
            return size;
        }

int Month::getIndexOfChar(char c) {
    for(int i = 0; i < 26; i++) {
        if(c == abc[i]) return i;
    }
    return -1;
}
