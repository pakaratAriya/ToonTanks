// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
	APlayerController *GetPlayerController() const;
	void HandleDestruction();

	bool bAlive = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent *SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent *CameraComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tank Movement", meta = (AllowPrivateAccess = "true"))
	float Speed = 400.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tank Movement", meta = (AllowPrivateAccess = "true"))
	float TurnRate = 20.f;

	APlayerController *PlayerController;

	void Move(float value);
	void Turn(float value);
};
