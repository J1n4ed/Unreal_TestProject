// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FTransformStruct {
  GENERATED_USTRUCT_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FVector CurrentLocation = FVector::ZeroVector;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FRotator CurrentRotation = FRotator::ZeroRotator;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UENUM(BlueprintType)
enum class EMovementState : uint8 { Mobility, Static };

UCLASS()
class CPPBASE_API ACppBaseActor : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  ACppBaseActor();

  UPROPERTY(VisibleAnywhere)
  UStaticMeshComponent *Mesh;

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  UPROPERTY(EditInstanceOnly)
  FString InstanceName = "Instance";

  UPROPERTY(EditInstanceOnly)
  int EnemyNum = 0;

  UPROPERTY(EditDefaultsOnly)
  float CurrentHealth = 100.00;

  UPROPERTY(EditInstanceOnly)
  bool IsAlive = true;

  UFUNCTION(BlueprintCallable)
  void ShowActorInformation();

  UFUNCTION(BlueprintCallable)
  FVector SinMovement();

  UPROPERTY(EditInstanceOnly)
  float Amplitude = 4.0f;

  UPROPERTY(EditInstanceOnly)
  float Frequency = 40.0f;

  UPROPERTY(EditDefaultsOnly)
  FVector InitialLocation;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;
};