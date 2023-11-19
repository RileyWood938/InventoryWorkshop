// Fill out your copyright notice in the Description page of Project Settings.


#include "RareCandyCommand.h"
#include "TrainerComponent.h"
#include "Pokemon.h"
#include "Kismet/KismetSystemLibrary.h"



RareCandyCommand::RareCandyCommand()
{
	User = nullptr;
	Target = nullptr;
	Result = false;
}

RareCandyCommand::~RareCandyCommand()
{
}

void RareCandyCommand::ExecuteCommand(APokemon* CommandTarget, UTrainerComponent* CommandUser)
{
	Target = CommandTarget;
	User = CommandUser;

	int32* ValuePtr = CommandUser->Inventory->Find(TEXT("RareCandy")); //Decrement Candy Count
	(*ValuePtr)--;

	CommandTarget->SetLevel(CommandTarget->GetLevel()+1); //Increment Pokemon Level

	Result = true; //  Make a note that this Action had its desired effect

}

void RareCandyCommand::UnExecuteCommand()
{
	if (Result == true) {
		int32* ValuePtr = User->Inventory->Find(TEXT("RareCandy")); //Re-increment Candy Count
		(*ValuePtr)++;

		Target->SetLevel(Target->GetLevel() - 1); //Decrement Pokemon Level

		Result = false; // Mark that this action has been undone
	}
}
