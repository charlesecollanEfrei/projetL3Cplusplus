// Projet C++
// Ecollan Charles
// Ha David
//
// L'3 RPOMO 2019
// Groupe A
//
// boucle.cpp

#include "boucle.hpp"


Pour::Pour(Expression *init, Expression *cond, Expression *inc, Expression *calc) :
Expression("for"), _init(init), _condition(cond), _incremente(inc), _calcul(calc) {}




double Pour::eval() const {
    double res = 0;
    _init->eval();
    while (_condition->eval() != 0.0) {
        res = _calcul->eval();
        _incremente->eval();
    }
    return res;
}


string Pour::str() const {
    return _nom + " (" + _init->str() + " ; " + _condition->str() + " ; "
    + _incremente->str() + ") { " + _calcul->str() + " }";
}




Bloc::Bloc(vector<Expression *> &_bloc) : Expression("Bloc"), _bloc(_bloc){}




double Bloc::eval() const {
    double res = 0.0;
    
    for(int i = 0; i < _bloc.size(); i++) {
        res = _bloc[i]->eval();
    }
    
    return res;
}




string Bloc::str() const {
    string res = "";
    
    for(int i = 0; i < _bloc.size(); i++) {
        res += _bloc[i]->str() + "\n";
    }
    
    return res;
}




