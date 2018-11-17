// Copyright Rafal Potoczek 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	void FindPhysicsComponent();
	void SetupInputComponent();
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	//How far ahead of the player can we reach in cm
	float Reach = 100.0f;

	class UPhysicsHandleComponent* PhysicsHandle = nullptr;

	class UInputComponent*  InputComponent = nullptr;

	//Ray-cast and grab what's
	void Grab();
	
	void Release();

	FHitResult GetFristPhysicsBodyInReach() const;

	FVector GetReachLineEnd();

	FVector GetReachLineStart();
};
