// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A_TimerPlatform.generated.h"

UCLASS()
class SPARTAPROJECT_API AA_TimerPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AA_TimerPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerPlatform|Components")
	USceneComponent* RootScene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerPlatform|Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerPlatform|Properties")
	FTimerHandle TimeHandler;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerPlatform|Properties")
	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerPlatform|Properties")
	FVector Direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerPlatform|Properties")
	float moveSpeed;

	UFUNCTION(BlueprintCallable, Category = "TimerPlatform|Action")
	void MoveActor();

	UFUNCTION(BlueprintCallable, Category = "TimerPlatform|Action")
	void RemoveActor();
};
