import numpy as np #Hara los calculos
import sympy as sym #Desarolla la forma algebraica del polinomio

print('Ingrese el tamaño de la muestra')
muestra = input()




#Ingresamos los datos
xi = np.array([1, 2, 9])
fi = np.array([7, 8, 5])

a = len(xi) #Calculamos los elementos dentro de la variable xi
b = len(fi) #Calculamos los elementos dentro de la variable fi

if a!=b:
    print('El tamaño de los arreglos no es equitativo')
    exit()

x = sym.Symbol('x') #Variable x
polinomio = 0

for i in range(0,a,1):
    numerador = 1
    denominador = 1
    for j in range (0,a,1):
        if (i!=j): #Verifica que no se uise el punto de referencia
            numerador = numerador*(x-xi[j]) #Calculamos el n´esimo termino de Lk(x)
            denominador = denominador*(xi[i]-xi[j]) #Calculamos el n´esimo termino de Lk(xk)
        termino = (numerador/denominador)*fi[i]
    polinomio= polinomio + termino
polisimple = sym.expand(polinomio) #Expandimos la exprecion matematica en forma de variable

print('Valor de y()?:') 
y = input()
#Sustituimos el valor de x en el polinomio simplificado
resultado = polisimple.subs(x,y) 

print('Polinomio:')
print(polinomio)
print('Polinomio simplificado:')
print(polisimple)
print('Resultado:')
print(resultado)