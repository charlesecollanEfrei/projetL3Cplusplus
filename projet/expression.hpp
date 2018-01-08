// Projet C++
// Ecollan Charles
// Ha David
//
// L'3 RPOMO 2019
// Groupe A
//
// expression.hpp

#ifndef expression_hpp
#define expression_hpp

#include <stdio.h>


#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <map>
#include <set>

using namespace std;

/* retourne une valeur reelle (val) sous forme de chaine de caracteres */
extern string string_from_double(double val);

class Expression {
protected:
    string _nom;

private:
    static set<Expression*> _pool;

public:
    /* applique itérativement l'operateur delete au premier element
     du pool tant que le pool n’est pas vide */
    static void toutLiberer();

public:
    Expression(const string& nom);
    virtual ~Expression();
    virtual double eval() const = 0;
    virtual string str() const;
    friend ostream& operator<<(ostream& os, const Expression& exp);
};




class Constante : public Expression {
    double _value;

public:
    Constante(double val);
    virtual double eval() const;
};




class Unaire : public Expression {
protected:
    Expression *_op;

public:
    Unaire(const string& nom, Expression* op);
    virtual double eval() const = 0;
    virtual string str() const;
};




class Cos : public Unaire {
public:
    Cos(Expression* op);
    double eval() const;
};




class Sin : public Unaire {
public:
    Sin(Expression* op);
    double eval() const;
};


#endif /* expression_hpp */
