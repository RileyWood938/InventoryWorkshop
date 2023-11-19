// Fill out your copyright notice in the Description page of Project Settings.

#include "PokeballCommand.h"
#include "TrainerComponent.h"
#include "Pokemon.h"
#include "Kismet/KismetSystemLibrary.h"



PokeballCommand::PokeballCommand()
{
	User = nullptr;
	Target = nullptr;
	Result = false;
	OriginalTrainer = nullptr;
}

PokeballCommand::~PokeballCommand()
{
}

void PokeballCommand::ExecuteCommand(APokemon* CommandTarget, UTrainerComponent* CommandUser)
{
	Target = CommandTarget;
	User = CommandUser;

	int32* ValuePtr = CommandUser->Inventory->Find(TEXT("Pokeball")); //Decrement Pokeball Count
	(*ValuePtr)--;
	
	CommandUser->getCapturedPokemon()->Add(CommandTarget); //  Add the pokemon to the new trainer's Inventory
	OriginalTrainer = CommandTarget->GetTrainer(); //Record the Original Trainer of the Pokemon For Undoing purposes
	if (OriginalTrainer)
	{		 
		OriginalTrainer->getCapturedPokemon()->Remove(CommandTarget);//  Take the pokemon out of it's original Trainer's Inventory
	}
	CommandTarget->SetTrainer(CommandUser);//  Set The Trainer of the Pokemon To The new Trainer
	
	Result = true; //  Make a note that this Action had its desired effect

}

void PokeballCommand::UnExecuteCommand()
{
	if (Result == true) {
		int32* ValuePtr = User->Inventory->Find(TEXT("Pokeball")); //Re-increment Pokeball Count
		(*ValuePtr)++;
	
		User->getCapturedPokemon()->Remove(Target); // Take the Pokemon out of the New Trainer's Inventory
	
		if (OriginalTrainer) 
		{
			OriginalTrainer->getCapturedPokemon()->Add(Target); // Put the pokemon back into its original trainers inventory
	
		}
	
		Target->SetTrainer(OriginalTrainer); // Set The pokemon's Trainer Back to it's original trainer
	
		Result = false; // Mark that this action has been undone
	}
}
