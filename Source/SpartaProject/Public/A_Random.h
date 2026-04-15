// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A_Random.generated.h"

UCLASS()
class SPARTAPROJECT_API AA_Random : public AActor
{
	GENERATED_BODY()

public:
	AA_Random();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RandomActor|Components")
	USceneComponent* RootScene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomActor|Components")
	UStaticMeshComponent* StaticMeshComp;

	UFUNCTION(BlueprintCallable, Category = "RandomActor|Actions")
	void randomMove();
	UFUNCTION(BlueprintCallable, Category = "RandomActor|Actions")
	void randomRotation();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomActor|Properties")
	bool randomMoveLocation;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "RandomActor|Properties")
	bool randomMoveRotation;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "RandomActor|Properties")
	float moveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerPlatform|Properties")
	FTimerHandle moveLocationTimeHandler;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerPlatform|Properties")
	FTimerHandle moveRotationTimeHandler;
	UPROPERTY()
	FVector vectorLocation;
	UPROPERTY()
	float RotationSpeed;
};
