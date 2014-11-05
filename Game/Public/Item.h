// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class GAME_API Item
{
public:
	Item(int id, FString name, FString description);
	~Item();
    
    int get_id();
    FString get_name();
    FString get_description();
private:
    int id; // The HEX id of the item
    FString name; // display name of item
    FString description; // description of the item
};
