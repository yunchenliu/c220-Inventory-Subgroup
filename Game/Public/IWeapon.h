// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Item.h"
/**
 * 
 */
class GAME_API IWeapon : public Item
{
public:
	IWeapon(int id, FString name, FString description, int atkMod);
	~IWeapon();

	bool use_Item(int id, Inventory &invq, AOCharacter &charq);

private:
	int atkMod;
	int defMod;
};

class Game_API IWSheild : public IWeapon
{
public:
	IWSheild(int id, FString name, FString description, int defMod);
	~IWSheild();
}
