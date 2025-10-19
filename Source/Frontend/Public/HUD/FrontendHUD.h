

#pragma once

#include "CoreMinimal.h"
#include "CommonInputModeTypes.h"
#include "GameFramework/HUD.h"
#include "FrontendHUD.generated.h"

class UPrimaryLayout;
/**
 * 
 */
UCLASS()
class FRONTEND_API AFrontendHUD : public AHUD
{
	GENERATED_BODY()

public:

	void InitializeHud();

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void ShowPressAnyKeyWidget();
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPrimaryLayout> PrimaryLayoutClass;
	
	UPROPERTY(EditDefaultsOnly)
	TSoftClassPtr<UUserWidget> PressAnyKeyWidgetClass;
};
