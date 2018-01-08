// Projet C++
// Ecollan Charles
// Ha David
//
// L'3 RPOMO 2019
// Groupe A
//
// binaire.hpp

#ifndef binaire_hpp
#define binaire_hpp

#include "expression.hpp"

class Binaire : public Expression {
protected:
    Expression *_opleft, *_opright;

public:
    Binaire(const string& nom, Expression* left, Expression* right);
    virtual double eval() const = 0;
    virtual string str() const;
};




class Somme : public Binaire {
public:
    Somme(Expression* left, Expression* right);
    double eval() const;
};


class Superieur : public Binaire {
public:
    Superieur(Expression* left, Expression* right);
    double eval() const;
};




// On ajoute la classe Produit
class Produit : public Binaire {
public:
    Produit(Expression* left, Expression* right);
    double eval() const;
};




// On ajoute la classe InferieurEgal
class InferieurEgal : public Binaire {
public:
    InferieurEgal(Expression* left, Expression* right);
    double eval() const;
};

#endif /* binaire_hpp */
