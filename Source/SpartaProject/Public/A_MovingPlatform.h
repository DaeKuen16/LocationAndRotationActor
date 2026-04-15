// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A_MovingPlatform.generated.h"

UCLASS()
class SPARTAPROJECT_API AA_MovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AA_MovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingPlatform|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatfom|Properties")
	FVector startLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatfom|Properties")
	FVector Direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatfom|Properties")
	float moveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatfom|Properties")
	float maxRange;
};
