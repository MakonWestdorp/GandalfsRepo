#ifndef ENTITY_H
#define ENTITY_H
#include <string>
using namespace std;
// Forward declaring Unit Test class to allow the Entity.h file to set the
// UnitTest class as a friend, giving the Unit Test class access to the setters
// and getters
class UnitTest;
class Entity {
  friend class UnitTest;

 public:
  // Default Constructor for Entity. Enemies will use Default constructor, so
  // the "Stats" and Names will be randomised.
  Entity();
  Entity(string inputName, int NumBossesDefeated);
  // Specific Constructor for players.
  Entity(string Name, int HP, int STR, int DEF, int MAG, string Resistance);
  // The attack/recieve attack functions.
  void takeDamage(int Damage, string DamageType);
  void Attack(Entity* Target);
  void Attack(Entity* Target, string TypeOfAttack, string StatUsed,
              int DamageBuff);
  void takeTurn(Entity* Target);
  bool GetIsAlive();
  int getCashOnHand();
  void setCashOnHand(int inputCashOnHand);
  // Getters and Setters. Only used in UnitTest class.
 protected:
  int getHP();
  int getSTR();
  int getDEF();
  int getMAG();
  string getName();
  string getRes();

  void setHP(int InputHP);
  void setSTR(int InputSTR);
  void setDEF(int InputDEF);
  void setMAG(int InputMAG);
  void setName(string InputName);
  void setRes(string InputName);
  int CashOnHand;
  int NumBossesDeafeated;
  std::string name, Resistance;
  int healthPoints, strength, defence, magic;
  bool isAlive;
};
#endif