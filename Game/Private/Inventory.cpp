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
/*adds a weapon to the weapon inventory;
if the weapon already exists, ups the
count by 1*/
bool Inventory::add_IWeapon(IWeapon _IWeapon) {

	int idq = _IWeapon.get_id();

	if (invIWeapon.find(idq) == invIWeapon.end()) {
		WStat wq(1, false);
		Weap to_add(idq, wq);
		auto ret = invIWeapon.insert(to_add);
		return ret.second;
	}
	else {
		invIWeapon.find(idq).second.first++;
		return true;
	}
}

void Inventory::add_IPotion(IPotion _IPotion) {
	_
}
void Inventory::add_IBuff(IBuff _IBuff) {

}

//removing an item from a sub-inventory
void Inventory::remove_IWeapon(IWeapon _IWeapon);
void Inventory::remove_IPotion(IPotion _IPotion);
void Inventory::remove_IBuff(IBuff _IBuff);

//Unequips the item by changing the WStat.second to false
bool Inventory::unequip_IWeapon(IWeapon _IWeapon) {

	int idq = _IWeapon.get_id();
	auto wfound = invIWeapon.find(idq);

	if (wfound == invIWeapon.end()) {
		return false;
	}
	else {
		wfound.second.first++;
		wfound.second.second = false;
		CurrEquipped = 0;
		return true;
	}
}

/*Equips the item by changing the WStat.second to true;
if another weapon is currently equipped, unequips that
item and then equips the newly requested item*/
bool Inventory::equip_IWeapon(IWeapon _IWeapon) {

	int idq = _IWeapon.get_id();
	auto wfound = invIWeapon.find(idq);

	if (wfound == invIWeapon.end()) {
		return false;
	}
	else if (CurrEquipped == 0) {
		wfound.second.first--;
		wfound.second.second = true;
		CurrEquipped = 0;
		return true;
	}
}