// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "IWeapon.h"

IWeapon::IWeapon(int id, FString name, FString description, int atkMod)
		: id(id), name(name), description(description), atkMod(atkMod) {
}

IWeapon::~IWeapon() {
}
