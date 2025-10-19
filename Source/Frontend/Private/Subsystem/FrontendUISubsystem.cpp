


#include "Subsystem/FrontendUISubsystem.h"

#include "Engine/AssetManager.h"
#include "Widget/CommonActivatableWidgetBase.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "Widget/PrimaryLayout.h"

UFrontendUISubsystem* UFrontendUISubsystem::Get(const UObject* WorldContextObject)
{
	if (GEngine)
	{
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert);

		return UGameInstance::GetSubsystem<UFrontendUISubsystem>(World->GetGameInstance());
	}
	return nullptr;
}

bool UFrontendUISubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	if (!CastChecked<UGameInstance>(Outer)->IsDedicatedServerInstance())
	{
		TArray<UClass*> FoundClasses;
		GetDerivedClasses(GetClass(), FoundClasses);
		
		return FoundClasses.IsEmpty();
	}
	return false;
}

void UFrontendUISubsystem::RegisterCreatedPrimaryLayoutWidget(UPrimaryLayout* PrimaryLayout)
{
	CreatedPrimaryLayout = PrimaryLayout;
}

void UFrontendUISubsystem::PushSoftWidgetToStackAsync(const FGameplayTag& InWidgetStackTag,
	TSoftClassPtr<UCommonActivatableWidgetBase> InSoftWidgetClass, TFunction<void (EAsyncPushWidgetState, UCommonActivatableWidgetBase*)> AsyncPushStateCallback)
{
	check(!InSoftWidgetClass.IsNull())

	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(
		InSoftWidgetClass.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda([this, InSoftWidgetClass, InWidgetStackTag, AsyncPushStateCallback]()
		{
			UClass* LoadedWidgetClass = InSoftWidgetClass.Get();
			check(LoadedWidgetClass && CreatedPrimaryLayout);

			UCommonActivatableWidgetContainerBase* FoundWidgetStack = CreatedPrimaryLayout->FindWidgetStackByTag(InWidgetStackTag);
			UCommonActivatableWidgetBase* CreatedWidget = FoundWidgetStack->AddWidget<UCommonActivatableWidgetBase>(LoadedWidgetClass, [AsyncPushStateCallback](UCommonActivatableWidgetBase& CreatedWidgetInstance)
			{
				AsyncPushStateCallback(EAsyncPushWidgetState::OnCreatedBeforePush, &CreatedWidgetInstance);
			});
			
			AsyncPushStateCallback(EAsyncPushWidgetState::AfterPush, CreatedWidget);
		}));
}
