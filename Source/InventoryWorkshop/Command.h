// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class APokemon;
class UTrainerComponent;

class INVENTORYWORKSHOP_API Command
{
public:
	Command();
	~Command();
	virtual void ExecuteCommand(APokemon* CommandTarget, UTrainerComponent* CommandUser);
	void UnExecuteCommand();
};
