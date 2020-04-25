// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

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

	//void OpenDoor();
	//void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnClose;

private:
	// UPROPERTY(VisibleAnywhere)
	//UPROPERTY(EditAnywhere)
	//float OpenAngle = -90.0f;
	//^ we don't need this anymore now that we have set this up in the custom Openable_Door blueprint

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	float TriggerMass = 30.f;

	//UPROPERTY(EditAnywhere)
	//float DoorCloseDelay = 1.f;
	//^ we don't need this anymore now that we have set this up in the custom Openable_Door blueprint

	//float LastDoorOpenTime;
	//^ we don't need this anymore now that we have set this up in the custom Openable_Door blueprint

	// Dont need this anymore so commenting it out
	// AActor* ActorThatOpens; //Remember that pawn inherits from actor
	AActor* Owner = nullptr; // The owning door

	float GetTotalMassOfActorsOnPlate();
	
};
