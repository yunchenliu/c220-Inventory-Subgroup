// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Item.h"
#include "IWeapon.h"
#include "IPotion.h"
#include "IBuff.h"
#include <list>
#include <map>

using namespace std;
typedef int ItemID;

/* IStat is a pair which specifies
- an int, the item's hex code
- an int, the quantity of the item in the inventory*/
typedef pair<ItemID, int> IStat;

/* Weap is an item in the inventory, a pair which specifies
- an int, the item's hex code
- an IStat*///
//typedef pair<int, IStat> ;

class GAME_API Inventory
{
public:
	Inventory();
	~Inventory();

	bool add_invItem(Item _Item);
	bool remove_invItem(Item _Item);

	bool unequip_IWeapon(IWeapon _IWeapon);
	bool equip_IWeapon(IWeapon _IWeapon);

private:
	map<ItemID, IStat> inv;
};
