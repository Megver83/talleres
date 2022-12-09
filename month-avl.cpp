#include "avl.h"

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

    // Crea la raíz del árbol
    Month* root = &enero;

    // Hace un array con el resto de meses para insertarlos con un for-each
    Month* meses[11] = {
        &febrero, &marzo, &abril, &mayo, &junio, &julio,
        &agosto, &septiembre, &octubre, &noviembre, &diciembre
    };

    // Hace la magia
    for(Month* m : meses) {
        cout << "Insertando " << m->name << " " << m->weight << endl;

        // Rebaja el peso en 1 mientras se encuentren coincidencias
        while(find(root, m->weight))
            m->lowerWeight();

        // Inserta el nodo
        root = insert(m, root);
        cout << endl;
    }

    // Imprime!
    cout << "In-order: ";
    inorder(root);
    cout << endl;
    cout << "Post-order: ";
    postorder(root);
    cout << endl;
    cout << "Pre-order: ";
    preorder(root);
    cout << endl;

    return 0;
}
