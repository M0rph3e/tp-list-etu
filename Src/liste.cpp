#include "liste.hpp"

#include <iostream>
#include <cassert>

Liste::Liste() {
  taille_list = 0;
  prem = nullptr;
}

Liste::Liste(const Liste& autre) {
  /* votre code ici */
}

Liste& Liste::operator=(const Liste& autre) {
  /* votre code ici */
  return *this ;
}

Liste::~Liste() {
  /* votre code ici */
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
  Cellule *ctemp = prem;
  prem = ctemp->suivant;
  delete ctemp;
  if(taille_list>0)
    taille_list -= 1;
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
  while(c->suivant != nullptr && c->valeur!=valeur)
  {
    c = c->suivant;
  }
  return c;
}

const Cellule* Liste::recherche(int valeur) const {
  Cellule *c = prem;
  while(c->suivant != nullptr && c->valeur!=valeur)
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
