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
class GAME_API Inventory
{
public:
	Inventory();
	~Inventory();

	map get_invIWeapon();
	map get_invIPotion();
	map get_invIBuff();

	void add_IWeapon(IWeapon _IWeapon);
	void add_IPotion(IPotion _IPotion);
	void add_IBuff(IBuff _IBuff);

	void remove_IWeapon(IWeapon _IWeapon);
	void remove_IPotion(IPotion _IPotion);
	void remove_IBuff(IBuff _IBuff);

	void unequip_IWeapon(IWeapon _IWeapon);
	void equip_IWeapon(IWeapon _IWeapon);

private:

	map<int, IWeapon> invIWeapon;
	map<int, IPotion> invIPotion;
	map<int, IBuff> invIBuff;
};
