#include <iostream>
using namespace std;

class Month {
    public:
        int weight;
        string name;

        Month(string month_name) {
            name = month_name;
            weight = calculateWeight(month_name);
        }

    private:
        string abc = "abcdefghijklmnopqrstuvwxyz";

        int calculateWeight(string month_name) {
            int size = 0;
            int index;
            for(char letter : month_name) {
                // La convierte en minúscula, por si acaso
                letter = tolower(letter);
                index = getIndexOfChar(letter);

                // Se ignoran caracteres que no estén en el abecedario inglés
                if(index > -1)
                    size += index + 1;
            }
            return size;
        }

        int getIndexOfChar(char c) {
            for(int i = 0; i < 26; i++) {
                if(c == abc[i]) return i;
            }
            return -1;
        }
};

int main() {
    // Crea los meses del año
    Month enero("Enero");
    Month febrero("Febrero");
    Month marzo("Marzo");
    Month abril("Abril");
    Month mayo("Mayo");
    Month junio("Junio");
    Month julio("Julio");
    Month agosto("Agosto");
    Month septiembre("Septiembre");
    Month octubre("Octubre");
    Month noviembre("Noviembre");
    Month diciembre("Diciembre");

    Month meses[12] = {enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre, noviembre, diciembre};
    for(Month mes : meses) cout << mes.name << " " << mes.weight << endl;

    return 0;
}
