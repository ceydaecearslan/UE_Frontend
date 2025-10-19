


#include "HUD/FrontendHUD.h"

#include "AsyncAction/AsyncActionPushSoftWidget.h"
#include "Blueprint/UserWidget.h"
#include "Subsystem/FrontendUISubsystem.h"
#include "Widget/PrimaryLayout.h"

void AFrontendHUD::InitializeHud()
{
	check(PrimaryLayoutClass);
	const TObjectPtr<UPrimaryLayout> PrimaryLayout = Cast<UPrimaryLayout>(CreateWidget(GetWorld(), PrimaryLayoutClass, TEXT("PrimaryLayout")));
	PrimaryLayout->AddToViewport();
	UFrontendUISubsystem::Get(GetWorld())->RegisterCreatedPrimaryLayoutWidget(PrimaryLayout);
	ShowPressAnyKeyWidget();
}
