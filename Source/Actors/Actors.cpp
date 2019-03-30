/*
 * Actors.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: Alex Rivero
 */

 #include "Actors.h"

 Actors::Actors()
 {
   health = defence = 0;
 }


 Actors::Actors(int x, int y, CellColor_e color , int healthValue, int defenceValue)
   : Cell(x,y,color,true)
 {
   health = healthValue;
   defence = defenceValue;
 }


 Actors::~Actors()
 {
   health = defence = 0;
 }

 int Actors::getDefence()
 {
   return defence;
 }

 int Actors::getHealth()
 {
   return health;
 }

 void Actors::changeDefence(int value)
 {
  defence += value;                 // increment or decrement defence

  if(defence > maxDefense)
    {
      defence = maxDefense;
    }
 }

 void Actors::changeHealth(int value)
 {
   health += value;                 // increment or decrement health

   if( health > maxHealth)
   {
     health = maxHealth;
   }
 }
