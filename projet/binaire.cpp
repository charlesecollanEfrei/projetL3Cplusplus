// Projet C++
// Ecollan Charles
// Ha David
//
// L'3 RPOMO 2019
// Groupe A
//
// binaire.cpp

#include "binaire.hpp"


Binaire::Binaire(const string& nom, Expression* left, Expression* right) : Expression(nom),
_opleft(left), _opright(right) {};




string Binaire::str() const {
    return "(" + _opleft->str() + " " + _nom + " " + _opright->str() + ")";
}




Somme::Somme(Expression* left, Expression* right) : Binaire("+", left, right) {}

double Somme::eval() const {
    return _opleft->eval() + _opright->eval();
}

Superieur::Superieur(Expression* left, Expression* right) : Binaire(">", left, right) {}




double Superieur::eval() const {
    return (double)(_opleft->eval() > _opright->eval());
}




Produit::Produit(Expression* left, Expression* right) : Binaire("*", left, right) {}




double Produit::eval() const{
    return _opleft->eval() * _opright->eval();
}




InferieurEgal::InferieurEgal(Expression* left, Expression* right) : Binaire("<=", left, right) {}




double InferieurEgal::eval() const{
    return (double)(_opleft->eval() <= _opright->eval());
}




