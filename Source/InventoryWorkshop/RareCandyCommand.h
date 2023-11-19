// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Command.h"
#include "CoreMinimal.h"

/**
 * 
 */
class INVENTORYWORKSHOP_API RareCandyCommand : public Command
{
public:
	RareCandyCommand();
	~RareCandyCommand();
	virtual void ExecuteCommand(APokemon* CommandTarget, UTrainerComponent* CommandUser) override;
	virtual void UnExecuteCommand() override;

private:
	UTrainerComponent* User;
	APokemon* Target;
	bool Result;
};
