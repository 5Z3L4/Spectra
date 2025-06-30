// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;
	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cam->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Horizontal", this, &AMyCharacter::HorizontalMove);
	InputComponent->BindAxis("Vertical", this, &AMyCharacter::VerticalMove);
	InputComponent->BindAxis("HorizontalRot", this, &AMyCharacter::HorizontalRot);
}

void AMyCharacter::HorizontalMove(float value)
{
	if (value != 0)
		AddMovementInput(GetActorRightVector(), value);
}

void AMyCharacter::VerticalMove(float value)
{
	if (value != 0)
		AddMovementInput(GetActorForwardVector(), value);
}

void AMyCharacter::HorizontalRot(float value)
{
	if(value != 0)
		AddActorLocalRotation(FRotator(0,value,0));
}
