// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "IPotion.h"

IPotion::IPotion(int id, FString name, FString description, int HP_amt)
		: id(id), name(name), description(description), HP_amt(HP_amt) {
}

IPotion::~IPotion()
{
}
