// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "Item.h"

using namespace std;

Item::Item(int id, FString name, FString description) 
	: id(id), name(name), description(description) {
}

Item::~Item() {
}

int Item::get_id() {
	return id;
}
FString Item::get_name() {
	return name;
}
FString Item::get_description() {
	return description;
}