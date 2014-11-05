// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <Item.h>
#include <IWeapon.h>
#include <IPotion.h>
#include <IBuff.h>
#include <list>
#include <map>

/**
*
*/

/*iItem is an item in the inventory, 
a pair which specifies
- the item's matching hex code
- the item's quantity in the inventory
*/
typedef pair<int, int> iItem;

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

	map<int, int> invIWeapon;
	map<int, int> invIPotion;
	map<int, int> invIBuff;
};
