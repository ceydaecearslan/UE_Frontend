

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "FrontendDeveloperSettings.generated.h"

class UCommonActivatableWidgetBase;
/**
 * 
 */
UCLASS(Config= Game, defaultconfig, meta=(DisplayName="Frontend UI Settings"))
class FRONTEND_API UFrontendDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	UPROPERTY(Config, EditAnywhere, Category="Widget Reference", meta = (ForceInlineRow, Categories="Frontend.Widget"))
	TMap<FGameplayTag, TSoftClassPtr<UCommonActivatableWidgetBase>> FrontendWidgetMap;
	
};
