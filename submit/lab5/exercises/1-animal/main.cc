#include "animal.hh"

#include <iostream>

int main(int argc, char* argv[]) {
  std::ostream& out = std::cout;
  Cat fluffy("fluffy"), simba("simba");
  Dog fido("fido"), rufus("rufus");
  Cow bossy("bossy"), bessie("bessie");
  //zconst Animal animals[] = { fido, fluffy };
  const Animal *animals[] = {
    &bessie,
    &bossy,
    &fido,
    &fluffy,
    &rufus,
    &simba,
  };
  for (auto animalP : animals) {
    out << animalP->name << " says " << animalP->eats() << std::endl;
  }
}
