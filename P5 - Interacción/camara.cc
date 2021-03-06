#include "camara.h"

Camara::Camara(){
  avanceAlzado = avanceDcha = avancePlanta = 10;
  avanceIzda = -10;
  giroAlzado = giroIzda = giroDcha = giroPlanta = 0;
}

void Camara::setEye(float uno, float dos, float tres){
  this->eye.x = uno;
  this->eye.y = dos;
  this->eye.z = tres;
}

void Camara::setAt(float uno, float dos, float tres){
  this->at.x = uno;
  this->at.y = dos;
  this->at.z = tres;
}

void Camara::setUp(float uno, float dos, float tres){
  this->up.x = uno;
  this->up.y = dos;
  this->up.z = tres;
}

void Camara::setVistaAlzado(){
  this->setEye(giroAlzado,0,avanceAlzado);
  this->setAt(0,0,0);
  this->setUp(0,1,0);
  this->setObservador();
}

void Camara::setVistaPerfilDerecho(){
  this->setEye(avanceDcha,0,giroDcha);
  this->setAt(0,0,0);
  this->setUp(0,1,0);
  this->setObservador();
}

void Camara::setVistaPerfilIzquierdo(){
  this->setEye(avanceIzda,0,giroIzda);
  this->setAt(0,0,0);
  this->setUp(0,1,0);
  this->setObservador();
}

void Camara::setVistaPlanta(){
  this->setEye(giroPlanta,avancePlanta,0);
  this->setAt(0,0,0);
  this->setUp(0,0,-1);
  this->setObservador();
}

void Camara::resetear(int camara){
  switch(camara){
    case 0:
      this->giroAlzado = 0;
      this->avanceAlzado = 10;
      break;
    case 1:
      this->giroDcha = 0;
      this->avanceDcha = 10;
      break;
    case 2:
      this->giroIzda = 0;
      this->avanceIzda = -10;
      break;
    case 3:
      this->giroPlanta = 0;
      this->avancePlanta = 10;
      break;
  }
}

void Camara::avanzar(int camara, int pos){
  switch (camara) {
    case 0:
      avanceAlzado -= pos;
      break;
    case 1:
      avanceDcha -= pos;
      break;
    case 2:
      avanceIzda += pos;
      break;
    case 3:
      avancePlanta -= pos;
      break;
  }
}

void Camara::girar(int camara, int pos){
  switch (camara) {
    case 0:
      giroAlzado += pos;
      break;
    case 1:
      giroDcha -= pos;
      break;
    case 2:
      giroIzda += pos;
      break;
    case 3:
      giroPlanta += pos;
  }
}

void Camara::setObservador(){
  gluLookAt(eye.x,eye.y,eye.z, at.x,at.y,at.z, up.x,up.y,up.z);
  imprimirPosicion();
}

void Camara::imprimirPosicion(){
  cout << "--POSICION DE LA CAMARA--" << endl;
  cout << "eye: " << eye.x << ", " << eye.y << ", " << eye.z << endl;
  cout << "at: " << at.x << ", " << at.y << ", " << at.z << endl;
  cout << "up: " << up.x << ", " << up.y << ", " << up.z << endl;
}
