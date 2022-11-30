// Fill out your copyright notice in the Description page of Project Settings.

#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::BeginPlay()
{
    Super::BeginPlay();
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
    GetWorldTimerManager().SetTimer(FireRateHandle, this, &ATower::CheckFireCondition, 2.f, true);
}

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (InFireRange())
    {
        RotateTurret(Tank->GetActorLocation());
    }
}

void ATower::CheckFireCondition()
{
    if (Tank == nullptr)
    {
        return;
    }
    if (InFireRange() && Tank->bAlive)
    {
        Fire();
    }
}

bool ATower::InFireRange()
{
    if (Tank)
        if (FVector::Dist(GetActorLocation(), Tank->GetActorLocation()) <= FireRange)
            return true;
    return false;
}

void ATower::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}