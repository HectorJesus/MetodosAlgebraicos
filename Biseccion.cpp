#include <iostream>
#include <cmath>
#include <regex>
#include<sstream>
#define WTH "\e[97m"
#define RED "\e[91m"



using namespace std;
bool mensajeError=false;
bool XuMayorX1=true;
bool isMayor20;
bool ValidaIntervalo=true;


int k=1,aux, tam;
float imp[100];
bool coeficiente0=false;
bool ErrorMenor;
void imprimirTodo(int n, int impHasta);
void imprimeCiclo(int n);
bool validar(string aux, regex regex1);
void ResultadoadosGrado3(float P[], float xr, float errorP, int g);
void imprimirResultadoados(float P[], float xr, float errorP, int g);
bool evaluarResultadoado(float xr,int g, float P[]);
bool evaluarIntervalo(float x1, float xu,int g, float P[]);

//Para validar la entrada de numeros
regex numeros("(-)?([0-9]+)?(.)?([0-9]+)"),numIntPos("[1-9]([0-9]+)?"),numDecPos("([0-9]+)?(.)?[0-9]+");

int main(){

	string auxiliar;
	ErrorMenor = false;
	int g;
	float x1,xu,xr, xr_1;
	float errorP, PorcentajeError, rfinal;
	bool again, isCorrect=true;
	
	do{
	
	do{
		system("cls");
		cout<<WTH "\n   Metodo de Biseccion\n"<<endl;
		if(!isCorrect) cout<<RED "  Introduzca numeros enteros positivos"<<endl;
		else cout<<endl;
		cout<<endl;
		cout<<WTH "   Introduzca el grado del polinomio: ";
		cin>>auxiliar;
		isCorrect = validar(auxiliar, numIntPos);	
		
	}
	while(!isCorrect);
	istringstream(auxiliar)>>g;
	imp[0]=g;
	tam=1;
	float P[g];
	imprimirTodo(0,1);
	for(int i=0;i<=g;i++){
		do{
		do{
		cout<<WTH"   Introduzca el coeficiente de X^"<<i<<": ";
		cin>>auxiliar;
		isCorrect = validar(auxiliar, numeros);
		
		if(!isCorrect){
		mensajeError=true;
		imprimirTodo(i,2);
		
		}
		else mensajeError=false;
			
		
		
		}
		while(!isCorrect);
		
		istringstream(auxiliar)>>P[i];
		
		if(i==g){
			if(P[i]==0){
				coeficiente0=true;
				imprimirTodo(i,2);
			}
			else coeficiente0=false;
		}
		
		}
		while(coeficiente0);
		
		istringstream(auxiliar)>>P[i];
		imp[i+1]=P[i];
		tam++;
		aux=i;
		imprimirTodo(aux+1,2);
	}
	
	do{
		ValidaIntervalo=true;
	
	do{
		cout<<WTH"   Introduzca X1: ";
		cin>>auxiliar;
		isCorrect = validar(auxiliar, numeros);	
		if(!isCorrect){
			mensajeError=true;
			imprimirTodo(aux+1,2);
		}
		else mensajeError=false;
			
		
	}
	while(!isCorrect);
	istringstream(auxiliar)>>x1;
	imp[tam]=x1;
	
	imprimirTodo(aux+1,3);
	do{
		
	
	do{
		cout<<WTH"   Introduzca Xu: ";
		cin>>auxiliar;
		isCorrect = validar(auxiliar, numeros);
		if(!isCorrect){
			mensajeError=true;
			imprimirTodo(aux+1,3);
		}
		else mensajeError=false;
			
	}
	while(!isCorrect);
	istringstream(auxiliar)>>xu;
	if(x1>=xu){
		XuMayorX1=false;
		imprimirTodo(aux+1,3);
	}
	else XuMayorX1=true;
	}
	while(!XuMayorX1);
	ValidaIntervalo = evaluarIntervalo(x1,xu,g,P);
	
	if(!ValidaIntervalo){
		imprimirTodo(aux+1,2);
	}
	
	}
	while(!ValidaIntervalo);
	imp[tam+1]=xu;
	tam=tam+2;
	imprimirTodo(aux+1,4);
	
	do{	
	do{
		cout<<WTH"   Introduzca el Porcentajeaje de error que desea: ";
		cin>>auxiliar;
		isCorrect = validar(auxiliar, numDecPos);
		
		if(!isCorrect){
			mensajeError=true;
			imprimirTodo(aux+1,4);
		}
		else mensajeError=false;
			
	}
	while(!isCorrect);
	istringstream(auxiliar)>>PorcentajeError;
	
	if(PorcentajeError>20){
		isMayor20 = true;
		imprimirTodo(aux+1,4);
	}
	else isMayor20 = false;
	}
	while(isMayor20);
	imp[tam]=PorcentajeError;
	
	xr=(x1+xu)/2;
	
	float Resultadox1=P[0];
	float Resultadoxr=P[0];
	
	for(int i=1;i<=g;i++){
		Resultadox1 = P[i]*pow(x1,i) + Resultadox1;
    	Resultadoxr = P[i]*pow(xr,i) + Resultadoxr;
	}
	 rfinal = Resultadox1*Resultadoxr;

	
	if(rfinal == 0){
		if(Resultadox1==0){
			if(g>3)
			imprimirResultadoados(P,x1,0,g);
			else 
			ResultadoadosGrado3(P,x1,0,g);
		}
		else 
		{
		
		if(g>3)
			imprimirResultadoados(P,xr,0,g);
			else 
			ResultadoadosGrado3(P,xr,0,g);		
			}
	}
	else
	{
		
		if(rfinal>0) x1=xr;
		else xu=xr;
		
		
		
		do{
			xr_1=xr;
			xr=(x1+xu)/2;
			errorP = abs((xr-xr_1)/xr)*100;
			
			if(errorP>=PorcentajeError){
	
			ErrorMenor = false;
			Resultadox1=P[0];
			Resultadoxr=P[0];
			
			for(int i=1;i<=g;i++){
				Resultadox1 = P[i]*pow(x1,i) + Resultadox1;
    			Resultadoxr = P[i]*pow(xr,i) + Resultadoxr;
			}
			
			rfinal = Resultadox1*Resultadoxr;
			
			if(rfinal>0) x1=xr;
			
			else xu=xr;

			}
			else
			{

				if(g<=3)
				ResultadoadosGrado3(P,xr, errorP, g);
				
				else imprimirResultadoados(P,xr,errorP,g);

				ErrorMenor = true;

				
			}
			
			
		}while(!ErrorMenor);
	}
	
	cout<<WTH"   Quiere introducir otro polinomio? (S/N): ";
	char aux;
	cin>>aux;
	
	if(aux=='S'|| aux=='s') again= true;
	else again=false;
	
	}while(again);
	
	system("pause");
	return 0;
}


