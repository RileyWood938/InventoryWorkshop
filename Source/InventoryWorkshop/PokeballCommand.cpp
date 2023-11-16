// Fill out your copyright notice in the Description page of Project Settings.


#include "PokeballCommand.h"
#include "TrainerComponent.h"
#include "Pokemon.h"

PokeballCommand::PokeballCommand()
{
}

PokeballCommand::~PokeballCommand()
{
}

void PokeballCommand::ExecuteCommand(APokemon* CommandTarget, UTrainerComponent* CommandUser)
{
	//Result = false;
	//Target = CommandTarget;
	//User = CommandUser;
	//if (User->GetPokeballCount() > 0) {
	//	User->SetPokeballCount(User->GetPokeballCount() - 1); // 1 Decrement Pokeball Count
	//
	//	User->getCapturedPokemon()->Add(Target); // 2 Add the pokemon to the new trainer's Inventory
	//	OriginalTrainer = Target->GetTrainer(); //Record the Original Trainer of the Pokemon For Undoing purposes
	//	if (OriginalTrainer)
	//	{		 
	//		OriginalTrainer->getCapturedPokemon()->Remove(Target);// 3 Take the pokemon out of it's original Trainer's Inventory
	//	}
	//	Target->SetTrainer(User);// 4 Set The Trainer of the Pokemon To The new Trainer
	//
	//	Result = true; // 5 Make a note that this Action had its desired effect
	//}
}

void PokeballCommand::UnExecuteCommand()
{
	//if (Result == true) {
	//	User->SetPokeballCount(User->GetPokeballCount() + 1); // 1 Re-increment Pokeball Count
	//
	//	User->getCapturedPokemon()->Remove(Target); // 2 Take the Pokemon out of the New Trainer's Inventory
	//
	//	if (OriginalTrainer) 
	//	{
	//		OriginalTrainer->getCapturedPokemon()->Add(Target); // 3 Put the pokemon back into its original trainers inventory
	//
	//	}
	//
	//	Target->SetTrainer(OriginalTrainer); // 4 Set The pokemon's Trainer Back to it's original trainer
	//
	//	Result = false; // 5 Mark that this action has been undone
	//}
}
