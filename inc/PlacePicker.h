#pragma once
#include "PlaceList.h"

class PlacePicker
{
public:
	PlacePicker(PlaceList* place);
	~PlacePicker();
	PlaceList* pickLunchPlace();

private:
	PlaceList* mPlaceList;
	int mTotalPlaceNum;
};
