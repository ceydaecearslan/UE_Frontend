


#include "FunctionLibrary/FrontendBlueprintFunctionLibrary.h"

#include "DeveloperSettings/FrontendDeveloperSettings.h"

TSoftClassPtr<UCommonActivatableWidgetBase> UFrontendBlueprintFunctionLibrary::GetFrontendSoftWidgetClassByTag(UPARAM(meta = (Categories = "Frontend.Widget")) FGameplayTag InWidgetTag)
{
	const UFrontendDeveloperSettings* DeveloperSettings = GetDefault<UFrontendDeveloperSettings>();
	check (DeveloperSettings)
	check (DeveloperSettings->FrontendWidgetMap.Contains(InWidgetTag))
	
	return DeveloperSettings->FrontendWidgetMap.FindRef(InWidgetTag);
}
