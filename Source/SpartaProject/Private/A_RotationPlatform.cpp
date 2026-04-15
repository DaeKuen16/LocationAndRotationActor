#include "A_RotationPlatform.h"

AA_RotationPlatform::AA_RotationPlatform()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotationSpeed = 90.0f;
	PrimaryActorTick.bCanEverTick = true;

}

void AA_RotationPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void AA_RotationPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(RotationSpeed * DeltaTime, 0.0f, 0.0f));
	}
}

