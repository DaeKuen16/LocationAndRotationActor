// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A_TimerPlatform.h"
#include "A_Random.h"
#include "Spawner.generated.h"

UCLASS()
class SPARTAPROJECT_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawner();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn|PlatformClass")
	TSubclassOf<AA_TimerPlatform> platformClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn|PlatformClass")
	TSubclassOf<AA_Random> randomPlatformClass;
public:	
	virtual void Tick(float DeltaTime) override;

};
