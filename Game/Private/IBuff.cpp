// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "IBuff.h"

IBuff::IBuff(int id, FString name, FString description, int atkMod)
	: id(id), name(name), description(description), atkMod(atkMod) {
}

IBuff::~IBuff() {
}
