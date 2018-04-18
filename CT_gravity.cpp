#include<iostream> 
#include <cstdlib>
#include <ctime>
	
	
	
using namespace std;
// se definen las funciones
void runge_kutta( int t, double A, double B, double h);	
double vel(double v,double t, double x);
double posicion(double v, double t, double x);
	

	
int main()
	
{ 
	
//las condiciones iniciales 
	
double m=10;
double x_in=20;
double v_in=3;
double h=0.1;
	

	
runge_kutta(0.0,x_in,v_in,h);
	
return 0;
	
	
}
	
//Funcion que establece la de velocidad
	
double vel(double x)
	
{ 
	

	
double G=10;
	
double M=1000;	
	
double velocity=  -G * M / (x*x);
	
return velocity;
	
}
	
// funcion de posicion
	
double posicion( double v)
	
{
	
return v;
	
}
	
////ecuaciones diferenciales segundo orden
	
void runge_kutta(int t, double A, double B, double h)
	
{
	

	
double dist_max=0.01*t; double a=t; double v=B; double y=A;
	

	
cout << y << " " << v << " " << t << endl;
	
//
	
double RG1;
double RG2;
double RG3;
double RG4; 
double k1;
double k2;
double k3;
double k4;
	

bool distmax=true;
	
//Ciclo calcula variacion
	
while(distmax)
	
{
	
	
	
//variables de Runge-Kutta para las variables de posicion y velocidad

t=t+h;

double ya= v + ( h * k3 );
double va = y + (h/2.0) ;
	
RG1=vel( y ); k1=posicion( v );
	
	
RG2=vel( y + (h/2.0) ); k2=posicion( v + ( ( h * k1 ) / 2.0) );
	
	
RG3=vel(va); k3=posicion( v + ( ( h * k2 ) / 2.0) );
	
	
RG4=vel( y + h ); k4=posicion(  ya);
	
double ye =h/6.0 * ( k1+k4+( 2 * k2)+( 2 * k3 ));
	
y=y+(ye);

double yo =  h/6.0 * ( RG1+RG4+( 2 * RG2)+( 2 * RG3 )) ;

v=v+(yo);
	
	
if(y>distmax)
	
{
	
cout << y << " " << v << " " << t << endl;
	
}
	
	
else
	
{
	
distmax=false;
	
}
	
}
	
	
}
