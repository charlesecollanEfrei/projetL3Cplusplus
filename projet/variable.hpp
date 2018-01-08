// Projet C++
// Ecollan Charles
// Ha David
//
// L'3 RPOMO 2019
// Groupe A
//
// variable.hpp

#ifndef variable_hpp
#define variable_hpp

#include "binaire.hpp"


class Variable : public Expression {
public:
    Variable(const string& nom);
    Variable(const string& nom, double init);
    
    /* retourne la valeur de la variable dont le nom est dans _nom
     si _nom n'est pas trouve dans _memoire alors une nouvelle variable
     est cree avec la valeur 0.0 qui est retournee */
    double eval() const;
    double set(double val);

private:
    /*ensemble des variable sous la forme d'un tableau
     associatif : la cle est le nom de la variable stockee */
    static map<string,double> _memoire;

public:
    /* vide completement le tableau associatif _memoire */
    static void effacerMemoire();
};




class Affectation : public Binaire {
public:
    Affectation(Variable* var, Expression* exp);
    double eval() const;
};

#endif /* variable_hpp */
