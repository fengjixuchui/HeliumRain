
#include "../../Flare.h"
#include "FlareShipInstanceInfo.h"
#include "../../Ships/FlareShipInterface.h"
#include "../../Player/FlarePlayerController.h"


/*----------------------------------------------------
	Construct
----------------------------------------------------*/

void SFlareShipInstanceInfo::Construct(const FArguments& InArgs)
{
	// Data
	StationData = NULL;
	ShipData = NULL;
	StationDescription = NULL;
	ShipDescription = NULL;
	UObject* Target = NULL;
	const FSlateBrush* Icon = NULL;

	// Station data
	if (InArgs._Station)
	{
		Target = InArgs._Station->_getUObject();
		StationData = InArgs._Station->Save();
		StationDescription = InArgs._Player->GetGame()->GetStationCatalog()->Get(StationData->Identifier);
		Icon = IFlareStationInterface::GetIcon(StationDescription);
	}

	// Ship data
	else if (InArgs._Ship)
	{
		Target = InArgs._Ship->_getUObject();
		ShipData = InArgs._Ship->Save();
		ShipDescription = InArgs._Player->GetGame()->GetShipCatalog()->Get(ShipData->Identifier);
		Icon = IFlareShipInterface::GetIcon(ShipDescription);
	}

	// Create the layout
	ChildSlot
	.VAlign(VAlign_Fill)
	.HAlign(HAlign_Fill)
	[
		SNew(SHorizontalBox)

		// Icon
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(FMargin(8))
		.VAlign(VAlign_Center)
		[
			SNew(SImage).Image(Icon)
		]

		// Name
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(FMargin(10))
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(Target->GetName())
			.TextStyle(FFlareStyleSet::Get(), "Flare.Title3")
		]

		// Info box
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(FMargin(10))
		.VAlign(VAlign_Center)
		[
			SAssignNew(InfoBox, SHorizontalBox)
		]
	];
}

