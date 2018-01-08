// Projet C++
// Ecollan Charles
// Ha David
//
// L'3 RPOMO 2019
// Groupe A
//
// expression.cpp

#include "expression.hpp"

/* retourne une valeur reelle (val) sous forme de chaine de caracteres */
string string_from_double(double val) {
    ostringstream os;
    os << val;
    return os.str();
}




set<Expression*> Expression::_pool = set<Expression*>();




Expression::Expression(const string& nom) : _nom(nom) {
    _pool.insert(this);
    //cout << "enregistrer " << _nom << endl;
}





void Expression::toutLiberer() {
    set<Expression*>::iterator it;
    while ( (it = _pool.begin()) != _pool.end())
        delete (*it);
}





string Expression::str() const { return _nom; }




Expression::~Expression() {
    _pool.erase(this);
    //cout << "liberer " << _nom << endl;
}




ostream& operator<<(ostream& os, const Expression& exp) {
    return os << exp.str();
}




Constante::Constante(double val) : Expression(string_from_double(val)), _value(val) {}




double Constante::eval() const {
    return _value;
}




Unaire::Unaire(const string& nom, Expression* op) : Expression(nom), _op(op) {}




string Unaire::str() const {
    return _nom + "(" + _op->str() + ")";
}




Cos::Cos(Expression* op) : Unaire("cos", op) {}




double Cos::eval() const {
    return cos(_op->eval());
}




Sin::Sin(Expression* op) : Unaire("sin", op) {}




double Sin::eval() const {
    return sin(_op->eval());
}




