// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoffeMachineBase.generated.h"

class UContainersComponent;
class ACoffeGroundsActor;
UCLASS()
class COFFEPROJECT_API ACoffeMachineBase : public AActor
{
	GENERATED_BODY()
	
	
public:	
	// Sets default values for this actor's properties
	ACoffeMachineBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UContainersComponent* ContainerComponent = nullptr;

	UPROPERTY(EditAnywhere, Category = "Grounds Container")
	ACoffeGroundsActor* CoffeGroundsActor = nullptr;

    UFUNCTION(BlueprintCallable)
	bool GetIsDuringPouring();

    UFUNCTION(BlueprintCallable)
	void SetIsDuringPouring(bool state);

    UFUNCTION(BlueprintCallable)
	bool GetIsIncomplete();

	UFUNCTION(BlueprintCallable)
	bool CanUseDisplay();

	UFUNCTION(BlueprintCallable)
	void SetIsDisplayBlocked(bool IsBlocked);

    UFUNCTION(BlueprintCallable)
	void SetIsIncomplete(bool state);

	UFUNCTION(BlueprintCallable)
	void MakeCoffe(int CoffeType);

	UFUNCTION(BlueprintNativeEvent, Category = "Coffe")
	void StartMakeCoffe(int CoffeType);
     
	void StartMakeCoffe_Implementation(int CoffeType);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	bool IsDuringPouring = false;

	UPROPERTY(EditAnywhere)
	bool IsDisplayBlocked = false;

	UPROPERTY(EditAnywhere)
	bool IsIncomplete = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
