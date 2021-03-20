#include<math.h>
#include<stdlib.h>
#include<stdio.h>


float funcao(float x,float *constantes,int n){ // retorna o y de f(x) = y
	
	int i = 0;
	float soma = 0;
	
	for( i = 0; i <= n ; i++){
		
		if( i == 0) soma = soma + ( pow(x,n) * constantes[i] );
		
		if( i == 1)	soma = soma + ( pow(x,n-1) * constantes[i] );
		
		if( i == 2)	soma = soma + ( pow(x,n-2) * constantes[i] );
		
		if( i == 3)	soma = soma + constantes[i];
		
	}
	
	
	return soma;
}


int verificaSinal(float x, float *constantes , int n) { // retorna 1 para positvo e 0 para negativo
	
	x = funcao( x, constantes, n);
	
	if(x<0) return 0;
	
	return 1;
	
}



float metodoBisseccao(float raiz, float a, float b, float erro, float erroAtual,float *constantes,int n,float valorCalc){
	
	float metadeDoIntervalo;  
	
	int sinalA;
	int sinalB;
	int sinalMetadeDoIntervalo;
	
	while(erroAtual > erro){
		
		
		metadeDoIntervalo = (a+b)/2;
	
		sinalA = verificaSinal(a,constantes,n);
		sinalB = verificaSinal(b,constantes,n);
		sinalMetadeDoIntervalo = verificaSinal(metadeDoIntervalo,constantes,n);
		
		if(erroAtual != 1000000000000 ) printf("A(Sinal) = %d  B(Sinal) = %d  N(a+b/2)(Sinal) = %d  f(n) = %f  Erro = %f\n",	sinalA,	sinalB,sinalMetadeDoIntervalo,funcao(metadeDoIntervalo,constantes,n),raiz-erroAtual);
		
		
		if( sinalA!= sinalMetadeDoIntervalo){
		
			erroAtual =  raiz - metadeDoIntervalo;
			b = metadeDoIntervalo;
	  	
		
		} 
		else{
			
			erroAtual =  raiz - metadeDoIntervalo;
			a = metadeDoIntervalo;

		} 
		
		if(erroAtual <0) erroAtual = erroAtual * (-1);
	}
	
	return raiz-erroAtual;
	
}

int main(){
	
	float a;
	float b;
	float c;
	float d;
	float erro;

	int i=0, grauDaFuncao = 4;
	printf("Fiz o programa, receber uma funcao como entrada, alem das informacoes necessarias para a bisseccao\n");
	printf("O programa consegue calcular funcoes de ate o 3 grau!!\n");
	printf("As funcoes devem ser escritas na forma: \n \t ax^3 + bx^2 + cx + d = 0 \n");
	printf("Logo, para escrever por exemplo x^2 - x, deve-se escrever: x^2 + -x");
	
	
	while(grauDaFuncao > 3 || grauDaFuncao < 1){
		
		printf("\n\nInforme o grau da sua funcao: ");
		scanf("%d",&grauDaFuncao);
		
		if(grauDaFuncao > 3 || grauDaFuncao < 1) printf("Valor invalido \n");
		
	}

	float raiz[grauDaFuncao];
	float constantes[grauDaFuncao +1];
	float valorEncontrado[grauDaFuncao];
	
	
	for(i = 0 ; i < grauDaFuncao + 1; i++){
		
		if( i == 0)	printf("Informe o valor de a: ");
		
		if( i == 1)	printf("Informe o valor de b: ");
		
		if( i == 2)	printf("Informe o valor de c: ");
		
		if( i == 3)	printf("Informe o valor de d: ");
		
		scanf("%f",&constantes[i]);	
		
		
	}
	
	
	funcao(-2,constantes,grauDaFuncao);
	
	for(i = 0 ; i < grauDaFuncao; i++){
		
		printf("Informe a %d raiz a ser encontrada: ",i+1);
		scanf("%f",&raiz[i]);
		
	}
	
	printf("Informe e o erro maximo permitido: ");
	scanf("%f",&erro);
		
	
	
	
	for( i = 0; i < grauDaFuncao; i++){
		
		printf("\nPara a %d raiz: \n\n",i+1);
		
		printf("Informe o valor 'a' do intervalo [a,b]: ");
		scanf("%f",&a);
	
		printf("Informe o valor 'b' do intervalo [a,b]: ");
		scanf("%f",&b);
		printf("\n");
		
		valorEncontrado[i] =  metodoBisseccao(raiz[i],a,b,erro,1000000000000,constantes,grauDaFuncao,0);
		printf("%d raiz encontrada = %f\n\n\n",i+1,valorEncontrado[i]);
		
	} 
	
	
	
}
