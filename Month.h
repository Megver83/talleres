#include <iostream>
using namespace std;

class Month {
    public:
        int weight;
        string name;
        Month* l = NULL;
        Month* r = NULL;

        // Constructor: inicializa weight y name
        Month(string);
        // Le resta 1 a weight
        void lowerWeight();

    private:
        string abc = "abcdefghijklmnopqrstuvwxyz";

        // Obtiene el peso en base a name
        int calculateWeight(string);
        // Retorna el índice de un char en abc, si está presente
        int getIndexOfChar(char);
};
