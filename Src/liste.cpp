#include "liste.hpp"

#include <iostream>
#include <cassert>

Liste::Liste() {
  taille_list = 0;
  prem = nullptr;
}

Liste::Liste(const Liste& autre) {
  prem = new Cellule(autre.tete()->valeur);
  const Cellule * ctemp = autre.tete();
  Cellule *ctemp_insert =prem;
  while(ctemp->suivant != nullptr)
  {
    ctemp_insert->suivant = new Cellule(ctemp->suivant->valeur);
    ctemp_insert = ctemp_insert->suivant;
    ctemp = ctemp->suivant;
  }
}

Liste& Liste::operator=(const Liste& autre) {
  Cellule *c = prem;
  //verif list nsuivanton vide
  if(c!= nullptr)
  {
    /*while(c->suivant != nullptr)
    {
        ctemp = c->suivant;
        c = ctemp; 
    }*/
    delete c;
    prem = nullptr;
    taille_list = 0;
  }

  prem = new Cellule(autre.tete()->valeur);

  taille_list = 1;
  const Cellule *ctemp_autre = autre.tete();
  Cellule * ctemp_insert = prem;
  while(ctemp_autre->suivant != nullptr)
  {
    taille_list++;
    ctemp_insert -> suivant = new Cellule(ctemp_autre->suivant->valeur);
    ctemp_insert = ctemp_insert->suivant;
    ctemp_autre = ctemp_autre->suivant;
  }




  return *this ;
}

Liste::~Liste() {
  delete prem;
}

void Liste::ajouter_en_tete(int valeur) {
    taille_list++;
    Cellule *c = new Cellule(valeur);
    c->suivant = prem;
    prem = c;
}

void Liste::ajouter_en_queue(int valeur) {
  Cellule *c = new Cellule(valeur);
  Cellule *ctemp = prem;
  while(ctemp->suivant != nullptr)
  {
    ctemp = ctemp->suivant;
  }
  taille_list++;
  ctemp->suivant = c;
}

void Liste::supprimer_en_tete() {
  Cellule *ctemp;

  ctemp =prem;
  prem = prem->suivant;
  ctemp->suivant = nullptr; //dechainage
  delete ctemp;
}

Cellule* Liste::tete() {
  return prem ;
}

const Cellule* Liste::tete() const {
  return prem ;
}

Cellule* Liste::queue() {
  Cellule *ctemp = prem;
  while(ctemp->suivant != nullptr)
  {
    ctemp = ctemp->suivant;
  }
  return ctemp;
}

const Cellule* Liste::queue() const {
  Cellule *ctemp = prem;
  while(ctemp->suivant != nullptr)
  {
    ctemp = ctemp->suivant;
  }
  return ctemp;
}

int Liste::taille() const {
  return taille_list ;
}

Cellule* Liste::recherche(int valeur) {
  Cellule *c = prem;
  while(c!=nullptr && c->valeur!=valeur)
  {
    c = c->suivant;
  }
  return c;
}

const Cellule* Liste::recherche(int valeur) const {
  Cellule *c = prem;
  while(c != nullptr && c->valeur!=valeur)
  {
    c = c->suivant;
  }
  return c;
}

void Liste::afficher() const {
  Cellule *ctemp = prem;
  while(ctemp != nullptr)
  {
    std::cout << ctemp->valeur << " : ";
    ctemp = ctemp->suivant;
  }
  std::cout << std::endl;
}
