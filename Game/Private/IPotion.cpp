// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "IPotion.h"
#include "Inventory.h"

IPotion::IPotion(int id, FString name, FString description, int HP_amt)
		: id(id), name(name), description(description), HP_amt(HP_amt) {
}

IPotion::~IPotion()
{
}

bool IPotion::use_Item(int id, Inventory &invq, AOCharacter &charq) {
	//write code to modify character's stats here
	bool b1 = CHECK_IF_STATS_ARE_MODIFIED_CORRECTLY;

	//removes item from inventory
	bool b2 = invq.remove_invItem(id);
	return (b1 && b2);
}