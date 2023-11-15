// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Command.h"
#include "CoreMinimal.h"


/**
 * 
 */
class APokemon;
class UTrainerComponent;
class INVENTORYWORKSHOP_API PokeballCommand : public Command
{
public:
	PokeballCommand();
	~PokeballCommand();
	void ExecuteCommand(APokemon* CommandTarget, UTrainerComponent* CommandUser);
	void UnExecuteCommand();

private:
	UTrainerComponent* User;
	APokemon* Target;
	bool Result;
	UTrainerComponent* OriginalTrainer;
};
