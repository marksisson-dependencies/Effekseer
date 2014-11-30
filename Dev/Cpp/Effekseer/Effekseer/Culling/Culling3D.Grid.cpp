
#include "Culling3D.Grid.h"
#include "Culling3D.ObjectInternal.h"

namespace Culling3D
{
	Grid::Grid()
	{
		IsScanned = false;
	}

	void Grid::AddObject(Object* o)
	{
		assert(o != NULL);

		ObjectInternal* o_ = (ObjectInternal*) o;
		assert(o_->ObjectIndex == -1);

		objects.push_back(o_);
		o_->ObjectIndex = objects.size() - 1;
	}

	void Grid::RemoveObject(Object* o)
	{
		assert(o != NULL);

		ObjectInternal* o_ = (ObjectInternal*) o;
		assert(o_->ObjectIndex != -1);

		if (objects.size() == 1)
		{
			objects.clear();
		}
		else if (objects.size() - 1 == o_->ObjectIndex)
		{
			objects.resize(objects.size() - 1);
		}
		else
		{
			objects[o_->ObjectIndex] = objects[objects.size() - 1];
			objects.resize(objects.size() - 1);
		}

		o_->ObjectIndex = -1;
	}
}