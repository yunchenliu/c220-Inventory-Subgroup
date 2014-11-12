// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "IWeapon.h"

IWeapon::IWeapon(int id, FString name, FString description, int atkMod)
		: id(id), name(name), description(description), atkMod(atkMod) {
}

IWeapon::~IWeapon() {
}

bool use_Item(int id, Inventory &invq, AOCharacter &charq) {

	//implement equip item to the character function here
	bool b1 = CHECK_IF_ITEM_EQUIPPED_CORRECTLY;

	//equip the item on the character
	bool b2 = CHECK_IF_WEAPON_EQUIPPED_PROPERLY;

	return (b1 && b2);
}