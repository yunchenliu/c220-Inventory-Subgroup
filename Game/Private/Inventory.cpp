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

bool Inventory::add_IPotion(IPotion _IPotion) {

	int idq = _IPotion.get_id();

	if (invIPotion.find(idq) == invIPotion.end()) {
		Consum cq(idq, 1);
		auto ret = invIPotion.insert(cq);
		return ret.second;
	}
	else {
		invIPotion.find(idq).second++;
		return true;
	}
}
bool Inventory::add_IBuff(IBuff _IBuff) {

	int idq = _IBuff.get_id();

	if (invIBuff.find(idq) == invIBuff.end()) {
		Consum cq(idq, 1);
		auto ret = invIBuff.insert(cq);
		return ret.second;
	}
	else {
		invIBuff.find(idq).second++;
		return true;
	}

}

//removing an item from a sub-inventory
bool Inventory::remove_IWeapon(IWeapon _IWeapon) {
	
	int idq = _IWeapon.get_id();

	if (invIWeapon.find(idq) == invIWeapon.end())
		return false;
	else {
		auto wfound = invIWeapon.find(idq);

		if (wfound.second.first > 1) {
			wfound.second.first--;
			return true;
		}
		else if (wfound.second.first == 1) {
			erase(wfound);
			return true;
		}
		else
			return false;
	}
}

bool Inventory::remove_IPotion(IPotion _IPotion) {

	int idq = _IPotion.get_id();

	if (invIPotion.find(idq) == invIPotion.end())
		return false;
	else {
		auto cfound = invIPotion.find(idq);

		if (cfound.second > 1) {
			cfound.second--;
			return true;
		}
		else if (cfound.second == 1) {
			erase(cfound);
			return true;
		}
		else
			return false;
	}
}
bool Inventory::remove_IBuff(IBuff _IBuff) {

	int idq = _IBuff.get_id();

	if (invIBuff.find(idq) == invIBuff.end())
		return false;
	else {
		auto cfound = invIBuff.find(idq);

		if (cfound.second > 1) {
			cfound.second--;
			return true;
		}
		else if (cfound.second == 1) {
			erase(cfound);
			return true;
		}
		else
			return false;
	}
}

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
item and then equips the newly requested item;
the int in the argument indicates the hand, where 1
is the left hand and 2 is the right hand*/
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