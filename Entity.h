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

 private:
  std::string name, Resistance;
  int healthPoints, strength, defence;
  bool isAlive;
};
#endif