#include "avl.h"

int height(Month* t)
{
    int h = 0;
    if (t != NULL) {
        int l_height = height(t->l);
        int r_height = height(t->r);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int difference(Month* t)
{
    int l_height = height(t->l);
    int r_height = height(t->r);
    int b_factor = l_height - r_height;
    return b_factor;
}

Month* rr_rotat(Month* parent)
{
    Month* t;
    t = parent->r;
    parent->r = t->l;
    t->l = parent;
    cout << "Right-Right Rotation" << endl;
    return t;
}

Month* ll_rotat(Month* parent)
{
    Month* t;
    t = parent->l;
    parent->l = t->r;
    t->r = parent;
    cout << "Left-Left Rotation" << endl;
    return t;
}


Month* lr_rotat(Month* parent)
{
    Month* t;
    t = parent->l;
    parent->l = rr_rotat(t);
    cout << "Left-Right Rotation" << endl;
    return ll_rotat(parent);
}

Month* rl_rotat(Month* parent)
{
    Month* t;
    t = parent->r;
    parent->r = ll_rotat(t);
    cout << "Right-Left Rotation" << endl;
    return rr_rotat(parent);
}

Month* balance(Month* t)
{
    // Calcula el factor de balance y hace la rotación correspondiente
    int bal_factor = difference(t);
    if (bal_factor > 1) {
        if (difference(t->l) > 0)
            t = ll_rotat(t);
        else
            t = lr_rotat(t);
    } else if (bal_factor < -1) {
        if (difference(t->r) > 0)
            t = rl_rotat(t);
        else
            t = rr_rotat(t);
    }
    return t;
}

Month* insert(Month* t, Month* p)
{
    // Peso del padre
    int v = p->weight;

    // Evalúa a que lado insertarlo
    if (v > t->weight) {
        if (p->l == NULL)
            p->l = t;
        else
            p->l = insert(t, p->l);
        p = balance(p);
    } else if (v < t->weight) {
        if (p->r == NULL)
            p->r = t;
        else
            p->r = insert(t, p->r);
        p = balance(p);
    }
    return p;
}

void inorder(Month* t)
{
    if (t == NULL)
        return;
    inorder(t->l);
    cout << t->weight << " ";
    inorder(t->r);
}

void preorder(Month* t)
{
    if (t == NULL)
        return;
    cout << t->weight << " ";
    preorder(t->l);
    preorder(t->r);
}

void postorder(Month* t)
{
    if (t == NULL)
        return;
    postorder(t->l);
    postorder(t->r);
    cout << t->weight << " ";
}

bool find(Month* t, int v)
{
    if (t != NULL) {
        bool l_weight = find(t->l, v);
        bool r_weight = find(t->r, v);
        if (t->weight == v || l_weight || r_weight)
            return true;
    }
    return false;
}
