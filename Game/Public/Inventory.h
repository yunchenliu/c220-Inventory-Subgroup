// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Item.h"
#include "IWeapon.h"
#include "IPotion.h"
#include "IBuff.h"
#include <list>
#include <map>

using namespace std;

/**
*
*/

/*Consum is a consumable item in the inventory, 
a pair which specifies
- an int, the item's matching hex code
- an int, the item's quantity in the inventory
*/
typedef pair<int, int> Consum;
/* WStat is a pair which specifies
- an int, the Weapon's quantity
- a bool, whether or not it's equipped*/
typedef pair<int, bool> WStat;
/* Weap is a weapon item in the inventory,
a pair which specifies
- an int, the item's matching hex code
- a WStat*/
typedef pair<int, WStat> Weap;

class GAME_API Inventory
{
public:
	Inventory();
	~Inventory();

	map get_invIWeapon();
	map get_invIPotion();
	map get_invIBuff();

	bool add_IWeapon(IWeapon _IWeapon);
	bool add_IPotion(IPotion _IPotion);
	bool add_IBuff(IBuff _IBuff);

	bool remove_IWeapon(IWeapon _IWeapon);
	bool remove_IPotion(IPotion _IPotion);
	bool remove_IBuff(IBuff _IBuff);

	void unequip_IWeapon(IWeapon _IWeapon);
	void equip_IWeapon(IWeapon _IWeapon);

private:

	map<int, WStat> invIWeapon;
	map<int, int> invIPotion;
	map<int, int> invIBuff;

	//Gives the hex code of the currently equipped weapon;
	//The code is 0 if no weapon equipped;
	int CurrLHEquip;
	int CurrRHEquip;
};
