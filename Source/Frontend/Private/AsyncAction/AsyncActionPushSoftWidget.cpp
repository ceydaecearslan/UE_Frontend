


#include "AsyncAction/AsyncActionPushSoftWidget.h"

#include "GameplayTagContainer.h"
#include "Subsystem/FrontendUISubsystem.h"
#include "Widget/CommonActivatableWidgetBase.h"

void UAsyncActionPushSoftWidget::Activate()
{
	UFrontendUISubsystem* FrontendUISubsystem = UFrontendUISubsystem::Get(CachedOwningWorld.Get());
	FrontendUISubsystem->PushSoftWidgetToStackAsync(CachedWidgetStackTag, CachedSoftWidgetClass,
		[this](EAsyncPushWidgetState InPushState, UCommonActivatableWidgetBase* PushedWidget)
		{
			switch (InPushState)
			{
			case EAsyncPushWidgetState::OnCreatedBeforePush:
				
				PushedWidget->SetOwningPlayer(CachedOwningPlayerController.Get());
				OnWidgetCreatedBeforePush.Broadcast(PushedWidget);
				break;
			case EAsyncPushWidgetState::AfterPush:
				
				OnAfterPush.Broadcast(PushedWidget);
				if (bCachedFocusOnNewlyPushedWidget)
				{
					if (UWidget* WidgetToFocus = PushedWidget->GetDesiredFocusTarget())
					{
						WidgetToFocus->SetFocus();
					}
				}
				SetReadyToDestroy();
				break;

			default:
				break;
			}
		});
}

UAsyncActionPushSoftWidget* UAsyncActionPushSoftWidget::PushSoftWidget(UObject* WorldContextObject,
	APlayerController* OwningPlayerController, TSoftClassPtr<UCommonActivatableWidgetBase> InSoftWidgetClass,
	UPARAM(meta = (Categories = "Frontend.WidgetStack")) FGameplayTag InWidgetStackTag, bool bFocusOnNewlyPushedWidget)
{
	check(!InSoftWidgetClass.IsNull());
	if (GEngine)
	{
		if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
		{
			UAsyncActionPushSoftWidget* Action = NewObject<UAsyncActionPushSoftWidget>();
			Action->CachedOwningWorld = World;
			Action->CachedOwningPlayerController = OwningPlayerController;
			Action->CachedSoftWidgetClass = InSoftWidgetClass;
			Action->CachedWidgetStackTag = InWidgetStackTag;
			Action->bCachedFocusOnNewlyPushedWidget = bFocusOnNewlyPushedWidget;
			
			Action->RegisterWithGameInstance(World);
			return Action;
		}
	}
	return nullptr;
}
