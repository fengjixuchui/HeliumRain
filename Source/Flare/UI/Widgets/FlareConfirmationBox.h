#pragma once

#include "../../Flare.h"
#include "../Components/FlareButton.h"


class SFlareConfirmationBox : public SCompoundWidget
{
	/*----------------------------------------------------
		Slate arguments
	----------------------------------------------------*/

	SLATE_BEGIN_ARGS(SFlareConfirmationBox)
	: _ContainerStyle(&FFlareStyleSet::Get().GetWidgetStyle<FFlareContainerStyle>("/Style/DefaultContainerStyle"))
	{}

	SLATE_EVENT(FFlareButtonClicked, OnConfirmed)
	SLATE_EVENT(FFlareButtonClicked, OnCancelled)

	SLATE_ARGUMENT(FText, CancelText)
	SLATE_ARGUMENT(FText, ConfirmText)

	SLATE_STYLE_ARGUMENT(FFlareContainerStyle, ContainerStyle)
	
	SLATE_END_ARGS()


public:

	/*----------------------------------------------------
		Public methods
	----------------------------------------------------*/

	/** Create the widget */
	void Construct(const FArguments& InArgs);

	/** Show this box for a specific amount */
	void Show(float Amount);

	/** Hide this box */
	void Hide();


protected:

	/*----------------------------------------------------
		Protected data
	----------------------------------------------------*/

	TSharedPtr<SFlareButton> ConfirmButton;

	TSharedPtr<STextBlock> CostLabel;


};
