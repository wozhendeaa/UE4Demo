// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "UFO.generated.h"

UCLASS()
class DEMOONE_API AUFO : public AActor
{
	GENERATED_BODY()
	
public:	
	
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category=UFO)
	float speed;
	   
	// Sets default values for this actor's properties
	AUFO();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
