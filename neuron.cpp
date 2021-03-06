#include <iostream>
#include "neurone.h"
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;


Neuron :: Neuron () // tableau initialise vide donc taille 0
        {
			 V=10;
			 C=1; 
			 R=20;
			 Nb_Spikes_=0; 
		}
         
vector<double> Neuron :: getT() const
{ 
	return T;
}

void Neuron :: setT(vector<double> t)			
{ 		
	T=t;	
}		

double Neuron :: getV() const
{ 
	return V;
}

int Neuron :: getNb_Spikes_() const
{ 
	return Nb_Spikes_;
}	
	
double Neuron :: getC() const
{ 
	return C;	
}

void Neuron :: setV(double v)
{
	V=v;
}	

void Neuron :: setNb_Spikes_()
{
	Nb_Spikes_=Nb_Spikes_ + 1; 
}		

void Neuron :: setC(double c)
{
	C=c;
}

bool Neuron:: IsNeuron_refractory(double Vth)
{
	if (V>Vth)
	{
		return true;
	}
	else return false;	
	
}

void Neuron :: fill_T(double t)
{
	T.push_back(t);
}	
	

void Neuron :: update(double I)
{
	
	double h(1);
	double V_update;
	V_update=exp(-h/(R*C))*V + I*R*(1-exp(-h/(R*C)));// updates the neuron state from time t to t+T ou T=n*h qvec n nbre de step
	V=V_update;
	
 }                                                                                                            
	
void Neuron :: update_connection(double I, double J)
{
	update(I);
	V += J;
	
	
	
} 
