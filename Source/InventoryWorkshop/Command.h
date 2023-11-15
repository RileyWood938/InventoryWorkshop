// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class INVENTORYWORKSHOP_API Command
{
public:
	Command();
	~Command();
	void ExecuteCommand();
	void UnExecuteCommand();
};
