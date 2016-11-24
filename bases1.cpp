
#include <iostream>
#include <cmath>


//usamos los siguientes valores: sigma = 10, rho = 28, beta = 8/3

struct ecuaciones {
  double x0;
  double y0;
  double z0;
} ecuacion;

//ecuaciones diferenciales del sistema

double ff(double xx, double yy, double zz) {
  
  double ff = 10 * (yy - xx);
  return ff;
}

double gg(double xx, double yy, double zz) {

  double gg = xx* (28 - zz) - yy;
  return gg;
}

double hh(double xx, double yy, double zz) {
  double hh = xx*yy - zz*(8.0/3.0);
  return hh;
}

//función que calcula valores de rk4
void rk4(double x0, double y0,double z0, double step) {

  double k0 = step * ff(x0, y0, z0);
  double l0 = step * gg(x0, y0, z0);
  double m0 = step * hh(x0, y0, z0);
  double k1 = step * ff(x0 + 0.5*k0, y0 + 0.5*l0, z0 + 0.5*m0);
  double l1 = step * gg(x0 + 0.5*k0, y0 + 0.5*l0, z0 + 0.5*m0);
  double m1 = step * hh(x0 + 0.5*k0, y0 + 0.5*l0, z0 + 0.5*m0);
  double k2 = step * ff(x0 + 0.5*k1, y0 + 0.5*l1, z0 + 0.5*m1);
  double l2 = step * gg(x0 + 0.5*k1, y0 + 0.5*l1, z0 + 0.5*m1);
  double m2 = step * hh(x0 + 0.5*k1, y0 + 0.5*l1, z0 + 0.5*m1);
  double k3 = step * ff(x0 + k2, y0 + l2, z0 + m2);
  double l3 = step * gg(x0 + k2, y0 + l2, z0 + m2);
  double m3 = step * hh(x0 + k2, y0 + l2, z0 + m2);

  ecuacion.x0 += (1./6)*(k0 + 2*k1 + 2*k2 + k3);
  ecuacion.y0 += (1./6)*(l0 + 2*l1 + 2*l2 + l3);
  ecuacion.z0 += (1./6)*(m0 + 2*m1 + 2*m2 + m3);
 
}
  


int main(void) {
  //para modificar las condiciones iniciales, descomentar "+pow(10, 6)"
  
  ecuacion.x0 = 0;
  ecuacion.y0 = 1 //+pow(10, -6);
  ecuacion.z0 = 0;

  double step = 0.0001;
  
  for (double t=0 ; t < 50; t+=step) {
    rk4(ecuacion.x0, ecuacion.y0, ecuacion.z0, step);
    std::cout<< ecuacion.x0 << "\t" << ecuacion.y0 << ecuacion.z0 << "\n";

    //para imprimir datos de los planos (descomentar sólo una de las líneas):
    
    //std::cout << ecuacion.x0 << "\t" << ecuacion.y0 << "\n";
    //std::cout << ecuacion.x0 << "\t" << ecuacion.z0 << "\n";
    //std::cout << ecuacion.y0 << "\t" << ecuacion.z0 << "\n";

    //para imprimir Y en función de t
    
    //std::cout << t << "\t" << ecuacion.y0 << "\n"; 
  }  

  return 0;

}
