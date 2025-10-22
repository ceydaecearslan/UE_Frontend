

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/HUD.h"
#include "FrontendHUD.generated.h"

class UAsyncActionPushSoftWidget;
class UCommonActivatableWidgetBase;
class UMVVMViewModelBase;
class UMVVMPressAnyKey;
class UPrimaryLayout;
/**
 * 
 */
UCLASS()
class FRONTEND_API AFrontendHUD : public AHUD
{
	GENERATED_BODY()

public:

	AFrontendHUD();
	
	void InitializeHud();

	UFUNCTION()
	void OnPressAnyKeyWidgetCreated(UCommonActivatableWidgetBase* PushedWidget);

protected:

	UAsyncActionPushSoftWidget* NewPushSoftWidgetAsyncAction(
		FName InSoftClassTag,
		FName InWidgetStackTag,
		bool bFocusOnNewlyPushedWidget);
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPrimaryLayout> PrimaryLayoutClass;

	TMap<FName, FGameplayTag> FrontendWidgetStackTags;
	TMap<FName, FGameplayTag> FrontendWidgetSoftClassTags;
};
