#include "operation.h"
#include <string>

void reduction_op(string equation){
	int temp=1,bgn;
	for(int i=0; i<equation.size(); i++){
		if((equation[i]=='+' || equation[i+1]=='-') && (equation[i]=='+' || equation[i+1]=='-')){
			bgn=i;
			while(equation[i]!='+' || equation[i]!='-'){
				if(equation[i]=='+')
					temp=temp*1;
				else
					temp=temp*-1;
				i++;		
			}
			if(temp%2==0){
				equation=equation.substr(0,bgn)+"+"+equation.substr(i,equation.size()-i);
			}
			else{
				equation=equation.substr(0,bgn)+"-"+equation.substr(i,equation.size()-i);
			}
		}

	}
}


Operation* Operation::buildFromEquation(string equation) {
	int level=0;
	size_t i=0;
	size_t pos_op;
	size_t pos_f=equation.size();
	char operation_t='0';

	

	for(int j=0;j<equation.size();j++){
		if(equation[j]=='(' && equation[pos_f-j]==')' ){
			i+=1;
			pos_f-=1;
		}
	}

	reduction_op(equation);

	for(i; i<pos_f; i++){
		if(equation[i]=='('){
			level+=1;	
		}

		if(equation[i]==')'){
			level-=1;	   
		}

		if( level==0 && isdigit(equation[i])==0 ){
			if(equation[i]=='+' || equation[i]=='-'){
				operation_t=equation[i];
				pos_op=i;
				break;
			}

			if(equation[i]=='*' || equation[i]=='/'){
				operation_t=equation[i];
				pos_op=i;
				continue;
			}

			if(equation[i]=='^'){
				operation_t=equation[i];
				pos_op=i;
			}
		}
	}
    
	switch(operation_t){
		
		case '+':
			return new addition(equation,pos_op);

		case '-':
			return new subtraction(equation,pos_op);

		case '*':
			return new multiplication(equation,pos_op);
			
		case '/':
			return new division(equation,pos_op);
			
		case '^':
			return new pow_t(equation,pos_op);
			
		default:
			return new constant_t(equation);
            
	}
}

