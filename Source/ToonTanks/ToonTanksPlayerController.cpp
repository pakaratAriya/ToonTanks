// Fill out your copyright notice in the Description page of Project Settings.

#include "ToonTanksPlayerController.h"

void AToonTanksPlayerController::DisablePlayerInput(bool bPlayerDisable)
{
    if (!bPlayerDisable)
    {
        GetPawn()->EnableInput(this);
    }
    else
    {
        GetPawn()->DisableInput(this);
    }
    bShowMouseCursor = bPlayerDisable;
}
