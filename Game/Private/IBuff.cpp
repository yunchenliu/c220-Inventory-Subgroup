// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "IBuff.h"

IBuff::IBuff(int id, FString name, FString description, int atkMod)
	: id(id), name(name), description(description), atkMod(atkMod) {
}

IBuff::~IBuff() {
}

bool IBuff::use_Item(int id, Inventory &invq, AOCharacter &charq) {
	//write code to modify character's stats here
	bool b1 = CHECK_IF_STATS_ARE_MODIFIED_CORRECTLY;

	//removes item from inventory
	bool b2 = invq.remove_invItem(id);
	return (b1 && b2);
}