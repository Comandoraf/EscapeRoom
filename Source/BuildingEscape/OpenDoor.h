// Copyright Rafal Potoczek 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


class ATriggerVolume;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(VisibleAnywhere)
		float OpenAngle = -90.0f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
		AActor* AcotrThatOpens;

	UPROPERTY(EditAnywhere)
		float CloseDelay = 1.f;

	float LastDoorOpenTime;
	bool bDoorOpened = false;

	AActor* Owner;
};
