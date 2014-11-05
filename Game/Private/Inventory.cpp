// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "Inventory.h"

Inventory::Inventory()
		: invIWeapon(map<int, IWeapon>), invIPotion(map<inv, IPotion>), invIBuff(map<inv, IBuff>) {
}

Inventory::~Inventory() {
}

map get_invIWeapon() {
	return invIWeapon;
};
map get_invIPotion() {
	return invIPotion;
};
map get_invIBuff() {
	return invIBuff;
};

void add_IWeapon(IWeapon _IWeapon) {
	int id = _IWeapon.get_id();
	FString name = _IWeapon.get_name();

};
void add_IPotion(IPotion _IPotion) {
	_
};
void add_IBuff(IBuff _IBuff) {

};

void remove_IWeapon(IWeapon _IWeapon);
void remove_IPotion(IPotion _IPotion);
void remove_IBuff(IBuff _IBuff);

void unequip_IWeapon(IWeapon _IWeapon);
void equip_IWeapon(IWeapon _IWeapon);

int Item::get_id() {
	return id;
}
FString Item::get_name() {
	return name;
}
FString Item::get_description() {
	return description;
}