// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "Inventory.h"
//constructor
Inventory::Inventory()
		: invItem(map<ItemID, IStat>) {
}
//deconstructor
Inventory::~Inventory() {
}

//adds quantity 1 of an item to the inventory
bool Inventory::add_invItem(ItemID idq) {

	//int idq = _Item.get_id();

	if (invItem.find(idq) == invItem.end()) {
		IStat _IStat(idq, 1);
		auto ret = invItem.insert({ idq, _IStat });
		return ret.second;
	}
	else {
		invItem.find(idq)->second.second++;
		return true;
	}
}

//removes quantity 1 of an item from the inventory
bool Inventory::remove_invItem(ItemID idq) {

	//int idq = _Item.get_id();

	if (invItem.find(idq) == invItem.end())
		return false;
	else {
		auto founditem = invItem.find(idq);

		if (founditem->second.second > 1) {
			founditem->second.second--;
			return true;
		}
		else if (founditem->second.second == 1) {
			if (/*check if weapon is equipped*/) {
				return false;
			}
			erase(founditem);
			return true;
		}
		else
			return false;
	}

}

/*
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
*/

/*Equips the item by changing the WStat.second to true;
if another weapon is currently equipped, unequips that
item and then equips the newly requested item;
the int in the argument indicates the hand, where 1
is the left hand and 2 is the right hand
bool Inventory::equip_IWeapon(IWeapon _IWeapon, int hand) {

	int idq = _IWeapon.get_id();
	auto wfound = invIWeapon.find(idq);

	if (wfound == invIWeapon.end()) {
		return false;
	}

	wfound.second.first--;
	wfound.second.second = true;

	if (hand == 1) {

		if (CurrLHEquip == 0) {
			CurrLHEquip = idq;
			return true;
		}
		else if ((CurrLHEquip != 0) && (unequip_IWeapon(_IWeapon)) {
			CurrLHEquip = idq;
			return true;
		}
		else
			return false;
	}
	else if (hand == 2) {

		if (CurrRHEquip == 0) {
			CurrRHEquip = idq;
			return true;
		}
		else if ((CurrLHEquip != 0) && (unequip_IWeapon(_IWeapon)) {
			CurrRHEquip = idq;
			return true;
		}
		else
			return false;
	}
}
*/