﻿// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor.h"
#include "Engine/Engine.h"

// Sets default values
ACppBaseActor::ACppBaseActor() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
  SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay() 
{ 
	Super::BeginPlay(); 
	InitialLocation = GetActorLocation();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void ACppBaseActor::ShowActorInformation() {
  UE_LOG(LogTemp, Display, TEXT("Instance Name: %s"), *GetName());
  UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
  UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}

FVector ACppBaseActor::SinMovement()
{
  // z = Amplitude × sin(Frequency × Time) + z0
  float Time = GetGameTimeSinceCreation();
  float NewZ = Amplitude * FMath::Sin(Frequency * Time) + InitialLocation.Z;
  FVector NewLocation = FVector(InitialLocation.X, InitialLocation.Y, NewZ);
  return NewLocation;
}