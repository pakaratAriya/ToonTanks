// Fill out your copyright notice in the Description page of Project Settings.

#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"
#include "ToonTanksPlayerController.h"
#include "TimerManager.h"

void AToonTanksGameMode::BeginPlay()
{
    Super::BeginPlay();
    HandleStartGame();
}

void AToonTanksGameMode::ActorDied(AActor *DeadActor)
{

    if (DeadActor == Tank)
    {
        Tank->HandleDestruction();
        PlayerController->DisablePlayerInput(true);
        GameOver(false);
    }
    else if (ATower *Tower = Cast<ATower>(DeadActor))
    {
        Tower->HandleDestruction();
        TowerCount--;
        if (TowerCount == 0)
        {
            GameOver(true);
        }
    }
}

void AToonTanksGameMode::HandleStartGame()
{
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
    PlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    TowerCount = GetTowerCount();
    StartGame();

    if (PlayerController)
    {
        FTimerHandle TimerHandle;
        FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(PlayerController, &AToonTanksPlayerController::DisablePlayerInput, false);

        PlayerController->DisablePlayerInput(true);
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, Delay, false);
    }
}

int32 AToonTanksGameMode::GetTowerCount()
{
    TArray<AActor *> Towers;
    UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers);
    return Towers.Num();
}