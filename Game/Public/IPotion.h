// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Item.h"
/**
*
*/
class GAME_API IPotion : public Item
{

public:
	IPotion(int id, FString name, FString description, int HP_amt);
	~IPotion();

	bool use_Item(int id, Inventory &invq, AOCharacter &charq);

private:
	int HP_amt;
};
