// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Item.h"
/**
*
*/
class GAME_API IBuff : public Item
{

public:
	IBuff(int id, FString name, FString description, float atkMultiplier);
	~IBuff();

	bool use_Item(int id, Inventory &invq, AOCharacter &charq);

private:
	float atkMultipler;
};