void imprimirTodo(int n, int impHasta){
	system("cls");
	cout<<WTH"\n   Metodo de Biseccion\n"<<endl;
	
	if(mensajeError)
		
		cout<<RED "   Por favor Introduzca solo numeros"<<endl;
		
	else if(!XuMayorX1)
	
		cout<<RED "   Por favor Introduzca un valor mayor a X1"<<endl;
		
	else if(isMayor20)
	
		cout<<RED "   Por favor Introduzca un Porcentajeaje de error mas bajo"<<endl;
		
	else if(!ValidaIntervalo)
	
		cout<<RED "   Por favor Introduzca un intervalo valido"<<endl;
		
	else if(coeficiente0)
	
		cout<<RED "   El coeficiente mas grande no puede ser cero"<<endl;
	
	else cout<<endl;
	

	cout<<endl;
	cout<<WTH"   Introduzca el grado del polinomio: "<<imp[0]<<endl;
	
	switch(impHasta){
		
		case 2:
			imprimeCiclo(n);
			break;
		case 3:
			imprimeCiclo(n);
			cout<<WTH"   Introduzca X1: "<<imp[k]<<endl;
			break;
		case 4:
			imprimeCiclo(n);
			cout<<WTH"   Introduzca X1: "<<imp[k]<<endl;
			cout<<WTH"   Introduzca Xu: "<<imp[k+1]<<endl;
			break;
		case 5:
			imprimeCiclo(n);
			cout<<WTH"   Introduzca X1: "<<imp[k]<<endl;
			cout<<WTH"   Introduzca Xu: "<<imp[k+1]<<endl;
			cout<<WTH"   Introduzca el Porcentajeaje de error que desea: "<<imp[k+2]<<endl;
			break;
			
	}
	
}

void imprimeCiclo(int n){
	
	
	k=1;
	for(int i=n;i>0;i--){
		cout<<WTH"   Introduzca el coeficiente de x^"<<k-1<<": "<<imp[k]<<endl;
		k++;
	}
	
}

bool validar(string aux, regex regex1){
	return regex_match(aux, regex1);
}

void ResultadoadosGrado3(float P[], float xr, float errorP, int g){
	system("cls");
	
	cout<<WTH "\n   Metodo de Bisecion\n"<<endl;
	
	for(int i=g;i>=0;i--)
	{
		if(i==g) cout<<"   ";
		
		if(i==3) {
			
		cout<<WTH<<P[i]<<"X\374";
		if(P[i-1]>=0) cout<<"+";
		}
		if(i==2){
			
		 cout<<WTH<<P[i]<<"X\375";
		 if(P[i-1]>=0) cout<<"+";
		 }
		 
		if(i==1){
			
			cout<<WTH<<P[i]<<"X";
			if(P[i-1]>=0) cout<<"+";
		} 
		if(i==0) cout<<WTH<<P[i]<<endl;
	}
	cout<<endl;
	if(evaluarResultadoado(xr,g,P)) errorP=0;
	cout<<WTH"   El valor de x es "<<xr<<" con error del "<<errorP<<"\45"<<endl;
	cout<<endl;
	
}


void imprimirResultadoados(float P[], float xr, float errorP, int g){
	system("cls");
	
	
	cout<<WTH "\n   Metodo de Bisecion\n"<<endl;
	
	for(int i=g;i>=0;i--){
		
		if(i==g) cout<<"   ";
		
		if(i!=0){
			cout<<WTH<<P[i]<<"X"<<i;
			if(P[i-1]>=0) cout<<"+";
		}
		if(i==0) cout<<WTH<<P[i]<<endl;
	}
	cout<<endl;
	cout<<WTH"   El valor de X es "<<xr<<" con error del "<<errorP<<"\45"<<endl;
	cout<<endl;	
}



bool evaluarIntervalo(float x1, float xu,int g, float P[]){
	float sumax1=P[0];
	float sumaxu=P[0];
	
	for(int i=1;i<=g;i++){
		
    	sumax1 = P[i]*pow(x1,i) + sumax1;
    	sumaxu = P[i]*pow(xu,i) + sumaxu;
	}
	
	if((sumaxu>=0&&sumax1<=0) || (sumaxu<=0&&sumax1>=0)) 
	return true;
	
	else return false;
	
}
bool evaluarResultadoado(float xr,int g, float P[]){
	float sumaxr=P[0];

	for(int i=1;i<=g;i++){
    	sumaxr = P[i]*pow(xr,i) + sumaxr;

	}
	if(sumaxr==0) return true;
	else return false;
}

