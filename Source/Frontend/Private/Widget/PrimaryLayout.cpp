


#include "Widget/PrimaryLayout.h"
#include "GameplayTagContainer.h"

TObjectPtr<UCommonActivatableWidgetContainerBase> UPrimaryLayout::FindWidgetStackByTag(const FGameplayTag& InTag) const
{
	checkf(RegisteredWidgetStackMap.Contains(InTag), TEXT("Widget Stack with Tag %s is not found!"), *InTag.ToString());
	return RegisteredWidgetStackMap.FindRef(InTag);
}

void UPrimaryLayout::RegisterWidgetStack(UPARAM(meta = (Categories = "Frontend.WidgetStack")) FGameplayTag InStackTag,
                                         UCommonActivatableWidgetContainerBase* InWidgetStack)
{
	if (!IsDesignTime())
	{
		if (!RegisteredWidgetStackMap.Contains(InStackTag))
		{
			RegisteredWidgetStackMap.Add(InStackTag, InWidgetStack);
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::MakeRandomColor(),FString::Printf(TEXT("Registered Widget Stack with Tag %s"), *InStackTag.ToString()));
		}
	}
}
