#ifndef OPERATION_H
#define OPERATION_H

#include <string>
#include <cmath>
#include<stdlib.h>
using namespace std;

class Operation {

    protected:
        string equation;
        Operation* left;
		Operation* right;

    public:  
        static Operation* buildFromEquation(string equation);
        inline string name() { return equation; }
        virtual float operate() = 0;
};




class constant_t: public Operation{

public:
	
 
	constant_t(string equation_t){

		left=nullptr;
		right=nullptr;
		equation=equation_t;
		cout<<"se creo operando:"<<equation<<endl;
	}	
	float operate(){
		
		return std::stof(equation);
	}	
	
};

class addition: public Operation{

public:

	addition(string equation_t, size_t pos_op){
		equation=equation_t;
		cout<<"se creo suma"<<endl;
		left=buildFromEquation(equation.substr(0,pos_op));
		right=buildFromEquation(equation.substr(pos_op+1,equation.size()-(1+pos_op)));
	}	
	float operate(){

		return (left->operate()+right->operate());
	}	
	
};

class subtraction: public Operation{

public:

	subtraction(string equation_t, size_t pos_op){
		cout<<"se creo resta"<<endl;
		equation=equation_t;
		left=buildFromEquation(equation.substr(0,pos_op));
		right=buildFromEquation(equation.substr(pos_op+1,equation.size()-(1+pos_op)));
	}	
	float operate(){
		return (left->operate()-right->operate());
	}	
	
};

class multiplication: public Operation{

public:

	multiplication(string equation_t, size_t pos_op){
		cout<<"se creo multi"<<endl;
		equation=equation_t;
		left=buildFromEquation(equation.substr(0,pos_op));
		right=buildFromEquation(equation.substr(pos_op+1,equation.size()-(1+pos_op)));
	}	
	float operate(){
		return (left->operate()*right->operate());
	}	
	
};

class division: public Operation{

public:

	division(string equation_t, size_t pos_op){
		cout<<"se creo division"<<endl;
		equation=equation_t;
		left=buildFromEquation(equation.substr(0,pos_op));
		right=buildFromEquation(equation.substr(pos_op+1,equation.size()-(1+pos_op)));	
	}	
	float operate(){
		return (left->operate()/right->operate());
	}	
	
};

class pow_t: public Operation{

public:

	pow_t(string equation_t, size_t pos_op){
		cout<<"se creo power"<<endl;
		equation=equation_t;
		left=buildFromEquation(equation.substr(0,pos_op));
		right=buildFromEquation(equation.substr(pos_op+1,equation.size()-(1+pos_op)));
	}	
	float operate(){
		return (pow(left->operate(),right->operate()));
	}	
	
};


#endif


