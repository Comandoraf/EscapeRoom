// Copyright Rafal Potoczek 2017

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	AcotrThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	AActor* Owner = GetOwner();

	Owner->GetTransform().GetRotation();

	FRotator NewRotation = FRotator(0.0f, -60.0f, 0.0f);

	Owner->SetActorRotation(NewRotation);
	bDoorOpened = true;
	UE_LOG(LogTemp, Warning, TEXT("Door opened"));
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!bDoorOpened && PressurePlate->IsOverlappingActor(AcotrThatOpens)) 
	{
		OpenDoor();
	}
	
}

