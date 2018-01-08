// Projet C++
// Ecollan Charles
// Ha David
//
// L'3 RPOMO 2019
// Groupe A
//
// variable.cpp

#include "variable.hpp"

Variable::Variable(const string& nom) : Expression(nom) { };





Variable::Variable(const string& nom, double init) : Expression(nom) {
    _memoire[_nom] = init;
}




double Variable::eval() const {
    return _memoire[_nom];
}




double Variable::set(double val) {
    _memoire[_nom] = val; return val;
}




map<string,double> Variable::_memoire = map<string,double>();




void Variable::effacerMemoire() {
    _memoire.clear();
}




Affectation::Affectation(Variable* var, Expression* exp) : Binaire("<-", var, exp) {}




double Affectation::eval() const {
    return ((Variable*)_opleft)->set(_opright->eval());
}










