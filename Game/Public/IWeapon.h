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

private:
	int atkMod;
	int defMod;
};
