


#include "HUD/FrontendHUD.h"

#include "AsyncAction/AsyncActionPushSoftWidget.h"
#include "Blueprint/UserWidget.h"
#include "FunctionLibrary/FrontendBlueprintFunctionLibrary.h"
#include "Interface/PressAnyKeyInterface.h"
#include "Subsystem/FrontendUISubsystem.h"
#include "Widget/PrimaryLayout.h"
#include "Widget/CommonActivatableWidgetBase.h"

AFrontendHUD::AFrontendHUD()
{
	FrontendWidgetSoftClassTags.Add(FName("PressAnyKeyWidget"), FGameplayTag::RequestGameplayTag(FName("Frontend.Widget.PressAnyKey")));
	FrontendWidgetSoftClassTags.Add(FName("MainMenuWidget"), FGameplayTag::RequestGameplayTag(FName("Frontend.Widget.MainMenu")));

	FrontendWidgetStackTags.Add(FName("Frontend"), FGameplayTag::RequestGameplayTag(FName("Frontend.WidgetStack.Frontend")));
	FrontendWidgetStackTags.Add(FName("GameHud"), FGameplayTag::RequestGameplayTag(FName("Frontend.WidgetStack.GameHud")));
	FrontendWidgetStackTags.Add(FName("GameMenu"), FGameplayTag::RequestGameplayTag(FName("Frontend.WidgetStack.GameMenu")));
	FrontendWidgetStackTags.Add(FName("Modal"), FGameplayTag::RequestGameplayTag(FName("Frontend.WidgetStack.Modal")));
}

void AFrontendHUD::InitializeHud()
{
	check(PrimaryLayoutClass);
	const TObjectPtr<UPrimaryLayout> PrimaryLayout = Cast<UPrimaryLayout>(CreateWidget(GetWorld(), PrimaryLayoutClass, TEXT("PrimaryLayout")));
	PrimaryLayout->AddToViewport();
	UFrontendUISubsystem::Get(GetWorld())->RegisterCreatedPrimaryLayoutWidget(PrimaryLayout);

	UAsyncActionPushSoftWidget* PushSoftWidgetAction = NewPushSoftWidgetAsyncAction(
		FName("PressAnyKeyWidget"),
		FName("Frontend"),
		true);
	
	PushSoftWidgetAction->OnWidgetCreatedBeforePush.AddDynamic(this, &AFrontendHUD::OnPressAnyKeyWidgetCreated);
}

void AFrontendHUD::OnPressAnyKeyWidgetCreated(UCommonActivatableWidgetBase* PushedWidget)
{
	Cast<IPressAnyKeyInterface>(PushedWidget)->OnPressAnyKeyCreated([this]()
	{
		NewPushSoftWidgetAsyncAction(
			FName("MainMenuWidget"),
			FName("Frontend"),
			true);
	});
}

UAsyncActionPushSoftWidget* AFrontendHUD::NewPushSoftWidgetAsyncAction(FName InSoftClassTag,
	FName InWidgetStackTag, bool bFocusOnNewlyPushedWidget)
{
		return UAsyncActionPushSoftWidget::PushSoftWidget(
		this,
		GetOwningPlayerController(),
		UFrontendBlueprintFunctionLibrary::GetFrontendSoftWidgetClassByTag(FrontendWidgetSoftClassTags.FindRef(InSoftClassTag)),
		FrontendWidgetStackTags.FindRef(InWidgetStackTag),
		bFocusOnNewlyPushedWidget);
}
