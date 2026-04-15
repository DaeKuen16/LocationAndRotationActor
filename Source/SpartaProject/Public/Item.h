#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SPARTAPROJECT_API AItem : public AActor
{
	GENERATED_BODY()

public:
	AItem();

protected:
	// Root Scene Component, 에디터에서 볼 수만 있고 수정 불가
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;
	// Static Mesh, 에디터와 Blueprint에서 수정 가능
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	// 회전 속도, 클래스 기본값만 수정 가능
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//함수를 블루프린트에서 호출 가능하도록 설정
	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void ResetActorPosition();

	//블루프린트에서 값만 반환하도록 설정
	UFUNCTION(BlueprintPure, Category = "Item|Properties")
	float GetRotationSpeed() const;

	//C++에서 호출되지만 구현은 블루프린트에서 수행
	UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
	void OnItemPickedUp();
};