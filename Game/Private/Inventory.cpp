// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "Inventory.h"
//constructor
Inventory::Inventory()
		: invIWeapon(map<int, int>), invIPotion(map<int, int>), invIBuff(map<int, int>) {
}
//deconstructor
Inventory::~Inventory() {
}
//getting individual sub-inventories
map Inventory::get_invIWeapon() {
	return invIWeapon;
}
map Inventory::get_invIPotion() {
	return invIPotion;
}
map Inventory::get_invIBuff() {
	return invIBuff;
}
//adding an item to a sub-inventory
bool Community::add_person(Person _person) {
	if (people.find(_person.get_username()) == people.end()) {
		contact to_add(_person.get_username(), _person);
		auto ret = people.insert(to_add);
		return ret.second;
	}
	else
		return false;
}
bool Inventory::add_IWeapon(IWeapon _IWeapon) {

	int idq = _IWeapon.get_id();

	if (invIWeapon.find(idq) == invIWeapon.end()) {
		iItem to_add(idq, 1);
		auto ret = invIWeapon.insert(to_add);
		return ret.second;
	}
	else {

	}
}

void Inventory::add_IPotion(IPotion _IPotion) {
	_
}
void Inventory::add_IBuff(IBuff _IBuff) {

}

//removing an item from a sub-inventory
void remove_IWeapon(IWeapon _IWeapon);
void remove_IPotion(IPotion _IPotion);
void remove_IBuff(IBuff _IBuff);

void unequip_IWeapon(IWeapon _IWeapon);
void equip_IWeapon(IWeapon _IWeapon);
}