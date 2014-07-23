#include <stdio.h>

int main()
{
	int op1, op2, result;
	char operand;
	int error = 0;

	scanf("%d", &op1);
	result = op1;
	while(1){
		scanf("%c", &operand);
		if(operand == '='){
			break;
		}
		scanf("%d", &op2);
		switch(operand){
			case '+':
				result += op2;
				break;
			case '-':
				result -= op2;
				break;
			case '*':
				result *= op2;
				break;
			case '/':
				if(op2 == 0){
					error = 1;
					break;
				}
				result /= op2;
				break;
			default:
				error = 1;
				break;
		}
	}
	if(error){
		printf("ERROR\n");
	}
	else{
		printf("%d\n", result);
	}

	return 0;
}