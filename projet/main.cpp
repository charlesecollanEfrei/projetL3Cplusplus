// Projet C++
// Ecollan Charles
// Ha David
//
// L'3 RPOMO 2019
// Groupe A
//
// main.cpp

#include "boucle.hpp"
#include "conditionnel.hpp"
#include "variable.hpp"
#include "binaire.hpp"
#include "variable.hpp"
#include "expression.hpp"
#include <vector>
#include <fstream>


string lireFichier(string exp){
    ifstream F("expressions.txt");
    
    if(F){
        getline(F, exp);
        F.close();
    }
    
    return exp;
}



void exo1(){
    
    cout << "Premiere partie" << endl;
    Cos *c = new Cos(new Constante(M_PI/3.0));
    
    cout << *c << " = " << c->eval() << endl;
    
    Expression::toutLiberer();
    
}




void exo2(){
    
    cout << "Deuxieme partie" << endl;
    Somme *s = new Somme( new Constante(1.0),
                         new Produit(new Constante(2.0),
                                     new Sin(new Constante(M_PI/6.0))
                                     )
                         );
    cout << *s << " = " << s->eval() << endl;
    Superieur comp(s, new Constante(1.8));
    cout << comp << " = " << (bool)comp.eval() << endl;
    
   //Expression::toutLiberer();
    
}




void exo3(){
    
    cout << "Troisieme partie" << endl;
    Variable x("x", 3.0);
    Variable y("y");
    cout << x << " = " << x.eval() << endl;
    cout << y << " = " << y.eval() << endl;
    Expression *exp = new Somme( new Constante(1.0),
                                new Produit(new Constante(2.0), new Variable("x")));
    Affectation *a = new Affectation(new Variable("y"), exp);
    cout << *a << " = " << a->eval() << endl;
    cout << y << " = " << y.eval() << endl;
    Variable::effacerMemoire();
    cout << y << " = " << y.eval() << endl;
    
    //Expression::toutLiberer();

}




void exo4(){
    
    cout << "Quatrieme partie" << endl;
    Conditionnel *test =
    new Conditionnel(new InferieurEgal(new Variable("x"), new Constante(0.0)),
                     new Cos(new Variable("x")),
                     new Cos(new Produit(new Constante(2.0), new Variable("x"))));
    Variable *x = new Variable("x", M_PI/3.0);
    cout << *x << " = " << x->eval() << endl;
    cout << *test << " = " << test->eval() << endl;
    x->set( -M_PI/3.0);
    cout << *x << " = " << x->eval() << endl;
    cout << *test << " = " << test->eval() << endl;
    
    Variable::effacerMemoire();
    Expression::toutLiberer();
    
}




void exo5(){
 
    cout << "Cinquieme partie" << endl;
    
    Variable * x = new Variable("x", 1.0);
    Variable * i = new Variable("i", 1.0);
    InferieurEgal * inf = new InferieurEgal(x, new Constante(5.0));
    
    Pour * boucle = new Pour(i, inf, new Affectation(x, new Somme(x, new Constante(1.0))), new Affectation(i, new Produit(i,x)));
    cout << boucle->str() << endl;
    cout << boucle->eval() << endl;
    
    Variable::effacerMemoire();
    Expression::toutLiberer();
    
    
    cout << endl << "Cinquieme partie - Bloc" << endl;
     
    vector<Expression *> bloc;
    Variable * var = new Variable("x", 3);
    Constante * cons = new Constante(30);
    bloc.push_back(var);
    bloc.push_back(cons);
     
    Bloc * blocs = new Bloc(bloc);
    cout << blocs->str() << endl;
    cout << blocs->eval() << endl;
     
    Variable::effacerMemoire();
    Expression::toutLiberer();
    
}




int main(int argc, const char * argv[]) {

    cout << "Projet C++"<< endl;
    cout << "Charles Ecollan et David Ha"<< endl;
    cout << "L'3 Promo 2019 - Groupe A"<< endl;
    cout << endl;
    
    cout << endl;
    exo1();
    cout << endl;
    exo2();
    cout << endl;
    exo3();
    cout << endl;
    exo4();
    cout << endl;
    exo5();
    cout << endl;
    
    return 0;
}
