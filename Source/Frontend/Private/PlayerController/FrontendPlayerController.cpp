


#include "PlayerController/FrontendPlayerController.h"
#include "Camera/CameraActor.h"
#include "HUD/FrontendHUD.h"
#include "Kismet/GameplayStatics.h"

void AFrontendPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	SetCameraView();

	if (AFrontendHUD* FrontendHUD = Cast<AFrontendHUD>(GetHUD()))
	{
		FrontendHUD->InitializeHud();
	}
}

void AFrontendPlayerController::SetCameraView()
{
	// TODO later, find another way to use instead of GetAllActorsOfClass 
	TArray<AActor*> FoundCameras;
	UGameplayStatics::GetAllActorsOfClassWithTag(this, ACameraActor::StaticClass(), FName("Default"), FoundCameras);
	if (!FoundCameras.IsEmpty())
	{
		SetViewTarget(FoundCameras[0]);	
	}
}
