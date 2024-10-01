#ifndef ENTITY_H
#define ENTITY_H
#include <string>
using namespace std;
class Entity {
 public:
  Entity();
  Entity(string Name, int HP, int STR, int DEF, int MAG, string Resistance);
  void takeDamage(int Damage, string DamageType);
  void MeleeAttack(Entity* Target);
  void MagicAttack(Entity* Target);

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

 private:
  std::string name, Resistance;
  int healthPoints, strength, defence, magic;
  bool isAlive;
};
#endif