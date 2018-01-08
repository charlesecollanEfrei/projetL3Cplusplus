// Projet C++
// Ecollan Charles
// Ha David
//
// L'3 RPOMO 2019
// Groupe A
//
// conditionnel.cpp


#include "expression.hpp"
#include "conditionnel.hpp"
#include "binaire.hpp"

Conditionnel::Conditionnel(Binaire * cond, Expression * e1, Expression * e2) : Expression("(" + cond->str() + ") ? " + e1->str() + " : " + e2->str() + ")")
{
    _cond = cond;
    _e1 = e1;
    _e2 = e2;
}

double Conditionnel::eval() const{
    return (_cond->eval()) ? _e1->eval() : _e2->eval();
}
