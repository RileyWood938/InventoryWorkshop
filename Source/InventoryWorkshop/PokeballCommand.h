// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Command.h"
#include "CoreMinimal.h"


/**
 * 
 */
class INVENTORYWORKSHOP_API PokeballCommand : public Command
{
public:
	PokeballCommand();
	~PokeballCommand();
	virtual void ExecuteCommand(APokemon* CommandTarget, UTrainerComponent* CommandUser) override;
	void UnExecuteCommand();

private:
	UTrainerComponent* User;
	APokemon* Target;
	bool Result;
	UTrainerComponent* OriginalTrainer;
};
