// Fill out your copyright notice in the Description page of Project Settings.


#include "CoffeMachineBase.h"
#include "ContainersComponent.h"
#include "CoffeGroundsActor.h"

// Sets default values
ACoffeMachineBase::ACoffeMachineBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ContainerComponent = CreateDefaultSubobject<UContainersComponent>("Container Component");

}


bool ACoffeMachineBase::GetIsDuringPouring()
{
    return IsDuringPouring;
}

void ACoffeMachineBase::SetIsDuringPouring(bool state)
{
	IsDuringPouring = state;
}

bool ACoffeMachineBase::GetIsIncomplete()
{
    return IsIncomplete;
}

bool ACoffeMachineBase::CanUseDisplay()
{
    return !(IsDisplayBlocked||IsDuringPouring||IsIncomplete);
}

void ACoffeMachineBase::SetIsDisplayBlocked(bool IsBlocked)
{
	IsDisplayBlocked = IsBlocked;
}

void ACoffeMachineBase::SetIsIncomplete(bool state)
{
	IsIncomplete = state;
}

void ACoffeMachineBase::MakeCoffe(int CoffeType)
{
	ContainerComponent->SetNewTargetCoffeGroundsLevel((ContainerComponent->GetTargetCoffeGroundsLevel())+20.0f);
	ContainerComponent->AddToTargetWaterLevel(-20.0f);
	StartMakeCoffe(CoffeType);
}

void ACoffeMachineBase::StartMakeCoffe_Implementation(int CoffeType)
{
	
}

// Called when the game starts or when spawned
void ACoffeMachineBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoffeMachineBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

