// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"), Category = "Components", BlueprintReadWrite)
	UStaticMeshComponent *ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UProjectileMovementComponent *ProjectileMovement;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Combat", BlueprintReadWrite)
	float InitialSpeed;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Combat", BlueprintReadWrite)
	float MaxSpeed;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class UParticleSystem *HitParticle;

	UPROPERTY(VisibleAnywhere, Category = "Combat")
	class UParticleSystemComponent *TrailParticleComp;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class USoundBase *LaunchSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase *HitSound;

	UPROPERTY(EditAnywhere, Category ="Combat")
	TSubclassOf<class UCameraShakeBase> HitCameraShake;

	UFUNCTION()
	void OnHit(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &HitResult);
};
