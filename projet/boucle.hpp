// Projet C++
// Ecollan Charles
// Ha David
//
// L'3 RPOMO 2019
// Groupe A
//
// boucle.hpp

#ifndef boucle_hpp
#define boucle_hpp

#include "variable.hpp"
#include <vector>

class Pour : public Expression {
protected:
    Expression *_init, *_condition, *_incremente, *_calcul;
public:
    Pour(Expression *init, Expression *cond, Expression *inc, Expression *calc);
    double eval() const;
    string str() const;
};




class Bloc : public Expression {
private:
    vector<Expression *> _bloc;
public:
    Bloc(vector<Expression *> &_bloc);
    double eval() const;
    string str() const;
};

#endif /* boucle_hpp */

