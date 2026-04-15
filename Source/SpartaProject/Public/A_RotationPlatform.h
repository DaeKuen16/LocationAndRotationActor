#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A_RotationPlatform.generated.h"

UCLASS()
class SPARTAPROJECT_API AA_RotationPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AA_RotationPlatform();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
